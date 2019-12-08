type imie = string
type nazwisko = string
type osoba = imie * nazwisko
type drzewo_osob = Empty | Node of osoba * drzewo_osob * drzewo_osob
val tree : drzewo_osob
val zad1 : drzewo_osob -> (osoba -> bool) -> osoba list
val loking : string * 'a -> bool
val loking2 : string * 'a -> bool
