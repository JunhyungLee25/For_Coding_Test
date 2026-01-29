### 정의

`std::pair`는 **두 개의 서로 다른(혹은 같은) 타입의 데이터를 하나의 객체로 묶어서 관리**하는 구조체 템플릿이다.

### 핵심 원리

- 두 데이터 데이터를 하나의 쌍(Pair)으로 묶어 처리한다. 첫 번째 데이터는 `first`, 두 번째 데이터는 `second`라는 이름의 멤버 변수로 접근한다.
    

### 주요 특징

- **데이터 결합:** 연관된 두 값을 한 번에 전달하거나 리턴할 때 유용하다. 특히 격자판의 좌표 $(r, c)$를 표현할 때 필수적이다.
    
- **비교 연산:** 기본적으로 `first` 값을 먼저 비교하고, 같을 경우 `second` 값을 비교하도록 연산자가 정의되어 있어 정렬에도 유리하다.
    
- **헤더:** `<utility>` 헤더에 정의되어 있으나, 보통 `<iostream>`이나 `<vector>` 등을 포함하면 자동으로 포함되는 경우가 많다.
    

### c++ 구현 예시


```c++
#include <iostream>
#include <utility> // pair가 포함된 헤더
using namespace std;

void pairExample() {
    // 1. 선언 및 초기화
    pair<int, int> p1 = make_pair(10, 20);
    pair<int, int> p2 = {30, 40}; // C++11 이상 권장 방식

    // 2. 값 접근
    cout << "p1의 첫 번째: " << p1.first << ", 두 번째: " << p1.second << endl;

    // 3. 중첩 사용 (예: 3개의 값 묶기)
    pair<int, pair<int, int>> triple = {1, {2, 3}};
}
```