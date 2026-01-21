## **데이터 구조 설계**

- **`struct WORD`**: 단어(`string`), 빈도(`cnt`), 길이(`len`)를 하나의 객체로 묶어 관리한다.
    
- **`unordered_map wordnote`**: 단어의 존재 여부를 $O(1)$ 속도로 확인한다. Value에 `vector`의 인덱스를 저장하여 데이터 위치에 즉시 접근한다.
    
- **`vector w`**: 단어 객체들을 저장하며, 최종 정렬의 대상이 된다.
    
- **`compare` 함수**: 빈도(내림차순) → 길이(내림차순) → 사전순(오름차순)의 복합 정렬 규칙을 정의한다.
    

---

#### **1. String (문자열)**

- **헤더**: `#include <string>`
    
- **핵심 기능**:
    
    ```c++
    string s = "apple";
    int len = s.length();    // 길이 확인
    char c = s[0];           // 특정 인덱스 문자 접근
    string s2 = s + " pie";  // 문자열 결합
    if (s < "banana") { ... } // 사전순 비교
    ```
    `cin`은 공백(스페이스, 엔터) 단위로 입력받는다. 공백을 포함한 한 줄 입력이 필요할 경우 `getline(cin, s)`를 사용한다.

#### **2. 해시테이블 (unordered_map)**

- **특징**: 평균 $O(1)$의 탐색 및 삽입 속도를 보장한다.
    
- **헤더**: `#include <unordered_map>`
    
- **핵심 패턴**:
    
    ```c++
    unordered_map<string, int> um;
    um["key"] = 1; // 데이터 삽입 및 수정
    
    // 데이터 존재 여부 확인 (표준 패턴)
    if (um.find("key") == um.end()) {
        // 데이터가 없는 경우 처리
    }
    ```
    
- **비교**: 데이터 정렬이 불필요한 경우, 일반 `map`($O(\log N)$)보다 `unordered_map`($O(1)$)이 성능상 유리하다.
    

#### **3. 구조체 (struct)**

- **정의**: 연관된 여러 변수를 하나의 사용자 정의 타입으로 묶는다. 정의 마지막에 세미콜론(`;`)을 명시한다.
    
- **사용**:
    ```c++
    struct Point { int x, y; };
    Point p = {10, 20}; // 중괄호 초기화 활용
    ```
    여러 속성을 가진 데이터를 정렬하거나 `vector`에 담아 관리할 때 주로 사용한다.

#### **4. 벡터 (vector)**

- **특징**: 동적 배열로, 런타임에 크기가 자동으로 조절된다.
    
- **헤더**: `#include <vector>`
    
- **핵심 기능**:
    
    ```
    vector<int> v;
    v.push_back(10);          // 데이터 추가
    int size = v.size();      // 현재 크기 확인
    sort(v.begin(), v.end()); // 전체 데이터 정렬
    ```
    배열 크기를 미리 특정할 수 없는 대부분의 경우 `vector`를 사용하는 것이 표준이다.

### 최종 코드
```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct WORD{
    string word;
    int cnt;
    int len;
};
bool compare(const WORD &a, const WORD &b){
    if(a.cnt != b.cnt){
        return a.cnt > b.cnt;
    }

    if(a.len != b.len){
        return a.len > b.len;
    }
    return a.word < b.word;
}
vector<WORD> w;
unordered_map<string, int> wordnote;
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    string wd;
    for(int i=0; i<n; i++){
        cin >> wd;
        if(wd.length()<m){
            continue;
        }
        if(wordnote.find(wd) == wordnote.end()){ // 해시맵에서 단어를 찾고 end를 반환했다면 찾지 못했다는 뜻.
            wordnote[wd] = w.size(); // 맵에 {단어: 현재 벡터의 크기} 기록
            WORD temp;
            temp.word = wd;
            temp.cnt = 1;
            temp.len = wd.length();
            w.push_back(temp);
        } else{ // 이미 존재하는 단어이면
            int index = wordnote[wd]; // 맵에서 그 단어가 벡터의 몇 번째에 있는지 가져옴.
            w[index].cnt++; 
        }
    }
    sort(w.begin(),w.end(),compare); // 정렬
    for(int i=0; i<w.size(); i++){
        cout << w[i].word << '\n';
    }

    return 0;
}
```