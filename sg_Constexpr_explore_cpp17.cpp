/* -std=c++17 -O2 */
/* [Compiler Explorer](https://godbolt.org/)    *****/ 


#include <string_view>
#include <iostream>
#include <array>

template <std::size_t Size>
using chars = std::array<char, Size>;


constexpr void copy(char const* first, char const* last, char* to) {
    while (first < last) {
        *to++ = *first++;
    }
}

template <std::size_t N1, std::size_t N2>
constexpr auto concat(
    chars<N1> const& arr1,
    chars<N2>const& arr2)
{
  chars<N1+N2> result{};
  copy(arr1.begin(), arr1.end(), result.begin());
  copy(arr2.begin(), arr2.end(), result.begin()+N1);
  return result;
}

template <unsigned N>
constexpr auto to_chars(){
  constexpr char lastDigit = '0' + N%10;
  if constexpr(N>=10) {
    return concat(to_chars<N/10>(), chars<1>{lastDigit});
  } else {
    return chars<1>{lastDigit};
  }
}

template <unsigned N>
constexpr auto nthFizzBuzz()
{
  constexpr chars<4> FIZZ{'f', 'i', 'z', 'z'};
  constexpr chars<4> BUZZ{'b', 'u', 'z', 'z'};
    
  if constexpr (N%3==0 && N%5 ==0) {
    return concat(FIZZ, BUZZ);
  } else if constexpr (N%3==0) {
    return FIZZ;
  } else if constexpr (N%5==0) {
    return BUZZ;
  } else {
    return to_chars<N>();
  }
}

template <unsigned N>
constexpr auto fizzBuzzUntil()
{
  constexpr chars<2> SEPARATOR{',', ' '};
  static_assert(N > 0);
  if constexpr (N != 1) {
    return concat(fizzBuzzUntil<N-1>(), 
      concat(SEPARATOR, nthFizzBuzz<N>())
    );
  } else {
    return nthFizzBuzz<N>(); 
  }
}

int main() {
  constexpr auto fizzBuzz = fizzBuzzUntil<22>();
  std::cout << std::string_view(fizzBuzz.data(), fizzBuzz.size()) << std::endl;
}

