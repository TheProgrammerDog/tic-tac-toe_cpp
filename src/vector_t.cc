/**
 * @file vector_t.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "vector_t.h"
#include <cassert>
#include <iostream>

template<class T>
Vector_t<T>::Vector_t() {
  array_ = new T[0];
  size_ = 0;
}

template<class T>
Vector_t<T>::Vector_t(unsigned size) {
  array_ = new T[size];
  size_ = 0;
}

template<class T>
Vector_t<T>::~Vector_t() {
  delete array_;
  array_ = nullptr;
  size_ = 0;
}

template<class T>
T& Vector_t<T>::at(const unsigned index) {
  assert (index < size_);
  return array_[index];
}

template<class T>
const T& Vector_t<T>::at(const unsigned index) const {
  assert(index < size_);
  return array_[index];
}

template<class T>
T& Vector_t<T>::operator[](const unsigned index) {
  return at(index);
}

template<class T>
const T& Vector_t<T>::operator[](const unsigned index) const {
  return at(index);
}

template<class T>
unsigned Vector_t<T>::size() const {
  return size_;
}