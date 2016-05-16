.PHONY: clean All

All:
	@echo "----------Building project:[ wf - Release ]----------"
	@"$(MAKE)" -f  "wf.mk"
clean:
	@echo "----------Cleaning project:[ wf - Release ]----------"
	@"$(MAKE)" -f  "wf.mk" clean
