//Google Phone Screen Interview
// You and a friend have received a special gold chain as a gift.
// The chain links each have an integer weight, not necessarily the same
// You and your friend must choose one of the links to be removed and provided to charity,
// after which the chain will be reconnected. After that, you can choose one place along the chain to split it in two,
// such that it creates two equally-weighted sections for you and your friend to take home.
// For a given input chain (list of link weights), determine if a solution is possible

 def can_split_chain_bug_free(chain):
	n = len(chain)
	if n < 3: return False  # Cannot split if fewer than 3 links
	total_weight = sum(chain)

	#Calculate prefix and suffix sums
	prefix_sums = [0] * n
	suffix_sums = [0] * n
	prefix_sums[0] = chain[0]
	suffix_sums[-1] = chain[-1]

	for i in range(1, n):
		prefix_sums[i] = prefix_sums[i-1] + chain[i]
	for i in range(n-2, -1, -1):
		suffix_sums[i] = suffix_sums[i+1] + chain[i]

	for i in range(n):
		# Weight excluding the current link
		remaining_weight = total_weight - chain[i]
		if remaining_weight % 2 != 0: continue

		half_weight = remaining_weight // 2
		#Check if it's possible to split the chain equally by removing this link
		if (i > 0 and prefix_sums[i-1] == half_weight) or \
		   (i < n-1 and suffix_sums[i+1] == half_weight):
			return True

	return False
