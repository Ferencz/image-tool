# build.sh
export CXXFLAGS="-frtti"
export CXXFLAGS_CC="-frtti"

node-gyp clean
node-gyp configure
node-gyp build
