//Made by: Brendan Warner, date: 11/30/2020
#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
    
};

node* root_node = nullptr;

node* get_new_node(int data)
{
    node* new_node = new node();
    new_node -> data = data;
    new_node -> left = new_node ->right = nullptr;
    return new_node;
    
}

node* insert_node(node* root_node, int data)
{
    if(root_node == nullptr)
    {
        root_node = get_new_node(data);
        return root_node;
        
    }
    
    else if(data <= root_node -> data)
    {
        
        root_node -> left = insert_node(root_node -> left, data);
        return root_node;
    }
    
    else if(data >= root_node -> data)
    {
        root_node -> right = insert_node(root_node -> right, data);
        return root_node;
        
    }
    
}

int maxDepth(node* root_node)  
{  
    if (root_node == NULL)  
    {
        return 0;  
    }
    else
    {  
        
        int lDepth = maxDepth(root_node ->left);  
        int rDepth = maxDepth(root_node ->right);  
      
        
        if (lDepth > rDepth)
        {
            return(lDepth + 1);
        }
        else 
        {
            return(rDepth + 1); 
        }
    }  
} 

bool search(node* root_node, int data)
{
    
    if(root_node == nullptr)
    {
        cout << "sorry, the tree is empty or the number you are looking for is not in the tree." << endl;
        return false;
        
    }
    
    else if (root_node -> data == data)
    {
        cout << data << "\nthe number has been found." << endl;
        
    }
    
    else if(data <= root_node -> data) 
    {
        cout << root_node -> data << endl;
        return search(root_node -> left, data);
        
        
    }
    
    else 
    {
        cout << root_node -> data << endl;
        return search(root_node -> right, data);
        
    }
}

void inoder(node* root_node)
    {
        if(root_node == nullptr)
        {
            return;
        }
        
        else
        {
            inoder(root_node -> left);
            cout << root_node -> data << " " << endl;
            inoder(root_node -> right);
            
        }
        
    }
    
    void post_order(node* root_node)
    {
        if(root_node == nullptr)
        {
            return;
        }
        
        else
        {
            post_order(root_node -> left);
            post_order(root_node -> right);
            cout << root_node -> data << " " << endl;
            
        }
        
    }
    
    void pre_order(node* root_node)
    {
        
        if(root_node == nullptr)
        {
            return;
        }
        
        
        
        else
        {
            
            cout << root_node -> data << " " << endl;
            pre_order(root_node -> left);
            pre_order(root_node -> right);
            
            
        }
        
    }
    
    void find_smallest(node* root_node, int &smallest)
    {
        if(root_node == nullptr)
        {
            return;
        }
        
        
        if(smallest >= root_node -> data)
        {
            smallest = root_node -> data;
        }
        
        find_smallest(root_node -> left, smallest);
        find_smallest(root_node -> right, smallest);
        
    }
    
    void find_largest(node* root_node, int &largest)
    {
        if(root_node == nullptr)
        {
            return;
        }
        
        
        if(largest <= root_node -> data)
        {
            largest = root_node -> data;
        }
        
        find_largest(root_node -> left, largest);
        find_largest(root_node -> right, largest);
        
    }
    
    node* minValueNode(node* root_node)
{
    node* current = root_node;
 
    
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
    
    node* delete_node(node* root_node, int data)
    {
        if(root_node == nullptr)
        {
            cout << " The node you tried to delete does not exist." << endl;
            return root_node;
        }
        
        else if(data < root_node -> data)
        {
            root_node -> left = delete_node(root_node -> left, data);
            
        }
        
        else if(data > root_node -> data)
        {
            root_node -> right = delete_node(root_node -> right, data);
            
        }
        
        else
        {
            if(root_node -> left == nullptr && root_node -> right == nullptr)
            {
                delete root_node;
                root_node = nullptr;
                 cout << "node 10 has been deleted." << endl;
                return root_node;
                
            }
            
            else if(root_node -> left == nullptr)
            {
                node* temp = root_node;
                root_node = root_node -> right;
                delete temp;
                 cout << "node 10 has been deleted." << endl;
                return root_node;
                
            }
            
            else if(root_node -> right == nullptr)
            {
                node* temp = root_node;
                root_node = root_node -> left;
                delete temp;
                 cout << "node 10 has been deleted." << endl;
                return root_node;
                
            }
            
            else 
            {
                struct node* temp = minValueNode(root_node ->right);
 
        
                root_node ->data = temp->data;
 
        
                root_node->right = delete_node(root_node ->right, temp->data);
                
            }
            
           
        }
        
        
    }


int main()
{
    int a[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
    
    int smallest =0;
    int largest = 0;
    int height = 0;
    
    for (int i = 0; i < 10; i++)
    {
        root_node = insert_node(root_node,a[i]);
    }
    
    
    cout << "The height of the bst is " << maxDepth(root_node) << endl;
    
    cout << "the binary search tree in pre_order is " << endl;
    inoder(root_node);
    
    cout << "the binary search tree in post_order is " << endl;
    post_order(root_node);
    
    cout << "the binary search tree in pre_order is " << endl;
    pre_order(root_node);
    
    smallest = root_node -> data;
    largest = root_node ->data;
    
    find_smallest(root_node, smallest);
    find_largest(root_node, largest);
    
    cout << "The smallest number in the bst is " << smallest << endl;
    cout << "The largest number in the bst is " << largest << endl;
    
    
    search(root_node, 38);
    search(root_node, 9);
    cout << "deleting the node 10" << endl;
    delete_node(root_node, 10);
    
    cout << "the binary search tree in pre_order is " << endl;
    inoder(root_node);
    
    cout << "the binary search tree in post_order is " << endl;
    post_order(root_node);
    
    cout << "the binary search tree in pre_order is " << endl;
    pre_order(root_node);



    return 0;
}