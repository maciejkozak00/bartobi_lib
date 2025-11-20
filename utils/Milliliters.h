#ifndef UTILS_MILLILITERS_H
#define UTILS_MILLILITERS_H

struct Milliliters {
  explicit constexpr Milliliters(float v) : value_(v) {}
  float value_;
};

constexpr Milliliters operator"" _ml(unsigned long long v) {
  return Milliliters(static_cast<float>(v));
}

#endif // UTILS_MILLILITERS_H
