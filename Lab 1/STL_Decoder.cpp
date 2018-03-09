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

 using namespace std;

 static double maxX;
 static double minX;
 static double maxY;
 static double minY;
 static double maxZ;
 static double minZ;
 static int numOfFacets=0;

 int main(int argc, char** argv){

    //Checks to see if File was imported
    if(argc < 2){
        cout << "Filename Was Not Entered" << endl;
    }
    else{
        string importedFile = argv[1];
        ifstream filein(importedFile.c_str());
        
        while(filein){
            string currentLine;
            getline(filein, currentLine);
            istringstream stringStreamIn(currentLine);
            
            while(stringStreamIn){
                string word;
                stringStreamIn >> word;
                if(compareWord(word, "facet")){
                    numOfFacets++;
                    double currentNum;
                    stringStreamIn.ignore(8);
                    stringStreamIn >> word;
                    cout << "Vertex" + numOfFacets <<endl;
                    cout << "X:" << setw(4) << word << endl;
                    currentNum = strtof(word.c_str,0);
                    compareX(currentNum);
                }
            }

        }
    }

    return 0;
 }

bool compareWord(string word, string refword){
    if(word.find(refword)== string::npos){
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