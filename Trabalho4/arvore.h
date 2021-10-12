#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "paciente.h"

using std::stack;
using std::cout;
using std::endl;

template <class T>
class Node {
public:
   T data;
   Node *left = nullptr;
   Node *right = nullptr;
};

template <class T>
class Arvore {
   template <class unused>
   friend ostream &operator<<(ostream &output, Arvore<T> &tree);

public:
   ~Arvore();
   T *operator+=(const T &insertNode);
   T *operator()(const string &patientName);

   Node<T> *root = nullptr;

private:
   Node<T> *Insert(Node<T> *begin, const T &insertNode);

   template <class type_data>
   Node<T> *Search(Node<T> *begin, const type_data &patientName);
};

template <class T>
Arvore<T>::~Arvore() {
   stack<Node<T> *> stack;
   Node<T> *curr = root;

   while (!stack.empty() || curr != nullptr) {

      if (curr != nullptr) {
         stack.push(curr);
         curr = curr->right;
      }
      else {
         curr = stack.top();
         stack.pop();
         curr = curr->left;
         delete curr;
      }
   }
}

template <class T>
T *Arvore<T>::operator+=(const T &insertNode) {

   if (root == NULL) {
      root = new Node<T>;
      root->data = insertNode;

      return &root->data;
   }
   else
      return &(Insert(root, insertNode)->data);
}

template <class T>
std::ostream &operator<<(std::ostream &output, Arvore<T> &tree) {

   stack<Node<T> *> stack;

   Node<T> *curr = tree.root;

   while (!stack.empty() || curr != nullptr) {

      if (curr != nullptr) {
         stack.push(curr);
         curr = curr->right;
      }
      else {
         curr = stack.top();
         stack.pop();
         cout << curr->data << endl;

         curr = curr->left;
      }
   }

   return output;
}

template <class T>
T *Arvore<T>::operator()(const std::string &patientName) {
   return &(Search(root, patientName)->data);
}

template <class T>
template <class type_data>

Node<T> *Arvore<T>::Search(Node<T> *begin, const type_data &value) {
   if (begin == NULL)
      return NULL;

   else if (begin->data == value)
      return begin;

   else if (begin->data < value)
      return Search(begin->left, value);

   else
      return Search(begin->right, value);
}

template <class T>
Node<T> *Arvore<T>::Insert(Node<T> *begin, const T &insertNode) {

   if (begin->data == insertNode) {
      return nullptr;
   }
   if (begin->data > insertNode) {

      if (begin->right == NULL) {
         begin->right = new Node<T>;
         begin->right->data = insertNode;

         return begin->right;
      }
      else
         return Insert(begin->right, insertNode);
   }
   else {
      if (begin->left == NULL) {
         begin->left = new Node<T>;
         begin->left->data = insertNode;

         return begin->left;
      }
      else
         return Insert(begin->left, insertNode);
   }
}

#endif