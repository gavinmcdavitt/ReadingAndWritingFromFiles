/* Name: Gavin McDavitt
Date: 11/13/2022 Section: TLH Main Campus Online
Assignment: Module 10: Starbucks-Coffee Customer Rating Data Program
Due Date: 11/13/2022
About this project: This project uses different C++ libraries to read from a file and output the
 max rating of the price between different consumers. It  also fins the average service rating
 by different service methods.
 Assumptions: Assumes Correct user Input, if the user wants to quit the program they must input
 the wrong char. All work below was performed by Gavin McDavitt */
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
/*
 * I use two different functions to find the max price rating and average service rating. In each
 * function the function will read from each StarbucksData.txt to find the correct output.
 */
void displayMaxPrice(int col, int row);
void displayAverageService(int col, int row);
/*
 * In this function my program will Open the StarbucksData.txt and use a 2D array named matrix,
 * that will copy the data from StarbucksData.txt. I then close the file and use two for loops
 * to read through each data value in the matrix. I then declare and initial a sum, count, and
 * average for each of the 5 service options to zero. I then use these variables to find how many
 * times each number was shown and its value for each service. I then output the average formatted
 * as shown in the example.
 */

void displayAverageService(int col, int row)
{
    /*
     * I declare a 2d array named matrix that goes from col and row, declared in main.
     * I open the file and name it 'aveFile' I run a test to ensure the file has opened
     * with output for the user to understand. I then use two for loops to input into the
     * matrix and close the file.
     */
    int matrix[col][row];
    fstream aveFile;
    ifstream read;
    read.open("StarbucksData.txt", ios::in);
    if(!read.is_open())
    {
        cout<<"Error opening input file!"<<endl;
    }
    for(int i=0; i<col;i++)
    {
        for(int index =0; index<row;index++)
        {
            read>>matrix[i][index];
        }
    }
    read.close();
    /*
     * I declare and initialize three variables for each service method. It's important to
     * put average as '0' because options: 'never' and 'other' are not actually called.
     * This ensures that the computer does not nan for the average when (sum / count). The
     * number beside each one represent which method is being compared.
     * Method:  0 = Dine-in
     *          1 = Drive-thru
     *          2 = Take Away
     *          3 = Never
     *          4 = Others
     */
    aveFile.open("OutputB.txt", ios::out);
    //These variables are used for each sum.
    double sum0=0, count0=0, average0=0;
    double sum1=0, count1=0, average1=0;
    double sum2=0, count2=0, average2=0;
    double sum3=0, count3=0, average3=0;
    double sum4=0, count4=0, average4=0;

    /*
     *I then use two for loops to read through the 2D matrix. When the second row is equal
     * different numbers it represents the different methods. So in my first if statement,
     * row 2 is equal to zero. This means that the Dine-In option was selected. It then jumps to
     * the 5th row and is assigned to sum0. Count is added to for the average calculation. Then loops
     * through.
     *
     */

    for(int j=0; j<col;j++)
    {
        for (int a = 0; a < row; a++)
        {
            if(matrix[j][1]==0)
            {
                sum0+=matrix[j][4];
                count0++;
            }
            if(matrix[j][1]==1)
            {
                sum1+=matrix[j][4];
                count1++;
            }
            if(matrix[j][1]==2)
            {
                sum2+=matrix[j][4];
                count2++;
            }
            if(matrix[j][1]==3)
            {
                sum3+=matrix[j][4];
                count3++;
            }
            if(matrix[j][1]==4)
            {
                sum4+=matrix[j][4];
                count4++;
            }

        }//end of inner for loop
    }//end of outer for loop
    /*
     * To ensure that my program works and gives the correct output, I ensure that an option
     * was called. If an option is not called then it will fail the test and average will be
     * zero. In the current program, options 'never' and 'other' are not called and would fail
     * the test.
     */
    if(count0>1)
    {
        average0 = sum0/count0;
    }
    if(count1>1)
    {
        average1= sum1/count1;
    }
    if(count2>1)
    {
        average2= sum2/count2;
    }
    if(count3>1)
    {
        average3= sum3/count3;
    }
    if(count4>1)
    {
        average4= sum4/count4;
    }
    /*
     * Outputs the averages to the console.
     */
    cout<<"Dine In   "<<setw(11)<< setprecision(3)<<average0<<endl;
    cout<<"Drive-Thru"<< setw(11)<<setprecision(3)<< average1 << endl;
    cout<<"Take away "<< setw(11)<<setprecision(3) <<average2 <<endl;
    cout<<"Never     "<< setw(11)<< setprecision(4)<<average3 <<endl;
    cout<<"Other     "<< setw(11) << setprecision(4)<< average4<<endl;

    /*
     * Output the averages to the file, OutputB.txt.
     */
    aveFile<<"Dine In   "<<setw(11)<< setprecision(3)<< showpoint<<average0<<endl;
    aveFile<<"Drive-Thru"<< setw(11)<<setprecision(3)<< showpoint<< average1 << endl;
    aveFile<<"Take away "<< setw(11)<<setprecision(3)<<showpoint <<average2 <<endl;
    aveFile<<"Never     "<< setw(11)<< setprecision(3)<<showpoint<<average3 <<endl;
    aveFile<<"Other     "<< setw(11) << setprecision(3)<<showpoint<< average4<<endl;
}
/*
 * This function uses two int elements called in main. I open the StarbucksData.txt file, and test
 * for it being opened. I then use two for loops to input the contents of StarbucksData.txt into a
 * 2d array named matrix. I then close the file. I then use to two for loops to compare the array
 * with the max of each status. The different numbers at row 1 represent the different status.
 * When a Status is called then the fourth row is tested for each status with that status's max.
 * I then display the max price rating for each status.
 */
void displayMaxPrice(int col,int row)
{

    int matrix[col][row];
    fstream maxfile;
    ifstream read;
    read.open("StarbucksData.txt", ios::in);
    if(!read.is_open())
    {
        cout<<"Error opening input file!"<<endl;
    }
    for(int i=0; i<col;i++)
    {
        for(int index =0; index<row;index++)
        {
            read>>matrix[i][index];
        }
    }
    read.close();

    /*
     *I create and open the file OutputA.txt, it is tested to ensure that the correct file
     * opens. I declare and initialize max elements for each status to zero. This ensures that
     * the maximum will be larger than 0 and the true maximum will be shown.
     * Status:  0 = student
     *          1=self-employed
     *          2= employed
     *          3=housewife
     */
    maxfile.open("OutputA.txt", ios::out);//write
    if(!maxfile.is_open())
    {
        cout<<"Error opening output file!"<<endl;
    }
    int maxStudent=0;
    int maxSelf=0;
    int maxEmploy=0;
    int maxWife =0;
    /*
     * The two for loops read through the matrix to find out which status is shown. When a
     * status is called, that status is compared to it's max element. In the first option, the
     * two for loops try to find the number in the first row. This will give us the status of
     * each option. I then compare that col at the fourth row. If it is larger than maxStudent then
     * that number is now maxStudent. It then loops through.
     */
    for(int j=0; j<col;j++)
    {
        for(int a=0; a<row;a++)
        {
            if(matrix[j][0]==0)
            {
                if(matrix[j][3]>maxStudent)
                {
                    maxStudent = matrix[j][3];
                }
            }//if statement for student
            if(matrix[j][0]==1)
            {
                if(matrix[j][3]>maxSelf)
                {
                    maxSelf = matrix[j][3];
                }
            }//if statement for self
            if(matrix[j][0]==2)
            {
                if(matrix[j][3]>maxEmploy)
                {
                    maxEmploy = matrix[j][3];
                }
            }//if statement for employed
            if(matrix[j][0]==3)
            {
                if(matrix[j][3]>maxWife)
                {
                    maxWife=matrix[j][3];
                }
            }//if statement for wife.
        }//inner for loop
    }//outer for loop
    /*
     * Output the max for each status to console.
     */
    cout<<endl;
    cout<<"Student      "<<setw(10)<<maxStudent<<endl;
    cout<<"Self-Employed"<<setw(10)<<maxSelf<<endl;
    cout<<"Employed     "<<setw(10)<<maxEmploy<<endl;
    cout<<"Housewife    "<<setw(10)<<maxWife<<endl;

    /*
     * Output the max for each status to OutputA.txt.
     */
    maxfile<<"Student      "<<setw(10)<< maxStudent<<endl;
    maxfile<<"Self-Employed"<<setw(10)<<maxSelf<<endl;
    maxfile<<"Employed     "<<setw(10)<<maxEmploy<<endl;
    maxfile<<"Housewife    "<<setw(10)<<maxWife<<endl;
    maxfile<<endl;
    cout<<endl;
}
/*
 * This is my main function in which I have a forever while loop. This ensures that the two options
 * can be chosen. I initialize constant variables of columns and rows the size of the
 * file, StarbucksData.txt. When the user selects 'A' or 'a' displayMaxPrice is called. If the user
 * selects 'B' or 'b' then displayAverageService is called. If the user inputs the wrong answer then
 * the loop is broken and must be re-ran.
 *
 */
int main() {
    cout<<"Starbucks - Coffee Customer Rating Data"<<endl;
    cout<<"Options"<<endl;
    int one =1;
    char choice;
    const int col=113, row=5;
    while(one < 2)
    {
        cout<<"A) Display the maximum Price Rating by Status...\n"
              "B) Display the average Service Rating by Method...\n"
              "Please select option (A-B)... ";
        cin>>choice;
        if (choice == 'A'|| choice=='a')
        {
            displayMaxPrice(col, row);
        }
        if(choice== 'B'|| choice=='b')
        {
            displayAverageService(col, row);
        }
        else
        {
            cout<<"Invalid option"<<endl;
            break;
        }
    }
    return 0;
}
