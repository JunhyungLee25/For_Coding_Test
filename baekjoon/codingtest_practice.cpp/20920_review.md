|시간 제한|메모리 제한|제출|정답|맞힌 사람|정답 비율|
|---|---|---|---|---|---|
|1 초 (추가 시간 없음)|1024 MB|35491|16591|13236|46.243%|

## 문제

화은이는 이번 영어 시험에서 틀린 문제를 바탕으로 영어 단어 암기를 하려고 한다. 그 과정에서 효율적으로 영어 단어를 외우기 위해 영어 단어장을 만들려 하고 있다. 화은이가 만들고자 하는 단어장의 단어 순서는 다음과 같은 우선순위를 차례로 적용하여 만들어진다.

1. 자주 나오는 단어일수록 앞에 배치한다.
2. 해당 단어의 길이가 길수록 앞에 배치한다.
3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다

 $M$보다 짧은 길이의 단어의 경우 읽는 것만으로도 외울 수 있기 때문에 길이가 $M$이상인 단어들만 외운다고 한다. 화은이가 괴로운 영단어 암기를 효율적으로 할 수 있도록 단어장을 만들어 주자.

## 입력

<br>첫째 줄에는 영어 지문에 나오는 단어의 개수 $N$과 외울 단어의 길이 기준이 되는 $M$이 공백으로 구분되어 주어진다. ($1 \leq N \leq 100\,000$, $1 \leq M \leq 10$)

둘째 줄부터 $N+1$번째 줄까지 외울 단어를 입력받는다. 이때의 입력은 알파벳 소문자로만 주어지며 단어의 길이는 $10$을 넘지 않는다.

단어장에 단어가 반드시 1개 이상 존재하는 입력만 주어진다.

## 출력

화은이의 단어장에 들어 있는 단어를 단어장의 앞에 위치한 단어부터 한 줄에 한 단어씩 순서대로 출력한다.

## 예제 입력 1 

7 4
<br>apple
<br>ant
<br>sand
<br>apple
<br>append
<br>sand
<br>sand

## 예제 출력 1 

sand
<br>apple
<br>append

## 예제 입력 2 

12 5
<br>appearance
<br>append
<br>attendance
<br>swim
<br>swift
<br>swift
<br>swift
<br>mouse
<br>wallet
<br>mouse
<br>ice
<br>age

## 예제 출력 2 

<br>swift
<br>mouse
<br>appearance
<br>attendance
<br>append
<br>wallet

****
#### **데이터 구조 설계**

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