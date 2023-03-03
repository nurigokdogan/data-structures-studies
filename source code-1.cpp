// Bir yığıta, eleman ekleme, eleman sileme ve listeleme işlemlerini switch-case yapısını kullanarak bir menü üzerinden yapan bir  C program

#include<stdio.h>
#define BOYUT 100

int dizi[BOYUT], top;

void push(int veri){
	if(top+1==BOYUT){
		printf("stack dolu");
	}
	else{
		top = top +1;
		dizi[top]=veri;
	}
}

void pop(){
	if(top == -1){
		printf("stack zaten bos");
	}
	else{
		top = top -1;
	}
	
}

int peek(){
	return dizi[top];
	}
	
	void yazdir(){
	for(int i=0; i<top+1; i++){
	printf("%d ", dizi[i]);
	}
	printf("==> TOP");
	}
	
	
	
	int main(){
		int secim;
		top = -1;
		while(1==1){
		
		printf("\n1-Push");
		printf("\n2- Pop");
		printf("\n3- Peek");
		printf("\nSecim yapiniz..");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("sayi giriniz..");
				scanf("%d", &secim);
				push(secim);
				yazdir();
				break;
			case 2:
				pop();
				yazdir();
				break;
			case 3:
				peek();
				yazdir();
				break;	
			}
		}
		return 0;
	}
