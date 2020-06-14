# vsf_demo
demos for vsf

# software/library & license
* vsf_emu -- GPL3.0
* vsf -- Apache2.0
* SDL2 -- zlib
* VisualBoyAdvance -- GPL2.0
* xboot -- MIT
* freetype-2.10.2 -- FTL
* zlib -- zlib
* libpng -- PNG Reference Library License v2
* jpeg-9c -- 

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
