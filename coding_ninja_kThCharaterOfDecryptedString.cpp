char kThCharaterOfDecryptedString(string str, long long k)
{
    //  Write your code here.
    long long int i, j;
 
    long long int n = str.length();

    long long int len;

    long int num;
    long long int freq;
 
    i = 0;
 
    while (i < n) {
        j = i;
        len = 0;
        freq = 0;
 
        while (j < n && str[j] >= 'a' && str[j] <= 'z') {
            j++;
            len++;
        }
 
        while (j < n && str[j] >= '0' && str[j] <= '9') {
            freq = freq * 10 + (str[j] - '0');
            j++;
        }
 
        num = freq * len;

        if (k > num) {
            k -= num;
            i = j;
        }
        else {
            k--;
            k %= len;
            return str[i + k];
        }
    }
    return str[k - 1];
}