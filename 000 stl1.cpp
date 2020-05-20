#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
	========
	 STACK
	========
	*/
    stack<string> distros;
    distros.push("Linux");
    distros.push("Ubuntu");
    distros.push("Mint");
    cout<<"Size of stack is: "<<distros.size()<<endl;
    cout<<"Top of stack is: "<<distros.top()<<endl;
    while(!distros.empty()){
        cout<<distros.top()<<endl;
        distros.pop();
    }

    /*
	========
	 VECTOR
	========
	*/

	vector<int> numbers;

	if(numbers.empty()){
        cout<<"The vector is empty"<<endl;
	}

	for(int i=0;i<10;i++){
        numbers.push_back(2*i+1);
	}
	cout<<"Size of the vector is: "<<numbers.size()<<endl;
	vector<int>::iterator it;
	int position = 5;
	numbers.insert(numbers.begin()+position, 9999);
	for(it= numbers.begin(); it!= numbers.end();it++){
        cout<<*it<<" ";
	}
	cout<<endl;
	numbers.erase(numbers.begin()+position);
	numbers.erase(numbers.begin()+3, numbers.begin()+6);
	for(it= numbers.begin(); it!= numbers.end();it++){
        cout<<*it<<" ";
	}
	cout<<endl;
	cout<<numbers.at(position)<<endl;
    numbers.clear();
    if(numbers.empty()){
        cout<<"The vector is empty"<<endl;
    }
    /*
	========
	 HASHMAPS
	========
	*/


return 0;
}
