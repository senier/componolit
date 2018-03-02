/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */

#include <atomic>                                                                                                                              

template <typename IntType>
struct __attribute__((packed, aligned(2 * sizeof(IntType)))) ConversionPair {
  ConversionPair(IntType f, IntType s) : first(f), second(s) { }
  ConversionPair(const ConversionPair&) = default;
  ConversionPair() = default;
  ConversionPair& operator=(const ConversionPair&) = default;
  IntType first;
  IntType second;
};
using ConversionPair32 = ConversionPair<uint32_t>;
using ConversionPair64 = ConversionPair<uint64_t>;

inline static ConversionPair64
AtomicLoadRelaxed16B (std::atomic<ConversionPair64>* target)
{
  uint64_t first, second;
  asm volatile (
      "lock cmpxchg16b (%2)"
      : "=a"(first), "=d"(second)
      : "r"(target), "a"(0), "d"(0), "b"(0), "c"(0)
      : "cc");
  return ConversionPair64(first, second);
}

int
main() { };

void Libc::Component::construct(Libc::Env &env)
{
    std::atomic<ConversionPair64> cp1;
    ConversionPair64 cp2 = AtomicLoadRelaxed16B(&cp1);
    exit (0);
}
