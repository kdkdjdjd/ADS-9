// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
    };
    Node* root;
    Node* addNode(Node*, const T&, int);
    int sizeTree;
    int searchNode(Node*, const T&);

 public:
    BST():root(nullptr), sizeTree(-1) {}
    void add(const T&);
    int search(const T&);
    int size();
};

template <typename T>
typename BST<T>::Node* BST<T>:: addNode(Node* root, const T& value, int size) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
    if (size > sizeTree) {
      sizeTree = size;
    }
  } else if (root->value > value) {
    root->left = addNode(root->left, value, ++size);
  } else if (root->value < value) {
    root->right = addNode(root->right, value, ++size);
  } else {
    root->count++;
  }
  return root;
}

template<typename T>
int BST<T>::searchNode(Node* root, const T& value) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == value) {
        return root->count;
    } else if (root->value < value) {
        return searchNode(root->right, value);
    } else if (root->value > value) {
        return searchNode(root->left, value);
    }
    return 0;
}

template <typename T>
void BST<T>::add(const T& value) {
    root = addNode(root, value, 0);
}

template<typename T>
int BST<T>::size() {
    return sizeTree;
}

template<typename T>
int BST<T>::search(const T& value) {
    return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
