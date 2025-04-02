clear all;
w=(-pi/2):0.01:(pi/2);
x1=16*(cos(4*w));
x2=-8*j*sin(3*w);
subplot(211);
plot(w,abs(x1),'r', 'linewidth', 2);
hold on;
plot(w,abs(x2),'k', 'linewidth', 2);
grid on;
xlabel('Frequency');
ylabel('Magnitudes');
legend('|X1(jw)|','|X2(jw)|');

axis([-2 2 0 20])
subplot(212);
plot(w,angle(x1),'b', 'linewidth', 2);
hold on;
plot(w,angle(x2),'g', 'linewidth', 2);
grid on;
xlabel('Frequency');
ylabel('Phase');
legend('<X1(jw)','<X2(jw)');