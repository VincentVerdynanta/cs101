#include <iostream>

using namespace std;

class MMmanger {
  private:
    int s;
    int id;
    int *g_mem;

  public:
    MMmanger(int size) {
      s = size;
      id = 0;
      g_mem = (int *)calloc(size, sizeof(int));
    }
    ~MMmanger() { free(g_mem); }
    int *calloc_MM(int size) {
      int indx = -1;
      for (int i = 0; indx < 0 && i < s; i++) {
        int j = 0;
        for (int k = 0; !j && k < size; k++) {
          if (g_mem[i + k] != 0 || i + k >= s) j = 1;
        };
        if (!j) indx = i;
      };
      if (indx >= 0) {
        for (int i = 0; i < size; i++) g_mem[indx + i] = id + 1;
        id++;
      };
      print_calloc_array(indx, size);
      return indx >= 0 ? &g_mem[indx + size - 1] : NULL;
    }
    void free_MM(int *p) {
      for (int i = 0; i < s; i++) if (g_mem[i] == *p) g_mem[i] = 0;
      print_calloc_array(0, 0);
    }
    int get_MMCapacity() {
      int capacity = 0;
      for (int i = 0; i < s; i++) if (g_mem[i] == 0) capacity++;
      return capacity;
    }
    void print_calloc_array(int flag, int size) {
      cout << "Capacity:" << get_MMCapacity() << " - ";
      for (int i = 0; i < s; i++) g_mem[i] ? cout << "1" : cout << "0";
      if (flag < 0) cout << " <- Out of space: demand " << size;
      cout << endl;
    }
};

int main() {
  MMmanger mmer(10);
  int *p1 = mmer.calloc_MM(1);
  int *p2 = mmer.calloc_MM(2);
  int *p3 = mmer.calloc_MM(3);
  int *p4 = mmer.calloc_MM(4);
  mmer.free_MM(p1);
  mmer.free_MM(p4);
  int *p5 = mmer.calloc_MM(6);

  return 0;
}
