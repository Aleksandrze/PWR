(*Lista 5*)




let lrepeat k llist =
let rec helper(reps, rest) = match (reps, rest) with
| (_, LNil) -> LNil
| (0, LCons(_, tailFunction)) -> helper(k, (tailFunction()))
| (_, LCons(head, _)) ->LCons(head, function() -> helper(reps - 1, rest))
in helper(k, llist);;
(*Zadanie 2 a*)

