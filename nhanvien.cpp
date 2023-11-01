#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien {
protected:
    string hoTen;
    int namSinh;
    string gioiTinh;
    double luong;

public:
    NhanVien() {}

    NhanVien(string ten, int ns, string gt, double l)
        : hoTen(ten), namSinh(ns), gioiTinh(gt), luong(l) {}

    friend istream& operator>>(istream& in, NhanVien& nv) {
        cout << "H? t�n: ";
        getline(in, nv.hoTen);
        cout << "Nam sinh: ";
        in >> nv.namSinh;
        in.ignore();
        cout << "Gi?i t�nh: ";
        getline(in, nv.gioiTinh);
        cout << "Luong: ";
        in >> nv.luong;
        in.ignore();
        return in;
    }

    friend ostream& operator<<(ostream& out, const NhanVien& nv) {
        out << "H? t�n: " << nv.hoTen << endl;
        out << "Nam sinh: " << nv.namSinh << endl;
        out << "Gi?i t�nh: " << nv.gioiTinh << endl;
        out << "Luong: " << nv.luong << endl;
        return out;
    }
};

class LapTrinhVien : public NhanVien {
private:
    string ngonNguLapTrinh;

public:
    LapTrinhVien() {}

    LapTrinhVien(string ten, int ns, string gt, double l, string ngonNgu)
        : NhanVien(ten, ns, gt, l), ngonNguLapTrinh(ngonNgu) {}

    friend istream& operator>>(istream& in, LapTrinhVien& ltv) {
        in >> static_cast<NhanVien&>(ltv);
        cout << "Ng�n ng? l?p tr�nh: ";
        getline(in, ltv.ngonNguLapTrinh);
        return in;
    }

    friend ostream& operator<<(ostream& out, const LapTrinhVien& ltv) {
        out << static_cast<const NhanVien&>(ltv);
        out << "Ng�n ng? l?p tr�nh: " << ltv.ngonNguLapTrinh << endl;
        return out;
    }
};

class KiemThuVien : public NhanVien {
private:
    string chuyenMon;

public:
    KiemThuVien() {}

    KiemThuVien(string ten, int ns, string gt, double l, string chuyenMon)
        : NhanVien(ten, ns, gt, l), chuyenMon(chuyenMon) {}

    friend istream& operator>>(istream& in, KiemThuVien& ktv) {
        in >> static_cast<NhanVien&>(ktv);
        cout << "Chuy�n m�n: ";
        getline(in, ktv.chuyenMon);
        return in;
    }

    friend ostream& operator<<(ostream& out, const KiemThuVien& ktv) {
        out << static_cast<const NhanVien&>(ktv);
        out << "Chuy�n m�n: " << ktv.chuyenMon << endl;
        return out;
    }
};

int main() {
    int n;
    vector<NhanVien*> danhSachNhanVien;

    cout << "Nh?p s? lu?ng nh�n vi�n (0 < N < 10): ";
    cin >> n;

    if (n <= 0 || n >= 10) {
        cout << "S? lu?ng nh�n vi�n kh�ng h?p l?." << endl;
        return 1;
    }

    cin.ignore();  // Lo?i b? k� t? th?a sau khi nh?p s? lu?ng

    for (int i = 0; i < n; i++) {
        cout << "Ch?n lo?i nh�n vi�n (1: L?p tr�nh vi�n, 2: Ki?m th? vi�n): ";
        int loaiNhanVien;
        cin >> loaiNhanVien;

        if (loaiNhanVien == 1) {
            LapTrinhVien* ltv = new LapTrinhVien();
            cin.ignore();  // Lo?i b? k� t? th?a sau khi ch?n lo?i
            cin >> *ltv;
            danhSachNhanVien.push_back(ltv);
        } else if (loaiNhanVien == 2) {
            KiemThuVien* ktv = new KiemThuVien();
            cin.ignore();  // Lo?i b? k� t? th?a sau khi ch?n lo?i
            cin >> *ktv;
            danhSachNhanVien.push_back(ktv);
        } else {
            cout << "Lo?i nh�n vi�n kh�ng h?p l?." << endl;
            continue;
        }
    }

    cout << "Danh s�ch nh�n vi�n:\n";
    for (NhanVien* nv : danhSachNhanVien) {
        if (dynamic_cast<LapTrinhVien*>(nv) != nullptr) {
            cout << "L?p tr�nh vi�n:\n";
            cout << *(static_cast<LapTrinhVien*>(nv));
        } else if (dynamic_cast<KiemThuVien*>(nv) != nullptr) {
            cout << "Ki?m th? vi�n:\n";
            cout << *(static_cast<KiemThuVien*>(nv));
        } else {
            cout << "Nh�n vi�n:\n";
            cout << *nv;
        }
        cout << "--------------------------------\n";
    }

    // Gi?i ph�ng b? nh? cho c�c d?i tu?ng nh�n vi�n
    for (NhanVien* nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}

