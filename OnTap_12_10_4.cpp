#include<iostream>
#include<vector>
#include<string>
using namespace std;

class BenhNhan{
	public:
		string hoTen;
		string queQuan;
		int namSinh;
		BenhNhan(){
			hoTen = "";
			queQuan = "";
			namSinh = 0;
		}
		void Nhap();
		void Xuat();
};

void BenhNhan::Nhap(){
	cout<<"Nhap ho ten: ";
	getline(cin.ignore(),hoTen);
	cout<<"Nhap que quan: ";
	getline(cin,queQuan);
	cout<<"Nhap nam sinh: ";
	cin>>namSinh;
}

void BenhNhan::Xuat(){
	cout<<"Ho va ten la: "<<hoTen<<endl;
	cout<<"Que quan la: "<<queQuan<<endl;
	cout<<"Nam sinh la: "<<namSinh<<endl;
}

class BenhAn:public BenhNhan{
	public:
		string TenBenhAn;
		double SoTien;
		BenhAn(){
			BenhNhan();
			TenBenhAn = "";
			SoTien = 0.0;
		}
		void Nhap(){
			BenhNhan::Nhap();
			cout<<"Nhap ten benh an: ";
			getline(cin.ignore(),TenBenhAn);
			cout<<"Nhap so tien vien phi: ";
			cin>>SoTien;
		};
		void Xuat(){
			BenhNhan::Xuat();
			int t = TinhTuoi();
			cout<<"Tuoi cua benh nhan la: "<<t<<endl;
			cout<<"Ten benh an la: "<<TenBenhAn<<endl;
			cout<<"So tien vien phi la: "<<SoTien<<endl;
		};
		int TinhTuoi(){
			return 2023 - namSinh;
		}
		
};

int main(){
	vector<BenhAn*> bA;
	int n;
	cout<<"Nhap so benh an la: ";
	cin>>n;
	for(int i = 0; i<n;i++){
		BenhAn * Ba = new BenhAn;
		Ba->Nhap();
		bA.push_back(Ba);
	}
	for(int i =0;i<n;i++){
		bA[i]->Xuat();
		cout<<endl;
	}
	BenhAn * ba = new BenhAn;
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
		if(bA[i]->TinhTuoi()<bA[j]->TinhTuoi()){
			ba = bA[i];
			bA[i] = bA[j];
			bA[j] = ba;
		}}
	}
	for(int i =0;i<n;i++){
		bA[i]->Xuat();
		cout<<endl;
	}
	for(int i = 0; i<n;i++){
		if(bA[i]->TinhTuoi()<=10){
			bA[i]->Xuat();
			cout<<endl;
		}
	}
	int Max = 0;
	for(int i = 0; i<n;i++){
		if(bA[i]->SoTien>Max){
			Max = bA[i]->SoTien;
		}
	}
	for(int i = 0;i<n;i++){
		if(bA[i]->SoTien==Max){
			bA[i]->Xuat();
			cout<<endl;
		}
	}
}
