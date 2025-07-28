#include<iostream>
#include<string>
#include <fstream>
#include<windows.h>
#include<sstream>
using namespace std;
void giris(string login_kullaniciAdi,string login_sifre);
void ana_menu();
void hesap_olustur();
void para_yatir();
void para_cekme();
void bakiye_sorgulama();
void musteri_listesi();
void hesabi_duzenle();
void cikis();
void tekrar_login();
void tekrar_secim();
void hesabi_sil();
struct kullanicilar{
	string id;
	string kullanici_Adi;
	string sifre;
	string isim;
	string soyisim;
};
struct musteriler{
	string id;
	string musteri_ad;
	string musteri_soyad;
	string bakiye;
};
string global_id;
string global_ad;
string global_soy;


int main(){
	tekrar_login();

}
void giris(string login_kullanici,string login_sifre){
	int i,j,val;
	
		ifstream kontrol_giris("kullanicilar.txt");
		kullanicilar kontrol[100];
		i=0;
		while(!kontrol_giris.eof()){
			kontrol_giris>>kontrol[i].id>>kontrol[i].kullanici_Adi>>kontrol[i].sifre>>kontrol[i].isim>>kontrol[i].soyisim; //Text dosyasýndaki kullanýcý bilgilerini
			i++;																										// kontrol structýna aktarýyoruz
		}
		for(j=0;j<i;j++)
			{	
				if(login_kullanici == kontrol[j].kullanici_Adi && login_sifre == kontrol[j].sifre) //For döngüsü kullanýlarak girdileri kontrol ediyoruz.
				{
					
					global_id = kontrol[j].id;
					global_ad = kontrol[j].isim;
					global_soy = kontrol[j].soyisim;
					val = 1;
					break;
				}
				else 
				{
					val = 0;
					continue;	
				}
				
			}
			
		if(val == 1) //Eðer girdiler doðruysa ana menu fonksiyonu çalýþmaya devam eder.
		{
		ana_menu();	
		}
		else
		{
		cout<<endl<<endl<<"Kullanici Adi Veya Sifre Yanlis!!"; 
		}	
					
 }
 
void ana_menu()
{
	int islem_sayi;
	system("cls");   // ekran temizleme kodu
	cout<<endl<<"\t \t \tBanka Yonetim Sistemi";
	cout<<endl<<endl<<"  Hesap Numarasi : "<<global_id;
	cout<<endl<<"  Isim Soyisim : "<<global_ad<<" "<<global_soy<<endl;
	cout<<endl<<"\t\tANA MENU"<<endl;
	cout<<endl<<"\t1-YENI HESAP OLUSTUR"<<endl;
	cout<<endl<<"\t2-PARA YATIRMA"<<endl;
	cout<<endl<<"\t3-PARA CEKME"<<endl;
	cout<<endl<<"\t4-BAKIYE SORGULAMA"<<endl;
	cout<<endl<<"\t5-TUM HESAP SAHIPLERINI GOSTER"<<endl;
	cout<<endl<<"\t6-HESAP KAPAMA"<<endl;
	cout<<endl<<"\t7-HESAP DUZENLEME"<<endl;
	cout<<endl<<"\t8-CIKIS YAP"<<endl;
	cout<<endl<<"\tLutfen size uygun olan secenegi isaretleyiniz (1-8) :"<<" ";
		cin>>islem_sayi;
	if(islem_sayi==1)
	hesap_olustur();
	else if(islem_sayi==2)
		para_yatir();
	else if(islem_sayi==3)
		para_cekme();
	else if(islem_sayi==4){
		system("cls");
		bakiye_sorgulama();}
	else if(islem_sayi==5){           
		system("cls");
		musteri_listesi();}
	else if(islem_sayi==6){
		system("cls");
		musteri_listesi();
		hesabi_sil();	}
	else if(islem_sayi==7)
		hesabi_duzenle();
	else if(islem_sayi==8)
		cikis();
	else{
		cout<<endl<<"\n Hatali Islem Sectiniz.Lutfen Tekrar Deneyiniz...";
		tekrar_secim();
		}	
}
void hesap_olustur(){
	system("cls");
	string musteri_ad1;
	string musteri_soyad1;
	string bakiye1;
	int son1;
	cout<<"\n Hesap Sahibinin Ismini Giriniz : ";
		cin>>musteri_ad1;
	cout<<"\n Hesap Sahibinin Soyismini Giriniz : ";
		cin>>musteri_soyad1;
	cout<<"\n Yatirmak Istediginiz Miktari Giriniz : ";
		cin>>bakiye1;
	
	
	musteriler son_id[100];
	ifstream musteri_id("musteriler.txt");
	int i;
	i=0;
	while(!musteri_id.eof())
	{
		musteri_id>>son_id[i].id;
		musteri_id>>son_id[i].musteri_ad;
		musteri_id>>son_id[i].musteri_soyad;
		musteri_id>>son_id[i].bakiye;
		i++;
	}

	musteri_id.close();
	string son;
	string string_son;
	son = son_id[i-1].id; //stringstream fonksiyonu kullanýlarak string "son", "c" yardýmýyla  integer deðere çevrilir.
	stringstream c;
	c<<son;
	c>>son1;
	son1++;					//son1=en son kullanýcýnýn id'si,string _son yeni kullanýcýnýn id'si.
	stringstream y;
	y<<son1;
	y>>string_son;
	
	
	ofstream yeni_musteri("musteriler.txt",ios::app);
	
	
		yeni_musteri<<endl<<string_son<<" "<<musteri_ad1<<" "<<musteri_soyad1<<" "<<bakiye1;
		yeni_musteri.close();
	
	tekrar_secim();
}
void para_yatir(){
	int i,deger,yatirmak;
	string bakiyem;
	system("cls");
	int secilen_hesap;
	musteri_listesi();
	cout<<endl<<" Para Yatirmak Istediginiz Hesabi Seciniz : "<<" ";
		cin>>secilen_hesap;
		ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
	i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
			
		}	
		musteri_dosya.close();
		
		
			if(kontrol[secilen_hesap-1].id!="\0")
			{
				
				cout<<endl<<" Yatirmak Istediginiz Para Miktari Giriniz : ";
					cin>>yatirmak;
				bakiyem = kontrol[secilen_hesap-1].bakiye; 
				stringstream degistirme;
				degistirme<<bakiyem;				//stringstream fonksiyonu kullanýlarak string "bakiyem", "degistirme" yardýmýyla  integer deðere çevrilir.
				degistirme>>deger;
				if(yatirmak<0)
				{
					cout<<endl<<" Girdiginiz Tutar hatalidir.";
					tekrar_secim();
				}
				deger = deger+yatirmak;
				stringstream degistirmek;
				degistirmek<<deger;
				degistirmek>>bakiyem;
				kontrol[secilen_hesap-1].bakiye = bakiyem;

			}
			else{
				cout<<endl<<" Girdiginiz Kullanici Bulunamadi !";
				tekrar_secim();
				
			}
	ofstream yeni_musteri1("musteriler.txt");	
	string cx;	
		int val;
		for(int j=0;j<i;j++)
		{
		
		
		cx = "\n";
	    if(j==0)
	    {
	    cx = "";
		}
		yeni_musteri1<<cx<<kontrol[j].id<<" "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<" "<<kontrol[j].bakiye;
		val =1;
		}
		yeni_musteri1.close();
		if(val ==1)
		{
			cout<<endl<<" Isleminiz Basariyla Gerceklestirildi . .";
				cout<<endl<<"\n\tYeni Bakiyeniz : "<<kontrol[secilen_hesap-1].bakiye;
		}
	
		tekrar_secim();
}

void para_cekme(){
	int i,cekmek,deger;
	system("cls");
	int secilen_hesap;
	string bakiyem;
	musteri_listesi();
	cout<<endl<<" Para Cekme Istediginiz Hesabi Seciniz : "<<" ";
		cin>>secilen_hesap;
		ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
		i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
		}
		musteri_dosya.close();
		
			if(kontrol[secilen_hesap-1].id!="\0")
			{
				
				cout<<endl<<" Cekmek Istediginiz Para Miktarini Giriniz : ";
					cin>>cekmek;
				bakiyem = kontrol[secilen_hesap-1].bakiye;
				stringstream degistirme;
				degistirme<<bakiyem;				//stringstream fonksiyonu kullanýlarak string "bakiyem", "degistirme" yardýmýyla  integer deðere çevrilir.
				degistirme>>deger;
				if(deger<cekmek)
				{
					cout<<endl<<" Hesabinizda Cekmek Istediginiz Miktarda Para Bulunmamaktadir ! ";
					cout<<"\n\n Hesabinizdan Cekebileceginiz Maksimum Miktar : "<<deger<<" TL ";
					cout<<endl<<" \nCekmek Istediginiz Para Miktarini Giriniz : ";
					cin>>cekmek;
					bakiyem = kontrol[secilen_hesap-1].bakiye;
					stringstream degistirme;
					degistirme<<bakiyem;				//stringstream fonksiyonu kullanýlarak string "bakiyem", "degistirme" yardýmýyla  integer deðere çevrilir.
					degistirme>>deger;
					deger = deger-cekmek;
					stringstream degistirmek;
					degistirmek<<deger;
					degistirmek>>bakiyem;
					kontrol[secilen_hesap-1].bakiye = bakiyem;
					cout<<endl<<"\tYeni Bakiyeniz : "<<kontrol[secilen_hesap-1].bakiye;
					tekrar_secim();
				}
				deger = deger-cekmek;
				stringstream degistirmek;
				degistirmek<<deger;
				degistirmek>>bakiyem;
				kontrol[secilen_hesap-1].bakiye = bakiyem;
					cout<<endl<<"\tYeni Bakiyeniz : "<<kontrol[secilen_hesap-1].bakiye;
				tekrar_secim();

			}
			
	else{
				cout<<endl<<" Girdiginiz Kullanici Bulunamadi ! ";
			}
	ofstream yeni_musteri1("musteriler.txt");	
	string cx;	
		int val;
		for(int j=0;j<i;j++)
		{
		
		
		cx = "\n";
	    if(j==0)
	    {
	    cx = "";
		}
		
	
		yeni_musteri1<<cx<<kontrol[j].id<<" "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<" "<<kontrol[j].bakiye;
		val =1;
		}
		yeni_musteri1.close();
		if(val ==1 && deger>cekmek)
		{
			cout<<endl<<"\n Islem Basariyla Gerceklestirildi . . ";
			cout<<endl<<"\n Yeni Bakiyeniz : "<<kontrol[secilen_hesap-1].bakiye;
		}
	
		tekrar_secim();
}
void bakiye_sorgulama(){
	int i,index,tercih;
		ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
		i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
		}
		for(int j=0;j<i;j++){
			cout<<endl<<j+1<<". Musterimizin id :"<<kontrol[j].id<<" "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<endl;
  		}
		cout<<endl<<" Bakiyesini Sorgulamak Istediginiz Hesabi Seciniz : ";
			cin>>index;
				system("cls");
		cout<<index<<".Musteri :"<<kontrol[index-1].musteri_ad<<" "<<kontrol[index-1].musteri_soyad<<endl<<" Hesap Bakiyesi :"<<kontrol[index-1].bakiye<<endl;
		tekrar_secim();
}
void musteri_listesi(){
	int i;
		ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
		i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
		}
	for(int j=0;j<i;j++){		
		cout<<endl<<j+1<<". Musteri : "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<endl;
	}
		
}

void hesabi_duzenle(){
	int i,secim;
	string temp_name,temp_sur;
		system("cls");
	int secilen_hesap;
	musteri_listesi();
	cout<<endl<<" Duzenleme Yapmak Istediginiz Hesabi Seciniz : "<<" ";
		cin>>secilen_hesap;
	
	ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
	i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
		}
		musteri_dosya.close();
			system("cls");
			if(secilen_hesap<=i){
		cout<<" 1- Isim "<<endl<<" 2- Soyisim ";
		cout<<endl<<" Lutfen Secimizinizi  Yapiniz. . ";
			cin>>secim;
			
	
		
		ofstream isim_degistir ("musteriler.txt");
		switch (secim){
			case 1:{
				cout<<endl<<kontrol[secilen_hesap-1].musteri_ad<<"  "<<kontrol[secilen_hesap-1].musteri_soyad;
				cout<<endl<<"Yeni Ismi Giriniz : ";
					cin>>temp_name;
				kontrol[secilen_hesap-1].musteri_ad=temp_name;
					break;								//swicth case yardýmýyla secilen hesabýn ismini veye soyismini deðiþtiriyoruz.
														//ofstream fonksiyonu kullanarak deðiþen müþteri bilgilerini txt üzerinden de deðiþtiriyoruz.
			}
			case 2:{
				cout<<endl<<kontrol[secilen_hesap-1].musteri_soyad;
				cout<<endl<<" Yeni Soyismi Giriniz : ";
					cin>>temp_sur;
				kontrol[secilen_hesap-1].musteri_soyad=temp_sur;
				break;
			}		
			default :
			cout<<"Hatali Sayi Girdiniz !";
			}
			for(int j=0;j<i;j++){
		
		isim_degistir<<"\n"<<kontrol[j].id<<" "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<" "<<kontrol[j].bakiye;
		}	
		isim_degistir.close();
		tekrar_secim();
	}
	else
	cout<<endl<<"Hatali Secim Yaptiniz ! ";
	tekrar_secim();
}
void cikis(){
	system("cls");
	cout<<endl<<" Bizi Tercih Ettiginiz Icin Tesekkur Ederiz . .";
	exit(0);	
}
void tekrar_login(){
	system("cls");
	string kullaniciAdi,sifre;
	cout<<"\tKullanici Adinizi Giriniz : ";
		cin>>kullaniciAdi;
	cout<<endl<<"\tSifrenizi Giriniz : ";
		cin>>sifre;
	giris(kullaniciAdi,sifre);

}
void tekrar_secim(){
	int tercih;
	cout<<endl<<endl<<"*************";
	cout<<endl<<endl<<"Yapmak Istediginiz Islemi Seciniz : "<<endl;
	cout<<endl<<"1. ANA MANU "<<endl;
	cout<<endl<<"2. CIKIS "<<endl;
	cout<<endl<<"\t\t: ";
		cin>>tercih;
			if(tercih==1){
				system("cls");
				ana_menu();	}
			 else if(tercih==2)
					exit(0);
				else {
						cout<<endl<<".....Hatali Secim Yaptiniz.Bizi Tercih Ettiginiz Icin Tesekkur Ederiz.....";
					exit(0);
				}
			
}
void hesabi_sil(){
		int i,j;
		system("cls");
	int secilen_hesap;
	musteri_listesi();
	cout<<endl<<" Kapatmak Istediginiz Hesabi Seciniz : "<<" ";
		cin>>secilen_hesap;
	
	
	ifstream musteri_dosya("musteriler.txt");
		musteriler kontrol[100];
	i=0;
		while(!musteri_dosya.eof()){
			musteri_dosya>>kontrol[i].id>>kontrol[i].musteri_ad>>kontrol[i].musteri_soyad>>kontrol[i].bakiye;
			i++;
		}
		musteri_dosya.close();
		if(secilen_hesap<i){
				system("cls");
		ofstream hesabi_sil ("musteriler.txt");
		for(j=0;j<i;j++)
			if(j==secilen_hesap-1){			//ofstream fonksiyonu yardýmýyla Txt yi bastan yazacak.
				continue;					//Secilen hesaba gelirse o satýrý atlayýp yazdýrmaya devam edecek.
			}
			else
			hesabi_sil<<"\n"<<kontrol[j].id<<" "<<kontrol[j].musteri_ad<<" "<<kontrol[j].musteri_soyad<<" "<<kontrol[j].bakiye;
		
		hesabi_sil.close();
		cout<<endl<<"Isleminiz Basariyla Gerceklestirildi . ."<<endl;
		tekrar_secim();
				}
				else{
				cout<<endl<<" \nHatali Secim Yaptiniz !";
				tekrar_secim();
				}
}
