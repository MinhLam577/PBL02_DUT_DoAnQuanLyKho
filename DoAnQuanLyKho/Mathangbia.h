#pragma once
#include "mathang.h"
class Mathangbia :public mathang
{
private:
	string docon;
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
	Mathangbia* operator=(mathang* a);
};
