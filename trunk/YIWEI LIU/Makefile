
gcc -c  -DSTDC_HEADERS=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_ALLOCA_H=1 -g hello.c
gcc -c  -DSTDC_HEADERS=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_ALLOCA_H=1 -g version.c
gcc -c  -DSTDC_HEADERS=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_ALLOCA_H=1 -g getopt.c

ALL: hallo hello
CC	=	gcc
OBJECTS	=	getopt.o        hallo.o	        version.o
DIFF    =       diff
.SUFFIXES:	.c	.o	
hallo hello:	$(OBJECTS)	
	 $(CC)	-o	$@	$(OBJECTS)
	
.c.o:	
	 $(CC)	-c	$(CFLAGS)	$(CPPFLAGS)	-o	$@	$<	
getopt.o:	getopt.h


depend:
 	(for file in $(SOURCES); do \
 	$(CC) -M $$file; \
 	done) > Makedeps
-include Makedeps

patch: 
	@diff -u hello.c hallo.c > hello_de.patch		

clean: 
	@rm -f *.o hallo


