#include "Bia.h"
void Bia::NhapFile()
{
	loaimathang::NhapFile();
	loaimathang::filein >> nongdocon;
}
void Bia::XuatFile()
{
	loaimathang::fileout.open("DanhSachLoaiMatHang.txt", ios_base::app);
	loaimathang::fileout << tenloaiMh << "\n";
	loaimathang::fileout.close();
	loaimathang::fileout.open("loaimathang.txt", ios_base::app);
	loaimathang::fileout << maloaiMh << setw(20) << tenloaiMh << setw(20) << nongdocon << "\n";
	loaimathang::fileout.close();
	loaimathang::XuatFile();
}
void Bia::Xuat()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang: " << maloaiMh << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen loai mat hang: " << tenloaiMh << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tNong do con trung binh: " << nongdocon << "\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen cac loai mat hang " << tenloaiMh << "\n\n\n";
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "DoCon"};
	for (int i = 0; i < List_Mh.size(); i++)
	{
		mathang* x = List_Mh[i];
		table += {x->Get_mamh(), x->Get_tenmh(), x->Get_soluongmh(), x->Get_DonGia(), x->Get_NgaySanXuat(), x->Get_NgayHetHan(), x->GetDoCon()};
	}
	table.setPadding(10);
	cout << table;
}
void Bia::SetDoCon(string a) { nongdocon = a; }