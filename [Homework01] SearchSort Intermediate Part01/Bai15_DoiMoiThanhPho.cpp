/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE - DO NOT CLEAR THIS LINE###

typedef long long ll;

ll tinhSoCayTrongNgay(ll soNgay, ll soLuongDoi1, ll ngayNghiDoi1,
                      ll soLuongDoi2, ll ngayNghiDoi2)
{  
    ll soNgayLamDoi1 = soNgay - (soNgay / ngayNghiDoi1);
    ll soNgayLamDoi2 = soNgay - (soNgay / ngayNghiDoi2);

    ll tongDoi1 = soNgayLamDoi1 * soLuongDoi1;
    ll tongDoi2 = soNgayLamDoi2 * soLuongDoi2;

    return tongDoi1 + tongDoi2;
}

ll timKetQua(ll soLuongDoi1, ll ngayNghiDoi1,
             ll soLuongDoi2, ll ngayNghiDoi2, ll tongSoCayCanChat)
{
    ll left = 1;
    
    ll right = 2e18 / (soLuongDoi1 + soLuongDoi2) + 1;

    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        ll soCayChat = tinhSoCayTrongNgay(mid, soLuongDoi1, ngayNghiDoi1,
                                          soLuongDoi2, ngayNghiDoi2);

        if (soCayChat >= tongSoCayCanChat)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll soLuongDoi1, ngayNghiDoi1, soLuongDoi2, ngayNghiDoi2, tongSoCayCanChat;
    cin >> soLuongDoi1 >> ngayNghiDoi1 >> soLuongDoi2 >> ngayNghiDoi2 >> tongSoCayCanChat;

    cout << timKetQua(soLuongDoi1, ngayNghiDoi1, soLuongDoi2, ngayNghiDoi2, tongSoCayCanChat);

    return 0;
}