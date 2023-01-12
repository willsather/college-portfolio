/**
 * @file IObservable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_

#include <vector>
#include <iostream>
#include <string>

#include "src/IObserver.h"
#include "src/data_structs.h"

template <typename T>
class IObservable {
 public:
  /** @brief
  This RegisterObserver function adds an
  observer to the observe list.  Once this
  occurs, the IObserver pointer is watching
  the screen. */
  void RegisterObserver(IObserver<T>* observer);

  /** @brief
  This ClearObservers function removes
  every observer from the observer list
  in order to start over. */
  void ClearObservers();

  /** @brief
  This NotifyObservers function is what
  calls the IObserver's notify function.
  This is necessary to update the bus data */
  void NotifyObservers(T* info);

 private:
  std::vector<IObserver<T>*> observers_;
};

template <typename T>
void IObservable<T>::RegisterObserver(IObserver<T>* observer) {
  observers_.push_back(observer);
}

template <typename T>
void IObservable<T>::ClearObservers() {
  observers_.clear();
}

template <typename T>
void IObservable<T>::NotifyObservers(T* info) {
  std::cout << "Notify Observers" << std::endl;
  for (int i = 0; i < static_cast<int>(observers_.size()); i++) {
      observers_[i]->Notify(info);
    }
}

#endif  // SRC_IOBSERVABLE_H_
