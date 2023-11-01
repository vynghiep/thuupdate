#include <bits/stdc++.h>
	using namespace std;
	class Hangxe {
	private:
	    string Mhx, tenhang, nuoc;
	    int nam;
	
	public:
	    Hangxe() {}
	
	    string getMhx() {
	        return Mhx;
	    }
	
	    string gettenhang() {
	        return tenhang;
	    }
	
	    string getnuoc() {
	        return nuoc;
	    }
	
	    int getnam() {
	        return nam;
	    }
	
	    void setMhx(string MHX) {
	        Mhx = MHX;
	    }
	
	    void settenhang(string TenHang) {
	        tenhang = TenHang;
	    }
	
	    void setnuoc(string Nuoc) {
	        nuoc = Nuoc;
	    }
	
	    void setnam(int NAM) {
	        nam = NAM;
	    }
	 void nhap() {
	        cin.ignore();
	        getline(cin, Mhx);
	        getline(cin, tenhang);
	        getline(cin, nuoc);
	        cin >> nam;
	    }
	void xuat(){}
	friend istream& operator >>(istream &is,Hangxe &hx){
			is.ignore();
	
	        getline(is, hx.Mhx);
	
	        getline(is, hx.tenhang);
	
	        getline(is, hx.nuoc);
	
	        is >> hx.nam;
	        return is;
	}
	friend ostream& operator <<(ostream &os,Hangxe &hx){
			os<<hx.getMhx()<<"-"<<hx.gettenhang()<<"-"<<hx.getnuoc()<<"-"<<hx.getnam();
			return os;
			}	
	};
	class PTGT{
	private:
	string MaPT,TenPT,Type,HangXe;
	long long Price;	
	public:
		PTGT(){}
		
		void nhap(){}
		
		void xuat(){}
		
		string getMaPT(){
		return MaPT;
		}
		void setMaPT(string mapt){
		this->MaPT = mapt;
		}
		string getTenPT(){
		return TenPT;
		}
		void setTenPT(string tenpt){
		this->TenPT = tenpt;
		}
		string getType(){
		return Type;
		}
		void setType(string type){
		this->Type = type;
		}
		string getHangXe(){
		return HangXe;
		}
		void setHangXe(string hangxe){
		this->HangXe = hangxe;
		}
		long long getPrice(){
		return Price;
		}
		void setPrice(long long price){
		this->Price = price;
		}
	};
		class Oto: private PTGT {
		private:
			string NameCar,Color,Fuel,HX;
			long long NamSX,PhiDK,GiaNY,IndexHX;
		public:
			Oto(){}
			
		void Nhap(vector<Hangxe> &hx1){
	    string a;
	    long long b;
	    cin >> a;
	    PTGT::setMaPT(a);
	    cin.ignore(); 
	    getline(cin, a);
	    PTGT::setTenPT(a);
	    getline(cin, a);
	    PTGT::setType(a);
	    cin >> b;
	    PTGT::setPrice(b);
	    nhapHangxe(hx1);
	    cin.ignore(); 
	    getline(cin, NameCar);
	    cin >> NamSX;
	    cin >> Color;
	    cin >> Fuel;
}
			void nhapHangxe(vector<Hangxe> &hx1){
			cin>>IndexHX;
			if (IndexHX >= 0 && IndexHX < hx1.size()) {
	            HX = hx1[IndexHX].gettenhang();
	        }
			}
			void Xuat(){
			}
			
			string getNameCar(){
			return NameCar;}
			
			void setNameCar(string namecar ){
			this->NameCar = namecar;}
			string getHX(){
			return HX;}
			void setHX(string hx){
			this->HX = hx;}
			string getColor(){
			return Color;}
			void setColor(string color ){
			this->Color = color;}
			
			string getFuel(){
			return Fuel;}
			
			void setFuel(string fuel ){
			this->Fuel = fuel;}
			
			long long getNamSX(){
			return NamSX;}
			
			
			void setNamSX(long long namsx ){
				this->NamSX = namsx;}
			long long getIndexHX(){
			return IndexHX;
			}
			void setIndexHX(long long indexhx){
			 this->IndexHX = indexhx;
			}
			long long Gia(){
			PhiDK = getPrice()+(0.072 * getPrice())+ 500000 + 340000 + 480000 + 2160000;
			return PhiDK;
			}
			friend istream& operator >>(istream &in,Oto &car){
	        return in;
		}
		friend ostream& operator <<(ostream &out,Oto car){
			cout<<car.getMaPT()<<"-"<<car.getNameCar()<<"-"<<car.getNamSX()<<"-"<<car.getHX() <<"-"<<car.getPrice()<<"-"<<car.Color;
			return out;
		}
	};
		class Xemay : public PTGT{
	private:
		string NameBike,ColorBike,FuelBike,hx;
		long long NamSXBike,PhiDKBike,GiaNYBike,Indexhx;
	public:
		Xemay(){
		GiaNYBike  = this->getPrice();
		}
		void Nhap(){}
		void Xuat(){}
		string getNameBike(){
		return NameBike;}
		void setNameBike(string namebike ){
		this->NameBike = namebike;}
		string getColorBike(){
		return ColorBike;}
		void setColorBike(string colorbike ){
		this->ColorBike = colorbike;}
		string getFuelBike(){
		return FuelBike;}
		void setFuelBike(string fuelbike ){
		this->FuelBike = fuelbike;}
		long long getNamSXBike(){
		return NamSXBike;}
		void setNamSXBike(long long namsxbike ){
		this->NamSXBike = namsxbike;}
		string gethx(){
		return hx;}
		long long GiaXM(){
		 return getPrice()+500000;
		}
		void Nhap(vector<Hangxe> &hx1){
	    string a;
	    long long b;
	    cin >> a;
	    PTGT::setMaPT(a);
	    cin.ignore(); 
	    getline(cin, a);
	    PTGT::setTenPT(a);
	    getline(cin, a);
	    PTGT::setType(a);
	    cin >> b;
	    PTGT::setPrice(b);
	    nhapHangXe(hx1);
	    cin.ignore(); 
	    getline(cin, NameBike);
	    cin >> NamSXBike;
	    cin >> ColorBike;
	    cin >> FuelBike;
	}
	void nhapHangXe(vector<Hangxe> &hx1){
		cin>>Indexhx;
		if (Indexhx >= 0 && Indexhx < hx1.size()) {
	    hx = hx1[Indexhx].gettenhang();
	    }
	}
	friend ostream& operator <<(ostream &out,Xemay bike){
			cout<<bike.getMaPT()<<"-"<<bike.getNameBike()<<"-"<<bike.getNamSXBike()<<"-"<<bike.gethx()<<"-"<<bike.getPrice()<<"-"<<bike.getColorBike();
			return out;
		}	
	};
int main(){
	vector<Hangxe> HXe;
	int SLHX;
	cin>>SLHX;
	int Index;
	long long Sum =0;
	for(int i=0;i<SLHX;i++){
		Hangxe hx1;
		cin>>hx1;
		HXe.push_back(hx1);
	}
	vector<Oto> Car;
	vector<Xemay> Bike;
	int SLxe,i=0;cin>>SLxe;
	for(int i=0;i<SLxe;i++){
		Oto oto;
		Xemay xemay;
		cin>>Index;
		if(Index==0){
		oto.Nhap(HXe);
		Car.push_back(oto);
		}else if(Index ==1){
		xemay.Nhap(HXe);
		Bike.push_back(xemay);
		}
	}
	for(i = 0;i<SLxe;i++){
		if(i<Car.size()){
		cout<<Car[i]<<endl;
		}
		if(i<Bike.size()){
		cout<<Bike[i]<<endl;
		}
	}
	cout<<"==="<<endl;

	for(int i =0;i<SLxe;i++){
		if(i<Car.size()){
		Sum+= Car[i].Gia();
		}
		if(i<Bike.size()){
		Sum += Bike[i].GiaXM();
		}
	}
	cout<<Sum;
	return 0;
	}

