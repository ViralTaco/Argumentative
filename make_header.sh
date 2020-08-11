#!bin/env bash

#project constants:
APP_SRC="./src/Argumentative.hpp"
HEADER_NAME="vt_argumentative.hpp"
QUOM_ARGS="-g VT_.+_HPP -t"

function does_app_exist() {
	hash $@ >/dev/null 2>&1
}

function puts() {
	for line in "$@"; do
		printf "$line\n"
	done
}

if ! does_app_exist quom; then
	puts "Error: Could not find 'quom'"
	puts "If you have pip installed run:"
	puts "\tpip install quom"
	puts "For more info go to: https://github.com/Viatorus/quom"
	exit 1
elif quom $APP_SRC $HEADER_NAME $QUOM_ARGS; then
	if does_app_exist clang-format; then
		clang-format -style=Google --sort-includes -i $HEADER_NAME
	fi
	puts "Done."
	exit $?
fi
