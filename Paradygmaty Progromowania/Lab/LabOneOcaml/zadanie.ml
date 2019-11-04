(*Zadanie 1*)

let trojkat a b c = (
	if a<0. || b<0. || c<0. then failwith "Ujemny bok"
	else if abs_float(b-.c)<a && a<b+.c then(
		let p = (a +.b +.c)/.2. in 
		sqrt(p *. (p-.a) *. (p -. b) *. (p -. c))
		)
		else failwith "Nie spelnia warunku"
		);;
trojkat 4. 4. 5. ;;
trojkat 1. 1. 1. ;;

(*Zadaine 2*)
