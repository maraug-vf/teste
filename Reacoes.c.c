#include display, gfx, led, buzzer
#include "ihm_reacoes.h"

adicionei este texto no arquivo.

_Elemento_Retangulo 	//Item selecionado
_Elemento_Scrollbar 	//Indicador rolagem tela
_Elemento_InverteCor 	//Item selecionado


void TelaApresentacao( void )
{
  uint8_t mascara;
  uint8_t pixel;
  uint16_t i=0;
  uint8_t offset_y=0;

  char logo[504] =
  {
    0xff, 0x0f, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x39, 0x45, 0xc5, 0xc5, 0x45, 0x39, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x03, 0x04, 0x04, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x42, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x1f, 0x0e, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x0e, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0xff, 0xff, 0xf0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xff
  };  

  for(uint8_t Y=0; Y<6; Y++)
  {
    offset_y = 8*Y;
    for(uint8_t x=0; x<84; x++)
    {
      mascara = 0x01;
      for(uint8_t y=0; y<8; y++)
      {
        
        pixel = logo[i] & mascara;
        if( pixel )
        {
          display.drawPixel(x, y+offset_y, BLACK);
        }
        else
        {        
          display.drawPixel(x, y+offset_y, WHITE);
        }
        //delay(1);
        //display.display();
        mascara = mascara << 1;
      }  
      i ++;    
    }        
  }

  display.display();
  
  delay(1000);
  display.setCursor(23,39);
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE);

  display.printf("s");
  display.display();
  delay(100);  
  display.printf("y");
  display.display();
  delay(100);
  display.printf("s");
  display.display();
  delay(100);
  display.printf("t");
  display.display();
  delay(100);
  display.printf("e");
  display.display();
  delay(100);
  display.printf("m");
  display.display();
  delay(100);
  display.printf("s");
  display.display();
}

void Reacoes_vTelaSensor( void* pvParametros )
{
	uint16_t Caixa = 05;
  	uint16_t Porcentagem = 52;
  	uint16_t Nivel = 22;

  // Calculos


  // Limpa o display
	display.clearDisplay();

  // Desenho da caixa
  // parede esq dupla
  display.drawLine(0,2,7,47,BLACK);
  display.drawLine(1,2,8,46,BLACK);
  // direita
  display.drawLine(43,2,36,47,BLACK);
  display.drawLine(42,2,35,46,BLACK);
  // inferior
  display.drawLine(8,47,35,47,BLACK);
  display.drawLine(9,46,34,46,BLACK);
  // linha nivel
  display.drawLine(9,22,33,22,BLACK);

  // Identificador da caixa
  display.setTextSize(1);
	display.setTextColor(BLACK);
	display.setCursor(49,2);
  display.printf("CAIXA");  
  display.setCursor(58,13);
  display.printf("%02lu", Caixa);
  display.drawRoundRect(56,11,15,11,2,BLACK);
  
  // Porcentagem
  display.setTextSize(2);
	display.setCursor(47,32);
	display.setTextColor(BLACK);
	display.printf("%02lu%%", Porcentagem);
  
  // Atualiza o display
  display.display();
}

void Reacoes_vTelaMenu( void* pvParametros )
{
	
}

void Reacoes_vTelaConfiguracoes( void* pvParametros )
{
	
}

void Reacoes_vTelaConexoes( void* pvParametros )
{
	
}

void Reacoes_vTelaAlarmes( void* pvParametros )
{
	
}


void IHM_REACOES_vTela1( void* pvParameters )
{
	
}

