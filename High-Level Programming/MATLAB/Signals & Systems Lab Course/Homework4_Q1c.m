clear all;

figure;
w=-3*pi:0.01:3*pi;
x=6*exp(-1j*3*w)./(9+(w.^2));
plot(w,abs(x),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
xlabel('Frequency');
ylabel('Magnitude');
title('X1(j0)');
grid on;

figure;
w=-3*pi:0.01:3*pi;
x=(10 * sin(2 * w)) ./ w;
plot(w,abs(x),'Color',[0.6350, 0.0780, 0.1840],'LineWidth',2);
xlabel('Frequency');
ylabel('Magnitude');
title('X2(j0)');
grid on;