#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;
class SANPHAM {
	protected:
		string TenSanPham;
		int NamSanXuat;
		int GiaThanh;
	public:
		SANPHAM(){
			TenSanPham = "";
			NamSanXuat = 0;
			GiaThanh = 0;
		}
		virtual void Nhap(){
			cout<<"Nhap ten san pham: ";
			getline(cin.ignore(),TenSanPham);
			cout<<"Nhap nam san xuat: ";
			cin>>NamSanXuat;
			cout<<"Nhap gia thanh san pham: ";
			cin>>GiaThanh;
		}
		virtual void Xuat(){
			cout<<left<<setw(5)<<"Ten san pham: "<<TenSanPham<<"|";
			cout<<left<<setw(5)<<"Nam san xuat: "<<NamSanXuat<<"|";
			cout<<left<<setw(5)<<"Gia thanh san pham: "<<GiaThanh<<"|";
		}
		virtual int ThanhTien(){
			return 0;
		}
		virtual int TinhLai(){
			return 0;
		}
};
class HOADON:public SANPHAM{
	protected:
		int SoLuong;
		int GiaBan;
	public:
		HOADON(){
			SANPHAM();
			SoLuong = 0;
			GiaBan = 0;
		}
		void Nhap(){
			SANPHAM::Nhap();
			cout<<"Nhap so luong san pham: ";
			cin>>SoLuong;
			cout<<"Nhap gia ban san pham: ";
			cin>>GiaBan;
		}
		void Xuat(){
			SANPHAM::Xuat();
			cout<<left<<setw(5)<<"So luong san pham: "<<SoLuong<<"|";
			cout<<left<<setw(5)<<"Gia ban san pham: "<<GiaBan<<"|";
			cout<<left<<setw(5)<<"Thanh tien: "<<ThanhTien()<<"|";
			cout<<left<<setw(5)<<"Lai: "<<TinhLai()<<endl;
		}
		int ThanhTien(){
			return SoLuong*GiaBan;
		}
		int TinhLai(){
			return SoLuong*(GiaBan- GiaThanh);
		}
};

int main(){
	vector<SANPHAM*> sp;
	int n;
	do{
		cout<<"Nhap so san pham: ";
		cin>>n;
	}while(0>=n||n>100);
	for(int i = 0;i<n;i++){
		HOADON * hd = new HOADON;
		hd->Nhap();
		sp.push_back(hd);
	}
	cout<<"\n==Danh sach hoa don chua sap xep==\n";
	for(int i = 0; i<sp.size();i++){
		sp[i]->Xuat();
	}
	for(int i = 0;i<sp.size()-1;i++){
		for(int j = 1;j<sp.size();j++){
			if(sp[i]->TinhLai()<sp[j]->TinhLai()){
				SANPHAM * temp = new SANPHAM;
				temp = sp[i];
				sp[i]= sp[j];
				sp[j] = temp;
			}
		}
	}
	cout<<"\n==Danh sach hoa don da sap xep==\n";
	for(int i = 0; i<sp.size();i++){
		sp[i]->Xuat();
	}
}
