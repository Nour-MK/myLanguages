% Determination of delay using matched filter from a noisy signal

clear all; % Clears all variables from the MATLAB workspace - fresh start

load lab4_mysterysig;
% To view the contents of a .mat file, simply double click it from inside MATLAB and you will view the variables and their contents in the "Workspace" panel on the right side of the MATLAB window.
% To view the contents of a specific variable, simply type its name in the command window and press Enter. 
% a .mat file is a binary file format used to store MATLAB variables. It's not meant to be directly viewed or edited like a text-based .m file.
% What this specific file contains is a vector noisyr and an associated time vector t. 
% noisyr is a delayed Barker signal of length 13 that has hadnoise added to it.

t0=0:0.01:13; % Defining a time vector t0 with values ranging from 0 to 13 seconds and a step size of 0.01 seconds. It contains ((13-0)/0.01)+1 = 1301 element. 
% Note that we didn't use the name t because it is already used in the loaded file and it will create errors when trying to refer to either as they will overwrite one another

b13=1*((t0>=0)&(t0<=5))-1*((t0>=5)&(t0<=7))+1*((t0>=7)&(t0<=9))-1*((t0>=9)&(t0<=10))+1*((t0>=10)&(t0<=11))-1*((t0>=11)&(t0<=12))+1*((t0>=12)&(t0<=13)); % b13 = [1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1]
hm=fliplr(b13); % The matched filter is obtained by time-reversing the Barker code.

y13=conv(b13,hm ); % Convolves the matched filter of Barker code b13 with the Barker code itself (autocorrelation).

y=conv(noisyr,hm); % Convolves the matched filter of Barker code b13 with the received noisy and delayed B13 signal. This is also considered autocorrelation because autocorrelation 
% compares a signal with a delayed version of itself, including any noise present in the signal.

figure;
subplot(1, 3, 1);
plot(t0, b13,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('A Regular Barker 13 Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

subplot(1, 3, 2);
plot (t0, hm,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('Matched Filter of Regular Barker 13 Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

subplot(1, 3, 3);
plot(t, noisyr,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('A Delayed and Noisy Barker 13 Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

figure;
subplot(1, 2, 1);
plot (0.01*(0:1:length(y13)-1),y13,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('Autocorrelation of Regular Barker 13 Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

subplot(1, 2, 2);
plot(0.01*(0:1:length(y)-1),y,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',1);
title('Autocorrelation of Delayed and Noisy Barker 13 Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;