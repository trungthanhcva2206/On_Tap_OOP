#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
class  Nguoi{
	protected:
		string HoTen;
		int NamSinh;
	public:
		Nguoi(){
			HoTen = "";
			NamSinh = 0;
		}
		virtual void Nhap(){
			cout<<"Nhap ho ten nguoi: ";
			getline(cin.ignore(),HoTen);
			do{
				cout<<"Nhap nam sinh nguoi: ";
				cin>>NamSinh;
			}while(NamSinh<=1930||NamSinh>2023);
		}
		virtual void Xuat(){
			cout<<left<<setw(15)<<"Ho ten nguoi:"<<HoTen<<"|";
			cout<<left<<setw(7)<<"Nam sinh:"<<NamSinh<<"|";
		}
		virtual int TuoiHienTai(){
			return 2023 - NamSinh;
		}
		virtual double TienVienPhi(){
			return 0;
		}
};

class Benh_Nhan:public Nguoi{
	protected:
		string TenBenhAn;
		int SoNgayNamVien;
	public:
		Benh_Nhan(){
			Nguoi();
			TenBenhAn = "";
			SoNgayNamVien = 0;
		}
		void Nhap(){
			Nguoi::Nhap();
			cout<<"Nhap ten benh an: ";
			getline(cin.ignore(),TenBenhAn);
			cout<<"Nhap so ngay nhap vien: ";
			cin>>SoNgayNamVien;
		}
		int TuoiHienTai(){
			return 2017 - NamSinh;
		}
		double TienVienPhi(){
			return SoNgayNamVien*50000;
		}
		void Xuat(){
			Nguoi::Xuat();
			cout<<left<<setw(5)<<"Ten benh an:"<<TenBenhAn<<"|";
			cout<<left<<setw(5)<<"So ngay nhap vien:"<<SoNgayNamVien<<"|";
			cout<<left<<setw(5)<<"Tuoi hien tai:"<<TuoiHienTai()<<"|";
			cout<<left<<setw(5)<<"Tien vien phi:"<<TienVienPhi()<<endl;
		}
};

int main(){
	vector<Nguoi*> nguoi;
	int n;
	do{
		cout<<"Nhap danh sach nguoi ban muon nhap: ";
		cin>>n;
	}while(n<=0||n>100);
	for(int i = 0; i<n;i++){
		Benh_Nhan * newBenhNhan = new Benh_Nhan;
		newBenhNhan->Nhap();
		nguoi.push_back(newBenhNhan);
	}
	cout<<"\n===Danh sach benh nhan===\n";
	for(int i = 0; i<nguoi.size();i++){
		nguoi[i]->Xuat();
	}
	cout<<"\n===Danh sach benh nhan co tuoi duoi 10===\n";
	for(int i = 0; i<nguoi.size();i++){
		if(nguoi[i]->TuoiHienTai()<10){
			nguoi[i]->Xuat();
		}
	}
	cout<<"\n===Cac benh nhan co tien vien phi cao nhat===\n";
	double max;
	for(int i = 0;i<nguoi.size();i++){
		if(nguoi[i]->TienVienPhi()>max){
			max = nguoi[i]->TienVienPhi();
		}
	}
	for(int i = 0;i<nguoi.size();i++){
		if(nguoi[i]->TienVienPhi() == max){
			nguoi[i]->Xuat();
			cout<<endl;
		}
	}
}
