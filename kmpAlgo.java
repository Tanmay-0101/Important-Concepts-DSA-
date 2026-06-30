    private boolean kmp(String pattern,String word){
        int m=pattern.length();
        int n=word.length();

        int[] lps=new int[m];
        for(int i=1,j=0;i<m;i++){
            while(j>0 && pattern.charAt(i)!=pattern.charAt(j)){
                j=lps[j-1];
            }
            if(pattern.charAt(i)==pattern.charAt(j)){
                j++;
            }
            lps[i]=j;
        }

        for(int i=0,j=0;i<n;i++){
            while(j>0 && pattern.charAt(j)!=word.charAt(i)){
                j=lps[j-1];
            }
            if(word.charAt(i)==pattern.charAt(j)){
                j++;
            }
            if(j==m) return true;
        }
        return false;
    }
