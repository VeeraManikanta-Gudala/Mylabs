#!/bin/bash
echo "Enter the username"
read user
if [ "$user" = "admin" ];then
echo "Enter the password"
read pass
if [ "$pass" = "secret" ]; then
echo "welcome"
elif [ "$pass" = "secret1" -o "$pass" = "secret2" ];then
echo "partially executed"
else
echo "enter correct details"
fi
else
echo "enter correct username"
fi