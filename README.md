# Gerenciamento_de_Arena_Esportiva
- Esse repositório tem como objetivo desenvolver um projeto de gerenciamento de uma arena esportiva, feito na linguagen C. 
***

## Desenvolvedores
>[Eduardo Abrantes](https://github.com/DuardoEdu2)
>
>[Giovanni Willian](https://github.com/GiovanniWillian)
***

# Tabela de conteúdo
> [Introdução](#introdução)
> 
> [Problemática](#problemática)
> 
> [Menu](#menu)
>
> [Organização Repositório](#organização-repositório)
***

# Introdução 
O sistema desse repositorio, permite que o usuário seja capaz de gerenciar uma arena esportiva de forma fácil. Podendo cadastrar e editar informações dos eventos que estão para acontecer e os times participantes.
***

# Problemática
Projetar um sistema na Linguagem C para gerenciamemto de uma arena esportiva. O sistema terá que manicuplar eventos e times.
***

## Menu
As sequintes opçãoes estão presentes no nosso menu:
- **Criar evento:** Cria um novo evento na lista;
- **Remove evento:** Remove um evento da lista;
- **Adiciona time a um evento:** Adiciona um time a um evento presente na lista;
- **remove time de um evento:** Remove um time do evento da lista;
- **Editar time:** Edita todas as caracteristicas de um time;
- **Busca time:** Busca algum time presente na lista de eventos pelo nome;
- **Listar eventos e seus times:** Mostra a lista de eventos e seus respectivos times;
- **Sair:** finaliza o programa.
***

# Organização Repositório
``` 
📁 Gerenciamento_de_Clinica_Veterinaria
│
└───Gerenciamento_de_arena_esportiva
        │
        ├──include
            │
            └───evento.h
            └───funcao.h
            └───time.h
        ├──src
            │
            └───evento.c
            └───funcao.c
            └───main.c
            └───time.c
            └───eventos_e_times.txt
