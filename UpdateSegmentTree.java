private void updateST(int idx,int val,int i,int l,int r,int[] seg){
    if(l==r){
        seg[i]=val;
        return;
    }

    int mid=(l+r)/2;
    if(idx<=mid){
        updateST(idx,val,2*i+1,l,mid,seg);
    }else{
        updateST(idx,val,2*i+2,l,mid,seg);
    }

    seg[i]=Math.max(seg[2*i+1],seg[2*i+2]);
}
