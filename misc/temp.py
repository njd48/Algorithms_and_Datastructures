# -*- coding: utf-8 -*-
"""
Approximations
"""

#---------------------------------------------------------#
#  Trying for utilitarian approximations of square root   #
#---------------------------------------------------------#


import numpy as np
import matplotlib.pyplot as plt

#------------------------------------------------------------------------------
def sqrt_apx0( x ):
    y = 1+x//(2**16)
    return y

def sqrt_apx1( x ):
    y = sqrt_apx0(x)
    y = (y*y+x)//(2*y)  # one newton step
    return y

def sqrt_apxn( x, n ):
    y = sqrt_apx0(x)
    for i in range(0,n):
        y = (y*y+x)//(2*y)  # one newton step
    return y

#------------------------------------------------------------------------------

x  = 2**np.linspace( 2, 16, 63  )

z  = np.sqrt(x)
y0 = sqrt_apx0( x )
y1 = sqrt_apx1( x )
yn = sqrt_apxn( x , 4 )

err = abs( yn - z ) 

#------------------------------------------------------------------------------

# plt.style.use('ggplot')

fig = plt.figure()
plt.scatter( x,z  , label='exact' )
plt.scatter( x,y0 , label='apx0' )
#plt.scatter( x,y1 , label='apx1' )
plt.scatter( x,yn , label='apxn' )
plt.legend()
plt.show()

fig = plt.figure()
plt.loglog( x, err, label='error' )
plt.legend()
plt.show()