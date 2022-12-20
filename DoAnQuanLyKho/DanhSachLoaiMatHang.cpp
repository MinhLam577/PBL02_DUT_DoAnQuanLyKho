#include "DanhSachLoaiMatHang.h"
ifstream DanhSachLoaiMatHang::filein;
ofstream DanhSachLoaiMatHang::fileout;
void DanhSachLoaiMatHang::NhapFile()
{
	vector<string> ten;
	filein.open("DanhSachLoaiMatHang.txt");
	while (!filein.eof())
	{
		string t; string t1 = "";
		filein >> t;
		if (t != t1)
		ten.push_back(t);
	}
	filein.close();
	loaimathang::filein.open("loaimathang.txt");
	for (int i = 0; i < ten.size(); i++)
	{
		string ten1 = ten[i];
		if (loaimathang::Inhoa(ten1) == loaimathang::Inhoa("bia"))
		{
			loaimathang* x = new Bia; x->NhapFile();
			list_lmh.InsertLast(new Node<loaimathang*>(x));
		}
		else if (loaimathang::Inhoa(ten1) == loaimathang::Inhoa("thuocla"))
		{
			loaimathang* x = new ThuocLa; x->NhapFile();
			list_lmh.InsertLast(new Node<loaimathang*>(x));
		}
		else if (loaimathang::Inhoa(ten1) == loaimathang::Inhoa("nuocngot"))
		{
			loaimathang* x = new NuocNgot; x->NhapFile();
			list_lmh.InsertLast(new Node<loaimathang*>(x));
		}
		else if (loaimathang::Inhoa(ten1) == loaimathang::Inhoa("ruou"))
		{
			loaimathang* x = new Ruou; x->NhapFile();
			list_lmh.InsertLast(new Node<loaimathang*>(x));
		}
		else if (ten1 == "") break;
		else
		{
			loaimathang* x = new loaimathang; x->NhapFile();
			list_lmh.InsertLast(new Node<loaimathang*>(x));
		}
	}
	loaimathang::filein.close();
}
void DanhSachLoaiMatHang::XuatFile()
{
	fileout.open("DanhSachLoaiMatHang.txt");
	fileout.clear();
	fileout.close();
	loaimathang::fileout.open("loaimathang.txt");
	loaimathang::fileout.clear();
	loaimathang::fileout.close();
	for (int i = 0; i < list_lmh.GetSoluong(); i++)
	{
		list_lmh[i]->XuatFile();
	}
}
void DanhSachLoaiMatHang::NhapThemTuFile()
{
	bool checktrung = false, check = true;
	string maloaiMh, tenloaiMh; 
	do {
		do {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap ma loai mat hang: "; cin >> maloaiMh;
			check = mathang::CheckName(maloaiMh);
			if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
		} while (check == false);
		checktrung = false;
		for (int i = 0; i < list_lmh.GetSoluong(); i++)
		{
			if (loaimathang::Inhoa(list_lmh[i]->Get_maloaiMh()) == loaimathang::Inhoa(maloaiMh))
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang da bi trung. Xin nhap lai\n";
				checktrung = true;
				break;
			}
		}
	} while (checktrung == true);
	do {
		mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang: ", tenloaiMh);
		if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
		check = mathang::CheckName(tenloaiMh);
	} while (check == false);
	loaimathang::fileout.open("LoaiMatHangOutPut.txt");
	loaimathang::fileout << maloaiMh << "\t\t" << tenloaiMh;
	loaimathang::fileout.close();
}
void DanhSachLoaiMatHang::Xuat()
{
	int cnt = 1;
	for (Node<loaimathang*>* p = list_lmh.GetHead(); p != nullptr; p = p->GetNext())
	{
		loaimathang* x = p->GetData();
		x->SapXepMatHang();
		p->SetData(x);
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t* Thong tin loai mat hang thu " << cnt++ << " *\n";
		p->GetData()->Xuat();
	}
}
void DanhSachLoaiMatHang::InsertLoaiMatHang(loaimathang* l)
{
	list_lmh.InsertLast(new Node<loaimathang*>(l));
}
void DanhSachLoaiMatHang::EraseLoaiMatHang(string ten)
{
	int cnt = 0;
	for (Node<loaimathang*>* p = list_lmh.GetHead(); p != nullptr; p = p->GetNext())
	{
		if (loaimathang::Inhoa(p->GetData()->Get_tenloaiMh()) == loaimathang::Inhoa(ten))
		{
			list_lmh.EraseElement(cnt);
			break;
		}
		cnt++;
	}
}
void DanhSachLoaiMatHang::SapXepLoaiMatHang()
{
	for (int i = 0; i < list_lmh.GetSoluong() - 1; i++)
	{
		for (int j = i + 1; j < list_lmh.GetSoluong(); j++)
		{
			if (loaimathang::Inhoa(list_lmh[i]->Get_tenloaiMh()) > loaimathang::Inhoa(list_lmh[j]->Get_tenloaiMh()))
			{
				list_lmh.SwapData(i, j);
			}
		}
	}
}
int DanhSachLoaiMatHang::binarySearchRecursive(int l, int r, string target)
{
	// RECURSIVE IMPLEMENTATION OF BINARY SEARCH
	int mid = (l + r) / 2;

	// base case 1 = checks if array is empty or not
	if (r - l < 0) {
		return -1;
	}
	// base case 2 = checks if array middle is the target value
	if (loaimathang::Inhoa(target) == loaimathang::Inhoa(list_lmh[mid]->Get_tenloaiMh())) {
		return mid;
	}
	// recursive case 1 = removes left array
	else if (loaimathang::Inhoa(target) >= loaimathang::Inhoa(list_lmh[mid]->Get_tenloaiMh())) {
		return binarySearchRecursive(mid + 1, r, target);
	}
	// recursive case 2 = removes right array
	else {
		return binarySearchRecursive(l, mid - 1, target);
	}
}
loaimathang* DanhSachLoaiMatHang::operator[](int vitri)
{
	Node<loaimathang*>* pos = list_lmh.GetHead();
	while (vitri--) pos = pos->GetNext();
	return pos->GetData();
}
int DanhSachLoaiMatHang::GetSoLuongLoaiMatHang()
{
	return list_lmh.GetSoluong();
}
int DanhSachLoaiMatHang::TimKiemMatHang(string tenmathang, int& vitriloaimathang)
{
	for (int i = 0; i < list_lmh.GetSoluong(); i++)
	{
		for (int j = 0; j < list_lmh[i]->GetSoLuongMatHang(); j++)
		{
			if (loaimathang::Inhoa(list_lmh[i]->operator[](j)->Get_tenmh()) == loaimathang::Inhoa(tenmathang))
			{
				vitriloaimathang = i;
				return j;
			}
		}
	}
	return -1;
}
void DanhSachLoaiMatHang::SetLoaiMatHang(int vitri, loaimathang* x)
{
	Node<loaimathang*>* pos = list_lmh.GetHead();
	int temp = vitri;
	while (temp--) pos = pos->GetNext();
	pos->SetData(x);
}
mathang* DanhSachLoaiMatHang::SetMatHang(int vitriloaimathang, int vitrimathang, string yeucau)
{
	int temp = vitriloaimathang;
	Node<loaimathang*>* pos = list_lmh.GetHead();
	while (temp--) pos = pos->GetNext();
	loaimathang* k = pos->GetData();
	system("cls");
	k->operator[](vitrimathang)->Xuat();
	string ma, ten, soluong, dongia, ngayhethan, ngaysanxuat; bool check1, check2 = true; mathang* t2 = new MatHangRong;
	Mathangthuocla* k1 = new Mathangthuocla; Mathangbia* k2 = new Mathangbia; Mathangnuocngot* k3 = new Mathangnuocngot;
	Mathangruou* k4 = new Mathangruou; int cnt = -1; 
	string nsx1 = k->operator[](vitrimathang)->Get_NgaySanXuat();
	int nsx = k->operator[](vitrimathang)->GetDay(nsx1), tsx = k->operator[](vitrimathang)->GetMonth(nsx1),
		namsx = k->operator[](vitrimathang)->GetYear(nsx1);
	if (yeucau == "1")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma mat hang can cat nhat: ", ma);
			check1 = mathang::CheckId(ma);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa mat hang khong hop le. Xin nhap lai\n";
			}
			else
			{
				for (int i = 0; i < k->GetSoLuongMatHang(); i++)
				{
					check2 = true;
					mathang* x = k->operator[](i);
					if (loaimathang::Inhoa(x->Get_mamh()) == loaimathang::Inhoa(ma))
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa mat hang da bi trung. Xin nhap lai\n";
						check2 = false;
						break;
					}
				}
			}
		} while (check1 == false || check2 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->Set_maMh(ma);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->Set_maMh(ma);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->Set_maMh(ma);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->Set_maMh(ma);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
		
	}
	else if (yeucau == "2")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang can cat nhat: ", ten);
			check1 = mathang::CheckName(ten);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen mat hang khong hop le. Xin nhap lai\n";
			}
			else
			{
				for (int i = 0; i < k->GetSoLuongMatHang(); i++)
				{
					check2 = true;
					mathang* x = k->operator[](i);
					if (loaimathang::Inhoa(x->Get_tenmh()) == loaimathang::Inhoa(ten))
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen mat hang da bi trung. Xin nhap lai\n";
						check2 = false;
						break;
					}
				}
			}
		} while (check1 == false || check2 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->Set_tenMh(ten);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->Set_tenMh(ten);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->Set_tenMh(ten);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->Set_tenMh(ten);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else if (yeucau == "3")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao so luong mat hang can cat nhat: ", soluong);
			check2 = true;
			check1 = mathang::CheckSoLuong(soluong);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong khong hop le. Xin nhap lai\n";
			}
			else if (stoi(soluong) < 0)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong >= 0. Xin nhap lai\n";
				check2 = false;
			}
		} while (check1 == false || check2 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->Set_soluongmh(stoi(soluong));
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->Set_soluongmh(stoi(soluong));
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->Set_soluongmh(stoi(soluong));
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->Set_soluongmh(stoi(soluong));
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else if (yeucau == "4")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao don gia mat hang can cat nhat: ", dongia);
			check2 = true;
			check1 = mathang::CheckSoLuong(dongia);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDon gia khong hop le. Xin nhap lai\n";
			}
			else if (stoi(dongia) < 0)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDon gia >= 0. Xin nhap lai\n";
				check2 = false;
			}
		} while (check1 == false || check2 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->SetDonGia(dongia);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->SetDonGia(dongia);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->SetDonGia(dongia);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->SetDonGia(dongia);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else if (yeucau == "5")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ngay san xuat mat hang can cat nhat: ", ngaysanxuat);
			check1 = mathang::CheckDateSanXuat(ngaysanxuat, nsx, tsx, namsx);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay san xuat khong hop le. Xin nhap lai\n";
			}
		} while (check1 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->SetNgaySanXuat(ngaysanxuat);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->SetNgaySanXuat(ngaysanxuat);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->SetNgaySanXuat(ngaysanxuat);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->SetNgaySanXuat(ngaysanxuat);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else if (yeucau == "6")
	{
		do {
			mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ngay het han mat hang can cat nhat: ", ngayhethan);
			check1 = mathang::CheckDateHetHan(ngayhethan, nsx, tsx, namsx);
			if (check1 == false)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay het han khong hop le. Xin nhap lai\n";
			}
		} while (check1 == false);
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->SetNgayHetHan(ngayhethan);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->SetNgayHetHan(ngayhethan);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->SetNgayHetHan(ngayhethan);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->SetNgayHetHan(ngayhethan);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else if (yeucau == "7")
	{
		if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
		{
			string nicotin;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao nicotin: ", nicotin);
				check1 = mathang::CheckSoThuc(nicotin);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tNicotin khong hop le. Xin nhap lai\n";
			} while (check1 = false);
			t2 = k->operator[](vitrimathang);
			k1 = k1->operator=(t2);
			t2->SetNiCoTin(nicotin);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k1;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
		{
			string docon;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao do con: ", docon);
				check1 = mathang::CheckSoThuc(docon);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo con khong hop le. Xin nhap lai\n";
			} while (check1 = false);
			t2 = k->operator[](vitrimathang);
			k2 = k2->operator=(t2);
			t2->SetDoCon(docon);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k2;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
		{
			string Calories;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao Calo: ", Calories);
				check1 = mathang::CheckSoThuc(Calories);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tCalo khong hop le. Xin nhap lai\n";
			} while (check1 = false);
			t2 = k->operator[](vitrimathang);
			k3 = k3->operator=(t2);
			t2->SetCalo(Calories);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k3;
		}
		else if (loaimathang::Inhoa(list_lmh[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
		{
			string doruou;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao do ruou: ", doruou);
				check1 = mathang::CheckSoThuc(doruou);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo ruou khong hop le. Xin nhap lai\n";
			} while (check1 = false);
			t2 = k->operator[](vitrimathang);
			k4 = k4->operator=(t2);
			t2->SetDoRuou(doruou);
			k->SetMatHang(vitrimathang, t2);
			pos->SetData(k);
			return k4;
		}
	}
	else return t2;
}
void DanhSachLoaiMatHang::SapXepMatHang(int i)
{
	Node<loaimathang*>* p = list_lmh.GetHead();
	while (i--) p = p->GetNext();
	loaimathang* x = p->GetData();
	x->SapXepMatHang();
	p->SetData(x);
}
void DanhSachLoaiMatHang::NhapThemMatHangMoiVaoKho(mathang* a, int vitriloaimathang , int& DONGIA2)
{
	int temp = vitriloaimathang;
	Node<loaimathang*>* p = list_lmh.GetHead();
	while (temp--) p = p->GetNext();
	loaimathang* x = p->GetData();
	x->InsertMatHang(list_lmh[vitriloaimathang]->GetSoLuongMatHang() - 1, a);
	DONGIA2 += stoi(a->Get_DonGia()) * stoi(a->Get_soluongmh());
	p->SetData(x);
}
mathang* DanhSachLoaiMatHang::NhapThemSoLuongMatHangDaCoSan(int vitriloaimathang, string tenmathang, int& DONGIA3)
{
	int t1 = vitriloaimathang;  Node<loaimathang*>* p1 = list_lmh.GetHead();
	string soluongcanthem; bool check = true; mathang* t; loaimathang* x = new loaimathang; 
	Mathangthuocla* k1 = new Mathangthuocla; Mathangbia* k2 = new Mathangbia; Mathangnuocngot* k3 = new Mathangnuocngot;
	Mathangruou* k4 = new Mathangruou; int cnt = -1;
	do
	{
		check = true;
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao so luong can nhap them: "; cin >> soluongcanthem;
		for (int i = 0; i < soluongcanthem.length(); i++)
		{
			if (soluongcanthem[i] < '0' || soluongcanthem[i] > '9')
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong khong hop le. Xin nhap lai\n";
				check = false;
				break;
			}
		}
		if (check == true && stoi(soluongcanthem) <= 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong khong hop le. Xin nhap lai\n";
		}
	} while (check == false || stoi(soluongcanthem) <= 0);
	while (t1--) p1 = p1->GetNext();
	x = p1->GetData();
	
	for (int i = 0; i < x->GetSoLuongMatHang(); i++)
	{
		if (loaimathang::Inhoa(x->operator[](i)->Get_tenmh()) == loaimathang::Inhoa(tenmathang))
		{
			t = x->operator[](i);
			if (loaimathang::Inhoa(x->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
			{
				k1 = k1->operator=(t); cnt = 1;
				int soluongbandau = stoi(t->Get_soluongmh());
				int soluongsauthem = soluongbandau + stoi(soluongcanthem);
				DONGIA3 += stoi(t->Get_DonGia()) * stoi(soluongcanthem);
				k1->Set_soluongmh(stoi(soluongcanthem));
				t->Set_soluongmh(soluongsauthem);
				x->SetMatHang(i, t);
				break;
			}
			else if (loaimathang::Inhoa(x->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
			{
				k2 = k2->operator=(t); cnt = 2;
				int soluongbandau = stoi(t->Get_soluongmh());
				int soluongsauthem = soluongbandau + stoi(soluongcanthem);
				DONGIA3 += stoi(t->Get_DonGia()) * stoi(soluongcanthem);
				k2->Set_soluongmh(stoi(soluongcanthem));
				t->Set_soluongmh(soluongsauthem);
				x->SetMatHang(i, t);
				break;
			}
			else if (loaimathang::Inhoa(x->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
			{
				k3 = k3->operator=(t); cnt = 3;
				int soluongbandau = stoi(t->Get_soluongmh());
				int soluongsauthem = soluongbandau + stoi(soluongcanthem);
				DONGIA3 += stoi(t->Get_DonGia()) * stoi(soluongcanthem);
				k3->Set_soluongmh(stoi(soluongcanthem));
				t->Set_soluongmh(soluongsauthem);
				x->SetMatHang(i, t);
				break;
			}
			else if (loaimathang::Inhoa(x->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
			{
				k4 = k4->operator=(t); cnt = 4;
				int soluongbandau = stoi(t->Get_soluongmh());
				int soluongsauthem = soluongbandau + stoi(soluongcanthem);
				DONGIA3 += stoi(t->Get_DonGia()) * stoi(soluongcanthem);
				k4->Set_soluongmh(stoi(soluongcanthem));
				t->Set_soluongmh(soluongsauthem);
				x->SetMatHang(i, t);
				break;
			}
		}
	}
	p1->SetData(x);
	if (cnt == 1) return k1;
	else if (cnt == 2) return k2;
	else if (cnt == 3) return k3;
	else return k4;
}
mathang* DanhSachLoaiMatHang::XuatKho(string tenmathang, int& DonGia1)
{
	string soluongcanxuat; int vitriloaimathang = -1; loaimathang* t = new loaimathang;
	mathang* x = new MatHangRong,* k = new MatHangRong; bool check = true; 
	Mathangthuocla* k1 = new Mathangthuocla; Mathangbia* k2 = new Mathangbia; Mathangnuocngot* k3 = new Mathangnuocngot;
	Mathangruou* k4 = new Mathangruou; int cnt = -1;
	do
	{
		check = true;
	checksoluongcanxuat:
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao so luong can xuat: "; cin >> soluongcanxuat;
		check = mathang::CheckSoLuong(soluongcanxuat);
		if (check == false)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong khong hop le. Xin nhap lai\n";
		}
		else if (stoi(soluongcanxuat) <= 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong can xuat >= 0. Xin nhap lai\n";
		}
	} while (check == false || stoi(soluongcanxuat) <= 0);
	for (int i = 0; i < list_lmh.GetSoluong(); i++)
	{
		for (int j = 0; j < list_lmh[i]->GetSoLuongMatHang(); j++)
		{
			if (loaimathang::Inhoa(list_lmh[i]->operator[](j)->Get_tenmh()) == loaimathang::Inhoa(tenmathang))
			{
				t = list_lmh[i];
				x = t->operator[](j);
				int soluongbandau = stoi(x->Get_soluongmh());
				if (stoi(soluongcanxuat) > soluongbandau)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tSo luong can xuat > luong hang trong kho. Xin nhap lai\n";
					goto checksoluongcanxuat;
				}
				if (loaimathang::Inhoa(t->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
				{
					k1 = k1->operator=(x); cnt = 1;
					int soluongconlai = soluongbandau - stoi(soluongcanxuat);
					int DONGIA = stoi(list_lmh[i]->operator[](j)->Get_DonGia());
					DonGia1 += DONGIA * stoi(soluongcanxuat);
					x->Set_soluongmh(soluongconlai);
					k1->Set_soluongmh(stoi(soluongcanxuat));
					if (soluongconlai == 0)
					{
						t->EraseMatHang(j);
					}
					else
					{
						t->SetMatHang(j, x);

					}
					vitriloaimathang = i;
					break;
				}
				else if (loaimathang::Inhoa(t->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
				{
					k2 = k2->operator=(x); cnt = 2;
					int soluongconlai = soluongbandau - stoi(soluongcanxuat);
					int DONGIA = stoi(list_lmh[i]->operator[](j)->Get_DonGia());
					DonGia1 += DONGIA * stoi(soluongcanxuat);
					x->Set_soluongmh(soluongconlai);
					k2->Set_soluongmh(stoi(soluongcanxuat));
					if (soluongconlai == 0)
					{
						t->EraseMatHang(j);
					}
					else
					{
						t->SetMatHang(j, x);

					}
					vitriloaimathang = i;
					break;
				}
				else if (loaimathang::Inhoa(t->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
				{
					k3 = k3->operator=(x); cnt = 3;
					int soluongconlai = soluongbandau - stoi(soluongcanxuat);
					int DONGIA = stoi(list_lmh[i]->operator[](j)->Get_DonGia());
					DonGia1 += DONGIA * stoi(soluongcanxuat);
					x->Set_soluongmh(soluongconlai);
					k3->Set_soluongmh(stoi(soluongcanxuat));
					if (soluongconlai == 0)
					{
						t->EraseMatHang(j);
					}
					else
					{
						t->SetMatHang(j, x);

					}
					vitriloaimathang = i;
					break;
				}
				else if (loaimathang::Inhoa(t->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
				{
					k4 = k4->operator=(x); cnt = 4;
					int soluongconlai = soluongbandau - stoi(soluongcanxuat);
					int DONGIA = stoi(list_lmh[i]->operator[](j)->Get_DonGia());
					DonGia1 += DONGIA * stoi(soluongcanxuat);
					x->Set_soluongmh(soluongconlai);
					k4->Set_soluongmh(stoi(soluongcanxuat));
					if (soluongconlai == 0)
					{
						t->EraseMatHang(j);
					}
					else
					{
						t->SetMatHang(j, x);

					}
					vitriloaimathang = i;
					break;
				}
			}
		}
	}
	if (vitriloaimathang != -1)
	{
		Node<loaimathang*>* p = list_lmh.GetHead();
		while (vitriloaimathang--) p = p->GetNext();
		p->SetData(t);
	}
	if (cnt == 1) return k1;
	else if (cnt == 2) return k2;
	else if (cnt == 3) return k3;
	else return k4;
}
void DanhSachLoaiMatHang::ThongKe(string yeucau, vector<int>& vitriloaimathanghethan, vector<string>& tenmathanhethang, int& demTK4)
{
	time_t now = time(0);
	tm* lm = localtime(&now);
	int namhientai = lm->tm_year + 1900;
	int ngayhientai = lm->tm_mday;
	int thanghientai = lm->tm_mon + 1;
	if (yeucau == "1")
	{
		vector<mathang*> mh; int cnt = 0; vector<mathang*> mh1;
		for (int i = 0; i < list_lmh.GetSoluong(); i++)
		{
			loaimathang* x = list_lmh[i];
			for (int j = 0; j < x->GetSoLuongMatHang(); j++)
			{
				string t = x->operator[](j)->Get_NgayHetHan();
				if (x->operator[](j)->GetYear(t) == namhientai)
				{
					if (x->operator[](j)->GetMonth(t) - thanghientai <= 1)
					{
						if(x->operator[](j)->GetDay(t) - ngayhientai > 7)
						mh.push_back(x->operator[](j));
					}
				}
			}
		}
		for (int i = 0; i < list_lmh.GetSoluong(); i++)
		{
			loaimathang* x = list_lmh[i];
			for (int j = 0; j < x->GetSoLuongMatHang(); j++)
			{
				string t = x->operator[](j)->Get_NgayHetHan();
				if (x->operator[](j)->GetYear(t) == namhientai)
				{
					if (x->operator[](j)->GetMonth(t) == thanghientai)
					{
						if(x->operator[](j)->GetDay(t) - ngayhientai <= 7)
						mh1.push_back(x->operator[](j));
					}
				}
			}
		}
		if (mh.size() != 0)
		{
			for (int i = 0; i < mh.size() - 1; i++)
			{
				for (int j = i + 1; j < mh.size(); j++)
				{
					if (stoi(mh[i]->Get_DonGia()) > stoi(mh[j]->Get_DonGia())) swap(mh[i], mh[j]);
				}
			}
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\tCac mat hang sap het han su dung(Han su dung duoi 1 thang, tren 1 tuan). Xin luu y\n\n";
			for (int i = 0; i < mh.size(); i++)
			{
				mh[i]->Xuat();
			}
		}
		if (mh1.size() != 0)
		{
			for (int i = 0; i < mh1.size() - 1; i++)
			{
				for (int j = i + 1; j < mh1.size(); j++)
				{
					if (stoi(mh1[i]->Get_DonGia()) > stoi(mh1[j]->Get_DonGia())) swap(mh1[i], mh1[j]);
				}
			}
			cout << "\n\t\t\t\t\t\t\t\t\tCac mat hang sap het han su dung(Han su dung duoi 1 tuan). Xin luu y\n\n";
			for (int i = 0; i < mh1.size(); i++)
			{
				mh1[i]->Xuat();
			}
		}
		if(mh1.size() == 0 && mh.size() == 0)
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tKhong co mat hang nao sap het han\n";
		}
		system("pause");
	}
	else if (yeucau == "2")
	{
		vector<mathang*> mh; vector<int> vitrimhhethan;
		for (int i = 0; i < list_lmh.GetSoluong(); i++)
		{
			loaimathang* x = list_lmh[i];
			for (int j = 0; j < x->GetSoLuongMatHang(); j++)
			{
				string t = x->operator[](j)->Get_NgayHetHan();
				if (x->operator[](j)->GetYear(t) < namhientai)
				{
					vitriloaimathanghethan.push_back(i);
					tenmathanhethang.push_back(x->operator[](j)->Get_tenmh());
					mh.push_back(x->operator[](j));
				}
				else if (x->operator[](j)->GetYear(t) == namhientai)
				{
					if (x->operator[](j)->GetMonth(t) < thanghientai)
					{
						vitriloaimathanghethan.push_back(i);
						tenmathanhethang.push_back(x->operator[](j)->Get_tenmh());
						mh.push_back(x->operator[](j));
					}
					else if (x->operator[](j)->GetMonth(t) == thanghientai)
					{
						if (x->operator[](j)->GetDay(t) <= ngayhientai)
						{
							vitriloaimathanghethan.push_back(i);
							tenmathanhethang.push_back(x->operator[](j)->Get_tenmh());
							mh.push_back(x->operator[](j));
						}
					}
				}
			}
		}
		if (mh.size() != 0)
		{
			for (int i = 0; i < mh.size() - 1; i++)
			{
				for (int j = i + 1; j < mh.size(); j++)
				{
					if (stoi(mh[i]->Get_DonGia()) > stoi(mh[j]->Get_DonGia())) swap(mh[i], mh[j]);
				}
			}
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang da het han su dung\n\n";
			for (int i = 0; i < mh.size(); i++)
			{
				mh[i]->Xuat();
			}
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tKhong co mat hang nao da het han\n";
		}
		system("pause");
	}
	else if (yeucau == "3")
	{
		vector<mathang*> mh; vector<int> vitri; vector<int> vitriloaimathang;
		for (int i = 0; i < list_lmh.GetSoluong(); i++)
		{
			loaimathang* x = list_lmh[i];
			for (int j = 0; j < x->GetSoLuongMatHang(); j++)
			{
				int soluong = stoi(x->operator[](j)->Get_soluongmh());
				if (soluong < 10)
				{
					mh.push_back(x->operator[](j));
					vitri.push_back(j);
					vitriloaimathang.push_back(i);
				}
			}
		}
		if (mh.size() != 0)
		{
			for (int i = 0; i < mh.size() - 1; i++)
			{
				for (int j = i + 1; j < mh.size(); j++)
				{
					if (stoi(mh[i]->Get_DonGia()) > stoi(mh[j]->Get_DonGia())) swap(mh[i], mh[j]);
				}
			}
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang sap het so luong(so luong duoi 10). Can nhap them\n\n";
			for (int i = 0; i < mh.size(); i++)
			{
				mh[i]->Xuat();
			}
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tKhong co mat hang nao sap het so luong\n";
		}
		system("pause");
	}
	else if (yeucau == "4")
	{
		if (vitriloaimathanghethan.size() != 0)
		{
			if (demTK4 == 0)
			{
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang ton kho\n\n\n";
				for (int i = 0; i < vitriloaimathanghethan.size(); i++)
				{
					int t = vitriloaimathanghethan[i];
					Node<loaimathang*>* p = list_lmh.GetHead();
					while (t--) p = p->GetNext();
					loaimathang* x = p->GetData();
					int vitrimathanghethan = x->TimKiemMatHang(tenmathanhethang[i]);
					x->EraseMatHang(vitrimathanghethan);
					p->SetData(x);
				}
				SapXepLoaiMatHang();
				Xuat();
				demTK4++;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang ton kho\n\n\n";
				Xuat();
				system("pause");
			}
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang ton kho\n\n\n";
			Xuat();
			system("pause");
		}
	}
}