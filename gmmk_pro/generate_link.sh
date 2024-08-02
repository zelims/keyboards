#!/bin/bash

print_usage() {
    cat << EOF >&2

Usage: $0 [args]
EOF
}

# using xelus22's firmware for key cancellation
# right now it has not been merged
# PR: https://github.com/qmk/qmk_firmware/pull/24000
QMK_HOME="$HOME/projects/xelus22_qmk_firmware"
KEYMAP_ROOT="$QMK_HOME/keyboards/gmmk/pro/rev1/ansi/keymaps/zelims"

# check if the keymap exists
if [[ -d $KEYMAP_ROOT ]]; then
	echo "Cleaning up old symlink"
	rm -rf $KEYMAP_ROOT
fi

cd $QMK_HOME
git pull origin master

echo "Re-linking working directory to $KEYMAP_ROOT"
# return to previous directory (hopefully where )
cd -
ln -s $PWD $KEYMAP_ROOT