#pragma once
#include "mathang.h"
class MatHangRong:public mathang
{
public:
	string GetNiCoTin();
	string GetDoCon();
	string GetDoRuou();
	string GetCalories();
	void SetNiCoTin(string);
	void SetDoCon(string);
	void SetCalo(string);
	void SetDoRuou(string);
};

