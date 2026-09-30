class Solution {
public:
    string addBinary(string a, string b) {
      //append zeros to the smaller value - number of digits become the same
      if(a.length() > b.length()) {
        //add leading zeroes to b
        int numLeading0s = a.length() - b.length();
        for(int i=0 ; i < numLeading0s ; i++) /*b = '0' + b;*/  b.insert(0, 1, '0');
      }
      else if(a.length() < b.length()) {
        //add leading zeroes to a
        int numLeading0s = b.length() - a.length();
        for(int i=0 ; i < numLeading0s ; i++) /*a = '0' + a;*/ a.insert(0, 1, '0');
      }

      string sum="";
      int carry = 0;

      for(int i=a.length() - 1 ; i>=0 ; i--) {
        int digit1= a[i] - '0';
        int digit2= b[i] - '0';
        int d=0;    

        //4 cases

        // 0 + 0
        if(digit1==0 && digit2==0) {
            //0 + 0 + 0
            if(carry == 0) {
                  d = 0;
                  carry = 0;
            }
            else {  //0 + 0 + 1
                d = 1;
                carry = 0;
            }
          
        }

        // 0 + 1
        if(digit1==0 && digit2==1) {
            //0 + 1 + 0
            if(carry == 0) {
                  d = 1;
                  carry = 0;
            }
            else {  //0 + 1 + 1
                d = 0;
                carry = 1;
            }
          
        }

        // 1 + 0
        if(digit1==1 && digit2==0) {
            //1 + 0 + 0
            if(carry == 0) {
                  d = 1;
                  carry = 0;
            }
            else {  //1 + 0 + 1
                d = 0;
                carry = 1;
            }
          
        }

        // 1 + 1
        if(digit1==1 && digit2==1) {
            //1 + 1 + 0
            if(carry == 0) {
                  d = 0;
                  carry = 1;
            }
            else {  //1 + 1 + 1
                d = 1;
                carry = 1;
            }
          
        }

        //add digit to sum
        //sum = (char)('0' + d) + sum ;
        sum.insert(0, 1, (char)('0' + d));
      }
      //add final carry
      if(carry == 1) {
        //sum = '1' + sum;
        sum.insert(0, 1, '1');
      }

      return sum;
          }
};