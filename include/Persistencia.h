// Persistencia.h
#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "Os.h"
#include <vector>
#include <string>

void salvarEmJson(
    const std::vector<Os>& listaOs, 
    const std::string& caminho
);

std::vector<Os> carregarDoJson(const std::string& caminho);

#endif
