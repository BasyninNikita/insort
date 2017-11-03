#include <iostream>
#include <string>
#include <utility>
#include <sstream>
using namespace std;
void vyvod(int *array,unsigned int size)
{
	for(unsigned int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
bool vvod(int *array,unsigned int size)
{
    string stroka;
    getline(cin,stroka);
    istringstream stream(stroka);
    for(unsigned int i=0;i<size;i++)
    {
        if(!(stream>>array[i])){
            cout<<"nepolnuy massiv";
            return false;
        }   
    }
    return true;
}
void insort(int *array,unsigned int size)
{
	for(unsigned int i=0;i<size;i++)
	{
		for(unsigned int j=i;j>0;j--)
		{
			if(array[j]<array[j-1]){swap(array[j-1],array[j]);} else break;
		}
	}
}
int main(int argc, char** argv) {
	unsigned int size;
	string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	if(!(stream>>size)){
        	cout<<"error"<<endl;
       		return -1;
    	}	
	int *array=new int[size];
	if(vvod(array,size))
	{
		insort(array,size);
		vyvod(array,size);
	}
	delete[]array;
	return 0;
}
