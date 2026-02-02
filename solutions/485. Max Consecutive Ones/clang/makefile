ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	OUTEXT=exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	OUTEXT=out
endif

CUNITPATH=/opt/homebrew/Cellar/cunit/2.1-3
BUILDPATH=build
OBJECTSPATH=$(BUILDPATH)/objs
REPORTSPATH=$(BUILDPATH)/reports

SOURCES = \
	solution.c
TESTS = $(patsubst %.c,test_%.c,$(SOURCES))
RESULTS = $(patsubst %.c,$(REPORTSPATH)/%.testreport,$(TESTS))

COMPILE=gcc -c
LINK=gcc
CFLAGS=-I. -I$(CUNITPATH)/include
LFLAGS=-L$(CUNITPATH)/lib -lcunit

.PHONY: tests
tests: $(BUILDPATH) $(RESULTS)
	@cat $(REPORTSPATH)/*.testreport

$(BUILDPATH):
	@$(MKDIR) $(BUILDPATH)
	@$(MKDIR) $(OBJECTSPATH)
	@$(MKDIR) $(REPORTSPATH)

$(REPORTSPATH)/%.testreport: $(BUILDPATH)/%.$(OUTEXT)
	@-./$< > $@ 2>&1

$(BUILDPATH)/test_%.$(OUTEXT): $(OBJECTSPATH)/%.o $(OBJECTSPATH)/test_%.o
	@$(LINK) $(LFLAGS) -o $@ $^

$(OBJECTSPATH)/%.o:: %.c
	@$(COMPILE) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	@$(CLEANUP) $(OBJECTSPATH)/*.o
	@$(CLEANUP) $(BUILDPATH)/*.$(OUTEXT)
	@$(CLEANUP) $(REPORTSPATH)/*.testreport
	@$(CLEANUP) -r $(BUILDPATH)

.PRECIOUS: $(BUILDPATH)/test_%.$(OUTEXT)
.PRECIOUS: $(OBJECTSPATH)/%.o
.PRECIOUS: $(REPORTSPATH)/%.testreport
