(*Zadanie 1*)
let one(x,y,z)= ([x;y],z*.z);;

let two list =
	List.hd (List.hd (fst list))+.1. = List.hd (List.hd (snd list))+.1.;;

let three(list,list2,b)=
	(List.hd list::list2),(List.hd list ,List.hd list2);;







(*Zadanie 3*)
let podlist(list,size) =
  if list = [] ||size <= 0 then failwith "size < 0 lub pusta lista"
  else
  let rec podlist_aux(i,list2,a,y) =
  if list2 = [] then y@[a]
  else if i = size then podlist_aux(0, list2, [], y@[a])
  else podlist_aux(i + 1, List.tl list2, a@[List.hd list2], y) in
  podlist_aux(0,list,[],[]);;


podlist([1;2;3;45;4;5;6],2);;

