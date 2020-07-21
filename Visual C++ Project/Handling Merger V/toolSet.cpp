#include<iostream>
#include<string>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<stdio.h>

using namespace std;

namespace toolSet {


	typedef list<string> liS;
	typedef pair<string, list<string> > sLi;


	struct SubHandlingData {
		string first;
		map<string, liS> second;

		bool operator<(const SubHandlingData &other) const {
			return first < other.first;
		}
	};

	class MainTool {

	private:

		set<SubHandlingData> F1;
		set<SubHandlingData> F2;
		set<SubHandlingData> InsertionVar;
		set<SubHandlingData> AllowedInsertionVar;
		string dirF1;
		string dirF2;
		map<string, string> VC;
		set<string> Var;
		set<string> AllowedVar;
		set<string> AllowedVeh;
		set<string> AllowedInsertionVeh;

		bool chnmb(char x) {
			return (tolower(x) >= 'a' && tolower(x) <= 'z') || (x >= '0' && x <= '9') || x == '-' || x == '.' || x == '_';
		}

		string firstId(string in) {
			string out;
			for (int i = 0; i < (int)in.size(); i++) {
				if (chnmb(in[i])) {
					while (chnmb(in[i]) && i < (int)in.size())
						out += in[i++];
					break;
				}
			}
			return out;
		}

		string fix(string in) {
			string ans, nodoubspace;
			int cquo = 0;
			for (int i = 0; i < (int)in.size(); i++)
				if (in[i] == '\t' || in[i] == '\n' || in[i] == '\r')
					in[i] = ' ';
			int j = 0;
			for (j = 0; j < (int)in.size() && in[j] == ' '; j++);
			in = in.substr(j, string::npos);
			for (int i = 0; i < (int)in.size(); i++) {
				if (in[i] == '\"')
					in[i] = (cquo++) % 2 == 0 ? '{' : '}';
			}
			for (int i = 0; i < (int)in.size(); i++) {
				while (i < (int)in.size() && in[i] == ' ' && ((int)in.size() - 1 == i || in[i + 1] == ' '))
					i++;
				if (i < (int)in.size())
					nodoubspace += in[i];
			}
			in = nodoubspace;
			for (int i = 0; i < (int)in.size(); i++) {
				if (in[i] == ' ' && i < (int)in.size() - 1 && !chnmb(in[i + 1]))
					i++;
				if (in[i] == ' ' && i > 0 && !(chnmb(in[i - 1]) || in[i - 1] == '}'))
					i++;
				if (i != (int)in.size())
					ans.push_back(in[i]);
			}
			for (int i = 0; i < (int)ans.size(); i++) {
				ans[i] = (ans[i] == '{' || ans[i] == '}') ? '\"' : ans[i];
			}
			return ans;
		}

		string join(pair<string, liS> in) {
			string &in_f = in.first, out;
			liS &in_s = in.second;
			for (int i = 0; i < (int)in_f.size(); i++) {
				if (in_f[i] == '$' && !in_s.empty()) {
					out += in_s.front();
					in_s.pop_front();
					i++;
				}
				if (i < (int)in_f.size())
					out += in_f[i];
			}
			return out;
		}

		sLi betQuotes(string in) {
			string out_s;
			list<string> out_l;
			for (int i = 0; i < (int)in.size(); i++) {
				if (in[i] == '\"') {
					i++;
					out_s += "\"$";
					string arg;
					while (i < (int)in.size() && in[i] != '\"') {
						arg += in[i++];
					}
					out_l.push_back(arg);
					if (i == (int)in.size())
						break;
				}
				out_s += in[i];
			}
			return sLi(out_s, out_l);
		}

		sLi betBrackets(string in) {
			string out_s;
			list<string> out_l;
			unsigned long long a = in.find(">");
			unsigned long long b = in.find("</");
			if (a == string::npos || b == string::npos || a > b)
				return sLi(out_s, out_l);
			out_l.push_back(in.substr(a + 1, (b - a - 1)));
			out_s = in.substr(0, a + 1) + "$" + in.substr(b, string::npos);
			return sLi(out_s, out_l);
		}


		int xtab;
		bool inBracket;
		char ch;

		string next() {
			if (ch == EOF)
				return "";
			string curr;
			if (inBracket) {
				curr = "<";
				while ((ch = getchar()) != EOF) {
					if (ch == '<')
						curr = "<";
					else if (ch == '>') {
						curr += ch;
						break;
					}
					else {
						curr += ch;
					}
				}
				inBracket = 0;
			}
			else {
				while ((ch = getchar()) != EOF && ch != '<') {
					curr += ch;
				}
				inBracket = 1;
			}
			if (ch == EOF)
				return "";
			if (curr.find("!--") != string::npos) {
				inBracket = 1;
				return next();
			}
			curr = fix(curr);
			if (curr == "")
				return next();
			return curr;
		}

		bool flagOut;

		void printIf(string txt) {
			if (!flagOut)
				return;
			for (int i = 0; i < xtab; i++)
				cout << " ";
			if (txt.find_last_of(";") != string::npos)
				txt = txt.substr(txt.find_last_of(";") + 1, string::npos);
			for (int i = 0; i < (int)txt.size(); i++) {
				cout << txt[i];
				if (txt[i] == '\n') {
					for (int j = 0; j < xtab; j++)
						cout << " ";
				}
			}
			cout << endl;
		}

		void printIf(sLi x) {
			if (!flagOut)
				return;
			string handlingName = x.first.substr(0, x.first.find(";"));
			SubHandlingData temp;
			temp.first = handlingName;
			set<string>::iterator it2 = AllowedVeh.find(handlingName);
			if (it2 != AllowedVeh.end()) {
				set<SubHandlingData>::iterator it = F1.find(temp);
				map<string, liS> args = it->second;
				map<string, liS>::iterator jt = args.find(x.first);
				if (jt != args.end() && AllowedVar.find(varName(x.first)) != AllowedVar.end()){
					printIf(join(*jt));
				}
				else {
					printIf(join(x));
				}
			}
			else {
				printIf(join(x));
			}
		}

		void insertVarPrint(string upToNow){
			int u = upToNow.find(";");
			string handName = upToNow.substr(0, u);
			SubHandlingData shd;
			shd.first = handName;
			set<SubHandlingData>::iterator s = AllowedInsertionVar.find(shd);
			if (s == AllowedInsertionVar.end()) {
				return;
			}
			shd = *s;
			for (map<string, liS>::iterator i = shd.second.begin(); i != shd.second.end(); i++) {
				string g = i->first.substr(0, i->first.find_last_of(";"))+";";
				if (upToNow == g) {
					printIf(*i);
				}
			}
		}

		void insertVarPrintExtra(string upToNow, set<string> subsUsed) {
			int u = upToNow.find(";");
			string handName = upToNow.substr(0, u);
			SubHandlingData shd;
			shd.first = handName;
			set<SubHandlingData>::iterator s = AllowedInsertionVar.find(shd);
			int k = subsUsed.size();
			if (s == AllowedInsertionVar.end()) {
				while (k++ < 3) {
					printIf("<Item type=\"NULL\"/>");
				}
				return;
			}
			shd = *s;
			for (map<string, liS>::iterator i = shd.second.begin(); i != shd.second.end(); i++) {
				string f = i->first.substr(0, i->first.find_last_of(";"));
				string g = f;
				if (g.find(";") == string::npos)
					continue;
				g = g.substr(g.find_last_of(";") + 1, g.size());
				if (subsUsed.find(g) == subsUsed.end()) {
					k++;
					g.pop_back();
					printIf("<Item type=\"" + g + "\">");
					xtab += 2;
					while (i != shd.second.end() && i->first.substr(0, i->first.find_last_of(";")) == f) {
						printIf(*i);
						i++;
					}
					i--;
					xtab -= 2;
					printIf("</Item>");
				}
			}
			while (k++ < 3) {
				printIf("<Item type=\"NULL\"/>");
			}
		}

		string varName(string v) {
			string out = "";
			if (v.find("<") != string::npos) {
				for (int j = v.find("<") + 1; j < (int)v.size() && chnmb(v[j]); j++) {
					out += v[j];
				}
			}
			return out;
		}

		bool multiLineVar(string ends, string &s_cum_o, list<string> &l_cum_o, int tab) {
			string s_cum;
			list<string> l_cum;
			string curr;
			while (ch != EOF) {
				s_cum += "\n";
				curr = next();
				if (curr == ends) {
					tab -= 2;
					for (int i = 0; i < tab; i++)
						s_cum += " ";
					s_cum += curr;
					break;
				}
				for (int i = 0; i < tab; i++)
					s_cum += " ";
				sLi x;
				if (curr.find("<") != string::npos){
					x = betQuotes(curr);
					s_cum += x.first;
					while (!x.second.empty()) {
						l_cum.push_back(x.second.front());
						x.second.pop_front();
					}
					if (curr.find("/>") != string::npos)
						continue;
					string willEnd = "</" + firstId(x.first) + ">";
					bool ok = multiLineVar(willEnd, s_cum, l_cum, tab + 2);
					if (!ok)
						return 0;
				} else {
					int i = 0;
					while (i < (int)curr.size()){
						while (curr[i] == ' ' && i < (int)curr.size()) {
							s_cum += "\n";
							for (int j = 0; j < tab; j++)
								s_cum += " ";
							i++;
						}
						string aux;
						while (i < (int)curr.size() && curr[i] != ' ') {
							aux += curr[i++];
						}
						s_cum += '$';
						l_cum.push_back(aux);
					}
				}
			}
			if (tab == 2) {
				int cnt = 0;
				for (int g = 0; g < (int)s_cum.size(); g++)
					if (s_cum[g] == '$')
						cnt++;
				if (cnt < 2) {
					s_cum = fix(s_cum);
				}
			}
			s_cum_o += s_cum;
			while (!l_cum.empty()) {
				l_cum_o.push_back(l_cum.front());
				l_cum.pop_front();
			}
			return curr == ends;
		}

		bool tokenize_FileIn(string ends, string upToNow, map<string, liS> &write) {
			string curr;
			while (ch != EOF) {
				curr = next();
				if (curr == ends) {
					if (upToNow.find(";") != upToNow.size() - 1)
						insertVarPrint(upToNow);
					xtab -= 2;
					printIf(curr);
					break;
				}
				if (curr == "<SubHandlingData>") {
					if (upToNow.find(";") == upToNow.size()-1)
						insertVarPrint(upToNow);
					printIf(curr);
					xtab += 2;
					bool ok = 1;
					map<string, int> cnt;
					set<string> subsUsed;
					while(ok){
						string aux = next();
						sLi y = betQuotes(aux);
						curr = y.first;
						if (curr == "<Item type=\"$\">") {
							printIf(y);
							xtab += 2;
							string subName = y.second.front();
							subName += char('0' + cnt[subName]++);
							subsUsed.insert(subName);
							string nextUp = upToNow + subName;
							ok = tokenize_FileIn("</Item>", nextUp + ";", write);
							if (!ok)
								xtab -= 2;
						} else if (curr == "<Item type=\"$\"/>") {
							continue;
						} else if (curr == "</SubHandlingData>") {
							break;
						} else {
							ok = 0;
						}
					}
					insertVarPrintExtra(upToNow, subsUsed);
					xtab -= 2;
					if (curr != "</SubHandlingData>") {
						curr = next();
					}
					printIf(curr);
					if (!ok || curr != "</SubHandlingData>")
						return 0;
				}
				else if (curr.size() > 3) {
					sLi x;
					if (curr.find("/>") != string::npos) {
						x = betQuotes(curr);
					}
					else {
						x = betQuotes(curr);
						string s_cum = x.first;
						list<string> l_cum = x.second;
						string willEnd = "</" + firstId(s_cum) + ">";
						bool ok = multiLineVar(willEnd, s_cum, l_cum, 2);
						if (!ok)
							return 0;
						string test = fix(s_cum);
						if (test == x.first + "$" + willEnd && test.find("=") == string::npos)
							s_cum = test;
						x.first = s_cum;
						x.second = l_cum;
					}
					printIf(make_pair(upToNow + x.first, x.second));
					if (x.first != "<handlingName>$</handlingName>")
						write[upToNow + x.first] = x.second;
				}
			}
			return curr == ends;
		}

		bool isFile1;

		vector<string> handlingNames;
		int itrHNs;

		void run_FileIn(set<SubHandlingData> &All) {
			string curr;
			while (ch != EOF) {
				xtab = 0;
				curr = next();
				if (curr == "<HandlingData>" || curr == "</HandlingData>")
					xtab = 2;
				if (curr == "<Item type=\"CHandlingData\">" || curr == "</Item>")
					xtab = 4;
				printIf(curr);
				if (curr != "<Item type=\"CHandlingData\">")
					continue;
				xtab += 2;
				itrHNs++;
				string handlingName = handlingNames[itrHNs];
				if (handlingName == "") {
					xtab -= 2;
					continue;
				}
				bool specialCase = 0;
				if (AllowedInsertionVeh.find(handlingName) != AllowedInsertionVeh.end()) {
					specialCase = 1;
					flagOut = 1;
					xtab -= 2;
					printIf("<Item type=\"CHandlingData\">");
					xtab += 2;
				}
				SubHandlingData shd;
				shd.first = handlingName;
				string logLoaded;
				if (tokenize_FileIn("</Item>", handlingName + ";", shd.second)) {
					if (!flagOut) {
						All.insert(shd);
						if (isFile1) {
							for (map<string, liS>::iterator it = shd.second.begin(); it != shd.second.end(); it++) {
								Var.insert(varName(it->first));
							}
						}
						/*cout << shd.first << endl;
						for (map<string, liS>::iterator it = shd.second.begin(); it != shd.second.end(); it++) {
							string F = it->first;
							//if (F.find_last_of(";") != string::npos)
								//F = F.substr(F.find_last_of(";")+1, string::npos);
							cout << join(make_pair(F, it->second)) << endl;
						}*/
					}
				}
				else {
					xtab -= 2;
				}
				if (specialCase) {
					flagOut = 0;
				}
			}
		}

		void run_F(set<SubHandlingData> &F, string in, string out) {
			handlingNames.clear();
			itrHNs = -1;
			ch = '$';
			cin.clear();
			freopen(in.c_str(), "r", stdin);
			while (ch != EOF) {
				string curr = next();
				if (curr == "<Item type=\"CHandlingData\">") {
					handlingNames.push_back("");
				}
				if (curr == "<handlingName>") {
					string b = next();
					string c = next();
					if (c == "</handlingName>") {
						if (handlingNames.size() > 0) {
							for (int i = 0; i < (int)b.size(); i++)
								b[i] = toupper(b[i]);
							handlingNames[handlingNames.size() - 1] = b;
						}
					}
				}
			}
			ch = '$';
			cin.clear();
			F.clear();
			freopen(in.c_str(), "r", stdin);
			if (out != "")
				freopen((out + ".temp").c_str(), "w", stdout);
			run_FileIn(F);
			cin.clear();
			freopen("aux", "r", stdin);
			if (out != "")
				freopen("aux", "w", stdout);
		}

		void uncommonVar() {
			InsertionVar.clear();
			for (set<SubHandlingData>::const_iterator it = F1.begin(); it != F1.end(); it++) {
				SubHandlingData temp;
				temp.first = it->first;
				set<SubHandlingData>::const_iterator it2 = F2.find(temp);
				if (it2 != F2.end()) {
					map<string, liS>::const_iterator i = it->second.begin(), j = it2->second.begin();
					while (i != it->second.end()) {
						while (j != it2->second.end() && i->first > j->first)
							j++;
						if (j == it2->second.end() || i->first < j->first) {
							temp.second[i->first] = i->second;
						}
						i++;
					}
					if (temp.second.size() > 0) {
						InsertionVar.insert(temp);
					}
				}
			}
		}

	public:

		MainTool() {
			freopen("aux", "w", stdout);
			flagOut = 0;
			xtab = 0;
			isFile1 = 0;
			VC["ADDER"] = "SUPER";
			VC["AIRBUS"] = "SERVICE";
			VC["AIRTUG"] = "UTILITY";
			VC["AKUMA"] = "MOTORCYCLE";
			VC["ALPHA"] = "SPORT";
			VC["AMBULAN"] = "EMERGENCY";
			VC["ANNIHL"] = "HELICOPTER";
			VC["ARMYTRAILER"] = "UTILITY";
			VC["ASEA"] = "SEDAN";
			VC["ASTEROPE"] = "SEDAN";
			VC["BAGGER"] = "MOTORCYCLE";
			VC["BALETRAILER"] = "UTILITY";
			VC["BALLER"] = "SUV";
			VC["BALLER2"] = "SUV";
			VC["BANSHEE"] = "SPORT";
			VC["BARRACKS"] = "MILITARY";
			VC["BARRACKS2"] = "MILITARY";
			VC["BATI"] = "MOTORCYCLE";
			VC["BENSON"] = "COMMERCIAL";
			VC["BESRA"] = "PLANE";
			VC["BFINJECT"] = "OFF_ROAD";
			VC["BIFF"] = "COMMERCIAL";
			VC["BIFTA"] = "OFF_ROAD";
			VC["BISON"] = "VAN";
			VC["BJXL"] = "SUV";
			VC["BLADE"] = "MUSCLE";
			VC["BLAZER"] = "OFF_ROAD";
			VC["BLAZER2"] = "OFF_ROAD";
			VC["BLIMP"] = "PLANE";
			VC["BLIMP2"] = "PLANE";
			VC["BLISTA"] = "COMPACT";
			VC["BLISTA2"] = "SPORT";
			VC["BMX"] = "CYCLE";
			VC["BOATTRAILER"] = "UTILITY";
			VC["BOBCATXL"] = "VAN";
			VC["BODHI2"] = "OFF_ROAD";
			VC["BOXVILLE"] = "VAN";
			VC["BUCCANEE"] = "MUSCLE";
			VC["BUFFALO"] = "SPORT";
			VC["BUFFALO2"] = "SPORT";
			VC["BUFFALO3"] = "SPORT";
			VC["BULLDOZE"] = "INDUSTRIAL";
			VC["BULLET"] = "SUPER";
			VC["BURRITO"] = "VAN";
			VC["BUS"] = "SERVICE";
			VC["BUZZARD"] = "HELICOPTER";
			VC["BUZZARD2"] = "HELICOPTER";
			VC["CADDY"] = "UTILITY";
			VC["CADDY2"] = "UTILITY";
			VC["CAMPER"] = "VAN";
			VC["CARBON"] = "MOTORCYCLE";
			VC["CARBONIZ"] = "SPORT";
			VC["CARGOBOB"] = "HELICOPTER";
			VC["CARGOPLANE"] = "PLANE";
			VC["CASCO"] = "SPORT_CLASSIC";
			VC["CAVCADE"] = "SUV";
			VC["CHEETAH"] = "SUPER";
			VC["COACH"] = "SERVICE";
			VC["COGCABRIO"] = "COUPE";
			VC["COMET"] = "SPORT";
			VC["COQUETTE"] = "SPORT";
			VC["COQUETTE2"] = "SPORT_CLASSIC";
			VC["CRUISER"] = "CYCLE";
			VC["CRUSADER"] = "MILITARY";
			VC["CUBAN800"] = "PLANE";
			VC["CUTTER"] = "INDUSTRIAL";
			VC["DAEMON"] = "MOTORCYCLE";
			VC["DILETTANTE"] = "COMPACT";
			VC["DINGHY"] = "BOAT";
			VC["DINGHY2"] = "BOAT";
			VC["DLOADER"] = "OFF_ROAD";
			VC["DOCKTRAILER"] = "UTILITY";
			VC["DOCKTUG"] = "UTILITY";
			VC["DOMINATOR"] = "MUSCLE";
			VC["DOMINATOR2"] = "MUSCLE";
			VC["DOUBLE"] = "MOTORCYCLE";
			VC["DUBSTA"] = "SUV";
			VC["DUBSTA3"] = "OFF_ROAD";
			VC["DUKES"] = "MUSCLE";
			VC["DUKES2"] = "MUSCLE";
			VC["DUMP"] = "INDUSTRIAL";
			VC["DUNE"] = "OFF_ROAD";
			VC["DUNE2"] = "OFF_ROAD";
			VC["DUSTER"] = "PLANE";
			VC["ELEGY2"] = "SPORT";
			VC["EMPEROR"] = "SEDAN";
			VC["ENDURO"] = "MOTORCYCLE";
			VC["ENTITYXF"] = "SUPER";
			VC["EXEMPLAR"] = "COUPE";
			VC["F620"] = "COUPE";
			VC["FAGGIO"] = "MOTORCYCLE";
			VC["FBI"] = "EMERGENCY";
			VC["FBI2"] = "EMERGENCY";
			VC["FELON"] = "COUPE";
			VC["FELON2"] = "COUPE";
			VC["FELTZER"] = "SPORT";
			VC["FIRETRUK"] = "EMERGENCY";
			VC["FIXTER"] = "CYCLE";
			VC["FLATBED"] = "INDUSTRIAL";
			VC["FORKLIFT"] = "UTILITY";
			VC["FQ2"] = "SUV";
			VC["FREIGHT"] = "RAIL";
			VC["FREIGHTCAR"] = "RAIL";
			VC["FROGGER"] = "HELICOPTER";
			VC["FUGITIVE"] = "SEDAN";
			VC["FUROREGT"] = "SPORT";
			VC["FUSILADE"] = "SPORT";
			VC["FUTO"] = "SPORT";
			VC["GAUNTLET"] = "MUSCLE";
			VC["GAUNTLET2"] = "MUSCLE";
			VC["GBURRITO2"] = "VAN";
			VC["GLENDALE"] = "SEDAN";
			VC["GRAINTRAIL"] = "UTILITY";
			VC["GRANGER"] = "SUV";
			VC["GRESLEY"] = "SUV";
			VC["GUARDIAN"] = "INDUSTRIAL";
			VC["HABANERO"] = "SUV";
			VC["HAKUCHOU"] = "MOTORCYCLE";
			VC["HANDLER"] = "INDUSTRIAL";
			VC["HAULER"] = "COMMERCIAL";
			VC["HEXER"] = "MOTORCYCLE";
			VC["HOTKNIFE"] = "MUSCLE";
			VC["HUNTLEY"] = "SUV";
			VC["HYDRA"] = "PLANE";
			VC["INFERNUS"] = "SUPER";
			VC["INGOT"] = "SEDAN";
			VC["INNOVAT"] = "MOTORCYCLE";
			VC["INSURGENT"] = "OFF_ROAD";
			VC["INSURGENT2"] = "OFF_ROAD";
			VC["INTRUDER"] = "SEDAN";
			VC["ISSI"] = "COMPACT";
			VC["JACKAL"] = "COUPE";
			VC["JB700"] = "SPORT_CLASSIC";
			VC["JESTER"] = "SPORT";
			VC["JET"] = "PLANE";
			VC["JETMAX"] = "BOAT";
			VC["JOURNEY"] = "VAN";
			VC["KALAHARI"] = "OFF_ROAD";
			VC["KHAMEL"] = "SPORT";
			VC["KURUMA"] = "SPORT";
			VC["KURUMA2"] = "SPORT";
			VC["LANDSTALKER"] = "SUV";
			VC["LAZER"] = "PLANE";
			VC["LECTRO"] = "MOTORCYCLE";
			VC["LGUARD"] = "EMERGENCY";
			VC["LUXOR"] = "PLANE";
			VC["MAMMATUS"] = "PLANE";
			VC["MANANA"] = "SPORT_CLASSIC";
			VC["MARQUIS"] = "BOAT";
			VC["MARSHALL"] = "OFF_ROAD";
			VC["MASSACRO"] = "SPORT";
			VC["MAVERICK"] = "HELICOPTER";
			VC["MESA"] = "OFF_ROAD";
			VC["METROTRAIN"] = "RAIL";
			VC["MILJET"] = "PLANE";
			VC["MINIVAN"] = "VAN";
			VC["MIXER"] = "INDUSTRIAL";
			VC["MIXER2"] = "INDUSTRIAL";
			VC["MONROE"] = "SPORT_CLASSIC";
			VC["MONSTER"] = "OFF_ROAD";
			VC["MOWER"] = "UTILITY";
			VC["MULE"] = "COMMERCIAL";
			VC["MULE3"] = "COMMERCIAL";
			VC["NEMESIS"] = "MOTORCYCLE";
			VC["NINEF"] = "SPORT";
			VC["ORACLE"] = "COUPE";
			VC["ORACLE2"] = "COUPE";
			VC["PACKER"] = "COMMERCIAL";
			VC["PANTO"] = "COMPACT";
			VC["PARADISE"] = "VAN";
			VC["PATRIOT"] = "SUV";
			VC["PBUS"] = "EMERGENCY";
			VC["PCJ"] = "MOTORCYCLE";
			VC["PENUMBRA"] = "SPORT";
			VC["PEYOTE"] = "SPORT_CLASSIC";
			VC["PHANTOM"] = "COMMERCIAL";
			VC["PHOENIX"] = "MUSCLE";
			VC["PICADOR"] = "MUSCLE";
			VC["PIGALLE"] = "SPORT_CLASSIC";
			VC["POLICE"] = "EMERGENCY";
			VC["POLICE2"] = "EMERGENCY";
			VC["POLICE3"] = "EMERGENCY";
			VC["POLICEB"] = "MOTORCYCLE";
			VC["POLICEOL2"] = "EMERGENCY";
			VC["POLICEOLD"] = "EMERGENCY";
			VC["POLICET"] = "EMERGENCY";
			VC["POLMAV"] = "HELICOPTER";
			VC["PONY"] = "VAN";
			VC["POUNDER"] = "COMMERCIAL";
			VC["PRAIRIE"] = "COMPACT";
			VC["PRANGER"] = "EMERGENCY";
			VC["PREDATOR"] = "BOAT";
			VC["PREMIER"] = "SEDAN";
			VC["PRIMO"] = "SEDAN";
			VC["PROPTRAILER"] = "UTILITY";
			VC["RADI"] = "SUV";
			VC["RAKETRAILER"] = "UTILITY";
			VC["RANCHERXL"] = "OFF_ROAD";
			VC["RAPIDGT"] = "SPORT";
			VC["REBEL"] = "OFF_ROAD";
			VC["REGINA"] = "SEDAN";
			VC["RHAPSODY"] = "COMPACT";
			VC["RHAPSODY1"] = "COMPACT";
			VC["RHINO"] = "MILITARY";
			VC["RIOT"] = "EMERGENCY";
			VC["RIPLEY"] = "UTILITY";
			VC["RLOADER"] = "MUSCLE";
			VC["ROCOTO"] = "SUV";
			VC["ROMERO"] = "SEDAN";
			VC["ROOSEVELT"] = "SPORT_CLASSIC";
			VC["RUBBLE"] = "INDUSTRIAL";
			VC["RUFFIAN"] = "MOTORCYCLE";
			VC["RUINER"] = "MUSCLE";
			VC["RUMPO"] = "VAN";
			VC["SABREGT"] = "MUSCLE";
			VC["SADLER"] = "UTILITY";
			VC["SANCHEZ"] = "MOTORCYCLE";
			VC["SANDKING"] = "OFF_ROAD";
			VC["SAVAGE"] = "HELICOPTER";
			VC["SCHAFTER2"] = "SEDAN";
			VC["SCHWARZE"] = "SPORT";
			VC["SCORCHER"] = "CYCLE";
			VC["SCRAP"] = "UTILITY";
			VC["SEAPLANE"] = "PLANE";
			VC["SEASHARK"] = "BOAT";
			VC["SEMINOLE"] = "SUV";
			VC["SENTINEL"] = "COUPE";
			VC["SERRANO"] = "SUV";
			VC["SHAMAL"] = "PLANE";
			VC["SHERIFF"] = "EMERGENCY";
			VC["SKYLIFT"] = "HELICOPTER";
			VC["SLAMVAN2"] = "MUSCLE";
			VC["SPEEDER"] = "BOAT";
			VC["SPEEDO"] = "VAN";
			VC["SQUALO"] = "BOAT";
			VC["STALION"] = "MUSCLE";
			VC["STALION2"] = "MUSCLE";
			VC["STANIER"] = "SEDAN";
			VC["STINGER"] = "SPORT_CLASSIC";
			VC["STINGERGT"] = "SPORT_CLASSIC";
			VC["STOCKADE"] = "COMMERCIAL";
			VC["STRATUM"] = "SEDAN";
			VC["STRETCH"] = "SEDAN";
			VC["STUNT"] = "PLANE";
			VC["SUBMERSIBLE"] = "BOAT";
			VC["SUBMERSIBLE2"] = "BOAT";
			VC["SULTAN"] = "SPORT";
			VC["SUNTRAP"] = "BOAT";
			VC["SUPERD"] = "SEDAN";
			VC["SURANO"] = "SPORT";
			VC["SURFER"] = "VAN";
			VC["SURGE"] = "SEDAN";
			VC["SWIFT"] = "HELICOPTER";
			VC["TACO"] = "VAN";
			VC["TAILGATE"] = "SEDAN";
			VC["TANKER"] = "UTILITY";
			VC["TAXI2"] = "SERVICE";
			VC["TECHNICAL"] = "OFF_ROAD";
			VC["THRUST"] = "MOTORCYCLE";
			VC["TIPTRUCK"] = "INDUSTRIAL";
			VC["TIPTRUCK2"] = "INDUSTRIAL";
			VC["TITAN"] = "PLANE";
			VC["TORNADO"] = "SPORT_CLASSIC";
			VC["TOURBUS"] = "SERVICE";
			VC["TOWTRUCK"] = "UTILITY";
			VC["TOWTRUCK2"] = "UTILITY";
			VC["TR2"] = "UTILITY";
			VC["TR3"] = "UTILITY";
			VC["TRACTOR"] = "UTILITY";
			VC["TRACTOR2"] = "UTILITY";
			VC["TRAILER"] = "UTILITY";
			VC["TRAILERL"] = "UTILITY";
			VC["TRAILERSMALL"] = "UTILITY";
			VC["TRASH"] = "SERVICE";
			VC["TRIBIKE"] = "CYCLE";
			VC["TROPIC"] = "BOAT";
			VC["TURISMOR"] = "SUPER";
			VC["UTILTRUC"] = "UTILITY";
			VC["UTILTRUC2"] = "UTILITY";
			VC["UTILTRUC3"] = "UTILITY";
			VC["VACCA"] = "SUPER";
			VC["VADER"] = "MOTORCYCLE";
			VC["VALKYR"] = "HELICOPTER";
			VC["VELUM"] = "PLANE";
			VC["VESTRA"] = "PLANE";
			VC["VIGERO"] = "MUSCLE";
			VC["VOLTIC"] = "SUPER";
			VC["VOODOO2"] = "MUSCLE";
			VC["WARRENER"] = "SEDAN";
			VC["WASHINGTON"] = "SEDAN";
			VC["YOUGA"] = "VAN";
			VC["ZENTORNO"] = "SUPER";
			VC["ZION"] = "COUPE";
			VC["ZTYPE"] = "SPORT_CLASSIC";
			VC["APC"] = "MILITARY";
			VC["ARDENT"] = "SPORT_CLASSIC";
			VC["AUTARCH"] = "SUPER";
			VC["AVARUS"] = "MOTORCYCLE";
			VC["BALLER3"] = "SUV";
			VC["BALLER4"] = "SUV";
			VC["BALLER5"] = "SUV";
			VC["BALLER6"] = "SUV";
			VC["BANSHEE2"] = "SPORT";
			VC["BARRAGE"] = "MILITARY";
			VC["BESTIAGTS"] = "SPORT";
			VC["BF400"] = "MOTORCYCLE";
			VC["BLAZER4"] = "OFF_ROAD";
			VC["BLAZER5"] = "OFF_ROAD";
			VC["BOXVILLE5"] = "VAN";
			VC["BRAWLER"] = "OFF_ROAD";
			VC["BRICKADE"] = "SERVICE";
			VC["BRIOSO"] = "COMPACT";
			VC["BTYPE2"] = "SPORT_CLASSIC";
			VC["BUCCANEE2"] = "MUSCLE";
			VC["CADDY3"] = "UTILITY";
			VC["CARACARA"] = "OFF_ROAD";
			VC["CHEBUREK"] = "SPORT_CLASSIC";
			VC["CHEETAH2"] = "SPORT_CLASSIC";
			VC["CHIMERA"] = "MOTORCYCLE";
			VC["CHINO"] = "MUSCLE";
			VC["CHINO2"] = "MUSCLE";
			VC["CLIFFHANG"] = "MOTORCYCLE";
			VC["COG55"] = "SEDAN";
			VC["COG552"] = "SEDAN";
			VC["COGNOSC"] = "SEDAN";
			VC["COGNOSC2"] = "SEDAN";
			VC["COMET3"] = "SPORT";
			VC["COMET5"] = "SPORT";
			VC["CONTENDER"] = "SUV";
			VC["COQUETTE3"] = "MUSCLE";
			VC["CYCLONE"] = "SUPER";
			VC["DAEMON2"] = "MOTORCYCLE";
			VC["DEFILER"] = "MOTORCYCLE";
			VC["DELUXO"] = "SPORT_CLASSIC";
			VC["DIABLOUS"] = "MOTORCYCLE";
			VC["DIABLOUS2"] = "MOTORCYCLE";
			VC["DOMINATOR3"] = "MUSCLE";
			VC["DUNE3"] = "OFF_ROAD";
			VC["DUNE4"] = "OFF_ROAD";
			VC["DUNE5"] = "OFF_ROAD";
			VC["ELEGY"] = "SPORT";
			VC["ELLIE"] = "MUSCLE";
			VC["ENTITY2"] = "SUPER";
			VC["ESSKEY"] = "MOTORCYCLE";
			VC["FACTION"] = "MUSCLE";
			VC["FACTION3"] = "MUSCLE";
			VC["FAGALOA"] = "SPORT_CLASSIC";
			VC["FAGGIO3"] = "MOTORCYCLE";
			VC["FAGGION"] = "MOTORCYCLE";
			VC["FBIOLD"] = "EMERGENCY";
			VC["FCR"] = "MOTORCYCLE";
			VC["FCR2"] = "MOTORCYCLE";
			VC["FELTZER3"] = "SPORT_CLASSIC";
			VC["FLASHGT"] = "SPORT";
			VC["FMJ"] = "SUPER";
			VC["GARGOYLE"] = "MOTORCYCLE";
			VC["GB200"] = "SPORT";
			VC["GBURRITO"] = "VAN";
			VC["GP1"] = "SUPER";
			VC["HAKUCHOU2"] = "MOTORCYCLE";
			VC["HALFTRACK"] = "MILITARY";
			VC["HAULER2"] = "COMMERCIAL";
			VC["HERMES"] = "MUSCLE";
			VC["HOTRING"] = "SPORT";
			VC["HUSTLER"] = "MUSCLE";
			VC["INFERNUS2"] = "SPORT_CLASSIC";
			VC["INSURGENT3"] = "OFF_ROAD";
			VC["ITALIGTB"] = "SUPER";
			VC["ITALIGTB2"] = "SUPER";
			VC["JESTER2"] = "SPORT";
			VC["JESTER3"] = "SPORT";
			VC["KAMACHO"] = "OFF_ROAD";
			VC["KHANJALI"] = "MILITARY";
			VC["LE7B"] = "SUPER";
			VC["LIMO2"] = "SEDAN";
			VC["LURCHER"] = "MUSCLE";
			VC["LUXOR2"] = "PLANE";
			VC["LYNX"] = "SPORT";
			VC["MAMBA"] = "SPORT_CLASSIC";
			VC["MANCHEZ"] = "MOTORCYCLE";
			VC["MARBELLA"] = "SEDAN";
			VC["MASSACRO2"] = "SPORT";
			VC["MICHELLI"] = "SPORT_CLASSIC";
			VC["MINIVAN2"] = "VAN";
			VC["MOONBEAM"] = "MUSCLE";
			VC["NEON"] = "SPORT";
			VC["NERO"] = "SUPER";
			VC["NERO2"] = "SUPER";
			VC["NIGHTBLADE"] = "MOTORCYCLE";
			VC["NIGHTSHARK"] = "OFF_ROAD";
			VC["NIMBUS"] = "PLANE";
			VC["NITESHAD"] = "MUSCLE";
			VC["OMNIS"] = "SPORT";
			VC["OPPRESSOR"] = "MOTORCYCLE";
			VC["OSIRIS"] = "SUPER";
			VC["PARIAH"] = "SPORT";
			VC["PENETRATOR"] = "SUPER";
			VC["PFISTER811"] = "SUPER";
			VC["PHANTOM2"] = "COMMERCIAL";
			VC["PHANTOM3"] = "COMMERCIAL";
			VC["PRIMO2"] = "SEDAN";
			VC["PROTOTIPO"] = "SUPER";
			VC["RAIDEN"] = "SPORT";
			VC["RALLYTRUCK"] = "SERVICE";
			VC["RAPIDGT3"] = "SPORT_CLASSIC";
			VC["RAPTOR"] = "SPORT";
			VC["RATBIKE"] = "MOTORCYCLE";
			VC["REAPER"] = "SUPER";
			VC["RETINUE"] = "SPORT_CLASSIC";
			VC["RIATA"] = "OFF_ROAD";
			VC["RIOT2"] = "EMERGENCY";
			VC["RLOADER2"] = "MUSCLE";
			VC["ROOSEVELT2"] = "SPORT_CLASSIC";
			VC["RUINER2"] = "MUSCLE";
			VC["RUMPO3"] = "VAN";
			VC["RUSTON"] = "SPORT";
			VC["SABREGT2"] = "MUSCLE";
			VC["SANCTUS"] = "MOTORCYCLE";
			VC["SAVESTRA"] = "SPORT_CLASSIC";
			VC["SC1"] = "SUPER";
			VC["SCHAFTER3"] = "SPORT";
			VC["SCHAFTER4"] = "SPORT";
			VC["SCHAFTER5"] = "SEDAN";
			VC["SCHAFTER6"] = "SEDAN";
			VC["SERRANO2"] = "SUV";
			VC["SEVEN70"] = "SPORT";
			VC["SHEAVA"] = "SUPER";
			VC["SHOTARO"] = "MOTORCYCLE";
			VC["SLAMVAN"] = "MUSCLE";
			VC["SLAMVAN3"] = "MUSCLE";
			VC["SPECTER"] = "SPORT";
			VC["SPECTER2"] = "SPORT";
			VC["SPMED"] = "PLANE";
			VC["SPSMALL"] = "PLANE";
			VC["STROMBER"] = "SPORT_CLASSIC";
			VC["SULTANRS"] = "SUPER";
			VC["SVOLITO"] = "HELICOPTER";
			VC["SWIFT2"] = "HELICOPTER";
			VC["T20"] = "SUPER";
			VC["TAIPAN"] = "SUPER";
			VC["TAMPA"] = "MUSCLE";
			VC["TAMPA2"] = "MUSCLE";
			VC["TECHNICAL2"] = "OFF_ROAD";
			VC["TECHNICAL3"] = "OFF_ROAD";
			VC["TEMPESTA"] = "SUPER";
			VC["TEZERACT"] = "SUPER";
			VC["TORERO"] = "SPORT_CLASSIC";
			VC["TORNADO5"] = "SPORT_CLASSIC";
			VC["TORNADO6"] = "SPORT_CLASSIC";
			VC["TRAILER2"] = "UTILITY";
			VC["TRAILERLARGE"] = "UTILITY";
			VC["TRAILERSMALL2"] = "MILITARY";
			VC["TRFLAT"] = "UTILITY";
			VC["TROPHY"] = "OFF_ROAD";
			VC["TROPHY2"] = "OFF_ROAD";
			VC["TROPOS"] = "SPORT";
			VC["TUG"] = "BOAT";
			VC["TURISMO2"] = "SPORT_CLASSIC";
			VC["TYRANT"] = "SUPER";
			VC["TYRUS"] = "SUPER";
			VC["URANUS"] = "COUPE";
			VC["VAGNER"] = "SUPER";
			VC["VERLIER"] = "SPORT";
			VC["VIGILANTE"] = "SUPER";
			VC["VINDICATOR"] = "MOTORCYCLE";
			VC["VIRGO"] = "MUSCLE";
			VC["VIRGO2"] = "MUSCLE";
			VC["VIRGO3"] = "MUSCLE";
			VC["VISERIS"] = "SPORT_CLASSIC";
			VC["VISIONE"] = "SUPER";
			VC["VOLATUS"] = "HELICOPTER";
			VC["VOLTIC2"] = "SUPER";
			VC["VOODOO"] = "MUSCLE";
			VC["VORTEX"] = "MOTORCYCLE";
			VC["WASTELANDER"] = "SERVICE";
			VC["WINDSOR"] = "COUPE";
			VC["WINDSOR2"] = "COUPE";
			VC["WOLFSBANE"] = "MOTORCYCLE";
			VC["XA21"] = "SUPER";
			VC["XLS"] = "SUV";
			VC["XLS2"] = "SUV";
			VC["YOSEMITE"] = "MUSCLE";
			VC["YOUGA2"] = "VAN";
			VC["ZOMBIEA"] = "MOTORCYCLE";
			VC["ZOMBIEB"] = "MOTORCYCLE";
			VC["COMET4"] = "SPORT";
			VC["GT500"] = "SPORT_CLASSIC";
			VC["ISSI3"] = "COMPACT";
			VC["REVOLTER"] = "SPORT";
			VC["SENTINEL3"] = "SPORT";
			VC["STREITER"] = "SPORT";
			VC["TAMPA3"] = "MUSCLE";
			VC["THRUSTER"] = "MILITARY";
			VC["Z190"] = "SPORT_CLASSIC";
			VC["ALPHAZ1"] = "PLANE";
			VC["CARGOBOB3"] = "HELICOPTER";
			VC["HUNTER"] = "HELICOPTER";
			VC["MICROLIGHT"] = "PLANE";
			VC["MOGUL"] = "PLANE";
			VC["NOKOTA"] = "PLANE";
			VC["PYRO"] = "PLANE";
			VC["ROGUE"] = "PLANE";
			VC["STARLING"] = "PLANE";
			VC["TORO"] = "BOAT";
			VC["VALKYR2"] = "HELICOPTER";
			VC["AKULA"] = "HELICOPTER";
			VC["AVENGER"] = "PLANE";
			VC["BLIMP3"] = "PLANE";
			VC["BOMBUSHKA"] = "PLANE";
			VC["BRUISER"] = "OFF_ROAD";
			VC["BRUISER2"] = "OFF_ROAD";
			VC["BRUTUS"] = "OFF_ROAD";
			VC["BRUTUS2"] = "OFF_ROAD";
			VC["CERBERUS"] = "COMMERCIAL";
			VC["CERBERUS2"] = "COMMERCIAL";
			VC["CHERNOBOG"] = "MILITARY";
			VC["CLIQUE"] = "MUSCLE";
			VC["DEATHBIKE"] = "MOTORCYCLE";
			VC["DEATHBIKE2"] = "MOTORCYCLE";
			VC["DEVESTE"] = "SPORT";
			VC["DEVIANT"] = "MUSCLE";
			VC["DOMINATOR4"] = "MUSCLE";
			VC["DOMINATOR5"] = "MUSCLE";
			VC["FREECRAWLER"] = "OFF_ROAD";
			VC["HAVOK"] = "HELICOPTER";
			VC["HOWARD"] = "PLANE";
			VC["IMPALER"] = "MUSCLE";
			VC["IMPALER2"] = "MUSCLE";
			VC["IMPALER3"] = "MUSCLE";
			VC["IMPERATOR"] = "MUSCLE";
			VC["IMPERATOR2"] = "MUSCLE";
			VC["ISSI4"] = "COMPACT";
			VC["ISSI5"] = "COMPACT";
			VC["ITALIGTO"] = "SPORT";
			VC["MENACER"] = "OFF_ROAD";
			VC["MOLOTOK"] = "PLANE";
			VC["MONSTER3"] = "OFF_ROAD";
			VC["MULE4"] = "COMMERCIAL";
			VC["OPPRESSOR2"] = "MOTORCYCLE";
			VC["PATRIOT2"] = "SUV";
			VC["PBUS2"] = "SERVICE";
			VC["POUNDER2"] = "COMMERCIAL";
			VC["RCBANDITO"] = "OFF_ROAD";
			VC["SCARAB"] = "MILITARY";
			VC["SCARAB2"] = "MILITARY";
			VC["SCHLAGEN"] = "SPORT";
			VC["SCRAMJET"] = "SUPER";
			VC["SEASPARROW"] = "HELICOPTER";
			VC["SLAMVAN4"] = "MUSCLE";
			VC["SLAMVAN5"] = "MUSCLE";
			VC["SPEEDO4"] = "VAN";
			VC["STAFFORD"] = "SEDAN";
			VC["STRIKEFORCE"] = "PLANE";
			VC["SWINGER"] = "SPORT_CLASSIC";
			VC["TERRORBYTE"] = "COMMERCIAL";
			VC["TOROS"] = "SUV";
			VC["TULIP"] = "MUSCLE";
			VC["VAMOS"] = "MUSCLE";
			VC["VOLATOL"] = "PLANE";
			VC["ZR380"] = "SPORT";
			VC["ZR3802"] = "SPORT";
			VC["SEABREEZE"] = "PLANE";
			VC["TULA"] = "PLANE";
			VC["MESA3"] = "OFF_ROAD";
			VC["TRASH2"] = "SERVICE";
		}

		void setF1(string directory) {
			freopen("aux", "w", stdout);
			ch = '$';
			dirF1 = directory;
			isFile1 = 1;
			Var.clear();
			run_F(F1, directory, "");
			isFile1 = 0;
			uncommonVar();
		}

		void setF2(string directory) {
			freopen("aux", "w", stdout);
			dirF2 = directory;
			run_F(F2, directory, "");
			uncommonVar();
		}

		list<string> common() {
			list<string> L;
			set<string> out;
			for (set<SubHandlingData>::iterator it = F1.begin(); it != F1.end(); it++) {
				if (F2.find(*it) != F2.end()) {
					string y = it->first;
					if (VC.find(it->first) != VC.end())
						y = "[" + VC[it->first] + "]   " + y;
					out.insert(y);
				}
			}
			for (set<string>::iterator it = out.begin(); it != out.end(); it++)
				L.push_back(*it);
			return L;
		}

		list<string> uncommon() {
			list<string> L;
			set<string> out;
			for (set<SubHandlingData>::iterator it = F1.begin(); it != F1.end(); it++) {
				if (F2.find(*it) == F2.end()) {
					string y = it->first;
					if (VC.find(it->first) != VC.end())
						y = "[" + VC[it->first] + "]   " + y;
					out.insert(y);
				}
			}
			for (set<string>::iterator it = out.begin(); it != out.end(); it++)
				L.push_back(*it);
			return L;
		}

		list<string> getVar() {
			set<string> out;
			list<string> L;
			for (set<string>::iterator i = Var.begin(); i != Var.end(); i++) {
				out.insert(*i);
			}
			for (set<string>::iterator i = out.begin(); i != out.end(); i++)
				L.push_back(*i);
			return L;
		}

		int merge(list<int> Vehicles, list<int>Variables) {
			if (dirF1 == "" || dirF2 == "")
				return 0;
			freopen("aux", "a", stdout);
			AllowedVar.clear();
			AllowedVeh.clear();
			list<string> AVe = common();
			list<string> AVa = getVar();
			int j = 0;
			while (!Vehicles.empty()) {
				if (j == Vehicles.front()) {
					string x = AVe.front();
					int p = x.find_last_of(" ");
					if (p != string::npos)
						x = x.substr(p + 1, string::npos);
					AllowedVeh.insert(x);
					Vehicles.pop_front();
				}
				AVe.pop_front();
				j++;
			}
			j = 0;
			while (!Variables.empty()) {
				if (j == Variables.front()) {
					string x = AVa.front();
					AllowedVar.insert(x);
					Variables.pop_front();
				}
				AVa.pop_front();
				j++;
			}
			flagOut = 1;
			run_F(F2, dirF2, dirF2);
			flagOut = 0;
			remove(dirF2.c_str());
			F2.clear();
			int arg = rename((dirF2 + ".temp").c_str(), dirF2.c_str());
			dirF2 = "";
			F1.clear();
			dirF1 = "";
			return 1;
		}

		int insert(list<int> Vehicles) {
			if (dirF1 == "" || dirF2 == "")
				return 0;
			list<string> AVe = uncommon();
			int j = 0;
			while (!Vehicles.empty()) {
				if (j == Vehicles.front()) {
					string x = AVe.front();
					int p = x.find_last_of(" ");
					if (p != string::npos)
						x = x.substr(p + 1, string::npos);
					AllowedInsertionVeh.insert(x);
					Vehicles.pop_front();
				}
				AVe.pop_front();
				j++;
			}
			cin.clear();
			freopen(dirF2.c_str(), "r", stdin);
			freopen((dirF2 + ".temp").c_str(), "w", stdout);
			while (!cin.eof()) {
				string curr;
				getline(cin, curr);
				if (fix(curr) != "</HandlingData>" && fix(curr) != "</CHandlingDataMgr>" && fix(curr) != "") {
					cout << curr << endl;
				}
			}
			set<SubHandlingData> Fnothing;
			run_F(Fnothing, dirF1, "");
			cout << "  </HandlingData>\n";
			cout << "</CHandlingDataMgr>\n";
			fflush(stdout);
			freopen("aux", "a", stdout);
			remove(dirF2.c_str());
			F2.clear();
			int arg = rename((dirF2 + ".temp").c_str(), dirF2.c_str());
			dirF2 = "";
			F1.clear();
			dirF1 = "";
			AllowedInsertionVeh.clear();
			return 1;
		}

		list<string> uncommonVarVeh() {
			list<string> L;
			set<string> out;
			for (set<SubHandlingData>::const_iterator i = InsertionVar.begin(); i != InsertionVar.end(); i++) {
				string y = i->first;
				if (VC.find(i->first) != VC.end())
					y = "[" + VC[i->first] + "]   " + y;
				out.insert(y);
			}
			for (set<string>::iterator it = out.begin(); it != out.end(); it++)
				L.push_back(*it);
			return L;
		}

		list<string> uncommonVarVar() {
			set<string> temp;
			for (set<SubHandlingData>::const_iterator it = InsertionVar.begin(); it != InsertionVar.end(); it++) {
				for (map<string, liS>::const_iterator i = it->second.begin(); i != it->second.end(); i++) {
					temp.insert(varName(i->first));
				}
			}
			list<string> out;
			for (set<string>::iterator i = temp.begin(); i != temp.end(); i++)
				out.push_back(*i);
			return out;
		}

		int insertVar(list<int> Vehicles, list<int> Variables) {
			if (dirF1 == "" || dirF2 == "")
				return 0;
			list<string> AVe = uncommonVarVeh();
			list<string> AVa = uncommonVarVar();
			set<string> auxVe, auxVa;
			int j = 0;
			while (!Vehicles.empty()) {
				if (j == Vehicles.front()) {
					string x = AVe.front();
					int p = x.find_last_of(" ");
					if (p != string::npos)
						x = x.substr(p + 1, string::npos);
					auxVe.insert(x);
					Vehicles.pop_front();
				}
				AVe.pop_front();
				j++;
			}
			j = 0;
			while (!Variables.empty()) {
				if (j == Variables.front()) {
					string x = AVa.front();
					auxVa.insert(x);
					Variables.pop_front();
				}
				AVa.pop_front();
				j++;
			}
			for (set<string>::iterator s = auxVe.begin(); s != auxVe.end(); s++) {
				SubHandlingData temp;
				temp.first = *s;
				set<SubHandlingData>::const_iterator a = InsertionVar.find(temp);
				for (map<string, liS>::const_iterator j = a->second.begin(); j != a->second.end(); j++) {
					if (auxVa.find(varName(j->first)) != auxVa.end()) {
						temp.second[j->first] = j->second;
					}
				}
				AllowedInsertionVar.insert(temp);
			}
			merge(Vehicles, Variables);
			AllowedInsertionVar.clear();
			return 1;
		}

	};

};
