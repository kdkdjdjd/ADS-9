// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    std::string stroc;
    char ch;
    while (file.get(ch)) {
      if (ch >= 'A' && ch <= 'Z') {
        ch += 32;
      }
      if (ch >= 'a' && ch <= 'z') {
        stroc += ch;
      } else {
        tree.add(stroc);
        stroc = "";
      }
    }
  }
  file.close();
  return tree;
}
