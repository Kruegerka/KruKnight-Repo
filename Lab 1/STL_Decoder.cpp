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
                if(compareWord(word, "facet")){
                    numOfFacets++;
                    double currentNum;
                    stringStreamIn.ignore(8);
                    stringStreamIn >> word;
                    std::cout << "Vertex" + numOfFacets <<std::endl;
                    std::cout << "X:" << std::setw(4) << word << std::endl;
                    //currentNum = stod(word.c_str, NULL);
                    //compareX(currentNum);
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