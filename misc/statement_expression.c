#include <stdio.h>

#define MIN_FAIL(x, y) ((x) < (y) ? (x) : (y))

#define MIN(x, y)                                                              \
  ({                                                                           \
    typeof(x) _x = (x);                                                        \
    typeof(y) _y = (y);                                                        \
    _x < _y ? _x : _y;                                                         \
  })

#define MAX(x, y)                                                              \
  ({                                                                           \
    typeof(x) _x = (x);                                                        \
    typeof(y) _y = (y);                                                        \
    _x > _y ? _x : _y;                                                         \
  })

int main() {
  int a = 1, b = 3;
  printf("%d\n", MIN_FAIL(a++, b));

  a = 1, b = 3;
  printf("%d\n", MIN(a++, b));

}
