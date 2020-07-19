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
