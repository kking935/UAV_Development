# This is a GNU make makefile.
#
#
SKIP_LIST :=

CXXFLAGS ?= -g -Wall


BINS := $(filter-out $(SKIP_LIST), $(patsubst %.cpp, %, $(wildcard *.cpp)))


# Some programs link with additional libraries:
rx_ascii_art_dft_LDFLAGS := -lncurses
benchmark_streamer_LDFLAGS := -lpthread
benchmark_rate_LDFLAGS := -lboost_thread
network_relay_LDFLAGS := -lboost_thread -lpthread
txrx_loopback_to_file_LDFLAGS := -lboost_filesystem -lboost_thread
test_clock_synch_LDFLAGS := -lboost_thread



UHD_LDFLAGS :=\
 $(shell pkg-config uhd --libs)\
 -Wl,-rpath=$(shell pkg-config uhd --variable=libdir)\
 -lboost_program_options


UHD_CPPFLAGS := $(shell pkg-config uhd --cflags)


# These are the tared files that we download
TARED_FILES := benchmark_rate.cpp benchmark_streamer.cpp gpio.cpp latency_test.cpp network_relay.cpp replay_samples_from_file.cpp rfnoc_nullsource_ce_rx.cpp rfnoc_radio_loopback.cpp rfnoc_rx_to_file.cpp rx_ascii_art_dft.cpp rx_multi_samples.cpp rx_samples_to_file.cpp rx_samples_to_udp.cpp rx_timed_samples.cpp sync_to_gps.cpp test_clock_synch.cpp test_dboard_coercion.cpp test_messages.cpp test_pps_input.cpp test_timed_commands.cpp twinrx_freq_hopping.cpp tx_bursts.cpp txrx_loopback_to_file.cpp tx_samples_from_file.cpp tx_timed_samples.cpp tx_waveforms.cpp usrp_list_sensors.cpp ascii_art_dft.hpp wavetable.hpp rx_samples_c.c tx_samples_c.c


build: uhd.tar.gz $(BINS)

$(BINS): %:%.o


print:
	@echo "$(BINS)"


# Rule to make objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(UHD_CPPFLAGS) $< -o $@




$(BINS):
	$(CXX) $(CXXFLAGS) $^ -o $@ $($@_LDFLAGS) $(UHD_LDFLAGS)


clean:
	rm -f *.o $(BINS) $(TARED_FILES)
	rm -rf init_usrp/ getopt/


# Also clean downloaded files
cleaner: clean
	rm -f uhd.tar.gz


download: uhd.tar.gz


uhd.tar.gz:
	./getFiles.bash
	@echo "You'll need to run $(MAKE) again because we just got the files we needed"

