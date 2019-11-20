module type QUEUE_FUN =
  sig
    type 'a t
    exception Empty of string
    val empty : unit -> 'a t
    val enqueue : 'a * 'a t -> 'a t
    val dequeue : 'a t -> 'a t
    val first : 'a t -> 'a
    val isEmpty : 'a t -> bool
  end
module Queue_fun : QUEUE_FUN
module Queue_fun2 : QUEUE_FUN
