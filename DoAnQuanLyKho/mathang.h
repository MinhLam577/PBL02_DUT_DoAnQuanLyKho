#ifndef MATHANG_H
#define MATHANG_H
#include <fstream>
#pragma warning(disable : 4996)
#include <time.h>
#include "Consoletable.h"
#include <iomanip>
using namespace std;
class mathang
{
protected:
	string maMh, tenMh, soluongMh, DonGia, NgaySanXuat, NgayHetHan;
public:
	virtual void Nhapfile();
	virtual void Xuatfile();
	static ifstream filein;
	static ofstream fileout;
	static void NhapChuoi(string, string&);
	static bool CheckId(string);
	static bool CheckName(string);
	static bool CheckSoLuong(string);
	static bool CheckDayNum(int, int, int);
	static bool CheckDateSanXuat(string, int&, int&, int&);
	static bool CheckDateHetHan(string, int, int, int);
	static bool CheckDate(string);
	static bool CheckSoThuc(string);
	virtual void Xuat();
	virtual void Nhap();
	virtual string GetNiCoTin() = 0;
	virtual string GetDoCon() = 0;
	virtual string GetDoRuou() = 0;
	virtual string GetCalories() = 0;
	virtual void SetNiCoTin(string) = 0;
	virtual void SetDoCon(string) = 0;
	virtual void SetCalo(string) = 0;
	virtual void SetDoRuou(string) = 0;
	string Get_mamh();
	string Get_tenmh();
	string Get_soluongmh();
	string Get_DonGia();
	string Get_NgaySanXuat();
	string Get_NgayHetHan();
	int GetDay(string);
	int GetMonth(string);
	int GetYear(string);
	void Set_soluongmh(int);
	void Set_maMh(string);
	void Set_tenMh(string);
	void SetDonGia(string);
	void SetNgaySanXuat(string);
	void SetNgayHetHan(string);
	mathang*& operator=(mathang*&);
};
#endif