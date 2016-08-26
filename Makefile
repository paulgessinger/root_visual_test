.PHONY: all test run clean
.PRECIOUS: run/%.png diff/%.png

MACRO := $(wildcard macro/*.C)
RUN := $(patsubst macro/%.C, run/%.png, $(MACRO))
DIFFS := $(patsubst macro/%.C, diff/%.png, $(MACRO))
OUTS := $(patsubst macro/%.C, out/%.png, $(MACRO))

all: $(OUTS)

clean:
	-rm run/* diff/* out/*

run: $(RUN)

run/%.png: macro/%.C
	-rm $@
	root -l -q -b -x $<


diff/%.png: ref/%.png run/%.png
	-compare -metric AE -compose src  $^ $@

out/%.png: ref/%.png run/%.png diff/%.png
	convert $^ +append $@
