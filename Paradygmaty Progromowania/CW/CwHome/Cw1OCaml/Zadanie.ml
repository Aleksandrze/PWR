
(* Zadamie 1*)
let rec flatten listOfLists =
if listOfLists=[] then []
else List.hd listOfLists @ flatten (List.tl listOfLists);;


flatten [[1;2;3];[4;5;4]];;

(* Zadanie 2 *)
 let rec count(element, list) =
	if list =[] then 0
	else (if List.hd list=element then 1 else 0) + count(element, List.tl list);;

count ("a" , ["a";"c";"a";"4";"a"]);;


(* Zadanie 3 *)

let rec coping(element, copin)=
	if copin <0 then failwith"Negative reps"
	else if copin = 0 then []
	else element :: coping(element, copin -1);;

coping ("a", 5);;

(*Zadanie 4 *)
let rec sqrList list=
	if list= []then[]
	else List.hd list * List.hd list :: sqrList(List.tl list);;

sqrList([1;2;4;5]);;

(*Zadanie 6 *)
let rec langthList list =
	if list= [] then 0
	else 1+ langthList(List.tl list);;

langthList([1;2;3;4;5;6;7;0;]);;


def index[A](xs:List[A], index:A):List[Int]={
def indexHelp[A](i:Int, xs:List[A], ys:List[Int]): List[Int]={
xs match {
	case Nil => ys
	case h::t =>
	if(h==index) indexHelp(i+1, t, i::ys) else
		indexHelp(i+1,t,ys)
	}
	}
	indexHelp(0,xs, List()).reverse
}                                                 //> index: [A](xs: List[A], index: A)List[Int]

	index(List(1,2,3,4,2,4,5,8,2), 2)         //> res0: List[Int] = List(1, 4, 8)
}