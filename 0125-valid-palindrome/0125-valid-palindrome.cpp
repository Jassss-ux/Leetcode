class Solution {
public:

    // This function checks whether the given character
    // is alphanumeric (either a digit or an alphabet).
    bool alphanumeric(char ch) {

        // Check if character is a digit (0-9)
        // OR an alphabet (a-z / A-Z)
        if ((ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {

            return true;
        }

        // If the character is not a digit or alphabet,
        // then it is a special character like:
        // ' ', ',', ':', '@', '#', etc.
        return false;
    }

    bool isPalindrome(string s) {

        // Two pointers:
        // st  -> starts from the beginning
        // end -> starts from the end
        int st = 0;
        int end = s.length() - 1;

        // Continue until both pointers cross each other
        while (st <= end) {

            // If the character at 'st' is not alphanumeric,
            // simply skip it and move the left pointer forward.
            //
            // Example:
            // "A man, a plan"
            // ',' is not alphanumeric, so we skip it.
            if (!alphanumeric(s[st])) {
                st++;
                continue;
            }

            // If the character at 'end' is not alphanumeric,
            // skip it and move the right pointer backward.
            else if (!alphanumeric(s[end])) {
                end--;
                continue;
            }

            // Convert both characters to lowercase
            // so that uppercase and lowercase are treated
            // as the same character.
            //
            // Example:
            // 'A' == 'a'
            if (tolower(s[st]) != tolower(s[end])) {

                // If characters don't match,
                // the string cannot be a palindrome.
                return false;
            }

            // If both characters match,
            // move both pointers towards the center.
            st++;
            end--;
        }

        // If we successfully compare all valid characters
        // without finding any mismatch,
        // the string is a palindrome.
        return true;
    }
};