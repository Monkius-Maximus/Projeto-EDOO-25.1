<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=66CDAA&height=120&section=header"/>

# SGMP - Sistema de Gerenciamento de Manutenção Predial 🏢🧰

Projeto desenvolvido para a disciplina de **Engenharia de Software com Orientação a Objetos (EDOO)**, utilizando a linguagem **C++** e os princípios fundamentais da **Programação Orientada a Objetos**.

---

## 📌 Objetivo

O SGMP tem como foco oferecer uma plataforma digital para **organizar, registrar e gerenciar manutenções prediais** dentro de condomínios ou edifícios. Ele visa substituir os métodos informais por um sistema rastreável e seguro, garantindo **transparência**, **controle** e **histórico de ordens de serviço (OS)**.

---

## 👨‍💻 Integrantes da Equipe

- Bruno Gabriel `<bgprs>`
- Diogo da Silva `<dsr>`
- Felipe Berardo `<fbalv>`
- Hugo José `<hjbc>`
- Lucas Cabral `<lsc>`

---

## 🧱 Tecnologias e Ferramentas

- 🖥️ Linguagem: **C++**
- 💾 Paradigma: **Programação Orientada a Objetos**
- 📋 Documentação: **Google Docs, Miro, Youtube**
- 🎨 Apresentação visual: **Canva, Miro**
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
🔗 [](githubpages virá aqui)

> *Feita com HTML e CSS para visualização e documentação do projeto.*

---

## Passos para rodar o projeto localmente

1. Estar Utilizando o Sistema Operacional Windows

2. Clone o repositório:
```bash
https://github.com/Monkius-Maximus/Projeto-EDOO-25.1.git
```
3. Abrir o Terminal

4. Utilizar o Comando "./config" para compilar e executar o código.

## 📎 Links Úteis

- 📒 Miro Diagrama de Classes (Documentação): [Acessar](https://miro.com/app/board/uXjVIjGJgRI=/?share_link_id=360641450079)
- 🖼️ Video Gravação da Equipe (Documentação): [Acessar]() 

---

## 📃 Licença

Este projeto é de caráter acadêmico, sem fins lucrativos. Todos os direitos reservados aos autores.

## Equipe do Projeto

<div align="center">

  <table>
    <tr>
      <td align="center">
        <img src="https://avatars.githubusercontent.com/u/162474087?v=4" width="100px" alt="Pessoa 1"/><br/>
        <b>Bruno Ramos 1</b>
      </td>
      <td align="center">
        <img src="https://avatars.githubusercontent.com/u/155683708?v=4" width="100px" alt="Lucas Cabral"/><br/>
        <b>Lucas Cabral</b>
      </td>
      <td align="center">
        <img src="https://avatars.githubusercontent.com/u/204962998?v=4" width="100px" alt="Samuel Miranda"/><br/>
        <b>Felipe Berardo</b>
      </td>
      <td align="center">
        <img src="https://avatars.githubusercontent.com/u/149613054?v=4" width="100px" alt="Pessoa 3"/><br/>
        <b>Diogo Rodrigues</b>
      </td>
      <td align="center">
        <img src="https://avatars.githubusercontent.com/u/205383087?v=4" width="100px" alt="Pessoa 3"/><br/>
        <b>Hugo Joseph</b>
      </td>
    </tr>
  </table>

</div>

---

<p align="center">
  &copy; 2025 Universidade Federal de Pernambuco - Centro de Informática. Todos os direitos reservados.
</p>

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=66CDAA&height=120&section=header"/>
