#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	int soru_sayisi=10,ogrenci_sayisi,ogrenci_numarasi,puan,toplam=0,ortalama=0,max,maxpuan,minpuan,medyan,range;
	char cevap_anahtari[10]={'A','C','B','A','E','D','D','A','E','C'};
	char ogrencinin_cevaplari[10];
	
	ofstream sinav;
	sinav.open ("input.txt",ios::out);
	sinav << soru_sayisi << endl;
	
	for(int i=0;i<10;i++){
		sinav << cevap_anahtari[i] << ",";
	}
	cout << "ogrenci sayisini giriniz:" << endl;
	cin >> ogrenci_sayisi;
	
	if(ogrenci_sayisi<100){
		for(int i=1;i<=ogrenci_sayisi;i++){
			cout << "ogrencinin numarasini giriniz = ";
			cin >> ogrenci_numarasi ;
			for(int j=0;j<10;j++){
				cout << j+1 << ".nci soru = ";
				cin >> ogrencinin_cevaplari[j];
			}
			sinav << endl << ogrenci_numarasi << ",";
			
			for(int j=0;j<10;j++){
				sinav << ogrencinin_cevaplari[j] << ",";
			}
			
			for(int i=0;i<10;i++){
				if(ogrencinin_cevaplari[i]==cevap_anahtari[i]){
					puan+=4;
				}
				else if(ogrencinin_cevaplari[i]!=cevap_anahtari[i]){
					puan-=1;
				}
				else if(ogrencinin_cevaplari[i]==0){
					puan+=0;
				}
			
			}
			if(puan<=0){
				puan=0;
			}
			puan*=2.5;
			cout << "puan = " << puan << endl;
			toplam+=puan;
			puan=0;
		}
	}
	else{
		cout << "gecersiz sayi girisi.(bir sinifin maksimum ogrenci sayisi 100 olacaktir)";
	}
	cout << "en yuksek puan = " << maxpuan << endl; 
	cout << "en dusuk puan = " << minpuan << endl;
	ortalama = toplam/ogrenci_sayisi;
	cout << "ortalama = " << ortalama << endl;
	sinav << endl << "EN YUKSEK PUAN = " << maxpuan;
	sinav << endl << "EN DUSUK PUAN = " << minpuan;
	sinav << endl << "ORTALAMA = " << ortalama;
	sinav << endl << "MEDYAN = " << medyan;
	sinav << endl << "ACIKLIK-RANGE = " << range;
	sinav.close();
	
	return 0;
}
