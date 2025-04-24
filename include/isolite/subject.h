#ifndef ISOLITE_SUBJECT_H
#define ISOLITE_SUBJECT_H

#include "events.h"
#include "observer.h"
#include <algorithm>
#include <vector>

namespace IsoLite {
class Subject {
public:
  void addObserver(Observer *observer) {
    int count = std::count(_observers.begin(), _observers.end(), observer);
    if (count == 0) { // Observer doesn't already exist
      _observers.emplace_back(observer);
    };
  };

  void removeObserver(Observer *observer) {
    auto itr = std::find(_observers.begin(), _observers.end(), observer);
    if (itr != _observers.end()) { // Observer exists, we can delete pointer
      _observers.erase(itr);
    }
  };

  void notifyObservers(const IsoEvent event) {
    for (int i = 0; i < _observers.size(); i++) {
      _observers[i]->onNotify(event);
    };
  };

private:
  std::vector<Observer *> _observers;
};
} // namespace IsoLite

#endif // !ISOLITE_SUBJECT_H
