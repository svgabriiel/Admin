#include <cstdlib>
#include <cstring>
#include <random>
#include "utilidades.h"
#include "headers.h"
#include <chrono>


using namespace std;

void limpar_tela() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

const char* enumerado_para_texto(funcao_pessoa f) {
    switch (f) {
        case ALUNO:      return "ALUNO";
        case PROFESSOR:  return "PROFESSOR";
        case ADMIN:      return "ADMIN";
        case VENDEDOR:   return "VENDEDOR";
        case LOCADOR:    return "LOCADOR";
        default:         return "DESCONHECIDO";
    }
}


// Gera um CPF aleatório
void generate_random_cpf(char *cpf_buffer) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9);

    for (int i = 0; i < 11; i++) {
        cpf_buffer[i] = '0' + dist(rng);
    }
    cpf_buffer[11] = '\0';
}

// Gera um nome aleatório
void generate_random_name(char *name_buffer) {

    static std::mt19937 rng(
        std::chrono::high_resolution_clock::now()
        .time_since_epoch().count()
    );

    static const char *first_names[] = {
        "Cleitinho","Gabriel","Marcos","Joao","Pedro",
        "Maria","Ana","Beatriz","Carla","Diana","Clara",
        "Lucas","Matheus","Rafael","Bruno","Felipe",
        "Naruto","Sasuke","Sakura","Kakashi","Hinata",
        "Shikamaru","Itachi","Gaara","Tsunade","Jiraiya",
        "Minato","Homer","Marge","Bart","Lisa","Maggie"
    };

    static const char *middle_names[] = {
        "da Quebrada","do Vale","das Neves","do Norte",
        "de Jesus","dos Roles","da Nevoa","da Escuridao",
        "do Armario","do Amor","da Alegria","do Sol","da Lua",
        // Lugares / comunidade
        "do Povo", "da Vila", "do Bairro", "da Rua", "do Centro",
        "da Colina", "do Morro", "do Sertao", "do Agreste", "do Interior",

        // Valores / sentimentos
        "da Paz", "da Esperanca", "do Sonho", "do Destino", "da Fe",
        "do Caminho", "da Verdade", "do Silencio", "da Forca", "do Tempo",

        // Natureza / elementos
        "do Fogo", "da Agua", "do Vento", "da Terra", "do Sol Nascente",
        "da Lua Cheia", "do Horizonte", "da Aurora", "do Crepusculo", "da Noite",

        // Direcoes / regioes
        "do Norte", "do Sul", "do Leste", "do Oeste", "do Vale Verde",
        "da Serra", "do Rio", "do Campo", "da Estrada", "do Porto"
    };

    static const char *last_names[] = {
        "Silva","Santos","Oliveira","Souza","Ferreira",
        "Uzumaki","Uchiha","Haruno","Namikaze","Simpson",
        "Yamanaka","Nara","Akimichi","Senju","Sarutobi",
        "Hyuga","Aburame","Inuzuka","Kaguya","Tsuchikage",
        "Almeida","Araújo","Barbosa","Batista","Bezerra",
        "Braga","Campos","Cardoso","Carvalho","Cavalcante",
        "Correia","Costa","Cruz","Cunha","Dias","Duarte",
        "Farias","Freitas","Figueiredo","Gomes","Guimarães",
        "Lima","Lopes","Machado","Marques","Martins","Medeiros",
        "Monteiro","Moraes","Moura","Nascimento","Pacheco","Peixoto",
        "Pereira","Pinto","Ramos","Ribeiro","Rocha","Sales","Siqueira",
        "Soares","Teixeira","Torres","Vasconcelos","Vieira","Xavier",
        "Rezende","Moreira","Tavares"
    };

    int first_count  = sizeof(first_names)  / sizeof(first_names[0]);
    int middle_count = sizeof(middle_names) / sizeof(middle_names[0]);
    int last_count   = sizeof(last_names)   / sizeof(last_names[0]);

    std::uniform_int_distribution<int> d1(0, first_count - 1);
    std::uniform_int_distribution<int> d2(0, middle_count - 1);
    std::uniform_int_distribution<int> d3(0, last_count - 1);
    std::uniform_int_distribution<int> use_middle(0, 6); // ~85% de probabilidade

    const char *part1 = first_names[d1(rng)];
    const char *part3 = last_names[d3(rng)];

    name_buffer[0] = '\0';

    std::strcat(name_buffer, part1);

    // usa nome do meio com alta probabilidade
    if (use_middle(rng) < 6) {
        const char *part2 = middle_names[d2(rng)];
        std::strcat(name_buffer, " ");
        std::strcat(name_buffer, part2);
    }

    std::strcat(name_buffer, " ");
    std::strcat(name_buffer, part3);
}