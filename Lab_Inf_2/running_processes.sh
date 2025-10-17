#!/bin/bash
ps aux
n=$(ps aux | wc -l)
n=$((n-1))
echo "$n"
