#include "../include/Os.h"
#include "../include/json.h"
#include "../include/Persistencia.h"
#include "../include/JsonSerializers.h"

#include <fstream>

using json = nlohmann::json;
using namespace std;

void salvarEmJson(const vector<Os>& listaOs, const string& caminho) {
    json j = listaOs;
    ofstream arquivo(caminho);
    arquivo << j.dump(4);
    arquivo.close();
}

vector<Os> carregarDoJson(const string& caminho) {
    ifstream arquivo(caminho);
    vector<Os> listaOs;

    if (arquivo.is_open()) {
        json j;
        arquivo >> j;
        listaOs = j.get<vector<Os>>();
    }

    return listaOs;
}
