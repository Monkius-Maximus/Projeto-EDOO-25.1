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
                {"comentario", os.getComentario()},
                {"valor", os.getValor()},
                {"dataFechamento", os.getDataFechamento()},
                {"conclusao", os.isConcluida()},
            };
        }
        
        static void from_json(const json& j, Os& os) {
            int numero = j.at("numeroOs");
            string data = j.at("dataAbertura");
            string categoria = j.at("categoria");
            string servico = j.at("servico");
            int prioridade = j.at("prioridade");
            string comentario = j.at("comentario");
            double valor = j.at("valor");
            string dataFechamento = j.at("dataFechamento");
            bool conclusao = j.at("conclusao");

            os = Os(
                numero,
                data,
                categoria,
                servico,
                prioridade,
                comentario,
                valor,
                dataFechamento,
                conclusao
            );
        }
    };
}

#endif
