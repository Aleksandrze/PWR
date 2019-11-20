(*1*)
(*tulko jeden+ obrazek*)
let rec evenR n=
	if n=0 then true
	else addR(n-1)
	and addR n=
		if n=0 then false
		else evenR(n-1);;

evenR(6);;

(*2a*)
let rec fib n =
  if n < 1 then raise (Failure "Wrong argument!")
  else if n <=2 then 1
  else fib(n-1) + fib(n-2);;

  (*2b*)
let rec fibTail n =
  if n < 1 then raise (Failure "Wrong argument!")
  else
        let rec fibTail_aux(i, a, b) =
        if n = i then b
        else fibTail_aux(i+1, b, a+b) in
  fibTail_aux(2,1,1);;

  (*3*)
let root3 a =
  let rec root3_aux x =
  if abs_float(x**3.-.a) <= 1e-55*.abs_float(a) then x
  else root3_aux(x+.(a/.x**2.-.x)/.3.) in
  root3_aux(if a<=1. then a else a/.3.);;



 	(*4*)
let (_,_,x,_,_)=(-2,-1,0,1,2)

	 
  (*5*)
let rec initSegment(xs, ys) =
  match (xs, ys) with
  ([],_) -> true
  | (_,[]) -> false
  | _ -> if List.hd xs = List.hd ys then initSegment(List.tl xs, List.tl ys) else false;;

  (*6*)
let rec replaceNth(xs, n, x) =
  match (xs, n) with
  ([],_) -> []
  | (h::t, 0) -> x::t
  | (h::t,_) -> h::replaceNth(t, n-1, x);;



