% This script will produce 8 graphical figures.

clear all; % Removes all variables from the current MATLAB session

t= [-2:0.005:10]; % Time vector with -2 as Tmin, 10 as Tmax, 0.005 as Tstep
% This defines the time range over which the signals will be evaluated.
% To find how many elements are in the row vector = ((Tmax-Tmin)/Tstep)+1

x1=(t>=0 & t<1); % Input signal, defined as 1 between 0 and 1, & 0 elsewhere.
figure; % To create a separate figure window plot for clarity
plot(t,x1);

x2=(t>=-1 & t<5); % Input signal, defined as 1 between -1 and 5, & 0 elsewhere.
figure; % To create a separate figure window plot for clarity
plot(t,x2);

x3=x1+x2; % Adding the signals x1(t) and x2(t) element-wise
figure; % To create a separate figure window plot for clarity
plot(t,x3);

x4=(t>=-1.5&t<-0.5); % This is signal x1 but shifted left by 1.5
% Input signal, defined as 1 between -1.5 and -0.5, & 0 elsewhere.
figure; % To create a separate figure window plot for clarity
plot(t,x4);

% The (&) symbol is the logical AND, which means both conditions have
% to be true for it to return true (i.e. 1). Otherwise, it returns 0.

y1=lab2systems(t,x1,4); % Applying input signal 1 to System 4
figure; % To create a separate figure window plot for clarity
plot(t,y1);

y2=lab2systems(t,x2,4); % Applying input signal 2 to System 4
figure; % To create a separate figure window plot for clarity
plot(t,y2);

% y=lab2systems(t,x,sysnum) is a user-defined function that takes 3 inputs 
% t vector of time, x vector of signal, sysnum system to implement 1, 2, 3, 4
% Output is y = vector of output signal values at times in vector t

y12=y1+y2; % Adding the signals y1(t) and y2(t) element-wise
figure; % To create a separate figure window plot for clarity
plot(t,y12, 'r', 'LineWidth',2);
hold on; % Compare y3 and y12 on the same plot to prove linearity
y3=lab2systems(t,x3,4); % Applying input signal 3 to System 4
plot(t,y3, 'b', 'LineWidth',2);
hold off; %Stop the holding behavior

figure; % To create a separate figure window plot for clarity
plot(t,y1, 'r', 'LineWidth',2);
hold on; % Compare y1 and y4 on the same plot to prove time invariance
y4=lab2systems(t,x4,4); % Applying input signal 4 to System 4
plot(t,y4, 'b', 'LineWidth',2);
hold off; %Stop the holding behavior