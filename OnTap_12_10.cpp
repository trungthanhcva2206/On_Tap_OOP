#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class CanBo{
	public:
		string HoTen;
		int NamSinh;
		int GioiTinh;
		string DiaChi;
		CanBo(){
			HoTen = "";
			NamSinh = 0;
			GioiTinh = 0;
			DiaChi = "";
		}
		void Nhap();
		void Xuat();
};

void CanBo::Nhap(){
	cout<<"Nhap ho ten: ";
	getline(cin.ignore(),HoTen);
	do{
		cout<<"Nhap nam sinh: ";
		cin>>NamSinh;
	}while(NamSinh<1930||NamSinh>2022);
	do{
		cout<<"== Nam(1) va Nu(0) ==\n";
		cout<<"Nhap gioi tinh: ";
		cin>>GioiTinh;
	}while(GioiTinh!=0&&GioiTinh!=1);
	cout<<"Nhap dia chi: ";
	getline(cin.ignore(),DiaChi);
}
void CanBo::Xuat(){
	cout<<"Ho va ten la: "<<HoTen<<endl;
	cout<<"Nam sinh la: "<<NamSinh<<endl;
	if(GioiTinh == 1){
		cout<<"Gioi tinh la: Nam"<<endl;
	}else{
		cout<<"Gioi tinh la: Nu"<<endl;
	}
	cout<<"Dia chi la: "<<DiaChi<<endl;
}

class CongNhan:public CanBo{
	public: 
		int Bac;
		CongNhan(){
			CanBo();
			Bac = 1;
		}
		void Nhap(){
			CanBo::Nhap();
			do{
				cout<<"Nhap bac cua cong nhan : ";
				cin>>Bac;
			}while(Bac<0||Bac>7);
		};
		void Xuat(){
			CanBo::Xuat();
			cout<<"Bac cua Cong Nhan la "<<Bac<<"/7"<<endl;
		};
};

class KySu:public CanBo{
	public:
		string NganhDaoTao;
		KySu(){
			CanBo();
			NganhDaoTao = "";
		}
		void Nhap(){
			CanBo::Nhap();
			cout<<"Nhap nganh dao tao cua ky su: ";
			getline(cin.ignore(),NganhDaoTao);	
		};
		void Xuat(){
			CanBo::Xuat();
			cout<<"Nganh dao tao cua ky su la: "<<NganhDaoTao<<endl;
		}
};

class NhanVien:public CanBo{
	public:
		string CongViec;
		NhanVien(){
			CanBo();
			CongViec = "";
		}
		void Nhap(){
			CanBo::Nhap();
			cout<<"Nhap cong viec cua cong nhan: ";
			getline(cin.ignore(),CongViec);
		}
		void Xuat(){
			CanBo::Xuat();
			cout<<"Cong viec cua cong nhan: "<<CongViec<<endl;	
		}
};

class QLCB{
	public:
		void Run(){
			vector <CongNhan*> cnv;
			vector <KySu*> ksv;
			vector <NhanVien*> nvv;
			int choice;
			do{
				cout<<"1. Nhap thong tin"<<endl;
				cout<<"2. Tim kiem theo ten"<<endl;
				cout<<"3. Hien thi thong tin theo ten"<<endl;
				cout<<"0. Thoat khoi chuong trinh"<<endl;
				cout<<"Nhap lua chon cua ban: ";
				cin>>choice;
				switch(choice){
					case 1:{
						int n;
						cout<<"Nhap so can bo ma ban mong muon: ";
						cin>>n;
						for(int i = 0; i<n;i++){
							int c;
							do{
								cout<<"== Cong nhan(1) va Ky su(2) va Nhan vien(3) ==\n";
								cout<<"Nhap loai can bo cua ban: ";cin>>c;
							}while(c<1||c>3);
							if(c == 1){
								CongNhan * cn = new CongNhan;
								cn->Nhap();
								cnv.push_back(cn);
							}
							if(c==2){
								KySu * ks = new KySu;
								ks->Nhap();
								ksv.push_back(ks);
							}
							if(c==3){
								NhanVien * nv = new NhanVien;
								nv->Nhap();
								nvv.push_back(nv);
							}
						}
						break;
					}
					case 2:{
						string s;
						string t;
						cout<<"Nhap ten ban muon tim: ";
						getline(cin.ignore(),s);
						for(int j = 0; j<s.length();j++){
							s[j]= toupper(s[j]);
						}
						for(int i = 0; i<cnv.size();i++){
							string t = cnv[i]->HoTen;
							for(int o = 0; o<t.length();o++){
								t[o]= toupper(t[o]);
							}
							int viTri = t.find(s);	
							if(viTri!=-1){
								cnv[i]->Xuat();
								cout<<endl;
							}
							viTri = -1;
						}
						for(int i = 0; i<cnv.size();i++){
							string t = ksv[i]->HoTen;
							for(int o = 0; o<t.length();o++){
								t[o]= toupper(t[o]);
							}
							int viTri = t.find(s);	
							if(viTri!=-1){
								ksv[i]->Xuat();
								cout<<endl;
							}
							viTri = -1;
						} 
						for(int i = 0; i<cnv.size();i++){
							string t = nvv[i]->HoTen;
							for(int o = 0; o<t.length();o++){
								t[o]= toupper(t[o]);
							}
							int viTri = t.find(s);	
							if(viTri!=-1){
								nvv[i]->Xuat();
								cout<<endl;
							}
							viTri = -1;
						}  
						break;
					}
					case 3:{
						for(int i = 0;i<cnv.size();i++){
							cnv[i]->Xuat();
							cout<<endl;
						}
						for(int i = 0;i<ksv.size();i++){
							ksv[i]->Xuat();
							cout<<endl;
						}
						for(int i = 0;i<nvv.size();i++){
							nvv[i]->Xuat();
							cout<<endl;
						}
						break;
					}
				}
			}while(choice!=0);
		}

};

int main(){
	QLCB quanlycanbo;
	quanlycanbo.Run(); 
	return 0;
}
