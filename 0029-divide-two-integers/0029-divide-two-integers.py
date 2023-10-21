class Solution:
  def divide(self, dividend: int, divisor: int) -> int:
    # Handling overflow case
    if dividend == -2**31 and divisor == -1:
      return 2**31 - 1

    # Determine the sign of the result
    sign = -1 if (dividend > 0) ^ (divisor > 0) else 1
    ans = 0
    dvd = abs(dividend)
    dvs = abs(divisor)

    # Perform the division using binary approximation
    while dvd >= dvs:
      k = 1
      # Find the largest 'k' such that 'k * 2 * dvs' is less than or equal to 'dvd'
      while k * 2 * dvs <= dvd:
        k <<= 1
      # Subtract 'k * dvs' from 'dvd' and add 'k' to 'ans'
      dvd -= k * dvs
      ans += k

    # Return the result with the appropriate sign
    return sign * ans
