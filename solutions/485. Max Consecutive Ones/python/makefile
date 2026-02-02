.PHONY: tests
tests:
	@echo "RESULTS:"
	@python -m unittest -v test_solution.py
	@echo ""
	@echo "BENCHMARK:"
	@python -m timeit \
		-n 100 \
		-r 100  \
		--setup "from solution import findMaxConsecutiveOnes; nums = [1, 1, 0, 1, 1, 1]" \
		"findMaxConsecutiveOnes(nums)"

