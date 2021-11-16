#include <iostream>
#include <cstring>

using namespace std;

void printScreen(int *pool, int **div, int width, int height);

void insertChar(int *pool, int **div, char input, char inputCord[5]);

bool valid(char input, char inputCord[]);

int sizeofArray(char array[]);

int main() {
  bool running = true;
  char input = ' ';
  char inputCord[5];
  int width = 30;
  int height = 30;
  int size = width*height;
  
  int **div = new int*[height];
  int *pool = new int[size];

  for(int i = 0; i < width; i++, pool += width) {
    div[i] = pool;
  }
  pool = div[0];

  while(running) {
    cout << "Insert character: ";
    cin >> input;
    cin.ignore();
    cout << "at: ";
    cin.getline(inputCord, 5);
    if(valid(input, inputCord)) {
      insertChar(pool, div, input, inputCord);
      printScreen(pool, div, width, height);
    }
  }
  
  delete [] pool;
  delete [] div;
  pool = NULL;
  div = NULL;
  return 0;
}

void insertChar(int *pool, int **div, char input, char inputCord[5]) {
  cout << "Insert Char";
}

int sizeofArray(char array[]) {
  int output = *(&array + 1) - array;
  cout << output << endl;
  return output;
}

bool valid(char input, char inputCord[]) {
  if(inputCord[0] >= 48 && inputCord[0] <= 57) {
    if((*(&inputCord + 1) - inputCord) >= 3) {
      return true;
    }
    else {
      cout << "Coordinates must contain at least two numbers." << endl;
    }
  }
  else {
    cout << "Coordinates must contain only numbers." << endl;
  }
  cout << "Ex: x,y" << endl;
  return false;
}

void printScreen(int *pool, int **div, int width, int height) {
  for(int h = 0; h < height; h++) {
    for(int w = 0; w < width; w++) {
      cout << *(div[h] + w) << ' ';
    }
    cout << endl;
  }
}

