#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int> ans,b;
    b.push_back(scores[0]);
    for(int i=1;i<scores.size();i++){
        if(scores[i]!=b[b.size()-1])
            b.push_back(scores[i]);
    }
    for(int i=0;i<alice.size();i++){
        if(alice[i]>b[0]){
            ans.push_back(1);continue;}
        else if(alice[i]<b[b.size()-1]){
            ans.push_back(b.size()+1);continue;}
        int f,lo=0,hi=b.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(b[mid]<alice[i] && alice[i]<b[mid-1]){
                ans.push_back(mid+1);break;}
            else if(b[mid]>alice[i] && alice[i]>=b[mid+1]){
                ans.push_back(mid+2);break;}
            else if(b[mid]<alice[i])
                hi = mid-1;
            else if(b[mid]>alice[i])
                lo = mid+1;
            else {ans.push_back(mid+1);break;}
        }
        /*for(int j=b.size()-1;j>=0;j--)
        if(alice[i]<b[j]){
            f=1;
            ans.push_back(j+2);
            break;
        }
        if(!f) ans.push_back(1);*/

    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
