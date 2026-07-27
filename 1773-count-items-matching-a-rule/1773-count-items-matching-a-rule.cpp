class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count =0;
        for( auto x: items){
            if( ruleKey == "type" && x[0] == ruleValue ){ //idhr humne phele jo key hai voh check krnge and jo array hai items ka usmein humne de rkha hai phele type pher color pher name toh indeex dekhlenge 0 index pe type ayega toh count++ , pher 1 index pe agr color match krha toh count++, pher agr name match krha 3 idex pe pher count++:
                count++;
            }
            else if( ruleKey == "color" && x[1] == ruleValue ){
                count++;
            }
            else if( ruleKey =="name"  && x[2] == ruleValue){
                count++;
            }
        }
        return count;
    }
};