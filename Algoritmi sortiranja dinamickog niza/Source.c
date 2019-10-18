//Branislav Stojanovic
//Broj indeksa 79/18

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Rastuce 1
#define Opadajuce 0

//SPECIFIKACIJA FUNKCIJA

//Dinamciki niz
void prikazNiza(int* niz, int n);
void ubaciElement(int** niz, int broj, int* brojElemenata, int* kapacitet);
void unosDinamickogNiza(int** niz, int* brojElemenata, int* kapacitet);

//Opste funkcije
void zamena(int* a, int* b);
void prikazNiza(int* niz, int n);
int meni();
int izborPoretka();

//BubbleSort
void BubbleSort(int* niz, int n);
void prikazNizaBubbleSort(int* niz, int n, int poz);

//Insertion srot
void InsertionSort(int* niz, int n);
void ubaciElementSaJednePozNaDrugu(int* niz, int n, int poz1, int poz2);
void prikazNizaInsertionSort(int* niz, int n, int a, int b);

//Selection sort
void SelectionSort(int* niz, int n);
int pozicijaMinMaxElementa(int* niz, int n, int poz, int poredak);
void prikazNizaSelectionSort(int* niz, int n, int minPoz, int poz);

//Radix sort
void RadixSort(int* niz, int n);
int brojCifaraNajvecegBrojaUNizu(int* niz, int n);
int NtaCifraBroja(int broj, int n);
void prikazNizaRadixSort(int* niz, int n, int cifra);
void zaokruziNtuCifruBroja(int n, int cifra);

//Merge sort
void MergeSort(int niz[], int l, int d, int poredak);
void spoji(int niz[], int levi, int sredina, int desni, int poredak);
void prikazNizaMerge(int niz[], int l, int d);

//Quick sort
void QuickSort(int niz[], int prvi, int poslednji, int poredak);
int podeli(int niz[], int prvi, int poslednji, int poredak);
void prikazNizaQuickSort(int niz[], int n, int pivot);

//GLAVNA FUNKCIJA
int main(void) {

	int* niz = NULL;  //Pocetna adresa niza
	int kapacitet = 0; //Pocetni kapacitet niza
	int n = 0;			  //Pocetan broj elemenata niza


	int poredak;

	int izbor = 1;
	do
	{

		switch (izbor)
		{
		case 1:
			niz = NULL;
			kapacitet = 0;
			n = 0;
			printf("UNOS DINAMICKOG NIZA\n\n");
			unosDinamickogNiza(&niz, &n, &kapacitet);
			break;
		case 2:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("INSERTION SORT\n");
			InsertionSort(niz, n);
			break;
		case 3:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("SELECTION SORT\n");
			SelectionSort(niz, n);
			break;
		case 4:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("BUBBLE SORT\n");
			BubbleSort(niz, n);
			break;
		case 5:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("RADIX SORT\n");
			RadixSort(niz, n);
			break;
		case 6:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("MERGE SORT\n");
			poredak = izborPoretka();
			MergeSort(niz, 0, n - 1, poredak);
			printf("NIZ JE SORTIRAN\n");
			prikazNiza(niz, n);
			break;
		case 7:
			printf("Uneti niz:"); prikazNiza(niz, n);
			printf("QUICK SORT\n");
			poredak = izborPoretka();
			printf("\nZa pivota se uzima poslednji broj ozacen sa [n]\n\n");
			QuickSort(niz, 0, n - 1, poredak);
			printf("NIZ JE SORTIRAN\n");
			prikazNiza(niz, n);
			break;
		case 0:
			break;
		default:
			printf("Pogresan izbor, pokusajte ponovo\n");
			break;
		}
		system("pause");
		system("cls");
		printf("Uneti niz:"); prikazNiza(niz, n);
		izbor = meni();
		system("cls");
	} while (izbor != 0);

	printf("KRAJ PROGRAMA\n");
	system("pause");
	return 0;
}

//IMPLEMENTACIJA FUNKCIJA

//Dinamciki niz
void ubaciElement(int** niz, int broj, int* brojElemenata, int* kapacitet) {
	/* Ako je broj elemenata >= od trenutnog kapaciteta
	realociraj memoriju niza tako sto ce sada biti rezervisana memorija koja je za 4 bajta veca( sizeof(int) )
	Kapacitet se takodje povecao za jedan*/
	if (*niz == NULL) {
		*niz = malloc(sizeof(int));
		(*kapacitet)++;
	}
	else if (*brojElemenata >= *kapacitet) {
		*niz = realloc(*niz, (*brojElemenata) * sizeof(int) + sizeof(int));
		//Ukoliko je doslo do greske prilikom realociranja 
		if (*niz == NULL) {
			printf("Greska pri ponovnoj alokaciji memorije\n");
			return 0;
		}

		*kapacitet = *brojElemenata + 1;
	}

	*((*niz) + *brojElemenata) = broj; //Dodeljivanje vrednosti
	(*brojElemenata)++; //Povecavanje broja elemenata za 1

}
void unosDinamickogNiza(int** niz, int* brojElemenata, int* kapacitet) {
	int izbor = 1;
	int element;
	do {
		switch (izbor)
		{
		case 1:
			printf("Unesite %d. element: ", *brojElemenata + 1);
			scanf("%d", &element);
			ubaciElement(niz, element, brojElemenata, kapacitet);
			break;
		case 2:
			break;
		default:
			printf("\nPogresan izbor, pokusajte ponovo\n\n");
			break;
		}
		printf("\nDa li zelite da unesete jos elemenata?\n1. Da\n2. Ne\nVas izbor: ");
		scanf("%d", &izbor);
		printf("\n");
	} while (izbor != 2);
}

//Opste funkcije
void prikazNiza(int* niz, int n) {
	printf("  ");
	for (int i = 0;i < n;i++) {
		printf("%d  ", niz[i]);
	}
	printf("\n\n");
}
void zamena(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int meni() {
	int izbor;
	printf("\
============\n\
||  MENI  ||\n\
============\n");
	printf("\
1. Unos dinamickog niza\n\
2. Insertion sort\n\
3. Selection sort\n\
4. Bubble sort\n\
5. Radix sort\n\
6. Merge sort\n\
7. Quick sort\n\
0. Kraj rada\n");
	printf("Vas izbor: ");
	scanf("%d", &izbor);
	return izbor;
}
int izborPoretka() {
	int izbor;
	printf("\
1. Sortiraj rastuce\n\
2. Sortiraj opadajuce\n");
	printf("Vas izbor: ");
	scanf("%d", &izbor);
	getchar();
	printf("\n");
	if (izbor == 1)return Rastuce;
	else if (izbor == 2)return Opadajuce;
	else {
		printf("Izabrana opcija ne postoji, pokusajte ponovo\n");
		return izborPoretka();
	}
}

//BubbleSort
void BubbleSort(int* niz, int n) {
	int ponovo;
	int prolaz = 0;
	int poredak = izborPoretka();
	do {
		prolaz++;
		ponovo = 0;
		printf("\nPROLAZ %d\n", prolaz);
		printf("---------\n");

		for (int i = 0;i < n - 1;i++) {
			prikazNizaBubbleSort(niz, n, i);
			if (poredak == Rastuce ? niz[i] > niz[i + 1]:niz[i] < niz[i + 1]) {
				zamena(&niz[i], &niz[i + 1]);
				ponovo = 1;
				printf(" - Zamena %d i %d ---> ", niz[i], niz[i + 1]);
				prikazNizaBubbleSort(niz, n, i);
			}
			else {
				printf(" - Nema zamene ----> ");
				prikazNizaBubbleSort(niz, n, i);
			}
			printf("\n\n");
		}
	} while (ponovo);
	printf("NIZ JE SORTIRAN!\n");
	prikazNiza(niz, n);
}
void prikazNizaBubbleSort(int* niz, int n, int poz) {
	printf("  ");
	for (int i = 0;i < n;i++) {
		if (i == poz || i == poz + 1) {
			printf("[%d]  ", niz[i]);
			continue;
		}
		printf("%d  ", niz[i]);
	}
}

//Insertion srot
void InsertionSort(int* niz, int n) {
	int poredak = izborPoretka();
	int i, j, k;
	int b = 0;
	for (i = 1;i < n;i++) {
		b = 0;
		prikazNizaInsertionSort(niz, n, i, b);
		for (j = 0;j < i;j++) {
			if (poredak == Rastuce ? niz[i]<niz[j] : niz[i]>niz[j]) {
				ubaciElementSaJednePozNaDrugu(niz, n, i, j);
			}
		}
		b = 1;
		prikazNizaInsertionSort(niz, n, i, b);
		printf("\n\n");
	}
	printf("NIZ JE SORTIRAN!\n");
	prikazNiza(niz, n);
}
void ubaciElementSaJednePozNaDrugu(int* niz, int n, int poz1, int poz2) {
	int broj = niz[poz1];

	for (int i = poz1;i > poz2;i--) {
		niz[i] = niz[i - 1];
	}

	niz[poz2] = broj;
}
void prikazNizaInsertionSort(int* niz, int n, int a, int b) {
	printf("  ");
	for (int i = 0;i < n;i++) {
		if (i == a && b == 0) {
			printf("|  [%d]  ", niz[i]);
		}
		else if (i == a && b == 1) {
			printf("%d  |  ", niz[i]);
		}
		else {
			printf("%d  ", niz[i]);
		}
	}
	printf("\n\n");
}

//Selection sort
void SelectionSort(int* niz, int n) {
	int poredak = izborPoretka();
	int poz = 0; //Pozicija najveceg/najmanjeg elementa (u zavisnosti od izbora poretka)
	for (int i = 0;i < n;i++) {
		poz = pozicijaMinMaxElementa(niz, n, i, poredak);
		prikazNizaSelectionSort(niz, n, poz, i);
		for (int j = 0;j <= i;j++) {
			if (poredak == Rastuce ? niz[poz]<niz[j] : niz[poz]>niz[j]) {
				ubaciElementSaJednePozNaDrugu(niz, n, poz, i);
			}
		}
		prikazNizaSelectionSort(niz, n, poz - n - 1, i + 1);
		printf("\n");
	}

	printf("NIZ JE SORTIRAN\n");
	prikazNiza(niz, n);
}
int pozicijaMinMaxElementa(int* niz, int n, int poz,int poredak) { //Funkcija koja vraca poziciju najmanjeg elementa u slucaju da je odabran rastaci poredak sortiranja
	int MinMaxPoz = poz;															  //A u slucaju opadajuceg poretka sortiranja vraca poziciju najveceg elementa
	for (int i = poz + 1;i < n;i++) {
		if (poredak==Rastuce ? niz[i] < niz[MinMaxPoz] : niz[i] > niz[MinMaxPoz]) {
			MinMaxPoz = i;
		}
	}
	return MinMaxPoz;
}
void prikazNizaSelectionSort(int* niz, int n, int minPoz, int poz) {
	printf("  ");
	for (int i = 0;i < n;i++) {
		if (i == poz && i == minPoz) {
			printf("| [%d]  ", niz[i]);
		}
		else if (i == poz) {
			printf("| %d  ", niz[i]);
		}
		else if (i == minPoz) {
			printf("[%d]  ", niz[minPoz]);
		}
		else {
			printf("%d  ", niz[i]);
		}
	}
	printf("\n");
}

//Radix sort
void RadixSort(int* niz, int n) {
	char nizStringova[][100] = { "jedinice","desetice","stotine","hiljade","deset hiljada","sto hiljada","milion","deset milion","sto miliona","milijarda" };
	int i, j, k;
	int brCifara = brojCifaraNajvecegBrojaUNizu(niz, n);
	int poredak = izborPoretka();
	for (i = 1;i <= brCifara;i++) {
		printf("Sortiranje po cifri %s\n", nizStringova[i - 1]);
		for (j = 0;j < n;j++) {
			for (k = 0;k < n;k++) {
				if (poredak == Rastuce ? NtaCifraBroja(niz[j], i) < NtaCifraBroja(niz[k], i) : NtaCifraBroja(niz[j], i) > NtaCifraBroja(niz[k], i)) {
					zamena(&niz[j], &niz[k]);
				}
			}
		}
		prikazNizaRadixSort(niz, n, i);
	}

	printf("NIZ JE SORTIRAN\n");
	prikazNiza(niz, n);
}
int brojCifaraNajvecegBrojaUNizu(int* niz, int n) {
	int max = niz[0];
	for (int i = 1;i < n;i++) {
		if (niz[i] > max) {
			max = niz[i];
		}
	}
	int brCifara = 0;
	while (max > 0) {
		brCifara++;
		max /= 10;
	}
	return brCifara;

}
int NtaCifraBroja(int broj, int n) {
	int i = 0;
	int cifra;
	while (i < n) {
		if (broj == 0)return 0;
		cifra = broj % 10;
		broj /= 10;
		i++;
	}
	return cifra;

}
void prikazNizaRadixSort(int* niz, int n, int cifra) {
	printf("  ");
	for (int i = 0;i < n;i++) {
		zaokruziNtuCifruBroja(niz[i], cifra);
		printf("   ");
	}
	printf("\n\n");
}
void zaokruziNtuCifruBroja(int broj, int cifra) {
	int i = 1;
	int niz[100];
	int el = 0;
	while (broj > 0) {
		niz[el++] = broj % 10;
		broj /= 10;
	}
	for (int j = el - 1;j >= 0;j--) {
		if (j + 1 == cifra)
			printf("[%d]", niz[j]);
		else
			printf("%d", niz[j]);
		i++;
	}

}

//Merge sort
void MergeSort(int niz[], int l, int d, int poredak) {
	// s sredina treutnog niza
	// l levi deo
	// d desni deo
	int i;
	if (l < d)
	{
		//Odredjivanje sredine niza/podniza
		int s = l + (d - l) / 2;

		prikazNizaMerge(niz, l, d);

		//Rekurzivno sortiranje leve,a zatim i desne strane 
		MergeSort(niz, l, s, poredak);
		MergeSort(niz, s + 1, d, poredak);

		// Funkcija za spajanje delova niza u sortiranom poretku
		spoji(niz, l, s, d, poredak);
	}
}
void spoji(int niz[], int levi, int sredina, int desni, int poredak) {
	int i, j, k;
	int nl = sredina - levi + 1; //Broj elemenata prvog dela
	int nd = desni - sredina;    //Broj elemenata drugog dela

	//Privremeni nizovi
	int* L = NULL;   //Niz za elemente levo od sredine
	int* D = NULL; //Niz za elemente desno od sredine
	int n1 = 0, n2 = 0;
	int kapacitet1 = 0, kapacitet2 = 0;

	//Stavljanje elemenata u privremene nizove
	for (i = 0; i < nl; i++)
		ubaciElement(&L, niz[levi + i], &n1, &kapacitet1);

	for (j = 0; j < nd; j++)
		ubaciElement(&D, niz[sredina + 1 + j], &n2, &kapacitet2);

	//Spajanje nizova u sortiranom poretku
	i = 0;
	j = 0;
	k = levi; //pocetni indeks za spojeni niz
	while (i < nl && j < nd)
	{
		if (poredak == Rastuce ? L[i] <= D[j] : L[i] >= D[j])
		{
			niz[k] = L[i];
			i++;
		}
		else
		{
			niz[k] = D[j];
			j++;
		}
		k++;
	}

	//Prebacivanje ostatka elemenata levog niza
	while (i < nl)
	{
		niz[k] = L[i];
		i++;
		k++;
	}

	//Prebacivanje ostatka elemenata desnog niza
	while (j < nd)
	{
		niz[k] = D[j];
		j++;
		k++;
	}
}
void prikazNizaMerge(int niz[], int l, int d) {
	int sr = l + (d - l) / 2;
	printf("Levi deo: ");
	for (int i = 0;i <= d;i++) {
		printf("%d ", niz[i]);
		if (i == sr)printf("\nDesni deo: ");
	}
	printf("\n\n");
}

//Quick sort
void QuickSort(int niz[], int prvi, int poslednji, int poredak) {
	if (prvi < poslednji)
	{
		//Deli niz u odnosu na poziciju pivota
		int pivot = podeli(niz, prvi, poslednji, poredak);


		//Rekurzivno pozivanje quick sorta za deo niza levo od pivota a zatim i desno
		QuickSort(niz, prvi, pivot - 1, poredak);
		QuickSort(niz, pivot + 1, poslednji, poredak);
	}
}
int podeli(int niz[], int prvi, int poslednji, int poredak) {
	int pivot = niz[poslednji];    // Za pivot se uzima poslednji element

	prikazNizaQuickSort(niz, poslednji + 1, poslednji);

	int i = (prvi - 1);  //Prvi (najmanji) element

	//Uporedjivanje svih elemenata sa pivotom ukoliko su manji (jednaki) od pivota prebacuju se levo
	//U suprotnom ostaju na istom mestu
	//Na kraju se pivot postavlja na odgovarajucu poziciju
	for (int j = prvi; j < poslednji; j++)
	{
		//Ako je broj manji (ili jednak) pivotu postavlja se sa njegove leve stranje
		if (poredak == Rastuce ? niz[j] <= pivot : niz[j] >= pivot)
		{
			i++;    //Povecava se indeks najmanjeg elementa
			zamena(&niz[i], &niz[j]);
		}
	}
	zamena(&niz[(i++) + 1], &niz[poslednji]); //Postavljanje pivota na odgovarajucu poziciju

	prikazNizaQuickSort(niz, poslednji + 1, i);
	printf("\n");

	return i; //Vrati poziciju pivota
}
void prikazNizaQuickSort(int niz[], int n, int pivot) {
	for (int i = 0;i < n;i++) {
		if (i == pivot) {
			printf("[%d] ", niz[i]);
		}
		else {
			printf("%d ", niz[i]);
		}
	}
	printf("\n");
}
