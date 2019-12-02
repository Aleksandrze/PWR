
let zad1 xs ys =
		let rec temp(el, pos,xs)=
			match xs with
 			|[] -> [el]
			| h::t -> 
						if(pos=0) then el::h::t 
							else h::temp(el,pos-1,t)
							
	in let rec set_bb(xs,ys,result)=
			match(xs, ys) with
 				([],[])-> result
			| (h1::t1,h2::t2)-> set_bb(t1,t2,temp(h1,h2,result))
			|_ -> raise(Failure "Error")
 	in set_bb(xs,ys,[]);;

zad1 [5;4;2;10] [2;1;0;3];;
zad1 [1;2;5] [3;2;1];;

(*	parametr dodac *)


(*	parametr dodac *)
(* (Rekurencja ogunowa byla; Wylo funkcj)*)


(*===================================*)
(* Zadanie 2*)
let rec fcomposition flist (operator) =
	let compo(f, g) = fun x -> f(g(x)) in
	let rec f_aux(f_list, result) = 
	match f_list with
	[] -> result
	| h::t -> f_aux(t, compo(result,((operator) (fst h) (snd h)))) in
match flist with
| h::t -> f_aux(t, ((operator) (fst h) (snd h)))
| _ -> raise (Failure "Error");;

let (++) (f)(g)(x) = f(x) +. g(x);;

let lin x = 0.;;
let sqr x = x*.x;;
let two x = 2.0*.x;;

fcomposition [(sqr,lin);(two,lin);(sqr,lin)] (++) 2.0;;
