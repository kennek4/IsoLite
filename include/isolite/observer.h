#ifndef ISO_OBSERVER_H
#define ISO_OBSERVER_H

#include "events.h"

namespace IsoLite {
class Observer {
public:
  virtual ~Observer() {};
  virtual void onNotify(const IsoEvent) = 0;
};
}; // namespace IsoLite

#endif // !ISO_OBSERVER_H
