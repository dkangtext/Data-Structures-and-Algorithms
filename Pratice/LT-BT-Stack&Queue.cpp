#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cctype>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n;
};

// Khởi tạo stack
void Init(Stack &S)
{
    S.n = 0;
    for (int i = 0; i < MAX; i++)
    {
        S.arr[i] = NULLDATA;
    }
}

// Kiểm tra xem stack đã đầy đủ chưa
int isFull(Stack S)
{
    if (S.n == MAX)
    {
        return true;
    }
    return false;
}

// Xóa phần tử ở đỉnh stack
void Push(Stack &S, int x)
{
    if (isFull(S))
    {
        return;
    }

    S.arr[S.n] = x;
    S.n++;
}

// Kiểm tra xem stack có rỗng không
int isEmpty(Stack S)
{
    if (S.n == 0)
    {
        return true;
    }
    return false;
}

// Xóa phần tử ở đỉnh stack
void Pop(Stack &S)
{
    if (isEmpty(S))
    {
        return;
    }

    if (S.n > 0)
    {
        S.n--;
    }
}

// Hàm trả về giá trị của phần tử nằm ở đỉnh stack mà không hủy nó
int Top(Stack S)
{
    if (S.n > 0)
    {
        return S.arr[S.n - 1];
    }
    return NULLDATA;
}

// In stack
void printStack(Stack S)
{
    if (S.n == 0)
    {
        cout << "Stack is empty";
        return;
    }

    for (int i = 0; i < S.n; i++)
    {
        cout << S.arr[i] << " ";
    }
}

// Hàm chuyển đổi số thập phân sang nhị phân (stack using array)
void DecimaltoBinary2(int n, Stack &S)
{
    if (n == 0)
    {
        Push(S, 0);
        return;
    }

    while (n > 0)
    {
        Push(S, n % 2);
        n = n / 2;
    }
}

// Hàm chuyển đổi số thập phân sang nhị phân (stack using linked list)
void DecimaltoBinary1(int n, Stack &S)
{
    if (n == 0)
    {
        Push(S, 0);
        return;
    }

    while (n > 0)
    {
        Push(S, n % 2);
        n = n / 2;
    }
}

// Kiểm tra xem chuỗi đã cho đóng mở ngoặc có hợp lệ hay không
int isValid(string s)
{
    Stack(S);
    Init(S);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            Push(S, 1);
        }
        else if (s[i] == ')')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
    }

    if (S.n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Kiểm tra xem chuỗi đã cho đóng mở ngoặc có hợp lệ hay không (new)
int isValid2(string s)
{
    Stack(S);
    Init(S);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            Push(S, s[i]);
        }
        else if (s[i] == ')'|| s[i] == ']' || s[i] == '}')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
    }

    if (S.n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Chuyển đổi cơ số - 2 (dùng STL)
void DecimaltoBinary(int n) 
{
    stack<int> Binary;  

    if (n == 0) 
    {
        cout << "0";
        return;
    }

    while (n > 0) 
    {
        Binary.push(n % 2);  
        n = n / 2;  
    }

    while (!Binary.empty()) 
    {
        cout << Binary.top();  
        Binary.pop();  
    }
}

// Kiểm tra toán học Latex
int isValid3(string s)
{
    Stack(S);
    Init(S);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            Push(S, 1);
        }
        else if (s[i] == ')')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
        else if (s[i] == ']')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
        else if (s[i] == '}')
        {
            if (S.n == 0)
            {
                return 0;
            }
            Pop(S);
        }
    }

    if (S.n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Tính giá trị biểu thức
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

// Hòa nhạc
long long demCapCoTheNhinThay(const vector<int> &chieuCao)
{
    stack<pair<int, int>> s;
    long long ketQua = 0;

    for (int i = 0; i < chieuCao.size(); i++)
    {
        int Dem = 1;

        while (!s.empty() && s.top().first <= chieuCao[i])
        {
            ketQua += s.top().second;
            if (s.top().first == chieuCao[i])
            {
                Dem += s.top().second;
            }
            s.pop();
        }

        if (!s.empty())
        {
            ketQua++;
        }

        s.push({chieuCao[i], Dem});
    }

    return ketQua;
}

int main()
{
    Stack S;
    Init(S);

    int n, x;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Push(S, x);
    }

    // In stack
    cout << "Stack:";
    printStack(S);

    cout << "\nTop:" << Top(S);
    Pop(S);

    // Cập nhật stack
    cout << "\nUpdated Stack:";
    printStack(S);

    cout << "\nTop:" << Top(S);

    // Hàm chuyển đổi số thập phân sang nhị phân
    cout << "\nNhap so thap phan: ";
    cin >> n;
    DecimaltoBinary1(n, S);

    cout << "So nhi phan: ";
    printStack(S);

    // Kiểm tra chuỗi có hợp lệ hay không
    string expr;
    cin >> expr;
    cout << isValid(expr);

    // Kiểm tra chuỗi có hợp lệ hay không
    string expr2; 
    cin>>expr2;
	cout<< isValid(expr2);

    // Chuyển đổi cơ số - 2
    int m;
    cin >> m;
    DecimaltoBinary(m);

    // Kiểm tra toán học Latex
    string expr3;
    cin >> expr3;
    cout << isValid3(expr3);

    // Tính giá trị biểu thức
    string bieuThuc;
    cin >> bieuThuc;
    queue<string> hauTo;
    trungToSangHauTo(bieuThuc, hauTo);
    double ketQua = tinhHauTo(hauTo);
    cout << ketQua << endl;

    // Buổi hòa nhạc
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> chieuCao(N);
    for (int i = 0; i < N; i++)
    {
        cin >> chieuCao[i];
    }
    cout << demCapCoTheNhinThay(chieuCao) << endl;

    return 0;
}