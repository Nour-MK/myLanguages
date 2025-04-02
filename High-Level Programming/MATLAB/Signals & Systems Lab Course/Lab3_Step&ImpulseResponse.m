clear all; % Clears all variables from the current workspace - starting with a clean slate

b=1; % The numerator coefficient of a transfer function - b is set to 1 because it's a first-order system
a=[1 2]; % The denomiator coefficients of a transfer function
sys=tf(b,a); % Creates a transfer function model based on the numerator and denominator coefficients I defined
t=[0:0.01:5]; % Creates a time vector t from 0 to 5 seconds with a step size of 0.01 seconds
% The time axis will have ((5-0)/0.01)+1 = 501 elements in it

s=step(sys,t); % Step response using MATLAB's step() function
st=(1/2)*(1-exp(-2*t)); % The function of my theoretically-obtained step response

h=impulse(sys,t); % Impulse response using MATLAB's impulse() function
ht=exp(-2*t); % The function of my theoretically-obtained impulse response

% Creating a 2-row, 2-column subplot arrangement
subplot(2,2,1);
plot(t,s); % Plotting the MATLAB-obtained step response against time
title('MATLAB Step Response');
xlabel('Time t (s)');
ylabel('s(t)');
grid on;

subplot(2,2,2);
plot(t,st); % Plotting the theoretically-obtained step response against time
title('Theoretical Step Response');
xlabel('Time t (s)');
ylabel('s(t)');
grid on;

subplot(2,2,3);
plot(t, h); % Plotting the MATLAB-obtained impulse response against time
title('MATLAB Impulse Response');
xlabel('Time t (s)');
ylabel('h(t)');
grid on;

subplot(2,2,4);
plot(t, ht); % Plotting the theoretically-obtained step impulse against time
title('Theoretical Impulse Response');
xlabel('Time t (s)');
ylabel('h(t)');
grid on;