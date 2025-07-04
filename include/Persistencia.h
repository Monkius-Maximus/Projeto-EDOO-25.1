// Persistencia.h
#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "Os.h"
#include <vector>
#include <string>

// Função responsável por persistir/salvar um vetor de objetos `Os` em arquivo no formato JSON.
void salvarEmJson(
    const std::vector<Os> &listaOs, // Referência constante para um vetor de obejtos `Os`.
                                    // 'const' garante que a função não modificará o vetor original.
    const std::string &caminho);    // Caminho completo do Arquivo JSON onde os dados serão salvos.

std::vector<Os> carregarDoJson(const std::string &caminho); // Esta função é responsável por carregar (ler) dados de um arquivo JSON e reconstruir um vetor de objetos 'Os' a partir desses dados.

#endif
