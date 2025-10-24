
from ctypes import cdll
lib = cdll.LoadLibrary('./cpps/myFunc.so')

x = 5

print( f"%i : "%x )

print( lib.upOnePow )

x = lib.upOnePow(x)

print( f"%i\n"%x )