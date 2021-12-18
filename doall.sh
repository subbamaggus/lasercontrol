pwd=`pwd`

if [ ! -e build ]; then
  mkdir build
fi

cd ${pwd}/build

if [ "${1}" == "all" ]; then
  rm -rf *

  cmake ..
  
  cp ../example.ini ./
fi

cmake --build .

./tst/Debug/app_project_tst.exe

./src/Debug/app_project_run.exe

cd ${pwd}