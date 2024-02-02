#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;
#define max 30

void Student_Record(float StudWeight[], string StudNames[], int StudNum)
{
	cout << endl
		<< left << setw(4) << "Sr."
		<< left << setw(15) << "Student Name"
		<< left << setw(7) << "Stud_Weight"
		<< endl;
	for (int i = 0; i < StudNum; i++)
	{
		cout << left << setw(4) << i+1 << " ";
		cout << left << setw(15) << StudNames[i] << " ";
		cout << left << setw(7) << StudWeight[i] << " ";
		cout << endl;
	}
}
void Student_Record_New(float StudWeight[], string StudNames[],float StudWNew[], int StudNum)
{
	cout << endl
		<< left << setw(4) << "Sr."
		<< left << setw(15) << "Student Name "
		<< left << setw(15) << "Stud_Weight "
		<< left << setw(15) << "Stud_Weight_New "
		<< endl;
	for (int i = 0; i < StudNum; i++)
	{
		cout << left << setw(4) << i + 1 << " ";
		cout << left << setw(15) << StudNames[i] << " ";
		cout << left << setw(15) << StudWeight[i] << " ";
		cout << left << setw(15) << StudWNew[i] << " ";
		cout << endl;
	}
}
void Difference_Weight(float StudWeight[],float StudWeightNew[],float Difference[], int StudNum)
{
	for (int i = 0; i < StudNum; i++)
	{
		Difference[i] = StudWeightNew[i] - StudWeight[i];
	}
}
void print_Difference(string StudNames[], float WeightDiff[], int StudNum)
{
	cout << endl
		<< left << setw(4) << "Sr. "
		<< left << setw(15) << "Student Name "
		<< left << setw(15) << "Weight_Differ "
		<< endl;
	for (int i = 0; i < StudNum; i++)
	{
		cout << left << setw(4) << i + 1 << " ";
		cout << left << setw(15) << StudNames[i] << " ";
		cout << left << setw(15) << WeightDiff[i] << "kg ";
		if (WeightDiff[i] == 0)
			cout << "  " << StudNames[i] << " had no change in weight.";
		else if (WeightDiff[i] > 0 && WeightDiff[i] <= 2.5)
			cout << "  " << StudNames[i] << " had a minor gain in weight.";
		else if (WeightDiff[i] < 0 && WeightDiff[i] >= -2.5)
			cout << "  " << StudNames[i] << " had a minor loss in weight.";
		else if (WeightDiff[i] < -2.5 && WeightDiff[i] >=-5)
			cout << "  " << StudNames[i] << " had a moderate loss in weight.";
		else if (WeightDiff[i] > 2.5 && WeightDiff[i] <= 5)
			cout << "  " << StudNames[i] << " had a moderate gain in weight.";
		else if (WeightDiff[i] < -5 )
			cout << "  " << StudNames[i] << " had a high loss in weight.";
		else if (WeightDiff[i] > 5 )
			cout << "  " << StudNames[i] << " had a high gain in weight.";
		cout << endl;
	}
}

int main()
{
	float StudWeight[max]{}, StudWeightNew[max]{}, WeightDiff[max]{};
	string StudNames[max]{};
	int TotalNum,StudNum=0;
	do
	{
		cout << 
			"How many Students you want to add to the record (Max 30): ";
		cin >> TotalNum;
	} while (TotalNum>30);
	do
	{
		cout << "Enter name of the student Sr." << StudNum+1 << " : ";
		getline(cin >> ws, StudNames[StudNum]);
		do
		{
			cout << 
				"Enter the weight(kg) of student " 
				<< StudNames[StudNum] << " Sr." << StudNum+1 << " : ";
			cin >> StudWeight[StudNum];
			if (StudWeight[StudNum] < 10)
				cout << "Invalid Weight...";
		} while (StudWeight[StudNum] < 10);
		StudNum++;
	} while (StudNum < TotalNum);
	cout << endl 
		 << "Weight(kg) input for " << StudNum << "Students is complete."
		 << endl 
		 << "Record of students on start of Term : ";
	Student_Record(StudWeight, StudNames, StudNum);
	cout << endl <<
		"The last day of term is here*"
		<< endl <<
		"Let's enter the Record of weights of students After the term."
		<< endl;
	StudNum = 0;
	do 
	{
		do
		{
			cout <<
				"Enter the New weight(kg) of student "
				<< StudNames[StudNum] << " Sr." << StudNum + 1 
				<< "(Previous Weight = "<< StudWeight[StudNum]<<") : ";
			cin >> StudWeightNew[StudNum];
			if (StudWeightNew[StudNum] < 10)
				cout << "Invalid Weight...";
		} while (StudWeightNew[StudNum] < 10);
		StudNum++;
	} while (StudNum < TotalNum);
	cout << endl
		<< "New Weight(kg) input for " << StudNum << "Students is complete."
		<< endl
		<< "Record of students on Start and end of Term : ";
	Student_Record_New(StudWeight, StudNames,StudWeightNew, StudNum);
	Difference_Weight(StudWeight, StudWeightNew,WeightDiff ,StudNum);
	print_Difference(StudNames, WeightDiff, StudNum);
	return 0;
}

