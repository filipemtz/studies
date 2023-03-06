
"""
There are faster solutions. 
"""


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        result = ""

        for i1 in range(len(num1)-1, -1, -1):
            digit1 = int(num1[i1])

            digit_result = "0" * ((len(num1) - 1) - i1)
            carry = 0

            for i2 in range(len(num2)-1, -1, -1):
                digit2 = int(num2[i2])

                m = digit1 * digit2 + carry
                digit_result += str(m % 10)
                carry = m // 10

            if carry > 0:
                digit_result += str(carry)

            digit_result = self.reverse(digit_result)
            result = self.sum_strings(result, digit_result)

        result = self.remove_left_zeros(result)

        return result

    def remove_left_zeros(self, s: str) -> str:
        idx = 0
        while (idx < len(s)-1) and (s[idx] == '0'):
            idx += 1

        if idx <= len(s)-1:
            return s[idx:]
        else:
            return s

    def sum_strings(self, num1: str, num2: str) -> str:
        idx1 = len(num1) - 1
        idx2 = len(num2) - 1

        result = ""
        carry = 0
        while (idx1 >= 0) or (idx2 >= 0):
            val1 = val2 = 0
            if idx1 >= 0:
                val1 = num1[idx1]
                idx1 -= 1
            if idx2 >= 0:
                val2 = num2[idx2]
                idx2 -= 1

            s = int(val1) + int(val2) + carry
            result += str(s % 10)
            carry = s // 10

        if carry > 0:
            result += str(carry)

        return self.reverse(result)

    def reverse(self, s: str) -> str:
        idx = len(s) - 1
        result = ""
        while idx >= 0:
            result += s[idx]
            idx -= 1
        return result
