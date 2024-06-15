#include "acoes.h"
#include "reacoes.h"


int (*pfPonteiroDeReacoes)(void* pvParametros);
void* pvParametros = NULL;


void Estados_vTask( void )
{
	PonteiroDeReacoes = EstadoInicial;

	while(1)
	{
		if( pfPonteiroDeReacoes(pvParametros) == 0 )
		{
			pfPonteiroDeReacoes = EstadoInicial;	
		}
	}
}

int EstadoInicial( void )
{	
	if( Acoes_bTimeout() )
	{
		pvParametros = 
		pfPonteiroDeReacoes = Estado1;
		return 1;
	}
	return 0;
}

int Estado1( void )
{
	int ret = 0;

  	if( Acoes_bClick() )
  	{
	   	pfPonteiroDeReacoes = TelaMenu;
	   	ret = 1;
	}
	else if( Acoes_bEncoderDireita() )
	{
		pfPonteiroDeReacoes = TelaSensor2;
		ret = 1;
	}
	else if( Acoes_bEncoderEsquerda() )
	{
		pfPonteiroDeReacoes = TelaSensor0;
		ret = 1;
	}
	//else
	//{
	//	ret = 0;
	//}   

	return ret;
}

int Estado2( void )
{
  	if()
  	{
    	pfPonteiroDeReacoes = Estado3;
	   	return 1;
	}
	return 0;    	
}

int Estado3( void )
{
  	if()
   		return 0;
}


