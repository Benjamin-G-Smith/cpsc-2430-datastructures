// Ben Smith
// P5.cpp
// version 1.0
// 11/15/2017

// PURPOSE: Allows the user to Parse a text file of Ulysses. Also allows the
// user to find the top 25 occurencs.
#include "hashTable.h"

string removeSpaces(string input);

int main(){
  hashTable hTable;
  ifstream input;
  ofstream outfile;
  string line,lineWord,temp;
  int fives = 0;
  string userInput;

  //File processing
  cout << "Please enter the file you would like to parse: ";
  cin >> userInput;
  input.open(userInput);

  while(input.fail()){
    cout << "Error opening file..." << endl;
    cout << "Please enter the file you would like to parse: ";
    cin >> userInput;
    input.open(userInput);
  }
  // file reading
  while(getline(input,line)){// looking through each line of the file
    string lineString = line;
    istringstream lineStream(lineString);
    while(lineStream >> lineWord){ //looking at every word in each line
      int srt = lineWord.length();
      for(int i = 0; i < srt; i++){
        if(!isalpha(lineWord[i])){
          lineWord[i] = ' ';
        }
      }
      string RlineWord = removeSpaces(lineWord);
      int x = RlineWord.length();
      if(x >= 5){
        fives++;
        hTable.insert(RlineWord);
      }
    }
  }
  input.close();
    outfile.open("P5Output.txt");
    // content dump
    hTable.dump(outfile);
    int bloom = hTable.find("Bloom");
    int hungry = hTable.find("hungry");
    int laugh = hTable.find("laugh");
    outfile << "Number of five length words " << fives << endl;
    outfile << "bloom " << bloom << endl;
    outfile << "hungry " << hungry << endl;
    outfile << "laugh " << laugh << endl;
    outfile.close();
    return 0;
}
string removeSpaces(string input)
{
  int l = input.length();
  for(int i=0; i<l; i++){
    if(input[i] == ' ') input.erase(i,1);
  }
  return input;
}
