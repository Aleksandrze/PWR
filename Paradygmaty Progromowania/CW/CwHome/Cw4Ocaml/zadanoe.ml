(*Lista 4*)

(*Zadanie 1*)
(* a *)
let f1 x y z = x y z;;
(*let f1 = function x -> function y -> function z -> x y z;;*)
(* y: 'a *)
(* z: 'b *)
(* x: 'a ->'b -> 'c*)
(* f1: ('a ->'b -> 'c) -> 'a ->'b -> 'c *)

(* b *)
let f2 x y= function z ->x::y;;
(* x: 'a *)
(* y: 'a List *)
(* z: 'b*)
(* finction z to anonim function*)
(* function z: 'a-> 'a List -> 'b *)
(* f2: 'a -> 'a List -> 'b -> 'a List*) 

(*Zadanie 2*)
let rec f x = f x;;
(* val f : 'a -> 'b = <fun> *)




type 'a bt = Empty | Node of 'a * 'a bt * 'a bt
type 'a graph = Graph of ('a -> 'a list)

(*Zadanie 3 ?????????????*)
(*
let breadthBT tree =
let rec helper = function
[] -> []
| [] :: tail -> helper tail
| Node(v, l, r) :: tail -> v :: helper (l :: r :: tail)
in helper [tree];;

let tt = Node(1, Node(2, Node(4, Empty, Empty),Empty),Node(3,Node(5,Empty,Node(6,Empty,Empty)),Empty));;
*)