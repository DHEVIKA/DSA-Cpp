class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

/* The given problem is about converting an integer into a Roman numeral. To do this, we can create arrays that represent the Roman numeral symbols for each place value (ones, tens, hundreds, thousands). Then, we can divide the given number into its respective place values and concatenate the corresponding Roman numeral symbols.

Approach:
Create four arrays: ones, tens, hrns, and ths, representing the Roman numeral symbols for ones, tens, hundreds, and thousands respectively. Each array contains the symbols for the numbers from 0 to 9 in their respective place value.
Divide the given number num into its respective place values:
// thousands = num / 1000
// hundreds = (num % 1000) / 100
// tens = (num % 100) / 10
// ones = num % 10
Concatenate the Roman numeral symbols based on the place values:
ths[num/1000] represents the Roman numeral for thousands place.
hrns[(num%1000)/100] represents the Roman numeral for hundreds place.
tens[(num%100)/10] represents the Roman numeral for tens place.
ones[num%10] represents the Roman numeral for ones place.
Return the concatenation of the Roman numeral symbols obtained from step 3.

*/