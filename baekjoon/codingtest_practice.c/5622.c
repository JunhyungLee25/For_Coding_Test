#include <stdio.h>
#include <string.h>

int main() {
    char tel[15]; // 최대 15글자 입력 가능
    scanf("%s", tel);

    int length = strlen(tel);
    int time = 0;

    for (int i = 0; i < length; i++) {
        if (tel[i] == 'A' || tel[i] == 'B' || tel[i] == 'C') {
            time += 3;
        }
        else if (tel[i] == 'D' || tel[i] == 'E' || tel[i] == 'F') {
            time += 4;
        }
        else if (tel[i] == 'G' || tel[i] == 'H' || tel[i] == 'I') {
            time += 5;
        }
        else if (tel[i] == 'J' || tel[i] == 'K' || tel[i] == 'L') {
            time += 6;
        }
        else if (tel[i] == 'M' || tel[i] == 'N' || tel[i] == 'O') {
            time += 7;
        }
        else if (tel[i] == 'P' || tel[i] == 'Q' || tel[i] == 'R' || tel[i] == 'S') {
            time += 8;
        }
        else if (tel[i] == 'T' || tel[i] == 'U' || tel[i] == 'V') {
            time += 9;
        }
        else { 
            time += 10;
        }
    }

    printf("%d\n", time);
    return 0;
}
