#include <iostream>
#include <fstream> // file read and write
#include <string>
#include <random> //random name and surname
#include <ctime> // for random number
#include <vector>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;


/*                                  ,/(#%#(*.
                          %%%%%%%%%%%%%%%%%%%%%%%%%%%%(
                    .%%%%%%%%%%% %/ %%%  % %% %% #%%%%%%%%%%
                 %%%%%%%*% *%//%. ( %%% %  %# %   (%%%%%%%/%%%%%
             .%%%%%%%,% %%% (( .%(%%%%%%%%%%%%#.%% %%%%( %%*#%%%%%%
           %%%%%( %%%%%%.,%%%%%%%%#(,       *#%%%%%%%%% %% %%/ %%%%%%*
         %%%%%#(% %%#%%%%%%#                        *%%%%%% ./.# #%%%%%(
       #%%%%# ,%%  #%%%#       *&&&&&&&&&&&&&&&&#.      ,%%%%  %%  %%%%%%/
     .%%%%%. #%% %%%%     ,&&&&&&&&&&&&&&&&&&&&&&&&&&&     ,%%% %%# %%%%%%%
    #%%%%  ****%%%#    /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.    %%%    ,#%%%%%.
   %%%%,/%%%%/%%%    &&&&&&&&&&&&%*           /&&&&&&&&&&&&/   .%%%%%*  #%%%%*
  #%%%,.(.% #%%/   /&&&&&&&&&%                    .&&&&&&&&&&.   %%,/% %.#%%%%,
 ,%%%%%%%%%#%%*   %&&&&&&&&*                         %&&&&&&&&(   #%(#(,  %%%%%
 %%%% %%%(.%%/   %&&&&&&&%                             &&&&&&&&*   %%%% *( %%%%#
 %%%%%(*. %%%   .&&&&&&&%                               &&&&&&&&   ,%%%%%%%%%%%%
(%%%%%%#, %%%   &&&&&&&&                                /&&&&&&&,   %% %./ /%%%%
%%%%( .( %%%(   &&&&&&&&       (%%%%%%    *%%%%%%.      ,&&&&&&&(   %%#*#%%%%%%%        // Karadeniz Technical University Logo
/%%%%%%%%%%%%   &&&&&&&&       #&&&&&&    *&&&&&&.      (&&&&&&&.   %%(//*, /%%%        // Object Oriented Programming Homework
 %%%%# ./ #%%   .&&&&&&&&      #&&&&&&    *&&&&&&.      &&&&&&&&   *% .*#% %%%%%
 %%%%/*% , %%#   %&&&&&&&&     #&&&&&&    *&&&&&&.    .&&&&&&&&.   %%%%%% /%%%%(
 .%%%%%%%%% %%/   %&&&&&&&&#   #&&&&&&    *&&&&&&.   &&&&&&&&&.   %% %.  *%%%%%
  (%%%%%# ( %%%#   *&&&&&&&&&&,#&&&&&&    *&&&&&&.(&&&&&&&&&&    %%%%#*% %%%%%
   (%%%%##%%%%%%%    (&&&&&&&&&&&&&&&&    *&&&&&&&&&&&&&&&&    *%./%*.%%%%%%%.
    *%%%%%%%%% %%%%    .&&&&&&&&&&&&&&    *&&&&&&&&&&&&&#    ,%#%%,(* #%%%%%
      %%%%%*.    %%%%,     #&&&&&&&&&&    *&&&&&&&&&&,     #%%%%%* (%%%%%%%
       (%%%%%*%%%%%%%%%%*       ,&&&&&    *&&&&(.       #%%%%%%%%%%%#%%%%
         #%%%%%%%%%%%%%%%%%%#                      .#%%%%%%%%%%%%%%%%%%,
           /%%%%%%%%%%%.%%%%%%%%%%%%##(/ /##%%%%%%%%%%%#*%%%%%%%%%%%%
              %%%%%%%%,, %%%%%%( (%%%#%%%%%(%/  /%%%%%% .#%%%%%%%%/
                 #%%%%%%%%%%%%%# %%,*% %(   %(,% #%%%%%%%%%%%%%,
                     (%%%%%%%%%%%%%*  #%%   %%%(%%%%%%%%%%%.
                           %%%%%%%%%%%%%%%%%%%%%%%%%%(   */


vector<string>teams;
vector<string>takimAdlari;
vector<string>directorAdlari;
string setTeamNick(int sayi);
void getTeamName();
void getDirector();
string fiksturMaclari[500];
void takimEkle(string takimAdi);
void takimlariOlustur();
void takimlariGetir();
void takimSil(string takimadi);
void takimgetir(string takmaAd);
void takimTumMaclar(string takimadi);
void fikstur();
void macOlustur(int id);


class futbolcu{

public:
    futbolcu(){
        setformaNo();
        setPerformans();
        setYas();
        setIsim();
        setSoyisim();
        setpozisyon();
    }

    void setformaNo(){
        formaNo = ((rand()+getpid()) % 99)+1;
    }
    int getformaNo(){
        return formaNo;
    }

    void setYas(){
        yas = (rand()+getpid())% (36-18+1) + 18;
    }
    int getYas(){
        return yas;
    }

    void setPerformans(int p=0){

        int perf = p;
        if(perf!=0){

            while(perf < 30 || perf > 100){
                cout << "oyuncu performans degerini yanlis girdiniz. ";
                if(perf < 30){
                    cout << "lutfen daha buyuk deger girin";
                    cin >> perf;
                }
                if(perf > 100){
                    cout << "lutfen daha kucuk bir deger girin";
                    cin >> perf;
                }
            }
            performans = perf;
        }
        else{
            performans = (rand()+getpid())% (100-30+1) + 30;
        }
    }
    int getPerformans(){
        return performans;
    }

    void setIsim(){
        string output;
        ifstream names("isimm.txt");
        for(int i = 0; i<((rand()+getpid()) % 100)+5;i++){
            getline(names,output);
        }
        isim = output;
    }
    string getIsim(){
        return isim;
    }

    void setSoyisim(){
        string output;
        ifstream names("soyisimm.txt");
        for(int i = 0; i<((rand()+getpid()) % 100)+5;i++){
            getline(names,output);
        }
        soyisim = output;
    }
    string getSoyisim(){
        return soyisim;
    }

    void setpozisyon(char a = 'K'){
        pozisyon = a;
    }
    char getpozisyon(){
        return pozisyon;
    }

    void getAll(){
        cout << "isim: " << getIsim();
        cout << "\nsoyisim: " << getSoyisim();
        cout << "\npozisyon: " << getpozisyon();
        cout << "\nyas: " << getYas();
        cout << "\nformano: " << getformaNo();
        cout << "\nperformans: " << getPerformans();
        cout << "\n\n";
    }

private:
    string isim;
    string soyisim;
    int yas;
    int formaNo;
    int performans;
    char pozisyon;
};


class takimlar{
public:
    takimlar(string tname="",string tid="",string tdirector="",int def=4, int ort = 4, int forv = 2){
        controlPerformance();
        controlAge();
        setPositions(def,ort,forv);
        setTeamName(tname);
        setTeamID(tid);
        setDirector(tdirector);
        setGol();
        setOrtalamaDefans(def);
        setOrtalamaForvet(def,ort,forv);
        setOrtalamaOrtasaha(def,ort);
        setOrtalamaKaleci();

    }


    void setGol(int a=-5){
        if(a==-5){
            gol=((rand()+getpid()) % 7)+0;
        }
        else if(a==0){
            gol=a;
        }
        else{
            gol+=a;
        }
    }

    int getGol(){
        return gol;
    }

    void setPerformansAgain(int k,string isim){
        for(int i=0;i<11;i++){
            string isimSoyisim = footballers[i].getIsim() + " " + footballers[i].getSoyisim();
            if(isim.compare(isimSoyisim)==0){
                footballers[i].setPerformans(k);
            }
        }
    }



    void setOrtalamaDefans(int d){
        ortD=0;
        for(int i=0;i<d;i++){
            ortD +=footballers[i].getPerformans();
        }
        ortD/=d;
    }

    int getOrtalamaDefans(){
        return ortD;
    }



    void setOrtalamaOrtasaha(int d,int o){
        ortO=0;
        for(int i=d;i<o+d;i++){
            ortO +=footballers[i].getPerformans();
        }
        ortO/=o;
    }

    int getOrtalamaOrtasaha(){
        return ortO;
    }



    void setOrtalamaForvet(int d,int o,int f){
        ortF=0;
        for(int i=o+d;i<10;i++){
            ortF +=footballers[i].getPerformans();
        }
        ortF/=f;
    }

    int getOrtalamaForvet(){
        return ortF;
    }

    void setOrtalamaKaleci(){
        ortK = footballers[10].getPerformans();
    }

    int getOrtalamaKaleci(){
        return ortK;
    }


    void setTeamName(string tname){
        teamName = tname;
    }
    string getTeamName(){
        return teamName;
    }

    void setTeamID(string tid){
        teamID = tid;
    }
    string getTeamID(){
        return teamID;
    }

    void setDirector(string tdirector){
        director = tdirector;
    }
    string getDirector(){
        return director;
    }

    void getAll(){
        cout << "TAKIM ADI: "<<getTeamName() << endl;
        cout << "TAKIM ID: " <<getTeamID() << endl;
        cout << "KOC: "<<getDirector() << endl;
        cout << "TAKIM ORTALAMA PERFORMANSI: " << controlPerformance() << endl;
        cout << "FUTBOLCULAR: " << endl;

        getFootballers();
    }

    void getFootballers(){
        for(int i=0;i<11;i++){
            footballers[i].getAll();
            cout << endl;
        }
    }

    futbolcu getFootballerbyOne(int i){
        return footballers[i];
    }

    void setPositions(int d,int o,int f){
        int k=0;
        for(int i=0;i<d;i++){
            footballers[k].setpozisyon('D');
            k++;
        }
        for(int i=0;i<o;i++){
            footballers[k].setpozisyon('O');
            k++;
        }
        for(int i=0;i<f;i++){
            footballers[k].setpozisyon('F');
            k++;
        }
    }

    int controlPerformance(){
        int ort=0;
        while(ort < 60){
            int total = 0;
            for(int i=0;i<11;i++){
                total += footballers[i].getPerformans();
            }
            ort = total / 11;
            if(ort < 60){
                for(int i=0;i<11;i++){
                    footballers[i].setPerformans();
                }
            }
        }
        return ort;
    }

    int controlAge(){
        int ort=0;
        while(ort < 25 || ort >32){
            int total =0;
            for(int i=0;i<11;i++){
                total += footballers[i].getYas();
            }
            ort = total /11;
            if(ort < 25 || ort >32){
                for(int i=0;i<11;i++){
                    footballers[i].setYas();
                }
            }
        }
        return ort;
    }

private:
    futbolcu footballers[11];
    string teamName;
    string teamID;
    string director;
    int gol;
    int ortD;
    int ortO;
    int ortF;
    int ortK;
};

class MacDiz{
public:
    MacDiz(takimlar t1,takimlar t2){
        team2 = t2;
        team1 = t1;
        yuzdeIlk = (team1.controlPerformance()*team2.controlPerformance())/100;
        yuzdeIkinci = 100-yuzdeIlk;
    }

    void macgetir(){
        cout <<"\n\n"<< team1.getTeamName() << "\t\t" << team2.getTeamName() << endl;
        cout << team1.getTeamID() << "\t\t\t" << team2.getTeamID() << endl;
        cout << team1.getDirector() << "\t\t" << team2.getDirector() << endl;

        cout << "\n\nFUTBOLCULAR:" << "\t\t" << "FUTBOLCULAR:\n\n"<<endl;

        for(int i=0;i<11;i++){
            cout << "isim: "<<team1.getFootballerbyOne(i).getIsim() << "\t\t" << "isim: " << team2.getFootballerbyOne(i).getIsim()<< endl;
            cout << "soyisim: "<<team1.getFootballerbyOne(i).getSoyisim() << "\t\t" << "soyisim: "<< team2.getFootballerbyOne(i).getSoyisim()<< endl;
            cout << "yas: "<<team1.getFootballerbyOne(i).getYas() << "\t\t\t" << "yas: "<< team2.getFootballerbyOne(i).getYas()<< endl;
            cout << "forma no: "<<team1.getFootballerbyOne(i).getformaNo() << "\t\t" << "forma no: "<< team2.getFootballerbyOne(i).getformaNo()<< endl;
            cout << "pozisyon: "<<team1.getFootballerbyOne(i).getpozisyon() << "\t\t" << "pozisyon: "<< team2.getFootballerbyOne(i).getpozisyon()<< endl;
            cout << "performans: " << team1.getFootballerbyOne(i).getPerformans() << "\t\t" << "performans: " << team2.getFootballerbyOne(i).getPerformans() << endl;
            cout << endl;
        }

        cout << "\n\ndefans ort: " << team1.getOrtalamaDefans() << "\t\t" << "defans ort: " <<team2.getOrtalamaDefans() << endl;
        cout << "ortasaha ort: " << team1.getOrtalamaOrtasaha() << "\t" << "ortasaha ort: " <<team2.getOrtalamaOrtasaha() << endl;
        cout << "forvet ort: " << team1.getOrtalamaForvet() << "\t\t" << "forvet ort: " <<team2.getOrtalamaForvet() << endl;
        cout << "kaleci ort: " << team1.getOrtalamaKaleci() << "\t\t" << "kaleci ort : " << team2.getOrtalamaKaleci() << endl;
        cout << "total ort:" << team1.controlPerformance() << "\t\t" << "total ort: " << team2.controlPerformance() << endl;
        cout << "\n\nkazanma yuzdesi: " << yuzdeIlk << "\t" << "kazanma yuzdesi: " << yuzdeIkinci << endl;
    }

    void skorHesapla(){
        cout << "\n\nBASLANGIC:\n" << team1.getTeamName()<<" gol degeri: " << team1.getGol() << endl;
        cout << team2.getTeamName()<<" gol degeri: " << team2.getGol() << endl;

        if(team1.getOrtalamaForvet() > team2.getOrtalamaForvet()){
            team1.setGol(1);
        }
        else if(team1.getOrtalamaForvet() < team2.getOrtalamaForvet()){
            team2.setGol(1);
        }

        if(team1.getOrtalamaOrtasaha() > team2.getOrtalamaOrtasaha()){
            team1.setGol(1);
            team2.setGol(-1);
        }
        else if(team1.getOrtalamaOrtasaha() < team2.getOrtalamaOrtasaha()){
            team2.setGol(1);
            team1.setGol(-1);
        }

        if(team1.getOrtalamaDefans() > team2.getOrtalamaDefans()){
            team2.setGol(-1);
        }
        else if(team1.getOrtalamaDefans() < team2.getOrtalamaDefans()){
            team1.setGol(-1);
        }


        if(team1.controlPerformance() > team2.controlPerformance()){
            int rsayi = ((rand()+getpid()) % 2)+0;
            if(rsayi==0){
                team1.setGol(1);
            }
            else{
               team2.setGol(-1);
            }
        }
        else if(team1.controlPerformance() < team2.controlPerformance()){
            int rsayi2 = ((rand()+getpid()) % 2)+0;
            if(rsayi2 == 0){
                team1.setGol(-1);
            }
            else{
                team2.setGol(1);
            }
        }

        if(team1.getGol()<0){
            team1.setGol(0);
        }
        if(team2.getGol()<0){
            team2.setGol(0);
        }

        cout << "\n\nSONUC:\n" << team1.getTeamName()<<" gol degeri: " << team1.getGol() << endl;
        cout << team2.getTeamName()<<" gol degeri: " << team2.getGol() << endl<< endl;
    }



private:
    int yuzdeIlk;
    int yuzdeIkinci;
    takimlar team1;
    takimlar team2;
};


int main(){
    takimlariOlustur();
    getTeamName();
    getDirector();


	int takimIslemi;
    cout << "[1] Takim ekle" << endl;
    cout << "[2] Takim listele" << endl;
    cout << "[3] Takim sil" << endl;
    cout << "[4] Fikstur olustur" << endl;
    cout << "[5] Takim cagir" << endl;
    cout << "[-1] Cikis yap" << endl;
	cin >> takimIslemi;

	while(takimIslemi != -1){
        switch (takimIslemi) {
        case 1:
        {
            string takimadi,teknikdirektoradi,birlestirilmis;
            cout << "eklemek istediginiz takim adini girin: ";
            cin >> takimadi;
            takimAdlari.push_back(takimadi);
            cout << "\nteknik direktor adini girin: ";
            cin.ignore();
            getline(cin,teknikdirektoradi);
            directorAdlari.push_back(teknikdirektoradi);
            birlestirilmis = takimadi + " - " +teknikdirektoradi;
            takimEkle(birlestirilmis);
            break;
        }

        case 2:
        {
            takimlariGetir();
            break;
        }
        case 3:
        {
             string silinecekTakim;
             cout<<"Silmek istediginiz takimin takma adini giriniz.(BUYUK KUCUK HARF UYUMU VARDIR)\n" << endl;
             cin >> silinecekTakim;
             takimSil(silinecekTakim);
            break;
        }
        case 4:
        {
            fikstur();
            int controller;
            cout << "Bir takimin tum maclarini gormek icin 1, id ye gore mac getirmek icin 2, ana menuye donmek icin 0 a basin: ";
            cin >> controller;
            if(controller==1){
                string takimName;
                cout << "\ntakim adi girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                cin >> takimName;
                takimTumMaclar(takimName);
            }
            else if(controller == 2){
                int id;
                cout << "gormek istediginiz macin id'sini giriniz: ";
                cin >> id;
                macOlustur(id);
            }
            break;
        }

        case 5:
            {
                string takmaAd;
                cout << "Lutfen takim takma adini girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                cin >> takmaAd;
                takimgetir(takmaAd);
                break;
            }
        default:
        {
            cout << "Gecerli bir sayi giriniz.(1,2,3,4,5,-1)" << endl;
            break;
        }
    }

    cout << "[1] Takim ekle" << endl;
    cout << "[2] Takim listele" << endl;
    cout << "[3] Takim sil" << endl;
    cout << "[4] Fikstur olustur" << endl;
    cout << "[5] Takim cagir" << endl;
    cout << "[-1] Cikis yap" << endl;
	cin >> takimIslemi;

	}

	system("Pause");
	return 0;
}

void macOlustur(int id){
    int d=4,o=4,f=2,controller;
    int index;
    int index2;
    string ilktakim = fiksturMaclari[id].substr(fiksturMaclari[id].find(">")+1,3);
    string ikincitakim = fiksturMaclari[id].substr(fiksturMaclari[id].find("-")+2,3);
    for(int i=0;i<takimAdlari.size();i++){
        if(takimAdlari[i].substr(0,3).compare(ilktakim)==0){
            index = i;
        }
        if(takimAdlari[i].substr(0,3).compare(ikincitakim)==0){
            index2 = i;
        }
    }

    cout << "ilk takim ici pozisyon degerlerini elle girmek icin 1, default parametreleri aktarmak icin(4-4-2) 0 a basin: ";
    cin >> controller;

    if(controller==1){
        cout << "defans degerini girin: ";
        cin >> d;
        cout << "ortasaha degerini girin: ";
        cin >> o;
        cout << "forvet degerini girin: ";
        cin >> f;
    }
    takimlar t1(takimAdlari[index],setTeamNick(index),directorAdlari[index],d,o,f);
    d=4;o=4;f=2;

    cout << "ikinci takim ici pozisyon degerlerini elle girmek icin 1, default parametreleri aktarmak icin(4-4-2) 0 a basin: ";
    cin >> controller;

    if(controller==1){
        cout << "defans degerini girin: ";
        cin >> d;
        cout << "ortasaha degerini girin: ";
        cin >> o;
        cout << "forvet degerini girin: ";
        cin >> f;
    }
    takimlar t2(takimAdlari[index2],setTeamNick(index2),directorAdlari[index2],d,o,f);
    MacDiz mac(t1,t2);
    mac.macgetir();
    mac.skorHesapla();
}

string setTeamNick(int sayi){
    string first = (teams.at(sayi).substr(0,3));
    string second  = (teams.at(sayi).substr(0,2));

    for(int k=0;k<sayi;k++){
        if((teams.at(k).substr(0,2)).compare(second) == 0){
            return first;
        }
    }
        return second;
}

void getTeamName(){
    for(int i=0;i<teams.size();i++){
        string c = teams[i];
        string takimAdi = c.substr(0,c.find("-"));
        takimAdlari.push_back(takimAdi);
    }
}

void getDirector(){
    for(int i=0;i<teams.size();i++){
        string a = teams[i];
        string directorName = a.substr(a.find("-")+1);
        directorAdlari.push_back(directorName);
    }
}

void takimEkle(string takimAdi){
    ofstream writeFile("SuperLig.txt", ios::app);
    writeFile << takimAdi << endl;
    teams.push_back(takimAdi);
    writeFile.close();
}

void takimlariOlustur(){
    string mytext;
    ifstream myfile;
    myfile.open("SuperLig.txt");
    while (getline(myfile, mytext)) {
        teams.push_back(mytext);
    }
    myfile.close();
}

void takimlariGetir(){
    for(int i=0;i<teams.size();i++){
        cout <<teams.at(i) << "  --->  " << setTeamNick(i) +"\n";
    }
}

void takimSil(string takimadi){
    string tAdi;

    if(takimadi.length() == 2){
        for(int i=0; i<teams.size();i++){
            if(teams.at(i).substr(0,2).compare(takimadi)== 0){
                teams.erase(teams.begin()+i);
                takimAdlari.erase(takimAdlari.begin()+i);
                directorAdlari.erase(directorAdlari.begin()+i);
            }
        }
    }
    else if(takimadi.length()==3){
        for(int i=0; i<teams.size();i++){
            if(teams.at(i).substr(0,3).compare(takimadi)== 0){
                teams.erase(teams.begin()+i);
                takimAdlari.erase(takimAdlari.begin()+i);
                directorAdlari.erase(directorAdlari.begin()+i);
            }
        }
    }
    else{
        cout << "lutfen gecerli bir takma ad girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
        cin >> tAdi;
        takimSil(tAdi);
    }
}


void takimgetir(string takmaAd){
    string tAd = takmaAd;
    int k,d=4,o=4,f=2,controller;
    string isim;
    string soyisim;
    string birlestirilmis;
    int performans;

    cout << "pozisyon degerlerini elle girmek icin 1, default parametreleri aktarmak icin(4-4-2) 0 a basin: ";
    cin >> controller;

    if(controller==1){
        cout << "defans degerini girin: ";
        cin >> d;
        cout << "ortasaha degerini girin: ";
        cin >> o;
        cout << "forvet degerini girin: ";
        cin >> f;
    }


    if(tAd.length() == 3){
        for(int i=0;i<takimAdlari.size();i++){
            if((takimAdlari.at(i).substr(0,3)).compare(tAd) == 0){
                takimlar tr(takimAdlari.at(i),tAd,directorAdlari.at(i),d,o,f);
                tr.getAll();
                cout << "bir futbolcunun performansini yeniden belirlemek icin 1,ana menuye donmek icin 0 a basin: ";
                cin >> k;
                while(k==1){
                    cout << "futbolcu adini girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                    cin >> isim;
                    cout << "\nfutbolcu soyadini girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                    cin >> soyisim;
                    cout << "\nyeni performans degeri girin: ";
                    cin >> performans;
                    birlestirilmis = isim + " " + soyisim;
                    tr.setPerformansAgain(performans,birlestirilmis);
                    cout << "performans degeri yeniden belirlendikten sonra futbolcu bilgileri: ";
                    tr.getAll();
                    cout << "bir futbolcunun performansini yeniden belirlemek icin 1,ana menuye donmek icin 0 a basin: ";
                    cin >> k;
                }
            }
        }
    }
    else if(tAd.length() == 2){
        for(int i=0;i<takimAdlari.size();i++){
            if((takimAdlari.at(i).substr(0,2)).compare(tAd) == 0){
                takimlar tr(takimAdlari.at(i),tAd,directorAdlari.at(i),d,o,f);
                tr.getAll();
                cout << "bir futbolcunun performansini yeniden belirlemek icin 1,ana menuye donmek icin 0 a basin: ";
                cin >> k;
                while(k==1){
                    cout << "futbolcu adini girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                    cin >> isim;
                    cout << "\nfutbolcu soyadini girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
                    cin >> soyisim;
                    cout << "\nyeni performans degeri girin: ";
                    cin >> performans;
                    birlestirilmis = isim + " " + soyisim;
                    tr.setPerformansAgain(performans,birlestirilmis);
                    cout << "performans degeri yeniden belirlendikten sonra futbolcu bilgileri: ";
                    tr.getAll();
                    cout << "bir futbolcunun performansini yeniden belirlemek icin 1,ana menuye donmek icin 0 a basin: ";
                    cin >> k;
                }
            }
        }
    }
    else{
        cout << "lutfen gecerli bir takma ad girin:(BUYUK KUCUK HARF UYUMU VARDIR) ";
        cin >> tAd;
        takimgetir(tAd);
    }
}

void takimTumMaclar(string takimadi){
    for(int i=0;i<300;i++){
        if(fiksturMaclari[i].find(takimadi) != -1){
            cout << fiksturMaclari[i] << endl;
        }
        else{
            continue;
        }
    }
}

void fikstur(){
    vector<string>yeniTakimAdlari = takimAdlari;
    static int controller=0;
    string sabitTakim= yeniTakimAdlari[0];
    string allTeam;
    int id = 0;
    for(int i=0;i<yeniTakimAdlari.size();i++){
        id++;
        allTeam=yeniTakimAdlari[i];
            if(yeniTakimAdlari.at(0) == sabitTakim){
                yeniTakimAdlari.erase(yeniTakimAdlari.begin()+0); //ilk indisi silme
            }
            controller++;

    }
    cout<<"\n\n";

    int sayac = 0;
    int hafta = 0;

    for(int i=0;i<yeniTakimAdlari.size();i++){
        string last = yeniTakimAdlari[yeniTakimAdlari.size()-1];
        hafta++;
        sayac++;
        cout<<hafta<<". hafta"<<endl;
        cout<< "macID:"<<sayac<<">"<<sabitTakim <<" - " << yeniTakimAdlari[0]<<endl;
        string sayacStr = to_string(sayac);
        fiksturMaclari[sayac] = "macID:"+sayacStr+">"+sabitTakim +" - " + yeniTakimAdlari[0];

        for(int j=0;j< (yeniTakimAdlari.size()-1)/2;j++){
            sayac++;
            cout<<"macID:"<<sayac<<">"<<yeniTakimAdlari[j+1] << " - " << yeniTakimAdlari[(yeniTakimAdlari.size()-1)-j];
            cout<<endl;

            string sayacStr = to_string(sayac);
            fiksturMaclari[sayac] = "macID:"+sayacStr+">"+yeniTakimAdlari[j+1] +" - " + yeniTakimAdlari[(yeniTakimAdlari.size()-1)-j];

        }
        for(int k=yeniTakimAdlari.size()-1;k>0;k--){
            yeniTakimAdlari[k] = yeniTakimAdlari[k-1];
        }
        yeniTakimAdlari[0]= last;

    }
}
