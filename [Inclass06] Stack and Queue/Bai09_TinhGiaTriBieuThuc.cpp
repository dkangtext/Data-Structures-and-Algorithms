#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <map>

using namespace std;

#define MAX 2000
#define NULLDATA -1

int mucDoUuTien(char toanTu)
{
    if (toanTu == '+' || toanTu == '-')
        return 1;
    if (toanTu == '*' || toanTu == ':')
        return 2;
    return 0;
}

void trungToSangHauTo(const string &bieuThuc, queue<string> &hauTo)
{
    stack<char> toanTu;

    for (size_t i = 0; i < bieuThuc.size(); ++i)
    {
        if (isdigit(bieuThuc[i]))
        {
            string so;
            while (i < bieuThuc.size() && isdigit(bieuThuc[i]))
            {
                so += bieuThuc[i];
                ++i;
            }
            hauTo.push(so);
            --i;
        }
        else if (bieuThuc[i] == '(')
        {
            toanTu.push(bieuThuc[i]);
        }
        else if (bieuThuc[i] == ')')
        {
            while (!toanTu.empty() && toanTu.top() != '(')
            {
                hauTo.push(string(1, toanTu.top()));
                toanTu.pop();
            }
            toanTu.pop();
        }
        else
        {
            while (!toanTu.empty() && mucDoUuTien(toanTu.top()) >= mucDoUuTien(bieuThuc[i]))
            {
                hauTo.push(string(1, toanTu.top()));
                toanTu.pop();
            }
            toanTu.push(bieuThuc[i]);
        }
    }

    while (!toanTu.empty())
    {
        hauTo.push(string(1, toanTu.top()));
        toanTu.pop();
    }
}

double tinhHauTo(queue<string> &hauTo)
{
    stack<double> giaTri;

    while (!hauTo.empty())
    {
        string kyHieu = hauTo.front();
        hauTo.pop();

        if (isdigit(kyHieu[0]))
        {
            giaTri.push(stod(kyHieu));
        }
        else
        {
            double b = giaTri.top();
            giaTri.pop();
            double a = giaTri.top();
            giaTri.pop();

            switch (kyHieu[0])
            {
            case '+':
                giaTri.push(a + b);
                break;
            case '-':
                giaTri.push(a - b);
                break;
            case '*':
                giaTri.push(a * b);
                break;
            case ':':
                giaTri.push(a / b);
                break;
            }
        }
    }

    return giaTri.top();
}

int main()
{
    string bieuThuc;
    cin >> bieuThuc;

    queue<string> hauTo;
    trungToSangHauTo(bieuThuc, hauTo);
    
    double ketQua = tinhHauTo(hauTo);

    cout << ketQua << endl;
    return 0;
}