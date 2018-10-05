mkdir tbin
mkdir bin
mkdir lib
cd src
for d in ./* ; do
  [ -d "${d}" ] || continue
  cd $d
  mkdir tbin
  mkdir bin
  cd ..
done
export LD_LIBRARY_PATH=~/CSTL/lib:D_LIBRARY_PATH
