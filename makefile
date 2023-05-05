HDIR = headers# directories/folders
CDIR = src
ODIR = objs
CPPFLAGS = -std=c++11 -g# flags -g for debugging
DEPS = $(wildcard $(HDIR)/*.h)
SOURCE = $(wildcard $(CDIR)/*.cpp)# essentially equals everything in CDIR that has ending of .cpp
OBJS = $(patsubst $(CDIR)/%.cpp, $(ODIR)/%.o, $(SOURCE))# replaces everything in source ending in arg1 with arg2
vpath %.h headers# basically a search function
vpath %.cpp src
vpath %.o objs
DIRS = $(HDIR) $(CDIR) $(ODIR)
$(shell mkdir -p $(DIRS))# makes all directories if it's not there

$(ODIR)/%.o: %.cpp $(DEPS)
    g++ $(CPPFLAGS) -c $< -o $@

singleLevelDirectory: $(OBJS)
    g++ $(CPPFLAGS) -o $@ $^

clean:
    rm $(ODIR)/*.o singleLevelDirectory *.wav

.PHONY: clean all
