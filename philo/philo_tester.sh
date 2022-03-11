#!/bin/bash

EXEC=./philo
LOGFILE=._log_philo_tester

function	timeout() { perl -e 'alarm shift; exec @ARGV' "$@"; }

function	run_test()
{
	if [[ $# -ge 5 ]]
	then
		NAME=$6
		ARGS="${@:1:5}"
	else
		NAME=$4
		ARGS="${@:1:3}"
	fi

	printf "\n\n\033[34;1m>> Running %s %s %s\033[0m\n" "$NAME" "$EXEC" "$ARGS"

	# timeout 5 ./$EXEC $ARGS > "$LOGFILE_""$NAME"

	shift
	shift
	shift
	shift

	if [[ $# -ge 5 ]]
	then
		shift
	fi

	printf "${*}"

	# cat "$LOGFILE_""$NAME"
}

if [[ ! -f "$EXEC" ]]
then
	printf "\033[31;1mERROR : %s is not a file \033[0m\n" "$EXEC"
	exit 1
fi

run_test 1 800 200 200 "Single_fork" 1

run_test 5 800 200 200 "Simple" 0

run_test 5 800 200 200 7 "Check_max_eat" 2

run_test 4 410 200 200 "Hard" 0
