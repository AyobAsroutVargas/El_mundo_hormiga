#ifndef Vector_H_
#define Vector_H_

#include<iostream>
#include <cmath>
#include <cassert>

const int initial_value = 0;

template<class T>
class Vector_t {
 public:
  Vector_t(void);
  Vector_t(const int& min, const int& max);
  ~Vector_t() {delete[] vector_;}

  int get_size(void);
  int get_min(void);
  int get_max(void);
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void initialize(const int value);
  void resize(const int& min, const int& max);

 private:
  T *vector_;
  int min_;
  int max_;
  int size_;
};

template <class T>
Vector_t<T>::Vector_t(void){
  size_ = 20;
  min_ = -10;
  max_ = 10;
  vector_ = new T[size_];
  //initialize(initial_value);
}


template <class T>
Vector_t<T>::Vector_t(const int& min, const int& max){
  size_ = abs(min) + abs(max);
  min_ = min;
  max_ = max;
  vector_ = new T[size_];
}


template<class T>
T& Vector_t<T>::at(const int i) {
  assert(i >= min_ && i < max_);
  int real_position = i + abs(min_);
  return vector_[real_position];
}

template<class T>
T& Vector_t<T>::operator[](const int i) {
  return at(i);
}

template<class T>
const T& Vector_t<T>::at(const int i) const {
  assert(i >= min_ && i < max_);
  int real_position = i + abs(min_);
  return vector_[real_position];
}



template<class T>
const T& Vector_t<T>::operator[](const int i) const {
  return at(i);
}

template<class T>
int Vector_t<T>::get_size() {
  return size_;
}

template<class T>
int Vector_t<T>::get_min() {
  return min_;
}

template<class T>
int Vector_t<T>::get_max() {
  return max_;
}

template<class T>
void Vector_t<T>::initialize(const int value) {
  for (int i = min_; i < max_; i++) {
    this->at(i) = value;
  }
}

template<class T>
void Vector_t<T>::resize(const int& min, const int& max) {
  min_ = min;
  max_ = max;
  size_ = abs(min_) + abs(max_);
  if (vector_ != NULL) {
    delete[] vector_;
  }
  vector_ = new T[size_];
}

#endif //Vector_H_