#include<iostream>
#include<string>
#include<vector>
using namespace std;

class NhanVien{
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		string getHoTen(){
			return HoTen;
		}
		NhanVien(){
			HoTen = "";
			NamSinh = 0;
			GioiTinh = "";
			DiaChi = "";
		}
		NhanVien(string HoTen, int NamSinh, string GioiTinh, string DiaChi){
			this->HoTen = HoTen;
			this->NamSinh = NamSinh;
			this->GioiTinh = GioiTinh;
			this->DiaChi = DiaChi;
		}
		friend istream & operator>>(istream & i, NhanVien & nv);
		friend ostream & operator<<(ostream & o, NhanVien nv);
};
istream & operator>>(istream & i, NhanVien & nv){
	cout << "Nhap ho ten nhan vien: ";
    getline(i.ignore(), nv.HoTen);
    
    cout << "Nhap nam sinh nhan vien: ";
    i >> nv.NamSinh;
    
    cout << "Nhap gioi tinh nhan vien: ";
    getline(i.ignore(), nv.GioiTinh);
    
    cout << "Nhap dia chi nhan vien: ";
    getline(i, nv.DiaChi);
    
    return i;
}

ostream & operator<<(ostream & o, NhanVien nv){
	o<<"Ho ten nhan vien la: "<<nv.HoTen<<endl;
	o<<"Nam sinh nhan vien la: "<<nv.NamSinh<<endl;
	o<<"Gioi tinh nhan vien la: "<<nv.GioiTinh<<endl;
	o<<"Dia chi nhan vien la: "<<nv.DiaChi<<endl;
	return o;
}
class CongNhan:public NhanVien{
	protected:
		double TienLuong;
		string CongViec;
	public:
		CongNhan(){
			NhanVien();
			TienLuong = 0.0;
			CongViec = "";
		}
		CongNhan(string HoTen, int NamSinh, string GioiTinh, string DiaChi, double TienLuong, string CongViec):NhanVien(HoTen, NamSinh, GioiTinh, DiaChi){
			this->TienLuong = TienLuong;
			this->CongViec = "";
		}
		friend istream & operator>>(istream & i, CongNhan & cn);
		friend ostream & operator<<(ostream & o, CongNhan cn);
};
istream & operator>>(istream & i, CongNhan & cn){
	NhanVien & nv = cn;
	i>>nv;
	cout<<"Nhap cong viec: ";
	getline(i,cn.CongViec);
	cout<<"Nhap tien luong: ";
	i>>cn.TienLuong;
	return i;
}
ostream & operator<<(ostream & o, CongNhan cn){
	NhanVien & nv = cn;
	o<<nv;
	o<<"Tien luong: "<<cn.TienLuong<<endl;
	o<<"Cong viec: "<<cn.CongViec<<endl;
	return o;
}

int main(){
	vector<CongNhan*> CN;
	int n;
	do{
		cout<<"Nhap so cong nhan: ";
		cin>>n;
	}while(n<=0||n>=10);
	for(int i = 0 ; i<n;i++){
		cout<<"Nhap thong tin cong nhan thu "<<i+1<<endl;
		CongNhan * cn = new CongNhan;
		cin>> *cn;
		CN.push_back(cn);
	}
	for(int i = 0; i<n;i++){
		cout<< *CN[i];
	}
	string s;
	cout<<"Nhap ho ten ban muon tim: ";
	getline(cin.ignore(),s);
	for(int i = 0; i<s.length();i++){
		s[i] = toupper(s[i]);
	}
	for(int i = 0; i<CN.size();i++){
		string t = CN[i]->getHoTen();
		for(int m = 0;m<t.length();m++){
			t[m] = toupper(t[m]);
		}
		int Vitri = t.find(s);
		if(Vitri != -1){
			cout<< *CN[i];
		}
		Vitri = -1;
	}
	
}
