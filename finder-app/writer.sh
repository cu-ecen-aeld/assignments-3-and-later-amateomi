#!/bin/sh

set -e

if [ $# -ne 2 ]; then
    exit 1
fi

writefile=$1
writestr=$2

if [ ! -f "$writefile" ]; then
    mkdir -p "$(dirname $writefile)"
fi

echo "$writestr" >"$writefile"
