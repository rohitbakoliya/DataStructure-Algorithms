#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

//node creation

node* Create(node* root , int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

//insertion

void Insert(node** root , int data)
{
    node* temp  = Create(*root , data);
    node* current = *root;

    if(*root == nullptr)
    {
        *root = temp;
        cout<<(*root)->data<<endl;
        return;
    }
    cout<<(*root)->data;
    while(1)
    {
        if(current->data==temp->data)
        {
            cout<<"\nError Two nodes of same data\n";
            return;
        }
        else if (current->data < temp->data)
        {
            cout<<"->R";
            if (current->right == nullptr)
            {
                current->right = temp;
//                cout<<current->data<<endl;
                cout<<endl;
                return;
            }
            else
            {
                current = current->right;
            }
        }
        else if(current->data > temp->data)
        {
            cout<<"->L";
            if (current->left == nullptr)
            {
                current->left = temp;
//                cout<<current->data<<endl;
                cout<<endl;
                return;
            }
            else
            {
                current = current->left;
            }
        }

    }
}


//void Delete(node** root , int data);



//searching in binary tree

bool Search(node* root , int data)
{
    node* current = root;
    while(true)
    {
        if(current==nullptr)
        {
            break;
        }
        else if(current->data==data)
        {
            return true;
        }
        else if(current->data < data)
        {
            current = current->right;
        }
        else if(current->data > data)
        {
            current = current->left;
        }

    }
    return false;
}


//finding maximum in BST

int findMax(node* root)
{
    node* current = root;
    int max =0;
    while(current!= nullptr)
    {
        if(max < current->data)
        {
            max = current->data;
        }
        current= current->right;
    }
    return max;
}

//finding minimum in BST


int findMin(node* root)
{
    node* current = root;
    int min = 0;
    while(current!= nullptr)
    {
        if(min > current->data )
            min = current->data;
        current=current->left;
    }
    return min;
}


//maxHeight of BST
// maximum distance from leaf to node
int maxHeight(node* root )
{
    if(root== nullptr)
        return -1;
    else
    {
        int  leftHeight = maxHeight(root->left);
        int  rightHeight= maxHeight(root->right);
        return max(leftHeight , rightHeight)+1;
    }
}

//bfs

void levelOrder(node* root)
{
    queue< node* > q;
    if(root==nullptr)
        return;
    q.push(root);
    while(!q.empty())
    {
        node* current = q.front();
        cout<<current->data<<" ";
        if(current->left!= nullptr)
        {
            q.push(current->left);
        }
        if(current->right!=nullptr)
        {
            q.push(current->right);
        }
        q.pop();
    }
    cout<<endl;
}

/* DFS */

//1. preorder
void preorder(node* root)
{
    if(root== nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//2. postorder
void postorder(node* root)
{
   if(root== nullptr)
   {
        return;
   }
   postorder(root->right);
   postorder(root->left);
   cout<<root->data<<" ";
}

//3. inorder
void inorder(node* root)
{
    if(root==nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

//given binary tree is binary search tree or not??


bool isSubTreeLesser(node* root , int value)
{
    if(root==nullptr)
        return true;
    return root->data < value && isSubTreeLesser(root->left, value)
           && isSubTreeLesser(root->right, value);
}

bool isSubTreeGreater(node* root, int value)
{
    if(root== nullptr)
        return true;
    return root->data > value && isSubTreeGreater(root->right, value) && isSubTreeGreater(root->right, value);
}
bool isBinaryTree(node* root /*, int min , int max */)
{
    if(root== nullptr)
        return true;
    /*
    if(isSubTreeLesser(root->left , root->data) && isSubTreeGreater(root->right , root->data)
    && isBinaryTree(root->left) && isBinaryTree(root->right) )
        return true;
    else
        return false;
    */

    // another way to do using max value and min value.
}




//driven program
int main()
{
    node *root = nullptr;
    int choice , data;
    while(0)
    {
        Insert(&root , 15);
        Insert(&root , 17);
        Insert(&root , 16);
        Insert(&root , 19);
        Insert(&root , 12);
        Insert(&root , 10);
        isBinaryTree(root)? cout<<"yes\n" : cout<<"no\n";
        break;
    }

    while(1)
    {
        cout<<"Enter the choice\n";
        cout<<"1.For insertion  2.For Deletion  3.For Searching  "
              "4.For Max  5.For Min  6.Max Height  "
              "7.For BFS traversal  8.For Preorder traversal 9. For Postorder"
              "10.For Inorder  Else. For Exit\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the value which you want to insert\n";
            cin>>data;
            Insert(&root , data);
        }
        else if(choice==2)
        {
            cout<<"Enter the value which you want to delete\n";
            cin>>data;
            //Delete(&root , data);
        }
        else if(choice==3)
        {
            cout<<"Enter the number to be searched\n\n";
            cin>>data;
            if(Search(root , data))
                cout<<"Element found!\n\n";
            else
                cout<<"Element is not in Tree\n\n";
        }
        else if(choice==4)
        {
            cout<<findMax(root)<<endl;
        }
        else if(choice==5)
        {
            cout<<findMin(root)<<endl;
        }
        else if(choice==6)
        {
            cout<<maxHeight(root)<<endl;
        }
        else if(choice==7)
        {
            levelOrder(root);
        }
        else if(choice==8)
        {
            preorder(root);
        }
        else if(choice==9)
        {
            postorder(root);
        }
        else if(choice==10)
        {
            inorder(root);
        }
        else if(choice==11)
        {
            if(isBinaryTree(root /*, findMax(root) , findMin(root)*/))
                cout<<"Given Binary Tree is Binary search tree\n";
            else
                cout<<"Given Binary Tree is not Binary Search tree\n";
        }
        else
        {
            exit(0);
        }
    }
}
