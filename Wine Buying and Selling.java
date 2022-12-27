class Solution{
    static class pair{
        int first, second;
        pair(int first, int second){
            this.first = first;
            this.second = second;
        }
    }
    long wineSelling(int Arr[],int N){
        // int n = Arr.length;
        ArrayList<pair> buy = new ArrayList<>();
        ArrayList<pair> sell = new ArrayList<>();
        for(int i=0;i<N;i++){
            if(Arr[i]>0) 
                buy.add(new pair(Arr[i],i));
            else 
                sell.add(new pair(Arr[i],i));
        }
        long ans = 0;
        int i=0,j=0;
        while(i < buy.size() && j < sell.size()){
            long x = Math.min(buy.get(i).first,-sell.get(j).first);
            buy.get(i).first -= x;
            sell.get(j).first += x;
            long diff = Math.abs(buy.get(i).second - sell.get(j).second);
            ans += (x * diff);
            if(buy.get(i).first == 0) 
                i++;
            if(sell.get(j).first == 0) 
                j++;
        }
        return ans;
    }

}
