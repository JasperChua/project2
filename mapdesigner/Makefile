##############################################################################
#
# ICT1002 Assignment 2, 2017-18 Trimester 1.
#
# You can use this file to build the Campus Designer using nmake (on Windows)
# or make (on Unix and MacOS X).
#
# Use the top settings for Microsoft compilers (i.e. Visual Studio) and the
# lower settings for GNU compilers (MacOS X, MinGW and Linux). Use the #
# character to comment out whichever settings you don't want.
#
###############################################################################

#
# Use the following settings for Microsoft compilers (Visual Studio).
#
CC       = cl
CFLAGS   = /nologo /c /Fo:
LD       = link
LDFLAGS  = /nologo /out:
LDLIBS   = user32.lib
RM       = del
O        = .obj
X        = .exe

#
# Use the following settings for MacOS, MinGW and Linux.
#
#CC       = gcc
#CFLAGS   = -c -o
#LD       = gcc
#LDFLAGS  = -o 
#LDLIBS   =
#RM       = rm -f
#O        = .o
#X        =


###############################################################################
#
# Do not change anything below this line
#
###############################################################################

campus1002$(X): commands$(O) features$(O) main$(O) map$(O)
	$(LD) $(LDFLAGS)campus1002$(X) commands$(O) features$(O) main$(O) map$(O) $(LDLIBS)

commands$(O): commands.c campus1002.h
	$(CC) $(CFLAGS) commands$(O) commands.c

features$(O): features.c campus1002.h
	$(CC) $(CFLAGS) features$(O) features.c
	
main$(O): main.c campus1002.h
	$(CC) $(CFLAGS) main$(O) main.c

map$(O): map.c campus1002.h
	$(CC) $(CFLAGS) map$(O) map.c
	
clean:
	$(RM) *$(O)
