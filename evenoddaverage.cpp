/******************************************************************************

                            Brendan Warner
                            project 5-2; calculates verious numbers based on what is in random.txt
                            11/1/2019

*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    
    int num, even = 0, odd = 0, check;
    double average=0, i = 0, sum = 0;
    string file;
    cout << "Please enter the file name you wish to open." << endl;
    cin >> file;
    
    
    
    ifstream inputfile;
    
    
    inputfile.open(file);
    while (!inputfile)
    {
        cout << "Faliure to open file, please try again." << endl;
        cin >> file;
        
        inputfile.open(file);
    }
    
    
    cout << "file opened" << endl;
        
    while (inputfile >> num)
    {
        i++;
        sum += num;
        
        check = num % 2;
       
        
        if (check > 0)
        {
            odd++;
            
        }
        
        
        else
        {
            even++;
        
        }
        
        
        
        
    }
    
    
    
    
   
    average = sum / i;
    
    cout << "Number of even numbers is: " << even << " Number of odd numbers is: " << odd << endl;
    cout << "The total amount of numbers in the file is: " << i << " The total sum of numbers is " << sum << endl;
    cout << "The average of all the numbers is: " << average << endl;
    
    inputfile.close();
    

    return 0;
}

