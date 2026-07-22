class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int n =letters.size();
      int l=0;
      int h=n-1;
      int mid;
      int pos =-1;
      while(l<=h){
        mid = (l+h)/2;
        if(letters[mid]>target){
            pos=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }



      }
      if(pos==-1) return letters[0];

      return letters[pos];  
    }
};