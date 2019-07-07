
include config.mk

SUBDIRS = pofunpack pof2svf

all: $(addsuffix .all,$(SUBDIRS))
$(addsuffix .all,$(SUBDIRS)):
	$(MAKE) -C $(basename $@) all

all: $(addsuffix .clean,$(SUBDIRS))
$(addsuffix .clean,$(SUBDIRS)):
	$(MAKE) -C $(basename $@) clean

.PHONY: all clean
