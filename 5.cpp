#include <iostream>
using namespace std;
void showarray(int arr[][3], int rows, int column)
{
	
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    const int row=3;
    const int col=3;
    int value = 0;
    int array[row][col]={0};
    
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<"Please enter value for ["<<i<<"]"<<"["<<j<<"]:";
            cin >> array[i][j];
        }
    }

    showarray(array,row,col);
    return 0;
}
