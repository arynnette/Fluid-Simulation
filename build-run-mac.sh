# for the mac loser
# before you run this remember to call chgr +x build-run-mac.sh to make it executable
#and then you can run it like a cool person

cd "$(dirname "$0")"

rm -rf build

cmake -B build
cmake --build build

./build/fluid_sim