TESTS = sqltranslator_test
check_PROGRAMS = sqltranslator_test
sqltranslator_test_SOURCES = \
	gtest_main.cc \
	gtest-all.cc \
	Constraint_test.cpp \
	Object_test.cpp \
	Field_test.cpp \
	Index_test.cpp \
	Table_test.cpp
sqltranslator_test_LDADD = ../src/libsqltranslator.a
sqltranslator_test_LDFLAGS = -pthread
