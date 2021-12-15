pwd=`pwd`

if [ ! -e build ]; then
  mkdir build
fi

cd build

if [ "${1}" == "all" ]; then
  rm -rf *

  cmake ..
fi

cmake --build .

tst/Debug/app_project_tst.exe
src/Debug/app_project_run.exe

cd ${pwd}