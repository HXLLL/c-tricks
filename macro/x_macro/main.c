#include <string.h>
#include <stdio.h>

typedef char String[255];

typedef struct {
    #define PERSON_MEMBER_FUNCTION(x, type) type x;
    #include "person.def"
} person_t;

void init(person_t *p) {
    #define PERSON_MEMBER_FUNCTION(x, type) memset(&(p->x), 0, sizeof(type));
    #include "person.def"
}

#define print_int(x) printf("%d\n", x)
#define print_double(x) printf("%.3lf\n", x)
#define print_String(x) printf("%s\n", x)

void print(person_t *p) {
    #define PERSON_MEMBER_FUNCTION(x, type) \
        printf(#x ": "); \
        print_##type(p->x); 
    #include "person.def"
}

int main() {
    person_t p;
    init(&p);
    p = (person_t) { .height=123, .weight=456.3 };
    strcpy(p.name, "alice");
    print(&p);
}