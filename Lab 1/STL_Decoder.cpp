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
 

 static double maxX;
 static double minX;
 static double maxY;
 static double minY;
 static double maxZ;
 static double minZ;
 static int numOfFacets=0;
 void compareX(double num);
 bool compareWord(std::string word, std::string refword);

 int main(int argc, char** argv){

    //Checks to see if File was imported
    if(argc < 2){
        std::cout << "Filename Was Not Entered" << std::endl;
    }
    else{
        std::string importedFile = argv[1];
        std::ifstream filein(importedFile.c_str());
        
        while(filein){
            std::string currentLine;
            getline(filein, currentLine);
            std::istringstream stringStreamIn(currentLine);
            
            while(stringStreamIn){
                std::string word;
                stringStreamIn >> word;
                int numOfVertex;
                //Checks to see if the word is Facet, then it prints out the facet number and addes to the count
                if(compareWord(word, "facet") && !compareWord(word, "endfacet")){
                    numOfFacets++;
                    std::cout <<std::endl << "Facet: " << numOfFacets <<std::endl;
                    numOfVertex = 0;
                }
                else if(compareWord(word, "vertex")){
                    double currentNum;
                    std::cout << std::setw(4) << "Vertex: " << numOfVertex << std::endl;
                    stringStreamIn >> word;
                    std::cout << std::setw(6) << "X:" << word << std::endl;
                    currentNum = std::stod(word.c_str(), NULL);
                    compareX(currentNum);

                    numOfVertex++;
                }
            }

        }
    }

    return 0;
 }

bool compareWord(std::string word, std::string refword){
    if(word.find(refword) == std::string::npos){
        return false;
    }
    return true;
}

void compareX(double num){
    if(num > maxX){
        maxX = num;
    }
    else if(num < minX){
        minX = num;
    }
}