CXX_C=g++
CXX_DEBUG_FLAGS=-ggdb -Og -Wall -Wextra -fsanitize=address,undefined
CXX_RELEASE_FLAGS=-O3 -ffast-math -Wall -Wextra -Werror -flto -march=native -fPIE -fprofile-generate
GAME_NAME=game


default: debug

debug: $(wildcard *.cpp) $(wildcard *.h)
	$(CXX_C) $(CXX_DEBUG_FLAGS) -o $@ $(wildcard *.cpp)

release:
	$(CXX_C) $(CXX_RELEASE_FLAGS) -o game $(wildcard *.cpp)
