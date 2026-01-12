// 3^(n-1)+1~3^(n-1)*2를 공백으로
// 0<= N <=12
#include <stdio.h>
#include <math.h>
#define SIZE 531442

char s[SIZE];

void cantor(int start, int end)
{
    int length = end - start + 1;
    int part = length / 3;
    if (length == 1)
        return;
    else
    {
        cantor(start, start + part - 1); // left
        cantor(start + part * 2, end);   // right
        for (int i = start + part; i < start + part * 2; i++)
        {
            s[i] = ' ';
        }
    }
}
    
int main(void)
{
    int N;
    while (scanf("%d", &N) != EOF)
    {
        
        int len = (int)pow(3, N);

        for (int i = 0; i < len; i++)
        {
            s[i] = '-';
        }
        s[len] = '\0';
        cantor(0, len - 1);
        printf("%s\n", s);
    }

    return 0;
}