% Showing how autocorrelation is used for time delay estimation

clear all; % Clears all variables from the MATLAB workspace
t= -10:0.01:10; % Defining a time range 

% Define the original square signal
u_t = heaviside(t);  % Define u(t)
u_t_minus_41 = heaviside(t - 4);  % Define u(t-4)
o_t = u_t - u_t_minus_41; % Define o(t) = u(t) - u(t-4)

% Define the time-delayed square signal
u_t_minus_42 = heaviside(t - 4);  % Define u(t-4)
u_t_minus_8 = heaviside(t - 8);  % Define u(t-8)
o_t_delayed = u_t_minus_42 - u_t_minus_8; % Define o(t-4) = u(t-4) - u(t-8)

b_t=fliplr(o_t);
y=0.01*conv(o_t_delayed,b_t);
t_autocorr = linspace(-20, 20, length(y));
% The choice of the time range is somewhat arbitrary for visualization purposes, but it's crucial to select one that allows you to observe the peak at the correct position. 
% If you use a smaller range, like -10 to 10, you might truncate the plot, and the peak could appear at a different position on the x-axis.
% The method used for autocorrelation is correct, but the choice of range for visualization is important to ensure accurate interpretation of the result.
% The key principle is that when you convolve a time-delayed signal with the time-reversed version of the original signal, you are performing autocorrelation. 
% This operation will result in a peak at the location of the time delay.
% Using a range of -20 to 20 centers the peak at 4 because it ensures that the x-axis covers a wide enough range to capture the full extent of the autocorrelation result, which peaks at t = 4. 
% Changing the range of your time vector does not change the underlying mathematical operation (autocorrelation), but it does affect the way the result is visualized on the plot. 
% The position of any peaks in the autocorrelation result will move along the x-axis accordingly.

% Plot the original signal
subplot(2,2,1);
plot(t, o_t,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Original Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1, 2]); % Adjust y-axis limits
grid on;

% Plot the time-delayed signal
subplot(2,2,2);
plot(t, o_t_delayed,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Time-Delayed Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1, 2]); % Adjust y-axis limits
grid on;

% Plot the time-reversed origianl signal
subplot(2,2,3);
plot(t, b_t,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Time-Reversed Original Signal');
xlabel('Time (s)');
ylabel('Amplitude');
ylim([-1, 2]); % Adjust y-axis limits
grid on;

% Plot autocorrelation
subplot(2,2,4);
plot(t_autocorr, y,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Autocorrelation');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;