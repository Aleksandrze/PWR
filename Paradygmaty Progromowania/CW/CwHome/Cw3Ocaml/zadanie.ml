(*Zadamie 1*)
(* a) (int -> int -> ‘a) -> ‘a  *)
(* b) (string -> 'a) -> string -> string -> 'a*)

(*Zadanie 2a*)

let curry3 f x y z =f(x,y,z);;
(*curry3 : ('a * 'b * 'c -> 'd) -> 'a -> 'b -> 'c -> 'd*)

(*Zadanie 2 b*)
 let uncurry3 f(x,y,z) =f x y z;;
(*uncurry3 : ('a -> 'b -> 'c -> 'd) -> 'a * 'b * 'c -> 'd*)

(*Zadanie 3*)
let sumProd list=
	List.fold_left (fun (s,p) h -> (s+h,h*p))(0,1)list;;

(*zadanie 4a*)
let rec quicksort = function
| []  -> []
| [x] -> [x]
|  xs  -> let small = List.filter (fun y -> y < List.hd xs ) xs
and large = List.filter (fun y -> y >= List.hd xs ) xs
in quicksort small @ quicksort large;;

(*Gdy w momencie kiedy w listcie bedzie wencej niz jeden elment i nie brdzie*)
(* minejszych elementow niz pierwszy, to pezestanie ona są dzielic i funkcja bedze *)
(*cię ciągle wywoływac rekurenckine dla tej listy, i to bedzir do momentu, wystopiena*)
(* STACK OVERFLOW*)

(*Zadanie 4b*)
let rec quicksort' = function
	| [] -> []
	|  x::xs -> let small = List.filter (fun y -> y < x ) xs
and large = List.filter (fun y -> y > x ) xs
in quicksort' small @ (x :: quicksort' large);;

(*b) Jeśli jakiś element się powtarza, to w liście wynikowej będzie występował tylko raz.*)

