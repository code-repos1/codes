#!/bin/bash
#A calculator script
#Author Karlson
#Email kohkarlson@gmail.com

Addition() {
	read -p "Enter first number: " num1
	read -p "Enter second number: " num2
	result=$((num1 + num2))
	echo "$num1 + $num2 = $result"
}

Subtraction() {
	read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        result=$((num1 - num2))
        echo "$num1 - $num2 = $result"
}

Multiplication() {
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        result=$((num1 * num2))
        echo "$num1 \* $num2 = $result"
}

Division() {
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        result=$((num1 / num2))
        echo "$num1 / $num2 = $result"
}

Module() {
        read -p "Enter first number: " num1
        read -p "Enter second number: " num2
        result=$((num1 % num2))
        echo "$num1 % $num2 = $result"
}

Exit() {
	echo "Exiting..."
	sleep 2
	exit
}

while true; do

echo "Welcome. This is a calculator program"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Module"
echo "6. Exit"

read choice

case $choice in
	1) 
		Addition
		;;
	2)
		Subtraction
		;;
	3)
		Multiplication
		;;
	4)
		Division
		;;
	5)
		Module
		;;
	6)
		Exit
		;;
	*)
		echo "Invalid option entered"
		;;
esac
	sleep 1
done
