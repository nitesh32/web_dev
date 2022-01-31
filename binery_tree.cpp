#include<iostream> 
using namespace std; 
struct node{ 
    int data; 
    struct node *left,*right; 
}; 
struct node * create(){ 
    struct node *root; 
    root = (struct node*)new int[sizeof(struct node)]; 
    int n; 
    cout<<"enter data : "; 
    cin>>n; 
    if(n==-1){ return 0; } 
    root->data=n; 
    cout<<"enter data for the left of : "<<n<<endl; 
    root->left=create(); 
    cout<<"enter data for the right of : "<<n<<endl; 
    root->right=create(); return root; 
} 
void printPreorder(struct node *node){
     if (node == NULL) 
     return; /* first print data of node */ 
     cout << node->data << " "; 
     /* then recur on left subtree */ 
     printPreorder(node->left); 
     /* now recur on right subtree */ 
     printPreorder(node->right); 
} 
void printPostorder(struct node *root){ 
    if (root == NULL){ return; } 
    printPostorder(root->left); 
    printPostorder(root->right); 
    cout<<root->data<<" "; 
} 
void printInorder(struct node * root){ 
    if(root == NULL){ return ; } 
    printInorder(root->left); 
    cout<<root->data<<" "; 
    printInorder(root->right); 
} 
int height(struct node *root){ 
    if(root == NULL){ return 0; } 
    return max(height(root->left),height(root->right))+1; 
} 
int size(struct node *root){ 
    if(root ==NULL){ return 0; } 
    return size(root->left)+size(root->right)+1; 
} 
int max_ele(struct node *root){ 
    if(root == NULL){ return INT_MIN; } 
    return max(root->data,max(max_ele(root->left),max_ele(root->right))); 
} 
int min_ele(struct node *root){ 
    if(root == NULL){ return INT_MAX; } 
    return min(root->data,min(max_ele(root->left),max_ele(root->right))); 
} 
int main(){ 
#ifndef ONLINE_JUDGE 
freopen("ipt.txt","r",stdin); 
freopen("out.txt","w",stdout); 
#endif 
    struct node *root= create(); 
    cout<<endl; cout<<"preorder -> "<<endl; 
    printPreorder(root); cout<<endl; 
    cout<<"postorder -> "<<endl; 
    printPostorder(root); 
    cout<<endl<<"inorder -> "<<endl; 
    printInorder(root); 
    cout<<endl<<"height of your binery tree -> "<<endl; 
    cout<<height(root); 
    cout<<endl<<"size of your binery tree -> "<<endl; 
    cout<<size(root); 
    cout<<endl<<"maximum in your binery tree -> "<<endl; 
    cout<<max_ele(root); 
    cout<<endl<<"minimum in your binery tree -> "<<endl; 
    cout<<min_ele(root);
     // level order traversal we need to study 
    return 0; 
}