(*Zadanie 1*)

type plec = Mesczyzna | Kobieta;;
type status_osoby = Dziecko | Uczen | Student | Pracownik | Emeryt;;
type osoba = {imie: string; nazwisko: string; pl:plec; status:status_osoby; wiek: int};;

let x ={imie= "Sasha"; nazwisko= "Klimenkov"; pl= Mesczyzna; status= Student; wiek= 67};;

let z1Status = function
	{imie; nazwisko; pl; status; wiek}->
		if(wiek< 7) then Dziecko
		else if wiek < 19 then Uczen
		else if wiek < 26 && status != Pracownik then Student
		else if  wiek < 60 && pl = Kobieta then status
		else if wiek < 60 && pl = Mesczyzna then status
		else Emeryt;;

z1Status x;;

(*Zadanie 3*)

(*Dzewo*)
(*Dodajemy jeden wezel*)


type wyborf = Empty | Krok | Lics of int;;
type 'a bt = Empty| Node of  'a bt * 'a bt |Lisc of int;;
let y = Node(Lisc(1), Node(Lisc(2), Node(Lisc(4),Lisc(3))));;


let element bt=
	let rec temp (q,konec,wynik) =
		match q with
		| []-> wynik@konec
		| h::t ->
		 if (h=Empty) then temp (t,konec, wynik)
			else match h with
			Node(l,r)->
				 temp (t@[l]@[r],konec, wynik)
			| Lisc(liczba) -> temp(t,konec, wynik@[string_of_int])
			|	_ -> raise(Failure "Error")
			 in
				temp(bt,[],[]);;


type 'a drzewo = Lisc of 'a | Wezly  of 'a drzewo * 'a drzewo | Wezel of 'a drzewo ;;
type 'a wybor = Wartosc of 'a| Brak ;;

let tree = (Wezly(Lisc(1),Wezly(Lisc(2),Wezly(Lisc(4),Lisc(3)))))

let rec zad3 = function
		| Wezly (w1,w2) ->(zad3 w1)@(zad3 w2)@[Brak]
		| Lisc (war) -> [Wartosc(war)]
		| _ -> raise(Failure "Error");;

zad3 tree;;


