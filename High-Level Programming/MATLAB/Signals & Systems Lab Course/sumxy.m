function z = sumxy(x, y, a)
    if length(x) ~= length(y)
        error('Input vectors must have the same length');
    end
    
    z = 0;
    
    for n = 1:length(x)
        term = x(n)^3 + a * x(n) * y(n)^2 + 50;
        z = z + term;
    end
end