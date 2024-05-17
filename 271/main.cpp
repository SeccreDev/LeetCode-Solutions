string encode(vector<string>& strs)
{
    string enc = "";
    for(string x : strs)
    {
        enc += to_string(x.size()) + "@" + x;
    }
    return enc;
}

vector<string> decode(string s)
{

    vector <string> dec;
    int i = 0;

    while (i < s.size())
    {
        int tracker = i;
        while(s[tracker] != '@')
        {
            tracker++;
        }

        int length = stoi(s.substr(i, tracker - i));
        string tempString = s.substr(tracker + 1, length);
        dec.push_back(tempString);
        i = length + tracker + 1;
    }
    return dec;
}

int main()
{
    vector <string> strings {"Hello", "Hola", "Adios"};
    for(string x : strings)
    {
        cout << x <<  " ";
    }
    cout << "\n";
    
    string enc = encode(strings);
    cout << enc;
    vector <string> stringDecode = decode(enc);
    cout << "\n";
    for(string x : stringDecode)
    {
        cout << x <<  " ";
    }
    
    return 0;
}
