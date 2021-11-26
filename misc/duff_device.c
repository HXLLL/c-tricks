#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(0));
    int n; scanf("%d",&n);

    int a[n],b[n];
    for (int i=0;i!=n;++i) a[i] = rand() % 10;
    for (int i=0;i!=n;++i) printf("%d ", a[i]);
    puts("");

    int *pa=a,*pb=b;
    int cnt = n / 4;

    /* Copy Data */
    switch (n%4) {
                do {*pb++ = *pa++;
        case 3:     *pb++ = *pa++;
        case 2:     *pb++ = *pa++;
        case 1:     *pb++ = *pa++;
        case 0: } while (cnt--);
    }

    printf("%ld %ld\n", pa-a, pb-b);


    int s1=0,s2=0,s3=0,s4=0;
    int *p1=a,*p2=a+1,*p3=a+2,*p4=a+3;
    cnt = n / 4;

    /* Sum */
    switch (n%4) {
                do {s4 += *p4; p4 += 4;
        case 3:     s3 += *p3; p3 += 4;
        case 2:     s2 += *p2; p2 += 4;
        case 1:     s1 += *p1; p1 += 4;
        case 0: } while (cnt--);
    }

    int sum = s1+s2+s3+s4;
    printf("%d\n", sum);
}
