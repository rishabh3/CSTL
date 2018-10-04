mkdir tbin
mkdir bin
cd src
for d in */ ; do
  cd $d
  mkdir tbin
  mkdir bin
  cd ..
done
make
export LD_LIBRARY_PATH=~/CSTL/lib:D_LIBRARY_PATH
