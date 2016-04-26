/*
2016-02-07
proj04.cpp

Your Comments
*/
#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<string>
using std::string; 

//initialize the function
string  fibo_string( string  f0, string f1, int length){
	string next;
	for ( int count; count < length; count++){
		next = f1 + f0;
		f0=f1;
		f1=next;
		count=next.size();	
		//cout<<next<<endl;
	}
		return (next.substr(0,length));//return the "next" of length given
}

int find_substring( string fibo_stg, string target) {
	int count =0;
	//find the substring from given string
	size_t nPos= fibo_stg.find(target, 0);
	while(nPos != string::npos) {
		count ++; //increment count.
		nPos = fibo_stg.find(target, nPos +1);
	}
	//cout <<count<<endl;
	return (count);
}

string lcs ( string first, string second){
	
	//initialize two strings
	string toUse; //this will be the shortest string to use
	string toUseLater; //this will be the longest string.
	if (second.length()  <first.length()){ 
		toUse=second; //toUse is the shortest string
		toUseLater=first;
	}else if (second.length() >first.length()){
			toUse=first;
			toUseLater=second;//toUseLater is the longest string
	}
int leng = toUse.size(); //find the length of first string
int leng2=toUseLater.size(); //find the length of second string
string substring, maximum;
for (int i=0; i<=leng; i++) {
    for (int j=0; j +i<=leng; j++) {
				//see if k is less than the length of the two strings
                for (int k=0; k <= leng && k <= leng2; k++){
					
					//compare if substring from the short string appears in the other string
                    if (toUse.substr(i,k) == toUseLater.substr(j,k)){
                        substring = toUse.substr(i,k);
                    } else{if (substring.length() > maximum.length())
                            maximum=substring;      //maxi is the longest substring             
                             substring=" "; }
                }
                    if (substring.length() >maximum.length())
                            maximum=substring;
                        substring=" ";
                        //cout<<max<<endl;
                       }}        
	return(maximum);
}

int main () {
  long cases, start, finish, length;
  string f0, f1, target, f0f1_str;
  string f1f0_str;
  cin >> cases;
  for (int i=0; i < cases; i++){
    cin >> f0 >> f1 >> length >> start >> finish >> target;
    f0f1_str = fibo_string(f0,f1,length);
    f1f0_str = fibo_string(f1,f0, length);
        //cout<<"FIRST"<<f1f0_str<<endl<<endl;
        // cout<<"SECOND"<<f0f1_str<<endl;

    // print the substring requested
    cout <<"Substring from "<< start<< " to " << finish << " is:"
	 << f0f1_str.substr(start,finish-start+1)<<endl;

    // print the cnt of the target in the fibo_string
    cout <<  "Found target "<< target << " " << find_substring(f0f1_str, target)
	 << " times" <<endl;

    // print the longest common substring of the fibo and reversed fibo string
    cout << "LCS of " << f0 << "," << f1
	 <<" fibo and " << f1 << ","<< f0
	 <<" fibo is:" << lcs(f0f1_str, f1f0_str) << endl;

  }
}


