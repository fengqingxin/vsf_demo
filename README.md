# vsf_emu
port game emulators to vsf

# software/library & license
* vsf_emu -- GPL3.0
* vsf -- Apache2.0
* SDL2 -- zlib
* VisualBoyAdvance -- GPL2.0
* xboot -- MIT
* freetype-2.10.2 -- FTL

# patches

## VisualBoyAdvance
1. Apply VisualBoyAdvance.patch to VisualBoyAdvance
2. Copy rom to vsf_emu/project/vc/winfs_root/vba/
3. Start with command: vba ./winfs_root/vba/xxxx.gba

## freetype
1. Apply freetype.patch to freetype
