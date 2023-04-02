###################################################
##   			TOP LEVEL MAKEFILE               ##
###################################################

# This makefile is used to wrap some of the ceedling
# commands to make them easier to run in the terminal

all:
	@echo "                                                                 "
	@echo "#################################################################"
	@echo "                     Supported Commands                          "
	@echo "#################################################################"
	@echo "                                                                 "
	@echo "    make clean     --- Remove all build artifacts ---"
	@echo "    make release   --- Run all unit tests and build release images ---"
	@echo "    make build     --- Build release image only ---"
	@echo "    make test      --- Run all unit tests ---"
	@echo "                                                                 "

# Remove all the build artifacts
.PHONY: clean
clean:
	ceedling clobber
	rm stmBase.map

# Run all unit tests and build release image
.PHONY: release
release:
	ceedling verbosity[4] test:all release

# Run all unit tests
.PHONY: test
test:
	ceedling test:all

# Build release image only
.PHONY: build
fw_stm32:
	ceedling release