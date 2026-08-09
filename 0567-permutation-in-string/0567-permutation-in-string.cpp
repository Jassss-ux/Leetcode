class Solution {
public:
    bool isfreqsame( int freq[], int windfreq[]){  //yeh check krega ki dono freq and windfreq array ke andr jo character ki freq hai same hai ki nhi same hui toh true ajyega and kahi bhi mismatach hogyi toh correct window nhi hai hamri false
        for( int i = 0;i<26;i++){
            if( freq[i] != windfreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        // calcuate the freq of the s1 string chracters
        // for this we a freq array
        int freq[26] = {0}; //made frequecny array of size 26 bcz 26 alphabets are there and intitales freq array with 0 value

        for( int i = 0; i<s1.length();i++){ //s1 ki length pe loop chalega and sare characeter ki frwuency count krlenge
            freq[s1[i]-'a']++;
        }

        // now ab window mltb jo s1 ka size hai jisse hume comapre krna hai s2 mein voh initilize krenge as a windsize variable
        int windsize = s1.length();

        // ab ik for loop lagenege jo s2 ke   uper traveerse krega and uske sare element ki freq ko ik windowfreq array mein add krega
        for( int i =0 ;i<s2.length() ;i++){
            int windidx = 0; //  yeh hamre start of the window hai joki hamare windsize ke uper traverse krega 
            int idx = i; // yeh idx hamre s2 ke length ke uper traverse krega and store krega frequenccy fo characeters

            int windfreq[26] = {0}; //windfreq array

            while( windidx < windsize && idx < s2.length()){ //windidx pura windsize pe traaverse krega islye less than windsize ka symbol aya and idx hamra pure s2 pe traverse krega is udhr bhi less than ka symbol and dono cheeze hamsha true hongi tabhi hum pta laga pyenge ki s2 string ke andr jinti bhi windows bani s1 lenght ki konsi window pe hamre character kki frequency match hogyi 

            windfreq[s2[idx] -'a']++;  //windfreq ke andr s2 ke andr  jo windoe banni hai hamri s1 ki uski chracter ki frequency store krhe hai 

            windidx++; //jisse next idex pe jake window ke comapre ho sakke 
            idx++; // next index pe jake s2 ke comapre ho ssake

            }

            if(isfreqsame( freq, windfreq)){
                return true;
            }
        }
        return false;
    }
};