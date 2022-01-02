#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
//         int gcdLen = __gcd(len1, len2);
//         // making str1 > str2
//         if(len1<len2){ 
//             swap(len1, len2);
//             swap(str1, str2);
//         }
    
//         string window = str2.substr(0, gcdLen);
//         int count1 = len1/gcdLen, count2 = len2/gcdLen;

//         string temp1 = "", temp2 = "";
//         for(int i=0; i<count1; i++){
//             temp1+=window;
//         }
//         for(int j=0; j<count2; j++){
//             temp2+=window;
//         }
//         if(temp1==str1 and temp2==str2){
//             return window;
//         }
//         return "";
    /*
    
    str1 = m(GCD), str2 = n(GCD)
    str1+str2 = (m+n)GCD = str2+str1
    if they are having same common pattern it will be followed 
    
    if == -> ans = str1.substr(0, gcd(len1, len2));
    else -> "";
    
    */
    return ((str1+str2)==(str2+str1)?str1.substr(0, __gcd(len1, len2)):"");
}

int main(){
    string str1, str2;
    cin>>str1>>str2;
    cout<<gcdOfStrings(str1, str2);
}