#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class freqFile {
  private:
    ifstream input;
    int freq[26] = {0};

  public:
    freqFile(string name) { input.open(name); }
    void readFile() {
      for (char ch; input.get(ch);) {
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        if (ch >= 'a' && ch <= 'z') freq[ch - 'a']++;
      };
    }
    void showFreq() {
      for (int i = 0; i < 26; i++) {
        char letter = 'a' + i;
        cout << "[" << letter << "] = " << freq[i] << endl;
      }
    }
};

int main() {
  freqFile myFile("main.cpp");
  myFile.readFile();
  myFile.showFreq();
  return 0;
}

