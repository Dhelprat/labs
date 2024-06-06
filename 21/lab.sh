#!/bin/bash

show_usage() {
    echo "Usage: $0 <directory>"
    echo "Traverse the specified directory and display full paths of subdirectories"
}

if [ $# -ne 1 ] # -ne истинно, когда количество аргументов не равно 1
then
echo "error: Incorrect number of arguments"
show_usage
exit 1
fi

if [ "$1" == "info" ] # проверка введенный аргумент равен info
then
show_usage
exit 0
fi

if [ ! -d "$1" ] # -d проверяет существование директории
then
echo "Error: Directory is not exist"
exit 1
fi

# Обходим директории
find "$1" -type d -print

exit 0