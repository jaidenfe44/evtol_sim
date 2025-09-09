#!/bin/bash


build_target='' # Default to empty (no target)
verbose=''


build_sim() {

	echo "Building Sim"

	if [ -d "./bin" ]; then
		rm -rf bin/sim
	else
		mkdir bin
	fi

	incList="-Isrc/"

	srcList="src/*.cpp "

	# Placeholder for any system defines
	defs=""

	clang++ $defs $incList $srcList -o bin/sim $verbose

	# Run the sim
	./bin/sim
}

build_test() {

	echo "Building Test Suite"

	if [ -d "./bin" ]; then
		rm -rf bin/test
	else
		mkdir bin
	fi

	incList="-Isrc/
			 -Itst/"

	srcList="
		tst/*.cpp "

	defs="-D TEST_SUITE"

	clang++ $incList $srcList $defs -o bin/test $verbose

	# Run the test suite
	./bin/test
}

usage() {
	echo "Usage: ./build.sh -t <target> [-v] [-h]"
	echo "    <target>:"
	echo "          sim - Build and run the simulation"
	echo "         test - Build and run the simulation test suite"
	echo "    Options:"
	echo "         -v                  - Build with verbose error messages"
    echo "         -h                  - Display help message"
}


while getopts 't:vh' flag; do
  case "${flag}" in
	t) build_target="${OPTARG}" ;;
	v) verbose='-v' ;;
	h) usage
	   exit 1 ;;
    *) usage
       exit 1 ;;
  esac
done


if [[ "$build_target" = 'test' ]]; then
	build_test
elif [[ "$build_target" = 'sim' ]]; then
	build_sim
else
	usage
fi
