

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
string removeSpaces(string input);

int main(){
  ifstream input;

  input.open("ulyss12.txt");
  string moving;
  int max = 0;
  string line,lineWord,temp;
  int count = 0;
  int fives = 0;
  long sum = 0;

  while(getline(input,line)){// looking through each line of the file

    string lineString = line;
    istringstream lineStream(lineString);

    while(lineStream >> lineWord){ //looking at every word in each line
      int srt = lineWord.length();
      bool badword = false;
      for(int i = 0; i < srt; i++){
        if(!isalpha(lineWord[i])){
          lineWord[i] = ' ';
          badword = true;
        }
      }
      string RlineWord = removeSpaces(lineWord);
      int x = RlineWord.length();
      if(x >= 5){
        fives++;
        string word = temp;
        hTable.insert(word);
        sum += stringValue;
      }
      count++;
      if(!badword && srt > max){
        max = srt;
        temp = RlineWord;
      }
    }
  }

  cout <<"Fives "<<fives <<"}  "<< max  <<" "<< temp << endl;
  input.close();
  string word = temp;
  int stringValue = 0;
  int size = word.length();
  for(int i = 0; i < size; i++){
    stringValue += static_cast<int>(word[i]) * i;
  }
  stringValue = stringValue % 900000;
  cout <<"String "<< stringValue  << endl;
  cout << "average " << sum / fives << endl;


  return 0;
}
string removeSpaces(string input)
{
  int l = input.length();
  for(int i=0; i<l; i++){
     if(input[i] == ' ') input.erase(i,1);
   }
  //input.erase(remove(input.begin(),input.end(),' '),input.end());
  return input;
}
