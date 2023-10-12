#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Nguoi{
	public:
		int CMND;
		string HoTen;
		int Tuoi;
		int NamSinh;
		string NgheNghiep;
		Nguoi(){
			CMND = 0;
			HoTen = "";
			Tuoi = 0;
			NamSinh = 0;
			NgheNghiep = "";
		}
		void Nhap();
		void Xuat();
};

void Nguoi::Nhap(){
	cout<<"Nhap chung minh nhan dan: ";
	cin>>CMND;
	cout<<"Nhap ho ten: ";
	getline(cin.ignore(),HoTen);
	cout<<"Nhap tuoi: ";
	cin>>Tuoi;
	cout<<"Nhap nam sinh: ";
	cin>>NamSinh;
	cout<<"Nhap nghe nghiep: ";
	getline(cin.ignore(),NgheNghiep);	
}
void Nguoi::Xuat(){
	cout<<"Chung minh nhan dan la: "<<CMND<<endl;
	cout<<"Ho va ten la: "<<HoTen<<endl;
	cout<<"Tuoi la: "<<Tuoi<<endl;
	cout<<"Nam sinh la: "<<NamSinh<<endl;
	cout<<"Nghe nghiep la: "<<NgheNghiep<<endl;
}

class HoDan:public Nguoi{
	public:
		vector<Nguoi*> ng;
		int SoThanhVien;
		int SoNha;
		HoDan(){
			SoThanhVien = 0;
			SoNha = 0;
		}
		void Nhap(){
			do{
				cout<<"Nhap thanh vien trong gia dinh: ";
				cin>>SoThanhVien;
			}while(SoThanhVien<1);
			cout<<"Nhap so nha la: ";
			cin>>SoNha;
			for(int i = 0; i<SoThanhVien;i++){
				cout<<"Nhap thanh vien thu "<<i+1<<" la: "<<endl;
				Nguoi * ngu = new Nguoi;
				ngu->Nhap();
				ng.push_back(ngu);
				cout<<endl;
			}
		};
		void Xuat(){
			cout<<"So thanh vien trong gia dinh la: "<<SoThanhVien<<endl;
			cout<<"So nha trong gia dinh la: "<<SoNha<<endl;
			for(int i = 0; i<SoThanhVien;i++){
				cout<<"Thanh vien thu "<<i+1<<" la: "<<endl;
				ng[i]->Xuat();
				cout<<endl;
			}
		};
};

int main(){
	vector<HoDan*> hodan;
	int choice;
	do{
		cout<<"1. Nhap thong tin ho dan."<<endl;
		cout<<"2. Tim kiem thong tin ho dan theo ten."<<endl;
		cout<<"3. Tim kiem thong tin ho dan theo so nha."<<endl;
		cout<<"4. Hien thi thong tin ho dan."<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"Nhap lua chon: ";
		cin>>choice;
		switch(choice){
			case 1:{
				int n;
				cout<<"Nhap so ho dan ban mong muon: ";
				cin>>n;
				for(int i = 0;i<n;i++){
					cout<<"Nhap ho dan thu "<<i+1<<" : "<<endl;
					HoDan * hd = new HoDan;
					hd->Nhap();
					hodan.push_back(hd);
				}
				break;
			}
			case 2:{
				string s;
				cout<<"Nhap ten ban muon tim: ";
				getline(cin.ignore(),s);
				for(int i =0;i<s.length();i++){
					s[i] = toupper(s[i]);
				}
				for(int i =0;i<hodan.size();i++){
					int m = hodan[i]->SoThanhVien;
					for(int j = 0;j<m;j++){
						string t = hodan[i]->ng[j]->HoTen;
						for(int w = 0;w<t.length();w++){
							t[w]=toupper(t[w]);
						}
						int viTri = t.find(s);
						if(viTri!=-1){
							hodan[i]->Xuat();
						}
						viTri = -1;
					}
				} 
				break;
			}
			case 3:{
				int t;
				cout<<"Nhap so nha ban muon tim: ";
				cin>>t;
				for(int i = 0;i<hodan.size();i++){
					if(hodan[i]->SoNha == t){
						hodan[i]->Xuat();
					}
				}
				break;
			}
			case 4:{
				for(int i = 0;i<hodan.size();i++){
					hodan[i]->Xuat();
					cout<<endl;
				}
				break;
			}
		}
	}while(choice!=0);
}
