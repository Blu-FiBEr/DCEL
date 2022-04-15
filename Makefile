#for all .o targets this will compile corresponding .cpp file
%.o: %.cpp main.hpp
	g++ -c $<
#assignment3 executable 
assignment3: main.o display_dcel.o display_edges.o display_hedges.o display_faces.o display_IDs.o find_endvertex.o find_previousedge.o find_nextedge.o split.o orientation.o is_inside.o is_type1.o is_type2.o edge_constructor.o dcel_constructor.cpp
	g++ -o $@ $^
#clean all created executables
clean:
	rm *.o assignment3
