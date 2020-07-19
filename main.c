#include <stdlib.h>
#include <stdio.h>
#include "md4.h"

#define ARRAY(name, size) \
    unsigned char name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

void md4(void) {
    struct md4_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[16];

    rhash_md4_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_md4_update(&ctx, msg, i);
    }
    rhash_md4_fina(&ctx, r);
}

int main(void) {
    md4();
    return 0;
}
