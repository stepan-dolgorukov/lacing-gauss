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

template<typename container>
double square(container& points) {
  double s{};

  for (std::size_t i{}; i < points.size() - 1; ++i) {
    s += points[i].first * points[i + 1].second;
    s -= points[i].second * points[i + 1].first;
  }

  s += points.back().first * points.front().second;
  s -= points.back().second * points.front().first;

  return std::abs(s) / 2.0;
}

int main(void) {
  std::size_t n{};

  std::cin >> n;
  std::vector<std::pair<double, double>> points(n);

  for (auto& p : points) {
    std::cin >> p;
  }

  std::cout << square(points) << '\n';
}
