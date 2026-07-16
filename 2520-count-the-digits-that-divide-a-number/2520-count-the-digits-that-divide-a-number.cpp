class Solution {
public:
    int countDigits(int num) {
        int count=0;
        int t=num;
        while(num>0){
            int val=num%10;
            if(t%val==0){
                count++;
            }
            num=num/10;
        }
        return count;
    }
};