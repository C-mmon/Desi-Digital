 dotProduct(SparseVector& vec) {
        int i = 0, j = 0;
        int result = 0;
        
        while (i < idx_value_pairs.size() && j < vec.idx_value_pairs.size()) {
            if (idx_value_pairs[i].first < vec.idx_value_pairs[j].first) {
                i++;
            } else if (idx_value_pairs[i].first > vec.idx_value_pairs[j].first) {
                j++;
            } else {
                result += (idx_value_pairs[i].second * vec.idx_value_pairs[j].second);
                i++;
                j++;
            }
        }
        
        return result;
