function [Zvec,pv,qv,n2]=zernike(x,pmax)
% function [Zvec,pv,qv,n2]=zernike(x,pmax);
%
% Generate set of vectors of first N zernike basis functions over COMPLEX 
% position vector x.  Also return vector of p,q corresponding to columns of Zvec
% Set is generated up to pmax, and ordered approx. based on gradient, so that for
% each p, q=p is before q=p-2 etc.
%
% Modified DGM from zernike and zernikev, 2/5/02
% D. MacMartin 10/22/01
%
% Modified PMT to get Zernike mode sequence according to Noll ordering.
% Function name was renamed from zernike2 to zernike to avoid issues in
% scripts that used the previous version.
% R. A. Romano 9/16/20
%

j=sqrt(-1);			% ensure = sqrt(-1)
nx=length(x);
Zvec=[ones(nx,1)/sqrt(nx) real(x) -imag(x)];
pv=[0;1;1];
qv=[0;1;-1];    % pmt 6-29-09
rmax=max(abs(x));
r=abs(x)/rmax;
th=atan2(imag(x),real(x));
R=zeros(size(r));
sw_cplx_modes = false;
for p=2:pmax
   for q=fliplr(p:-2:0)			% fliplr to get pmt 6-29-09; changed rar 9-16-21.
      R=0*R;
      for s=0:(p-q)/2
         fac=(-1)^s*factorial(p-s)/(factorial(s)*factorial((p+q)/2-s)*factorial((p-q)/2-s));
         R=R+fac*r.^(p-2*s);
      end
      Z=R.*exp(q*j*th);
      if q==0
         Zvec=[Zvec Z];
         pv=[pv;p];
         qv=[qv;q];
         sw_cplx_modes = ~sw_cplx_modes;
      else
         if sw_cplx_modes   % rar 9-16-20: Noll ordering --- CEO compatibility
            Zvec=[Zvec -imag(Z) real(Z)];
         else
            Zvec=[Zvec real(Z) -imag(Z)];
         end
         pv=[pv;p;p];
         qv=[qv;q;q];   % rar 9-16-20: Noll ordering --- CEO compatibility
%          qv=[qv;q;-q]; % pmt 6-29-09
        
      end
%       fprintf('p=%.2g,q=%.2g\n',p,q)
   end
end
[~,n2]=size(Zvec);
%
% Ensure orthogonality over finite grid:
%
for i=2:n2
   Zvec(:,i)=Zvec(:,i)-Zvec(:,1:i-1)*(Zvec(:,1:i-1)'*Zvec(:,i));
   Zvec(:,i)=Zvec(:,i)/sqrt(Zvec(:,i)'*Zvec(:,i));
end

end

