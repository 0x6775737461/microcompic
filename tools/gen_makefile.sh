#!/usr/bin/env bash

makefile_template=\
'''file := replace_me
chip := 16f628a

hex_file := $(file).hex
c_file := $(file).c

all: hex #clean

hex: $(file).c
\t echo "Gerando o arquivo " $(hex_file)
\t xc8 -V --chip=$(chip) $(c_file)

clean: $(c_file) $(hex_file)
\t rm $(shell ls | grep -Ev "(^*.(c|hex)$$|Makefile)")
'''

# Gera o Makefile
gen_file(){
  file_name="$1"

  if test -n "$file_name"; then
    file_name=$(sed "s/replace_me/${file_name}/" \
      <<< "$makefile_template")
  fi

  echo -e "$file_name" > Makefile
}

main() {
  gen_file "$1"
}

main "$@"
