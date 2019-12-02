type plec = Mesczyzna | Kobieta
type status_osoby = Dziecko | Uczen | Student | Pracownik | Emeryt
type osoba = {
  imie : string;
  nazwisko : string;
  pl : plec;
  status : status_osoby;
  wiek : int;
}
val x : osoba
val z1Status : osoba -> status_osoby
