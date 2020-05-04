#!/bin/bash

make clean

rm -rf out/
build-wrapper --out-dir out/ make all
make check
# valgrind --leak-check=full --show-leak-kinds=all -s --xml=yes --xml-file=out/valgrind.xml test/gtest --gtest_output=xml:out/xunit.xml
test/gtest --gtest_output=xml:out/xunit.xml
gcovr -x -r . > out/gcov.xml
cppcheck --quiet --check-config --suppress=missingIncludeSystem --enable=all --xml --xml-version=2 -I src src 2> out/cppcheck.xml
rats -w 3 --xml src > out/rats.xml
find . | grep ".*\.cpp\|.*\.h" | vera++ -d -s -c out/vera.xml
sonar-scanner
