// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
  private:
      struct Node {
          T value;
          int count;
          Node* left, * right;
      };
      Node* root;
      int size;

      Node* addRecursive(Node* node, const T& value, int count=1) {
          if (node == nullptr) {
              node = new Node;
              node->value = value;
              node->count = count;
              node->left = node->right = nullptr;
              size++;
          } else {
              if (node->value == value) {
                  node->count++;
              } else if (node->value > value) {
                  node->left = addRecursive(node->left, value, count);
              } else {
                  node->right = addRecursive(node->right, value, count);
              }
          }
          return node;
      }

      void deleteTree(Node* node) {
          if (node != nullptr) {
              deleteTree(node->left);
              deleteTree(node->right);
              delete node;
              size--;
          }
      }

      int searchRecursive(Node* node, const T& value) {
          if (node == nullptr) {
              return 0;
          } else if (node->value == value) {
              return node->count;
          } else if (node->value > value) {
              return searchRecursive(node->left, value);
          } else {
              return searchRecursive(node->right, value);
          }
      }

      int depthRecursive(Node* node) {
          if (node == nullptr) {
              return -1;
          } else {
              return 1 + std::max(depthRecursive(node->left), depthRecursive(node->right));
          }
      }

  public:
      BST(): root(nullptr), size(0) {}

      ~BST() {
          deleteTree(root);
          root = nullptr;
      }

      void add(const T& value) {
          root = addRecursive(root, value, 1);
      }

      int search(const T& value) {
          return searchRecursive(root, value);
      }

      int depth() {
          return depthRecursive(root);
      }

      int getSize() {
          return size;
      }
};
#endif  // INCLUDE_BST_H_
