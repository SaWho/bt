#include <iostream>
using namespace std;

class node{
public:    
    int data;
    
    node * left;
    node * right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BT{
public:
    node * root;
    BT(){
        root = NULL;
    }
    void insert(int value){
        insert2(root, value);
    }
    
    
    void insert2(node * curr, int value){
        
        if (root == NULL){
            root = new node(value);
        }
         else if (value < curr->data){
            
             if(curr->left == NULL)
		 curr->left = new node(value);
             else
		 insert2(curr->left, value);
        }
        else{
            
            if(curr->right == NULL)
		 curr->right = new node(value);
             else
		insert2(curr->right, value);
        }     
    }
    void display(){disp2(root);}
    
    void disp2(node * curr){
        
        if (curr == NULL) 
	return;
	disp2(curr->left);        
        cout << curr->data <<",";
        disp2(curr->right);
    }
   
    node * search(node * curr, int value){
        if (curr == NULL || curr->data == value) 
	return curr;
        else if (value < curr->data)
	return search (curr->left, value);
        else 
	return search (curr->right, value);
    }
   
};



int main(){
BT obj;
node* t;
   for(int i=1;i<=5;i++)
   {
	obj.insert(i);
	}
obj.display();
t=obj.search(obj.root,6);
cout<<t;
}


