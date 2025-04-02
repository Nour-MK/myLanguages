t = [-2:0.001:10];

% Testing signals for linearity
x1 = (t>=0 & t<1);
x2 = (t>=-1 & t<5);

y1 = finalsystems(t, x1);
y2 = finalsystems(t, x2);
y12 = y1 + y2;

x3 = x1 + x2;
y3 = finalsystems(t, x3);

figure;
plot(t, y3, 'r');
grid on;
hold on;
plot (t, y12, 'g');
title('Linearity Test');
xlabel('Time t (s)');
ylabel('Signal Amplitude');
legend('y3(t)', 'y12(t)')
hold off;

% Testing signals for time invariance
x4 = (t>=-1.5 & t<-0.5);
y4 = finalsystems(t, x4);

figure;
plot(t, y1, 'r');
grid on;
hold on;
plot (t, y4, 'b');
title('Time Invariance Test');
xlabel('Time t (s)');
ylabel('Signal Amplitude');
legend('y1(t)', 'y4(t)')
hold off;
