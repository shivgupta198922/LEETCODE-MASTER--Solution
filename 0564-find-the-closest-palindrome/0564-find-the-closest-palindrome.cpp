class Solution {
public:
    long long dp[19];
    long long int abs1(long long int a) {
        if(a<0) {
            return -1 * a;
        }
        return a;
    }

    bool isPalindrome(string n) {
        int j = n.size()-1;
        for(int i=0;i<n.size()/2;i++) {
            if(n[i]!=n[j]) {
                return false;
            }
            j--;
        }
        return true;
    }

    long long int toNumber(string n) {
        long long int number = n[0]-'0';
        for(int i=1;i<n.size();i++) {
            number = (number * 10) + (n[i]-'0');
        }
        return number;
    }

    string nearestPalindromic(string n) {
        if(n=="10" || n=="11") {
            return to_string(9);
        }
        long long number = 0;
        long long ten = 1;
        dp[0] = ten;
        for(int i=1;i<18;i++) {
            dp[i] = dp[i-1] * 10;
        }
        number = (n[0]-'0');
        if(n.size()==1) {
            number--;
            return to_string(number);
        }
        for(int i=1;i<n.size();i++) {
            number = (number * 10) + (n[i]-'0');
        }
        for(int i=0;i<19;i++) {
            if(dp[i]==number) {
                return to_string(number-1);
            }
            if(dp[i]==(number+1)) {
                return to_string(dp[i]+1);
            }
        }
        long long copyNumber = number;
        int mid = n.size()/2;

        copyNumber = number / dp[mid];
        copyNumber -= 1;
        string takeOffMid = "";
        string firstHalf = to_string(copyNumber);
        if(n.size()%2 && firstHalf.size()>mid) {
            takeOffMid = firstHalf[firstHalf.size()-1];
            firstHalf.pop_back();
        }
        
        string reversedHalf = firstHalf; 
        reverse(reversedHalf.begin(), reversedHalf.end());
        string less = firstHalf+takeOffMid+reversedHalf; // Assuming leeseer Value is the answer.

        copyNumber = number / dp[mid];
        copyNumber += 1;
        if(copyNumber == 0) {
            return to_string(9);
        }
        takeOffMid = "";
        firstHalf = to_string(copyNumber);
        if(n.size()%2) {
            takeOffMid = firstHalf[firstHalf.size()-1];
            firstHalf.pop_back();
        }
        
        reversedHalf = firstHalf; 
        reverse(reversedHalf.begin(), reversedHalf.end());
        string more = firstHalf+takeOffMid+reversedHalf; // Assuming greater Value is the answer.
        
        string possibleAns = "";
        if(toNumber(more)-number<number-toNumber(less)) {
            possibleAns = more;
        } else {
            possibleAns = less;
        }

        if(!isPalindrome(n)) {
        // Assuming Revered value as answer
        int j = n.size()-1;
            for(int i=0;i<mid;i++) {
                n[j] = n[i];
                j--;
            }
            long long int thirdParty = toNumber(n);
            if(abs1(toNumber(possibleAns)-number)>abs1(number-toNumber(n))) {
                possibleAns = n;
                cout<<n<<endl;
            } else if(abs1(toNumber(possibleAns)-number)==abs1(number-toNumber(n))) {
                if(toNumber(n)<=toNumber(possibleAns)) {
                    possibleAns = n;
                }
            }
        }
        return possibleAns;
    }
};