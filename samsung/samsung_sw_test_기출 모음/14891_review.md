## 1. 핵심 로직

- **상태 표현:** 4개의 톱니바퀴와 각 8개의 날을 `int wheel[4][8]` 2차원 배열로 관리.
    
- **회전 조건:** 인접한 두 톱니바퀴의 맞닿은 극(3시 방향 index `2`, 9시 방향 index `6`)이 서로 다를 때만 반대 방향으로 회전.
    
- **전파 로직:** 한 톱니바퀴가 회전할 때, 그 영향이 좌우로 퍼져나가며 연쇄적으로 회전 여부가 결정됨.
    


## 2. 최적화 및 설계 과정

### ① 2차원 배열 및 인덱스 조작

처음에는 `wheel_1`, `wheel_2` 등 개별 배열로 접근했으나, 반복문을 통한 효율적인 관리를 위해 `wheel[4][8]` 2차원 배열로 통합하였다. 또한, 실제 데이터를 물리적으로 이동시키는 배열 Shifting 방식을 구현하여 시뮬레이션의 직관성을 높였다.

### ② 회전을 결정하는 전략

회전과 동시에 다음 바퀴를 체크하면, 바퀴가 이미 돌아가 버려 **원래의 접점 정보가 유실**되는 문제가 발생한다.(처음에 계속 실수한 부분이다.)

1. `rotate_flag`와 `rotate_dir` 배열을 사용하여 회전할 바퀴와 방향을 **미리 결정**.
    
2. 모든 결정이 끝난 후 한꺼번에 `rotate` 함수를 호출하여 상태를 업데이트.
    

### ③ 반복문을 통한 전파 자동화

`if(wheel_num == 1)` 등 하드코딩 방식에서 탈피하여, 선택된 바퀴를 기준으로 **왼쪽 방향 전파**와 **오른쪽 방향 전파**를 각각 `for` 루프로 구현하여 코드의 확장성과 가독성을 확보했습니다.


## 3. 실수했던 부분

### 잘못된 상태 체크 (Simultaneity Issue)

- **실수:** 바퀴를 하나 돌린 후, 바뀐 상태의 인덱스를 사용하여 다음 바퀴와의 접점을 비교함.
    
- **해결:** 모든 바퀴의 회전 여부를 현재 상태 기준으로 먼저 확정한 뒤 회전을 수행해야 함.
    

### 데이터 타입 및 입력 처리 (ASCII Trap)

- **실수:** 공백 없이 주어지는 숫자 문자열을 `int`로 바로 받으려 하거나, `char`를 `int` 배열에 넣을 때 ASCII 값이 저장됨.
    
- **해결:** `string`으로 한 줄을 입력받은 뒤, `n1[i] - '0'` 연산을 통해 실제 정수값(`0` 또는 `1`)으로 변환하여 저장함.
    

### 전파 로직의 인덱스 참조

- **실수:** `for` 루프 내부에서 제어 변수 `j`가 아닌 고정된 `cur` 값을 사용하여 연쇄 전파가 중단됨.
    
- **해결:** `wheel[j][2]`와 `wheel[j+1][6]` 처럼 현재 검사 중인 인덱스를 동적으로 참조하여 구현함.
    


## 4. 회전 함수

- **시계 방향:** 마지막 원소를 저장 후, 앞의 원소들을 뒤로 한 칸씩 밀기 ($i=7 \dots 1$).
    
- **반시계 방향:** 첫 번째 원소를 저장 후, 뒤의 원소들을 앞으로 한 칸씩 당기 ($i=0 \dots 6$).
    
## 5. 최종 코드

```c++
#include<iostream>
using namespace std;
// [0][2]<->[1][6], [1][2]<->[2][6], [2][2]<->[3][6]
// [0][0] + 2*[1][0] + 4*[2][0] + 8*[3][0] 
int wheel[4][8];
void rotate(int wheel_num, int dir, int flag){
    if(flag==0){return;}
    if(dir==1){
        int temp = wheel[wheel_num][7];
        for(int i=7; i>0; i--){wheel[wheel_num][i]=wheel[wheel_num][i-1];} // 시계
        wheel[wheel_num][0]=temp;
    } else {
        int temp = wheel[wheel_num][0];
        for(int i=0; i<7; i++){wheel[wheel_num][i]=wheel[wheel_num][i+1];} // 반시계
        wheel[wheel_num][7]=temp;    
    }
}
int main(void){
    int k,wheel_num,dir;
    string n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    for(int i=0; i<8; i++){
        wheel[0][i] = n1[i] - '0';
        wheel[1][i] = n2[i] - '0';
        wheel[2][i] = n3[i] - '0';
        wheel[3][i] = n4[i] - '0';
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int rotate_flag[4]={0};
        int rotate_dir[4]={0};
        cin >> wheel_num >> dir;
        int cur=wheel_num-1;
        rotate_dir[cur]=dir; rotate_flag[cur]=1;
        for(int j=cur; j<3; j++){
            if(wheel[j][2]!=wheel[j+1][6]){
                rotate_dir[j+1]=-rotate_dir[j];
                rotate_flag[j+1]=1;
            } else{break;}
        }
        for(int j=cur; j>0; j--){
            if(wheel[j-1][2]!=wheel[j][6]){
                rotate_dir[j-1]=-rotate_dir[j];
                rotate_flag[j-1]=1;
            } else{break;}
        }
        for(int a=0; a<4; a++){
            rotate(a,rotate_dir[a],rotate_flag[a]);
        }
    }
    int result = wheel[0][0] + 2*wheel[1][0] + 4*wheel[2][0] + 8*wheel[3][0];
    cout << result;
    return 0;
}
```