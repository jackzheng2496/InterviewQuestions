#include <iostream>

template<int N, int D>
struct Fraction {
  static const long Num = N;
  static const long Den = D;
};

template<int N, typename T>
struct ScalarMultiplication {
  typedef Fraction<N*T::Num,N*T::Den> result;
};

int main() {
  typedef Fraction<2,3> two_thirds;
  typedef ScalarMultiplication<4,two_thirds>::result eight_twelve;
  
  std::cout << eight_twelve::Num << "/" << eight_twelve::Den << "\n";
}
