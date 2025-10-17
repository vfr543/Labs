#!/bin/bash
read message
echo "$message" | nc localhost 12345
