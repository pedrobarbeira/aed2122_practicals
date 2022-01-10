// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <set>
#include <map>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    int count = 0;
    set<int> cards;

    for(auto card : collection)
        cards.insert(card);

    for(auto card: bag){
        if(cards.insert(card).second) count++;
    }

    return count;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
  int ret;
  multiset<int> aliceCards, brunoCards;
  for(auto card : alice)
      aliceCards.insert(card);
  cout << endl;
  for (auto card : bruno)
      brunoCards.insert(card);

  multiset<int>::iterator aliceMove;
  multiset<int>::iterator brunoMove;

    while(!aliceCards.empty() && !brunoCards.empty()){
     aliceMove = --aliceCards.end();
     brunoMove = --brunoCards.end();

     if(*aliceMove > *brunoMove){
         aliceCards.erase(aliceMove);
         aliceCards.insert(*aliceMove - *brunoMove);
         brunoCards.erase(brunoMove);
     }
     else if(*aliceMove < *brunoMove){
         brunoCards.erase(brunoMove);
         brunoCards.insert(*brunoMove-*aliceMove);
         aliceCards.erase(aliceMove);
     }
     else{
         aliceCards.erase(aliceMove);
         brunoCards.erase(brunoMove);
     }
 }

  if(aliceCards.empty()){
      if(brunoCards.empty())
          return 0;
      else return -brunoCards.size();
  }
  else return aliceCards.size();
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    set<string> movies;
    string name;
    for(auto review : reviews){
        name = review.first;
        movies.insert(name);
    }
  return movies.size();
}

// ..............................
// b) O filme com mais reviews
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> movies;
    string name;
    m = 1;
    n = 0;
    int revCount = 0;

    for(const auto& review : reviews){
        name = review.first;
        pair<string, int> in(name, 1);
        pair<map<string,int>::iterator, bool> it = movies.insert(in);
        if(!it.second){
            revCount = ++it.first->second;
            if(revCount > m){
                m = revCount;
                n = 1;
            }
            else if(revCount == m)
                n++;
        }
        else{
            if(m == 1) n++;
        }
    }
}

// ..............................
// c) Os melhores filmes
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    map<string, pair<int, double>> movies;
    string name;
    for(auto& review : reviews){
        pair<string, pair<int, double>> in(review.first, pair<int, double>(review.second, 1));
        pair<map<string, pair<int, double>>::iterator, bool> it = movies.insert(in);
        if(!it.second){
            it.first->second.first += review.second;
            it.first->second.second++;
        }
    }

    for(auto movie : movies){
        if(movie.second.first/movie.second.second >= k) answer.push_back(movie.first);
    }

    return answer;
}
