#include <bits/stdc++.h>
#include <string>
using namespace std;

class Hangxe {
private:
    string MaHX, TenHX, Country;
    int Date;

public:
    Hangxe() {}

    Hangxe(string ma, string ten, string nuoc, int nam) {
        MaHX = ma;
        TenHX = ten;
        Country = nuoc;
        Date = nam;
    }

    string getMaHX() const {
        return MaHX;
    }

    void setMaHX(string ma) {
        MaHX = ma;
    }

    string getTenHX() const {
        return TenHX;
    }

    void setTenHX(string ten) {
        TenHX = ten;
    }

    string getCountry() const {
        return Country;
    }

    void setCountry(string nuoc) {
        Country = nuoc;
    }

    int getDate() const {
        return Date;
    }

    void setDate(int nam) {
        Date = nam;
    }

    void nhap() {
        cin >> MaHX;
        cin.ignore();
        getline(cin, TenHX);
        cin >> Country;
        cin >> Date;
    }

    void xuat() const {
        cout << MaHX << endl;
        cout << TenHX << endl;
        cout << Country << endl;
        cout << Date << endl;
    }
};

class Oto {
private:
    string MaXe, TenXe, HangXe;
    int NamSanXuat;
    long long GiaNiemYet;
    string MauXe;

public:
    Oto() {}

    Oto(string ma, string ten, string hang, int nam, double gia, string mau) {
        MaXe = ma;
        TenXe = ten;
        HangXe = hang;
        NamSanXuat = nam;
        GiaNiemYet = gia;
        MauXe = mau;
    }

    string getMaXe() const {
        return MaXe;
    }

    void setMaXe(string ma) {
        MaXe = ma;
    }

    string getTenXe() const {
        return TenXe;
    }

    void setTenXe(string ten) {
        TenXe = ten;
    }

    string getHangXe() const {
        return HangXe;
    }

    void setHangXe(string hang) {
        HangXe = hang;
    }

    int getNamSanXuat() const {
        return NamSanXuat;
    }

    void setNamSanXuat(int nam) {
        NamSanXuat = nam;
    }

    long long getGiaNiemYet() const {
        return GiaNiemYet;
    }

    void setGiaNiemYet(long long gia) {
        GiaNiemYet = gia;
    }

    string getMauXe() const {
        return MauXe;
    }

    void setMauXe(string mau) {
        MauXe = mau;
    }

    long long tinhGiaLanBanh() const {
        long long phiDangKy = 0.072 * GiaNiemYet + 500000 + 340000 + 480000 + 2160000;
        return GiaNiemYet + phiDangKy;
    }

    void nhap(const vector<Hangxe>& danhSachHangXe) {
        cin >> MaXe;
        cin.ignore();
        getline(cin, TenXe);
        cin >> NamSanXuat;
		nhapHangXe(danhSachHangXe);
        cin >> GiaNiemYet;
        cin.ignore();
        getline(cin, MauXe);
    }

    void nhapHangXe(const vector<Hangxe>& danhSachHangXe) {
        int indexHangXe;
        cin >> indexHangXe;

        if (indexHangXe >= 0 && indexHangXe < danhSachHangXe.size()) {
            HangXe = danhSachHangXe[indexHangXe].getTenHX();
        }
    }

    void xuat() const {cout <<MaXe<<"-"<<TenXe<<"-"<< HangXe <<"-"<<NamSanXuat <<"-"<<GiaNiemYet<<"-"<<MauXe<<endl;
    }
};

bool soSanhTheoGiaLanBanh(const Oto& a, const Oto& b) {
    return a.tinhGiaLanBanh() < b.tinhGiaLanBanh();
}

int main() {
    int soLuongHangXe, soLuongOto;
    cin >> soLuongHangXe;
	cin.ignore();
    vector<Hangxe> danhSachHangXe;

    for (int i = 0; i < soLuongHangXe; i++) {
        Hangxe hangXe;
        hangXe.nhap();
        danhSachHangXe.push_back(hangXe);
    }
    cin >> soLuongOto;
    vector<Oto> danhSachOto;

    for (int i = 0; i < soLuongOto; i++) {
        Oto xe;
        xe.nhap(danhSachHangXe);
        danhSachOto.push_back(xe);
    }
    string maHangXe;
    getline(cin,maHangXe);
	string Hangx;
    for (int i = 0; i < danhSachHangXe.size(); i++) {
        if (danhSachHangXe[i].getMaHX() == maHangXe) {
        	Hangx = danhSachHangXe[i].getTenHX();
        }
}
    for (int i = 0; i < danhSachOto.size(); i++) {
    	
        if (Hangx == danhSachOto[i].getHangXe()) {
            danhSachOto[i].xuat();
        }
    }
	cout<<endl<<"==="<<endl;
    	for (int i = 0; i < soLuongOto; i++) {
        for (int j = i + 1; j < soLuongOto; j++) {
            if (soSanhTheoGiaLanBanh(danhSachOto[i], danhSachOto[j])) {
                swap(danhSachOto[i], danhSachOto[j]);
            }
        }
    }
    for (int i = 0; i < danhSachOto.size(); i++) {
        danhSachOto[i].xuat();
   }
    return 0;
}
