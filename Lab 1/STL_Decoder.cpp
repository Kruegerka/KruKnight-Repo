/**
 * AUTHOR: Kyle Krueger
 * DATE:   3/8/18
 * NAME:   STL_Decoder.cpp
 * The perpous of this program is to read in a STL file
 * then summarize the contents out to the console
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

static double maxX = 0;
static double minX = 0;
static double maxY = 0;
static double minY = 0;
static double maxZ = 0;
static double minZ = 0;
static int numOfFacets = 0;

void compareX(double num);
void compareY(double num);
void compareZ(double num);
bool compareWord(std::string word, std::string refword);

/** 
 * @param argc Number of arguments passed in
 * @param argv Name of the passed in file
 * @return int 0
 */
int main(int argc, char **argv)
{

    //Checks to see if File was imported
    if (argc < 2)
    {
        std::cout << "Filename Was Not Entered" << std::endl;
    }
    //File has been imported
    else
    {
        std::string importedFile = argv[1];
        std::ifstream filein(importedFile.c_str());

        while (filein)
        {
            std::string currentLine;
            getline(filein, currentLine);
            std::istringstream stringStreamIn(currentLine);

            while (stringStreamIn)
            {
                std::string word;
                stringStreamIn >> word;
                int numOfVertex;

                //Checks to see if the word is Facet, then it prints out
                //the facet number and addes to the count
                if (compareWord(word, "facet") && !compareWord(word, "endfacet"))
                {
                    numOfFacets++;
                    std::cout << std::endl
                              << "Facet: " << numOfFacets << std::endl;
                    numOfVertex = 0;
                }
                else if (compareWord(word, "vertex"))
                {
                    double currentNum;

                    //The spaces were added infrom of vertex because setw() didn't want to work
                    std::cout << std::setw(4) << std::endl
                              << "  Vertex: " << numOfVertex << std::endl;

                    //X Handler
                    stringStreamIn >> word;
                    std::cout << std::setw(6) << "X:" << word << std::endl;
                    currentNum = std::stod(word.c_str(), NULL);
                    compareX(currentNum);

                    //Y Handler
                    stringStreamIn >> word;
                    std::cout << std::setw(6) << "Y:" << word << std::endl;
                    currentNum = std::stod(word.c_str(), NULL);
                    compareY(currentNum);

                    //Z Handler
                    stringStreamIn >> word;
                    std::cout << std::setw(6) << "Z:" << word << std::endl;
                    currentNum = std::stod(word.c_str(), NULL);
                    compareZ(currentNum);

                    numOfVertex++;
                }
            }
        }

        filein.close();

        //Prints out static values
        std::cout << std::setw(6) << std::endl
                  << "Number Of Facets: " << numOfFacets << std::endl;

        std::cout << std::setw(6) << std::endl
                  << "Max X: " << maxX << std::endl;
        std::cout << std::setw(6) << "Min X: " << minX << std::endl;

        std::cout << std::setw(6) << std::endl
                  << "Max Y: " << maxY << std::endl;
        std::cout << std::setw(6) << "Min Y: " << minY << std::endl;

        std::cout << std::setw(6) << std::endl
                  << "Max Z: " << maxZ << std::endl;
        std::cout << std::setw(6) << "Min Z: " << minZ << std::endl;
    }
    return 0;
}

/**
 * @brief Compares the 2 passed in words
 * 
 * @param word Word to check
 * @param refword Reffrence word to check to
 * @return true The two words are the same
 * @return false The two words are diffrent
 */
bool compareWord(std::string word, std::string refword)
{
    if (word.find(refword) == std::string::npos)
    {
        return false;
    }
    return true;
}

/**
 * @brief Checks a passed in number compared to the min and max value of X
 * 
 * @param num Passed in number
 */
void compareX(double num)
{
    if (num > maxX)
    {
        maxX = num;
    }
    else if (num < minX || minX == 0)
    {
        minX = num;
    }
}

/**
 * @brief Checks a passed in number compared to the min and max value of X
 * 
 * @param num Passed in number
 */
void compareY(double num)
{
    if (num > maxY)
    {
        maxY = num;
    }
    else if (num < minY || minY == 0)
    {
        minY = num;
    }
}

/**
 * @brief Checks a passed in number compared to the min and max value of X
 * 
 * @param num Passed in number
 */
void compareZ(double num)
{
    if (num > maxZ)
    {
        maxZ = num;
    }
    else if (num < minZ || minZ == 0)
    {
        minZ = num;
    }
}