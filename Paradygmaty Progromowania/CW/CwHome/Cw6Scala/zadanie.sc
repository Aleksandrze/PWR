object zadanie {

//Zadanie 1 postac zwinięta

def whileLoop (cond: => Boolean, block: => Unit): Unit ={
	if(cond) {
	block
	whileLoop(cond, block)
	}
}

// Zadanie 1 postac rozwinięta
def whileLoop(cond: => Boolean)(block: => Unit): Unit ={
	if (cond) {
		block
		whileLoop(cond)(block)
	}
}

/*
Postaci rozwiniętej można używać jak zwykłej pętli while, np.:
whileLoop(true) println(true);

Przy przekazywaniu argumentów do funkcji wykorzystany został mechanizm wywołania
przez nazwę, tzn. do funkcji przekazywane są domknięcia argumentów. Obliczanie
wartości tych domknięć jest leniwe, tzn. są one obliczane w momencie, gdy są
potrzebne. Cond jest warunkiem kontynuacji pętli czyli typ Boolean. Block jest
wyrażeniem do wykonania, którego zwraca typ Unit. Typem wyniku funkcji whileLoop
jest Unit.
*/

//==================================================

//Zadanie 2

def swap(tab: Array[Int], i: Int, j: Int): Unit ={
	val aux = tab(i)
	tab(i) = tab(j)
	tab(j) = aux
}
/*
Powyższa funkcja przyjmuje jako argument tablicę intów oraz numery indeksów
elementów tablicy, które mają być zamienione. Z użyciem pomocniczej wartości aux
następuje zamiana dwóch elementów tablicy.
*/

def choose_pivot(tab: Array[Int], m: Int, n: Int): Int ={
tab((m + n) / 2)
}

/*
Funkcja przyjmuje tablicę do posortowania oraz indeksy elementów stanowiących
początek i koniec podtablicy tablicy tab. Zwraca element rozdzielający (pivot)
danej podtablicy, którym jest jej element środkowy.
*/

def partition(tab: Array[Int], l: Int, r: Int): (Int, Int) ={
	var i = l
	var j = r
	val pivot = choose_pivot(tab, l, r)
		while (i <= j) {
				while (tab(i) < pivot) i += 1
					while (pivot < tab(j)) j -= 1
							if (i <= j) {
							swap(tab, i, j)
							i += 1
							j -= 1
						}
					}
		(i, j)
	}
	
/*
Funkcja przyjmuje argumenty te same, co poprzednia funkcja. Jej zadaniem jest
ustawienie elementów tablicy mniejszych od pivota przed nim, a większych od niego
po nim. Zmiennej i przypisywany jest indeks elementu większego od pivota, który
znajduje się przed nim (czyli po niewłaściwej stronie), a zmiennej j indeks
elementu mniejszego od pivota, który znajduje się za nim (czyli także po
niewłaściwej stronie). Poszukiwania elementów większych od pivota zaczynają się od
pierwszego elementu tablicy, a elementów mniejszych od niego od końca tablicy.
Elementy te są zamieniane miejscami. Na koniec zwracana jest para (i, j), na podstawie
której można podzielić tablicę tab[l..r] na podtablice: tab[l..j] zawierającą
elementy mniejsze od pivota i tab[i..r] zawierającą elementy większe od pivota.
*/
def quick(tab: Array[Int], l: Int, r: Int): Unit ={
	if (l < r) {
		val (i, j) = partition(tab, l, r)
			if ((j - l) < (r - i)) {
			quick(tab, l, j)
			quick(tab, i, r)
			} else {
					quick(tab, i, r)
					quick(tab, l, j)
			}
		} else ()
	}
/*
Funkcja quick przyjmuje argumenty takie same jak dwie poprzednie funkcje. Jest ona
„głównym” kodem sortowania szybkiego. Najpierw jest sprawdzana poprawność indeksu
początkowego i końcowego tablicy – ten pierwszy musi oczywiście być mniejszy od
tego drugiego. Następnie indeksy są podane poprawnie to wartości (i,j) jest
przypisany wynik funkcji partition wywołanej dla argumentów, które przekazano
funkcji quick. Następuje sprawdzenie która z podtablic (utworzonych na podstawie
wyników funkcji partition – patrz opis do tej funkcji) jest krótsza i ta tablica
jest sortowana rekurencyjnie w pierwszej kolejności, w drugiej kolejności jest
sortowana tablica dłuższa (usprawnienie polegające na tym, by żądanie sortowania
dłuższej tablicy odkładać na stos, dzięki czemu wielkość stosu jest ograniczana do
lg n).
*/
def quicksort(tab: Array[Int]): Unit = {
	quick(tab, 0, tab.length - 1)
}
/*
Funkcja przyjmująca tablicę do posortowania i wywołująca funkcję quick wykonującą
sortowanie szybkie na tej tablicy, gdzie początkowe indeksy tablicy to 0 (pierwszy
element) i tab.length-1 (ostatni element) czyli wywoływane jest sortowanie dla
całej tablicy.
*/

quicksort (Array(5,7,12,3,2))
}