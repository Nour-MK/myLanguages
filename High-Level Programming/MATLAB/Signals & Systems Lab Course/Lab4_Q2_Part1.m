% Showing the relationship of matched filtering and autocorrelation

clear all; % Clears all variables from the MATLAB workspace

t= -3:0.01:3; % Defining a time range 
% Be very careful while adjusting the time step size
% Changing the step size of your time axis from 0.01 to 1 can significantly impact the shape of your square signal.
% With a step size of 0.01, you have a very fine-grained representation of the time axis. This means that you are evaluating the function u(t)u(t2) at a large number of points within the specified time range.
% When you change the step size to 1, you are now evaluating the function at much fewer points within the time range. This results in a coarser representation of the signal.
% The choice of step size depends on the level of detail you need in your plot. A smaller step size provides a more precise representation, while a larger step size may be sufficient for a more generalized view.

% One method of defining u(t) - u(t-2)
% r_t=1*((t>=0)&(t<=2)); 
% Defining a rectangular pulse signal r(t) using logical operations
% It creates a rectangular pulse that is 1 between t = 0 and t = 2 and 0 elsewhere

% Another easier method of doing it using a MATLAB predefined function
u_t = heaviside(t);  % Define u(t)
u_t_minus_2 = heaviside(t - 2);  % Define u(t-2)
% heaviside(t) is a mathematical function that represents the unit step function u(t)
% The unit step function is a piecewise-defined function that has a value of 0 for t<0 and a value of 1 for t0
% It is named after the British engineer Oliver Heaviside
r_t = u_t - u_t_minus_2;  % Define the function r(t) = u(t) - u(t-2)

h_t=fliplr(r_t); % Creating a left-right time-reversed version h(t) of the signal r(t)
% In matched filtering, the template signal is time-reversed to create h(t) because it aligns the template signal properly for correlation. 
% This alignment ensures that the filtering process is sensitive to the presence of the template signal in the received signal.
% The time-reversed template signal is then convolved with the received signal. The convolution operation essentially slides the time-reversed 
% template signal along the received signal, computing the inner product at each point. After convolution, you look for peaks in the resulting 
% correlation function. The location of the peak corresponds to the time in the received signal where the template best matches.

y=0.01*conv(r_t,h_t); % Computes the convolution of r_t and h_t, scaled by a factor of 0.01. 
% Convolution is a mathematical operation that combines two signals to produce a third signal. 
% In this context, it's being used to compute the autocorrelation of the rectangular pulse signal.
% It's good practice to choose a scaling factor in the convolution operation that aligns with the time step in your time range to ensure accurate and interpretable results.

t_autocorr = linspace(-3, 3, length(y)); % Calculate the corresponding time values for the autocorrelation - This ensures that the autocorrelation peak will be properly at t = 0
% linspace(a, b, n) generates a linearly spaced vector of n points between a and b.
% length(y) gives you the number of elements in the vector y, which is the result of the convolution.

% Plotting the function u(t) - u(t-2)
subplot(3,1,1);
plot(t, r_t, 'LineWidth', 2, 'Color', [0.6350, 0.0780, 0.1840]);
% Note that [0.6350, 0.0780, 0.1840] is the RGB value for the maroon color - my preferred signature graph color
grid on;
xlabel('Time t');
ylabel('Signal Amplitude');
title('Plot of r(t) = u(t) - u(t-2)');
ylim([-1, 2]); % Adjust y-axis limits

% Plotting the time-reversed version of the function u(t) - u(t-2)
subplot(3,1,2);
plot(t, h_t, 'LineWidth', 2, 'Color', [0.6350, 0.0780, 0.1840]); 
grid on;
xlabel('Time t');
ylabel('Signal Amplitude');
title('Plot of the Time-Reveresed Signal r(-t)');
ylim([-1, 2]); % Adjust y-axis limits

% Plots the autocorrelation function
subplot(3,1,3);
plot(t_autocorr,y,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2); 
grid on;
xlabel('Time t');
ylabel('Signal Amplitude');
title('Plot of the Autocorrelation of r(t)');

