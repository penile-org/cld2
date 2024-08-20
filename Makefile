all: libcld2.a

CXX=clang++-16

libcld2.a:
	cd internal && CFLAGS="-Wno-c++11-narrowing -std=c++11" ./compile_libs.sh $(CXX)
	mv internal/libcld2.a libcld2.a
cld2wrap.o: cld2wrap.cpp
	$(CXX) -c cld2wrap.cpp
test: libcld2.a cld2wrap.o test.c
	$(CC) -o test test.c cld2wrap.o libcld2.a -lstdc++
clean:
	rm -f libcld2.* cld2wrap.o test
