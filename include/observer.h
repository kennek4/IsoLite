#ifndef ISO_OBSERVER_H
#define ISO_OBSERVER_H

#include <algorithm>
#include <vector>

typedef enum IsoEvent {

} IsoEvent;

class Observer {
public:
  virtual ~Observer() = 0;
  virtual void onNotify(const IsoEvent event) = 0;
};

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
      _observers.emplace_back(observer);
    };
  };

  void notifyObservers(const IsoEvent event) {
    for (int i = 0; i < _observers.size(); i++) {
      _observers[i]->onNotify(event);
    };
  };

private:
  std::vector<Observer *> _observers;
};

#endif // !ISO_OBSERVER_H
