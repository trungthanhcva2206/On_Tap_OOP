#include<iostream>
#include<vector>
using namespace std;

class MonHoc{
	private:
		string MaMonHoc,TenMonHoc;
		int SoTinChi;
	public:
		MonHoc(){
			MaMonHoc = "";
			TenMonHoc = "";
			SoTinChi = 0;
		}
		MonHoc(string MaMonHoc, string TenMonHoc, int SoTinChi){
			this->MaMonHoc = MaMonHoc;
			this->TenMonHoc = TenMonHoc;
			this->SoTinChi = SoTinChi;
		}
		string getMaMonHoc(){
			return MaMonHoc;
		}
		string getTenMonHoc(){
			return TenMonHoc;
		}
		int getSoTinChi(){
			return SoTinChi;
		}
		void setMaMonHoc(string MaMonHoc ){
			this->MaMonHoc = MaMonHoc;
		}
		void setTenMonHoc(string Ten){
			this->TenMonHoc = Ten;
		}
		void setSoTinChi(int SoTin){
			this->SoTinChi = SoTin;
		}
		friend istream & operator>>(istream & i, MonHoc & mh);
		friend ostream & operator<<(ostream & o, MonHoc mh);
		bool operator !=( const MonHoc&a){
			return (MaMonHoc!=a.MaMonHoc);
		}
};
istream & operator>>(istream & i, MonHoc & mh){
	cout<<"Nhap ma mon hoc: ";
	getline(i.ignore(),mh.MaMonHoc);
	cout<<"Nhap ten mon hoc: ";
	getline(i,mh.TenMonHoc);
	cout<<"Nhap so tin chi: ";
	i>>mh.SoTinChi;
}
ostream & operator<<(ostream & o, MonHoc mh){
	o<<"Ma mon hoc la: "<<mh.MaMonHoc<<endl;
	o<<"Ten mon hoc la: "<<mh.TenMonHoc<<endl;
	o<<"So tin chi la: "<<mh.SoTinChi<<endl;
}

class ToanHoc:public MonHoc{
	private:
		string KieuHoc;
	public:
		ToanHoc(){
			MonHoc();
			KieuHoc = "";
		}
		ToanHoc(string MaMonHoc, string TenMonHoc, int SoTinChi, string KieuHoc):MonHoc(MaMonHoc, TenMonHoc, SoTinChi){
			this->KieuHoc = KieuHoc;
		}
		string getKieuHoc(){
			return KieuHoc;
		}
		void setKieuHoc(string Kieu){
			this->KieuHoc = Kieu;
		}
		friend istream & operator>>(istream & i, ToanHoc & th);
		friend ostream & operator<<(ostream & o, ToanHoc th);
};

istream & operator>>(istream & i, ToanHoc & th){
	MonHoc & mh = th;
	i>>mh;
	cout<<"Nhap kieu hoc: ";
	i>>th.KieuHoc;
}
ostream & operator<<(ostream & o, ToanHoc th){
	MonHoc & mh = th;
	o<<mh;
	o<<"Kieu hoc: "<<th.KieuHoc<<endl;
}

class TinHoc:public MonHoc{
	private:
		double DiemThi;
	public:
		TinHoc(){
			MonHoc();
			DiemThi = 0.0;
		}
		TinHoc(string MaMonHoc, string TenMonHoc, int SoTinChi, double DiemThi):MonHoc(MaMonHoc, TenMonHoc, SoTinChi){
			this->DiemThi = DiemThi;
		}
		double getDiemThi(){
			return DiemThi;
		}
		void setDiemThi(double Diem){
			this->DiemThi = Diem;
		}
		friend istream & operator>>(istream & i, TinHoc & t);
		friend ostream & operator<<(ostream & o, TinHoc t);
};

istream & operator>>(istream & i, TinHoc & t){
	MonHoc & mh = t;
	i>>mh;
	cout<<"Nhap diem thi: ";
	i>>t.DiemThi;
}
ostream & operator<<(ostream & o, TinHoc t){
	MonHoc & mh = t;
	o<<mh;
	o<<"Diem thi: "<<t.DiemThi<<endl;
}

int main(){
	int n;
	vector<TinHoc*> T;
	vector<ToanHoc*> TH;
	do{
		cout<<"Nhap so mon hoc: ";
		cin>>n;
	}while(n<=0||n>=10);
	for(int i = 0; i<n;i++){
		int m;
		do{
			cout<<"== Nhap Toan (0) va Tin (1) =="<<endl;
			cin>>m;
		}while(m!=0 && m!= 1);
		if(m == 0){
			ToanHoc * th = new ToanHoc;
			cin>>*th;
			TH.push_back(th);
		}
		else{
			TinHoc * t = new TinHoc;
			cin>>*t;
			T.push_back(t);
		}
	}
	
	for(int i = 0; i<TH.size();i++){
		cout<< *TH[i]<<endl;
	}
	for(int i = 0 ; i<T.size();i++){
		cout<< *T[i]<<endl;
	}
	
	ToanHoc * th1 = new ToanHoc;
	TinHoc * t1 = new TinHoc;
	cin>>*th1;
	for(int i = 0; i<TH.size();i++){
		if(*th1!=(*TH[i])){
			continue;
		}else{
			cout<<"Da co trong danh sach";
			break;
		}
	}
}
