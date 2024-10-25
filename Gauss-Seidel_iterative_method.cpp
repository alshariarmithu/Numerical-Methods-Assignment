#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
const int N=6;
double A[N][N],X[N],Y[N];
void string_to_coefficient(string s,int i)
{
    int num=0;
    int sign=1;
    int idx=0;
    if (s[0]=='-')
    {
        sign=-1;
        idx=1;
    }
    for(int j=idx;j<s.length();j++)
    {
        if (s[j]<='9' && s[j]>='0')
        {
            num=num*10+(s[j]-'0');
        }
        else if(s[j]=='x')
        {
            if(num==0)
            {
                num = 1;
            }
            A[i][1]=sign*num;
            num=0;
            sign=1;
        }
        else if(s[j]=='y')
        {
            if(num==0)
            {
                num = 1;
            }
            A[i][2]=sign*num;
            num=0;
            sign=1;
        }
        else if(s[j]=='z')
        {
            if(num==0)
            {
                num=1;
            }
            A[i][3]=sign*num;
            num=0;
            sign=1;
        }
        else if(s[j]=='w')
        {
            if(num==0)
            {
                num=1;
            }
            A[i][4]=sign*num;
            num=0;
            sign=1;
        }
        if(s[j]=='-')
        {
            sign=-1;
        }
        else if(s[j]=='+')
        {
            sign=1;
        }
    }
    X[i]=sign*num;
}
void gaussSeidelMethod(int n, int maxIter, double tolerance)
{
    double sol[N]={0};
    for(int i=1;i<=n;i++)
    {
        Y[i] = 0;
    }
    cout<<"\nGauss-Seidel Iteration:\n";
    for(int iter=0;iter<maxIter;iter++)
    {
        bool converged=true;
        for(int i=1;i<=n;i++)
        {
            double sum=0;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    sum+=A[i][j]*sol[j];
                }
            }
            sol[i]=(X[i]-sum)/A[i][i];
        }
        for(int i=1;i<=n;i++)
        {
            if(fabs(sol[i]-Y[i])>tolerance)
            {
                converged = false;
            }
            Y[i]=sol[i];
            cout<<"x"<<i<<" = "<<sol[i]<< "\t";
        }
        cout<<endl;
        if(converged)
        {
            cout<<"Gauss-Seidel method converged after "<<iter + 1<<" iterations.\n";
            break;
        }
    }
    cout<<"\nSolution:\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"x"<<i<<" = "<<sol[i]<<endl;
    }
}
int main()
{
    int n,maxIter;
    double tolerance;
    cout<<"Enter the number of variables (max: 5): ";
    cin>>n;
    cout<<"Enter the equations:\n";
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        string_to_coefficient(s,i);
    }
    cout<<"\nCoefficient Matrix:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<"\t"<<X[i]<< endl;
    }
    cout<<"Enter the maximum number of iterations: ";
    cin>>maxIter;
    cout<<"Enter the tolerance: ";
    cin>>tolerance;
    gaussSeidelMethod(n, maxIter, tolerance);
    return 0;
}
