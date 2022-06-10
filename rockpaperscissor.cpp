/******************************************************************************

Brendan Warner
project 7
read from a file of test scores to find verious numbers.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
  int num;
  int i, j;
  double student_sum = 0, test_sum = 0, best_grade, tracker = 0;
  double student_average = 0, test_average = 0;




  const int SIZE1 = 5;
  const int SIZE2 = 3;
  int students_grades[SIZE1][SIZE2];
  ifstream open_file;
  open_file.open ("p6.txt");




  for (i = 0; i < SIZE1; i++)
    {
      for (j = 0; j < SIZE2; j++)
	{
	  open_file >> students_grades[i][j];

	}
    }


  for (i = 0; i < SIZE1; i++)
    {
      for (j = 0; j < SIZE2; j++)
	{
	  student_sum += students_grades[i][j];

	  if (j == SIZE2 - 1)
	    {
	      student_average = student_sum / (j + 1);
	      cout << fixed << setprecision (2) << showpoint;
	      cout << "Student average for " << i +
		1 << " is " << student_average << endl;
	      student_average = 0;
	      student_sum = 0;
	    }
	}
    }



  for (j = 0; j < SIZE2; j++)
    {
      for (i = 0; i < SIZE1; i++)
	{
	  test_sum += students_grades[i][j];

	  if (i == SIZE1 - 1)
	    {
	      test_average = test_sum / (i + 1);
	      cout << fixed << setprecision (2) << showpoint;
	      cout << "test average for test " << j +
		1 << " is " << test_average << endl;
	      test_average = 0;
	      test_sum = 0;
	    }
	}
    }

  best_grade = students_grades[0][0];
  for (i = 0; i < SIZE1; i++)
    {
      for (j = 0; j < SIZE2; j++)
	{


	  if (students_grades[i][j] > best_grade)
	    {
	      best_grade = students_grades[i][j];
	    }
	}
    }
  cout << "The best score is " << best_grade << endl;

  for (i = 0; i < SIZE1; i++)
    {
      for (j = 0; j < SIZE2; j++)
	{


	  if (students_grades[i][j] < 59)
	    {
	      tracker += 1;
	    }
	}
    }
  cout << setprecision(0);
  cout << "The number of failed tests was " << tracker << endl;
  open_file.close ();

  return 0;
}
