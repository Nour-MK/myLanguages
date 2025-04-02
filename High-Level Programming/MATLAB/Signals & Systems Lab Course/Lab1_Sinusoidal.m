clear all; 
% removes all variables from the current MATLAB session.

t = [0 : 0.01:10];
% creating a row vector t that represents a time vector.
% 0 is the starting value of the vector.
% 0.01 is the step size or interval between each consecutive element.
% 10 is the ending value.

Wo1 = 0.4 * pi; %1st angular frequency
Wo2 = pi; %2nd angular frequency
Wo3 = 0.4 * pi; %3rd angular frequency

theta1 = 0; %1st phase angle
theta2 = 0; %2nd phase angle
theta3 = 0.5 * pi; %3rd phase angle

y1 = cos(Wo1 * t + theta1); %1st sinusoidal signal
y2 = cos(Wo2 * t + theta2); %2nd sinusoidal signal
y3 = cos(Wo3 * t + theta3); %3rd sinusoidal signal

subplot(3,1,1), plot(t, y1, 'red'); 
%this plot is the 1st part of a 3-row, 1-column figure
ylabel('Sinusoidal Signal 1','Color', 'red');
xlabel('Time(sec)','Color', 'red');
grid on;

subplot(3,1,2), plot(t, y2, 'blue'); 
%this plot is the 2nd part of a 3-row, 1-column figure
ylabel('Sinusoidal Signal 2','Color', 'blue');
xlabel('Time(sec)','Color', 'blue');
grid on;

subplot(3,1,3), plot(t, y3, 'green'); 
%this plot is the 3rd part of a 3-row, 1-column figure
ylabel('Sinusoidal Signal 3','Color', 'green');
xlabel('Time(sec)','Color', 'green');
grid on;

% plotting t on the x-axis and y1, y2, y3 on the y-axis.