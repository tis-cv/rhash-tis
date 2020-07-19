#include <stdlib.h>
#include <stdio.h>
#include "md4.h"
#include "md5.h"
#include "sha1.h"
#include "tiger.h"
#include "tth.h"
#include "torrent.h"

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
    rhash_md4_final(&ctx, r);
}

void md5(void) {
    struct md5_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[16];

    rhash_md5_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_md5_update(&ctx, msg, i);
    }
    rhash_md5_final(&ctx, r);
}

void sha1(void) {
    struct sha1_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha1_hash_size];

    rhash_sha1_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha1_update(&ctx, msg, i);
    }
    rhash_sha1_final(&ctx, r);
}

void tiger(void) {
    struct tiger_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[tiger_hash_length];

    rhash_tiger_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_tiger_update(&ctx, msg, i);
    }
    rhash_tiger_final(&ctx, r);
}

void tth(void) {
    struct tth_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[64];

    rhash_tth_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_tth_update(&ctx, msg, i);
    }
    rhash_tth_final(&ctx, r);
}

void torrent(void) {
    struct torrent_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[btih_hash_size];

    bt_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        bt_update(&ctx, msg, i);
    }
    bt_final(&ctx, r);
}



int main(void) {
    md4();
    md5();
    sha1();
    tiger();
    tth();
    //torrent();
    return 0;
}
