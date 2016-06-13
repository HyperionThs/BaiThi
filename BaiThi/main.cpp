#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class SinhVien {
protected:
	int maSV;
	string hoTen;
	float diemTB;
public:
	void nhapThongTin();
	void xuatThongTin();
	virtual float tinhDiemTB(float diem1 ,float diem2,float diem3);
	SinhVien();
	SinhVien(int masv, string hoten);
	void setHoTen(string);
	void setMaSV(int);
	void setDiemTB(float);
	string getHoTen() { return hoTen; }
	int getMaSV() { return maSV; }
	int getDiemTB() { return diemTB; }
};
void SinhVien::setDiemTB(float diemtb) {
	diemTB = diemtb;
}
void SinhVien::setHoTen(string ten) {
	hoTen = ten;
}
void SinhVien::setMaSV(int masv) {
	maSV = masv;
}
SinhVien::SinhVien(int masv, string hoten) {
	maSV = masv;
	hoTen = hoten;
}
SinhVien::SinhVien() {
	maSV = 0;
	hoTen = " ";
}
 float SinhVien::tinhDiemTB(float diem1, float diem2, float diem3) {
	float kq;
	kq = (diem1 + diem2 + diem3) / 3;
	return kq;
}
void SinhVien::nhapThongTin() {
	cout << "Nhap ma sinh vien: ";
	cin >> maSV;
	cout << "Nhap ho ten sinh vien :";
	cin >> hoTen;
}
void SinhVien::xuatThongTin() {
	cout << "MASV :" << maSV << endl;
	cout << "HoTen : " << hoTen << endl;
}
class SinhVienNganhWeb :public SinhVien {
private:
	float diemHtml;
	float diemJava;
	float diemPhp;
public:
	SinhVienNganhWeb() { 
		diemHtml = 0;
		diemJava = 0;
		diemPhp = 0;
	};
	SinhVienNganhWeb(int masv, string hoten, float diemhtml, float diemjava, float diemphp) {
		SinhVien::SinhVien(masv, hoten);
			this->diemHtml = diemhtml;
			this->diemJava = diemjava;
			this->diemPhp = diemphp;
	}
	virtual float tinhDiemTB(float diem1, float diem2, float diem3) {
		float kq;
		kq = (diem1 + diem2 + diem3) / 3;
		return kq;
	}
	void nhapThongTin() {
		SinhVien::nhapThongTin();
		cout << "Nhap diem HTML : ";
		cin >> diemHtml;
		cout << "Nhap diem Java : ";
		cin >> diemJava;
		cout << "Nhap diem Php : ";
		cin >> diemPhp;
		diemTB = tinhDiemTB(diemHtml, diemJava, diemPhp);
	}
	
	void xuatThongTin() {
		SinhVien::xuatThongTin();
		cout << "Diem mon HTML: " << diemHtml << endl;
		cout << "Diem mon Java: " << diemJava << endl;
		cout << "Diem mon php: " << diemPhp << endl;
		cout << "Diem trung binh : " << diemTB << endl;
	}
};
SinhVienNganhWeb arrSV[100];
SinhVienNganhWeb ts;
int dem = 0;
void main() {
	int chon;
	while (true) {
		system("cls");
		cout << "\n                   ษออออออออออออออออออออออออออออออออออออออ";
		cout << "\n                   บ       Bai Kiem Tra                  บ";
		cout << "\n                   บอออออออออออออออออออออออออออออออออออออบ";
		cout << "\n                   บ  STT บ      Lenh                    บ";
		cout << "\n                   บ   1  บ Nhap Sinh Vien               บ";
		cout << "\n                   บ   2  บ Xem Tat Ca Sinh Vien         บ";
		cout << "\n                   บ   0  บ Thoat                        บ";
		cout << "\n                   ศอออออออออออออออออออออออออออออออออออออผ\n";
		cout << "\n\n Chon Chuong Trinh: "; cin >> chon;
		switch (chon) {
		case 1:
			arrSV[dem].nhapThongTin();
			dem++;
			system("pause");
			break;
		case 2:
			for (int i = 0; i < dem; i++) {
				arrSV[i].xuatThongTin();
			};
			system("pause");
			break;
		case 0:
			exit(1);
		default:
			cout << "Chuong Trinh Khong Co Chuc Nang Nay !" << endl; system("pause");
			break;
		}
	}
}