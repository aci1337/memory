#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

//Function to read a file and store it in a string variable
string ReadFile(string FileName){
    // Create a stringstream variable
    stringstream ss;
    // Create a variable to store the contents of the file
    string FileData;
    // Open the file
    ifstream File(FileName.c_str());
    // Read the file
    ss << File.rdbuf();
    // Store the file data in the variable
    FileData = ss.str();
    // Close the file
    File.close();
    // Return the file data
    return FileData;
}

//Function to download a file from a URL and store it in a string variable
string DownloadFile(string URL){
    // Create a stringstream variable
    stringstream ss;
    // Create a variable to store the contents of the file
    string FileData;
    // Open the file
    ifstream File(URL.c_str());
    // Read the file
    ss << File.rdbuf();
    // Store the file data in the variable
    FileData = ss.str();
    // Close the file
    File.close();
    // Return the file data
    return FileData;
}

//Function to run a file from memory
void RunFileFromMemory(string FileData){
    // Create a vector to store the file lines
    vector<string> FileLines;
    // Create a stringstream variable
    stringstream ss;
    // Store the file data in the stringstream
    ss << FileData;
    // Create a variable to store the current line
    string Line;
    // Loop through the file lines
    while(getline(ss, Line)){
        // Add the line to the vector
        FileLines.push_back(Line);
    }
    // Create a variable to store the current line number
    int LineNumber = 0;
    // Create a variable to store the current command
    string Command;
    // Create a variable to store the command arguments
    vector<string> Arguments;
    // Loop through the file lines
    while(LineNumber < FileLines.size()){
        // Get the current line
        Line = FileLines[LineNumber];
        // Check if the line is empty
        if(Line.length() == 0){
            // Increment the line number
            LineNumber++;
            // Skip to the next line
            continue;
        }
        // Create a stringstream variable
        stringstream ss;
        // Store the line in the stringstream
        ss << Line;
        // Get the command
        ss >> Command;
        // Check if the command is "print"
        if(Command == "print"){
            // Get the argument
            string Argument;
            ss >> Argument;
            // Print the argument
            cout << Argument << endl;
        }
        // Check if the command is "exit"
        else if(Command == "exit"){
            // Exit the program
            exit(0);
        }
        // Increment the line number
        LineNumber++;
    }
}

int main(){
    // Get the URL of the file to download
    string URL;
    cout << "Enter the URL of the file to download: ";
    cin >> URL;
    // Download the file
    string FileData = DownloadFile(URL);
    // Run the file from memory
    RunFileFromMemory(FileData);
    return 0;
}