class Solution{
public:
    bool isPrime(int n){
    	if(n==1) return false;
    	if(n==2 || n==3)
    		return true;
    	for(int i=2;i<=sqrt(n);i++){
    		if(n%i==0){
    			return false;
    		}
    	}
    	return true;
    }
    Node *primeList(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            int num=temp->val,num1,num2;
            num1=num2=num;
            if(num==1){
                temp->val=2;
                temp=temp->next;
                continue;
            }
            while(!isPrime(num1)){
                num1--;
            }
            while(!isPrime(num2)){
                num2++;
            }
            if(num-num1>num2-num){
                temp->val=num2;
            }
            else{
                temp->val=num1;
            }
            temp=temp->next;
        }
        return head;
    }
};
