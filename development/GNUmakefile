# This is a GNU make makefile.
#
# This is a comment.


# If not defined already
CXXFLAGS ?= -g -Wall
CFLAGS   ?= -g -Wall


# Binary programs that we can build
BINS := rx tx 2shorts_to_ascii


# variables to use
UHD_LDFLAGS :=\
 $(shell pkg-config uhd --libs)\
 -Wl,-rpath=$(shell pkg-config uhd --variable=libdir)\
 -lboost_program_options


UHD_CPPFLAGS := $(shell pkg-config uhd --cflags)



# Some programs need libuhd related compiler options
# We make them variables that we use in commands below
rx_CPPFLAGS := $(UHD_CPPFLAGS)
rx_LDFLAGS := $(UHD_LDFLAGS)

tx_CPPFLAGS := $(UHD_CPPFLAGS)
tx_LDFLAGS := $(UHD_LDFLAGS)



# the default thing to build is "build"
#
# "build" is a phoney make target so we never really build a file called
# "build"
build: $(BINS)


# programs listed in BINS depend on the corresponding object file
# and you can add more dependences
$(BINS): %:%.o


# Suffix rule for making object files from C++ files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $($@_CPPFLAGS) $< -o $@

# Suffix rule for making object files from C files
%.o: %.c
	$(CXX) $(CFLAGS) -c $($@_CPPFLAGS) $< -o $@

# Rule to make binary executables in the BINS variable
$(BINS):
	$(CXX) $(CXXFLAGS) $^ -o $@ $($@_LDFLAGS)

# How to 'make clean'
# clean is a phoney target
clean:
	rm -f *.o $(BINS)

