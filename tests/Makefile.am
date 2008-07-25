include $(top_srcdir)/build-aux/init.mk
include $(top_srcdir)/build-aux/autotest.mk

# Package the following files.
EXTRA_DIST += package.m4.in

# Clean atconfig (do not distribute it).
CLEANFILES += atconfig

# simple
check_PROGRAMS = simple
simple_SOURCES = simple.cc

# variant
check_PROGRAMS += variant
variant_SOURCES = variant.cc

# access-notifier
check_PROGRAMS += access-notifier
access_notifier_SOURCES = access-notifier.cc

# ------------ #
# Test suite.  #
# ------------ #

TESTSUITE_AT =				\
		simple.at		\
		variant.at		\
		access-notifier.at

