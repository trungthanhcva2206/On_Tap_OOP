#include<iostream>
#include<vector>
#include<string>
using namespace std;

class SanPham{
	private:
		string Ten,NhaSanXuat;
	public:
		SanPham(){
			Ten = "";
			NhaSanXuat = "";
		}
		SanPham(string Ten, string NhaSanXuat){
			this -> Ten = Ten;
			this -> NhaSanXuat = NhaSanXuat;
		}
		string getTen(){
			return Ten;
		}
		string getNhaSanXuat(){
			return NhaSanXuat;
		}
		void setTen(string sTen){
			this -> Ten = sTen;
		}
		void setNhaSanXuat(string sNhaSanXuat){
			this -> NhaSanXuat = sNhaSanXuat;
		}
		void Nhap(){
			cout<<"Nhap ten san pham: ";
			getline(cin.ignore(),Ten);
			cout<<"Nhap ten nha san xuat cua san pham: ";
			getline(cin,NhaSanXuat);
		}
		void Xuat(){
			cout<<"Ten san pham la: "<<Ten<<endl;
			cout<<"Ten nha san xuat la: "<<NhaSanXuat<<endl;
		}
};

class BanLe:SanPham{
	private:
		double GiaBanLe;
		int SoLuong;
	public:
		BanLe(){
			SanPham();
			GiaBanLe = 0.0;
			SoLuong = 0;
		};
		BanLe(string Ten, string NhaSanXuat,double GiaBanLe, int SoLuong):SanPham(Ten, NhaSanXuat){
			this -> GiaBanLe = GiaBanLe;
			this -> SoLuong = SoLuong;
		}
		double getGiaBanLe(){
			return GiaBanLe;
		}
		int getSoLuong(){
			return SoLuong;
		}
		void setGiaBanLe(double GiaBanLe){
			this -> GiaBanLe = GiaBanLe;
		}
		void setSoLuong(int SoLuong){
			this -> SoLuong = SoLuong;
		}
		void Nhap(){
			SanPham::Nhap();
			cout<<"Nhap gia ban le cua san pham la: ";
			cin>>GiaBanLe;
			do{
				cout<<"Nhap so luong cua san pham: ";
				cin>>SoLuong;
			}while(SoLuong>=10||SoLuong<=0);
		}
		double ThanhToan(){
			return GiaBanLe * SoLuong;
		}
		void Xuat(){
			SanPham::Xuat();
			cout<<"Gia ban le cua san pham la: "<<GiaBanLe<<endl;
			cout<<"So luong san pham la: "<<SoLuong<<endl;
			cout<<"So tien ban phai thanh toan la: "<<ThanhToan()<<endl;
		}
};

class BanSi:SanPham{
	private:
		double GiaSi;
		int SoLuong;
	public:
		BanSi(){
			SanPham();
			GiaSi = 0.0;
			SoLuong = 0;
		};
		BanSi(string Ten, string NhaSanXuat, double GiaSi, int SoLuong):SanPham(Ten,NhaSanXuat){
			this -> GiaSi = GiaSi;
			this -> SoLuong = SoLuong;
		}
		double getGiaSi(){
			return GiaSi;
		}
		int getSoLuong(){
			return SoLuong;
		}
		void setGiaTri(double GiaSi){
			this -> GiaSi = GiaSi;
		}
		void setSoLuong(int SoLuong){
			this -> SoLuong = SoLuong;
		}
		void Nhap(){
			SanPham::Nhap();
			cout<<"Nhap gia si cua san pham: ";
			cin>>GiaSi;
			do{
				cout<<"Nhap so luong san pham: ";
				cin>>SoLuong;
			}while(SoLuong<=100);
		}
		double ThanhToan(){
			return GiaSi * SoLuong;
		}
		void Xuat(){
			SanPham::Xuat();
			cout<<"Gia si cua san pham: "<<GiaSi<<endl;
			cout<<"So luong cua san pham: "<<SoLuong<<endl;
			cout<<"So tien phai thanh toan la: "<<ThanhToan()<<endl;
		}
};

int main(){
	vector<BanSi*> BS;
	vector<BanLe*> BL;
	int n;
	do{
		cout<<"Nhap so san pham la: ";
		cin>>n;
	}
	while(n<=0);
	for(int i = 0; i<n;i++){
		int t;
		do{
			cout<<"So luong san pham phai lon hon va khong the nam trong khoang tu 10 den 100"<<endl;
			cout<<"Nhap so luong du dinh cua san pham thu "<<i + 1<<" : ";
			cin>>t;
		}while(t<=0||(t>=10&&t<=100));
		if(t<10){
			cout<<" === San pham cua ban se duoc ap dung bang gia ban le === "<<endl;
			BanLe * bl = new BanLe;
			bl->Nhap();
			BL.push_back(bl);
		}
		else{
			cout<<" === San pham cua ban se duoc ap dung bang gia ban si === "<<endl;
			BanSi * bs = new BanSi;
			bs->Nhap();
			BS.push_back(bs);
		}
	}
	cout<<endl;
	for(int i =0;i<BL.size();i++){
		BL[i]->Xuat();
		cout<<endl;
	}
	for(int i =0;i<BS.size();i++){
		BS[i]->Xuat();
		cout<<endl;
	}
	double Min;
	if(BL.size()!= 0 ){
		Min = BL[0]->ThanhToan();
	}else{
		Min = BS[0]->ThanhToan();
	}
	for(int i = 0;i<BL.size();i++){
		if(Min>BL[i]->ThanhToan()){
			Min = BL[i]->ThanhToan();
		}
	}
	for (int i = 0; i<BS.size();i++){
		if(Min>BS[i]->ThanhToan()){
			Min = BS[i]->ThanhToan();
		}
	}
	int m = 0;
	for(int i = 0; i<BL.size();i++){
		if(BL[i]->ThanhToan() == Min){
			BL[i]->Xuat();
			cout<<endl;
			m++;
			break;
		}
	}
	for(int i = 0;i<BS.size();i++){
		if(BS[i]->ThanhToan() == Min && m == 0){
			BS[i]->Xuat();
			cout<<endl;
		}
	}
	
}
