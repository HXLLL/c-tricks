/************************** begin of coroutine.h **************************/

//! never use two YIELDs in one line, never use any YIELDs inside a switch 
// block.

#define BEGIN static int state=0; switch (state) { case 0:;
#define END(v) } return (v)
#define YIELD(v) do { state=__LINE__;return (v);case __LINE__:; }while (0)
#define RETURN(v) do { state=__LINE__;case __LINE__:;return(v);} while(0)

/*************************** end of coroutine.h ***************************/

/***
 * sample program
 ***/

#include <stdio.h>

int fib() {
    static int p0=0,p1=1;
    BEGIN;
        while (1) {
            int tmp = p1+p0;
            p0=p1;
            p1=tmp;
            YIELD(p1);
            if (p1 % 7 == 0) RETURN(p1);
        }
    END(-1);
}

int main() {
    int n;scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        printf("%d\n", fib());
        getchar();
    }
}
