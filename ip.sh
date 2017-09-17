#!/bin/bash
ip route get $1 | grep -oE 'src [[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' | cut -d' ' -f2