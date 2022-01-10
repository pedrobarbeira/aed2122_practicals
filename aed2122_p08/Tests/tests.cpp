// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "hashTable.h"
#include "funWithHashTables.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1: Tabelas de Dispersão
// ----------------------------------------------------------

// ..............................
// a) Inserindo elementos
TEST(test_1, insert) {
    cout << "Testando 'insert'" << endl;

    // -------------------------------------------------

    HashTable<int> h(5, FunWithHashTables::hashInt);

    EXPECT_EQ(0, h.getNumActive());
    EXPECT_FALSE(h.contains(42));

    EXPECT_TRUE(h.insert(42));
    EXPECT_FALSE(h.insert(42)); // Já inserido, não deve conseguir voltar a inserir
    EXPECT_TRUE(h.insert(22));
    EXPECT_TRUE(h.insert(50));
    EXPECT_TRUE(h.insert(32));
    EXPECT_FALSE(h.insert(62)); // Tabela já com 4 elementos: mais um iria encher

    EXPECT_EQ(4, h.getNumActive());
    EXPECT_TRUE(h.contains(42));
    EXPECT_TRUE(h.contains(22));
    EXPECT_FALSE(h.contains(62));

    // -------------------------------------------------

    HashTable<string> h2(31, FunWithHashTables::hashString);
    EXPECT_EQ(0, h2.getNumActive());
    vector<string> data = {"um", "dois", "tres", "quatro", "cinco"};
    for (string s : data) EXPECT_FALSE(h2.contains(s));
    for (string s : data) EXPECT_TRUE(h2.insert(s));
    for (string s : data) EXPECT_FALSE(h2.insert(s)); // Já inseridos
    for (string s : data) EXPECT_TRUE(h2.contains(s));
    EXPECT_EQ(5, h2.getNumActive());
    EXPECT_EQ(26, h2.getNumEmpty());
    EXPECT_FALSE(h2.contains("seis"));
}

// ..............................
// b) Removendo elementos
TEST(test_1, remove) {
    cout << "Testando 'remove'" << endl;

    // -------------------------------------------------

    HashTable<int> h(5, FunWithHashTables::hashInt);

    EXPECT_FALSE(h.contains(42));
    EXPECT_TRUE(h.insert(42));
    EXPECT_TRUE(h.contains(42));
    EXPECT_TRUE(h.remove(42));
    EXPECT_FALSE(h.contains(42));
    EXPECT_EQ(4, h.getNumEmpty()); // Posição anterior ficou deleted e não empty
    EXPECT_EQ(0, h.getNumActive());

    EXPECT_FALSE(h.remove(37)); // Elemento não existe

    EXPECT_TRUE(h.insert(0));
    EXPECT_TRUE(h.insert(5));
    EXPECT_TRUE(h.insert(10));
    EXPECT_FALSE(h.insert(15)); // Ao inserir ficava sem posicoes empty (1 deleted + 3 Active ja na tabela)

    EXPECT_EQ(3, h.getNumActive());
    EXPECT_TRUE(h.remove(10));
    EXPECT_EQ(2, h.getNumActive());
    EXPECT_TRUE(h.remove(5));
    EXPECT_EQ(1, h.getNumActive());
    EXPECT_TRUE(h.remove(00));
    EXPECT_EQ(0, h.getNumActive());

    EXPECT_FALSE(h.contains(0));
    EXPECT_FALSE(h.contains(5));
    EXPECT_FALSE(h.contains(10));

    // -------------------------------------------------

    HashTable<string> h2(31, FunWithHashTables::hashString);
    EXPECT_EQ(0, h2.getNumActive());
    vector<string> data = {"um", "dois", "tres", "quatro", "cinco"};
    for (string s : data) EXPECT_TRUE(h2.insert(s));
    for (string s : data) EXPECT_TRUE(h2.contains(s));
    for (string s : data) EXPECT_TRUE(h2.remove(s));
    for (string s : data) EXPECT_FALSE(h2.contains(s));
    EXPECT_EQ(0, h2.getNumActive());
    EXPECT_EQ(26, h2.getNumEmpty());
    EXPECT_FALSE(h2.contains("seis"));
}

// ..............................
// c) Refazendo a tabela
TEST(test_1, rehash) {
    cout << "Testando 'rehash'" << endl;

    // -------------------------------------------------

    HashTable<int> h(31, FunWithHashTables::hashInt);

    vector<int> numbers = {1,2,3,4,5,6,7,8,9,42};
    for (int i : numbers) EXPECT_TRUE(h.insert(i));
    EXPECT_EQ(10, h.getNumActive());

    EXPECT_FALSE(h.rehash(5)); // sem espaço para todos
    EXPECT_FALSE(h.rehash(10)); // sem espaço para ficar um empty

    EXPECT_TRUE(h.rehash(37));
    EXPECT_EQ(10, h.getNumActive());
    EXPECT_EQ(27, h.getNumEmpty());
    for (int i : numbers) EXPECT_TRUE(h.contains(i));
    EXPECT_FALSE(h.contains(41));

    // -------------------------------------------------

    HashTable<string> h2(31, FunWithHashTables::hashString);
    EXPECT_EQ(0, h2.getNumActive());
    vector<string> data = {"um", "dois", "tres", "quatro", "cinco"};
    for (string s : data) EXPECT_TRUE(h2.insert(s));
    EXPECT_TRUE(h2.rehash(6));
    EXPECT_EQ(5, h2.getNumActive());
    EXPECT_EQ(1, h2.getNumEmpty());
    for (string s : data) EXPECT_TRUE(h2.contains(s));
    EXPECT_FALSE(h2.contains("seis"));
}


// ..............................
// d) Contando diferentes somas de pares
TEST(test_1, sumPairs) {
    cout << "Testando 'sumPairs'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    EXPECT_EQ(8, FunWithHashTables::sumPairs({2,3,6,7,8}));

    cout << "  . Outros casos" << endl;
    EXPECT_EQ(1, FunWithHashTables::sumPairs({1,2}));
    EXPECT_EQ(9, FunWithHashTables::sumPairs({1,2,3,4,5,6}));
    EXPECT_EQ(17, FunWithHashTables::sumPairs({2,4,6,14,16,18,20,22}));
}

// ----------------------------------------------------------
// Exercicio 2: Um padrão no DNA
// ----------------------------------------------------------
TEST(test_2, dnaMOtifs) {
    cout << "Testando 'dnaMotifs'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    unordered_set<string> motifs1;
    EXPECT_EQ(3,FunWithHashTables::dnaMotifs("GTATAGCGTAATAGTAG", 3, motifs1));
    unordered_set<string> answer1 = {"GTA", "TAG"};
    EXPECT_EQ(answer1, motifs1);

    cout << "  . Outros casos" << endl;

    unordered_set<string> motifs2;
    EXPECT_EQ(5,FunWithHashTables::dnaMotifs("GTATAGCGTAATAGTAG", 2, motifs2));
    unordered_set<string> answer2 = {"TA"};
    EXPECT_EQ(answer2, motifs2);

    unordered_set<string> motifs3;
    EXPECT_EQ(2,FunWithHashTables::dnaMotifs("GTATAGCGTAATAGTAG", 4, motifs3));
    unordered_set<string> answer3 = {"ATAG"};
    EXPECT_EQ(answer3, motifs3);

    unordered_set<string> motifs4;
    EXPECT_EQ(2,FunWithHashTables::dnaMotifs("GTATATAGCGACTGATCGATGCTA", 3, motifs4));
    unordered_set<string> answer4 = {"ATA","CGA","TAT","GAT"};
    EXPECT_EQ(answer4, motifs4);
}

// ----------------------------------------------------------
// Exercicio 3: Torre de Babel
// ----------------------------------------------------------
TEST(test_3, findLanguage) {
    cout << "Testando 'findLanguage'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    unordered_map<string,vector<string>> dict1;
    dict1["pt"] = {"algoritmos", "estruturas", "dados", "tabela","dispersao"};
    dict1["es"] = {"algoritmos", "estructuras", "datos", "table", "dispersion"};
    dict1["en"] = {"algorithms", "data", "structures", "hash", "table"};
    unordered_map<string, int> answer1;
    FunWithHashTables::findLanguage("Algoritmos e Estruturas de Dados: uma UC de LEIC", dict1, answer1);
    unordered_map<string, int> correct1 = {{"en", 0}, {"es", 1},{"pt",3}};
    EXPECT_EQ(answer1, correct1);

    cout << "  . Outros casos" << endl;

    unordered_map<string,vector<string>> dict2;
    dict2["pt"] = {"quarenta", "dois", "sentido", "vida",};
    dict2["es"] = {"cuarenta", "dos", "significado", "vida"};
    dict2["en"] = {"forty", "two", "meaning", "life",};
    dict2["fr"] = {"quarante", "deux", "sens", "vie",};
    unordered_map<string, int> answer2, correct2;

    answer2.clear(); FunWithHashTables::findLanguage("quarenta e dois: o sentido da vida", dict2, answer2);
    correct2 = {{"pt",4}, {"es",1}, {"en",0}, {"fr",0}};
    EXPECT_EQ(answer2, correct2);

    answer2.clear(); FunWithHashTables::findLanguage("--life--vida--vie--", dict2, answer2);
    correct2 = {{"pt",1}, {"es",1}, {"en",1}, {"fr",1}};
    EXPECT_EQ(answer2, correct2);

    answer2.clear(); FunWithHashTables::findLanguage("cuarenta y dos cuarenta y dos  -  dos   y   cuarenta", dict2, answer2);
    correct2 = {{"pt",0}, {"es",6}, {"en",0}, {"fr",0}};
    EXPECT_EQ(answer2, correct2);

    unordered_map<string,vector<string>> dict3;
    dict3["en"] = {"mind", "killer", "fear", "dune"};
    dict3["us"] = {"mind", "killer", "fear", "dune"};
    dict3["pt"] = {"medo", "assassino", "mente", "dune"};
    unordered_map<string, int> answer3, correct3;

    answer3.clear(); FunWithHashTables::findLanguage("dUnE: FEAR is ThE MiNd killer!", dict3, answer3);
    correct3 = {{"pt",1}, {"en",4}, {"us",4}};
    EXPECT_EQ(answer3, correct3);

    answer3.clear(); FunWithHashTables::findLanguage("atreides harkonnen", dict3, answer3);
    correct3 = {{"pt",0}, {"en",0}, {"us",0}};
    EXPECT_EQ(answer3, correct3);
}

// ----------------------------------------------------------
// Exercicio 4: Palavras Alienígenas
// ----------------------------------------------------------
TEST(test_4, wordIndex) {
    cout << "Testando 'wordIndex'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    vector<int> answer, correct;

    answer.clear(); FunWithHashTables::wordIndex({"ade","a", "ac", "vwxyz"}, answer);
    correct = {399, 1, 28, 83681};
    EXPECT_EQ(answer, correct);

    cout << "  . Outros casos" << endl;

    answer.clear(); FunWithHashTables::wordIndex({"a", "ab", "abc", "abcd", "abcde"}, answer);
    correct = {1, 27, 352, 2952, 17902};
    EXPECT_EQ(answer, correct);

    answer.clear(); FunWithHashTables::wordIndex({"drtv", "ans", "yz", "e", "cimo", "demos"}, answer);
    correct = {10511, 578, 351, 5, 8277, 51014};
    EXPECT_EQ(answer, correct);

    answer.clear(); FunWithHashTables::wordIndex({"fhjk", "knqtw", "tuv", "z", "km"}, answer);
    correct = {12105, 80081, 2917, 26, 233};
    EXPECT_EQ(answer, correct);
}