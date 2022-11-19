#include "Mathangbia.h"
void Mathangbia::Nhapfile()
{
	mathang::Nhapfile();
	mathang::filein >> docon;
}
void Mathangbia::Xuatfile()
{
	mathang::Xuatfile();
	mathang::fileout << "\t\t" << docon;
}
void Mathangbia::Nhap()
{
	mathang::Nhap();
	bool check = true;
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao nong do con: ", docon);
		check = mathang::CheckSoThuc(docon);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo con khong hop le. Xin nhap lai\n";
	} while (check == false);
}
void Mathangbia::Xuat()
{
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "DoCon" };
	table.setStyle(1);
	table += {maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan, docon};
	table.setPadding(9);
	cout << table;
}
string Mathangbia::GetDoCon(){return docon;}
string Mathangbia::GetCalories(){return "";}
string Mathangbia::GetDoRuou(){return "";}
string Mathangbia::GetNiCoTin(){return "";}
void Mathangbia::SetNiCoTin(string a){}
void Mathangbia::SetDoCon(string a){ docon = a; }
void Mathangbia::SetCalo(string a){}
void Mathangbia::SetDoRuou(string a){}
Mathangbia* Mathangbia::operator=(mathang* a)
{
	Mathangbia* k = new Mathangbia;
	k->maMh = a->Get_mamh();
	k->tenMh = a->Get_tenmh();
	k->soluongMh = a->Get_soluongmh();
	k->DonGia = a->Get_DonGia();
	k->NgaySanXuat = a->Get_NgaySanXuat();
	k->NgayHetHan = a->Get_NgayHetHan();
	k->docon = a->GetDoCon();
	return k;
}