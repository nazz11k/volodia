#include "str_lib.h"

void inner(string* lines, int n){
    cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, lines[i]);
    }
}

void deleter(string* lines, int n){
    int pos;
    for(int i=0; i<n; i++){
        pos=0;
        int max_length=0;
        int max_beg=0;
        while(lines[i].find( '(', pos)!=-1){
            int open_pos=lines[i].find('(', pos);
            int close_pos=lines[i].find(')', pos);
            int cur_pos=open_pos+1;
            lines[i].insert(close_pos, " ");
            while(cur_pos<close_pos-2){
                if((lines[i].find(' ', cur_pos)-cur_pos)>max_length){
                    max_length=lines[i].find(' ', cur_pos)-cur_pos;
                    max_beg=cur_pos;
                }
                cur_pos=lines[i].find(' ', cur_pos)+1;
            }
            lines[i].erase(max_beg, max_length+1);
            pos=close_pos;
        }
    }
    outer(lines, n, "Changed lines:");
}

void counter(string*  lines, int n){
    int count, max_count=0, max_line=0;
    for(int i=0; i<n; i++){
        count=0;
        for(int j=0; j<lines[i].length(); j++){
            if(lines[i][j]=='('){
                count++;
            }
        }
        if(count>max_count){
            max_count=count;
            max_line=i;
        }
        lines[i]+=" | count = ";
        lines[i]+=to_string(count);
    }
    cout<<"String with the biggest number of groups:"<<endl<<lines[max_line]<<endl<<endl;
    outer(lines, n, "Strings with their numbeers of groups:");
}

void outer(string* lines, int n, string name){
    cout<<name<<endl;
    for(int i=0; i<n; i++){
        cout<<lines[i]<<endl;
    }
}