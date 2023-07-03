#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct timeval mytime;
    long long tmp1;
    long tmp2;


    // 현재 시간을 얻어온다.
    gettimeofday(&mytime, NULL);
    tmp1 = (mytime.tv_sec * 1000) + (mytime.tv_usec / 1000);
    tmp2 = (mytime.tv_sec * 1000) + (mytime.tv_usec / 1000);
    printf("%lld //// %ld\n", tmp1, tmp2);
    return 0;
}