function y=lab2systems(t,x,sysnum)
% This is a user-defined function that implements 4 continuous-time 
% systems for ECEN 221 Lab 2 

%% Input Variables:  
% 1. t = vector of times
% 2. x = vector of input signal values (at times in vector t)
% 3. sysnum = # of system to implement (1, 2, 3, or 4)

%% Output Variable: 
% y = vector of output signal values (at times in vector t)

% Pre-processing:  make sure x and t are column vectors
x=x(:);
t=t(:);

%% Implementing the 4 systems

if sysnum==1				% System #1
  y=x.*(t>=0);
elseif sysnum==2			% System #2
  y=x.^2;
elseif sysnum==3			% System #3
  y=tan(2*pi/3)*x;
elseif sysnum==4			% System #4
  y=t.^2.*x;
else					% Error:  invalid system number
  error('LAB2SYSTEMS:  Invalid system.  Input sysnum must be 1, 2, 3, or 4');
end

% End of function
end
