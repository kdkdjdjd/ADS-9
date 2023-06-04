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
    int depthTree;
    int searchNode(Node*, const T&);

 public:
    BST():root(nullptr), depthTree(-1) {}
    void add(const T&);
    int search(const T&);
    int depth();
};

template <typename T>
typename BST<T>::Node* BST<T>:: addNode(Node* root, const T& value, int depth) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
    if (depth > depthTree) {
      depthTree = depth;
    }
  } else if (root->value > value) {
    root->left = addNode(root->left, value, ++depth);
  } else if (root->value < value) {
    root->right = addNode(root->right, value, ++depth);
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
int BST<T>::depth() {
    return depthTree;
}

template<typename T>
int BST<T>::search(const T& value) {
    return searchNode(root, value);
}
#endif  // INCLUDE_BST_H_
