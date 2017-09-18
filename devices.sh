#!/bin/bash
ls -l /sys/class/net | grep pci | while read line || [ -n "$line" ]; do
	tmp=$(echo $line | grep -oE '[^/]*/net/.*$')
	dev=$(echo $tmp | cut -d'/' -f3)
	pci=$(echo $tmp | cut -d'/' -f1)
	detail=$(lspci -D | grep $pci | cut -d' ' -f2-)
	echo $dev - $detail
done