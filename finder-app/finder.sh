#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

filesdir=$1
if [ ! -d "$filesdir" ]; then
    exit 1
fi
searchstr=$2

total_file_count=$(find "$filesdir" -type f | wc -l)
line_match_count=$(grep "$searchstr" -r "$filesdir" --text | wc -l)

echo "The number of files are $total_file_count and the number of matching lines are $line_match_count"
