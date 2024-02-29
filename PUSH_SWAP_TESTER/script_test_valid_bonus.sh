#!/bin/bash

##################################################
# Checks is an argument is numeric
is_numeric() {
    if [[ "$1" =~ ^[0-9]+$ ]];
	then
        return 0
    else
        return 1
	fi
}

##################################################
# Checks if two arguments have been given
if [ $# -ne 2 ];
then
	echo "ERROR - Two arguments expected"
	exit 1
fi

# Checks if both arguments are numbers
if ! is_numeric "$1" || ! is_numeric "$2";
then
	echo "ERROR - The arguments have to be numbers"
	exit 1
fi

# Checks if the generator.py file exists
if [ ! -f "generator.py" ]; then
    echo "ERROR - generator.py file has not been found"
    exit 1
fi

# Checks if ./push_swap exists
if [ ! -f "./push_swap" ]; then
    echo "ERROR - push_swap program has not been found"
    exit 1
fi

# Checks if ./checker_linux exists
if [ ! -f "./checker" ]; then
    echo "ERROR - checker_linux program has not been found"
    exit 1
fi


##################################################
# Main program
stack_size="$1"
nb_iteration="$2"
for (( i=0; i<$nb_iteration; i++ ));
do
	if [ $(($i % 100)) -eq 0 ];
	then
		echo "#LOOP $i"
	fi
	ARG=$(python3 generator.py $stack_size);
	res=$(./push_swap $ARG | ./checker $ARG)
	if [ "$res" != "OK" ];
	then
		echo "####################"
		echo "ERROR"
		echo $ARG
		exit 1
	fi
done
echo "####################"
