# Calculates 
#   5! = 5 x 4 x 3 x 2 x 1 = 120
# using a while loop

n = 5;
fact = 1; 
i = 1;
while i <= n
  fact = fact * i;
  i = i+1;
end

disp(fact);
