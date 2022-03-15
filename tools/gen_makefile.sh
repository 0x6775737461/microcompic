#!/usr/bin/env bash

makefile_template=\
'''file := replace_me
chip := 16f628a

hex_file := $(file).hex
c_file := $(file).c

all: hex #clean

hex: $(file).c
	 echo "Gerando o arquivo " $(hex_file)
	 xc8 -V --chip=$(chip) $(c_file)

# TODO:
# limpa todos os arquivos gerados pelo xc8,
# exceto o *.c e *.hex... perceba que ta limpando
# o próprio Makefile também.
#clean: $(c_file) $(hex_file)
#	 rm $(shell ls | grep -Ev "^*.(c|hex)$")
'''

# Pega o nome do arquivo
get_fname(){
  read -p 'nome do arquivo: ' file_name
}

# Gera o Makefile
gen_file(){
  get_fname

  if test -n "$file_name"; then
    file_name=$(sed "s/replace_me/${file_name}/" \
      <<< "$makefile_template")
  fi

  echo -e "$file_name" > Makefile
}

main() {
  gen_file
}

main 
