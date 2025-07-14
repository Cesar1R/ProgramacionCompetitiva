std::vector<int> tribonacci(std::vector<int> signature, int n){
	
	std::vector<int> result(signature.begin(), signature.begin()+std::min(n, 3)); 
	
	if(n>3){ 	
		int i, k, term=0;

		for(i=0; i<3; i++){
			term +=signature[i];
		}
	
		result.push_back(term);
		i=0;
		for(k=0; k<n-4; k++){
			term *=2;
			term -= result[i++];
			result.push_back(term);
		}	
	}  
	return result;
}
