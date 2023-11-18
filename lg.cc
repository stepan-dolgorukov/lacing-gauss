#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

template<typename stream_in,
         typename point>
stream_in&
operator>> (stream_in& in, point& p) {
  in >> p.first >> p.second;
  return in;
}

int main(void) {
  std::size_t n{};
  double square{};

  std::cin >> n;
  std::vector<std::pair<double, double>> points(n);

  for (auto& p : points) {
    std::cin >> p;
  }

  for (std::size_t i{}; i < points.size() - 1; ++i) {
    square += points[i].first * points[i + 1].second;
    square -= points[i].second * points[i + 1].first;
  }

  square += points.back().first * points.front().second;
  square -= points.back().second * points.front().first;

  std::cout << std::abs(square) / 2.0  << '\n';
}
