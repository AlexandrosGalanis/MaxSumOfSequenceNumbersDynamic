#include<iostream>

using namespace std;

int marray(int T[], int start, int finish){
    int mid =(start+finish)/2;
    int i,L=0,R=0;
    int sumR=0;
    int sumL=0;

    for(i=mid; i>=start; i--){
        sumL+=T[i];
        if(sumL>L){
            L=sumL;
        }
    }

    for(i = mid+1;i<=finish;i++){
        sumR+=T[i];
        if(sumR>R){
            R=sumR;
        }
    }

    return R+L;
}

int syn(int T[], int start, int finish){

    int mid;
    if(start==finish){
        return T[start];
    }

    mid=(start+finish)/2;

    int maxL=syn(T,start,mid);
    int maxR=syn(T,mid+1,finish);
    int midmax=marray(T,start,finish);

    return max(midmax,max(maxL,maxR));
}


int main(){

    int T[6],i,result=0;

    for(i=0; i<6; i++){
        cout<<"Dwse stoixeia:"<<endl;
        cin>>T[i];
    }
    result = syn(T,0,5);
    cout<<result;

    return 0;
}
