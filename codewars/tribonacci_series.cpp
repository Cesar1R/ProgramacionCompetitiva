std::vector<int> tribonacci(std::vector<int> signature, int n){
	
	std::vector<int> result(signature.begin(), signature.begin()+std::min(n, 3)); 
	
	if(n>3){ 	
		int i=0, k, term=signature[0] + signature[1] + signature[2];
		result.push_back(term);
		for(k=0; k<n-4; k++){
			term *=2; term -= result[i++];
			result.push_back(term);
		}	
	}  
	return result;
}
