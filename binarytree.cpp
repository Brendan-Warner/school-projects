/******************************************************************************

                              Brendan Warner
							  project 5, creat a binary tree from a file, taking in only letter, and outputting the characters and the number of times they appear

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class user_file
{
   private:
   
   struct binary_tree
   {
       char tree_char;
       int tree_count;
       binary_tree *left;
       binary_tree *right;
       
   };
   
   binary_tree *node_pointer;
   
   public:
   
   user_file()//constructor 
   {node_pointer = nullptr;}
   
   
   ~user_file()//destructor 
   {
       
   }
   
   void insert_node(char input)//creates node to be put in the tree, passes it to the insert function
   {
       binary_tree *new_node = nullptr;
       
       new_node = new binary_tree;
       new_node -> tree_char = input;
       new_node -> tree_count = 1;
       
       new_node -> left = new_node -> right = nullptr;
       
       insert(node_pointer, new_node);
   }
   
   
   void insert(binary_tree *&node_pointer, binary_tree *&new_node)//inserts node into the tree
   {
       
       if(node_pointer == nullptr)
       {
           node_pointer = new_node;
       }
       
       else if(new_node -> tree_char < node_pointer -> tree_char)
       {
           insert(node_pointer -> left, new_node);
           
       }
       
       else
       {
           insert(node_pointer -> right, new_node);
           
       }
       
       
       
   }
   
   bool check_for_same(char input)//checks for same character in tree, if the character exists, then increments count by 1, else, call insert node
   {
       
       
       binary_tree *nodeptr = node_pointer;
       
       if(nodeptr == nullptr)
       {
           insert_node(input);
           return false;
           
       }
       
       
       
       
	   
	   while(nodeptr)
	   {
	        
			if(nodeptr -> tree_char == input)
			{
				nodeptr -> tree_count += 1;
				return true;
			}
			
			else if (input < nodeptr -> tree_char)
			{
				nodeptr = nodeptr -> left;
			}
			
			else 
			{
			    nodeptr = nodeptr -> right;
			}
			

	   
	   }
	   
	   
	   
	   insert_node(input);
	   
	   return false;
	   
       
   }
    
    
    void show_tree()
    {
        inoder(node_pointer);
        
    }
    
    void inoder(binary_tree *node_pointer)//outputs tree chars and their count 
    {
        if(node_pointer == nullptr)
        {
            return;
        }
        
        else
        {
            inoder(node_pointer -> left);
            cout << node_pointer -> tree_char << " " << node_pointer -> tree_count << endl;
            inoder(node_pointer -> right);
            
        }
        
    }
    
};

int main()
{
	int i = 0, user_input = 0, string_length = 0;
	string user_char;
	char hold_char;
	string user_string = "", opened_file;
	
	
	
	user_file user_tree;
	
	cout << "Please enter a file to read from" << endl;
	cin >> opened_file;
	
	ifstream file;

	file.open(opened_file);
	
	if(!file)//checks for file existing 
	{
	
		cout << "error, the file in question does not exist, please try again" << endl;
		cin >> opened_file;
		file.open(opened_file);
		
	
	}
	
	
	cout << "Please enter the number of spaces you would like to traverse in the file" << endl;
	cin >> user_input;
	
	for(i =0; i < user_input; i++)//loop for adding chars from file to the string, only takes in alphabetical character
	{
		file >> hold_char;
		
		if(isalpha(hold_char))//checks for alphabetical character
		{
		    user_char = hold_char;
		    user_string.append(user_char);
		}
		
		else//adds one to the input of the user to account for non alphabetical char, number, or punctuation being encountered in the file
		{
		    user_input ++;
		}
		
	
	}
	
	string_length = user_string.length();
	
	
	for(i = 0; i < string_length; i++)//loop for checking for the same char in the tree
	{
	    
		
		user_tree.check_for_same(user_string[i]);
		
	}
	
	cout << "Here are the character in the file and the number of times they appear" << endl;
	user_tree.show_tree();
	
	


	return 0;    
}
