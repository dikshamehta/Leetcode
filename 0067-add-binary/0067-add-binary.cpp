
class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int sum = 0;
//         int n1 = a.size();
//         int n2 = b.size();

//         for(int i=0; i<n1; i++){
//             if(a[i] == '1') sum = sum + pow(2,n1-i-1);
//         }

//         for(int i=0; i<n2; i++){
//             if(b[i] == '1') sum = sum + pow(2,n2-i-1);
//         }

//         if (sum == 0) return "0";

//         string result = "";
//         while (sum > 0) {
//             result = char((sum % 2) + '0') + result;
//             sum /= 2;
//         }

//         return result;
//     }
// };