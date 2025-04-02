% Keep in mind that the name of the MATLAB script file does not necessarily have to match the function name.
% However, if you plan to use this function in other MATLAB scripts or call it from the MATLAB command line, 
% the script file should be saved with the same name as the function (excluding the .m extension). 
% This is because MATLAB requires that the filename and the function name match for easy identification and execution.
% It's a good practice to keep the function name and script filename consistent for clarity and ease of use

function [x,t]=ctfs_synthesis(T0,ak) % User-defined function to implement continuous time Fourier series synthesis equation
 
% Variables:
%        Inputs:
%               T0 = fundamental period
%               ak = Fourier series coefficients

%        Outputs:
%                t = vector of times function computes values for 2 periods
%                x = x(t), samples of the periodic time signal

Kmax=(length(ak)-1)/2;

maxfreq=Kmax/T0; % Sampling frequency of the signal x(t)
  t=-T0:1/(8*maxfreq):T0; %sample at four times Nyquist rate

w0=2*pi/T0;				% Fundamental frequency
k=-Kmax:Kmax;           % Vector of k's

Ek=exp(j*t'*k*w0);		% Matrix of complex exponentials

ak=ak(:);				% Make sure ak is column vector

x=Ek*ak;				% Compute x as matrix multiply


if max(abs(imag(x)))<100*eps		% Make sure x is real, 100*eps is on order of 2*10^(-14).
  x=real(x);				% (eliminate small imaginary part)
end

end