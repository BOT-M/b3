# 执行程序
conan install . --output-folder=build --build=missing -s build_type=Debug

cmake --preset conan-debug