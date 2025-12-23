# for the mac aka linux professionals
# before you run this remember to call chmod +x build-run-mac.sh to permit execution
# and to run it from the terminal with ./build-run-mac.sh

cd "$(dirname "$0")"

cmake -S . -B build
cmake --build build

./build/fluid_sim