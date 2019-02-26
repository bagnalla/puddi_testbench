debug :
	cd Debug && make -j8

debug_run :
	cd Debug && make -j8 && cd .. && Debug/src/puddi_testbench

debug_setup :
	mkdir Debug && cd Debug && cmake -D CMAKE_BUILD_TYPE=Debug ..

gdb :
	cd Debug && make -j8 && cd .. && gdb Debug/src/puddi_testbench
