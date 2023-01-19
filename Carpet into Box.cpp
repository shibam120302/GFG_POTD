class Solution {
public:
    int carpetBox(int a, int b, int c, int d) {
        //code here
        int x = a, y = b, s = 0;
        while (x > c || y > d)
        {
            if (x > c)
            {
                x /= 2;
                s++;
            }
            if (y > d)
            {
                y /= 2;
                s++;
            }
        }
        int ans = s;
        x = a; y = b;
        s = 0;
        while (x > d || y > c)
        {
            if (x > d)
            {
                x /= 2;
                s++;
            }
            if (y > c)
            {
                y /= 2;
                s++;
            }
        }
        return min(ans, s);
    }
};
