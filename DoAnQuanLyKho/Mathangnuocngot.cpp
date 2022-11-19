#include "Mathangnuocngot.h"
void Mathangnuocngot::Nhapfile()
{
	mathang::Nhapfile();
	mathang::filein >> Calories;
}
void Mathangnuocngot::Xuatfile()
{
	mathang::Xuatfile();
	mathang::fileout << "\t\t" << Calories;
}
void Mathangnuocngot::Nhap()
{
	mathang::Nhap();
	bool check = true;
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao calo: ", Calories);
		check = mathang::CheckSoThuc(Calories);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tCalo khong hop le. Xin nhap lai\n";
	} while (check == false);
}
void Mathangnuocngot::Xuat()
{
	ConsoleTable table{ "Id", "TenMatHang", "SoLuong", "DonGia" , "NgaySanXuat", "NgayHetHan", "Calo" };
	table.setStyle(1);
	table += {maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan, Calories};
	table.setPadding(9);
	cout << table;
}
string Mathangnuocngot::GetDoCon(){return "";}
string Mathangnuocngot::GetCalories(){return Calories;}
string Mathangnuocngot::GetDoRuou(){return "";}
string Mathangnuocngot::GetNiCoTin(){return "";}
void Mathangnuocngot::SetNiCoTin(string a){}
void Mathangnuocngot::SetDoCon(string a) {}
void Mathangnuocngot::SetCalo(string a) { Calories = a; }
void Mathangnuocngot::SetDoRuou(string a) {}
Mathangnuocngot* Mathangnuocngot::operator=(mathang* a)
{
	Mathangnuocngot* k = new Mathangnuocngot;
	k->maMh = a->Get_mamh();
	k->tenMh = a->Get_tenmh();
	k->soluongMh = a->Get_soluongmh();
	k->DonGia = a->Get_DonGia();
	k->NgaySanXuat = a->Get_NgaySanXuat();
	k->NgayHetHan = a->Get_NgayHetHan();
	k->Calories = a->GetCalories();
	return k;
}