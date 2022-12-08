#include "DanhSachLoaiMatHang.h"
int main()
{
	DanhSachLoaiMatHang List;
	List.NhapFile();
	vector<string> NGAYNHAP; vector<string> NGAYXUAT; vector<string> MAHOADONXUAT; vector<string> MAHOADONNHAP;
	vector<int> vitriloaimathanghethan; vector<string> tenmathanghethan;

	vector<mathang*> lmh8; vector <int> VITRILOAIMATHANG1; vector<int> VITRILOAIMATHANG2; 
	vector<int> VITRIMATHANG2; int dongia1 = 0, dongia2 = 0; string mahoadon8; vector<loaimathang*> LMH;

	int dongia = 0; vector<int> VITRILOAIMATHANG; vector<int> VITRIMATHANG; vector<mathang*> lmh7; string mahoadon;

	time_t now = time(0);
	tm* lm = localtime(&now);
	int namhientai = lm->tm_year + 1900;
	int ngayhientai = lm->tm_mday;
	int thanghientai = lm->tm_mon + 1;
	string curdate = to_string(ngayhientai) + "/" + to_string(thanghientai) + "/" + to_string(namhientai);
	ifstream filein("Hoadonxuathang.txt");
	while (!filein.eof())
	{
		string ma, ngay;
		filein >> ma >> ngay;
		if (ma != "" && ngay != "")
		{
			NGAYXUAT.push_back(ngay);
			MAHOADONXUAT.push_back(ma);
		}
	}
	filein.close();
	filein.open("Hoadonnhaphang.txt");
	while (!filein.eof())
	{
		string ma, ngay;
		filein >> ma >> ngay;
		if (ma != "" && ngay != "")
		{
			NGAYNHAP.push_back(ngay);
			MAHOADONNHAP.push_back(ma);
		}
	}
	filein.close();
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t\t\t\t\t\t\t*    MENU    *\n";
		cout << "\n\t\t\t\t\t\t\t\t\t1. In danh sach cac loai mat hang co san\n";
		cout << "\n\t\t\t\t\t\t\t\t\t2. Xoa loai mat hang trong danh sach\n";
		cout << "\n\t\t\t\t\t\t\t\t\t3. Tim kiem thong tin loai mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t4. Cat nhat thong tin loai mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t5. Cat nhat thong tin mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t6. Tim kiem thong tin mat hang\n";
		cout << "\n\t\t\t\t\t\t\t\t\t7. Xuat mat hang trong kho\n";
		cout << "\n\t\t\t\t\t\t\t\t\t8. Nhap kho\n";
		cout << "\n\t\t\t\t\t\t\t\t\t9. Thong ke\n";
		cout << "\n\t\t\t\t\t\t\t\t\t0. Thoat(Luu ket qua vao file)\n";
		cout << "\n\n";
		cout << "\n\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; string luachon; cin >> luachon;
		if (luachon == "1")
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang\n\n\n";
			List.SapXepLoaiMatHang();
			List.Xuat();
			system("pause");
		}
		else if (luachon == "2")
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n"; List.Xuat();
			int vitri; string ten; bool check1 = true, check2 = true;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can xoa: ", ten);
				check1 = mathang::CheckName(ten);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai!\n";
				vitri = List.TimKiemLoaiMatHang(ten);
				if (vitri == -1 && check1 == true)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen loai mat hang can xoa khong ton tai. Xin nhap lai!\n";
					check2 = false;
				}
				else if (vitri != -1 && check1 == true) check2 = true;
			} while (check1 == false || check2 == false);
			List.EraseLoaiMatHang(ten); system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang sau khi xoa\n\n\n"; List.Xuat(); system("pause");
		}
		else if (luachon == "3")
		{
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n"; List.Xuat();
			string ten; int kq; bool check1 = true, check2 = true;
			do {

				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can tim: ", ten);
				check1 = mathang::CheckName(ten);
				if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai!\n";
				kq = List.TimKiemLoaiMatHang(ten);
				if (kq == -1 && check1 == true)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen loai mat hang can tim khong ton tai. Xin nhap lai!\n";
					check2 = false;
				}
				else if (kq != -1 && check1 == true) check2 = true;
			} while (check1 == false || check2 == false);
			system("cls"); cout << "\n\t\t\t\t\t\t\t\t\t\t\tThong tin loai mat hang can tim\n"; List[kq]->Xuat(); system("pause");
		}
		else if (luachon == "4")
		{
			system("cls");
			vector<int> VITRILOAIMATHANG;
			while (true)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n"; List.Xuat();
				bool check1 = true, check2 = true;  int vitriloaimathang;
				string tenloaimathang, tenmathang;
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can cat nhat: ", tenloaimathang);
					check1 = mathang::CheckName(tenloaimathang);
					if (check1 == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
					}
					vitriloaimathang = List.TimKiemLoaiMatHang(tenloaimathang);
					if (check1 == true && vitriloaimathang == -1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang khong co san. Xin nhap lai\n";
						check2 = false;
					}
					else if (check1 == true && vitriloaimathang != -1) check2 = true;
				} while (check1 == false || check2 == false);
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Cat nhat ma loai mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t2. Cat nhat thong tin rieng loai mat hang\n";
				string choice4; bool check; string s = "12", tieptuc; int i; char c; string ma; loaimathang* x = new loaimathang;
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: ", choice4);
					c = choice4[0];
					check = false;
					if (choice4.length() != 1)	check = false;
					else
					{
						for (i = 0; i < s.length(); i++)
						{
							if (s[i] == c)
							{
								check = true;
								break;
							}
						}
					}
					if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
				} while (check == false);
				if (choice4 == "1")
				{
					system("cls"); List[vitriloaimathang]->Xuat();
					do {
						mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma loai mat hang can cat nhat: ", ma);
						check1 = mathang::CheckId(ma);
						if (check1 == false)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang khong hop le. Xin nhap lai\n";
						}
						else
						{
							for (int i = 0; i < List.GetSoLuongLoaiMatHang(); i++)
							{
								check2 = true;
								if (loaimathang::Inhoa(List[i]->Get_maloaiMh()) == loaimathang::Inhoa(ma))
								{
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa loai mat hang da bi trung. Xin nhap lai\n";
									check2 = false;
									break;
								}
							}
						}
					} while (check1 == false || check2 == false);
					x = List[vitriloaimathang];
					system("cls");
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang ban dau\n\n"; x->Xuat();
					VITRILOAIMATHANG.push_back(vitriloaimathang);
					x->Set_maloaiMh(ma);
					List.SetLoaiMatHang(vitriloaimathang, x);
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang sau khi cat nhat\n\n"; x->Xuat();
				}
				if (choice4 == "2")
				{
					system("cls"); List[vitriloaimathang]->Xuat();
					x = List[vitriloaimathang];
					if (loaimathang::Inhoa(List[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
					{
						string nicotin;
						do {
							mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao nicotin: ", nicotin);
							check1 = mathang::CheckSoThuc(nicotin);
							if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tNicotin khong hop le. Xin nhap lai\n";
						} while (check1 = false);
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang ban dau\n\n"; x->Xuat();
						x->SetNiCoTin(nicotin);
					}
					else if (loaimathang::Inhoa(List[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
					{
						string docon;
						do {
							mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao do con: ", docon);
							check1 = mathang::CheckSoThuc(docon);
							if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo con khong hop le. Xin nhap lai\n";
						} while (check1 = false);
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang ban dau\n\n"; x->Xuat();
						x->SetDoCon(docon);
					}
					else if (loaimathang::Inhoa(List[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
					{
						string Calories;
						do {
							mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao Calo: ", Calories);
							check1 = mathang::CheckSoThuc(Calories);
							if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tCalo khong hop le. Xin nhap lai\n";
						} while (check1 = false);
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang ban dau\n\n"; x->Xuat();
						x->SetCalo(Calories);
					}
					else if (loaimathang::Inhoa(List[vitriloaimathang]->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
					{
						string doruou;
						do {
							mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao do ruou: ", doruou);
							check1 = mathang::CheckSoThuc(doruou);
							if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tDo ruou khong hop le. Xin nhap lai\n";
						} while (check1 = false);
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang ban dau\n\n"; x->Xuat();
						x->SetDORuou(doruou);
					}
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang sau khi cat nhat\n\n"; x->Xuat();
					VITRILOAIMATHANG.push_back(vitriloaimathang);
					List.SetLoaiMatHang(vitriloaimathang, x);
				}
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhan phim 0 de thoat chuong trinh hoac phim bat ky de tiep tuc chuong trinh: "; cin >> tieptuc;
				system("Cls");
				if (tieptuc == "0")
				{
					if (VITRILOAIMATHANG.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang da cat nhat\n\n\n";
						loaimathang* y = List[VITRILOAIMATHANG[0]]; y->Xuat();
						for (int i = 1; i < VITRILOAIMATHANG.size(); i++)
						{
							check2 = true;
							loaimathang* t = List[VITRILOAIMATHANG[i]];
							for (int j = i - 1; j >= 0; j--)
							{
								loaimathang* k = List[VITRILOAIMATHANG[j]];
								{
									if (loaimathang::Inhoa(t->Get_tenloaiMh()) == loaimathang::Inhoa(k->Get_tenloaiMh()))
									{
										check2 = false;
										break;
									}
								}
							}
							if (check2 == true)	t->Xuat();
						}
					}
					system("pause");
					break;
				}
			}
		}
		else if (luachon == "5")
		{
			system("cls");
			vector<mathang*> mh; vector<int> VITRILOAIMATHANG; vector<int> VITRIMATHANG;
			while (true)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n"; List.Xuat();
				bool check1 = true, check2 = true;  int vitriloaimathang, vitrimathang;
				string tenloaimathang, tenmathang;
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can cat nhat: ", tenloaimathang);
					check1 = mathang::CheckName(tenloaimathang);
					if (check1 == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
					}
					vitriloaimathang = List.TimKiemLoaiMatHang(tenloaimathang);
					if (check1 == true && vitriloaimathang == -1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang khong co san. Xin nhap lai\n";
						check2 = false;
					}
					else if (check1 == true && vitriloaimathang != -1) check2 = true;
				} while (check1 == false || check2 == false);
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang co san\n\n"; List[vitriloaimathang]->Xuat();
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang can cat nhat: ", tenmathang);
					check1 = mathang::CheckName(tenmathang);
					if (check1 == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
					}
					vitrimathang = List[vitriloaimathang]->TimKiemMatHang(tenmathang);
					if (check1 == true && vitrimathang == -1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tMat hang khong co san. Xin nhap lai\n";
						check2 = false;
					}
					else if (check1 == true && vitrimathang != -1) check2 = true;
				} while (check1 == false || check2 == false);
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Cat nhat ma mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t2. Cat nhat ten mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t3. Cat nhat so luong mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t4. Cat nhat don gia mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t5. Cat nhat ngay san suat mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t6. Cat nhat ngay het han mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t7. Cat nhat thong tin rieng cua mat hang\n";
				string choice4; bool check; string s = "1234567", tieptuc; int i; char c; mathang* x = new MatHangRong;
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: ", choice4);
					c = choice4[0];
					check = false;
					if (choice4.length() != 1)	check = false;
					else
					{
						for (i = 0; i < s.length(); i++)
						{
							if (s[i] == c)
							{
								check = true;
								break;
							}
						}
					}
					if (check == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
				} while (check == false);
				loaimathang* k = List[vitriloaimathang];
				x = List.SetMatHang(vitriloaimathang, vitrimathang, choice4);
				mh.push_back(x);
				VITRILOAIMATHANG.push_back(vitriloaimathang);
				VITRIMATHANG.push_back(vitrimathang);
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhan phim 0 de thoat chuong trinh hoac phim bat ky de tiep tuc chuong trinh: "; cin >> tieptuc;
				system("Cls");
				if (tieptuc == "0")
				{
					system("cls");
					if (mh.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac mat hang truoc khi cat nhat\n\n";
						for (int i = 0; i < mh.size(); i++) mh[i]->Xuat();
					}
					if (mh.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang sau khi cat nhat\n\n\n";
						mathang* y = List[VITRILOAIMATHANG[0]]->operator[](VITRIMATHANG[0]);
						y->Xuat();
						for (int i = 1; i < VITRILOAIMATHANG.size(); i++)
						{
							check2 = true;
							mathang* x = List[VITRILOAIMATHANG[i]]->operator[](VITRIMATHANG[i]);
							for (int j = i - 1; j >= 0; j--)
							{
								mathang* k = List[VITRILOAIMATHANG[j]]->operator[](VITRIMATHANG[j]);
								if (x->Get_tenmh() == k->Get_tenmh())
								{
									check2 = false;
									break;
								}
							}
							if (check2 == true)	x->Xuat();
						}
					}
					system("pause");
					break;
				}
			}
		}
		else if (luachon == "6")
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n"; List.Xuat();
			string ten; int vitriloaimathang; int vitrimathang; bool check1 = true, check2 = true;
			do {
				mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang can tim: ", ten);
				check1 = mathang::CheckName(ten);
				if (check1 == false)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
				}
				vitrimathang = List.TimKiemMatHang(ten, vitriloaimathang);
				if (vitrimathang == -1 && check1 == true)
				{
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen mat hang can tim khong ton tai. Xin nhap lai!\n";
					check2 = false;
				}
				else if (vitrimathang != -1 && check1 == true) check2 = true;
			} while (check1 == false || check2 == false);
			system("cls");
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tThong tin mat hang " << ten << "\n\n";
			List[vitriloaimathang]->operator[](vitrimathang)->Xuat();
			system("pause");
		}
		else if (luachon == "7")
		{
			system("cls");
			string choice; string tenmathang, tenloaimathang; bool check1 = true, check2 = true; int vitriloaimathang, vitrimathang;
			if (MAHOADONXUAT.size() == 0)
			{
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma hoa don khi xuat: ", mahoadon);
					check1 = mathang::CheckId(mahoadon);
					if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
				} while (check1 == false);
			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t* Lich su xuat hang *\n\n";
				ifstream filein("HoaDonXuatHang.txt"); string ma, ngay;
				while (!filein.eof())
				{
					filein >> ma >> ngay;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don xuat: " << ma << "\t\t" << "Ngay xuat: " << ngay << "\n";
				}
				filein.close();
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma hoa don khi xuat: ", mahoadon);
					check1 = mathang::CheckId(mahoadon);
					check2 = true;
					if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
					else
					{
						for (int i = 0; i < MAHOADONXUAT.size(); i++)
						{
							if (MAHOADONXUAT[i] == mahoadon)
							{
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don bi trung. Xin nhap lai\n";
								check2 = false;
								break;
							}
						}
					}
				} while (check1 == false || check2 == false);
			}
			while (true)
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang co san\n\n\n";
				List.Xuat();
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can xuat: ", tenloaimathang);
					check1 = mathang::CheckName(tenloaimathang);
					if (check1 == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
					}
					vitriloaimathang = List.TimKiemLoaiMatHang(tenloaimathang);
					if (check1 == true && vitriloaimathang == -1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang khong co san. Xin nhap lai\n";
						check2 = false;
					}
					else if (check1 == true && vitriloaimathang != -1) check2 = true;
				} while (check1 == false || check2 == false);
				do {
					system("cls");
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang co san\n\n"; List[vitriloaimathang]->Xuat();
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang can xuat: ", tenmathang);
					check1 = mathang::CheckName(tenmathang);
					if (check1 == false)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
						system("pause");
					}
					vitrimathang = List[vitriloaimathang]->TimKiemMatHang(tenmathang);
					if (check1 == true && vitrimathang == -1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tMat hang khong co san. Xin nhap lai\n";
						system("pause");
						check2 = false;
					}
					else if (check1 == true && vitrimathang != -1) check2 = true;
				} while (check1 == false || check2 == false);
				mathang* a = List.XuatKho(tenmathang, dongia);
				lmh7.push_back(a);
				VITRILOAIMATHANG.push_back(vitriloaimathang);
				VITRIMATHANG.push_back(vitrimathang);
				do {
					system("cls");
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Tiep tuc xuat\n";
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; cin >> choice;
					if (choice == "1")
					{
						break;
					}
					else if (choice == "0")
					{
						system("cls");
						if (lmh7.size() != 0)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac mat hang da xuat\n\n";
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don: " << mahoadon << "\n";
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay xuat: " << curdate << "\n";
							for (int i = 0; i < lmh7.size(); i++)
							{
								lmh7[i]->Xuat();
							}
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tien thu duoc khi xuat kho: " << dongia << "\n";
						}
						if (lmh7.size() != 0)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang con lai\n\n\n";
							mathang* x = List[VITRILOAIMATHANG[0]]->operator[](VITRIMATHANG[0]);
							x->Xuat();
							for (int i = 1; i < lmh7.size(); i++)
							{
								check1 = true;
								loaimathang* h = List[VITRILOAIMATHANG[i]];
								for (int j = i - 1; j >= 0; j--)
								{
									loaimathang* l = List[VITRILOAIMATHANG[j]];
									if (loaimathang::Inhoa(h->operator[](VITRIMATHANG[i])->Get_tenmh()) == loaimathang::Inhoa(l->operator[](VITRIMATHANG[j])->Get_tenmh()))
									{
										check1 = false;
										break;
									}
								}
								if (check1 == true)
								{
									x = List[VITRILOAIMATHANG[i]]->operator[](VITRIMATHANG[i]);
									x->Xuat();
								}
							}
						}
						ofstream fileout("hoadonxuathang.txt", ios_base::app);
						if (MAHOADONXUAT.size() == 0) fileout << mahoadon << setw(20) << curdate;
						else fileout << "\n" << mahoadon << setw(20) << curdate;
						fileout.close();
						string tenfile = "ChiTietHoaDonXuatMaHoaDon_" + mahoadon + ".txt";
						ofstream Fileout(tenfile);
						char Bang[][30] = { "Ma Hoa Don", "Ten Mat Hang Xuat", "So Luong Mat Hang", "Don Gia Mat Hang", "Ngay Xuat" };
						Fileout << Bang[0] << setw(30) << Bang[1] << setw(30) << Bang[2] << setw(30) << Bang[3] << setw(30) << Bang[4] << "\n";
						int m = strlen(Bang[0]), t = strlen(Bang[1]), s = strlen(Bang[2]), d = strlen(Bang[3]), nx = strlen(Bang[4]);
						for (int i = 0; i < lmh7.size() - 1; i++)
						{
							Fileout << "\n" << mahoadon << setw(m - mahoadon.length() + 30 - t + lmh7[i]->Get_tenmh().length()) << lmh7[i]->Get_tenmh()
								<< setw(t - lmh7[i]->Get_tenmh().length() + 30 - s + lmh7[i]->Get_soluongmh().length())
								<< lmh7[i]->Get_soluongmh() << setw(s - lmh7[i]->Get_soluongmh().length() + 30 - d + lmh7[i]->Get_DonGia().length()) << lmh7[i]->Get_DonGia()
								<< setw(d - lmh7[i]->Get_DonGia().length() + 30 - nx + curdate.length()) << curdate << "\n";
						}
						Fileout << "\n" << mahoadon << setw(m - mahoadon.length() + 30 - t + lmh7[lmh7.size() - 1]->Get_tenmh().length()) << lmh7[lmh7.size() - 1]->Get_tenmh()
							<< setw(t - lmh7[lmh7.size() - 1]->Get_tenmh().length() + 30 - s + lmh7[lmh7.size() - 1]->Get_soluongmh().length())
							<< lmh7[lmh7.size() - 1]->Get_soluongmh() << setw(s - lmh7[lmh7.size() - 1]->Get_soluongmh().length() + 30 - d + lmh7[lmh7.size() - 1]->Get_DonGia().length()) << lmh7[lmh7.size() - 1]->Get_DonGia()
							<< setw(d - lmh7[lmh7.size() - 1]->Get_DonGia().length() + 30 - nx + curdate.length()) << curdate;
						system("pause");
						break;
					}
					else
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
					}
				} while (choice != "1" && choice != "0");
				if (choice == "0") break;
			}
		}
		else if (luachon == "8")
		{
			string choice; bool check1 = true, check2 = true; string ngaynhap;
			system("cls");
			if (MAHOADONNHAP.size() == 0)
			{
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma hoa don khi nhap them: ", mahoadon8);
					check1 = mathang::CheckId(mahoadon8);
					if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
				} while (check1 == false);
			}
			else
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t* Lich su nhap hang *\n\n";
				ifstream filein("HoaDonNhapHang.txt"); string ma, ngay;
				while (!filein.eof())
				{
					filein >> ma >> ngay;
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don nhap: " << ma << "\t\t" << "Ngay nhap: " << ngay << "\n";
				}
				filein.close();
				do {
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ma hoa don khi nhap them: ", mahoadon8);
					check1 = mathang::CheckId(mahoadon8);
					check2 = true;
					if (check1 == false) cout << "\n\t\t\t\t\t\t\t\t\t\t\tId khong hop le. Xin nhap lai\n";
					else
					{
						for (int i = 0; i < MAHOADONNHAP.size(); i++)
						{
							if (MAHOADONNHAP[i] == mahoadon8)
							{
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don bi trung. Xin nhap lai\n";
								check2 = false;
								break;
							}
						}
					}
				} while (check1 == false || check2 == false);
			}
			while (true)
			{
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Nhap them loai mat hang moi\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t2. Nhap them mat hang\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
				cout << "\n\n";
				do {
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; cin >> choice;
					if (choice != "0" && choice != "1" && choice != "2")
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
					}
				} while (choice != "0" && choice != "1" && choice != "2");
				if (choice == "1")
				{
					system("cls");
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n";
					List.Xuat();
				Check:
					loaimathang* l = new loaimathang; int t, vitri; List.NhapThemTuFile();  ifstream filein("LoaiMatHangOutPut.txt");
					t = l->NhapThemTuFile(filein);
					if (t == -1)
					{
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tKhong tim thay ten file loai mat hang. Xin kiem tra lai\n";
						system("pause");
					}
					else
					{
						vitri = List.TimKiemLoaiMatHang(l->Get_tenloaiMh());
						if (vitri != -1)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoai mat hang vua them da co san. Xin nhap lai\n";
							goto Check;
						}
						else
						{
							List.InsertLoaiMatHang(l);
							LMH.push_back(l);
							system("cls");
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang sau khi them\n\n\n";
							List.Xuat();
							system("pause");
						}
					}
				}
				else if (choice == "2")
				{
					string choice2;
					while (true)
					{
						system("cls");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Nhap them mat hang moi\n";
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t2. Nhap them so luong mat hang co san\n";
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
						do {
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: "; cin >> choice2;
							if (choice2 == "1")
							{
								system("cls");
								string tenmathang, tenloaimathang, choose1; int vitriloaimathang, vitrimathang; mathang* x = new Mathangthuocla;
								bool check1 = true, check2 = true;
								do {
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang co san\n\n\n";
									List.Xuat();
									mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap ten loai mat hang can nhap them: ", tenloaimathang);
									check1 = mathang::CheckName(tenloaimathang);
									if (check1 == false)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
									}
									vitriloaimathang = List.TimKiemLoaiMatHang(tenloaimathang);
									if (check1 == true && vitriloaimathang == -1)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang khong co san. Xin nhap lai\n";
										check2 = false;
									}
									else if (check1 == true && vitriloaimathang != -1) check2 = true;
								} while (check1 == false || check2 == false);
								do {
									system("cls");
									loaimathang* k = List[vitriloaimathang];
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang co san\n\n"; k->Xuat();
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tNhap vao thong tin mat hang moi can nhap them\n";
									if (loaimathang::Inhoa(k->Get_tenloaiMh()) == loaimathang::Inhoa("thuocla"))
									{
										x = new Mathangthuocla; x->Nhap();
									}
									else if (loaimathang::Inhoa(k->Get_tenloaiMh()) == loaimathang::Inhoa("bia"))
									{
										x = new Mathangbia; x->Nhap();
									}
									else if (loaimathang::Inhoa(k->Get_tenloaiMh()) == loaimathang::Inhoa("ruou"))
									{
										x = new Mathangruou; x->Nhap();
									}
									else if (loaimathang::Inhoa(k->Get_tenloaiMh()) == loaimathang::Inhoa("nuocngot"))
									{
										x = new Mathangnuocngot; x->Nhap();
									}
									for (int i = 0; i < List[vitriloaimathang]->GetSoLuongMatHang(); i++)
									{
										check1 = true;
										check2 = true;
										loaimathang* y = List[vitriloaimathang];
										if (loaimathang::Inhoa(x->Get_tenmh()) == loaimathang::Inhoa(y->operator[](i)->Get_tenmh()))
										{
											check1 = false;
											break;
										}
										if (loaimathang::Inhoa(x->Get_mamh()) == loaimathang::Inhoa(y->operator[](i)->Get_mamh()))
										{
											check2 = false;
											break;
										}
									}
									if (check1 == false)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen mat hang da bi trung. Xin nhap lai\n";
									}
									else if (check2 == false)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa mat hang da bi trung. Xin nhap lai\n";
									}
									else
									{
										List.NhapThemMatHangMoiVaoKho(x, vitriloaimathang, dongia1);
										lmh8.push_back(x);
										VITRILOAIMATHANG1.push_back(vitriloaimathang);
										
									}
									system("pause");
								} while (check1 == false || check2 == false);
							}
							else if (choice2 == "2")
							{
								system("cls");
								string tenloaimathang, tenmathang; bool check1 = true, check2 = true; int vitrimathang, vitriloaimathang;
								string choose2; mathang* x = new MatHangRong;
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac loai mat hang co san\n\n\n";
								List.Xuat();
								do {
									mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten loai mat hang can nhap them: ", tenloaimathang);
									check1 = mathang::CheckName(tenloaimathang);
									if (check1 == false)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
									}
									vitriloaimathang = List.TimKiemLoaiMatHang(tenloaimathang);
									if (check1 == true && vitriloaimathang == -1)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang khong co san. Xin nhap lai\n";
										check2 = false;
									}
									else if (check1 == true && vitriloaimathang != -1) check2 = true;
								} while (check1 == false || check2 == false);
								system("cls");
								cout << "\n\t\t\t\t\t\t\t\t\t\t\tCac mat hang co san\n\n"; List[vitriloaimathang]->Xuat();
								do {
									mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao ten mat hang can nhap them: ", tenmathang);
									check1 = mathang::CheckName(tenmathang);
									if (check1 == false)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tTen khong hop le. Xin nhap lai\n";
									}
									vitrimathang = List[vitriloaimathang]->TimKiemMatHang(tenmathang);
									if (check1 == true && vitrimathang == -1)
									{
										cout << "\n\t\t\t\t\t\t\t\t\t\t\tMat hang khong co san. Xin nhap lai\n";
										check2 = false;
									}
									else if (check1 == true && vitrimathang != -1) check2 = true;
								} while (check1 == false || check2 == false);
								x = List.NhapThemSoLuongMatHangDaCoSan(vitriloaimathang, tenmathang, dongia2);
								lmh8.push_back(x);
								VITRILOAIMATHANG2.push_back(vitriloaimathang);
								VITRIMATHANG2.push_back(vitrimathang);
							}
							else if (choice2 == "0")
							{
								system("cls");
								int dem1 = 0;
								if (lmh8.size() != 0)
								{
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don: " << mahoadon8 << "\n";
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay nhap hang: " << curdate << "\n";
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tat ca cac mat hang da nhap them\n\n";
									for (int i = 0; i < lmh8.size(); i++)
									{
										lmh8[i]->Xuat();
									}
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tien phai tra: " << dongia1 + dongia2 << "\n";
								}
								if (VITRILOAIMATHANG1.size() != 0)
								{
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach loai mat hang sau khi nhap them mat hang moi\n\n";
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang thu " << 1 << "\n\n";
									List[VITRILOAIMATHANG1[0]]->Xuat();
									for (int i = 1; i < VITRILOAIMATHANG1.size(); i++)
									{
										bool check1 = true;
										for (int j = i - 1; j >= 0; j--)
										{
											if (List[VITRILOAIMATHANG1[i]]->Get_tenloaiMh() == List[VITRILOAIMATHANG1[j]]->Get_tenloaiMh())
											{
												check1 = false;
												break;
											}
										}
										if (check1 == true)
										{
											cout << "\n\t\t\t\t\t\t\t\t\t\t\tloai mat hang thu " << dem1++ << "\n\n";
											List[VITRILOAIMATHANG1[i]]->Xuat();
										}
									}
								}
								if (VITRILOAIMATHANG2.size() != 0)
								{
									cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac mat hang co san sau khi nhap them so luong\n\n";
									mathang* x = List[VITRILOAIMATHANG2[0]]->operator[](VITRIMATHANG2[0]);
									x->Xuat();
									for (int i = 1; i < VITRILOAIMATHANG2.size(); i++)
									{
										bool check1 = true;
										loaimathang* h = List[VITRILOAIMATHANG2[i]];
										for (int j = i - 1; j >= 0; j--)
										{
											loaimathang* l = List[VITRILOAIMATHANG2[j]];
											if (loaimathang::Inhoa(h->operator[](VITRIMATHANG2[i])->Get_tenmh()) == loaimathang::Inhoa(l->operator[](VITRIMATHANG2[j])->Get_tenmh()))
											{
												check1 = false;
												break;
											}
										}
										if (check1 == true)
										{
											x = List[VITRILOAIMATHANG2[i]]->operator[](VITRIMATHANG2[i]);
											x->Xuat();
										}
									}
								}
								system("pause");
								break;
							}
							else cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
						} while (choice2 != "0" && choice2 != "1" && choice2 != "2");
						if (choice2 == "0") break;
					}
				}
				else
				{
					if (lmh8.size() == 0 && LMH.size() == 0) break;
					ofstream fileout("hoadonnhaphang.txt", ios_base::app);
					if (MAHOADONNHAP.size() == 0) fileout << mahoadon8 << setw(20) << curdate;
					else fileout << "\n" << mahoadon8 << setw(20) << curdate;
					fileout.close();
					string tenfile = "ChiTietHoaDonNhapMaHoaDon_" + mahoadon8 + ".txt";
					ofstream Fileout(tenfile);
					if (lmh8.size() != 0)
					{
						char Bang[][30] = { "Ma Hoa Don", "Ten Mat Hang Nhap", "So Luong Mat Hang", "Don Gia Mat Hang", "Ngay Nhap" };
						Fileout << Bang[0] << setw(30) << Bang[1] << setw(30) << Bang[2] << setw(30) << Bang[3] << setw(30) << Bang[4] << "\n";
						int m = strlen(Bang[0]), t = strlen(Bang[1]), s = strlen(Bang[2]), d = strlen(Bang[3]), nx = strlen(Bang[4]);
						for (int i = 0; i < lmh8.size() - 1; i++)
						{
							Fileout << "\n" << mahoadon8 << setw(m - mahoadon8.length() + 30 - t + lmh8[i]->Get_tenmh().length()) << lmh8[i]->Get_tenmh()
								<< setw(t - lmh8[i]->Get_tenmh().length() + 30 - s + lmh8[i]->Get_soluongmh().length())
								<< lmh8[i]->Get_soluongmh() << setw(s - lmh8[i]->Get_soluongmh().length() + 30 - d + lmh8[i]->Get_DonGia().length()) << lmh8[i]->Get_DonGia()
								<< setw(d - lmh8[i]->Get_DonGia().length() + 30 - nx + curdate.length()) << curdate << "\n";
						}
						Fileout << "\n" << mahoadon8 << setw(m - mahoadon8.length() + 30 - t + lmh8[lmh8.size() - 1]->Get_tenmh().length()) << lmh8[lmh8.size() - 1]->Get_tenmh()
							<< setw(t - lmh8[lmh8.size() - 1]->Get_tenmh().length() + 30 - s + lmh8[lmh8.size() - 1]->Get_soluongmh().length())
							<< lmh8[lmh8.size() - 1]->Get_soluongmh() << setw(s - lmh8[lmh8.size() - 1]->Get_soluongmh().length() + 30 - d + lmh8[lmh8.size() - 1]->Get_DonGia().length()) << lmh8[lmh8.size() - 1]->Get_DonGia()
							<< setw(d - lmh8[lmh8.size() - 1]->Get_DonGia().length() + 30 - nx + curdate.length()) << curdate << "\n\n";
					}
					char Bang2[][30] = { "Ten Loai Mat Hang Nhap" };
					Fileout << Bang2[0] << "\n";
					for (int i = 0; i < LMH.size(); i++)
					{
						Fileout << LMH[i]->Get_tenloaiMh() << "\n";
					}
					Fileout.close();
					break;
				}
			}
		}
		else if (luachon == "9")
		{
			int demTK4 = 0;
			while (true)
			{
				system("cls");
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t1. Mat hang sap het han su dung\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t2. Mat hang da het han su dung\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t3. Mat hang sap het so luong\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t4. Cac mat hang ton kho\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t5. Tong cac mat hang da nhap kho\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t6. Tong cac mat hang da xuat kho\n";
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t0. Thoat\n";
				string choice4; string s = "1234560"; char c; bool check = true;
				do
				{
					check = false;
					mathang::NhapChuoi("\n\t\t\t\t\t\t\t\t\t\t\tNhap vao lua chon: ", choice4);
					c = choice4[0];
					if (choice4.length() != 1)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
						check = false;
					}
					else
					{
						for (int i = 0; i < s.length(); i++)
						{
							if (c == s[i])
							{
								check = true;
								break;
							}
						}
						if (check == false)
						{
							cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
						}
					}
				} while (check == false);
				if (choice4 != "0" && choice4 != "5" && choice4 != "6") List.ThongKe(choice4, vitriloaimathanghethan, tenmathanghethan, demTK4);
				else if (choice4 != "0" && choice4 == "5")
				{
					system("cls");
					if (LMH.size() == 0 && lmh8.size() == 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tChua co hang nao duoc nhap ve\n";
						system("pause");
						continue;
					}
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don: " << mahoadon8 << "\n";
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay nhap hang: " << curdate << "\n";
					
					if (lmh8.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tat ca cac mat hang da nhap them\n\n";
						for (int i = 0; i < lmh8.size(); i++)
						{
							lmh8[i]->Xuat();
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tien phai tra: " << dongia1 + dongia2 << "\n";
					}
					if (LMH.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tat ca loai mat hang da nhap them\n\n";
						for (int i = 0; i < LMH.size(); i++)
						{
							LMH[i]->Xuat();
						}
					}
					system("pause");
				}
				else if (choice4 != "0" && choice4 == "6")
				{
					system("cls");
					if (lmh7.size() == 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tChua co mat hang nao duoc xuat ra\n\n";
						system("pause");
						continue;
					}
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tMa hoa don: " << mahoadon << "\n";
					cout << "\n\t\t\t\t\t\t\t\t\t\t\tNgay xuat: " << curdate << "\n";
					if (lmh7.size() != 0)
					{
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tDanh sach cac mat hang da xuat\n\n";
						for (int i = 0; i < lmh7.size(); i++)
						{
							lmh7[i]->Xuat();
						}
						cout << "\n\t\t\t\t\t\t\t\t\t\t\tTong tien thu duoc khi xuat kho: " << dongia << "\n";
					}
					system("pause");
				}
				else if(choice4 == "0") break;
			}
		}
		else if (luachon == "0")
		{
			List.XuatFile();
			break;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tLua chon khong hop le. Xin nhap lai\n";
			system("pause");
		}
	}
	return 0;
}