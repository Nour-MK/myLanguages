% clear all; 
% % removes all variables from the current MATLAB session.
% 
% t = [0 : 0.01: 6]; %creating time vector t
% % 0 is the starting value of the vector.
% % 0.01 is the step size or interval between each consecutive element.
% % 6 is the ending value.
% 
% alpha1 = -0.1;
% alpha2 = -0.4;
% alpha3 = -0.8;
% alpha4 = 0.1;
% 
% y1 = exp(alpha1*t); % 1st exponential signal
% y2 = exp(alpha2*t); % 2nd exponential signal
% y3 = exp(alpha3*t); % 3rd exponential signal
% y4 = exp(alpha4*t); % 4th exponential signal
% 
% plot(t, y1, 'red', 'LineWidth', 2); % time on x-axis, signal on y-axis
% hold on;
% % command used to retain the current plot in the figure window 
% % so that new plots can be added to it without erasing the existing 
% % content. It essentially "holds on" to the current plot, allowing 
% % you to overlay multiple plots on the same figure.
% plot(t, y2, 'blue', 'LineWidth', 2); % time on x-axis, signal on y-axis
% plot(t, y3, 'green', 'LineWidth', 2); % time on x-axis, signal on y-axis
% xlabel('\bf Time(sec)');
% ylabel('\bf Signal Amplitude');
% grid on;
% hold off; %stops the holding behavior

clear all;

t = [0 : 0.01: 6];
alpha1 = -0.1;
alpha2 = -0.4;
alpha3 = -0.8;
alpha4 = 0.1;

y1 = exp(alpha1*t);
y2 = exp(alpha2*t);
y3 = exp(alpha3*t);
y4 = exp(alpha4*t);

% First Figure
figure; % Create a new figure window
plot(t, y1, 'red', 'LineWidth', 2);
hold on;
plot(t, y2, 'blue', 'LineWidth', 2);
plot(t, y3, 'green', 'LineWidth', 2);
xlabel('\bf Time(sec)');
ylabel('\bf Signal Amplitude');
grid on;
title('First Figure');

% Second Figure
figure; % Create a new figure window
plot(t, y1, 'red', t, y4, 'yellow');
xlabel('\bf Time(sec)');
ylabel('\bf Signal Amplitude');
grid on;
title('Second Figure');
