GMP_IN := -lgmp -lgmpxx -lssl -lcrypto -I include

all: bin/main

build/main.o: src/main.cpp
	@mkdir -p build
	g++ -c $^ -o $@ $(GMP_IN)

build/lib/%.o: src/lib/%.cpp
	@mkdir -p build/lib/
	g++ -c $^ -o $@  $(GMP_IN)

build/sm2/%.o: src/sm2/%.cpp
	@mkdir -p build/sm2/
	g++ -c $^ -o $@  $(GMP_IN)

# build/main.o: tests/main.cpp 
# 	@mkdir -p build/
# 	g++ -c $^ -o $@ -I include $(GMP_IN)

build/sm2/sm2-sign-imple.o: build/sm2/sm2.o build/sm2/sign.o build/sm2/verify.o
	@mkdir -p build/sm2
	ld -r -o $@ $^

build/lib/mathlib.o:build/lib/finiteField.o build/lib/finiteFieldElement.o build/lib/ellipticCurve.o build/lib/ellipticCurvePoint.o 
	@mkdir -p build/lib/
	ld -r -o $@ $^

bin/main: build/lib/mathlib.o build/main.o build/sm2/sm2-sign-imple.o build/lib/sha256.o
	@mkdir -p bin/
	g++ -o bin/main $^ $(GMP_IN)

clean:
	rm -rf ./build/*
	rm -rf ./bin/*