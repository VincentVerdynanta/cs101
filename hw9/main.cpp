#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class ReplaceMyString {
  public:
    string getfile(ifstream &is) {
      string contents;
      for (char ch; is.get(ch); contents.push_back(ch)) {};
      return contents;
    }
    void replaceString(string find, string replace) {
      ifstream input("main.cpp");
      string contents = getfile(input);
      size_t pos = 0;
      while ((pos = contents.find(find, pos)) != -1) {
        contents.replace(pos, find.size(), replace);
        pos += replace.size();
      };
      ofstream output("Rmain.cpp");
      output << contents;
    }
};

int main() {
  ReplaceMyString my;
  my.replaceString("IU", "IU is best");
  return 0;
}
