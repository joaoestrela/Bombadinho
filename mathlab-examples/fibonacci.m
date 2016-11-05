
# Print the first 20 Fibonacci numbers
disp(1);
disp(1);

prev = 1;
fib = 1;

for i = 1 : 20 
  tmp = fib;
  fib = fib + prev;
  prev = tmp;
  disp(fib);
end 

