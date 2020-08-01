/**
 * Biblioteca Arduino para modulo MFRC522.
 * 
 * @autores Rafael Mascarenhas  e Grabriel Pacheco.
 * 
 * Para mais informacoes , leia o documento README.
 * 
 * Por favor, leia este arquivo para uma visão geral da biblioteca e, depois, o arquivo .cpp para especificacoe das funcoes
 */
#ifndef NFC_h
#define NFC_h

#include "mfrc522.h"
#include <Arduino.h>
#include <SPI.h>

class NFC{
  public: 
    NFC();
	NFC(byte pinoReset);
	NFC(byte pinoSelecaoChip, byte pinoReset);
    
	void iniciar();
	//void iniciar(byte pinoReset);
	//void iniciar(byte pinoSelecaoChip, byte pinoReset);
    	
    //virtual bool CartaoEstaPresente();
	//virtual bool LerCodigoCartao();
	
	virtual void imprimirUID(NFC *nfc, String *conteudo);
	
  protected:
    byte _pinoSelecaoChip, _pinoReset;		
};



#endif
