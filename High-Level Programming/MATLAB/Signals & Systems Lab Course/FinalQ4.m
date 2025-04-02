clear all; % Clear all existing variables and figures from memory - fresh start

T0=4; % The fundamental period

Kmax=5;
k=-Kmax:Kmax;
ak = (sin(k*(pi/3))./(pi*k)); 
ak(Kmax+1)= 1/3;

[x5,t5]=ctfs_synthesis(T0,ak);

tLayout = tiledlayout(1,1, 'Padding', 'none'); 
nexttile;
plot(t5,x5,'g','LineWidth',4);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=20; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (sin(k*(pi/3))./(pi*k)); 
ak(Kmax+1)= 1/3;

[x20,t20]=ctfs_synthesis(T0,ak);

plot(t20,x20,'b','LineWidth',3);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold on;


Kmax=100; % Overwriting the value in Kmax
k=-Kmax:Kmax; % Overwriting the value in k
ak = (sin(k*(pi/3))./(pi*k)); 
ak(Kmax+1)= 1/3;

[x100,t100]=ctfs_synthesis(T0,ak);

plot(t100,x100,'r','LineWidth',2);
axis([-4 4 -0.5 1.2]);
grid on;
xlabel('Time t (s)');
ylabel('x(t): Signal Amplitude');
hold off;

title('Reconstructed signal x(t)');
legend('x(t) when Kmax = 5', 'x(t) when Kmax = 20', 'x(t) when Kmax = 100');