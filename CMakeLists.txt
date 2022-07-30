cmake_minimum_required(VERSION 3.20)
project(PROJECT C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJECT main.c TripsArrayFunctions.c CitiesArrayFunctions.c CustomersFunctions.c CityPollFunctions.c GeneticAlgorithm.c)
