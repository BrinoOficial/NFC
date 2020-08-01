/*
* NFC.cpp - Biblioteca Arduino para modulo MFRC522 13.56 MHZ com TAGS SPI W e R.
* NOTA: Por favor confira os comentarios em NFC.h - eles apresentam dicas importantes.
*/

#include <Arduino.h>
#include "mfrc522.h"
#include "NFC.h"

/////////////////////////////////////////////////////////////////////////////////////
// Funcoes para configurar o Arduino
/////////////////////////////////////////////////////////////////////////////////////
/**
 * Construtor.
 */
 
NFC:: NFC() : NFC(SS, UINT8_MAX){ // SS esta definido em pins_arduino.h, UINT8_MAX significa que nao ha conexao entre o Arduino com entrada RESET do MFRC522
	MFRC522 mfrc522();
} // fim do construtor

/**
 * Construtor.
 * Prepara os pinos de saida.
 */
NFC:: NFC(	byte pinoReset	///< Arduino pin connected to MFRC522's reset and power down input (Pin 6, NRSTPD, active low). If there is no connection from the CPU to NRSTPD, set this to UINT8_MAX. In this case, only soft reset will be used in PCD_Init().
				): NFC(SS, pinoReset) { // SS is defined in pins_arduino.h
	MFRC522 mfrc522(pinoReset);
} // End constructor


/**
 * Constructor.
 * prepara os pinos de saida.
 */
NFC::NFC(	byte pinoSelecaoChip,		///< Arduino pin connected to MFRC522's SPI slave select input (Pin 24, NSS, active low)
					byte pinoReset	///< Arduino pin connected to MFRC522's reset and power down input (Pin 6, NRSTPD, active low). If there is no connection from the CPU to NRSTPD, set this to UINT8_MAX. In this case, only soft reset will be used in PCD_Init().
				) {
	_pinoSelecaoChip = pinoSelecaoChip;
	_pinoReset = pinoReset;
	MFRC522 mfrc522(pinoSelecaoChip, pinoReset);
} // End constructor


/////////////////////////////////////////////////////////////////////////////////////
// Functions for manipulating the MFRC522
/////////////////////////////////////////////////////////////////////////////////////

/**
 * Initializes the MFRC522 chip.
 */
 
void NFC::iniciar(){
	NFC();
	mfrc522.PCD_Init();
}
	