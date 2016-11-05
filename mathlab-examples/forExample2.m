# Calculates 
#   1! + 2! + 3! + ... + 7!
# using two for loops

n = 7;
sum = 0; 

for i = 1 : n
  fact = 1;
  for j = 1 : i
    fact = fact * j; 
  end
  sum = sum + fact;
  disp(fact);
  disp(sum);
end

