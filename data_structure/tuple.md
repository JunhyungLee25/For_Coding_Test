### 정의

`std::tuple`은 서로 다른 타입의 원소들을 하나로 묶을 수 있는 **고정 크기의 컬렉션**이다. 두 개의 데이터만 묶을 수 있는 `std::pair`를 확장하여 세 개 이상의 데이터를 동시에 저장할 수 있는 자료구조이다.

### 핵심 원리

- 여러 종류의 데이터를 하나의 단위로 그룹화하여 관리한다. 함수에서 여러 개의 값을 한 번에 반환해야 하거나, 3차원 좌표($x, y, z$)처럼 연관된 데이터 세트를 저장할 때 주로 사용한다. 컴파일 타임에 원소의 개수와 타입이 결정되므로 실행 시점의 오버헤드가 적다.
    

### 주요 특징

- **이질적 타입 저장:** `int`, `double`, `string` 등 서로 다른 타입의 데이터를 하나의 튜플에 담을 수 있다.
    
- **고정 크기:** 생성 시점에 크기가 정해지며, 실행 중에 원소를 추가하거나 삭제할 수 없다.
    
- **접근 방식:** 인덱스를 기반으로 접근하지만, 배열처럼 `[]` 연산자를 쓰지 않고 `std::get<N>(t)` 함수를 사용한다.
    
- **헤더:** `<tuple>` 헤더를 포함해야 한다.
    

### 동작 방식

1. **생성:** `std::make_tuple()` 함수를 사용하거나 생성자를 통해 튜플 객체를 만든다.
    
2. **접근:** `std::get<index>(tuple_name)`을 통해 특정 위치의 원소에 접근한다. 인덱스는 0부터 시작하며 반드시 상수여야 한다.
    
3. **분해 (tie):** `std::tie()`를 사용하여 튜플의 값을 개별 변수로 한 번에 추출한다.
    
4. **구조체 바인딩 (C++17 이상):** `auto [a, b, c] = my_tuple;`과 같이 더욱 직관적인 방식으로 값을 꺼낼 수 있다.
    

### c++ 구현 예시


```c++
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

void tupleExample() {
    // 1. 생성 (int, string, double)
    tuple<int, string, double> t1 = make_tuple(1, "Tomato", 3.5);

    // 2. 값 접근 (std::get)
    int id = get<0>(t1);
    string name = get<1>(t1);
    cout << "ID: " << id << ", Name: " << name << endl;

    // 3. std::tie를 이용한 분해
    int a;
    string b;
    double c;
    tie(a, b, c) = t1;

    // 4. 구조체 바인딩 (C++17 추천 방식)
    auto [id2, name2, score] = t1;
    cout << "Score: " << score << endl;
}
```