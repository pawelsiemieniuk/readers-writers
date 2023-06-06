#!/bin/bash

error_args(){
    case "$1" in 
    "1") echo 'One or more given arguments are invalid.' ;;
    "2") echo 'Wrong number of arguments.' ;;
    esac
    echo "Try './run.sh --help' for more information."
}

if [ "$1" == "--help" ]
then
    echo "Usage: ./run.sh [VERSION] [READERS] [WRITERS]"
    echo "Runs VERSION of 'readers-writers-problem' program with READERS and WRITERS as arguments."
    echo ""
    echo "READERS   -   Number of readers created in program."
    echo "WRITERS   -   Number of writers created in program."
    echo ""
    echo "Available VERSIONs:"
    echo "  1) 'wstarv'  -   Program runs with possibility of writers starvation."
    echo "  2) 'rstarv'  -   Program runs with possibility of readers starvation."
    echo "  3) 'exclude' -   Program runs excluding possibility of starvation for any of writers and readers."
    echo "VERSION could be either the number or the name of the program version."
elif [ $# == 3 ]
then
    if [[ $2 == +([0-9]) && $3 == +([0-9]) ]]
    then
        if [[ $1 == 1 || "$1" == "wstarv" ]]
        then `./bin/readers-writers-wstarv $2 $3`

        elif [[ $1 == 2 || "$1" == "rstarv" ]]
        then `./bin/readers-writers-rstarv $2 $3`

        elif [[ $1 == 3 || "$1" == "exclude" ]]
        then `./bin/readers-writers-exclude $2 $3`
        
        else
            error_args "1"
        fi
    else
        error_args "1"
    fi
else
    error_args "2"
fi