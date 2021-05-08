#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// Eczane menusu icin yonetici sifresinin belirlenmesi:
const string& yonetici_sifresi="admin";  

// Eczane icin sinif olusturulmasi:
class eczn
{
 private:
    int eczn_id;
    string eczn_isim;
    string eczn_adres;
 public:
    eczn();                                   
    eczn(int id_,string isim_, string adres_);   
    eczn(const eczn &obj);                  
    eczn& operator=(const eczn &obj);      

    void eczn_olustur();
    void eczn_goster();
    void eczn_ilac_sayfasi();

    void setID_Num(int id_);
    void setIsim(string isim_);
    void setAdres(string adres_);

    int getID_Num();
    string getIsim();
    string getAdres();
};

// Ilaclar icin sinif olusturulmasi:
class ilac{
 private:
    int ilac_id;
    int ilac_sayisi;
    double ilac_fiyati;
    string ilac_isim;
 public:
    ilac();                                             
    ilac(int id_,int sayi_,double fiyat_,string isim_);     
    ilac(const ilac &obj);                          
    ilac& operator=(const ilac &obj);            

    void ilac_olustur();
    void ilac_goster();
    void ilac_duzenle();

    void setID_Num(int id_);
    void setSayi(int sayi_);
    void setFiyat(double fiyat_);
    void setIsim(string isim_);

    int getID_Num();
    int getSayi();
    double getFiyat();
    string getIsim();
};

// Menu olusturma fonksiyonlarinin prototiplerini tanimliyoruz.
void menu_goster();             //  ana menu
void eczane_menusu();          //  eczane menusu
void musteri_menusu();        // musteri menusu

// Menu icerisinde kullanilacak fonksiyonlarinin prototiplerini tanimliyoruz.
void ecznListesiOlustur();         // eczane listesi, eczane ve bagli ilac listesi olusturur.
void eczn_ekle();                 // listete eczane ekler.
void ilac_ekle();                // listeye ilac ekler.
void ilacDuzenle();             // var olan ilaci duzenler.
void ilac_ara();               // tum eczanelerin ilac listesini tararayarak aranan ilaci bulur.
void eczaneleri_goster();     // eczane listesini yazdirir.
void eczane_goster();        // aranan eczaneyi yazdirir.
void ilac_listele();        // istenen eczanenin ilac listesini yazdirir.

// Bazi islemler icin gerekli ek fonksiyonlarin prototiplerini tanimliyoruz.
int eczn_sayisi ();                                                      // Eczane listesinde kayitli eczane sayisini veren ek fonksiyon.
int obje_sayisi (string ecznIsmi);                                      // Istenen eczaneye kac ilac kayitli oldugunu veren ek fonksiyon.
int kopyakontroleczane(string isim_kopya,int id_kopya);                // Eklenen eczane ile ayni id ve ya isimde eczane varsa uyari verir.
int kopyakontrolilac(string isim_kopya,int id_kopya,string ecznIsmi); //   Eklenen ilac ile ayni id ve ya isimde ilac varsa uyari verir.

// Eczane class'inda bulunan fonksiyonlari tanimliyoruz..
eczn::eczn() 
{
    eczn_id = 0;           //
    eczn_isim = "\0";     // Varsayilan deger -> NULL
    eczn_adres = "\0";   // Varsayilan deger -> NULL
}
eczn::eczn(int id_,string isim_, string adres_)
{
    eczn_id = id_;
    eczn_isim = isim_;
    eczn_adres = adres_;
}
eczn::eczn(const eczn &obj)                 
{
    eczn_id = obj.eczn_id;
    eczn_isim = obj.eczn_isim;
    eczn_adres = obj.eczn_adres;
    
}
eczn &eczn::operator=(const eczn &obj)
{
    eczn_id = obj.eczn_id;
    eczn_isim = obj.eczn_isim;
    eczn_adres = obj.eczn_adres;
    return (*this);
}

void eczn::eczn_olustur()
{ 
    cout<<"Eczane numarasini girin:"<<endl;
    cin>>eczn_id; cin.clear(); fflush(stdin);
    cout<<"Eczane ismini girin : "<<endl;
    cin>>eczn_isim; cin.clear(); fflush(stdin);
    cout<<"Eczane adresini girin: "<<endl;
    cin>>eczn_adres; cin.clear(); fflush(stdin);
}
void eczn::eczn_goster()
{
    cout<<"Eczane ismi: "<<eczn_isim<<" | Eczane ID: "<<eczn_id<<" | Eczane adresi: "<<eczn_adres<<endl;
}
void eczn::eczn_ilac_sayfasi()
{
    string dosyaadi;
    dosyaadi = eczn_isim+"_ilac.dat";
	fstream filex;
	filex.open(dosyaadi.c_str(), ios::out);
    filex.close();
}

void eczn::setID_Num(int id_){eczn_id = id_;}
void eczn::setIsim(string isim_){eczn_isim=isim_;}
void eczn::setAdres(string adres_){eczn_adres = adres_;}

int eczn::getID_Num(){return eczn_id;}
string eczn::getIsim(){return eczn_isim;}
string eczn::getAdres(){return eczn_adres;}

// Ilac class'inda bulunan fonksiyonlari tanimliyoruz..
ilac::ilac()
{
    ilac_id = 0;         //
    ilac_sayisi = 0;    // 
    ilac_fiyati = 0;   //
    ilac_isim = "\0"; // Varsayilan deger -> NULL
    
}
ilac::ilac(int id_, int sayi_,double fiyat_,string isim_ )
{
    ilac_id = id_;
    ilac_sayisi = sayi_;
    ilac_fiyati = fiyat_;
    ilac_isim = isim_;
}
ilac::ilac(const ilac &obj)
{
    ilac_id = obj.ilac_id;
    ilac_sayisi = obj.ilac_sayisi;
    ilac_fiyati = obj.ilac_fiyati;
    ilac_isim = obj.ilac_isim;
}
ilac &ilac::operator=(const ilac &obj)
{
    ilac_id = obj.ilac_id;
    ilac_sayisi = obj.ilac_sayisi;
    ilac_fiyati = obj.ilac_fiyati;
    ilac_isim = obj.ilac_isim;
    return (*this);
}

void ilac:: ilac_olustur()
{
    cout<<"Ilac ID giriniz: "<<endl;
    cin>>ilac_id;cin.clear(); fflush(stdin);
    cout<<"Ilac sayisini giriniz: "<<endl;
    cin>>ilac_sayisi;cin.clear(); fflush(stdin);
    cout<<"Ilac fiyatini giriniz: "<<endl;
    cin>>ilac_fiyati;cin.clear(); fflush(stdin);
    cout<<"Ilac ismini giriniz: "<<endl;
    cin>>ilac_isim;cin.clear(); fflush(stdin);
}
void ilac::ilac_goster()
{
    cout<<"isim: "<<ilac_isim<<" | ID: "<<ilac_id<<" | Sayi: "<<ilac_sayisi<<" | Fiyat: "<<ilac_fiyati<<endl;
}
void ilac::ilac_duzenle()
{
	cout<<"Sistem Notu: Ilac ID'si ve ismi degistirilemez."<<endl;
    cout<<"Yeni ilac sayisini giriniz: "<<endl;
    cin>>ilac_sayisi;cin.clear(); fflush(stdin);
    cout<<"Yeni ilac fiyatini giriniz: "<<endl;
    cin>>ilac_fiyati;cin.clear(); fflush(stdin);
}

void ilac::setID_Num(int id_){ilac_id = id_;}
void ilac::setSayi(int sayi_){ilac_sayisi=sayi_;}
void ilac::setFiyat(double fiyat_){ilac_fiyati=fiyat_;}
void ilac::setIsim(string isim_){ilac_isim=isim_;}

int ilac::getID_Num(){return ilac_id;}
int ilac::getSayi(){return ilac_sayisi;}
double ilac::getFiyat(){return ilac_fiyati;}
string ilac::getIsim(){return ilac_isim;}

// Eczane menusununun olusturulmasi:
void eczane_menusu()
{
        while (1)
        {
            int secim,adet;
            cout<<"Eczane Girisi"<<endl<<
            "1. Eczane Listesi Olustur"<<endl<<
            "2. Eczane Ekle"<<endl<<
            "3. Ilac Ekle"<<endl<<
            "4. Ilac Duzenle"<<endl<<
            "5. Ana Menuye Don"<<endl<<
            "Seciminiz: "<<endl;
            cin>>secim;
            if(secim> 5 || secim<1){
            cout<<"Gecersiz bir secenek girdiniz."<<endl;
            }
            else {
            if (secim==1){
                cout<<"Kac adet eczane gireceksiniz?"<<endl;
                cin>>adet;
                if(adet>0){
                for(;adet>0;adet=adet-1){
                ecznListesiOlustur();
				}
				}
				else {cout<<"Gecersiz giris."<<endl;}
				}
				
            if(secim==2)
                eczn_ekle();
            if(secim==3)
                ilac_ekle();
            if(secim==4)
                ilacDuzenle();
            if(secim==5)
            {
                break;
            }
        }}
}
// Musteri menusununun olusturulmasi:
void musteri_menusu()
{
    while (1)
        {
            int secim;
            cout<<"Musteri Girisi"<<endl<<
            "1. Ilac Ara"<<endl<<
            "2. Eczane Listesi"<<endl<<
            "3. Herhangi bir Eczaneyi Goster"<<endl<<
            "4. Herhangi bir Eczaneye ait Ilac Listesi"<<endl<<
            "5. Ana Menuye Don"<<endl<<
            "Seciminiz: "<<endl;
            cin>>secim;
            
            if (secim==1)
                ilac_ara();
            else if(secim==2)
                eczaneleri_goster();
            else if(secim==3)
                eczane_goster();
            else if(secim==4)
                ilac_listele();
            else if(secim==5)
            {
                break;
            }
            else
                cout<<"Gecersiz giris, lutfen gecerli bir secim giriniz."<<endl; 
        } 
}
// Ana menunun olusturulmasi:
void menu_goster()
{
    string sifre;int secim;
    while (1)
    {
        cout<<"1. Eczane Girisi"<<endl<<
              "2. Musteri Girisi"<<endl<<
              "3. Cikis"<<endl<<
              "Seciminiz: "<<endl;
        cin>>secim;

        if(secim==1)
        {
            cout<<"Sifrenizi giriniz: ";
            cin>>sifre;cin.clear(); fflush(stdin);
            if(sifre==yonetici_sifresi){
            cout<<"Sifre kabul edildi."<<endl;
            eczane_menusu(); }
            else{
            cout<<"Gecersiz sifre girildi."<<endl;
            }
        }
        else if(secim==2)
            musteri_menusu();
        else if(secim==3){
            cout<<"Programdan cikmak icin bir tusa basin..."<<endl; system("pause"); break; }
        else
            cout<<"Gecersiz giris, lutfen gecerli bir secim giriniz."<<endl;    
    }
    
}
// Eczane listesi olusturma fonksiyonunun tanimlanmasi:
void ecznListesiOlustur()
{
    eczn a;char c;
    a.eczn_olustur();
    int kopya_kontrol=kopyakontroleczane(a.getIsim(),a.getID_Num());
    if(kopya_kontrol==0){
    a.eczn_ilac_sayfasi();
    ofstream my_file1;
	my_file1.open("eczane_listesi.dat", ios::app);
    (my_file1 << a.getID_Num()<<" "+a.getIsim()+" " << a.getAdres()<<endl);
     my_file1.close();
     cout<<"Eczane listesi ve eczanenin ilac listesi olusturuldu."<<endl;
     cout<<"Ilac listesini doldurmak ister misiniz?(E/H)"<<endl;
     cout<<"Daha sonra 'Ilac ekle' bolumunden de doldurabilirsiniz."<<endl;
     cout<<"Cevabininizi girin (E/H)."<<endl;
     scanf("%s",&c);
     if(c == 'E' || c =='e'){
    A:
	ilac ilac1;
    ilac1.ilac_olustur();
    ofstream my_file2;
    my_file2.open((a.getIsim()+"_ilac.dat").c_str(),ios::app);
    my_file2<<ilac1.getID_Num()<<" "<<ilac1.getSayi()<<" "<<ilac1.getFiyat()<<" "<<ilac1.getIsim()<<endl;
    my_file2.close();
    cout<<"Daha fazla ilac eklemek istiyor musunuz?(E/H)"<<endl;
    scanf("%s",&c);
      if(c == 'E' || c =='e'){goto A;}
      else{}
	 }
     else{}}
     else { cout<<"Bu id ve ya isimde eczane zaten var."<<endl;
	 cout<<"ID ve isim her bir eczane icin benzersiz olmali."<<endl;}
}
// Eczane ekleme fonksiyonunun tanimlanmasi:
void eczn_ekle()
{
    eczn a;
    a.eczn_olustur();
    int kopya_kontrol=kopyakontroleczane(a.getIsim(),a.getID_Num());
    if(kopya_kontrol==0){
    a.eczn_ilac_sayfasi();
    ofstream my_file1;
	my_file1.open("eczane_listesi.dat", ios::app);
    (my_file1 << a.getID_Num()<<" "+a.getIsim()+" " << a.getAdres()<<endl);
     my_file1.close();cout<<"Eczane listeye eklendi."<<endl;}
       else { cout<<"Bu id ve ya isimde eczane zaten var."<<endl;
       cout<<"ID ve isim her bir eczane icin benzersiz olmali."<<endl;}
}

// Ilac ekleme fonksiyonunun tanimlanmasi:

void ilac_ekle()
{
	string ecznIsmi;
    cout<<"Ilac eklenmek istenen eczanenin ismini giriniz:"<<endl;
    cin>>ecznIsmi;cin.clear(); fflush(stdin);
    ifstream myFile((ecznIsmi+"_ilac.dat").c_str());
    if(myFile.fail()){
    cout<<"Girilen isimde eczane ve ya eczanenin ilac listesi yok."<<endl;}
    else {
    myFile.close();
    ilac ilac1;
    ilac1.ilac_olustur();
    int kopya_kontrol=kopyakontrolilac(ilac1.getIsim(),ilac1.getID_Num(),ecznIsmi);
    if(kopya_kontrol==0){
    ofstream my_file2;
    my_file2.open((ecznIsmi+"_ilac.dat").c_str(),ios::app);
    my_file2<<ilac1.getID_Num()<<" "<<ilac1.getSayi()<<" "<<ilac1.getFiyat()<<" "<<ilac1.getIsim()<<endl;
    my_file2.close(); cout<<"Ilac listeye eklendi."<<endl;}
    else { cout<<"Bu id ve ya isimde ilac zaten var."<<endl;
    cout<<"ID ve isim her bir ilac icin benzersiz olmali."<<endl;}}
}

// Indeksleme islemleri icin yardimci fonksiyonlarin tanimlanmasi:
int eczn_sayisi ()
{
    int eczn_sayisi = 0;
    string satir;
    ifstream myfile("eczane_listesi.dat");
    while (getline(myfile, satir)){ ++eczn_sayisi;}
    return eczn_sayisi;
}

int obje_sayisi (string ecznIsmi)
{
    int obje_sayisi = 0;
    string satir;
    ifstream myfile((ecznIsmi+"_ilac.dat").c_str());
    while (getline(myfile, satir)){ ++obje_sayisi;}
    return obje_sayisi;
}
// Bir eczanenin ilac listesini yazdirma fonskiyonu:
void ilac_listele()
{
    string ecznIsmi;
    cout<<"Ilaclari listelenmek istenen eczanenin ismini giriniz:"<<endl;
    cin>>ecznIsmi;cin.clear(); fflush(stdin);
    int n=obje_sayisi(ecznIsmi);
    if (n==0){ cout<<"Aradiginiz isimde eczane ve ya eczaneye kayitli ilac yok."<<endl;}
    else{
    cout<<"-----------------> Ilac listesi yazdiriliyor <---------------------"<<endl;
    ilac ilac [n];
 	ifstream myfile((ecznIsmi+"_ilac.dat").c_str());
    int id,sayi;double fiyat;string isim;

 for(int i = 0; i < n; i++){
    if(myfile >> id >> sayi >>fiyat>>isim)
     {
     	 ilac[i].setID_Num(id);
     	 ilac[i].setSayi(sayi);
         ilac[i].setFiyat(fiyat);
         ilac[i].setIsim(isim);
         ilac[i].ilac_goster();
     }}
	 cout<<"----------------->  Yazdirma islemi bitti   <---------------------"<<endl;
	 myfile.close(); } 
}


// Ilac duzenleme fonksiyonu:
void ilacDuzenle()
{
    string ecznIsmi; int temp_id,index;
    index=-1;
    cout<<"Ilaclari duzenlemek istenen eczanenin ismini giriniz:"<<endl;
    cin>>ecznIsmi;cin.clear(); fflush(stdin);
    int n=obje_sayisi(ecznIsmi);
    if (n==0){ cout<<"Aradiginiz isimde eczane ve ya eczaneye kayitli ilac yok."<<endl;}
    else{
    cout<<"Duzenlemek istediginiz ilacin ID'sini girin: "<<endl;
    cin>>temp_id;cin.clear(); fflush(stdin);
    ilac ilac [n];
 	ifstream myfile((ecznIsmi+"_ilac.dat").c_str());
    int id,sayi;double fiyat;string isim;

 for(int i = 0; i < n; i++){
    if(myfile >> id >> sayi >>fiyat>>isim)
     {
     	 ilac[i].setID_Num(id);
     	 ilac[i].setSayi(sayi);
         ilac[i].setFiyat(fiyat);
         ilac[i].setIsim(isim);
         if (id==temp_id){
         	index=i;
         }
     }}
     if (index==-1){  cout<<"Aradiginiz ID'ye sahip ilac bulunamadi."<<endl;  }
     else{
     cout<<"Duzenlemek istediginiz ilacin bilgileri:"<<endl;
     ilac[index].ilac_goster();
     ilac[index].ilac_duzenle();
   	fstream my_file;
	my_file.open((ecznIsmi+"_ilac.dat").c_str(), ios::out);
    for(int i = 0; i < n; i++)
    if(my_file << ilac[i].getID_Num()<<" "<<ilac[i].getSayi()<<" "<<ilac[i].getFiyat()<<" "<<ilac[i].getIsim()<<endl)
    {}
	cout<<"Ilac bilgileri basarili bir sekilde duzenlendi."<<endl;
	myfile.close(); my_file.close();}}
}

// Istenilen bir eczanenin bilgilerini gostermek icin fonksiyon:

void eczane_goster()
{
    string eczn_isim;int index=-1;
    cout<<"Aradiginiz eczanenin ismini giriniz:"<<endl;
    cin>>eczn_isim;cin.clear(); fflush(stdin);
    int n1=eczn_sayisi();
    ifstream myfile3("eczane_listesi.dat");
    int ID; string name; string adress;
   
    eczn eczn [n1];
    for(int i = 0; i < n1; i++){
    if(myfile3 >> ID >> name >> adress)
     {
         eczn[i].setID_Num(ID);
         eczn[i].setIsim(name);
         eczn[i].setAdres(adress);
         if (eczn[i].getIsim()==eczn_isim){
         	index=i;
         }
     }}
     if(index==-1){ cout<<"Aranan isimde eczane yok."<<endl;}
	 else{
	 cout<<"----------------->       Eczane yazdiriliyor     <---------------------"<<endl;
	 eczn[index].eczn_goster();
     cout<<"----------------->      Yazdirma islemi bitti    <---------------------"<<endl;
	 }
	 myfile3.close();
}
     
// Tum eczaneleri listelemek icin fonksiyon:

void eczaneleri_goster()
{
    int n1=eczn_sayisi();
    if (n1==0){cout<<"Sisteme henuz eczane eklenmemis."<<endl;}
    else{
    cout<<"-----------------> Eczane listesi yazdiriliyor <---------------------"<<endl;
    ifstream myfile3("eczane_listesi.dat");
    int ID; string name; string adress;
   
    eczn eczn [n1];
    for(int i = 0; i < n1; i++){
    if(myfile3 >> ID >> name >> adress)
     {
         eczn[i].setID_Num(ID);
         eczn[i].setIsim(name);
         eczn[i].setAdres(adress);
         eczn[i].eczn_goster();
     }}
	 cout<<"----------------->      Yazdirma islemi bitti    <---------------------"<<endl;
	 myfile3.close();
}
}
     
// Ilac arama fonksiyonu:
void ilac_ara()
{
    string ilac_ismi; int kontrol=-1;
    cout<<"Aradiginiz ilacin adini girin:"<<endl;
    cin>>ilac_ismi;cin.clear(); fflush(stdin);
    int n1=eczn_sayisi(); string eczn_gecici;
    ifstream myfile3("eczane_listesi.dat");
    int ID; string name; string adress;
    int id,sayi;double fiyat;string isim;
    eczn eczn [n1];
    for(int i = 0; i < n1; i++){
    if(myfile3 >> ID >> name >> adress)
     {
         eczn[i].setID_Num(ID);
         eczn[i].setIsim(name);
         eczn[i].setAdres(adress);
     }}
     
   for(int i=0;i<n1;i++){
   	eczn_gecici=eczn[i].getIsim();
   	int n=obje_sayisi(eczn_gecici);
    ilac ilac [n];
 	ifstream myfile((eczn_gecici+"_ilac.dat").c_str());
     for(int i = 0; i < n; i++){
    if(myfile >> id >> sayi >>fiyat>>isim)
     {
     	 ilac[i].setID_Num(id);
     	 ilac[i].setSayi(sayi);
         ilac[i].setFiyat(fiyat);
         ilac[i].setIsim(isim);
         if (ilac_ismi==ilac[i].getIsim()){
         kontrol=kontrol+1;
         cout<<"Ilacin bulundugu eczane:"<<eczn_gecici<<endl;
         cout<<"Bu eczanede fiyati: "<<ilac[i].getFiyat()<<" | Bu eczanede sayisi:"<<ilac[i].getSayi()<<endl;
         }
     }}myfile3.close(); myfile.close();}
         if (kontrol==-1){cout<<"Aradiginiz ilac hic bir eczanede bulunamadi."<<endl;}
         else{ cout<<"Aradiginiz ilac "<<(kontrol+1)<<" tane eczanede bulundu."<<endl;}
}

// Ayni isim ve id ile eczane eklenmesini onlemek icin fonksiyon:
int kopyakontroleczane(string isim_kopya,int id_kopya)
{   int kontrol=0;
    int n1=eczn_sayisi();
    if (n1==0){return kontrol;}
    else{
    ifstream myfile3("eczane_listesi.dat");
    int ID; string name; string adress;
    eczn eczn [n1];
    for(int i = 0; i < n1; i++){
    if(myfile3 >> ID >> name >> adress)
     {
         eczn[i].setID_Num(ID);
         eczn[i].setIsim(name);
         eczn[i].setAdres(adress);
         if(eczn[i].getID_Num()==id_kopya||eczn[i].getIsim()==isim_kopya){ kontrol=1;}
     }}myfile3.close();} 
	     return kontrol;
}

// Ayni isim ve id ile ilac eklenmesini onlemek icin fonksiyon:
int kopyakontrolilac(string isim_kopya,int id_kopya,string ecznIsmi)
{   int kontrol=0;
    int n=obje_sayisi(ecznIsmi);
    if (n==0){ return kontrol;}
    else{
    ilac ilac [n];
 	ifstream myfile((ecznIsmi+"_ilac.dat").c_str());
    int id,sayi;double fiyat;string isim;

 for(int i = 0; i < n; i++){
    if(myfile >> id >> sayi >>fiyat>>isim)
     {
     	 ilac[i].setID_Num(id);
     	 ilac[i].setSayi(sayi);
         ilac[i].setFiyat(fiyat);
         ilac[i].setIsim(isim);
         if(ilac[i].getID_Num()==id_kopya||ilac[i].getIsim()==isim_kopya){kontrol=1;}
     }} myfile.close();}  
         return kontrol;
}

//  Olusturulan sinif ve fonksiyonlarin kullanilacaði ana fonksiyonun tanimlanmasi:
int main()
{
	cout<<"Eczane Programina Hosgeldiniz!"<<endl;
    menu_goster();
    return 0;          
}
