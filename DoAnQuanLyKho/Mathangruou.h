#pragma once
#include "mathang.h"
class Mathangruou:public mathang
{
private:
	string DoRuou;
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
	Mathangruou* operator=(mathang* a);
};

