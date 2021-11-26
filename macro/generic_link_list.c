/*********************** begin of generic_link_list.h ************************/
#ifndef GENERIC_LINK_LIST_H
#define GENERIC_LINK_LIST_H

typedef struct ll_handle_struct_t {
    struct ll_handle_struct_t *next;
} ll_handle;

/**
 * @brief assume *node* is not NULL, return its successor if it has one,
 * otherwise return NULL
 */
#define NEXT(node)                                                             \
    node->ll.next                                                              \
        ? ((void *)(node->ll.next) - ((void *)&(node->ll) - (void *)node))     \
        : NULL

/**
 * @brief assume *node* and *x* is not NULL, insert *x* after *node* as *node*'s
 * successor
 */
#define INSERT(node, x)                                                        \
    do {                                                                       \
        x->ll.next = node->ll.next;                                            \
        node->ll.next = &x->ll;                                                \
    } while (0)

/**
 * @brief assume *x* is not NULL, insert *x* to *list* as its new head
 */
#define INSERT_FRONT(list, x)                                                  \
    do {                                                                       \
        if (!list) {                                                           \
            list = malloc(sizeof(*list));                                      \
            memset(list, 0, sizeof(*list));                                    \
        }                                                                      \
        INSERT(list, x);                                                       \
    } while (0)

/**
 * @brief assume *node* is not NULL, delete *node*'s successor
 */
#define DELETE_NEXT(node)                                                      \
    do {                                                                       \
        ll_handle *nxt = node->ll.next;                                        \
        node->ll.next = nxt->next;                                              \
        nxt->next = NULL;                                                      \
    } while (0)

/**
 * @brief assume *list* is not empty, delete the first element of list
 */
#define DELETE_FRONT(list)                                                     \
    do {                                                                       \
        DELETE_NEXT(list);                                                     \
    } while (0)

/**
 * @brief return *list*'s head
 */
#define HEAD(list) (list ? NEXT(list) : NULL)

/**
 * @brief return whether *list* is empty
 */
#define EMPTY(list) (!list || !list->ll.next)

#endif

/*********************** end of generic_link_list.h ************************/

/**
 * Below is a sample program, using generic link list to maintain a sorted
 * list, while supporting elements insertion and deletion
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data1 {
    int x;
    ll_handle ll;
};

struct Data2 {
    double y;
    ll_handle ll;
};

int main() {
    struct Data1 *l = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i != n; ++i) {
        char opt[255];
        scanf("%s", opt);

        if (opt[0] == 'i') { // insertion
            int x;
            scanf("%d", &x);
            struct Data1 *rec = malloc(sizeof(struct Data1));
            rec->x = x;

            if (EMPTY(l))
                INSERT_FRONT(l, rec);
            else {
                struct Data1 *head = HEAD(l), *it;
                if (rec->x < head->x)
                    INSERT_FRONT(l, rec);
                else {
                    for (it = head; NEXT(it); it = NEXT(it)) {
                        struct Data1 *nxt = NEXT(it);
                        if (rec->x < nxt->x) break;
                    }
                    INSERT(it, rec);
                }
            }
        } else if (opt[0] == 'd') { // deletion
            int x;
            scanf("%d", &x);
            struct Data1 *it = HEAD(l), *prev = NULL;
            for (; it; prev = it, it = NEXT(it)) {
                if (it->x == x) break;
            }
            if (!it)
                printf("element not found\n");
            else if (!prev) {
                DELETE_FRONT(l);
                free(it);
            } else {
                DELETE_NEXT(prev);
                free(it);
            }
        }

        for (struct Data1 *it = HEAD(l); it; it = NEXT(it)) {
            printf("%d ", it->x);
        }
        puts("");
    }
}