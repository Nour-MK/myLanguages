clear all;
k=[-10:1:10];
ak=(j*(exp(-j*k*2*pi/3)-2*exp(j*k*2*pi/3)+1))./(2*pi*k);
ak(11)=1; %This is a0

figure;
stem(k,abs(ak));
grid on;
xlabel('k'); 
ylabel('Magnitude of ak)');

figure;
stem(k,angle(ak));
grid on;
xlabel('k'); 
ylabel('Phase angle of ak)');