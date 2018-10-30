#ifndef XORSHIFT_HPP_
#define XORSHIFT_HPP_

#include <iomanip>
#include <sstream>

namespace xorshift {
template<typename T>
class Bits {
 public:
  static constexpr std::size_t size = sizeof(T) * 8;

  explicit Bits(T value)
    : value_(value) {}

  T value() const {
    return value_;
  }

 private:
  T value_;
};

template <typename T, typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>& operator<<(
        std::basic_ostream<CharT, Traits>& out,
        const Bits<T>& bits) {
  std::basic_ostringstream<CharT, Traits> sout;
  sout << "0x"
       << std::hex
       << std::setw(Bits<T>::size / 4)
       << std::setfill('0')
       << bits.value();
  out << sout.str();
  return out;
}
}  // namespace xorshift
#endif  // XORSHIFT_HPP_
