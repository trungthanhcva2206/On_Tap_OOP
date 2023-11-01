#include<iostream>
using namespace std;

class MonHoc{
	private:
		string MaMH,TenMH;
		int SoTinChi;
	public:
		MonHoc();
		MonHoc(string MaMH,string TenMH,int SoTinChi);
		void setMaMH(string newMaMH);
		void setTenMH(string newTenMH);
		void setSoTinChi(int newSoTinChi);
		string getMaMH();
		string getTenMH();
		int getSoTinChi();
		void input();
		void output();
		bool operator !=(MonHoc a)
		{
			return (MaMH!=a.MaMH);
		}
};
MonHoc::MonHoc()
{
	
}
MonHoc::MonHoc(string MaMH,string TenMH,int SoTinChi)
{
	MaMH = MaMH;
	TenMH = TenMH;
	SoTinChi = SoTinChi;
}
string MonHoc::getMaMH(){
	return MaMH;
}
string MonHoc::getTenMH(){
	return TenMH;
}
int MonHoc::getSoTinChi(){
	return SoTinChi;
}
void MonHoc::setMaMH(string newMaMH){
	MaMH = newMaMH;
}
void MonHoc::setTenMH(string newTenMH){
	TenMH = newTenMH;
}
void MonHoc::setSoTinChi(int newSoTinChi){
	SoTinChi = newSoTinChi;
}
void MonHoc::input(){
	cout<<endl;
	cin.ignore();
	cout<<"Nhap ma MH: ";getline(cin,MaMH);
	cout<<"Nhap ten MH: ";getline(cin,TenMH);
	cout<<"Nhap so tin chi: ";cin>>SoTinChi;
}
void MonHoc::output(){
	cout<<endl;
	cout<<"Ma MH: "<<MaMH<<endl;
	cout<<"Ten MH: "<<TenMH<<endl;
	cout<<"So tin chi: "<<SoTinChi<<endl;
}
//=========================================
class ToanHoc: public MonHoc{
	private:
		string KieuHoc;
	public:
		ToanHoc();
		ToanHoc(string MaMH,string TenMH,int SoTinChi,string KieuHoc);
		void setKieuHoc(string newKieuHoc);
		string getKieuHoc();
		void input();
		void output();
		//friend bool operator !=(ToanHoc t1,ToanHoc t2);

};
ToanHoc::ToanHoc(){
}
ToanHoc::ToanHoc(string MaMH,string TenMH,int SoTinChi,string KieuHoc):MonHoc(MaMH,TenMH,SoTinChi){
	this->KieuHoc = KieuHoc;
}
void ToanHoc::setKieuHoc(string newKieuHoc){
	KieuHoc = newKieuHoc;
}
string ToanHoc::getKieuHoc(){
	return KieuHoc;
}
void ToanHoc::input(){
	MonHoc::input();
	cin.ignore();
	cout<<"Nhap kieu hoc: ";getline(cin,KieuHoc);
}
void ToanHoc::output(){
	MonHoc::output();
	cout<<"Kieu hoc: "<<KieuHoc<<endl;
}
//bool operator !=(ToanHoc t1,ToanHoc t2){
//	if(t1.getMaMH() == t2.getMaMH()){
//		return false;
//	}else{
//		return true;
//	}
//}
//==================================
class TinHoc: public MonHoc{
	private:
		float DiemThi;
	public:
		TinHoc();
		TinHoc(string MaMH,string TenMH,int SoTinChi,float Diemthi);
		void setDiemThi(float newDiemThi);
		float getDiemThi();
		void input();
		void output();
		//friend bool operator !=(ToanHoc t1,ToanHoc t2);

};
TinHoc::TinHoc(){
}
TinHoc::TinHoc(string MaMH,string TenMH,int SoTinChi,float DiemThi):MonHoc(MaMH,TenMH,SoTinChi){
	this->DiemThi = DiemThi;
}
void TinHoc::setDiemThi(float newDiemThi){
	DiemThi = newDiemThi;
}
float TinHoc::getDiemThi(){
	return DiemThi;
}
void TinHoc::input(){
	MonHoc::input();
	cin.ignore();
	cout<<"Nhap diem thi: ";cin>>DiemThi;
}
void TinHoc::output(){
	MonHoc::output();
	cout<<"Diem thi: "<<DiemThi<<endl;
}
//===========================================
int main(){
	int n,count = 0;
	do{
		cout<<"Nhap so doi tuong: ";cin>>n;
	}while(n<0);
	TinHoc *Tin;
	ToanHoc *Toan;
	int DemTin=0, DemToan=0; 
	for(int i=0; i<n; i++)
	{
		int ch;
		do{
			cout<<"Nhap Tin hoc (1) hoac Toan hoc(2)";
			cin>>ch;	
		}while(ch!=1 && ch!=2);
		if (ch==1)
		{
			Tin = new TinHoc;
			cout<<"Nhap thong tin cua Tin hoc:\n";
			Tin->input();
			DemTin++;
		}
		else
		{
			Toan = new ToanHoc;
			cout<<"Nhap thong tin cua Toan hoc:\n";
			Toan->input();
			DemToan++;
		}
	}
	cout<<"Thong tin mon Tin hoc:\n";
	for(int i=0; i<DemTin; i++)
		Tin[i].output();
	cout<<"\nThong tin mon Toan hoc:\n";
	for(int i=0; i<DemToan; i++)
		Toan[i].output();
	//Su dung nap chong toan tu
	TinHoc Tin1;
	ToanHoc Toan1;
	int ch;
	do{
		cout<<"Nhap Tin hoc (1) hoac Toan hoc(2)";
		cin>>ch;	
	}while(ch!=1 && ch!=2);
	if(ch==1) 
	{
		Tin1.input();
		for(int i=0;i<DemTin;i++)
		{
			if (Tin1!=Tin[i]){
				continue;
				//count++;
			}
			else
			{
				cout<<"Doi tuong co trong danh sach doi tuong ban dau!"<<endl;
				//count++;
				break;
			}
		}
	}
	else
	{
		Toan1.input();
		for(int i=0;i<DemToan;i++)
		{
			if (Toan1!=Toan[i]){
				continue;
				//count++;
			}
			else
			{
				cout<<"Doi tuong co trong danh sach doi tuong ban dau!"<<endl;
				//count++;
				break;
			}
		}
	}
	
//	
//	ToanHoc T[n];
//	cin.ignore();
//	for(int i=0;i<n;i++){
//		T[i].input();
//	}
//	for(int i=0;i<n;i++){
//		T[i].output();
//	}
//	ToanHoc b;
//	b.input();
//	for(int i=0;i<n;i++){
//		if (b!=T[i]){
//			continue;
//			count++;
//		}else{
//			cout<<"Doi tuong co trong danh sach doi tuong ban dau!"<<endl;
//			count++;
//			break;
//		}
//	}
//	if(count==0){
//		cout<<"Doi tuong khong co trong danh sach doi tuong ban dau!"<<endl;

	
}
