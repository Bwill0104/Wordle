#!/bin/bash
set -e
g++ -Wall -g main.cpp wordle.cpp -o wordle
./wordle $*