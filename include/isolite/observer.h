#ifndef ISOLITE_OBSERVER_H
#define ISOLITE_OBSERVER_H

#include "events.h"

namespace IsoLite {
class Observer {
public:
  virtual ~Observer() {};
  virtual void onNotify(const IsoEvent) = 0;
};
}; // namespace IsoLite

#endif // !ISOLITE_OBSERVER_H
