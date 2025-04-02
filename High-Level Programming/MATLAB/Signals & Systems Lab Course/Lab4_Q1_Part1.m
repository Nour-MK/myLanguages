% In the context of signal processing, "sampling" refers to the process of taking discrete measurements or values of a continuous signal at specific points in time or space.
% When we perform operations on continuous signals (like convolution), the result is usually a continuous signal as well. However, for practical implementation and analysis, 
% we often need to represent these continuous signals in a digital form that a computer can process. This involves "sampling" the continuous signal to obtain discrete values.

delta = 0.25;
t = 0:delta:10; % Creates a vector t that starts from 0, increments by delta, and goes up to 10
% The length of the vector t is ((10-0)/delta)+1
% Note that when your code operates on large amounts of data or does not use memory efficiently, MATLAB might produce an error in response to an unreasonable array size, or it might run out of memory. MATLAB has built-in protection against creating arrays that are too large. 

x = exp(-t); % Input signal x(t) = e^(-t) u(t)
% Computes the exponential function exp(-t) for each element in the vector t
% Note that we did not need to write the unit step function since we already start the time from 0

h = ones (1, length(t)); % Impulse response h(t) = u(t)
% Creates a vector h consisting of ones and the length of this vector is the same as the length of t.
% The function ones(m, n) is used to create a matrix or vector filled with ones where m is the number of rows, and n is the number of columns.

y1 = delta * conv(x, h);
% The resulting y is a vector of discrete values representing the continuous signal at intervals of delta seconds. 
% conv() function is used for performing linear convolution between two sequences. 
% Linear convolution is a mathematical operation that combines two functions (or sequences) to produce a third function (or sequence). This operation is commonly used in various signal processing and filtering applications.

plot(delta*(0:length(y1)-1), y1, 'r','LineWidth',2);
% 0:length(y)-1 creates a vector of indices ranging from 0 to length(y)-1. This corresponds to the discrete time steps of the convolution result y.
% delta * ... scales these indices by delta. This is because the original time vector t had a step size of delta.
% The x-axis values are generated to match the time steps used in the convolution, and the y-axis values are the resulting convolution values.
% You could certainly use plot(t, y) if the time values in t correspond directly to the samples in y. 
% However, in this specific case, t was generated with a step size of delta, which might not match the discrete time steps of the convolution result y.
% The line t = [0:delta:10]; creates a time vector with steps of delta. If the convolution operation resulted in y being sampled at exactly these time points, then plot(t, y) would work perfectly.
% But if the convolution operation resulted in y being sampled at different time points, using plot(delta*(0:length(y)-1), y) allows you to plot y with a time axis that corresponds to these discrete samples.
% If we use plot(t,y,'blue') it will give an error that the two vectors aren’t of the same size. 

grid on;
xlabel('Time t');
ylabel('Output y(t)');

hold on;
delta2 = 0.1;
t2=0:delta2:10;
x2=exp(-t2); 
h2=ones(1,length(t2)); 
y2=delta2*conv(x2,h2);
plot(delta2*(0:length(y2)-1),y2,'g','LineWidth',2);
xlabel('Time t');
ylabel('Output y(t)');
grid on;

hold on;
delta3 = 0.01;
t3=0:delta3:10;
x3=exp(-t3); 
h3=ones(1,length(t3)); 
y3=delta3*conv(x3,h3);
plot(delta3*(0:length(y3)-1),y3,'k','LineWidth',2);
xlabel('Time t');
ylabel('Output y(t)');
grid on;

legend('y1(t) when delta = 0.25', 'y2(t) when delta = 0.1', 'y3(t) when delta = 0.01');