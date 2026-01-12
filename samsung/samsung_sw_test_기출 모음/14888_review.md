# review

# 첫번째 시도 

실패원인: 
1. 문제의 조건을 면밀히 확인하지 않고, testcase의 예제만 보고 숫자가 크기 순서대로 온다고 착각하였다.
2. 곱셈, 나눗셈을 수의 크기나 현재 상태에 따라 배치하면 최적의 값을 얻을 수 있는 알고리즘이 있을 것이라 생각하였다.
3. 2번으로 인해 `N==3`과 같은 특수 케이스를 별도 처리하느라 쓸데없는 코드가 생김.

```c++
#include<iostream>
using namespace std;
int num[11];
int max_cal(int plus, int minus, int mul, int div){
    int temp=num[0];
    // '-' > '/' > '+' > 'x'
    int idx_1 = minus;
    int idx_2 = minus+div;
    int idx_3 = minus+div+plus;
    int idx_4 = minus+div+plus+mul;
    int idx = 1;
    if(minus>0){
        while(minus--){temp -= num[idx]; idx++;}
    }
    if(div > 0){
        while(div--){temp /= num[idx]; idx++;}
    }
    if(plus > 0){
        while(plus--){temp += num[idx]; idx++;}
    }
    if(mul > 0){
        while(mul--){temp *= num[idx]; idx++;}
    } 
    return temp;
}
int min_cal(int plus, int minus, int mul, int div){
    int temp=num[0];
    // '+' > '/' > '-' > 'x'
    int idx_1 = plus;
    int idx_2 = plus+div;
    int idx_3 = plus+div+minus;
    int idx_4 = plus+div+minus+mul;
    int idx = 1;
    if(plus>0){
        while(plus--){temp += num[idx]; idx++;}
    }
    if(div > 0){
        while(div--){temp /= num[idx]; idx++;}
    }
    if(minus > 0){
        while(minus--){temp -= num[idx]; idx++;}
    }
    if(mul > 0){
        while(mul--){temp *= num[idx]; idx++;}
    } 
    return temp;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,plus,minus,mul,div;
    int max_result=0;
    int min_result=0;
    cin >> n;
    for(int i=0; i<n; i++){cin >> num[i];} 
    cin >> plus >> minus >> mul >> div;
    if(n==3){
        int temp1=num[0];
        int temp2=num[0];
        if(plus>0 && minus>0){
            temp1 += num[1]; temp1 -= num[2];
            temp2 -= num[1]; temp2 += num[2];
        } else if(plus>0 && mul>0){
            temp1 += num[1]; temp1 *= num[2];
            temp2 *= num[1]; temp2 += num[2];
        } else if(plus>0 && div>0){
            temp1 += num[1]; temp1 /= num[2];
            temp2 /= num[1]; temp2 += num[2];
        } else if(minus>0 && mul>0){
            temp1 -= num[1]; temp1 *= num[2];
            temp2 *= num[1]; temp2 -= num[2];
        } else if(minus>0 && div>0){
            temp1 -= num[1]; temp1 /= num[2];
            temp2 /= num[1]; temp2 -= num[2];
        } else if(mul>0 && div>0){
            temp1 *= num[1]; temp1 /= num[2];
            temp2 /= num[1]; temp2 *= num[2];
        } else if(plus==2){
            temp1 += num[1]; temp1 += num[2];
            temp2 += num[1]; temp2 += num[2];
        } else if(minus==2){
            temp1 -= num[1]; temp1 -= num[2];
            temp2 -= num[1]; temp2 -= num[2];
        } else if(mul==2){
            temp1 *= num[1]; temp1 *= num[2];
            temp2 *= num[1]; temp2 *= num[2];
        } else if(div==2){
            temp1 /= num[1]; temp1 /= num[2];
            temp2 /= num[1]; temp2 /= num[2];
        }
        if(temp1 > temp2){cout << temp1 << '\n' << temp2;}
        else{cout << temp2 << '\n' << temp1;}
        return 0;
    }
    max_result = max_cal(plus,minus,mul,div);
    min_result = min_cal(plus,minus,mul,div);
    cout << max_result << '\n' << min_result;
    return 0;
}
```

****
# 두번째 시도

가장 중요한 규칙은 모든 숫자의 순서는 정해져있고 연산자 우선 순위를 무시하고 앞에서부터 진행한다. 이다.
또한 숫자의 갯수가 최대 11개로 제한되어 있기 때문에, 최대 가능한 연산 수는 10!=3,628,800 개 이므로 시간 제한에도 걸리지 않고 완수할 수 있다.
따라서 모든 경우의 수를 진행한 후 최대값과 최소값을 얻어낸다.
이때, C++17으로 진행하기 때문에 음수/양수 나눗셈 시 고려할 사항이 없다.

실수했던 부분:
- 결과값 오염: 처음에 코드를 구현할 때
	`if(plus>0){temp += num[index]; index++; plus--; max_min_calc(temp, plus, minus, mul, div, index);}` 
	로 작성하였다. 이로인해 다음 if문으로 넘어갈 때, 이미 plus 연산 결과가 적용된 값들로 계산되어 출력값이 제대로 나오지 않았다.

풀이방식: 
모든 경우의 수를 확인해야하고 특별한 알고리즘이 없기 때문에 백트랙킹 방식으로 재귀함수를 구현하여 풀이하였다.

동작 방식:
1. 기저조건(terminate)
	사용할 연산자가 하나도 남지 않았을 때 == 연산 종료 이므로 결과값을 현재까지의 최대값, 최소값과 비교하여 update.
2. body
	연산자가 4개 이므로 if문 4개를 사용하여 현재 상태값에서 최대 4가지 연산을 진행 후 다음 index로 전진.  
****

## 최종코드

```c++
#include<iostream>
using namespace std;
int num[11];
int max_result=-1000000001;
int min_result=1000000001;
void max_min_calc(int temp, int plus, int minus, int mul, int div, int index){
    if(plus==0 && minus==0 && mul==0 && div==0){
        if(temp > max_result){max_result = temp;}
        if(temp < min_result){min_result = temp;}
        return;
    }
    if(plus>0){max_min_calc(temp+num[index], plus-1, minus, mul, div, index+1);}
    if(minus>0){max_min_calc(temp-num[index], plus, minus-1, mul, div, index+1);}
    if(mul>0){max_min_calc(temp*num[index], plus, minus, mul-1, div, index+1);}
    if(div>0){max_min_calc(temp/num[index], plus, minus, mul, div-1, index+1);}
    return;
}
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,plus,minus,mul,div;
    cin >> n;
    for(int i=0; i<n; i++){cin >> num[i];} 
    cin >> plus >> minus >> mul >> div;
    max_min_calc(num[0],plus,minus,mul,div, 1);
    cout << max_result << '\n' << min_result;
    return 0;
}
```