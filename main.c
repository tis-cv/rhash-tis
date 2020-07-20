#include <stdlib.h>
#include <stdio.h>
#include "md4.h"
#include "md5.h"
#include "sha1.h"
#include "tiger.h"
#include "tth.h"
#include "torrent.h"
#include "ed2k.h"
#include "aich.h"
#include "whirlpool.h"
#include "ripemd-160.h"
#include "gost94.h"
#include "has160.h"
#include "gost12.h"
#include "sha256.h"
#include "sha512.h"
#include "edonr.h"
#include "sha3.h"
#include "snefru.h"

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
    bt_cleanup(&ctx);
}

void ed2k(void) {
    struct ed2k_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[16];

    rhash_ed2k_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_ed2k_update(&ctx, msg, i);
    }
    rhash_ed2k_final(&ctx, r);
}


void aich(void) {
    struct aich_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[20];

    rhash_aich_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_aich_update(&ctx, msg, i);
    }
    rhash_aich_final(&ctx, r);
}

void whirlpool(void) {
    struct whirlpool_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[64];

    rhash_whirlpool_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_whirlpool_update(&ctx, msg, i);
    }
    rhash_whirlpool_final(&ctx, r);
}

void ripemd160(void) {
    struct ripemd160_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[ripemd160_hash_size];

    rhash_ripemd160_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_ripemd160_update(&ctx, msg, i);
    }
    rhash_ripemd160_final(&ctx, r);
}

void gost94(void) {
    struct gost94_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[gost94_hash_length];

    rhash_gost94_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_gost94_update(&ctx, msg, i);
    }
    rhash_gost94_final(&ctx, r);
}

void gost94pro(void) {
    struct gost94_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[gost94_hash_length];

    rhash_gost94_cryptopro_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_gost94_update(&ctx, msg, i);
    }
    rhash_gost94_final(&ctx, r);
}

void has160(void) {
    struct has160_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[has160_hash_size];

    rhash_has160_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_has160_update(&ctx, msg, i);
    }
    rhash_has160_final(&ctx, r);
}

void gost12_256(void) {
    struct gost12_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[gost12_256_hash_size];

    rhash_gost12_256_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_gost12_update(&ctx, msg, i);
    }
    rhash_gost12_final(&ctx, r);
}

void sha224(void) {
    struct sha256_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha224_hash_size];

    rhash_sha224_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha256_update(&ctx, msg, i);
    }
    rhash_sha256_final(&ctx, r);
}


void sha256(void) {
    struct sha256_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha256_hash_size];

    rhash_sha256_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha256_update(&ctx, msg, i);
    }
    rhash_sha256_final(&ctx, r);
}

void sha384(void) {
    struct sha512_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha384_hash_size];

    rhash_sha384_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha512_update(&ctx, msg, i);
    }
    rhash_sha512_final(&ctx, r);
}

void sha512(void) {
    struct sha512_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha512_hash_size];

    rhash_sha512_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha512_update(&ctx, msg, i);
    }
    rhash_sha512_final(&ctx, r);
}

void edonr224(void) {
    struct edonr_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[edonr224_hash_size];

    rhash_edonr224_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_edonr256_update(&ctx, msg, i);
    }
    rhash_edonr256_final(&ctx, r);
}

void edonr256(void) {
    struct edonr_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[edonr256_hash_size];

    rhash_edonr256_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_edonr256_update(&ctx, msg, i);
    }
    rhash_edonr256_final(&ctx, r);
}

void edonr384(void) {
    struct edonr_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[edonr384_hash_size];

    rhash_edonr384_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_edonr512_update(&ctx, msg, i);
    }
    rhash_edonr512_final(&ctx, r);
}

void edonr512(void) {
    struct edonr_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[edonr512_hash_size];

    rhash_edonr512_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_edonr512_update(&ctx, msg, i);
    }
    rhash_edonr512_final(&ctx, r);
}

void sha3_224(void) {
    struct sha3_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha3_224_hash_size];

    rhash_sha3_224_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha3_update(&ctx, msg, i);
    }
    rhash_sha3_final(&ctx, r);
}

void sha3_256(void) {
    struct sha3_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha3_256_hash_size];

    rhash_sha3_256_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha3_update(&ctx, msg, i);
    }
    rhash_sha3_final(&ctx, r);
}

void sha3_384(void) {
    struct sha3_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha3_384_hash_size];

    rhash_sha3_384_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha3_update(&ctx, msg, i);
    }
    rhash_sha3_final(&ctx, r);
}

void sha3_512(void) {
    struct sha3_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[sha3_512_hash_size];

    rhash_sha3_512_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_sha3_update(&ctx, msg, i);
    }
    rhash_sha3_final(&ctx, r);
}

void snefru128(void) {
    struct snefru_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[snefru128_hash_length];

    rhash_snefru128_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_snefru_update(&ctx, msg, i);
    }
    rhash_snefru_final(&ctx, r);
}

void snefru256(void) {
    struct snefru_ctx ctx;
    ARRAY(msg, 128);
    unsigned char r[snefru256_hash_length];

    rhash_snefru256_init(&ctx);
    for (size_t i = 0; i < 128; i++) {
        rhash_snefru_update(&ctx, msg, i);
    }
    rhash_snefru_final(&ctx, r);
}


int main(void) {
    md4();
    md5();
    sha1();
    tiger();
    tth();
    torrent();
    ed2k();
    aich();
    whirlpool();
    ripemd160();
    gost94();
    gost94pro();
    has160();
    //gost12_256();
    sha224();
    sha256();
    sha384();
    sha512();
    //edonr224();
    //edonr256();
    edonr384();
    edonr512();
    sha3_224();
    sha3_256();
    sha3_384();
    sha3_512();
    snefru128();
    snefru256();
    return 0;
}
