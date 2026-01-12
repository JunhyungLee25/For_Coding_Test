#include <stdio.h>
// stdlib.h: malloc(동적 메모리 할당), atoi(문자열->정수 변환) 함수 사용
#include <stdlib.h>
// string.h: strcmp(문자열 비교), strdup(문자열 복제) 함수 사용
#include <string.h>
// ctype.h: isdigit(문자가 숫자인지 판별) 함수 사용
#include <ctype.h>

// 해시 테이블의 크기(버킷의 개수)를 100,000으로 정의
#define TABLE_SIZE 100000


typedef struct poketmon {
    char name[21];         // 포켓몬 이름 (문자열 포인터)
    // char* name;
    int idx;            // 포켓몬 번호 (입력 순서)
    struct poketmon* next; 
} POKE;


// 해시 테이블 (이름 -> 번호 검색용)
// POKE 노드 포인터를 저장하는 배열. 
// 각 칸(hash[i])은 '연결 리스트의 시작점(head)' 역할을 함.
POKE* hash[TABLE_SIZE]; 

// 1차원 포인터 배열 (번호 -> 이름 검색용)
// 문자열 포인터(char*)를 저장하는 배열.
// poke_list[번호] = "이름이 저장된 주소" 형태로 사용할 것임.
char *poke_list[TABLE_SIZE + 1]; 


/*
 * 'djb2' 해시 함수
 * - 기능: 문자열(str)을 받아서 0 ~ (TABLE_SIZE-1) 사이의 정수(인덱스)로 변환
 * - 장점: 계산이 빠르고, 충돌이 적도록 값이 고르게 분포됨
 */
unsigned int hash_djb2(const char* str) {
    // 5381은 이 함수가 경험적으로 찾은 '좋은 시작값'(magic number)
    unsigned long hash_val = 5381; 
    int c;

    // 문자열의 끝(\0)을 만날 때까지 한 글자씩 반복
    while (c = *str++) {
        // (hash_val * 33) + c
        // (hash << 5)는 (hash * 32)와 같음. 
        // 비트 연산이 곱셈보다 빠르므로 성능에 유리함.
        hash_val = ((hash_val << 5) + hash_val) + c; 
    }

    // 최종 해시 값을 테이블 크기로 나누어 '인덱스'로 만듦
    return hash_val % TABLE_SIZE;
}


int main(void) {
    int N, M, hash_idx;
    char name[21]; 

    scanf("%d %d", &N, &M); // N: 포켓몬 수, M: 문제 수

    // 해시 테이블 초기화
    // 모든 칸(연결 리스트의 시작점)을 NULL로 초기화
    // 이유: 여기가 NULL이어야 연결 리스트의 '끝'임을 알 수 있음.
    //      초기화 안 하면 쓰레기 주소를 가리켜서 런타임 에러 발생.
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash[i] = NULL;
    }

    // --- N개의 포켓몬 데이터를 2개의 자료구조에 동시 저장 ---
    for (int i = 0; i < N; i++) {
        // 1. 임시 버퍼 'name'에 이름을 입력받음
        scanf("%s", name); 
        
        // 2. [해시 테이블 저장 로직]
        // 2-1. 해시 함수로 'name'이 들어갈 버킷(인덱스) 계산
        hash_idx = hash_djb2(name);
        
        // 2-2. 새 'POKE' 노드를 저장할 메모리를 동적으로 할당
        POKE* newNode = (POKE*)malloc(sizeof(POKE));
        if (newNode == NULL) { // 메모리 할당 실패 시
            return 1; // 프로그램 비정상 종료
        }

        // 2-3. [!!매우 중요!!] 'strdup'로 문자열 복제
        // 'name' 버퍼는 다음 scanf에서 덮어써질 '임시' 공간임.
        // strdup은 '영구적인' 새 메모리 공간을 따로 할당(malloc)하고
        // 'name'의 내용을 그곳에 복사(strcpy)한 뒤, 그 주소를 반환함. 
        // newNode->name = strdup(name);

        strcpy(newNode->name,name);
        newNode->idx = i + 1; // 번호는 1번부터 시작 (문제 조건)
        // 2-4. [해시 테이블 삽입] '연결 리스트'의 맨 앞에 새 노드 삽입
        // (1) 새 노드의 'next'가 현재 'head'(hash[hash_idx])를 가리킴
        newNode->next = hash[hash_idx]; 
        // (2) 이제 'head'(hash[hash_idx])가 '새 노드'를 가리킴
        hash[hash_idx] = newNode;       

        // 3. [1차원 배열 저장 로직]
        // [!!핵심!!] '번호 -> 이름' 검색을 위해, 
        // 1차원 배열의 (i+1)번 칸에 방금 복제한 문자열의 '주소'를 저장
        // (newNode->name과 poke_list[i+1]은 동일한 메모리 주소를 가리킴)
        poke_list[i + 1] = newNode->name;    
    }

    // --- M개의 문제(쿼리) 처리 ---
    for (int i = 0; i < M; i++) {
        // 쿼리를 임시 버퍼에 입력받음
        char query_buffer[21];
        scanf("%s", query_buffer);

        // 1. 쿼리가 '숫자'인지 '문자'인지 판별
        // query_buffer[0](첫번째 글자)가 '0'~'9' 사이면 참(True)
        if (isdigit(query_buffer[0])) {
            // --- [유형 2] 번호 -> 이름 검색 (O(1) 속도) ---
            
            // atoi: 'A'SCII 'to' 'I'nt. 문자열 "25"를 정수 25로 변환
            int index = atoi(query_buffer); 
            
            // 1차원 배열 'poke_list'에서 해당 인덱스의 문자열을 '즉시' 찾아 출력
            printf("%s\n", poke_list[index]);

        } else {
            // --- [유형 1] 이름 -> 번호 검색 (평균 O(1) 속도) ---
            
            // 1. 해시 함수로 쿼리 문자열의 인덱스(버킷)를 찾음
            hash_idx = hash_djb2(query_buffer);
            
            // 2. 해당 버킷의 '연결 리스트 시작점(head)'을 가져옴
            POKE* current = hash[hash_idx];
            
            // 3. [충돌 처리] 연결 리스트를 끝(NULL)까지 순회
            // 해시값이 우연히 동일(충돌 발생)할 수도 있기 때문에 특정 해시값을 가지고 있는 연결리스트로 가서 모든 연결된 리스트를 순회해야한다.
            while (current != NULL) {
                // 4. [!!중요!!] 'strcmp'로 문자열 '내용'을 비교
                // (current->name == query_buffer 는 '주소'를 비교하므로 절대 안 됨)
                // strcmp는 두 문자열이 같으면 0을 반환함.
                if (strcmp(current->name, query_buffer) == 0) {
                    // 5. 일치하는 노드를 찾으면 '번호(idx)'를 출력
                    printf("%d\n", current->idx);
                    break; // 검색 성공했으므로 while 루프 탈출
                }
                
                // 6. 못 찾았으면 리스트의 다음 노드로 이동
                current = current->next;
            }
        }
    }
    // 1. 해시 테이블의 모든 '통'(버킷)을 순회합니다. (0 ~ TABLE_SIZE-1)
    for (int i = 0; i < TABLE_SIZE; i++) {
        // 2. 각 통(hash[i])에 연결된 '연결 리스트'를 순회합니다.
        POKE* current = hash[i];
        while (current != NULL) {
            // 3. [!!매우 중요!!]
            //    current를 바로 free 해버리면 'current->next'로 이동할 수 없습니다.
            //    따라서 'temp'에 현재 노드(free할 노드)를 임시 저장하고,
            //    'current'는 다음 노드로 먼저 이동시킵니다.
            POKE* temp = current;
            current = current->next;
            
            // 4. 임시 저장해둔 'temp' (이전 노드)를 안전하게 free 합니다.
            free(temp);
        }
    }
    return 0; // 정상 종료
}