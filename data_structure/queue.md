# Queue

### 정의

`std::queue`는 **FIFO(First-In, First-Out; 선입선출)** 원칙을 따르는 자료구조로, 먼저 들어간 데이터가 먼저 나오는 특징을 가진다.

### 핵심 원리

- 데이터의 삽입은 뒤(Back)에서 일어나고, 삭제는 앞(Front)에서 일어난다. 이 구조는 BFS(너비 우선 탐색)에서 방문할 노드를 순서대로 관리하는 데 최적화되어 있다.
    

### 주요 특징

- **제한된 접근:** 중간에 있는 데이터를 임의로 꺼내거나 수정할 수 없다. 오직 가장 앞(`front`)과 가장 뒤(`back`)만 확인할 수 있다.
    
- **시간 복잡도:** 원소의 삽입(`push`)과 삭제(`pop`) 모두 $O(1)$의 성능을 보장한다.
    
- **헤더:** `<queue>` 헤더를 포함해야 한다.
    

### 동작 방식

1. **push:** 큐의 맨 뒤에 데이터를 추가한다.
    
2. **front:** 큐의 맨 앞에 있는 데이터를 확인한다 (삭제는 하지 않는다).
    
3. **pop:** 큐의 맨 앞에 있는 데이터를 제거한다 (반환값은 없다).
    
4. **empty/size:** 큐가 비어있는지 확인하거나 현재 담긴 원소의 개수를 반환한다.
    

### c++ 구현 예시

```c++
#include <iostream>
#include <queue>
using namespace std;

void queueExample() {
    queue<int> q;

    q.push(10); // [10]
    q.push(20); // [10, 20]
    
    if (!q.empty()) {
        cout << "맨 앞의 값: " << q.front() << endl; // 10
        q.pop(); // [20]
    }
    
    cout << "큐의 크기: " << q.size() << endl; // 1
}
```

---

# Priority_Queue

### 정의
`std::priority_queue`는 모든 원소 중에서 우선순위가 가장 높은 데이터가 먼저 나가는 자료구조로, 내부적으로 힙(Heap) 구조를 사용하여 데이터를 관리한다.

### 핵심 원리
일반적인 큐가 들어온 순서(FIFO)를 따지는 것과 달리, 우선순위 큐는 데이터의 **값(우선순위)**을 기준으로 출력 순서를 결정한다. 데이터가 삽입될 때마다 내부적으로 정렬이 이루어져 항상 최상단에는 우선순위가 가장 높은 원소가 위치하게 된다.

### 주요 특징
자동 정렬: 새로운 원소가 추가되거나 삭제될 때마다 힙 규칙에 따라 내부 요소들이 자동으로 재배치된다.

시간 복잡도: 원소의 삽입(push)과 삭제(pop)는 $O(\log N)$이며, 가장 높은 우선순위의 원소를 확인하는 top 연산은 $O(1)$이다.

기본 설정: C++ 표준 라이브러리의 우선순위 큐는 기본적으로 **내림차순(Max Heap)**으로 동작하여 값이 클수록 우선순위가 높다고 판단한다.

### 헤더: std::queue와 마찬가지로 <queue> 헤더를 포함해야 한다.

### 동작 방식
push: 우선순위 큐에 데이터를 추가한다. 내부적으로 힙 정렬이 발생하여 적절한 위치로 이동한다.

top: 현재 우선순위가 가장 높은(가장 큰) 데이터를 확인한다 (삭제는 하지 않는다).

pop: 현재 우선순위가 가장 높은 데이터를 제거한다 (반환값은 없다).

empty/size: 큐가 비어있는지 확인하거나 현재 담긴 원소의 개수를 반환한다.

### c++ 구현 예시

```c++
#include <iostream>
#include <queue> // priority_queue 포함
#include <vector>
using namespace std;

void priorityQueueExample() {
    // 기본 내림차순 우선순위 큐
    priority_queue<int> pq;

    pq.push(30); // [30]
    pq.push(10); // [30, 10]
    pq.push(50); // [50, 30, 10]
    
    if (!pq.empty()) {
        // 가장 큰 값인 50이 출력됨
        cout << "현재 우선순위가 가장 높은 값: " << pq.top() << endl; 
        pq.pop(); // 50 제거
    }

    // 오름차순(Min Heap)으로 사용하고 싶은 경우
    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(30);
    minPq.push(10);
    minPq.push(50);

    // 가장 작은 값인 10이 출력됨
    cout << "오름차순 큐의 top: " << minPq.top() << endl;
}
```