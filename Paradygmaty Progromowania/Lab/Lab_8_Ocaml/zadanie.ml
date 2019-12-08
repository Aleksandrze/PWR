
type imie = string
type nazwisko = string
type osoba =  imie * nazwisko
type drzewo_osob =Empty|Node of osoba*drzewo_osob*drzewo_osob;;

let tree = Node(("Test", "Test"), Node(("Sasha", "Klimenkov"), Node (("Troj", "Gub"),Empty,Empty),Empty),Empty);;



let rec zad1 tree pred = 
 	match tree with 
		|Empty -> [] 
		|Node (o,l,r) -> if (pred o) then [o]@(zad1 l pred)@(zad1 r pred) else (zad1 l pred)@(zad1 r pred);;

  

 let loking osob =  
	if (fst osob) = "Sasha" then true 
			else false;;  


 let loking2 osob =  
	if (fst osob) = "Pusto" then true 
			else false;;  


zad1 tree loking;;


zad1 tree loking2;;


