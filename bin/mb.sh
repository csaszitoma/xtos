rm sys.old
mv sys.mod sys.old
cd ../src
make clean all
cd ../bin
qemu-system-x86_64 -kernel sys.mod

