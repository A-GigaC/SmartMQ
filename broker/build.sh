rm -rf build

conan install .
cmake -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

cmake --build .

./SmartMQ.broker