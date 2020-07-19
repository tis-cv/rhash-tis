# PicoLisp tis.config file generator
(de prn (F M)
   (prinl "{")
   (printsp "name" ': (pack F " - " M))
   (prinl ",")
   (printsp "files" ': "all")
   (prinl ",")
   (printsp "machdep" ': (text M))
   (prinl ",")
   (printsp "raw_options" ':)
   (prin "{ ")
   (printsp "-no-results" ': "true")
   (prinl "} ,")
   (printsp "main" ': (text F))
   (prinl)
   (prinl "}") )
(setq
   *M
   (quote
      sparc_64 sparc_32
      x86_32 x86_64
      x86_win32 x86_win64
      armeb_eabi arm_eabi aarch64 aarch64eb
      rv64ifdq rv32ifdq
      mips_o32 mips_n32 mips_64 mipsel_64
      mipsel_n32 apple_ppc_32
   )
   *F
   (quote
      md4 md5 sha1 tiger tth torrent ed2k aich whirlpool
      ripemd160 gost94 gost94pro has160 gost12_256 sha224
      sha256 sha384 sha512 edonr224 edonr256 edonr384 edonr512
      sha3_224 sha3_256 sha3_384 sha3_512 snefru128 snefru256
   )
   *L
   (make
      (for F *F
         (for M *M
            (link (cons F M)) ) ) ) )
(out "tis.config"
   (prinl "// Auto genetated file")
   (prinl "[")
   (for (L *L L (cdr L))
      (let (F (caar L)  M (cdar L))
         (prn F M)
         (and (cdr L) (prinl ",")) ) )
   (prinl "]") )
(bye)
