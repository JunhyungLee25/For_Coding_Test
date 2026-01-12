#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(const void* a, const void* b){return *(int*)a-*(int*)b;}
int num[8001];
int main(void){
    int n;    
    double mean=0;
    int min,max,maxfreq=0,freq,mid;
    scanf("%d",&n);
    int val;
    scanf("%d",&val);
    num[val+4000]++;
    mean += val;
    min=max=val;
    for(int i=1; i<n; i++){
        scanf("%d",&val);
        num[val+4000]++;
        mean += val;
        if(min > val){min = val;}
        else if(max < val){max = val;}
    }
    int cnt3 = 0;
    for(int i = 0; i<8001; i++){
        cnt3 += num[i];
        if(cnt3 >= n/2 + 1){
            mid = i-4000;
            break;
        }
    }
    for(int i=0; i<8001; i++){
        if(num[i] > maxfreq){
            maxfreq = num[i];
            freq = i;
        }
    }
    int cnt4=0;
    for(int i=0; i<8001; i++){
        if(num[i] == maxfreq){
            cnt4++;
            if(cnt4==2){
                freq = i;
                break;
            }
        }
    }
 
    mean /= n;
    printf("%d\n",(int)round(mean));
    printf("%d\n",mid); 
    printf("%d\n",freq-4000);
    printf("%d\n",max-min);
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <unistd.h>
// #define N 3000007

// int main()
// {
// 	int num[8001]={0};
// 	int t, flag, i, n=0, avg=0, mid=0, mode=0, range=0, count=0;
// 	char *buf=(char *)calloc(N, sizeof(char));
// 	char *c=buf;

// 	ssize_t l=read(0, buf, N);

// 	while(*c != '\n')
// 	{
// 		n*=10;
// 		n+=(*c-'0');
// 		++c;
// 	}
// 	++c;

// 	while(c < buf+l-1)
// 	{
// 		flag=1;
// 		t=0;

// 		if(*c == '-')
// 		{
// 			flag=-1;
// 			++c;
// 		}

// 		while(*c != '\n')
// 		{
// 			t*=10;
// 			t+=(*c-'0');
// 			++c;
// 		}
// 		++c;

// 		t*=flag;

// 		avg+=t;
// 		++num[t+4000];
// 	}
// 	free(buf);

// 	t=0;
// 	for(i=0; i < 8001; ++i)
// 	{
// 		t+=num[i];
// 		if(t > n/2)
// 		{
// 			mid=i-4000;
// 			break;
// 		}
// 	}

// 	for(i=0; i < 8001; ++i)
// 	{
// 		if(count < num[i])
// 		{
// 			count=num[i];
// 			mode=i-4000;
// 			flag=0;
// 		}
// 		else if(count == num[i] && count && !flag)
// 		{
// 			mode=i-4000;
// 			flag=1;
// 		}
// 	}

// 	for(i=8000; i >= 0; --i)
// 		if(num[i])	break;

// 	range=i-4000;

// 	for(i=0; i < 8001; ++i)
// 		if(num[i])	break;

// 	range-=i-4000;

// 	printf("%lld\n%d\n%d\n%d", llround((double)avg/n), mid, mode, range);
// }