//SIEVE OF ERATOSTHENES
    private int[] sieve(int n){
        int[] sieveArray=new int[n+1];
        Arrays.fill(sieveArray,1);
        sieveArray[0]=0;
        sieveArray[1]=0;
        for(int i=2;i*i<=n;i++){
            if(sieveArray[i]==1){
                for(int multiple=i*i;multiple<=n;multiple+=i){
                    sieveArray[multiple]=0;
                }
            }    
        }
        return sieveArray;
    }
