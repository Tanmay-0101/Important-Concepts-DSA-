private int lowerBound(int[] arr,int tar){
    int n=arr.length;
    int l=0,r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>=tar){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}

private int upperBound(int[] arr,int tar){
    int n=arr.length;
    int l=0,r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>tar){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
