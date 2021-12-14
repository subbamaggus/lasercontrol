pwd=`pwd`

if [ ! -e build ]; then
  mkdir build
fi

cd build

rm -rf *

cmake ..

cmake --build .

tst/Debug/app_project_tst.exe

cd ${pwd}