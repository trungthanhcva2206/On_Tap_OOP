#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class CPoint{
	private:
		int x;
		int y;
	public:
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		void setX(int X){
			x = X;
		}
		void setY(int Y){
			y = Y;
		}
		CPoint(){
			x = 0;
			y = 0;
		}
		CPoint(int newX, int newY){
			x = newX;
			y = newY;
		}
		void NhapDiem(){
			cout<<"Nhap tung do x: ";
			cin>>x;
			cout<<"Nhap hoang do y: ";
			cin>>y;
		}
		void XuatDiem(){
			cout<<"Tung do cua diem la: "<<x<<endl;
			cout<<"Hoanh do cua diem la: "<<y<<endl;
		}
		void DiChuyenSangPhai(){
			x = x + 1;
		}
		bool checkThang(double a, double b , double c){
			return (a+b == c)||( a + c == b)|| (b+ c == a);
		}
		friend double KhoangCachGiua2Diem(CPoint * b, CPoint * c);
};
double KhoangCachGiua2Diem(CPoint * b, CPoint * c){
	return sqrt(pow((c->x - b->x),2) + pow((c->y - b->y),2));
};

int main(){
	CPoint * P1 = new CPoint(1,2);
	CPoint * P2 = new CPoint;
	P2->NhapDiem();
	P1->XuatDiem();
	P2->XuatDiem();
	double m = KhoangCachGiua2Diem(P1, P2);
	cout<<m<<endl;
	P2->DiChuyenSangPhai();
	P2->XuatDiem();
	CPoint * P3 = new CPoint;
	P3->NhapDiem();
	double z = KhoangCachGiua2Diem(P1, P2);
	double n = KhoangCachGiua2Diem(P2, P3);
	double t = KhoangCachGiua2Diem(P3, P1);
	if(P1->checkThang(z,n,t)){
		cout<<"3 diem thang hang";
	}else{
		cout<<"3 diem khong thang hang";
	}
}

