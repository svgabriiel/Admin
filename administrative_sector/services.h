typedef struct {
    int id;
    int ativo;
    char nome [100];
    char cpf[20];
    char senha [30];
    char category[30]
} Identidade;

enum PersonRole {
    ROLE_ALUNO,
    ROLE_PROFESSOR,
    ROLE_FUNCIONARIO
};