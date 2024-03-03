/*
        Created by: Trevor Dunn and Sameer Merchant
        Creation Date: February 28, 2024
        Project Name: Movie Rental Database
        Purpose: Create a database of movies to help ensure that we have a firm
        grasp on classes for upcoming labs and projects in Programming
        Fundamentals II

*/

#include "movie.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

std::string getFileName();
std::vector<std::Movie> getFileInformation();

int main() {
  // Get some basic information
  std::string userName;
  std::cout << "What is your name?" << std::endl;
  getline(std::cin, userName);

  return 0;
}
