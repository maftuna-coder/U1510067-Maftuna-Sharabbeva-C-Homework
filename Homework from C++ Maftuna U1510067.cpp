#include<iostream>
#include <stdlib.h>
#include<iomanip>

using namespace std;
void Input_Grades();
void Input_credit_hours();
void Demonstrate_grades();
void Estimate_Grade_points();
void Estimate_GPA();
//applying static variables
static int Grades[4][3] = {};
static int Credit_hours[3] = {};
static float Grade_points[4][3] = {};
static float GPA[6] = {};

int main()//start of main function
{
	//call the functions
	Input_Grades();
	Input_credit_hours();
	Estimate_Grade_points();
	Demonstrate_grades();
	Estimate_GPA();
	system("pause");
	return 0;//end sucessfully 
}//end of the main function
void Input_Grades()//start the function
{
	for (int m = 0; m < 4; m++)//applying the for loop for entering the scores of 6 student
	{
		for (int n = 0; n < 3; n++)//applying the for loop for entering the scores of 6 student from 4 subjects
		{
			cout << "Enter the " << m + 1 << "student score from" << m + 1 << "subject : ";
			cin >> Grades[m][n];// to take the score of i+1 subject from user 
		}
	}
}// end of the function

void Input_credit_hours()//start the function
{
	for (int m = 0; m < 3; m++)//applying the for loop for entering creditsfrom 4 subjects
	{
		cout << "Enter the " << m + 1 << "subject credit hours: 0";
		cin >> Credit_hours[m];//taking the credit hours from the user
	}
}//end of function

void Demonstrate_grades()//satrt of the function
{
	cout << "student" << "\tSubject1\tSubject2\tSubject3\tSubject4" << endl;
	for (int m = 0; m < 4; m++)
	{
		cout << m + 1;
		for (int n = 0; n < 3; n++)
		{//to show the students grade and their GPA for each subject
			cout << setw(13) << Grades[m][n] << " " << Grade_points[m][n];
		}
		cout << endl;//to print the next student's grade and GPA in new line
	}
}//end of function
void Estimate_Grade_points()
{
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 3; n++)
		{
			if (Grades[m][n] >= 95 && Grades[m][n] <= 100)
				Grade_points[m][n] = 4.5;
			else if (Grades[m][n] >= 90 && Grades[m][n] <= 89)
				Grade_points[m][n] = 4.0;
			else if (Grades[m][n] >= 80 && Grades[m][n] <= 84)
				Grade_points[m][n] = 3.5;
			else if (Grades[m][n] >= 75 && Grades[m][n] <= 79)
				Grade_points[m][n] = 2.0;
			else if (Grades[m][n] >= 64 && Grades[m][n] <= 69)
				Grade_points[m][n] = 1.5;
			else
				Grade_points[m][n] = 0.0;
		}
	}
}//end of the function
void Estimate_GPA()//begin of the function
{
	int credits = 0;
	for (int n = 0; n < 3; n++)//estimate the full credit hours
		credits += Credit_hours[n];
	for (int m = 0; m <4; m++)//estimate the fullscore from all subjects
	{
		float sum = 0;//i need this variable for calculate the full score
		for (int n = 0; n < 3; n++)//calculate the full score from all subjects
		{
			sum += Credit_hours[n] * Grade_points[m][n];
		}
		GPA[m] = float(sum / credits);//calculate the GPA for each student
		cout << "Student " << m + 1 << "GPA: " << GPA[m] << endl;
	}
}//end of the function