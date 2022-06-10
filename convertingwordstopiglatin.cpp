/******************************************************************************

                              Brendan Warner
                              project 2; converting english words to pig latin
                              2/28/2020

*******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Word 
{
 string english;
 string piglatin;
};

Word * splitSentence(string , int& ); // splits the words into an array of sturcts
void convertToPigLatin(Word [] , int ); // converts english to pig latin

int main()
{
    string user_input;
    int size;
    
    cout << "please enter a word or phrase" << endl;
    getline(cin, user_input);
    
    Word * convert_input = nullptr;//creates array pointer for a dynamic array
    convert_input = splitSentence(user_input, size);//passes string to function to split and add to structs
    
    
    convertToPigLatin(convert_input,size); // takes array of sturcts and converts english to pig latin
    
    return 0;
    
    delete [] convert_input;//delets dynamic array
}

Word * splitSentence ( string user_word, int &size)
{
    int i, j=0, h, t=0; // variable for manipulating for loops
    h = user_word.length();
    string fix_word;
    
    
    for(i = 0; i < h; i++)//used to generate the size fo the array of structs
    {
		if(i == h-1)
		{
			size++;
			break;
		}
        if((isalpha(user_word[i]) || ispunct(user_word[i])) && isspace(user_word[i+1]))//checks for printable character and white space to determine words
        {
            size++;
        }
    }
    cout << size << " " << h << endl;
    Word * convert_input = new Word [size];//creates dynamic array
    
    
    for(i = 0; i < h; i++)//adds words to array of sturcts
    {
		if(i == h-1)
		{
			convert_input[t].english = user_word.substr(j,(i+1)-j);//adds substrings to english member of the array of structs
			break;
		}
	
        if((isalpha(user_word[i]) || ispunct(user_word[i])) && isspace(user_word[i+1]))
        {
            convert_input[t].english = user_word.substr(j,(i+1)-j);//adds substrings to english member of the array of structs
            j=i+1;
            t++;
            
        }
        
        
    }
    
    string hold_char;
    
    for(i = 0; i < size; i++)//used to delete white space and puncuation in strings
    {
        h = convert_input[i].english.length();//fetches new length for going through the next string
        
        
        for(t = 0; t < h; t++)
        {
            
            if(isalpha(convert_input[i].english[t]))
            {
                hold_char = tolower(convert_input[i].english[t]);
                
                
                fix_word.append(hold_char);
                
            }
            
        }
        
        
        convert_input[i].english = fix_word;
        
        fix_word.clear();
        
    }
    
    
    return convert_input;//returns array of structs
}

void convertToPigLatin(Word convert_input [], int size)//converts english to pig latin
{
    
    int i,t;
	string h;
    string character;//hold the first character to test for vowels 
    
    for(i = 0; i < size; i++)
    {
        h = convert_input[i].english[0];
        if(h == "a" or h == "e" or h == "i" or h == "o" or h == "u" )//checking for vowel
        {
        
            convert_input[i].piglatin = convert_input[i].english;
            convert_input[i].piglatin.append("way");
        
        }
        
        else//if not vowel, adds first letter to the end of the word as well as "ay"
        {
            
            convert_input[i].english.erase(convert_input[i].english.begin());
        
            convert_input[i].piglatin = convert_input[i].english;
        
		    convert_input[i].piglatin.append(h);
		
            convert_input[i].piglatin.append("ay");
            
        }
    }
    
    cout << "Your word(s) in pig latin are: ";
    for(i =0; i <size; i++)//outputs converted pig latin word
    {
        cout  << convert_input[i].piglatin << " ";
        
    }
    
}
