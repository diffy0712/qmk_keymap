link:
    ln -s ~/qmk_keymap/sofle/ ~/qmk_firmware/keyboards/sofle/keymaps/diffy
    ln -s ~/qmk_keymap/ferris/ ~/qmk_firmware/keyboards/ferris/keymaps/diffy

sofle:
    qmk compile -kb sofle/rev1 -km diffy -e CONVERT_TO=promicro_rp2040
    mv ~/qmk_firmware/sofle_rev1_diffy_promicro_rp2040.uf2 ~/qmk_keymap/.builds

ferris:
    qmk compile -kb ferris/sweep -km diffy -e CONVERT_TO=promicro_rp2040
    mv ~/qmk_firmware/ferris_sweep_diffy_promicro_rp2040.uf2 ~/qmk_keymap/.builds