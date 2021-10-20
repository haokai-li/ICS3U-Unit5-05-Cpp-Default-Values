// Copyright (c) 2021 haokai All rights reserved
//
// Created by: Haokai
// Created on: Oct 2021
// This Program calculate the volume of a cylinder
#include <iostream>
#include <string>
#include <cstring>
#include <locale>
#include <algorithm>

std::string addressPart(std::string fullNameString,
                        int streetNumber,
                        std::string streetTypeString,
                        std::string cityString,
                        std::string provinceString,
                        std::string postalCodeString,
                        int apartmentNumber = 0) {
    // This Program calculate the volume of a cylinder
    std::string finalUpper;

    // process
    if (apartmentNumber != 0) {
        finalUpper = fullNameString
                     + "\n"
                     + std::to_string(apartmentNumber)
                     + "-"
                     + std::to_string(streetNumber)
                     + " "
                     + streetTypeString
                     + "\n"
                     + cityString
                     + " "
                     + provinceString
                     + " "
                     + postalCodeString;
    } else {
        finalUpper = fullNameString
                     + "\n"
                     + std::to_string(streetNumber)
                     + " "
                     + streetTypeString
                     + "\n"
                     + cityString
                     + " "
                     + provinceString
                     + " "
                     + postalCodeString;
    }

    std::for_each(finalUpper.begin(), finalUpper.end(),
    [](char & c) { c = ::toupper(c);});

    return finalUpper;
}

main() {
    // This function just call other functions
    std::string addressFinal;
    std::string userFullNameString;
    std::string userIfApartmentString;
    std::string userApartmentString;
    int userApartmentNumber;
    std::string userStreetString;
    int userStreetNumber;
    std::string userStreetTypeString;
    std::string userCityString;
    std::string userProvinceString;
    std::string userPostalCodeString;


    std::cout << "This Program formats your address to a mailing address."
    << std::endl;
    std::cout << "" << std::endl;

    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, userFullNameString);
    std::cout << "Do you live in a apartment? (y/n): ";
    getline(std::cin, userIfApartmentString);
    if (userIfApartmentString == "y" || userIfApartmentString == "yes") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, userApartmentString);
    }
    std::cout << "Enter your street number: ";
    getline(std::cin, userStreetString);
    std::cout << "Enter your street name AND type (Main St, Express Pkwy...): ";
    getline(std::cin, userStreetTypeString);
    std::cout << "Enter your city: ";
    getline(std::cin, userCityString);
    std::cout << "Enter your province (as an abbreviation, ex: ON, BC..): ";
    getline(std::cin, userProvinceString);
    std::cout << "Enter your postal code (123 456): ";
    getline(std::cin, userPostalCodeString);
    std::cout << "" << std::endl;

    try {
        if (userIfApartmentString == "y" || userIfApartmentString == "yes") {
            userApartmentNumber = std::stoi(userApartmentString);
        }
        userStreetNumber = std::stoi(userStreetString);

        // call functions
        if (userIfApartmentString != "") {
            addressFinal = addressPart(userFullNameString,
                                       userStreetNumber,
                                       userStreetTypeString,
                                       userCityString,
                                       userProvinceString,
                                       userPostalCodeString,
                                       userApartmentNumber);
        } else {
            addressFinal = addressPart(userFullNameString,
                                       userStreetNumber,
                                       userStreetTypeString,
                                       userCityString,
                                       userProvinceString,
                                       userPostalCodeString);
        }

        // output
        std::cout << addressFinal << std::endl;
    } catch (std::invalid_argument) {
        // output
        std::cout << "You didn't enter an integer." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
