### 정의

`std::stack`은 **LIFO(Last-In, First-Out; 후입선출)** 원칙에 따라 작동하는 컨테이너 어댑터이다. 가장 최근에 추가된 데이터가 가장 먼저 제거되는 구조를 가진다.

### 핵심 함수 및 연산

스택에서 주로 사용하는 멤버 함수는 다음과 같다. 모든 주요 연산의 시간 복잡도는 $O(1)$이다.

| **함수**        | **설명**                                |
| ------------- | ------------------------------------- |
| `push(value)` | 스택의 맨 위에 데이터를 추가한다.                   |
| `pop()`       | 스택의 맨 위에 있는 데이터를 제거한다. (반환값 없음)       |
| `top()`       | 스택의 맨 위에 있는 데이터를 참조한다.                |
| `empty()`     | 스택이 비어 있으면 `true`, 아니면 `false`를 반환한다. |
| `size()`      | 스택에 저장된 원소의 개수를 반환한다.                 |

### 기본 사용법 (C++ 구현)

```c++
#include <iostream>
#include <stack> // 스택 사용을 위한 헤더
#include <utility> // pair 사용을 위한 헤더

using namespace std;

void stackManual() {
    // 1. 선언: stack<데이터타입> 변수명;
    stack<int> s;

    // 2. 데이터 삽입
    s.push(10);
    s.push(20);
    s.push(30);

    // 3. 상단 데이터 확인 및 제거
    // 주의: 스택이 비어있을 때 top()이나 pop()을 호출하면 런타임 에러가 발생한다.
    while (!s.empty()) {
        cout << "현재 Top: " << s.top() << endl;
        s.pop();
    }
}
```

### 고급 활용: pair와 함께 사용하기

'탑' 문제처럼 값(높이)과 위치(인덱스)를 동시에 관리해야 할 때는 `std::pair`를 스택의 요소로 넣는 것이 효율적이다.

```c++
// stack<pair<높이, 인덱스>> 형태로 선언
stack<pair<int, int>> towerStack;

// 데이터 넣기
towerStack.push({100, 1}); // 높이 100, 1번째 탑

// 데이터 접근
int height = towerStack.top().first;  // 100
int index = towerStack.top().second;  // 1
```