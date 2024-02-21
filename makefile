all : minlex.4.LS.exe minlex.4.2Rx2C.exe \
		maxlex.4.LS.exe maxlex.4.2Rx2C.exe \
		minlex.5.LS.exe \
		maxlex.5.LS.exe \
		minlex.6.LS.exe minlex.6.2Rx3C.exe minlex.6.3Rx2C.exe \
		maxlex.6.LS.exe maxlex.6.2Rx3C.exe maxlex.6.3Rx2C.exe \
		minlex.7.LS.exe \
		maxlex.7.LS.exe \
		minlex.8.LS.exe minlex.8.2Rx4C.exe minlex.8.4Rx2C.exe \
		maxlex.8.LS.exe maxlex.8.2Rx4C.exe maxlex.8.4Rx2C.exe \
		minlex.9.LS.exe minlex.9.3Rx3C.exe \
		maxlex.9.LS.exe maxlex.9.3Rx3C.exe

# 4

minlex.4.2Rx2C.exe : canonical.4.2Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.4.2Rx2C.c -o minlex.4.2Rx2C.exe

maxlex.4.2Rx2C.exe : canonical.4.2Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.4.2Rx2C.c -o maxlex.4.2Rx2C.exe -D_MAXLEX=1

minlex.4.LS.exe : canonical.4.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.4.LS.c -o minlex.4.LS.exe

maxlex.4.LS.exe : canonical.4.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.4.LS.c -o maxlex.4.LS.exe -D_MAXLEX=1

# 5

minlex.5.LS.exe : canonical.5.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.5.LS.c -o minlex.5.LS.exe

maxlex.5.LS.exe : canonical.5.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.5.LS.c -o maxlex.5.LS.exe -D_MAXLEX=1

# 6

minlex.6.2Rx3C.exe : canonical.6.2Rx3C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.2Rx3C.c -o minlex.6.2Rx3C.exe

maxlex.6.2Rx3C.exe : canonical.6.2Rx3C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.2Rx3C.c -o maxlex.6.2Rx3C.exe -D_MAXLEX=1

minlex.6.3Rx2C.exe : canonical.6.3Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.3Rx2C.c -o minlex.6.3Rx2C.exe

maxlex.6.3Rx2C.exe : canonical.6.3Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.3Rx2C.c -o maxlex.6.3Rx2C.exe -D_MAXLEX=1

minlex.6.LS.exe : canonical.6.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.LS.c -o minlex.6.LS.exe

maxlex.6.LS.exe : canonical.6.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.6.LS.c -o maxlex.6.LS.exe -D_MAXLEX=1

# 7

minlex.7.LS.exe : canonical.7.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.7.LS.c -o minlex.7.LS.exe

maxlex.7.LS.exe : canonical.7.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.7.LS.c -o maxlex.7.LS.exe -D_MAXLEX=1

# 8

minlex.8.2Rx4C.exe : canonical.8.2Rx4C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.2Rx4C.c -o minlex.8.2Rx4C.exe

maxlex.8.2Rx4C.exe : canonical.8.2Rx4C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.2Rx4C.c -o maxlex.8.2Rx4C.exe -D_MAXLEX=1

minlex.8.4Rx2C.exe : canonical.8.4Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.4Rx2C.c -o minlex.8.4Rx2C.exe

maxlex.8.4Rx2C.exe : canonical.8.4Rx2C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.4Rx2C.c -o maxlex.8.4Rx2C.exe -D_MAXLEX=1

minlex.8.LS.exe : canonical.8.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.LS.c -o minlex.8.LS.exe

maxlex.8.LS.exe : canonical.8.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.8.LS.c -o maxlex.8.LS.exe -D_MAXLEX=1

# 9

minlex.9.3Rx3C.exe : canonical.9.3Rx3C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.9.3Rx3C.c -o minlex.9.3Rx3C.exe

maxlex.9.3Rx3C.exe : canonical.9.3Rx3C.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.9.3Rx3C.c -o maxlex.9.3Rx3C.exe -D_MAXLEX=1

minlex.9.LS.exe : canonical.9.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.9.LS.c -o minlex.9.LS.exe

maxlex.9.LS.exe : canonical.9.LS.c
	gcc.exe -flto -s -static -static-libgcc -O3 -march=native canonical.9.LS.c -o maxlex.9.LS.exe -D_MAXLEX=1

