#pragma once
#include "mathang.h"
class Mathangnuocngot:public mathang
{
private:
	string Calories;
public:
	void Nhapfile();
	void Xuatfile();
	void Nhap();
	void Xuat();
	string GetNiCoTin();
	string GetDoCon();
	string GetDoRuou();
	string GetCalories();
	void SetNiCoTin(string);
	void SetDoCon(string);
	void SetCalo(string);
	void SetDoRuou(string);
	Mathangnuocngot* operator=(mathang* a);
};

