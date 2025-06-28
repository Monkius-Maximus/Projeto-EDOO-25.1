#ifndef JSON_SERIALIZERS_HPP
#define JSON_SERIALIZERS_HPP

#include "Os.h"
#include "json.h"

using nlohmann::json;

namespace nlohmann {
    template <>
    struct adl_serializer<Os> {
        static void to_json(json& j, const Os& os) {
            j = json{
                {"numeroOs", os.getNumeroOs()},
                {"dataAbertura", os.getDataAbertura()},
                {"categoria", os.getCategoria()},
                {"servico", os.getServico()},
                {"prioridade", os.getPrioridade()},
                {"comentarioTecnico", os.getComentarioTecnico()},
                {"valor", os.getValor()},
                {"dataFechamento", os.getDataFechamento()},
                {"conclusao", os.isConcluida()},
                {"idMoradorCriador", os.getIdMoradorCriador()},
                {"nomeMoradorCriador", os.getNomeMoradorCriador()},
                {"comentarioMorador", os.getComentarioMorador()},
                {"notaAvaliacao", os.getNotaAvaliacao()},
                {"avaliada", os.isAvaliada()},
                {"idTecnicoResponsavel", os.getIdTecnicoResponsavel()},
                {"nomeTecnicoResponsavel", os.getNomeTecnicoResponsavel()},
                {"atribuida", os.isAtribuida()}
            };
        }
        
        static void from_json(const json& j, Os& os) {
            int numero = j.at("numeroOs");
            string data = j.at("dataAbertura");
            string categoria = j.at("categoria");
            string servico = j.at("servico");
            int prioridade = j.at("prioridade");
            string comentarioTecnico = j.value("comentarioTecnico", "");
            double valor = j.at("valor");
            string dataFechamento = j.at("dataFechamento");
            bool conclusao = j.at("conclusao");
            int idMoradorCriador = j.value("idMoradorCriador", 0);
            string nomeMoradorCriador = j.value("nomeMoradorCriador", "Desconhecido");
            string comentarioMorador = j.value("comentarioMorador", "");
            int notaAvaliacao = j.value("notaAvaliacao", 0);
            bool avaliada = j.value("avaliada", false);
            int idTecnicoResponsavel = j.value("idTecnicoResponsavel", 0);
            string nomeTecnicoResponsavel = j.value("nomeTecnicoResponsavel", "N/A");
            bool atribuida = j.value("atribuida", false);

            os = Os(
                numero,
                data,
                categoria,
                servico,
                prioridade,
                comentarioTecnico,
                valor,
                dataFechamento,
                conclusao,
                idMoradorCriador,
                nomeMoradorCriador,
                comentarioMorador,
                notaAvaliacao,
                avaliada,
                idTecnicoResponsavel,
                nomeTecnicoResponsavel,
                atribuida
            );
        }
    };
}

#endif
