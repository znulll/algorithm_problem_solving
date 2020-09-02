#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string m_sInput;
int width;
int height;
char** m_cNewArr;
void input(void);
void findNum(int);
void input()
{
    height = 1;
    width = 1;
    getline(cin,m_sInput);
    int nStrLen = m_sInput.length();
    findNum(nStrLen);
    
    m_cNewArr = new char*[width];
    for(int i= 0; i < width;i++)
    {
        m_cNewArr[i] = new char[height];
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            m_cNewArr[y][x] = m_sInput.at(x*height+y);
        }
    }

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                cout<<m_cNewArr[y][x] ;
            }
        }
    // cout<<nStrLen<<endl;

}
void findNum(int strLen)
{
    int max = 0;
    int temp = 0;
    
    while(1)
    {

        if(width >= max)
        {
            max = width;
        }
        if(strLen % width == 0 )  
        {
           temp  = strLen / width;

        }
        if(temp <= width) break;
        width ++;
    }
    width = max;
    height = strLen / width;
    // cout<<"width : "<<width<<" height : "<<height<<endl;
}
int main()
{
    input();


    for(int i= 0; i < width;i++)
    {
         delete[] m_cNewArr[i];
    }
    delete []m_cNewArr;

    return 0;
}