function y=finalsystems(t,x)
%t = vector of times
%x = vector of input signal values (at times in vector t)
%%% Pre-processing:  make sure x and t are column vectors

x=x(:);
t=t(:);

% System
y=2*(t.^2).*x+10;

end
