#pragma once
// ensures file is only included once during compilation, avoiding redefiniation errors

#include <chrono>

using Clock = std::chrono::steady_clock;

// get the current time
inline Clock::time_point now()
{
  return Clock::now();
}

// compute elapsed time in nanoseconds since a given start time
inline uint64_t ns_since(const Clock::time_point &t0)
{
  return std::chrono::duration_cast<std::chrono::nanoseconds>(
             Clock::now() - t0)
      .count();
}

// a small RAII (resource acquisition is initialisator) timer
// stores the current time when constructed
// later can call .ns() to get elapsed nanoseconds
// handy when want time code blocks without manually writing now()

struct Timer
{
  Clock::time_point t0; // starting timestampt

  // constructor automatically records the current time
  Timer() : t0(Clock::now()) {}

  void reset() { t0 = Clock::now(); }

  // elapsed time since construction
  uint64_t ns() const
  {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(
               Clock::now() - t0)
        .count();
  }

  // elapsed time in lms which is easier to inerpret
  double ms() const
  {
    return std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
               Clock::now() - t0)
        .count();
  }
};
