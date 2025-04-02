% Generating Barker code & Performing Autocorrelations

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Reference for Barker Codes of All Lengths:
% b02 = [1, -1] 
% b03 = [1, 1, -1]
% b04 = [1, -1, 1, 1]
% b05 = [1, 1, 1, -1, 1]
% b07 = [1, 1, 1, -1, -1, 1, -1]
% b11 = [1, 1, 1, -1, -1, -1, 1, -1, -1, 1, -1]
% b13 = [1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all; % Clears all variables from the MATLAB workspace

t=0:0.01:3; % Creates a time vector t ranging from 0 to 3 seconds with a step size of 0.01 seconds. This will be used for defining the signals. 
% It contains ((3-0)/0.01)+1 = 301 element. This can also be found by typing length(t) in the Command Window

% Creating a length 3 barker code signal by defining it as 1 in the time interval [0,2] seconds and -1 in the interval [2,3] seconds.
% Note that you cannot simply define it as a vector of length 3 elements b3 = [1, 1, -1] because when you get to plotting, there will be a huge incompatibility between the x axis that contains 301 elements and
% the y axis will only have 3, MATLAB will be unable to match the points because they are insufficient, hence, a workaround to defining a signal vector of barker code that contains 301 elements
% written manually, we can use logical operations to set a certain value for a specified ranges in the time axis. This way, the length of b3 is still 3 but it respects the range of t when it comes to plotting.
b3=1*((t>=0)&(t<=2))-1*((t>=2)&(t<=3)); 

h3m=fliplr(b3); % The matched filter is obtained by time-reversing the Barker code.

y3=conv(b3,h3m ); % Convolves the Barker code b3 with its matched filter h3m. This operation is equivalent to autocorrelation in this context.

figure ('Name', 'Barker Code of Length 3 Autocorrelation Process');
subplot(2,2,1);
plot (t, b3,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Barker Signal of Length 3');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(2,2,2);
plot(t, h3m,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Matched Filter for Barker Signal of Length 3');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(2,2,[3,4]);
plot(0.01*(0:length(y3)-1),y3/max(abs(y3)),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Autocorrelation of Barker Signal of Length 3');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

% We didn't simply write plot(t, y3); due to the mismatch in the lengths of t and y3 since t has 301 elements, while y3 has 601 elements. 
% This means that directly plotting t against y3 would result in an error due to the mismatch in dimensions.
% To make them compatible, we use the argument of the x-axis to create 0.01*(0:length(y3)-1)
% 0:length(y3)-1 creates a vector of indices from 0 to the length of y3 minus 1. This is essentially creating a time index in terms of sample points.
% 0.01*(0:length(y3)-1) term as a whole takes each index and multiplies it by the time step size (0.01 s). This converts the index values to time values in seconds.
% In my case length(y3) = 601. So, the range if indices would be from 0 to 600. And when I multiply by 0.01, I get a range of time values from 0 to 6.00 seconds, with an increment of 0.01 seconds between each point.
% So, 0.01*(0:length(y3)-1) generates a time axis that corresponds to the autocorrelation result, where the time values are in seconds.
% Remember to run each individual argument in the Command Window to see its result to better validate and understand the operation being done.
% So if you run 0.01*(0:length(y3)-1) alone and y3/max(abs(y3)) alone you will find that both contain 601 elements.

% As for the argument y3/max(abs(y3)) it is used to normalize the autocorrelation result y3. Normalizing the result means that the maximum value in y3 will be scaled to 1, and all other values will be relative to that maximum value. 
% This can be useful for visualizing the relative strengths of different peaks in the autocorrelation result. In some cases, the autocorrelation result may have large amplitude values, and normalizing it helps in visualizing the 
% relative strengths of different features in the plot. It also makes it easier to compare autocorrelation results with different scales or units.
% max() is a MATLAB function that returns the maximum value in a given array or vector.
% abs() is a MATLAB function that returns the absolute value of a given number or array.
% So, code-wise what we did is find the absolute value of each element in vector y3 then we found the maximum value in the vector of absolute values of y3 then we divided each element in the vector y3 by the maximum value. 
% We've basically scaled the values to a specific range.

% Now, the same process will be done for Barker codes of lengths 7 and 13 as well.

t1=0:0.01:7; % Defining another time vector t with values ranging from 0 to 7 seconds and a step size of 0.01 seconds. It contains ((7-0)/0.01)+1 = 701 element. 
b7 = 1*((t1>=0)&(t1<=3)) - 1*((t1>=3)&(t1<=5)) + 1*((t1>=5)&(t1<=6)) - 1*((t1>=6)&(t1<=7)); %b07 = [1, 1, 1, -1, -1, 1, -1] aka (1 = 1), (2 = 1), (3 = 1), (4 = -1), (5 = -1), (6 = 1), (7 = -1)
% Keep in mind that MATLAB indexing starts from 1 but we use t1>=0 because the time vector itself starts from 0 so we have to put it into consideration
h7m=fliplr(b7); % The matched filter is obtained by time-reversing the Barker code.
y7=conv(b7,h7m );
figure ('Name', 'Barker Code of Length 7 Autocorrelation Process');
subplot(2,2,1);
plot (t1, b7,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Barker Signal of Length 7');
xlabel('Time (s)');
xlim([0, 7]); % Adjust x-axis limits
ylabel('Amplitude');
grid on;
subplot(2,2,2);
plot(t1, h7m,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Matched Filter for Barker Signal of Length 7');
xlabel('Time (s)');
xlim([0, 7]); % Adjust x-axis limits
ylabel('Amplitude');
grid on;
subplot(2,2,[3,4]);
plot(0.01*(0:length(y7)-1),y7/max(abs(y7)),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Autocorrelation of Barker Signal of Length 7');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

t2=0:0.01:13; % Defining another time vector t with values ranging from 0 to 13 seconds and a step size of 0.01 seconds. It contains ((13-0)/0.01)+1 = 1301 element. 
b13 = 1*((t2>=0)&(t2<=5)) - 1*((t2>=5)&(t2<=7)) + 1*((t2>=7)&(t2<=9)) - 1*((t2>=9)&(t2<=10)) + 1*((t2>=10)&(t2<=11)) - 1*((t2>=11)&(t2<=12)) + 1*((t2>=12)&(t2<=13)); % b13 = [1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1]
% Keep in mind that MATLAB indexing starts from 1 but we use t1>=0 because the time vector itself starts from 0 so we have to put it into consideration
h13m=fliplr(b13); % The matched filter is obtained by time-reversing the Barker code.
y13=conv(b13,h13m );
figure ('Name', 'Barker Code of Length 13 Autocorrelation Process');
subplot(2,2,1);
plot (t2, b13,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Barker Signal of Length 13');
xlabel('Time (s)');
xlim([0, 13]); % Adjust x-axis limits
ylabel('Amplitude');
grid on;
subplot(2,2,2);
plot(t2, h13m,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Matched Filter for Barker Signal of Length 13');
xlabel('Time (s)');
xlim([0, 13]); % Adjust x-axis limits
ylabel('Amplitude');
grid on;
subplot(2,2,[3,4]);
plot(0.01*(0:length(y13)-1),y13/max(abs(y13)),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Autocorrelation of Barker Signal of Length 13');
xlabel('Time (s)');
xlim([0, 26]); % Adjust x-axis limits
ylabel('Amplitude');
grid on;