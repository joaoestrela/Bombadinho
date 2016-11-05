  #
  # a, b, and c are three lengths 
  # They define a triangle if:
  # 1) a, b, c are all positive
  # 2)  the sum of any two lengths must be greater than the other
  
  a = 3;
  b = 4;
  c = 7;
  
  isValid = true;
  
  if a <= 0 
    isValid = false;
  else
    if b <= 0
      isValid = false;
    else
      if c <= 0
        isValid = false; 
      else
        if a >= b + c
          isValid = false;
        elseif b >= a + c
          isValid = false;
        elseif c >= a + b
          isValid = false;
        end
      end
    end
  end
  
  disp(isValid);