class Solution {
    public String findDifferentBinaryString(String[] nums) {
        //here the length of each string in nums equals the length of nums itself. So we can use the Cantor's diagonal approach 
        //consider the square matrix(n*n, where n=nums.length) that would be made by these strings
        //we can flip all the bits nums[i][i] where i goes from 0 to n-1
        //this would generate a final string that differs from all the strings by atleast one position, meaning overall the answer would be different from all these strings
        //so we constructed a unique string by flipping the diagonal bits of the input matrix to ensure difference from every existing string.
        int n=nums.length;
        StringBuilder ans=new StringBuilder();

        for(int i=0;i<n;i++){
            ans.append(nums[i].charAt(i)=='0' ? '1' : '0');
        }

        return ans.toString();
    }
}
