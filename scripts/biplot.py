import sys
import numpy as np
from numpy import loadtxt
import matplotlib.pyplot as plt
from matplotlib.ticker import LinearLocator
from matplotlib import cm

lines = loadtxt(sys.argv[1], comments="#", delimiter=" ", unpack=False)



P1 = lines[:,0]
P2 = lines[:,1]

stepP2 = P2[1]-P2[0]
P2max = P2[P2.size-1]
P2min = P2[0]
NP2 = round((P2max-P2min)/stepP2)
rstepP2 = (P2max-P2min)/NP2

stepP1 = P1[NP2+1]-P1[0]
P1max = P1[P1.size-1]
P1min = P1[0]
NP1 = round((P1max-P1min)/stepP1)
rstepP1 = (P1max-P1min)/NP1

P1 = np.arange(P1min, P1max+rstepP1, rstepP1)
P2 = np.arange(P2min, P2max+rstepP2, -rstepP2)
Z = np.ndarray([NP1+1, NP2+1])
for x in range(NP1+1):
    for y in range(NP2+1):
        Z[x,y]=lines[NP2*x+y,2]

X, Y = np.meshgrid(P2, P1)
fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
surf = ax.plot_surface(X, Y, Z) #cmap=cm.coolwarm, linewidth=0, antialiased=False)

# Customize the z axis.
#ax.set_zlim(80, 100)
ax.zaxis.set_major_locator(LinearLocator(10))
# A StrMethodFormatter is used automatically
#ax.zaxis.set_major_formatter('{x:.02f}')

# Add a color bar which maps values to colors.
fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()
