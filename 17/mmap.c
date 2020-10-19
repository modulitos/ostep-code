#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

// sizeof(node_t) is 16
typedef struct __node_t {
    int size;
    struct __node_t *next;
} node_t;

// This is an example of how malloc works internally. Given that we have a 4096
// chunk of memory to manage (ie: the heap is 4KB), we can use a free list to
// manage our memory. So we'll initialize the list with one item with a size of 4096.

int main() {
    // The initial size is 4096 (minus the header)
    node_t *head = mmap(
        NULL,
        4096,
        PROT_READ|PROT_WRITE,
        MAP_ANON|MAP_PRIVATE,
        -1,
        0
    );
    // This is the actual size of the list:
    head->size = 4096 - sizeof(node_t); // 4096 - 16 = 4080
    head->next = NULL;
    printf("head->size: %d\n", head->size);
    printf("head->next: %p\n", head->next);
    // The status of the list is that it has a single entry, of size 4080.
    return 0;
}
