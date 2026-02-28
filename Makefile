# 1. 动态获取 macOS 下 Homebrew 的前缀路径
# 如果是 M1/M2/M3 Mac，通常是 /opt/homebrew
# 如果是 Intel Mac，通常是 /usr/local
# 如果没安装 brew，则回退到空字符串
BREW_PREFIX := $(shell brew --prefix 2>/dev/null || echo "")

# 2. 定义包含路径 (Include Paths)
# 将项目 include 目录和 brew 的 include 目录都加进去
INC_FLAGS := -I include
ifneq ($(BREW_PREFIX),)
    INC_FLAGS += -I $(BREW_PREFIX)/include
endif

# 3. 定义库文件搜索路径 (Library Paths) 和 链接库 (Libraries)
# 注意：LIBS 只在最后链接可执行文件时使用
LDFLAGS :=
LIBS :=
ifneq ($(BREW_PREFIX),)
    LDFLAGS += -L $(BREW_PREFIX)/lib
endif
# 添加需要的库
LIBS += -lgmp -lgmpxx -lssl -lcrypto

# 编译器设置
CXX := g++
# 添加一些常用警告和标准设置
CXXFLAGS := -std=c++17 -Wall -Wextra

# ---------------------------------------------------------
# 目标规则
# ---------------------------------------------------------

all: bin/main

# 编译 main.cpp
# 修正：只使用 INC_FLAGS，不使用 LIBS (因为 -c 不需要链接库)
build/main.o: src/main.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

# 编译 lib 下的所有 cpp
# 修正：只使用 INC_FLAGS
build/lib/%.o: src/lib/%.cpp
	@mkdir -p build/lib
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

# 编译 sm2 下的所有 cpp
# 修正：只使用 INC_FLAGS
build/sm2/%.o: src/sm2/%.cpp
	@mkdir -p build/sm2
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INC_FLAGS)

# ---------------------------------------------------------
# 局部链接 (Partial Linking) - 修正 ld -r 问题
# ---------------------------------------------------------

# 修正：使用 $(CXX) -r 代替 ld -r
# macOS 的 ld 直接调用容易出错，g++ -r 会正确处理 Mach-O 格式
build/sm2/sm2-sign-imple.o: build/sm2/sm2.o build/sm2/sign.o build/sm2/verify.o
	@mkdir -p build/sm2
	$(CXX) -r $^ -o $@

build/lib/mathlib.o: build/lib/finiteField.o build/lib/finiteFieldElement.o build/lib/ellipticCurve.o build/lib/ellipticCurvePoint.o
	@mkdir -p build/lib
	$(CXX) -r $^ -o $@

# ---------------------------------------------------------
# 最终链接
# ---------------------------------------------------------

# 修正：在这里加上 $(LDFLAGS) 和 $(LIBS)
# 注意：库文件顺序有时很重要，通常放在最后
bin/main: build/lib/mathlib.o build/main.o build/sm2/sm2-sign-imple.o build/lib/sha256.o
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) $(LIBS)

clean:
	rm -rf ./build/*
	rm -rf ./bin/*

.PHONY: all clean