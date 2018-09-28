#include<stdio.h>
#include<math.h>

//sml3
// Gökay AY
// 1306160093



//e^x fonksiyonu
double f(double x){
  return exp(x);
}



//trapezoidal metodu
double trapezoidal(double f(double x), double x0, double x1, int n){

    double x,length,sum=0,integral;
    int i;
    length=fabs(x1-x0)/n;

    for(i=1;i<n;i++){
        x=x0+i*length;
        sum=sum+f(x);
    }

    integral=(length/2)*(f(x0)+f(x1)+2*sum);
    return integral;
}

double simpsons13(double f(double x),double x0, double x1){

      int sayac = 0, deger;

      double x[1000], y[1000], hatapayi, m = 0, n = 0, sonuc;

      printf("\nSimpsons1-3 kurali icin hata payi giriniz: ");
      scanf("%lf", &hatapayi);
      deger = (x1 - x0) / hatapayi;
      if(deger % 2 == 1)
      {
            deger = deger + 1;
      }

      hatapayi = (x1 - x0) / deger;

      while(sayac <= deger)
      {
            x[sayac] = x0 + sayac * hatapayi;
            y[sayac] = f(x[sayac]);
            sayac++;
      }
      sayac = 1;
      while(sayac < deger)
      {
            if(sayac % 2 == 1)
            {
                  m = m + y[sayac];
            }
            else
            {
                  n = n + y[sayac];
            }
            sayac++;
      }
      sonuc = hatapayi / 3 * (y[0] + y[deger] + 4 * m + 2 * n);
      printf("\n\nSimpson kurali integrali %d adimda bu sekilde buldu: %lf\n",sayac, sonuc);
      return 0;
}

double simpsons38(double f(double x),double x0, double x1){

    double hatapayi,h,sum,abc;
    int i,j;
    sum=0;
    printf("Simpsons3-8 kurali icin hata payini giriniz (3 ve 3'un katlari olmalidir): ");
    scanf("%lf",&hatapayi);
    h = (x1-x0)/hatapayi;
    sum = f(x0)+f(x1);

    for(i=1;i<hatapayi;i++)
    {
        if(i%3==0){
            sum=sum+2*f(x0+i*h);
        }
        else{
            sum=sum+3*f(x0+i*h);
        }
        }
        abc=(3*h/8)*sum;

    printf("Simpsons3-8 kuralina gore integral budur :  %lf\n", abc);


}

double boole(double f(double x),double x0, double x1){

    double hatapayi,h,sum,abc;

    printf("\nBoole kurali icin adim sayisini giriniz:");
    scanf("%lf",&hatapayi);

    sum=7*f(x0);
    h = (x1 - x0)/(hatapayi+150); //

    int modAlma;
    int i =1;

    while (i<hatapayi+150)
    {
      modAlma = i%4;
      if (modAlma==0)
        sum+=14*f(x0+i*h);
      else if (modAlma==1)
        sum+=32*f(x0+i*h);
      else if (modAlma==2)
        sum+=12*f(x0+i*h);
      else
        sum+=32*f(x0+i*h);
      ++i;
    }
    abc= 2* h/45 * sum;

    printf("Boole kuralina gore integral budur : %lf\n",abc);

}

main(){
    int n,i=2;
    double x0,x1,length,hatapayi,sum=0,integral,olusanIntegral;

    printf("e^x fonksiyonu icin integral araliklarini belirtiniz\n");
    printf("\nAlt siniri belirtin: ");
    scanf("%lf",&x0);
    printf("\nUst siniri belirtin: ");
    scanf("%lf",&x1);

    printf("\n\n*************************************************\n\n");

    printf("\nTrapezoidal icin hata payini belirtin: ");
    scanf("%lf",&hatapayi);




    olusanIntegral=trapezoidal(f,x0,x1,i);

//hata payindan büyük olana kadar adim sayisini ilerlet

  while(fabs(olusanIntegral-integral)>=hatapayi){

    integral=olusanIntegral;
    i++;
    olusanIntegral=trapezoidal(f,x0,x1,i);
  }


      printf("Integral  %d adimda bu sekilde bulundu: \n %lf \n ",i,olusanIntegral);

      printf("\n\n*************************************************\n\n");

 //programlar ayrı olarak oluşturulmuştu, onun için daha sonradan simpsons1/3-3/8 ve boole fonksiyonları bu trapezoidal c programına dahil edildi!!!

      simpsons13(f,x0,x1);

      printf("\n\n*************************************************\n\n");

      simpsons38(f,x0,x1);

      printf("\n\n*************************************************\n\n");

      boole(f,x0,x1);
}
