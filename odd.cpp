// Copyright (c) 2020 Sydney Kuhn All rights reserved
//
// Created by: Sydney Kuhn
// Created on: Oct 2020
// This program prints the odd numbers in a list of 10 random numbers

#include <iostream>

#include <random>
#include <list>

std::list<int> FindOddNumbers(std::list<int> listOfNumbers) {
    // this function prints the odd numbers
    std::list<int> oddNumbers;
    int loopCounter = 1;

    for (int listItem : listOfNumbers) {
        if (loopCounter % 2 != 0) {
            oddNumbers.push_back(listItem);
        }
        loopCounter += 1;
    }
    return oddNumbers;
}

int main() {
    // this function creates 10 random numbers in a list
    std::list<int> listOfNumbers;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 100);  // [1, 100]
    int loopCounter = 0;
    int randomNumber;
    int numberOfElements;
    int length;
    std::list<int> oddNumbers;
    std::string sNumberOfElements;

    // input, process & output
    std::cout << "How many random numbers would you like : ";
    std::cin >> sNumberOfElements;
    try {
        numberOfElements = std::stoi(sNumberOfElements);
        if (numberOfElements > 0) {
            for (int loopCounter = 0; loopCounter < numberOfElements;
                loopCounter++) {
                randomNumber = idist(rgen);
                listOfNumbers.push_back(randomNumber);
                std::cout << "The random number " << loopCounter + 1 << " is : "
                    << randomNumber << std::endl;
            }
            oddNumbers = FindOddNumbers(listOfNumbers);
            length = oddNumbers.size();

            std::cout << "\nThe numbers in odd positions in the list are : ";
            for (int listItem : oddNumbers) {
                std::cout << listItem << " ";
            }
        } else {
        std::cout << "\nNegative number entered, please try again."
            << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid number entered, please try again." << std::endl;
    }

    std::cout << "\n\nDone." << std::endl;
}
