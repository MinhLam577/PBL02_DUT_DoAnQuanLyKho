#include "mathang.h"
#include "loaimathang.h"
ifstream mathang::filein;
ofstream mathang::fileout;
bool mathang::CheckSoThuc(string s)
{
	if (stof(s) <= 0)
	{
		return false;
	}
	if (s[0] == '.') return false;
	for (int i = 1; i < s.length() - 1; i++)
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			return false;
		}
	}
	if (s[s.length() - 1] == '.') return false;
	return true;
}
bool mathang::CheckId(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if ((a[i] < 'a' || a[i] > 'z') && (a[i] < 'A' || a[i] > 'Z') && (a[i] < '0' || a[i] > '9'))
		{
			return false;
		}
	}
	return true;
}
bool mathang::CheckName(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if ((a[i] < 'a' || a[i] > 'z') && (a[i] < 'A' || a[i] > 'Z'))
		{
			return false;
		}
	}
	return true;
}
bool mathang::CheckSoLuong(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] < '0' || a[i] > '9')
		{
			return false;
		}
	}
	return true;
}
void mathang::NhapChuoi(string out, string& a)
{
	cout << out;
	rewind(stdin);
	getline(cin, a);
}
void CachDong(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
}
void mathang::Nhapfile()
{
	filein >> maMh >> tenMh >> soluongMh >> DonGia >> NgaySanXuat >> NgayHetHan;
}
void mathang::Xuatfile()
{
	fileout << maMh << setw(30) << tenMh << setw(20) << soluongMh << setw(20) << DonGia << setw(20) << NgaySanXuat << setw(20) << NgayHetHan;
}
bool mathang::CheckDayNum(int day, int month, int year)
{
	if (day <= 0) return false;
	if (year <= 0) return false;
	int songay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) songay[2] = 29;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > songay[month]) return false;
	}
	else if (month == 2)
	{
		if (day > songay[month]) return false;
	}
	else if (day > songay[month]) return false;
	return true;
}
int mathang::GetDay(string Date)
{
	int i = 0; string d = "";
	while (i < 3)
	{
		d += Date[i];
		i++;
	}
	return stoi(d);
}
int mathang::GetMonth(string Date)
{
	int i = 3; string m = "";
	while (i < 6)
	{
		m += Date[i];
		i++;
	}
	return stoi(m);
}
int mathang::GetYear(string Date)
{
	int i = 6; string y = "";
	while (i < Date.length())
	{
		y += Date[i];
		i++;
	}
	return stoi(y);
}
bool mathang::CheckDateSanXuat(string Date, int& ngaysanxuat, int& thangsanxuat, int& namsanxuat)
{
	time_t now = time(0);
	tm* lm = localtime(&now);
	int namhientai = lm->tm_year + 1900;
	int ngayhientai = lm->tm_mday;
	int thanghientai = lm->tm_mon + 1;
	int ngay = -1, thang = -1, nam = -1; string d, m, y, t;
	if (Date.length() != 10) return false;
	int i = 0;
	while (i < 3)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			d = t + Date[i + 1];
			ngay = stoi(d);
		}
		i += 3;
	}
	while (i < 6)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			m = t + Date[i + 1];
			thang = stoi(m);
		}
		i += 3;
	}
	while (i < Date.length())
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9'))
		{
			return false;
		}
		else
		{
			y += Date[i];
		}
		i++;
	}
	nam = stoi(y);
	if (nam > namhientai)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNam san xuat <= nam hien tai\n";
		return false;
	}
	else if (nam == namhientai && thang > thanghientai)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tThang san xuat <= thang hien tai\n";
		return false;
	}
	else if (thang == thanghientai && ngay > ngayhientai)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay san xuat <= ngay hien tai\n";
		return false;
	}
	if (thang <= 0 || thang > 12) return false;
	else
	{
		if (CheckDayNum(ngay, thang, nam) == false) return false;
	}
	ngaysanxuat = ngay; thangsanxuat = thang; namsanxuat = nam;
	return true;
}
bool mathang::CheckDateHetHan(string Date, int ngaysanxuat, int thangsanxuat, int namsanxuat)
{
	int ngay = -1, thang = -1, nam = -1; string d, m, y, t;
	if (Date.length() != 10) return false;
	int i = 0;
	while (i < 3)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			d = t + Date[i + 1];
			ngay = stoi(d);
		}
		i += 3;
	}
	while (i < 6)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			m = t + Date[i + 1];
			thang = stoi(m);
		}
		i += 3;
	}
	while (i < Date.length())
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9'))
		{
			return false;
		}
		else
		{
			y += Date[i];
		}
		i++;
	}
	nam = stoi(y);
	if (nam < namsanxuat)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNam het han >= nam san xuat\n";
		return false;
	}
	else if (nam == namsanxuat && thang < thangsanxuat)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tThang het han >= thang san xuat\n";
		return false;
	}
	else if (thang == thangsanxuat && ngay < ngaysanxuat)
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay het han >= ngay san xuat\n";
		return false;
	}
	if (thang <= 0 || thang > 12) return false;
	else
	{
		if (CheckDayNum(ngay, thang, nam) == false) return false;
	}
	return true;
}
bool mathang::CheckDate(string Date)
{
	string d, m, y, t; int ngay = -1, thang = -1, nam = -1;
	if (Date.length() != 10) return false;
	int i = 0;
	while (i < 3)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			d = t + Date[i + 1];
			ngay = stoi(d);
		}
		i += 3;
	}
	while (i < 6)
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9') && Date[i + 2] != '/')
		{
			return false;
		}
		else
		{
			t = Date[i];
			m = t + Date[i + 1];
			thang = stoi(m);
		}
		i += 3;
	}
	while (i < Date.length())
	{
		if ((Date[i] < '0' || Date[i] > '9') && (Date[i + 1] < '0' || Date[i + 1] > '9'))
		{
			return false;
		}
		else
		{
			y += Date[i];
		}
		i++;
	}
	nam = stoi(y);
	if (CheckDayNum(ngay, thang, nam) == false) return false;
	return true;
}
void mathang::Nhap()
{
	bool check = true, check2; int ngaysanxuat, thangsanxuat, namsanxuat;
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap ma mat hang: ", maMh);
		check = CheckId(maMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
	} while (check == false);
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang: ", tenMh);
		check = CheckName(tenMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
	} while (check == false);
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao so luong mat hang: ", soluongMh);
		check2 = true;
		check = CheckSoLuong(soluongMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong khong hop le. Xin nhap lai\n";
		else
		{
			if (stoi(soluongMh) < 0)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong >= 0. Xin nhap lai\n";
				check2 = false;
			}
		}
	} while (check == false || check2 == false);
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao don gia mat hang: ", DonGia);
		check2 = true;
		check = CheckSoLuong(DonGia);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDon gia khong hop le. Xin nhap lai\n";
		else
		{
			if (stoi(DonGia) < 0)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDon gia >= 0. Xin nhap lai\n";
				check2 = false;
			}
		}
	} while (check == false || check2 == false);
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap ngay san xuat: ", NgaySanXuat);
		check = CheckDateSanXuat(NgaySanXuat, ngaysanxuat, thangsanxuat, namsanxuat);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay san xuat khong hop le. Xin nhap lai\n";
	} while (check == false);
	do {
		NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap ngay het han: ", NgayHetHan);
		check = CheckDateHetHan(NgayHetHan, ngaysanxuat, thangsanxuat, namsanxuat);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay het han khong hop le. Xin nhap lai\n";
	} while (check == false);
}
void mathang::Xuat()
{
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan" };
	table.setStyle(1);
	table += {maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan};
	table.setPadding(9);
	cout << table;
}
string mathang::Get_mamh()
{
	return maMh;
}
string mathang::Get_tenmh()
{
	return tenMh;
}
string mathang::Get_soluongmh()
{
	return soluongMh;
}
string mathang::Get_DonGia()
{
	return DonGia;
}
string mathang::Get_NgaySanXuat()
{
	return NgaySanXuat;
}
string mathang::Get_NgayHetHan()
{
	return NgayHetHan;
}
void mathang::Set_soluongmh(int soluong)
{
	string a = to_string(soluong);
	soluongMh = a;
}
void mathang::Set_maMh(string ma)
{
	maMh = ma;
}
void mathang::Set_tenMh(string ten)
{
	tenMh = ten;
}
void mathang::SetDonGia(string dg)
{
	DonGia = dg;
}
void mathang::SetNgaySanXuat(string nsx)
{
	NgaySanXuat = nsx;
}
void mathang::SetNgayHetHan(string hsd)
{
	NgayHetHan = hsd;
}
mathang*& mathang::operator=(mathang*& x)
{
	mathang* a = new MatHangRong;
	a->maMh = x->maMh;
	a->tenMh = x->tenMh;
	a->soluongMh = x->soluongMh;
	a->DonGia = x->DonGia;
	a->NgaySanXuat = x->NgaySanXuat;
	a->NgayHetHan = x->NgayHetHan;
	return a;
}