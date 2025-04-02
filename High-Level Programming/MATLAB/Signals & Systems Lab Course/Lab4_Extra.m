% Constructing a normal probability density function

clear all; % Clears all variables from the MATLAB workspace - fresh start

mu=0; % Setting the value of the mean (i.e. expectation of the distribution)
sigma=0.5; % Setting the value of the standard deviation
x=-5:0.001:5; % generates a vector x ranging from -5 to 5 with a step size of 0.001 - if you don't define the step in matlab it will be 1 by default
mat=pdf('Normal',x,mu,sigma); % Calculates the probability density function (pdf) values for a normal distribution with mean mu and standard deviation sigma at the points specified in vector x.
theo=(1/(sqrt(2*pi)*sigma))*exp(-(x-mu).^2/(2*sigma^2)); % Computes the theoretical formula for the normal distribution's probability density function.

figure;
plot(x,mat,'b','LineWidth',2); % Plotting the normal probability density function in blue.
hold on; % Hold the current plot so that additional plots can be overlaid on top.
plot(x,theo,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2); % Plotting the theoretical probability density function in red.
grid on;
xlabel('x-axis');
ylabel('Probability density function p(x) with µ = 0 and σ = 0.5');
legend('MATLAB-calculated pdf','Theoretically-calculated pdf');

% Only changing the mean to observe the center peak of the plot changing with it
x1=-5:0.001:10;
mu1=8; % Setting the value of the mean (i.e. expectation of the distribution)
mat1=pdf('Normal',x1,mu1,sigma); % Calculates the probability density function (pdf) values for a normal distribution with mean mu and standard deviation sigma at the points specified in vector x.
theo1=(1/(sqrt(2*pi)*sigma))*exp(-(x1-mu1).^2/(2*sigma^2)); % Computes the theoretical formula for the normal distribution's probability density function.

figure;
plot(x1,mat1,'b','LineWidth',2); % Plotting the normal probability density function in blue.
hold on; % Hold the current plot so that additional plots can be overlaid on top.
plot(x1,theo1,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2); % Plotting the theoretical probability density function in red.
grid on;
xlabel('x-axis');
ylabel('Probability density function p(x) with µ = 8 and σ = 0.5');
legend('MATLAB-calculated pdf','Theoretically-calculated pdf');

w=sigma*randn(1,length(x)); % Generates random normal distributed noise with mean 0 and standard deviation sigma. The length of w is the same as the length of x.

% Calculate statistics for the noise
wm=mean(w); % Calculates the average (mean) value of the generated random numbers w.
wv1=var(w,1); % Computes the sample variance of w (the second argument 1 indicates that it is a sample variance).
wv2=mean(abs(w).^2); % Computes the mean of the absolute values of w squared.

figure;
subplot(2, 1, 1);
plot(x, w, 'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('Generated Random Noise');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

% Display statistics
subplot(2, 1, 2);
text(0.5, 0.8, ['Mean (µ): ', num2str(wm)], 'FontSize', 12, 'HorizontalAlignment', 'center');
text(0.5, 0.6, ['Standard Deviation (σ): ', num2str(sigma)], 'FontSize', 12, 'HorizontalAlignment', 'center');
text(0.5, 0.4, ['Sample Variance (σ²): ', num2str(wv1)], 'FontSize', 12, 'HorizontalAlignment', 'center');
text(0.5, 0.2, ['Variance of the distribution (σ²): ', num2str(wv2)], 'FontSize', 12, 'HorizontalAlignment', 'center');
% text() is a function used to add text annotations to a plot.
% The first two arguments 0.5 and 0.8 specify the x and y coordinates where the text will be placed.
% ['Mean (wm): ', num2str(wm)] creates a string that will be displayed. It combines the text "Mean (wm): " with the value of wm (the mean).
% 'FontSize', 12 sets the font size of the text to 12 points.
% 'HorizontalAlignment', 'center' means that the text will be horizontally centered around the specified x-coordinate.
axis off; % turns off the axis lines and labels for the current figure since it's just used for displaying text.