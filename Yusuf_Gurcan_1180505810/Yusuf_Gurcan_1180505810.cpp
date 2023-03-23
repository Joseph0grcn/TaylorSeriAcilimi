// Yusuf_Gurcan_1180505810.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
#include <math.h>
using namespace std;

//# Soru: F(x) = 0.75x^5 – 2x^3 + 1;
/*
Yukarýda verilen f(x) fonksiyonunun Taylor Seri açýlýmýný aþaðýda verilen yönergeye göre gerçekleþtiren bir C/C++ programý yazýnýz.
• Serideki terim sayýsý kullanýcýdan alýnacaktýr. Aralýk deðeri: [3, 8]
• Seri açýlýmdaki x0 deðeri kullanýcýdan alýnacaktýr. Aralýk deðeri: [-2, 2]
• Seri açýlýmdaki x deðeri kullanýcýdan alýnacaktýr. Aralýk deðeri: [-4, 4]
• Seri açýlým gerçekleþtirildikten sonra kullanýcýdan alýnan x deðeri seride yerine yazýlacak ve oluþan y/f(x) deðeri
kullanýcýya bildirilecektir.
*/
double terim_1(double x0) {
	double sonuc;
	double x01 = x0, x02 = x0;
	sonuc = 0.75 * pow(x01, 5) - 2 * pow(x02, 3) + 1;
	return sonuc;
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

double rpart(double x, double x0, int n) {
	//terimin sað kýsmý (x-x0)^n/n!
	return pow((x - x0), n) / factorial(n);
}

double lpart(double x0,int n) {
	//terimin sol kýsmý türev alma
	//F(x) = 0.75x^5 – 2x^3 + 1 ; türevini n . türevini alýp içine x0 koyup returnliyecez
	int n1 = 5, n2 = 3; 
	int nc1 = 1, nc2 = 1;
	double x01 = x0, x02 = x0;
	for (int i = 0; i < n; i++)
	{
		if (n1>0) {
			nc1 = nc1* n1;
			n1--;
		}
		else if (n1==0) {
			nc1 *= n1;
		}

		if (n2>0) {
			nc2 = nc2 * n2;
			n2--;
		}
		else if (n2==0) {
			nc2 *= n2;
		}
	}
	//F(x) = 0.75x^5 – 2x^3 
	double sonuc;
	sonuc = 0.75 * pow(x01, n1) * nc1 - 2 * pow(x02, n2) * nc2;
	return sonuc;
}

double tamýslem(double x0,double x,int terim) {
	double sonuc;
	sonuc = terim_1(x0);
	for (int i = 1; i < terim; i++)
	{ //ilk terim f(x0) a eþit olduðundan dolayý 2. terimden itibaren bu for döngüsü çalýþmaktadýr
		sonuc+=(lpart(x0,i)*rpart(x, x0, i));
		
	}
	return sonuc;
}

int main()
{	//x0>>terim>>x
	int terim;
	double x,x0,sonuc;
    
	cout << "Soru: F(x) = 0.75x^5 – 2x^3 + 1";

	do
	{
		
		cout << "YUKARIDA VERILEN FONKSIYONU TAYLOR SERI ACILIMI ICIN X0 DEGERINI [-2,2] ARALIGI ICINDE GIRINIZ :";
		cin >> x0;
		if ((x0 > 2 || x0 < -2))
		{
			cout << "LUTFEN BELIRTILEN DEGERLER ARASINDA BIR SAYI GIRINIZ\n";
		}

	} while (x0 > 2 || x0 < -2);

	do
	{
		
		cout << "TAYLOR SERI ACILIMINDA OLMASI GEREKEN TERIM SAYISINI [3 , 8] ARALIGI ICIN GIRINIZ :";
		cin >> terim;
		if (terim > 8 || terim < 3) {
			cout << "LUTFEN BELIRTILEN DEGERLER ARASINDA BIR TAM SAYI GIRINIZ\n";
		}

	} while (terim > 8 || terim < 3);

	do
	{
		
		cout << "TAYLOR SERI ACILIMINDA HESAPLANACAK X DEGERINI [-4,4] ARALIGI ICINDE GIRINIZ :";
		cin >> x;
		if (x > 4 && x < -4) {
			cout << "LUTFEN BELIRTILEN DEGERLER ARASINDA BIR SAYI GIRINIZ\n";
		}

	} while (x > 4 || x < -4);

	/*
	// F(x)= f(x0)*(x-x0)^n/n!   +    f'(x0)*(x-x0)^n/n!  +  f''(x0)*(x-x0)^n/n!
	*/

	sonuc=tamýslem(x0, x, terim);

	cout << "x=" << x << " ICIN FONKSIYON SONUCU="<<sonuc;
	
	

}


