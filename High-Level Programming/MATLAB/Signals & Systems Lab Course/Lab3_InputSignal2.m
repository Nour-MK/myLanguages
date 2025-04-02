clear all; % Clears all variables from the current workspace - starting with a clean slate

b=1; % The numerator coefficient of a transfer function - b is set to 1 because it's a first-order system
a=[1 2]; % The denomiator coefficients of a transfer function
sys=tf(b,a); % Creates a transfer function model based on the numerator and denominator coefficients I defined
t1=[0:0.01:1]; % Creates a time vector t from 0 to 1 seconds with a step size of 0.01 seconds
t2=[0:0.01:10]; % Creates a time vector t from 0 to 10 seconds with a step size of 0.01 seconds
x1=sin(3*t1) % Defining the input signal's function
x2=sin(3*t2) % Defining the input signal's function
% No need to write the u(t) explicitly in the input signal since we defined the time vector as starting from 0
% Since the unit-step signal is only defined for all values of t > 0

y1=lsim(sys,x1,t1); % Output signal using MATLAB's lsim() function
yt1=(1/13)*(3*exp(-2*t1)-3*cos(3*t1)+2*sin(3*t1)); % The function of my theoretically-obtained output signal

y2=lsim(sys,x2,t2); % Output signal using MATLAB's lsim() function
yt2=(1/13)*(3*exp(-2*t2)-3*cos(3*t2)+2*sin(3*t2)); % The function of my theoretically-obtained output signal

% Creating a 2-row, 1-column subplot arrangement
subplot(2,1,1);
plot(t1,y1, 'k', 'LineWidth', 2); % Plotting the MATLAB-obtained output signal against time
title('MATLAB vs. Theoretical Output Signal');
hold on;
plot(t1,yt1, 'r', 'LineWidth', 2); % Plotting the theoretically-obtained output signal against time
xlabel('Time t (s)');
ylabel('y(t)');
grid on;
legend('MATLAB Output Signal', 'Theoretical Output Signal'); % Add a legend
hold off;

subplot(2,1,2);
plot(t2,y2, 'k', 'LineWidth', 2); % Plotting the MATLAB-obtained output signal against time
title('MATLAB vs. Theoretical Output Signal');
hold on;
plot(t2,yt2, 'r', 'LineWidth', 2); % Plotting the theoretically-obtained output signal against time
xlabel('Time t (s)');
ylabel('y(t)');
grid on;
legend('MATLAB Output Signal', 'Theoretical Output Signal'); % Add a legend
hold off;