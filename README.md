# My miryoku keyboard customization
## This is customizations for a [Let's split](https://benkyriakou.com/posts/lets-split-keyboard-build) keyboard.
This layout may also fitt other keyboards with the [ortho_4x12 layout](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku#ortho_4x12).

Content is found in the QMK development environment. In folder `.../qmk_firmware/users/manna-harbour_miryoku`.
Read more on [Miryoku QMK](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku). A direct link to readme in the described folder.

## Quick and dirty instalation
1. Clone or fork the [QMK project](https://github.com/qmk/qmk_firmware)
1. Explore the folder structure of the QMK project. Go to folder `.../qmk_firmware/users`, Remove folder `./manna-harbour_miryoku` like this `rm -Rf ./manna-harbour_miryoku`
1. Replace `./manna-harbour_miryoku` folder. Clone this repo when current forlder is `.../qmk_firmware/users`

This readme is not  part of the content of the orginal miryoku folder

## Compiling
Here is the command to compile and flash the keyboard layout for the lets'split keyboard:
- Firs of all move to the root QMK folder: `.../qmk_firmware`
```make
make lets_split:manna-harbour_miryoku:flash \
           MIRYOKU_MAPPING=EXTENDED_THUMBS \
           MIRYOKU_ALPHAS=QWERTY \
           MIRYOKU_NAV=VI \
           MIRYOKU_CLIPBOARD=WIN # lets'split, extended thumbs
```
If you whant more ergonomic for pinkies then move whole pinky columns one key down like this:
```make
make lets_split:manna-harbour_miryoku:flash \
           MIRYOKU_MAPPING=SPLIT \
           MIRYOKU_ALPHAS=QWERTY \
           MIRYOKU_NAV=VI \
           MIRYOKU_CLIPBOARD=WIN # lets'split, extended thumbs
```
This layout may also fitt other keyboards with the [ortho_4x12 layout](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku#ortho_4x12). Read the dockumentation for  the [ortho_4x12 layout](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku#ortho_4x12). Change the first line of the comand to your choice, for compiling the code to your keyboard.

## Prerequisites

| App | Description |
| --- | --- |
| [WinCompose](https://github.com/samhocevar/wincompose) |  This is required to instal to get norwegian characters as æ ø å to work |
| [CopyQ](https://github.com/hluk/CopyQ) |  This is not required, but wery handy to browse trough clippboard history |
| [AutoText](https://www.jitbit.com/autotext/) |  This is not required, but wery handy to create text snippets |


### Sym
|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
|  :---: | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  | :---:  |
| +      |   !    | ;      | ''     |    *   |        |        |   ^    |  ~     |    #   | _      | &      |
| -      | ?      | :      | ""     | /      |        |        | {}     | ()     | []     |  $     | Ø      |
| %      | x      | c      | \`     | =      |        |        | }      | )      | ]      | Å      | Æ      |
|        | U_NP   |  U_NP  | \|     |  \     | <      | >      | @      |OSL(SYM)| U_NP   | U_NP   |        |
