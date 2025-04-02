clear all; 
% removes all variables from the current MATLAB session.

load r3param.mat; 
% Load the contents of the file into the current MATLAB workspace.
% It contains values for the variables Cn, theta, Tsamplem and W0.

T=2*pi/w0; % Fundamental period
tmax=2*T+0.1; % plus 0.1 seconds just to see the 2 periods clearly
% 2*T in order to generate 2 periods of the signal

t = [0:Tsample:tmax];
% creating a row vector t that represents a time vector.
% 0 is the starting value of the vector.
% Tsample is the step size or interval between each consecutive element.
% tmax is the ending value.

N=length(Cn); %to find how many elements in the coefficient vector

xt=zeros(1,length(t)); 
% Initializes a row vector xt with all elements set to zero. 
% This vector will be used to store the values of the signal this is
% why it contains as many zeroes as there are values of time in the t vector.

for n=1:N %loop runs N times (once for each coefficient)
% In MATLAB, array indices typically start from 1, not 0. 
% If you're trying to loop from 0 to N, you may encounter an error because 
% Cn and thetan are arrays and Cn(0) or thetan(0) are not defined.
xt=xt+Cn(n)*cos(n*w0*t+thetan(n));
% updates the xt vector by adding the contribution of the n-th term.
end %loop ends

plot(t, xt); %plot time on the x-axis and xt on the y-axis
grid on;
xlabel('\bf Time(sec)');
ylabel('\bf r4(t)');