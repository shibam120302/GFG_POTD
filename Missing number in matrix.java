class Solution
{
    public long  MissingNo(int[][] matrix)
    {
        // code here
        TreeSet<Long>nonzero=new TreeSet<>(), zero=new TreeSet<>();
    	
    	// Interating through rows
    	for(int i = 0; i < matrix.length; i++){
    		boolean f = true;
    		long sum = 0;
    		for(int j = 0; j < matrix[0].length; j++){
    			sum += matrix[i][j];
    			if(matrix[i][j]==0)
    				f = false;
    		}
    		if(f)nonzero.add(sum);
    		if(!f)zero.add(sum);
    	}
    	// Interating through coloumns
    	for(int  j = 0; j < matrix[0].length; j++){
    		boolean f = true;
    		long sum = 0;
    		for(int i = 0; i < matrix.length; i++){
    			sum += matrix[i][j];
    			if(matrix[i][j]==0)
    				f = false;
    		}
    		if(f)nonzero.add(sum);
    		if(!f)zero.add(sum);
    	}
    	// Interating through diagonals
    	boolean f = true;
    	long sum = 0;
    	for(int i = 0; i < matrix.length; i++){
    		sum += matrix[i][i];
    		if(matrix[i][i]==0)
    			f = false;
    	}
    	if(f)nonzero.add(sum);
		if(!f)zero.add(sum);
    	// Interating through diagonals
    	f = true;
    	sum = 0;
    	for(int i = 0, j = matrix.length - 1; j >= 0; i++,j--){
    		sum += matrix[i][j];
    		if(matrix[i][j]==0)
    			f = false;
    	}
		if(f)nonzero.add(sum);
		if(!f)zero.add(sum);
    	if(nonzero.size() == 1 && zero.size() == 1){
    		long x = nonzero.first();
    		long y = zero.first();
    		if(x <= y)
    			return -1;
    		return x - y;
    	}
    	return -1;
    }
}
