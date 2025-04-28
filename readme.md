# 执行程序
conan install . --output-folder=build --build=missing -s build_type=Debug

cmake --preset conan-debug

conanfile.txt: CMakeToolchain: Preset 'conan-debug' added to CMakePresets.json.
    (cmake>=3.23) cmake --preset conan-debug
    (cmake<3.23) cmake <path> -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake  -DCMAKE_POLICY_DEFAULT_CMP0091=NEW -DCMAKE_BUILD_TYPE=Debug