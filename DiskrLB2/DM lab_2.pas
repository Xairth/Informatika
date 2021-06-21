var 
n,m, i:integer;
src: array[0..500] of string;
s: string;

procedure comb(n,m: integer; res: string; k, j:integer);
var i:integer;
begin
  if j=m then writeln(res)
  else 
  for i:=k+1 to n do
    comb(n,m, res+src[i]+' ', i,j+1);
end;

function f(x: integer):integer;
var i,res:integer;
begin
  res:=1;
  for i:=2 to x do
  res *= i;
  result := res;
end;

function C(n,m: integer):integer;
begin
  result := f(n) div (f(n-m)*f(m));
end;


begin
write('Введите n: ');
read(n);
write('Введите m: ');
read(m);

for i:=1 to n do begin
  str(i,s);
  src[i] := s;
end;
writeln('Всего сочетаний будет: ', C(n,m));


comb(n,m,'',0,0);



end.