class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        int i,j;
    	std::map<int, int> l,r;
    	for(i=0;i<N;i++) r[A[i]]++;
    	std::vector<int> v;
    	for(i=0;i<N;i++){
    		r[A[i]]--;
    		if(r[A[i]]==0) r.erase(A[i]);
    		v.push_back(l.size()-r.size());
    		l[A[i]]++;
    	}
    	return v;
    }
};
