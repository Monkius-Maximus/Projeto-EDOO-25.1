# SGMP - Sistema de Gerenciamento de Manutenção Predial 🏢🧰

Projeto desenvolvido para a disciplina de **Engenharia de Software com Orientação a Objetos (EDOO)**, utilizando a linguagem **C++** e os princípios fundamentais da **Programação Orientada a Objetos**.

---

## 📌 Objetivo

O SGMP tem como foco oferecer uma plataforma digital para **organizar, registrar e gerenciar manutenções prediais** dentro de condomínios ou edifícios. Ele visa substituir os métodos informais por um sistema rastreável e seguro, garantindo **transparência**, **controle** e **histórico de ordens de serviço (OS)**.

---

## 👨‍💻 Integrantes da Equipe

- Bruno Gabriel `<bgprs>`
- Diogo da Silva `<dsr>`
- Felipe Berardo
- Hugo José `<hjbc>`
- Lucas Cabral

---

## 🧱 Tecnologias e Ferramentas

- 🖥️ Linguagem: **C++**
- 💾 Paradigma: **Programação Orientada a Objetos**
- 📋 Documentação: **Notion**
- 🎨 Apresentação visual: **Canva**
- 🌐 Interface Web: **HTML + (GitHub Pages)**

---

## 🧩 Arquitetura do Sistema

O sistema é composto pelas seguintes classes:

- `Pessoa` (classe base): nome, ID, contato.
- `Morador`: herda de Pessoa; possui apartamento e bloco.
- `Técnico`: herda de Pessoa; possui especialidade.
- `OrdemDeServico`: gerencia a OS, status, datas, morador solicitante e técnico responsável.

### 🧠 Princípios de POO Aplicados

| Conceito         | Como foi aplicado                                              | Benefício                            |
|------------------|----------------------------------------------------------------|---------------------------------------|
| **Herança**       | `Morador` e `Técnico` herdam de `Pessoa`                      | Reutilização de código e hierarquia   |
| **Polimorfismo**  | Método virtual `exibirInformacoes()`                          | Flexibilidade para múltiplos perfis   |
| **Encapsulamento**| Atributos privados e acesso via métodos públicos              | Segurança e consistência dos dados    |
| **Abstração**     | Interface clara de cada classe, escondendo complexidade interna| Facilidade de uso e manutenção        |

---

## 🔄 Fluxo de Uso (Resumo)

1. O morador abre uma nova Ordem de Serviço com uma descrição do problema.
2. A OS é criada com status **"ABERTA"**.
3. Um técnico com especialidade compatível assume a OS.
4. A OS muda para **"EM ANDAMENTO"**.
5. Após a execução do serviço, o técnico finaliza a OS.
6. A OS passa para o status **"CONCLUÍDA"** com todo o histórico registrado.

---

## 🌍 Interface Web (opcional)

Você pode acessar a versão do site em:  
🔗 [](githubpages aqui)

> *Feita com HTML e CSS para visualização e documentação do projeto.*

---

## 📎 Links Úteis

- 📒 Notion (Documentação): [Acessar](https://www.notion.so/200310bb6bd18064a488f352b61458cd?v=202310bb6bd180168bc9000c944c56a0)
- 🖼️ Canva (Apresentação): [Acessar](https://www.canva.com/design/DAGpZUx9FtY/rxkW4Mn8XcwCpa0vm3SdGA/edit)

---

## 📃 Licença

Este projeto é de caráter acadêmico, sem fins lucrativos. Todos os direitos reservados aos autores.

---

## 🚀 Futuras Melhorias

- Integração com banco de dados
- Interface gráfica em Qt
- Filtros de busca por OS
- Relatórios exportáveis (PDF/CSV)
