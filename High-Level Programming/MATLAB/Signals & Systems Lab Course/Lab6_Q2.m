clear all; % Clear all existing variables and figures from memory - fresh start

T0=4; % The fundamental period

Kmax=10;
k=-Kmax:Kmax;
ak = (sin(k*(pi/2)))./(pi*k);
ak(Kmax+1)= 1/2;

[x10,t10]=ctfs_synthesis(T0,ak);

tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t10,x10,'g','LineWidth',4);
axis([-4 4 -0.5 1.5]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=50; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (sin(k*(pi/2)))./(pi*k); % Overwriting the values in ak
ak(Kmax+1)= 1/2; % Overwriting the value in ak(Kmax+1)

[x50,t50]=ctfs_synthesis(T0,ak);

plot(t50,x50,'b','LineWidth',3);
axis([-4 4 -0.5 1.5]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=100; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (sin(k*(pi/2)))./(pi*k); % Overwriting the values in ak
ak(Kmax+1)= 1/2; % Overwriting the value in ak(Kmax+1)

[x100,t100]=ctfs_synthesis(T0,ak);

plot(t100,x100,'r','LineWidth',2);
axis([-4 4 -0.5 1.5]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold off;

title('Reconstructed signal x(t)');
legend('x(t) when Kmax = 10', 'x(t) when Kmax = 50', 'x(t) when Kmax = 100');