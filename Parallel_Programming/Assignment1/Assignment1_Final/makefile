
compiler = g++
FLAGS = -O3 

p1_files = binomial.cpp trig_ratio.cpp matrix_A.cpp matrix_B.cpp main_matrixC.cpp
p3a_files = binomial.cpp trig_ratio.cpp matrix_A.cpp matrix_B.cpp write_A_B.cpp
p3b_files = binomial.cpp trig_ratio.cpp matrix_A.cpp matrix_B.cpp read_AB_compute_C.cpp
p6a_files = binomial.cpp trig_ratio.cpp matrix_Ap6.cpp matrix_Bp6.cpp matrix_Cp6.cpp write_CNi.cpp
p6b_files = read_CNi.cpp



all:	p1_exe	p3	p6
p3:		p3a_exe	p3b_exe
p6:		p6a_exe	p6b_exe

p1_exe: $(p1_files)
		$(compiler) $(FLAGS) $(p1_files) -o $@

p3a_exe: $(p3a_files)
		$(compiler) $(FLAGS) $(p3a_files) -o $@

p3b_exe: $(p3b_files)
		$(compiler) $(FLAGS) $(p3b_files) -o $@

p6a_exe: $(p6a_files)
		$(compiler) $(FLAGS) $(p6a_files) -o $@

p6b_exe: $(p6b_files)
		$(compiler) $(FLAGS) $(p6b_files) -o $@


clean:
		rm *_exe

