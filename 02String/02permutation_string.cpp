#include<iostream>
#include<vector>
using namespace std;
void permutation(string input, vector<string>&ans, int index){
    if(index==input.size()){
        ans.push_back(input);
        return ;
    }
    
    for(int i=index;i<input.size();i++){
    string output=input;
        char t=output[index];
        output[index]=output[i];
        output[i]=t;
        permutation(output,ans,index+1);
    }
}
int main(){
    string input="abc";
    vector<string>ans;
    permutation(input,ans,0);
    vector<string>::iterator it;
    for(it=ans.begin();it!=ans.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}