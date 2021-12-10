# My miryoku keyboard customization
## This is customizations for a [Let's split](https://benkyriakou.com/posts/lets-split-keyboard-build) keyboard.
Read more on [https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org](https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org)

Customizations is done on the miryoku development branch, described in [this instructions](https://github.com/manna-harbour/qmk_firmware/blob/miryoku/users/manna-harbour_miryoku/miryoku.org#miryoku-)

orginal content is found in the QMK development environment. In folder `.../qmk_firmware/Users/manna-harbour_miryoku`. [Here is a link to that folder in the QMK github repo](https://github.com/manna-harbour/qmk_firmware/tree/miryoku/users/manna-harbour_miryoku)

This readme is not  part of the content of the orginal miryoku folder

Here is the command to compile and flash the keyboard layout:
- Firs of all move to the root QMK folder: `.../qmk_firmware`
```make
make lets_split:manna-harbour_miryoku:flash \
           MIRYOKU_MAPPING=EXTENDED_THUMBS \
           MIRYOKU_ALPHAS=QWERTY \
           MIRYOKU_NAV=VI \
           MIRYOKU_CLIPBOARD=WIN # lets'split, extended thumbs
```



### Sym
|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
|  :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  |
| +      |   !    | ;      | ''     |    *   |        |        |   ^    |  ~     |    #   | _      | &      |
| -      | ?      | :      | ""     | /      |        |        | {}     | ()     | []     |  $     | Ø      |
| %      | x      | c      | \`     | =      |        |        | }      | )      | ]      | Å      | Æ      |
|        | U_NP   |  U_NP  | \|     |  \     | <      | >      | @      |OSL(SYM)| U_NP   | U_NP   |        |




## Personal notes
``` text
Denne kan brukes for å permanent aktivere en layer
key on tap, hold layer on hold, switch to layer on double tap
https://docs.qmk.fm/#/feature_tap_dance?id=example-6
```
