IDIR=./
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Wextra -pedantic-errors -O2 -pthread

RB_DIR=red_black_tree
AVL_dir=AVL_tree


binary_tree: classic_binary_tree/test_tree.cpp
	$(CXX) -o binary_tree.exe $(CXXFLAGS) classic_binary_tree/test_tree.cpp

	./binary_tree.exe

.PHONY: clean

RB_tree: $(RB_DIR)/test_rbtree.cpp
#	$(CXX) -o bin1.exe $(CXXFLAGS) $(RB_DIR)/test_bintree.cpp
	$(CXX) -o RB1.exe $(CXXFLAGS) $(RB_DIR)/test_rbtree.cpp

#	./bin1.exe
	./RB1.exe

.PHONY: clean

AVL_tree: $(AVL_DIR)/test_AVLtree.cpp
#	$(CXX) -o bin1.exe $(CXXFLAGS) $(RB_DIR)/test_bintree.cpp
	$(CXX) -o AVL1.exe $(CXXFLAGS) $(AVL_DIR)/test_AVLtree.cpp

#	./bin1.exe
	./AVL1.exe

.PHONY: clean

AVL_compare: $(AVL_DIR)/test_compare_trees.cpp
	$(CXX) -o compare_trees.exe $(CXXFLAGS) $(AVL_DIR)/test_compare_trees.cpp

	./compare_trees.exe

.PHONY: clean

#build: *.cpp
#	$(CXX) -o assignment.exe $(CXXFLAGS) *.cpp

#.PHONY: clean

clean:
	rm -f a.out 
	rm -f binary_tree.exe
	rm -f RB_tree.exe
	rm -f bin1.exe
	rm -f RB1.exe
	rm -f AVL1.exe
	rm -f compare_trees.exe

#run:
#	./assignment.exe $(ARGS)