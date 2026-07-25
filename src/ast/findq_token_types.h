#ifndef FINDQ_TOKEN_TYPES_H
#define FINDQ_TOKEN_TYPES_H
// grammar/findq_token_types.h

#include <stdint.h>


namespace findqparser {
using namespace std;

struct NumberArg {
  uint64_t val;
  int sign = 0;

  //auto operator<=>(const NumberArg&) const = default;
  friend auto operator<=>(const NumberArg&, const NumberArg&) noexcept = default;
  
};

}

#endif

