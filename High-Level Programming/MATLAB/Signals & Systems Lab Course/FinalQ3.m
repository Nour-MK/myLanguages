clear all;

t = 0:0.01:11;

b11 = 1*((t>=0) & (t<=3)) - 1*((t>=3) & (t<=6)) + 1*((t>=6) & (t<=7)) - 1*((t>=7) & (t<=9)) + 1*((t>=9) & (t<=10)) - 1*((t>=10) & (t<=11));

h11m=fliplr(b11); % The matched filter is obtained by time-reversing the Barker code.
y11=conv(b11,h11m ); % Convolves the Barker code b3 with its matched filter h3m. This operation is equivalent to autocorrelation in this context.

figure ('Name', 'Barker Code of Length 11 Autocorrelation Process');
subplot(2,2,1);
plot (t, b11,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Barker Signal of Length 11');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(2,2,2);
plot(t, h11m,'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Matched Filter for Barker Signal of Length 11');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;
subplot(2,2,[3,4]);
plot(0.01*(0:length(y11)-1),y11/max(abs(y11)),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
title('Autocorrelation of Barker Signal of Length 11');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;