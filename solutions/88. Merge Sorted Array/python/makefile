.PHONY: tests
tests:
	@echo "RESULTS:"
	@python -m unittest -v test_solution.py
	@echo ""
	@echo "BENCHMARK:"
	@python -m timeit \
		-n 100 \
		-r 100  \
		--setup "from solution import merge; nums1, m = [1,2,3,0,0,0], 3; nums2, n = [2,5,6], 3" \
		"merge(nums1, m, nums2, n)"

