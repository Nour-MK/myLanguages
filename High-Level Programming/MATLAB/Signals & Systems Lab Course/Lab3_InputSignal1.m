clear all; % Clears all variables from the current workspace - starting with a clean slate

b=1; % The numerator coefficient of a transfer function - b is set to 1 because it's a first-order system
a=[1 2]; % The denomiator coefficients of a transfer function
sys=tf(b,a); % Creates a transfer function model based on the numerator and denominator coefficients I defined
t=[0:0.01:5]; % Creates a time vector t from 0 to 5 seconds with a step size of 0.01 seconds
x=exp(-5*t) % Defining the input signal's function
% No need to write the u(t) explicitly in the input signal since we defined the time vector as starting from 0
% Since the unit-step signal is only defined for all values of t > 0

y=lsim(sys,x,t); % Output signal using MATLAB's lsim() function
yt=(1/3)*(exp(-2*t)-exp(-5*t)); % The function of my theoretically-obtained output signal

% Creating a 1-row, 2-column subplot arrangement
subplot(1,2,1);
plot(t,y); % Plotting the MATLAB-obtained output signal against time
title('MATLAB Output Signal');
xlabel('Time t (s)');
ylabel('y(t)');
grid on;

subplot(1,2,2);
plot(t,yt); % Plotting the theoretically-obtained output signal against time
title('Theoretical Output Signal');
xlabel('Time t (s)');
ylabel('y(t)');
grid on;