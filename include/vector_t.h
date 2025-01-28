/**
 * @file vector_t.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VECTOR_T
#define VECTOR_T

template<class T>
class Vector_t {
  public:
    Vector_t();
    Vector_t(const unsigned size);
    ~Vector_t();

    T& operator[](const unsigned index);
    const T& operator[](const unsigned index) const;
    T& at(const unsigned index);
    const T& at(const unsigned index) const;

    unsigned size() const;

    void rlcesize(const unsigned index);
    void clear();
  private:
    T* array_;
    unsigned size_;
};

#endif