#!/usr/bin/python3
import os
import sys

PLAT='SC7280'
BIN_FOLDER=f'bin/{PLAT}'
SRC_FOLDER=f'src/{PLAT}'
GEN_FOLDER=f'gen/{PLAT}'
IDA_OUT=f'{SRC_FOLDER}/libqtisec.c'

def get_cmd_result(cmd):
    return os.popen(cmd).read()

def nm(filename):
    return get_cmd_result('nm ' + filename)

def ls(folder):
    return [(pika.split(' ')[-1] if len(pika) else '') for pika in get_cmd_result('ls -l ' + folder).split('\n')][1:-1]

def grep(function):
    return get_cmd_result(f'grep " {function}(" {SRC_FOLDER}/libqtisec.h')

def get_line_number(function):
    s = get_cmd_result(f'grep -n " {function}(" {SRC_FOLDER}/libqtisec.c | grep -v ";"').split(':')[0]
    if s == '':
        return -1
    return int(s)

def get_function_body(function):
    line_number = get_line_number(function)
    if line_number == -1:
        return ''
    f = open(IDA_OUT, 'r')
    lines = f.readlines()
    for i in range(int(line_number), len(lines)):
        if lines[i][0] == '}' != -1:
            return ''.join(lines[line_number-1:i+1]) + '\n\n'

obj_list=ls(BIN_FOLDER)
# print(obj_list)

def parse_nm_result(s):
    L = []
    P = []
    for l in s.split('\n'):
        lul = l.split(' ')
        if len(lul) == 3 and lul[1] == 'T':
            L.append(lul[-1])
            P.append(grep(lul[-1]))
    return (s, L, P)

# @return (source_file, header_file, nm_return, func_names, prototype_lists)
def nm_all_objs():
    L = []
    for obj in obj_list:
        nm_r, funcs, protos = parse_nm_result(nm(f'{BIN_FOLDER}/{obj}'))
        L.append((obj[0:-2] + '.c', obj[0:-2] + '.h', nm_r, funcs, protos))
    return L

print(nm_all_objs()[0])

def gen_all_c_files():
    nms = nm_all_objs()
    for c_file, h_file, nm_r, funcs, protos in nms:
        with open(f'{GEN_FOLDER}/{h_file}', 'w') as f:
            f.write('#pragma once\n#include "defs.h"\n')
            for p in protos:
                f.write(p)
        with open(f'{GEN_FOLDER}/{c_file}', 'w') as f:
            f.write(f'/*{nm_r}*/\n#include "{h_file}"\n#include "defs.h"\n#include <stdbool.h>\n#include <stdint.h>\n#include <stddef.h>\n')
            for func in funcs:
                f.write(get_function_body(func) + '\n')

gen_all_c_files()

# def gen_func_list(obj_list):
#     L = []
#     for obj in obj_list:
#         L += parse_nm_result(nm(f'{BIN_FOLDER}/{obj}'))
#     return L

