# vsf_demo
demos for vsf.
1. Install Visual Studio with clang support
2. apply [patches](#patches)
3. Open vsf_demo/project/vc/vsf_demo.sln, compile and run.

# software/library & license
* vsf_emu -- GPL 3.0
* vsf -- Apache 2.0
* SDL2 -- zlib
* VisualBoyAdvance -- GPL 2.0
* xboot -- MIT
* freetype-2.10.2 -- FTL
* zlib -- zlib
* libpng -- PNG Reference Library License v2
* jpeg-9c -- 
* Roboto -- Apache 2.0
* Font Awesome -- OFD 1.1
* vsfvm -- Apache 2.0

# patches

## VisualBoyAdvance
1. Apply patches/VisualBoyAdvance.patch to VisualBoyAdvance
2. Copy rom to vsf_emu/project/vc/winfs_root/vba/
3. Start with command: vba ./winfs_root/vba/xxxx.gba

## freetype
1. ~~Apply patches/freetype.patch to freetype~~(already applied)

## xboot
1. switch to test_xui branch
2. remove assert.h/ctype.h/io.h/malloc.h/math.h/stdarg.h/stdint.h/stdio.h/stdlib.h/string.h/time.h in xboot/src/include
