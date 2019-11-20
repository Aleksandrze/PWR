(* Zadanie 1 *)
module type QUEUE_FUN =
sig
type 'a t
exception Empty of string
val empty: unit -> 'a t
val enqueue: 'a * 'a t -> 'a t
val dequeue: 'a t -> 'a t
val first: 'a t -> 'a
val isEmpty: 'a t -> bool
end;;

(* A **)
(*lst = queue oraz v = element *)
 module Queue_fun: QUEUE_FUN =
struct
type 'a t = 'a list
exception Empty of string
let empty () = []
let enqueue (v, lst) = lst@[v] 

let dequeue = function
[] -> raise (Empty "dequeue") (* lub [] *)
| head::tail -> tail;;

let first = function
[] -> raise (Empty "first")
| head::tail -> head;;

let isEmpty lst = lst=[] (* lst=[] to sprawdzenie rownosci *)
end;;


(* B *)
(* q= endOfQueue*)
module Queue_fun2: QUEUE_FUN =
struct
type 'a t = 'a list * 'a list
exception Empty of string
let empty () = ([], [])

let normalize = function
([], q) -> (List.rev q, [])
| q -> q (* Jeżeli lista jest postaci normalnej, nic nie rób *)

let enqueue (v,(x1, lst)) = normalize (x1, v::lst)
(*let enqueue (element, queue) =
normalize(fst queue, element :: snd queue)*)

let dequeue = function
(_::xs, q) -> normalize (xs, q)
| _ -> raise (Empty "dequeue")
(*let dequeue = function
| ([], _) -&gt; ([], [])
| (head :: tail, endOfQueue) -&gt; normalize(tail, endOfQueue)*)

let first = function
(x::_, _) -> x
| _ -> raise (Empty "first")

let isEmpty lst = lst=([], []) (* lst=([],[]) to sprawdzenie rownosci *)
end;;