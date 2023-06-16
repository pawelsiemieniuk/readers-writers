#!/bin/bash

ARG_NUM=1
VERSION=$1
READERS=$2
WRITERS=$3
MAX_TIME=5
REST_TIME=1

error(){
    case "$1" in 
    "1") echo 'Error: One or more given arguments are invalid.' ;;
    "2") echo 'Error: Wrong number of arguments.' ;;
    "3") echo 'Error: Invalid options' ;;
    esac
    echo "Try './run.sh -h' for more information."
    exit
}

help(){
    echo "Usage: ./run.sh [OPTION] ... VERSION READERS WRITERS"
    echo "Runs VERSION of 'readers-writers-problem' program with READERS and WRITERS as arguments."
    echo ""
    echo "OPTIONs:"
    echo "  -m          Set maxium library usage time"
    echo "  -r          Set resting time after library usage"
    echo "  -h          Display this help and exit"
    echo ""
    echo "READERS   -   Number of readers created in program."
    echo "WRITERS   -   Number of writers created in program."
    echo ""
    echo "Available VERSIONs:"
    echo "  1) 'wstarv'  -   Program runs with possibility of writers starvation."
    echo "  2) 'rstarv'  -   Program runs with possibility of readers starvation."
    echo "  3) 'exclude' -   Program runs excluding possibility of starvation for any of writers and readers."
    echo "VERSION could be either the number or the name of the program version."
    exit
}


while getopts ":hr:m:" option; do
    case $option in 
        h)
            help;;
        m)
            if [[ $OPTARG == +([0-9]) ]]
            then
                MAX_TIME=$OPTARG
                ((ARG_NUM+=2))
            else
                error "3"
            fi ;;
        r)
            if [[ $OPTARG == +([0-9]) ]]
            then
                REST_TIME=$OPTARG
                ((ARG_NUM+=2))
            else
                error "3"
            fi ;;
        \?)
            error "3" ;;
    esac
done


if [ "$1" == "--help" ]
then
    help
elif [[ $#>=3 && $#<=8 ]]
then
    VERSION=${!ARG_NUM}; ((ARG_NUM++))
    READERS=${!ARG_NUM}; ((ARG_NUM++))
    WRITERS=${!ARG_NUM}

    echo $VERSION $READERS $WRITERS
    
    if [[ $READERS == +([0-9]) && $WRITERS == +([0-9]) ]]
    then
        if [[ $VERSION == 1 || "$VERSION" == "wstarv" ]]
        then ./bin/readers-writers-wstarv $READERS $WRITERS $MAX_TIME $REST_TIME

        elif [[ $VERSION == 2 || "$VERSION" == "rstarv" ]]
        then ./bin/readers-writers-rstarv $READERS $WRITERS $MAX_TIME $REST_TIME

        elif [[ $VERSION == 3 || "$VERSION" == "exclude" ]]
        then ./bin/readers-writers-exclude $READERS $WRITERS $MAX_TIME $REST_TIME
        
        else
            error "1"
        fi
    else
        error "1"
    fi
else
    error "2"
fi
