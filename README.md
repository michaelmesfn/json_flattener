# json_flattener

## requirements
1. nlohmann json must be installed, instructions and packages can be found here:
   https://github.com/nlohmann/json

## how to run the program
1. g++ -Wall -o <<i>FILE_NAME</i>> json_flatten.h json_flatten.cpp
2. cat main.json | ./<<i>FILE_NAME</i>>

## testing
1. g++ -Wall -o <<i>FILE_NAME</i>> test.cpp
2. ./<<i>FILE_NAME</i>>

## notes
If your install of nlohmann json is version 3.9 or above,using the class nlohmann::ordered_json instead of nlohmann::json is preferred.
Replace destinations have been marked with comments on code.
