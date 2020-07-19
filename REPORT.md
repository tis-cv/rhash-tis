Raw list of everything without sort by severity.

```
=================================================================
==425787==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 1024 byte(s) in 1 object(s) allocated from:
    #0 0x55fe1734c942 in realloc (/home/mpech/rhash-tis/a.out+0x17e942)
    #1 0x55fe174aab76 in bt_vector_add_ptr (/home/mpech/rhash-tis/a.out+0x2dcb76)
    #2 0x55fe174ab973 in bt_store_piece_sha1 (/home/mpech/rhash-tis/a.out+0x2dd973)
    #3 0x55fe174abfba in bt_final (/home/mpech/rhash-tis/a.out+0x2ddfba)
    #4 0x55fe17400922 in torrent (/home/mpech/rhash-tis/a.out+0x232922)
    #5 0x55fe17400a0c in main (/home/mpech/rhash-tis/a.out+0x232a0c)
    #6 0x7f283c3d6001 in __libc_start_main (/usr/lib/libc.so.6+0x27001)

Direct leak of 256 byte(s) in 1 object(s) allocated from:
    #0 0x55fe1734c942 in realloc (/home/mpech/rhash-tis/a.out+0x17e942)
    #1 0x55fe174b1a8a in bt_str_ensure_length (/home/mpech/rhash-tis/a.out+0x2e3a8a)
    #2 0x55fe174aed79 in bt_str_append (/home/mpech/rhash-tis/a.out+0x2e0d79)
    #3 0x55fe174afd81 in bt_bencode_int (/home/mpech/rhash-tis/a.out+0x2e1d81)
    #4 0x55fe174addbb in bt_generate_torrent (/home/mpech/rhash-tis/a.out+0x2dfdbb)
    #5 0x55fe174abfc3 in bt_final (/home/mpech/rhash-tis/a.out+0x2ddfc3)
    #6 0x55fe17400922 in torrent (/home/mpech/rhash-tis/a.out+0x232922)
    #7 0x55fe17400a0c in main (/home/mpech/rhash-tis/a.out+0x232a0c)
    #8 0x7f283c3d6001 in __libc_start_main (/usr/lib/libc.so.6+0x27001)

Indirect leak of 5120 byte(s) in 1 object(s) allocated from:
    #0 0x55fe1734c5b9 in malloc (/home/mpech/rhash-tis/a.out+0x17e5b9)
    #1 0x55fe174ab90e in bt_store_piece_sha1 (/home/mpech/rhash-tis/a.out+0x2dd90e)
    #2 0x55fe174abfba in bt_final (/home/mpech/rhash-tis/a.out+0x2ddfba)
    #3 0x55fe17400922 in torrent (/home/mpech/rhash-tis/a.out+0x232922)
    #4 0x55fe17400a0c in main (/home/mpech/rhash-tis/a.out+0x232a0c)
    #5 0x7f283c3d6001 in __libc_start_main (/usr/lib/libc.so.6+0x27001)

SUMMARY: AddressSanitizer: 6400 byte(s) leaked in 3 allocation(s).
```

```
gost12.c:809:3: runtime error: index 10 out of bounds for type 'uint64_t [8]'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior gost12.c:809:3 in 
=================================================================
==427505==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffe4d4700d0 at pc 0x55d9a23f736e bp 0x7ffe4d46fd90 sp 0x7ffe4d46f540
WRITE of size 5 at 0x7ffe4d4700d0 thread T0
    #0 0x55d9a23f736d in __asan_memcpy (/home/mpech/rhash-tis/a.out+0x17d36d)
    #1 0x55d9a2456fd2 in rhash_gost12_update (/home/mpech/rhash-tis/a.out+0x1dcfd2)
    #2 0x55d9a24ae7fa in gost12_256 (/home/mpech/rhash-tis/a.out+0x2347fa)
    #3 0x55d9a24ae91f in main (/home/mpech/rhash-tis/a.out+0x23491f)
    #4 0x7ff88614e001 in __libc_start_main (/usr/lib/libc.so.6+0x27001)
    #5 0x55d9a23550bd in _start (/home/mpech/rhash-tis/a.out+0xdb0bd)

Address 0x7ffe4d4700d0 is located in stack of thread T0 at offset 304 in frame
    #0 0x55d9a24ae4ef in gost12_256 (/home/mpech/rhash-tis/a.out+0x2344ef)

  This frame has 3 object(s):
    [32, 296) 'ctx' <== Memory access at offset 304 overflows this variable
    [368, 496) 'msg'
    [528, 560) 'r'
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow (/home/mpech/rhash-tis/a.out+0x17d36d) in __asan_memcpy
Shadow bytes around the buggy address:
  0x100049a85fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a85fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a85fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a85ff0: 00 00 00 00 f1 f1 f1 f1 00 00 00 00 00 00 00 00
  0x100049a86000: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x100049a86010: 00 00 00 00 00 00 00 00 00 f2[f2]f2 f2 f2 f2 f2
  0x100049a86020: f2 f2 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a86030: 00 00 f2 f2 f2 f2 00 00 00 00 f3 f3 f3 f3 f3 f3
  0x100049a86040: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a86050: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100049a86060: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==427505==ABORTING
make: *** [Makefile:2: all] Error 1
```

