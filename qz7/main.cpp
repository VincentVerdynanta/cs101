#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class ReadClass {
  public:
    string getfile(ifstream &is) {
      string contents;
      for (char ch; is.get(ch); contents.push_back(ch)) {};
      return contents;
    }
    void showClass() {
      ifstream input("main.cpp");
      string contents = getfile(input);
      string find = "\nclass", output = "";
      int total = 0;
      size_t pos = 0, name;
      while ((pos = contents.find(find, pos)) != -1) {
        for (name = pos + find.size(); contents[name] == ' '; name++) {};
        output += "\nclass ";
        for (size_t i = name; i < contents.find(" ", name); i++) {
          output.push_back(contents[i]);
        };
        pos += find.size();
        total++;
      };
      cout << total << " class in main.cpp" << output << endl;
    }
};

int main() {
  ReadClass rfile;
  rfile.showClass();
  return 0;
}
