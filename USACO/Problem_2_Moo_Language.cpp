#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, C, P;
        cin >> N >> C >> P;

        vector<string> ns, tvs, ivs, cs;

        for (int i = 0; i < N; ++i) {
            string w, t;
            cin >> w >> t;

            if (t[0] == 'n') {
                ns.push_back(w);
            }
            if (t[0] == 't') {
                tvs.push_back(w);
            }
            if (t[0] == 'i') {
                ivs.push_back(w);
            }
            if (t[0] == 'c') {
                cs.push_back(w);
            }
        }

        pair<int, int> res = {0, 0};

        for (int nt = 0; nt <= tvs.size(); ++nt) {
            int ni = min(static_cast<int>(ivs.size()), static_cast<int>(ns.size()) - 2 * nt);
            int nc;

            while (ni >= 0) {
                nc = min(static_cast<int>(cs.size()), (nt + ni) / 2);

                if (nt + ni - nc <= P) {
                    break;
                }

                ni -= 1;
            }

            if (ni < 0) {
                continue;
            }

            int en = min(C, static_cast<int>(ns.size()) - (ni + 2 * nt));

            if (nt == 0) {
                en = 0;
            }

            int nw = 3 * nt + 2 * ni + nc + en;

            res = max(res, {nw, nt});
        }

        int nw = res.first;
        int nt = res.second;
        int ni = min(static_cast<int>(ivs.size()), static_cast<int>(ns.size()) - 2 * nt);
        int nc = min(static_cast<int>(cs.size()), (nt + ni) / 2);

        cout << nw << endl;

        vector<string> bs;
        for (int i = 0; i < ni; ++i) {
            bs.push_back(ns.back() + " " + ivs.back());
            ns.pop_back();
            ivs.pop_back();
        }

        for (int i = 0; i < nt; ++i) {
            bs.push_back(ns.back() + " " + tvs.back() + " " + ns[ns.size() - 2]);
            ns.pop_back();
            tvs.pop_back();
            ns.pop_back();
        }

        while (nt > 0 && C > 0 && !ns.empty()) {
            bs.back() += ", " + ns.back();
            C -= 1;
            ns.pop_back();
        }

        vector<string> csentences;

        for (int i = 0; i < nc; ++i) {
            csentences.push_back(bs.back() + " " + cs.back() + " " + bs[bs.size() - 2]);
            bs.pop_back();
            cs.pop_back();
            bs.pop_back();
        }

        vector<string> ssentences;
        ssentences.reserve(bs.size() + csentences.size());

        for (const auto& s : bs) {
            ssentences.push_back(s + ".");
        }

        for (const auto& s : csentences) {
            ssentences.push_back(s + ".");
        }

        for (const auto& s : ssentences) {
            cout << s << " ";
        }

        cout << endl;
    }

    return 0;
}
