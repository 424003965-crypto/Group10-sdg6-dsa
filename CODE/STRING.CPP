#include "String.h"

vector<vector<string>> tipsMatrix = {
    {"Tip: Nice! Your water looks clear and safe. Keep your source clean so it stays this way.", 
     "Tip: Your water is safe, but a bit colored. A simple filter can make it look even better."},
    {"Tip: Your water is a bit acidic. It’s better to filter it or find another source before drinking.", 
     "Tip: Your water is a bit too alkaline. Try using a filter or ask your local water provider to check it.", 
     "Tip: The water looks very colored. It might have dirt or germs, so please boil and filter it first.", 
     "Tip: The water did not pass the check. Boiling and filtering can help make it safer."}
};

string classifyWater(double pH, int colorCode) {
    if (pH >= 6.5 && pH <= 8.5 && (colorCode == 1 || colorCode == 2))
        return "Filtered";
    else
        return "Not Filtered";
}

string getTip(double pH, int colorCode, const string &status) {
    if (status == "Filtered") return tipsMatrix[0][colorCode - 1];
    else {
        if (pH < 6.5) return tipsMatrix[1][0];
        else if (pH > 8.5) return tipsMatrix[1][1];
        else if (colorCode == 3) return tipsMatrix[1][2];
        else return tipsMatrix[1][3];
    }
}
