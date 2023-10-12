#include <iostream>
using namespace std;
class PhanSo
{
	private:
		int tuso;
		int mauso;
	public:
		PhanSo()
		{
			tuso=0; mauso=0;
		}
		PhanSo(const PhanSo &a)
		{
			tuso=a.tuso; mauso=a.mauso;
		}
		void nhap();
		void xuat();
		void toigian();
		PhanSo operator +(PhanSo a);
		friend PhanSo operator -(PhanSo x,PhanSo y);
		int operator <(PhanSo b)
		{
			return (tuso*b.mauso<mauso*b.tuso);
		}
};
void PhanSo::nhap()
{
	cout<<"Tu so = "; cin>>tuso;
	do
	{
		cout<<"Mau so = "; cin>>mauso;
	} while (mauso==0);
	cout<<endl;
}
void PhanSo::xuat()
{
	cout<<tuso<<"/"<<mauso<<endl;
}
void  PhanSo::toigian()
{
	int mcln=0;
	for (int i=2;i<=min(tuso,mauso);i++)
		if (tuso%i==0&&mauso%i==0) 
			mcln=i;
	if (mcln!=0)
	{
		tuso=tuso/mcln;
		mauso=mauso/mcln;
	}
}
void hoanvi(PhanSo &a,PhanSo &b)
{
	PhanSo tg;
	tg=a;
	a=b;
	b=tg;
}
PhanSo PhanSo::operator +(PhanSo a)
{
	PhanSo kq;
	kq.tuso=tuso*a.mauso+mauso*a.tuso;
	kq.mauso=mauso*a.mauso;
	return kq;
}
PhanSo operator -(PhanSo a,PhanSo b)
{
	PhanSo kq;
	kq.tuso=b.tuso*a.mauso-b.mauso*a.tuso;
	kq.mauso=b.mauso*a.mauso;
	return kq;
}

int main()
{
	int n;
	do
	{
		cout<<"Nhap so phan so: "; cin>>n;
	} while (n<0||n>10);
	PhanSo ps[n];
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap phan so thu "<<i+1<<endl;
		ps[i].nhap();
	}
	cout<<"Mang phan so da nhap la\n";
	for (int i=0;i<n;i++)
		ps[i].xuat();
	for (int i=0;i<n;i++)
		ps[i].toigian();
	cout<<"Mang phan so sau khi toi gian\n";
	for (int i=0;i<n;i++)
		ps[i].xuat();
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
		{
			if (ps[i]<ps[j]) hoanvi(ps[i],ps[j]);
		}
	cout<<"Mang sau khi sap xep\n";
	for (int i=0;i<n;i++)
		ps[i].xuat();
//HUONG DAN CUA THAY - NAP CHONG TOAN TU
/*	{ 
	cout<<"Cong tru 2 phan so\n";
	PhanSo tg,a,b;
	a.nhap();
	a.xuat();
	b.nhap();
	b.xuat();
	tg=a+b;
	tg.toigian();
	tg.xuat();
	tg=operator -(a,b);
	tg.toigian();
	tg.xuat();
	if (a<b)
	{
		cout<<"Phan so ";
		a.xuat();
		cout<<"nho hon phan so ";
		b.xuat();
	}
	}*/
}
