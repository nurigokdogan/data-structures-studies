// nxn boyutunda A ve B isimli iki matrisi tek boyutlu diziye atayarak bunların çarpımını yapan  ve sonucu ekrana yazdıran C programı 
// A ve B matrisleri “matrisler.txt” isimli bir text dosyadan okunacaktır. Sonuç da yine “sonuc.txt” isimli bir text dosyaya yazdırılacaktır.



#include <stdio.h>


int main() {
	FILE* dosya1, * dosya2;
	int satirA, sutunA, satirB, sutunB;
	int i, j, k;
	dosya1 = fopen("matrisler.txt", "r");
	if (dosya1 != NULL) {
		fscanf(dosya1, "%d", &satirA);
		fscanf(dosya1, "%d", &sutunA);
		int matrisA[satirA][sutunA];
		int diziA[satirA * sutunA];
		int indexA = 0;
		for (i = 0; i < satirA; i++) {
			for (j = 0; j < sutunA; j++) {
				fscanf(dosya1, "%d", &matrisA[i][j]);
				diziA[indexA] = matrisA[i][j];
				printf("%d", diziA[indexA]);
				indexA++;
			}
		}
		printf("\n");
		fscanf(dosya1, "%d", &satirB);
		fscanf(dosya1, "%d", &sutunB);
		int matrisB[satirB][sutunB];
		int diziB[satirB * sutunB];
		int indexB = 0;
		for (i = 0; i < satirB; i++) {
			for (j = 0; j < sutunB; j++) {
				fscanf(dosya1, "%d", &matrisB[i][j]);
				diziB[indexB] = matrisB[i][j];

				printf("%d", diziB[indexB]);
				indexB++;
			}
	 	}
		printf("\n");
		int matrisCarpimi[satirA][sutunB];
		int toplam = 0;
		dosya2 = fopen("sonuc.txt", "w");
		for (i = 0; i < satirA; i++) {
			for (j = 0; j < sutunB; j++) {
				for (k = 0; k < sutunA; k++) {
					toplam += diziA[i * sutunA + k] * diziB[k * sutunB + j];
				}
				matrisCarpimi[i][j] = toplam;
				toplam = 0;
				printf("%d\t", matrisCarpimi[i][j]);
				fprintf(dosya2, "%d\t", matrisCarpimi[i][j]);
			}
			fprintf(dosya2, "\n", matrisCarpimi[i][j]);
			printf("\n");
		}

	}
	fclose(dosya2);
	fclose(dosya1);
	
	return 0;
}
