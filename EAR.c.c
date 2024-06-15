// Modelo IHM-DEAR
// Dados Estados Ações Reações
// Integra os Dados do sistema, Ações geradas pelo usuário através
// da interface de entrada (botão, encoder) e as respectivas Reações através
// da interface de saída (display, led, buzzer) 
// A reação referente a cada ação, depende do estado atual
// Os dados irão moldar a modular a reação 



#include "Estados.h"
#include "Acoes.h"
#include "Reacoes.h"



// ACOES
#define N_ACOES     4

typedef void(*ptAcoes)(void);

ptAcoes _pxMatrizAcoes[N_ACOES];

typedef enum
{
    CLICK,
    DIREITA,
    ESQUERDA,
    TEMPO
} enEventosUsuario;



// REACOES
#define N_REACOES   20

// As reacoes(telas) possuem o seguinte protótipo padrão
// Retornam um índice, o seu identificador. Serve como referencia para o DAR saber onde ele está no mapa de reacoes 
// Recebem dados, para moldar seu comportamento
typedef uint16_t(*ptReacoes)(uint16_t parametros);

// Esta matriz relaciona todas as acoes possiveis, com suas respectivas reacoes
ptReacoes _pxMatrizReacoes[N_REACOES][N_ACOES] = 
{
    //ACOES
    { Acoes_bClick, Acoes_bEncoderDireita, Acoes_bEncoderEsquerda, Acoes_bTimeout },
    //REACOES
    // ESTADO 0 
    { NULL, NULL, NULL, Reacoes_vTelaSensor(1) },
    // ESTADO 1
    { Reacoes_vTelaMenu(0), Reacoes_vTelaSensor(2), Reacoes_vTelaSensor(0), Reacoes_vTelaSensor(1) },
    // ESTADO 2
    { }
};

// Ponteiro para executar a reacao causada por uma ação.
ptReacoes _pxReacaoAtual;


// ESTADOS
//#define INDICE_DAS_ACOES 0

// O identificador (reacao atual), indexa a linha da matriz que contem as reacoes inerentes ao seu estado atual
//uint16_t _u16EstadoAtual;



// Integra estados, ações e reações 
void EAR_vTask( void )
{
    //_u16EstadoAtual = Estados_enEstadoAtual();

    // Varre as colunas da matriz, mantendo linha constante (Linha 0, eventos) 
    for( uint16_t i = 0; i < N_ACOES; i ++ )
    {
        // Executa o ponteiro da funcao de cada evento
        // O primeiro evento ocorrido, ocasionará sua respectiva reação
        // Organizar as ações de acordo com as prioridades das regras de IHM
        // A reação depende do estado atual
        if( _pxMatrizAcoes[ i ] == true )
        {
            // Registra o ponteiro da tela associada ao evento ocorrido
            // sera usado para saber qual tela mostrar em resposta ao 
            // evento ocorrido            
            _pxReacaoAtual = MatrizControles[_u16EstadoAtual][i]; // pegar o conteudo do ponteiro, sem executar.
            _u16EstadoAtual = _pxReacaoAtual; // executar a funcao e armazenar o retorno na variavel.
        }
    }
}