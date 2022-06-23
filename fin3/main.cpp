#include <iostream>
using namespace std;

class myArray {
  private:
    int *rec;

  public:
    myArray(int size) { rec = (int *)calloc(size, sizeof(int)); }
    void recInput(int array[], int size) {
      rec = (int *)calloc(size, sizeof(int));
      for (int i = 0; i < size; i++) rec[i] = array[i];
    }
    int recMax(int size) {
      int max = 0;
      for (int i = 0; i < size; i++) if (rec[i] > max) max = rec[i];
      return max;
    }
    int recSum(int size) {
      int sum = 0;
      for (int i = 0; i < size; i++) sum += rec[i];
      return sum;
    }
    int recAve(int size) {
      int sum = 0;
      for (int i = 0; i < size; i++) sum += rec[i];
      return sum / size;
    }
};

int main() {
  int size = 5;
  int array[] = {500, 1, 2, 3, 4};
  myArray A(size);
  A.recInput(array, size);
  cout << "The max is: " << A.recMax(size) << endl;
  cout << "The sum is: " << A.recSum(size) << endl;
  cout << "The avr is: " << A.recAve(size) << endl;
  return 0;
}

