
class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Using string streams to split the versions by '.'
        stringstream ss1(version1);
        stringstream ss2(version2);
        
        // Temporary variables to store each revision
        int revision1, revision2;
        
        // Loop through revisions
        while (ss1 || ss2) {
            // If a revision exists in version1, store it; otherwise, set to 0
            if (ss1) {
                ss1 >> revision1;
            } else {
                revision1 = 0;
            }
            
            // If a revision exists in version2, store it; otherwise, set to 0
            if (ss2) {
                ss2 >> revision2;
            } else {
                revision2 = 0;
            }
            
            // Compare the revisions
            if (revision1 < revision2) {
                return -1;
            } else if (revision1 > revision2) {
                return 1;
            }
            
            // Clear the stream for the next iteration
            ss1.ignore(); 
            ss2.ignore();
        }
        
        // If all revisions are equal
        return 0;
    }
};
