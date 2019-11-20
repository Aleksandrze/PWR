val f1 : ('a -> 'b -> 'c) -> 'a -> 'b -> 'c
val f2 : 'a -> 'a list -> 'b -> 'a list
val f : 'a -> 'b
type 'a bt = Empty | Node of 'a * 'a bt * 'a bt
type 'a graph = Graph of ('a -> 'a list)
