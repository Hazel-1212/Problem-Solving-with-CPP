#include<iostream>
using namespace std;
class Node{	
    public:
    	Node(){
		nextN=NULL;
		nextS=NULL;
		nextE=NULL;
		nextW=NULL;
		}
    	string name;
		Node* nextN;
		Node* nextS;
		Node* nextE;
		Node* nextW;
		
		char turn(){
			char dire;
			cin>>dire;
			switch(dire){
				case 'E':
				if(nextE!=NULL){
				return dire;
			    }else{
			    return turn();
				}
			    break;
                case 'W':
			    if(nextW!=NULL){
				return dire;
			    }else{
			    return turn();
				}
			    case 'S':
			    if(nextS!=NULL){
				return dire;
			    }else{
			    return turn();
				}
				case 'N':
			    if(nextN!=NULL){
				return dire;
			    }else{
			    return turn();
				}
			
		    }
	    }
		
		void printNext(){
			cout<<"You are in room "<<name<<" of a maze of twisty little passages, all alike."<<endl<<"You can go ";
			if(nextE!=NULL){
				cout<<"(E)ast, ";
			}

			if(nextW!=NULL){
				cout<<"(W)est, ";
			}
			
			if(nextS!=NULL){
				cout<<"(S)outh, ";
			}
			if(nextN!=NULL){
				cout<<"(N)orth, ";
			}
			cout<<"or (Q)uit.\n";
			
		}
			
};
typedef Node* NodePtr;

int main(){
	
	NodePtr A;
	A=new Node;
    A->name="A";
    
    NodePtr B;
	B=new Node;
    B->name="B";
    
    NodePtr C;
	C=new Node;
    C->name="C";
    
    NodePtr D;
	D=new Node;
    D->name="D";
    
    NodePtr E;
	E=new Node;
    E->name="E";
    
    NodePtr F;
	F=new Node;
    F->name="F";
    
    NodePtr G;
	G=new Node;
    G->name="G";
    
    NodePtr H;
	H=new Node;
    H->name="H";
    
    NodePtr I;
	I=new Node;
    I->name="I";
    
    NodePtr J;
	J=new Node;
    J->name="J";
    
    NodePtr K;
	K=new Node;
    K->name="K";
    
    NodePtr L;
	L=new Node;
    L->name="L";
   
	A->nextE=B;
	B->nextN=A;
	A->nextS=E;
	E->nextN=A;
	B->nextS=F;
	F->nextN=B;
	C->nextS=G;
	G->nextN=C;
    C->nextE=D;
	D->nextW=C;
	E->nextS=I;
	F->nextE=G;
	G->nextW=F;
	G->nextE=H;
	H->nextW=G;
	H->nextS=L;
	L->nextN=H;
	G->nextS=K;
	K->nextN=G;
	I->nextN=E;
	I->nextE=J;
	J->nextW=I;
	
	
	
	NodePtr userPtr=new Node;
	userPtr=A;
	while(userPtr!=L){
		userPtr->printNext();
		char d=userPtr->turn();
		switch(d){
			case 'E':
				userPtr=userPtr->nextE; 
			    break;
                case 'W':
			    userPtr=userPtr->nextW; 
			    break;
			    case 'S':
			    userPtr=userPtr->nextS; 
			    break;
				case 'N':
			    userPtr=userPtr->nextN; 
			    break;
		}
	}
	cout<<"Reach the Destination L!\n";
	delete A,B,C,D,E,F,G,H,I,J,K,L;
}
