#!/bin/bash

while read line || [ -n "$line" ]; do
	for word in $line; do
		echo $word | grep -Ew '[[:digit:]]?[13579]'
	done
done < $1