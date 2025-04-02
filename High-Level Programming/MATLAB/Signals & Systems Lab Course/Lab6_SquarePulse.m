% Define the time vector
t = linspace(-2.5, 2.5, 1000);

% Create the square wave
x = zeros(size(t));

% Set the values for different intervals
x((t > -2.25) & (t <= -1.75)) = 1;
x((t > -1.75) & (t <= -1.25)) = 0;
x((t > -1.25) & (t <= -0.75)) = 1;
x((t > -0.75) & (t <= -0.25)) = 0;
x((t > -0.25) & (t <= 0.25)) = 1;
x((t > 0.25) & (t <= 0.75)) = 0;
x((t > 0.75) & (t <= 1.25)) = 1;
x((t > 1.25) & (t <= 1.75)) = 0;
x((t > 1.75) & (t <= 2.25)) = 1;

% Plot the signal
figure;
tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t, x,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
xlabel('Time (in terms of both T and T1)');
ylabel('x(t): Sqaure Pulse Amplitude');
title('A Periodic Square Pulse');
grid on;
xlim([-2.5, 2.5]);
ylim([-1.25, 2]);

% Customize x-axis labels
xticks([-2.5 -2.25 -2 -1.75 -1.5 -1.25 -1 -0.75 -0.5 -0.25 0 0.25 0.5 0.75 1 1.25 1.5 1.75 2 2.25 2.5]);  % Specify the locations of the tick marks
xticklabels({'-3T/2 = -10T1', '-3T/4 = -9T1', '-2T = -8T1', '-3(2T)/4 = -7T1', '-2T/2 = -6T1', '-2T/4 = -5T1', '-T = -4T1', '-3T/4 = -3T1', '-T/2 = -2T1', '-T/4 = -T1', '0', 'T/4=T1', 'T/2 = 2T1', '3T/4 = 3T1', 'T = 4T1', '2T/4 = 5T1', '2T/2 = 6T1', '3(2T)/4 = 7T1', '2T = 8T1', '3T/4 = 9T1', '3T/2 = 10T1'});  % Specify the labels for each tick mark