echo ""
echo "***"
echo "Starting x86 build"
echo "***"
echo ""
export ANDROID_NDK_ROOT=$HOME/Library/Android/sdk/ndk/25.1.8937393
export PATH=$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/darwin-x86_64/bin:$PATH
export HOST_TAG=darwin-x86_64
export TOOLCHAIN=$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/$HOST_TAG
#
# TARGET can be one of:
#  x86_64-linux-android (x86-64)
#  armv7a-linux-androideabi (armeabi-v7a)
#  aarch64-linux-android (arm64-v8a)
#  i686-linux-android (x86)
#
export TARGET=i686-linux-android
export ABI=x86

export OPENSSL_ROOT=`pwd`/..
export VERSION=33

DEST=$OPENSSL_ROOT/install-ndk/$ABI
mkdir -p $DEST
mkdir -p $TARGET$VERSION
cd $TARGET$VERSION

echo ""
echo "***"
echo "Starting x86 Configure"
echo "***"
echo ""
$OPENSSL_ROOT/Configure android-x86 --prefix=$DEST
echo ""
echo "***"
echo "Starting x86 Make"
echo "***"
echo ""
make
echo ""
echo "***"
echo "Starting x86 Install"
echo "***"
echo ""
make install
echo ""
echo "***"
echo "Done x86 build"
echo "***"
echo ""
