#!/bin/bash

# Test the program with given input that should result in the correct output

# Test 1 : negetive integer
echo "Test 1"
output=$(./main -32)
expected_output="Error: integer must be positive. Try again." 
if [ "$output" == "$expected_output" ]; then
    echo "Pass"
else
    echo "Fail"
fi

# Test 2 : 0
echo "Test 2"
output=$(./main 0)
expected_output="0 = zero dollars and zero cents"
if [ "$output" == "$expected_output" ]; then
    echo "success"
else
    echo "failed"
fi

# Test 3:  value is a million
echo "Test 3"
output=$(./main 100000000)
expected_output="100000000 = one million dollars and zero cents"
if [ "$output" == "$expected_output" ]; then
    echo "success"
else
    echo "failed"
fi

# Test 4: input is a complex number
echo "Test 4"
output=$(./main 123456789)
expected_output="123456789 = one million two hundred thirty-four thousand five hundred sixty-seven and eighty-nine cents"
if [ "$output" == "$expected_output" ]; then
    echo "success"
else
    echo "failed"
fi