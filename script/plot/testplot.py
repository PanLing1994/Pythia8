import numpy as np
from matplotlib import pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
from scipy.optimize import curve_fit
from matplotlib.pyplot import MultipleLocator

pp   = PdfPages('D0 and D0_star_bar.pdf')
tmp1 = plt.figure(1)
plot = open('D0_and_D0_star_bar-0.dat')
plot = [line.split() for line in plot]
valx = [float(x[0]) for x in plot]
valy = [float(x[1]) for x in plot]
vale = [float(x[2]) for x in plot]

#x_major_locator=MultipleLocator(1)
#y_major_locator=MultipleLocator(10)

plt.scatter(valx,80*np.log10(valy),alpha=0.5)

#plt.scatter(valx, valy, alpha=0.5) 
#plt.hist( valx, vale, weights = valy, histtype='stepfilled', color='orange', label=r'D0')
#plt.plot(valx,np.log10(valy),'r-',linewidth=2, label=u'loge(x)')#log10(x)
"""
x = valx
num1 = valy
y1 = np.array(num1)
def func(x, a, b, c):
    return a * x**2+b*x + c
plot1 = plt.plot(x, y1, 'ms',label='orig1')
 
popt, pcov = curve_fit(func, x, y1)
yy2 = [func(i, popt[0],popt[1],popt[2]) for i in x]
plt.plot(x, yy2, 'r-', label='fit')
"""
'''
x = valx
num1 = valy
y1 = np.array(num1)
f1 = np.polyfit(x, y1, 6)
p1 = np.poly1d(f1)
print(p1)
yvals1 = p1(x)
plot1 = plt.plot(x, y1, 's',label='original values')
plot2 = plt.plot(x, yvals1, 'r',label='polyfit values')
'''
"""
plot = open('D0 and D0_star_bar-1.dat')
plot = [line.split() for line in plot]
valx = [float(x[0]) for x in plot]
valy = [float(x[1]) for x in plot]
vale = [float(x[2]) for x in plot]
plt.hist( valx, vale, weights = valy, histtype='step', color='royalblue', label=r'D0_star_bar')
plt.ticklabel_format(axis='y', style='sci', scilimits=(-2,3))
plt.legend(frameon=False,loc='best')
"""

plt.title(r'7 TeV at |y| < 0.5')
plt.xlabel(r'pT distribution')
plt.ylabel(r'nEvents')

pp.savefig(tmp1,bbox_inches='tight')
plt.clf()
pp.close()
