#include "Imerso/OtherLib/Foo.h"
#include "Imerso/SomeLib/Foo.h"

namespace Imerso {
namespace IcPcdGenerators {
int f(int x); // Is accessible from SomeLib
//int h(int x); // Not accessible. (anonymous namespace)
}

namespace OtherLib {
int other(int x) { return 3 * IcPcdGenerators::g(x) * IcPcdGenerators::f(x); }

} // namespace OtherLib
} // namespace Imerso
