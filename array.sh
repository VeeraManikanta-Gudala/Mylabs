#!/bin/bash
declare -a arr
echo "Enter size"
read x
echo "enter elements"
for ((i = 0;i<$x;i++)) do 
read arr[$i]
done
echo ${arr[@]}
while $1
do
echo "enter operation:"
read op
case $op in 
1)
echo "enter element"
read a 
arr=("$a" "${arr[@]}")
echo "inserted"
echo ${arr[@]}
;;
2)
echo "enter element"
read a
arr+=("$a")
echo "inserted"
echo ${arr[@]}
;;
3)
echo "enter element"
read a
echo "enter index"
read b
arr=( "${arr[@]:0:$b}" "$a" "${arr[@]:$b}" )
echo "inserted"
echo ${arr[@]}

;;
4)
echo "delete from beginning"
unset arr[0]
echo ${arr[@]}
;;
5)
echo "delete from end"
unset arr[-1]
echo ${arr[@]}
;;
6)
echo "delete from index"
echo "enter index"
read b
unset arr[$b]
echo ${arr[@]}
;;
7)
echo "search"
echo "enter element"
read a
for ((i = 0;i<$x;i++)) do
if [ "${arr[$i]}" = "$a" ];then
echo "found"
fi
done
;;
8)
echo "sort"
arr=($(printf '%s\n' "${arr[@]}" | sort))
echo ${arr[@]}
;;
*)
echo "invalid"
esac
done