/******************************************************************************

                              Brendan Warner
                              Project 1, program creates an array from user input, splits it into odd and even arrays, then compares
                              them to see which value is larger in each section. after this a final array is created with the winners
                              , the array is displayed and sorted.
                              2/14/2020

*******************************************************************************/

#include <iostream>
#include <ctime>

using namespace std;


void initialize_array(int [], int);

int * shuffle_array( int [], int);

void print_array( int [], int);

int * createOddArray( int [], int, int &);

int * createEvenArray( int [], int, int &);

void array_war(int *, int, int *, int);

void sort_array(int *,int);

int main()
{
    
    int user_input, size, i;
    int count_odd = 0, count_even = 0;// creats sizes holders for odd and even arrays
    
    cout << "plese enter the size of an array between 1 and 52" << endl;
    cin >> user_input;
    if (user_input < 1 or user_input >52)
    {
        cout << "error, number is out of bounds, please enter a new number" << endl;
        cin >> user_input;
    }
    size = user_input;
    
    
    
    int user_array[size];
    
    initialize_array(user_array, size);//calls a function to initialize the array
    
    
    
    
    
    
    
    int * shuffled_array = nullptr;//generates new dynamic array
    
    shuffled_array = shuffle_array(user_array, size);//calls a function that shuffles the array
    
    
    print_array(shuffled_array, size); //calls a function to print the shuffled array
    
    
    
    int * odd_array = nullptr;
    odd_array = createOddArray(shuffled_array, size, count_odd);//calls a funtion to create a new array filled with odd numbers from shuffled array
    
    
    int * even_array = nullptr;//creats new dynamic array for even numbers
    
    even_array = createEvenArray(shuffled_array, size, count_even);//calls a function to create a new array filled with even numbers from shuffled_array
    
    
    
    
    
    array_war(odd_array, count_odd, even_array, count_even);//sends both odd and even array to compare numbers and create a new array based on the winners of position winners
    
    
    
    delete [] shuffled_array;
    
    delete [] even_array;
    delete [] odd_array;
    
    

    
    return 0;
}




void initialize_array(int array1[], int num1)
{
    int i = 0;
    cout << "Your array is: ";
    
    for(i=0; i < num1; i++) // adds numbers to array then prints
    {
        array1[i] = i+1;
        cout << array1[i] << " "; 
    }
    
    
}



int * shuffle_array( int array2[], int num2)
{
    
    int i = 0, j;
    srand ((unsigned) time(0));//seeds the random number generator
    
    
    
    int * shuffled_array = new int [num2];
    
    for (i = 0; i < num2; i ++)
    {
        shuffled_array[i] = array2[i];
        
    }
    
    
    for (i = 0; i < num2; i ++)//randomly chooses a point in the array and swaps it with point i
    {
        j = (rand() % (num2 - 1));
        swap(shuffled_array[i], shuffled_array[j]);
        
        
    }
    
    return shuffled_array;
    
    
    
}

void print_array( int  array3[], int num3)
{
    int i;
    cout << "\nYour shuffled array is: ";
    for (i = 0; i < num3; i++)//prints array
    {
        cout << array3[i] << " ";
        
    }
    

}


int * createOddArray( int  array4[], int num4, int &count_odd)
{
    int i, j = 0;
    
    
    for(i = 0; i < num4; i++)//finds what size odd array is
    {
        if(array4[i] % 2 != 0)
        {
            count_odd++;
        }
    }
    
    
    
    int * odd_array = new int [count_odd];
    
    for(i = 0; i < num4; i++)//assigns odd numbers from shuffled_array to odd array
    {
        if (array4[i] % 2 != 0)
        {
            odd_array[j] = array4[i];
            j++;
        }
    }
    
    
    cout << "\nYour odd array is: ";
    for(i = 0; i < count_odd; i++)
    {
        cout << odd_array[i] << " ";
    }
    
    return odd_array;
}

int * createEvenArray( int  array5[], int num5, int &count_even)
{
    int i, j = 0;
    
    for(i = 0; i < num5; i++)//finds what size array even should be
    {
        if(array5[i] % 2 == 0)
        {
            count_even++;
        }
    }
    
    
    
    int * even_array = new int [count_even];
    
    for(i = 0; i < num5; i++)//assigns numbers from shuffled_array to even array
    {
        if(array5[i] % 2 == 0)
        {
            even_array[j] = array5[i];
            j++;
        }
    }
    
    cout << "\nYour even array is: ";
    for(i=0; i < count_even; i++)
    {
        cout << even_array[i] << " ";
    }
    
    
    return even_array;
    
}


void array_war(int  odd_array[], int num5, int  even_array[], int num6)
{
    int lesser_count = 0, i = 0, final_size;
    
    if (num5 > num6)//used to find how far we need to compare before we hit out of bounds on one of two arrays if aplicable
    {
        lesser_count = num6;
        final_size = num5;
    }
    
    else 
    {
        lesser_count = num5;
        final_size = num6;
    }
    
    
    
    int * array_w_store = nullptr;
    array_w_store = new int [final_size];
    for(i=0; i < lesser_count; i++) //assigns winning variables from even and odd arrays to new array
    {
        if (odd_array[i] > even_array[i])
        {
            array_w_store[i] = odd_array[i];
        }
        
        else
        {
            array_w_store[i] = even_array[i];
            
        }
    }
    
    if( num5 > num6)//used to add the autamatic winner from an array that was larger then another
    {
        for(i = final_size - 1; i >= lesser_count; i--)
        {
            array_w_store[i] = odd_array[num5 - 1];
        }
    }
    
    cout << "\nThe array winners are: ";
    for (i=0; i < final_size; i++)
    {
        cout << array_w_store[i] << " ";
    }
    
    sort_array(array_w_store, final_size);//sorts array filled with winning numbers from smallest to largest and prints them
    
    
}

void sort_array(int  array_w_store[],int num7)
{
    int i, j;
    
    
    
    for(i = num7 - 1; i > 0; i--)//bubble sort for winner array
    {
        for(j = 0; j< i; j++)
        {
            if (array_w_store[j] > array_w_store[j+1])
            {
                swap(array_w_store[j], array_w_store[j + 1]);
            }
        }
    }
    cout << "\nYour array winner sorted is ";
    for(i=0; i < num7; i++)//prints winner array
    {
        cout  << array_w_store[i] << " ";
    }
    delete [] array_w_store;
    
}