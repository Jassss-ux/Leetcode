
class Solution {

public:

    bool isfreqsame(int freq[], int windfreq[]) {  
        // yeh check karega ki dono freq aur windfreq array ke andar
        // jo character ki frequency hai woh same hai ya nahi.
        // Agar dono ki frequency same hui toh true aa jayega
        // aur agar kahi bhi mismatch hui toh correct window nahi hai,
        // isliye false return hoga.

        for(int i = 0; i < 26; i++) {

            if(freq[i] != windfreq[i]) {
                return false;
            }
        }

        return true;
    }


    bool checkInclusion(string s1, string s2) {

        // calculate the frequency of the s1 string characters.
        // Iske liye hum ek frequency array banayenge.

        int freq[26] = {0}; 
        // frequency array size 26 banaya hai kyunki 26 alphabets hote hain
        // aur initially saari frequency ko 0 se initialize kiya hai.


        for(int i = 0; i < s1.length(); i++) {

            // s1 ki length pe loop chalega aur
            // s1 ke saare characters ki frequency count kar lenge.

            freq[s1[i] - 'a']++;
        }


        // Ab window ka size initialize karenge.
        // Window ka size s1 ki length ke equal hoga,
        // kyunki hume s2 ke andar s1 size ki window ko compare karna hai.

        int windsize = s1.length();


        // Ab ek for loop lagayenge jo s2 ke upar traverse karega
        // aur s2 ke andar s1 size ki different windows banayega.
        // Har window ke characters ki frequency ko
        // ek windfreq array mein store karenge.

        for(int i = 0; i < s2.length(); i++) {

            int windidx = 0; 
            // yeh hamare current window ka index hai
            // jo window ke size ke according traverse karega.

            int idx = i; 
            // yeh idx s2 ke upar traverse karega
            // aur current window ke characters ko access karega.


            int windfreq[26] = {0}; 
            // yeh windfreq array hai jisme current window ke
            // characters ki frequency store karenge.


            while(windidx < windsize && idx < s2.length()) {

                // windidx window ke size tak traverse karega
                // aur idx s2 ke end tak traverse karega.
                // Dono conditions true hongi tabhi hum current window
                // ke andar characters ki frequency calculate kar payenge.

                windfreq[s2[idx] - 'a']++;  
                // windfreq ke andar current window ke characters ki
                // frequency store kar rahe hain.

                windidx++; 
                // window ke next index pe jaane ke liye increment karenge.

                idx++; 
                // s2 ke next index pe jaane ke liye increment karenge.
            }


            if(isfreqsame(freq, windfreq)) {

                // Ab s1 ki frequency aur current window ki frequency
                // ko compare karenge.
                // Agar dono ki frequency same hui toh s1 ka permutation
                // s2 ke andar mil gaya hai.

                return true;
            }
        }

        // Agar poori s2 string traverse karne ke baad bhi
        // koi matching window nahi mili toh false return karenge.

        return false;
    }
};

