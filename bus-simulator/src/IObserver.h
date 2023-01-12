/**
 * @file IObserver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include "src/data_structs.h"

template <typename T>
class IObserver {
 public:
  /** @brief
  This UpdateObserver function uses a BusData
  object to update the observer pattern and
  provide it's values to the screen.
  */
  virtual void Notify(T* info) = 0;
};
#endif  // SRC_IOBSERVER_H_
