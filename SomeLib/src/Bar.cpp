#include "Bar.h"

namespace Imerso {
namespace IcPcdGenerators {

namespace {
int h(int x) { return 4 * x; };
} // namespace

int f(int x) { return 2 * h(x); }
} // namespace SomeLib
} // namespace Imerso
