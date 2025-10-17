#!/bin/bash
while true; do
echo "message recieved" | nc -l -p 12345
done
