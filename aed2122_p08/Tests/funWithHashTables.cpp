// AED 2021/2022 - Aula Pratica 08
// Pedro Ribeiro (DCC/FCUP) [12/12/2021]

#include "funWithHashTables.h"
#include "hashTable.h"

#include <vector>
#include <iostream>
#include <cctype>
#include <cmath>

// Exemplo de função de hash para ints
unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
}

// Exemplo de função de hash para strings
unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

// ----------------------------------------------------------
// Exercicio 1: Tabelas de Dispersão
// ----------------------------------------------------------

// ..............................
// d) Contando diferentes somas de pares
// TODO
int FunWithHashTables::sumPairs(const vector<int>& numbers) {
    int count = 0, size = numbers.size();
    HashTable<int> table(size, hashInt);
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i + 1; j < numbers.size(); j++){
            if(table.getNumEmpty() == 1){
                size *= 2;
                table.rehash(size);
            }
            int key = numbers[i] + numbers[j];
            table.insert(key);
        }
  return table.getNumActive();
}

// ----------------------------------------------------------
// Exercicio 2: Um padrão no DNA
// ----------------------------------------------------------
// TODO
int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {
  unordered_map<string, int> map;
  int m = 0;
  for(int i = 0; i <= dna.length() - k; i++) {
      pair<string, int> seq(dna.substr(i, k), 1);
      pair<unordered_map<string, int>::iterator, bool> in = map.insert(seq);
      if (!in.second) {
          in.first->second++;
          m = max(m, in.first->second);
      }
  }
  unordered_map<string, int>::iterator it = map.begin();
  while(it != map.end()){
      if(it->second == m)
          motifs.insert(it->first);
      it++;
  }
  return m;
}

// ----------------------------------------------------------
// Exercicio 3: Torre de Babel
// ----------------------------------------------------------
// TODO
vector<string> split(string t);

void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {
    vector<string> words = split(text);
    unordered_multimap<string, string> reDict;
    for(auto it = dict.begin(); it != dict.end(); it++){
        string lang = it->first;
        for(auto et = it->second.begin(); et != it->second.end(); et++){
            pair<string, string> load (*et, lang);
            reDict.insert(load);
        }
        answer.insert(pair<string, int>(lang, 0));
    }
    for(auto word : words){
        auto range = reDict.equal_range(word);
        for(auto it = range.first; it != range.second; it++){
            answer.find(it->second)->second++;
        }
    }
}

vector<string> split(string in){
    vector<string> ret;
    string load = "";
    for(int i = 0; i <= in.length();i++){
        if(!isalpha(in[i]) || i == in.length()){
            if(!load.empty()) {
                ret.push_back(load);
                load.clear();
            }
        }
        else
            if(isalpha(in[i]))
                load += tolower(in[i]);
    }
    return ret;
}

// ----------------------------------------------------------
// Exercicio 4: Palavras Alienígenas
// ----------------------------------------------------------
// TODO

vector<string> makeWords(int l) {
    string load;
    vector<string> v;
    if(v.empty()){
        for(char c = 'a'; c <= 'z'; c++){
            load = c;
            v.push_back(load);
        }
    }
    int i = 0;
    bool stop = false;
    while(!stop){
        for(char c = v[i][v[i].length()-1] + 1; c <= 'z'; c++){
            load = v[i] + c;
            if(load.length() > l){
               stop = true;
               break;
            }
            v.push_back(load);
        }
        i++;
    }

    return v;
}


unordered_map<string, int> makeMap(vector<string> v){
    unordered_map<string, int> ret;
    int i = 1;
    for(auto w : v) {
        ret.insert(pair<string, int>(w, i));
        i++;
    }
    return ret;
}
void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
    unsigned int m = 0;
    for(auto word : words){
        m = max(m, word.length());
    }
    vector<string> v = makeWords(5);
    unordered_map<string, int> map = makeMap(v);
    for(auto w : words)
        answer.push_back(map.find(w)->second);

}


