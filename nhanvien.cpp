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
        cout << "H? tên: ";
        getline(in, nv.hoTen);
        cout << "Nam sinh: ";
        in >> nv.namSinh;
        in.ignore();
        cout << "Gi?i tính: ";
        getline(in, nv.gioiTinh);
        cout << "Luong: ";
        in >> nv.luong;
        in.ignore();
        return in;
    }

    friend ostream& operator<<(ostream& out, const NhanVien& nv) {
        out << "H? tên: " << nv.hoTen << endl;
        out << "Nam sinh: " << nv.namSinh << endl;
        out << "Gi?i tính: " << nv.gioiTinh << endl;
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
        cout << "Ngôn ng? l?p trình: ";
        getline(in, ltv.ngonNguLapTrinh);
        return in;
    }

    friend ostream& operator<<(ostream& out, const LapTrinhVien& ltv) {
        out << static_cast<const NhanVien&>(ltv);
        out << "Ngôn ng? l?p trình: " << ltv.ngonNguLapTrinh << endl;
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
        cout << "Chuyên môn: ";
        getline(in, ktv.chuyenMon);
        return in;
    }

    friend ostream& operator<<(ostream& out, const KiemThuVien& ktv) {
        out << static_cast<const NhanVien&>(ktv);
        out << "Chuyên môn: " << ktv.chuyenMon << endl;
        return out;
    }
};

int main() {
    int n;
    vector<NhanVien*> danhSachNhanVien;

    cout << "Nh?p s? lu?ng nhân viên (0 < N < 10): ";
    cin >> n;

    if (n <= 0 || n >= 10) {
        cout << "S? lu?ng nhân viên không h?p l?." << endl;
        return 1;
    }

    cin.ignore();  // Lo?i b? ký t? th?a sau khi nh?p s? lu?ng

    for (int i = 0; i < n; i++) {
        cout << "Ch?n lo?i nhân viên (1: L?p trình viên, 2: Ki?m th? viên): ";
        int loaiNhanVien;
        cin >> loaiNhanVien;

        if (loaiNhanVien == 1) {
            LapTrinhVien* ltv = new LapTrinhVien();
            cin.ignore();  // Lo?i b? ký t? th?a sau khi ch?n lo?i
            cin >> *ltv;
            danhSachNhanVien.push_back(ltv);
        } else if (loaiNhanVien == 2) {
            KiemThuVien* ktv = new KiemThuVien();
            cin.ignore();  // Lo?i b? ký t? th?a sau khi ch?n lo?i
            cin >> *ktv;
            danhSachNhanVien.push_back(ktv);
        } else {
            cout << "Lo?i nhân viên không h?p l?." << endl;
            continue;
        }
    }

    cout << "Danh sách nhân viên:\n";
    for (NhanVien* nv : danhSachNhanVien) {
        if (dynamic_cast<LapTrinhVien*>(nv) != nullptr) {
            cout << "L?p trình viên:\n";
            cout << *(static_cast<LapTrinhVien*>(nv));
        } else if (dynamic_cast<KiemThuVien*>(nv) != nullptr) {
            cout << "Ki?m th? viên:\n";
            cout << *(static_cast<KiemThuVien*>(nv));
        } else {
            cout << "Nhân viên:\n";
            cout << *nv;
        }
        cout << "--------------------------------\n";
    }

    // Gi?i phóng b? nh? cho các d?i tu?ng nhân viên
    for (NhanVien* nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}

