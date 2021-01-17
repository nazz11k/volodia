#include "str_lib.h"

int main() {
    int n;
    cout<<"Enter number of lines: ";
    cin>>n;
    string* lines= new string[n];
    inner(lines, n);
    deleter(lines, n);
    counter(lines, n);
}
