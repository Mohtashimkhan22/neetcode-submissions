class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int bitA = a & 1;
            int bitB = b & 1;

            int s = bitA + bitB + carry;

            if (s >= 2) {
                carry = 1;
                s -= 2;
            } else {
                carry = 0;
            }

            sum |= (s << i);

            a >>= 1;
            b >>= 1;
        }

        return sum;
    }
};