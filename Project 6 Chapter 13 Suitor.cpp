/*There were six suitors then the elimination process would
proceed as follows:
123456 initial list of suitors, start counting from 1
12456 suitor 3 eliminated, continue counting from 4
1245 suitor 6 eliminated, continue counting from 1
125 suitor 4 eliminated, continue counting from 5
15 suitor 2 eliminated, continue counting from 5
1 suitor 5 eliminated, 1 is the lucky winner
Write a program that creates a circular linked list of nodes to determine which
position you should stand in to marry the princess if there are n suitors.
A circular linked list is a linked list where the link field of the last node
in the list refers to the node that is the head of the list. Your program should
simulate the elimination process by deleting the node that corresponds
to the suitor that is eliminated for each step in the process.*/
#include<iostream>
using namespace std;
class suitor{
	public:
	int code;
	suitor *link;
};
typedef suitor* suiPtr;
int main(){
	int n;
	while(1){
	cin>>n;
	if(n==0){
		cout<<"Oops, nobody woos princess Eve!\n";
		break;
	}
	suiPtr head;
	suiPtr tempPtr;
	head=new suitor;
	tempPtr=new suitor;
	
	tempPtr=head;
	for(int i=1;i<n;i++){
		tempPtr->code=i;
		tempPtr->link=new suitor;
		tempPtr=tempPtr->link;
	}
	tempPtr->code=n;
	tempPtr->link=head;
	
	while(tempPtr->link!=tempPtr){
		//find the third
		suiPtr deletePtr=new suitor;
		tempPtr=tempPtr->link->link;
		deletePtr=tempPtr->link;
	    tempPtr->link=tempPtr->link->link;
	    
	    cout<<"Suitor "<<deletePtr->code<<" is eliminated."<<endl;
	    
	    delete deletePtr;
	}
	
	cout<<"Stand in code "<<tempPtr->code<<" to win the hand of Princess.\n";	
	cout<<endl;
	}
	
} 
