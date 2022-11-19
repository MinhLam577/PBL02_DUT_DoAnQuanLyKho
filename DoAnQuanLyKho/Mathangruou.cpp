#include "Mathangruou.h"
void Mathangruou::Nhapfile()
{
	mathang::Nhapfile();
	mathang::filein >> DoRuou;
}
void Mathangruou::Xuatfile()
{
	mathang::Xuatfile();
	mathang::fileout << "\t\t" << DoRuou;
}
void Mathangruou::Nhap()
{
	mathang::Nhap();
	bool check = true;
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao do ruou: ", DoRuou);
		check = mathang::CheckSoThuc(DoRuou);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo ruou khong hop le. Xin nhap lai\n";
	} while (check == false);
}
void Mathangruou::Xuat()
{
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "DoRuou" };
	table.setStyle(1);
	table += {maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan, DoRuou};
	table.setPadding(9);
	cout << table;
}
string Mathangruou::GetDoCon(){return "";}
string Mathangruou::GetCalories() { return ""; }
string Mathangruou::GetDoRuou(){return DoRuou;}
string Mathangruou::GetNiCoTin(){return "";}
void Mathangruou::SetNiCoTin(string a){}
void Mathangruou::SetDoCon(string a) {}
void Mathangruou::SetCalo(string a) {}
void Mathangruou::SetDoRuou(string a) { DoRuou = a; }
Mathangruou* Mathangruou::operator=(mathang* a)
{
	Mathangruou* k = new Mathangruou;
	k->maMh = a->Get_mamh();
	k->tenMh = a->Get_tenmh();
	k->soluongMh = a->Get_soluongmh();
	k->DonGia = a->Get_DonGia();
	k->NgaySanXuat = a->Get_NgaySanXuat();
	k->NgayHetHan = a->Get_NgayHetHan();
	k->DoRuou = a->GetDoRuou();
	return k;
}