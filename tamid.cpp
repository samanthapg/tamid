#include <iostream>
#include <vector>
using namespace std; 

int find_max(int num1, int num2)
{
	if (num1>num2)
	{
		return num1;
	}
	else
	{
		return num2; 
	}
}

int max_profit(vector <int> arr)
{
//assuming positive integers and 0

	//int size = *(&arr + 1) - arr; 
	int size =arr.size();  
	vector <int> cumm_profit(size, 0); 
	//cout<<"size is "<<size<<endl; 

	int min=arr[0]; 
	int max=arr[size-1]; 

	for (int i=size-2; i>0; i--)
	{ 
		if (max < arr[i])
		{
			max=arr[i];
		}
		//update profit
		cumm_profit[i]=find_max(max-arr[i],cumm_profit[i+1]); 
	}

	for (int i=1; i<size; i++)
	{
		if (min > arr[i])
		{
			min= arr[i]; 

		}
		//update profit
		cumm_profit[i]=find_max(cumm_profit[i]-min+arr[i], cumm_profit[i-1]); 
	}

return cumm_profit[size-1]; 
}

int main()
{
	//test case 1 
	vector <int> arr; 
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(4);
	int result=max_profit(arr);
	cout<<"max profit is: "<<result<<endl; 

	//test case 2 
	arr.clear(); 
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	result=max_profit(arr);
	cout<<"max profit 2 is: "<<result<<endl; 

	//test case 3
	arr.clear(); 
	arr.push_back(7);
	arr.push_back(6);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(1);
	result=max_profit(arr);
	cout<<"max profit is: "<<result<<endl; 

	//test case 4 
	arr.clear(); 
	arr.push_back(0);
	result=max_profit(arr);
	cout<<"max profit is: " <<result<<endl; 

	//test case 5
	arr.clear(); 
	arr.push_back(100);
	arr.push_back(30);
	arr.push_back(200000);
	arr.push_back(10);
	arr.push_back(8);
	arr.push_back(25); 
	arr.push_back(80); 
	result=max_profit(arr);
	cout<<"max profit is: "<<result<<endl; 

	return 0; 
}