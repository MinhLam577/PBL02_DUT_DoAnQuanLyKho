#include "loaimathang.h"
ifstream loaimathang::filein;
ofstream loaimathang::fileout;
string loaimathang::Inhoa(string s)
{
	string t = "";
	for (int i = 0; i < s.length(); i++)
	{
		int c = s[i];
		t += (char)toupper(c);
	}
	return t;
}
void loaimathang::Nhap()
{
	bool check = true;
	do {
		mathang::mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap ma loai mat hang: ", maloaiMh);
		check = mathang::CheckId(maloaiMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
	} while (check == false);
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang: ", tenloaiMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
		check = mathang::CheckName(tenloaiMh);
	} while (check == false);
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten cac mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t*     MENU     *\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Nhap Them\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
		string luachon;
		do {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; cin >> luachon;
			if (luachon != "1" && luachon != "0") cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
		} while (luachon != "1" && luachon != "0");
		int dem = 1;
		if (luachon == "1")
		{
			mathang* x = new MatHangRong;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao thong tin mat hang thu " << dem++ << "\n"; x->Nhap();
			List_Mh.push_back(x); system("pause");
		}
		else break;
	}
}
void loaimathang::NhapFile()
{
	filein >> maloaiMh;
	filein >> tenloaiMh;
	string tenfile = tenloaiMh + ".txt";
	mathang::filein.open(tenfile);
	while (!mathang::filein.eof())
	{
		if (Inhoa(tenloaiMh) == Inhoa("thuocla"))
		{
			mathang* x = new Mathangthuocla;
			x->Nhapfile();
			List_Mh.push_back(x);
		}
		else if (Inhoa(tenloaiMh) == Inhoa("bia"))
		{
			mathang* x = new Mathangbia;
			x->Nhapfile();
			List_Mh.push_back(x);
		}
		else if(Inhoa(tenloaiMh) == Inhoa("ruou"))
		{
			mathang* x = new Mathangruou;
			x->Nhapfile();
			List_Mh.push_back(x);
		}
		else if (Inhoa(tenloaiMh) == Inhoa("nuocngot"))
		{
			mathang* x = new Mathangnuocngot;
			x->Nhapfile();
			List_Mh.push_back(x);
		}
		else
		{
			mathang* x = new MatHangRong;
			x->Nhapfile();
			List_Mh.push_back(x);
		}
	}
	mathang::filein.close();
}
void loaimathang::XuatFile()
{
	if (Inhoa(tenloaiMh) == Inhoa("ThuocLa"))
	{
		mathang::fileout.open("thuocla.txt");
		for (int i = 0; i < List_Mh.size() - 1; i++)
		{
			List_Mh[i]->Xuatfile();
			mathang::fileout << "\n";
		}
		List_Mh[List_Mh.size() - 1]->Xuatfile();
		mathang::fileout.close();
	}
	else if (Inhoa(tenloaiMh) == Inhoa("bia"))
	{
		mathang::fileout.open("bia.txt");
		for (int i = 0; i < List_Mh.size() - 1; i++)
		{
			List_Mh[i]->Xuatfile();
			mathang::fileout << "\n";
		}
		List_Mh[List_Mh.size() - 1]->Xuatfile();
		mathang::fileout.close();
	}
	else if (Inhoa(tenloaiMh) == Inhoa("ruou"))
	{
		mathang::fileout.open("ruou.txt");
		for (int i = 0; i < List_Mh.size() - 1; i++)
		{
			List_Mh[i]->Xuatfile();
			mathang::fileout << "\n";
		}
		List_Mh[List_Mh.size() - 1]->Xuatfile();
		mathang::fileout.close();
	}
	else if (Inhoa(tenloaiMh) == Inhoa("nuocngot"))
	{
		mathang::fileout.open("nuocngot.txt");
		for (int i = 0; i < List_Mh.size() - 1; i++)
		{
			List_Mh[i]->Xuatfile();
			mathang::fileout << "\n";
		}
		List_Mh[List_Mh.size() - 1]->Xuatfile();
		mathang::fileout.close();
	}
	else
	{
		loaimathang::fileout.open("DanhSachLoaiMatHang.txt", ios_base::app);
		loaimathang::fileout << tenloaiMh << "\n";
		loaimathang::fileout.close();
		loaimathang::fileout.open("loaimathang.txt", ios_base::app);
		loaimathang::fileout << maloaiMh << setw(20) << tenloaiMh << "\n";
		loaimathang::fileout.close();
		string ten = tenloaiMh + ".txt";
		mathang::fileout.open(ten);
		for (int i = 0; i < List_Mh.size() - 1; i++)
		{
			List_Mh[i]->Xuatfile();
			mathang::fileout << "\n";
		}
		List_Mh[List_Mh.size() - 1]->Xuatfile();
		mathang::fileout.close();
	}
}
int loaimathang::NhapThemTuFile(ifstream& filein)
{
	filein >> maloaiMh;
	filein >> tenloaiMh;
	string tenfile = tenloaiMh + ".txt";
	mathang::filein.open(tenfile);
	if (!mathang::filein)
	{
		return -1;
	}
	while (!mathang::filein.eof())
	{
		mathang* x = new MatHangRong;
		x->Nhapfile();
		List_Mh.push_back(x);
	}
	mathang::filein.close();
}
void loaimathang::NhapThemMatHang()
{
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten cac mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t*     MENU     *\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Nhap Them\n";
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
		cout << "\n\n";
		string luachon;
		do {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; cin >> luachon;
			if (luachon != "1" && luachon != "0") cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
		} while (luachon != "1" && luachon != "0");
		int dem = 1; bool checktrung = true;
		if (luachon == "1")
		{
			mathang* x = new MatHangRong;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao thong tin mat hang thu " << dem++ << "\n"; x->Nhap();
			List_Mh.push_back(x); system("pause");
		}
		else break;
	}
}
void loaimathang::Xuat()
{
	SapXepMatHang();
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang: " << maloaiMh << "\n" << "\n\t\t\t\t\t\t\t\t\t\t\tten loai mat hang: " << tenloaiMh;
	cout << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen cac loai mat hang " << tenloaiMh << "\n\n\n";
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan" };
	for (int i = 0; i < List_Mh.size(); i++)
	{
		table += {List_Mh[i]->Get_mamh(), List_Mh[i]->Get_tenmh(), List_Mh[i]->Get_soluongmh(),
			List_Mh[i]->Get_DonGia(), List_Mh[i]->Get_NgaySanXuat(), List_Mh[i]->Get_NgayHetHan()};
	}
	table.setPadding(12);
	cout << table;
}
string loaimathang::Get_maloaiMh()
{
	return maloaiMh;
}
string loaimathang::Get_tenloaiMh()
{
	return tenloaiMh;
}
void loaimathang::Set_maloaiMh(string ma)
{
	maloaiMh = ma;
}
void loaimathang::Set_tenloaiMh(string ten)
{
	tenloaiMh = ten;
}
void loaimathang::SetNiCoTin(string a){}
void loaimathang::SetCalo(string a){}
void loaimathang::SetDoCon(string a){}
void loaimathang::SetDORuou(string a){}
void loaimathang::EraseMatHang(int vitri)
{
	List_Mh.erase(List_Mh.begin() + vitri);
}
int loaimathang::TimKiemMatHang(string tencantim)
{
	for (int i = 0; i < List_Mh.size(); i++)
	{
		if (Inhoa(List_Mh[i]->Get_tenmh()) == Inhoa(tencantim))
			return i;
	}
	return -1;
}
int loaimathang::GetSoLuongMatHang()
{
	return List_Mh.size();
}
mathang* loaimathang::operator[](int vitri)
{
	return List_Mh[vitri];
}
void loaimathang::InsertMatHang(int vitri, mathang* x)
{
	List_Mh.insert(List_Mh.begin() + vitri, x);
}
void loaimathang::SetMatHang(int vitrimathang, mathang* x)
{
	List_Mh[vitrimathang] = x;
}
void loaimathang::SapXepMatHang()
{
	Heapsort(List_Mh.size());
}
void loaimathang::Max_heapify(int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && stoi(List_Mh[left]->Get_DonGia()) > stoi(List_Mh[largest]->Get_DonGia()))
		largest = left;
	if (right < n && stoi(List_Mh[right]->Get_DonGia()) > stoi(List_Mh[largest]->Get_DonGia()))
		largest = right;
	if (largest != i)
	{
		swap(List_Mh[i], List_Mh[largest]);
		Max_heapify(n, largest);
	}
}
void loaimathang::Heapsort(int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Max_heapify(n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(List_Mh[0], List_Mh[i]);
		Max_heapify(i, 0);
	}
}
