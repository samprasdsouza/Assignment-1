/*
  author:Sampras
*/
#include<iostream>
#include<stack>
using namespace std;
bool solve(string brackets)
{
    int n=(int)brackets.size();                         //size of the string
    stack<char>st;                                      // stack
    
    for(int i=0;i<n;i++)
    {
        char k =brackets[i];
        if(k=='(' || k=='{' || k=='[')                  // Opening Brackets
        {
            st.push(brackets[i]);                       // push into stack
        }
        else{
            
            if(st.empty()){
                return false;                          // if closing is encountered and No opening Encountered
            }
            
            char c = st.top();
             
            if((c=='{' && k=='}')||(c=='(' && k==')')||(c=='[' && k==']'))     //if the Latest closing and opening match
                st.pop();                                                      // pop
            else{
                return false;                                                  // if  they do not match
            }
        }
    }
    if(!st.empty())return false;                                            // if the stack is No empty (i.e. No Closing Brackets For Opening Brackets)
    
    return true;                                                           // if all condtions are satisfied
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string brackets;
        cin>>brackets;
        bool ans = solve(brackets);
        if(ans)                                              // if ans == true
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
