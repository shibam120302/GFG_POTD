int minSteps(string str) {
    int cnt=1;
    for(int i=1;i<str.size();i++){
        if(str[i]!=str[i-1]){
            cnt++;
        }
    }
    return cnt/2 + 1;
}
