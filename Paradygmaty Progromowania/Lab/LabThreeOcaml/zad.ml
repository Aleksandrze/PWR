
let  zad2(elemnt, xs)=
	let rec help (i,xs,ys)=
		match xs with
		| []-> ys
		| h::t-> if(h=elemnt) then help(i+1,t, i::ys) 
		else help(i+1,t,ys) 
		in List.rev (help(0,xs,[]));;

zad2(2,[1;2;3;4;2;4;5;8;2]);;