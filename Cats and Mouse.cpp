#include<iostream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
const int gridSize=10;
const char mouse='@';
const char cat='C';
class Animal{
	protected:
	int x,y;
	public:
		Animal(int x,int y):x(x),y(y){}
		virtual void move(Animal* grid[gridSize][gridSize])=0;
		virtual char getChar() const = 0;
		int getX () const{
			return x;
		}
		int getY () const{
			return y;
		}
		void updatePos(int a,int b){
			x=a;
			y=b;
		}
};
class Mouse:public Animal{
	public:
	Mouse(int x,int y):Animal(x,y){}
	void move(Animal* grid[gridSize][gridSize]) override{
	    int direction[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
	    int d=rand()%4;
	    for(int i=d;i<d+4;i++){
	    	int newX=x+direction[i%4][0];
	    	int newY=y+direction[i%4][1];
	        if(grid[newX][newY]==nullptr&&newX<gridSize&&newX>=0&&newY>=0&&newY<gridSize){
                grid[newX][newY] = this;
                grid[x][y]=nullptr;
				updatePos(newX,newY);
	        	break;
			}
		}
	}
	char getChar() const override{
		return mouse;
	}
};

class Cat:public Animal{
	public:
	Cat(int x,int y):Animal(x,y){}
	void move(Animal* grid[gridSize][gridSize]) override{
	    int direction[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
	    int d=rand()%4;
	    for(int i=d;i<d+4;i++){
	    	int newX=x+direction[i%4][0];
	    	int newY=y+direction[i%4][1];
	        if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
                if (grid[newX][newY] != nullptr && grid[newX][newY]->getChar() == mouse) {
                    delete grid[newX][newY];
                    grid[newX][newY] = this;
                    grid[x][y] = nullptr;
                    updatePos(newX, newY);
                    cout << "Cat eats a mouse!\n";
                    break;
                } else if (grid[newX][newY] == nullptr) {
                    grid[newX][newY] = this;
                    grid[x][y] = nullptr;
                    updatePos(newX, newY);
                    break;
                }
            }
		}
	}
	char getChar() const override{
		return cat;
	}
};

void printMap(Animal* grid[gridSize][gridSize]){
	for(int i=0;i<gridSize;i++){
		for(int j=0;j<gridSize;j++){
			if(grid[i][j]==nullptr){
				cout<<setw(2)<<".";
			}else{
			     cout<<setw(2)<<grid[i][j]->getChar();
			}
			
		}
		cout<<endl;
	}
	cout<<endl;
} 

void preyAndPredator(Animal* grid[gridSize][gridSize]){
	vector<Animal*>moved;
	for(int i=0;i<gridSize;i++){
		for(int j=0;j<gridSize;j++){
			bool check=0;
			if(grid[i][j]!=nullptr&&grid[i][j]->getChar()==mouse){
				for(int k=0;k<moved.size();k++){
					if(moved[k]==grid[i][j]){
						check=1;
					}
				}
				if(!check){
					moved.push_back(grid[i][j]);
					grid[i][j]->move(grid);
				}
				
			}
		}
	}
	
	for(int i=0;i<gridSize;i++){
		for(int j=0;j<gridSize;j++){
			if(grid[i][j]!=nullptr&&grid[i][j]->getChar()==cat){
				bool check=0;
				for(int k=0;k<moved.size();k++){
					if(moved[k]==grid[i][j]){
						check=1;
					}
				}
				if(!check){
					moved.push_back(grid[i][j]);
					grid[i][j]->move(grid);
				}
			}
		}
	}
}

int main(){
	Animal* grid[gridSize][gridSize]={nullptr};
	srand(time(0));
	int x,y;
	for(int i=0;i<10;i++){
		do{
			x=rand()%gridSize;
	    	y=rand()%gridSize;
		}while(grid[x][y]!=nullptr);
		grid[x][y]=new Mouse(x,y);	
	}
	
	for(int i=0;i<3;i++){
		do{
			x=rand()%gridSize;
	    	y=rand()%gridSize;
		}while(grid[x][y]!=nullptr);
		grid[x][y]=new Cat(x,y);
	}
	//Operation
	printMap(grid);
	while(1){
		cout << "Press Enter to continue..." << endl;
        cin.get();
        preyAndPredator(grid);
		printMap(grid);
		
	}
	
	for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            delete grid[i][j];
        }
    }
	
}
