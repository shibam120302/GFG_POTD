class Solution{
public:
    int inSequence(int A, int B, int C){
        int d = (B - A);
        if(d == 0)
            return 1;
        if(d < 0){
            if(C >= 0)
                return 0;
            if(d%C == 0)
                return 1;
            return 0;
        }
        else{
            if(C <= 0)
                return 0;
            if(d%C == 0)
                return 1;
            return 0;
        }
        return 0;
    }
};
