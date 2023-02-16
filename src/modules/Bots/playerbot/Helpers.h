#pragma once

template<typename T>
map<int, T> filterList(vector<T> src, string filter)
{
    map<int, T> result;
    if (filter.empty() || filter == "*")
    {
        int idx = 0;
        for (vector<T>::iterator i = src.begin(); i != src.end(); ++i)
            result[idx++] = *i;
        return result;
    }

    if (filter.find("-") != string::npos)
    {
        vector<string> ss = split(filter, '-');
        int from = 0, to = src.size() - 1;
        if (!ss[0].empty()) from = atoi(ss[0].c_str()) - 1;
        if (ss.size() > 1 && !ss[1].empty()) to = atoi(ss[1].c_str()) - 1;
        if (from < 0) from = 0;
        if (from > src.size() - 1) from = src.size() - 1;
        if (to < 0) to = 0;
        if (to > src.size() - 1) to = src.size() - 1;

        for (int i = from; i <= to; ++i)
            result[i] = src[i];

        return result;
    }

    vector<string> ss = split(filter, ',');
    for (vector<string>::iterator i = ss.begin(); i != ss.end(); ++i)
    {
        int idx = atoi(i->c_str()) - 1;
        if (idx < 0) idx = 0;
        if (idx > src.size() - 1) idx = src.size() - 1;
        result[idx] = src[idx];
    }

    return result;
}
