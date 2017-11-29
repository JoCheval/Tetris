#ifndef __MUSIC_H
#define __MUSIC_H

// relics of the past
/*
#define NONOTE htim4.Instance->PSC=0
#define DOTEN HAL_Delay(quarter*3/4);
#define TRIPA HAL_Delay(quarter*2/3 - 50);NONOTE;HAL_Delay(50);
#define TRIPB HAL_Delay(quarter/3);
#define EIGHN HAL_Delay(quarter/2);
#define EIGHNS HAL_Delay(quarter/2 -50);NONOTE;HAL_Delay(50);
#define DOTQN HAL_Delay(quarter*3/2);
#define QUARN HAL_Delay(quarter);
#define QUARNS HAL_Delay(quarter-50);NONOTE;HAL_Delay(50);
#define DOTHN HAL_Delay(quarter*3);
#define HALFN HAL_Delay(quarter*2);
#define WHOLN HAL_Delay(quarter*4);
#define SIXN HAL_Delay(quarter*3-50);NONOTE;HAL_Delay(50);
#define CHPSC htim4.Instance->PSC=note
#define CHPSC2 htim4.Instance->PSC=note2
#define CHPSC3 htim4.Instance->PSC=note3
#define CHPSC4 htim4.Instance->PSC=note4
#define ARRVAL htim4.Instance->ARR
#define ADSR htim4.Instance->CCR1
*/
/*
const int note3[9] = {
538.2335483,
8231.727444, // C3
7333.489389,
6533.330908, // E3
6166.591071,
5493.505495, // G3
4894.104895,
4360.071827,
4115.206387
};*/

#define WHOL *4
#define DOTH *3
#define DOTHS *3 - 50
#define HALFS *2 - 50
#define HALF *2
#define DOTQ *3/2
#define DOTQS *3/2 - 50
#define QUARS -50
#define QUAR *1
#define DOTE *3/4
#define EIGHS /2 - 50
#define EIGH /2
#define SIXT /4
#define STAC 50
#define TRIPA *2/3 - 50
#define TRIPB 50
#define TRIPC /3

const int note[] = {
2746.252747, // G4
2446.552448, // A4
2179.535913, // B4
2057.142526, // C5
1832.591128, // D5
1632.557948, // E5
1454.321122, // F#5
1372.643895, // G5
1222.776224, // A5
1089.256919, // B5
1028.071263, // C6
915.7955638, // D6
815.7727791, // E6
726.6605609, // F#6
685.8219473, // G6
};

const int noiseScale[] = {
0, // no note
2446.552448, // A4
2309.200525, // A#4
2179.535913, // B4
2057.142526, // C5
	
544.1312189, // B6
407.3863895 // E7
};

const int kirbyScale[] = {
0, // no note
1729.691968, // Eb5
2057.142526, // C5
1832.591128,
1632.557948,
1540.853616,
1372.643895, // G5
1222.776224,
1089.256919,
1028.071263, // C6
915.7955638,
815.7727791,
769.932327,
685.8219473,
610.8881119,
544.1312189,
513.5356316, // C7
864.3390306, // Eb6
// bass notes start
538.2335483, 
8231.727444, // C3
7333.489389,
6533.330908, // E3
6166.591071,
5493.505495, // G3
4894.104895,
4360.071827,
4115.206387
};

const int tetrisScale[] = {
0, // no note
6533.330908,
6166.591071,
5185.241642, // G#3
4894.104895,
4360.071827,
4115.206387,
3666.244694,
3266.066338,
3082.707233,
2592.120821, // G#4
2446.552448,
2179.535913,
2057.142526,
1832.591128,
1632.557948, // E5
1540.853616,
1372.643895,
1222.776224 // A5
};

const int zeldaScale[] = {
0, // no note
1832.591128, // D5
1632.557948, // E5
1540.853616, // F5
1372.643895, // G5
1222.776224, // A5
1089.256919, // B5
1028.071263, // C6
915.7955638, // D6
815.7727791, // E6
769.932327, // F6
685.8219473, // G6
};

const char noise1Notes[] = {
	1,2,3,4,0
};

const int noise1Times[] = {
	n1quarter QUAR,n1quarter QUAR,n1quarter QUAR,n1quarter DOTH,n1quarter/2
};

const char noise2Notes[] = {
	4,0,4,0,4,2,4,0
};

const int noise2Times[] = {
	n2quarter EIGH,n2quarter DOTE,n2quarter EIGHS,STAC,
	n2quarter EIGH,n2quarter EIGH,n2quarter HALF,n2quarter/2
};
const char noise3Notes[] = {
	5,6,6,0
};

const int noise3Times[] = {
	n3quarter EIGH,n3quarter DOTQ,n3quarter HALF,n3quarter/2
};

const char tetrisNotes[] = {
	15,12,13,
	14,13,12,
	11,0,11,13,
	15,14,13,
	12,0,12,13,
	14,15,13,
	11,0,11,0,
	
	14,16,18,17,16,
	15,13,15,14,13,
	12,0,12,13,14,15,
	13,11,0,11,0,
	
	8,6,7,5,
	6,4,3,5,
	8,6,7,5,
	6,8,11,0,10,0
};

const int tetrisTimes[] = {
	tquarter QUAR,tquarter EIGH,tquarter EIGH,
	tquarter QUAR,tquarter EIGH,tquarter EIGH,
	tquarter QUARS,STAC,tquarter EIGH,tquarter EIGH,
	tquarter QUAR,tquarter EIGH,tquarter EIGH,
	tquarter QUARS,STAC,tquarter EIGH,tquarter EIGH,
	tquarter QUAR,tquarter QUAR,tquarter QUAR,
	tquarter QUARS,STAC,tquarter QUAR,tquarter QUAR,
		
	tquarter DOTQ,tquarter EIGH,tquarter QUAR,tquarter EIGH,tquarter EIGH,
	tquarter DOTQ,tquarter EIGH,tquarter QUAR,tquarter EIGH,tquarter EIGH,
	tquarter QUARS,STAC,tquarter EIGH,tquarter EIGH,tquarter QUAR,tquarter QUAR,
	tquarter QUAR,tquarter QUARS,STAC,tquarter QUAR,tquarter QUAR,
		
	tquarter HALF,tquarter HALF,tquarter HALF,tquarter HALF,
	tquarter HALF,tquarter HALF,tquarter HALF,tquarter HALF,
	tquarter HALF,tquarter HALF,tquarter HALF,tquarter HALF,
	tquarter QUAR,tquarter QUAR,tquarter HALFS,STAC,tquarter WHOL,tquarter EIGH
};

const char kirbyNotes[] = {
	// A
	6,0,6,9,0,
	9,0,11,
	13,16,15,14,13,
	11,0,13,12,10,0,11,10,11,0,10,9,0,
	
	// A
	6,0,6,9,0,
	9,0,11,
	13,16,15,14,13,
	11,0,13,12,10,0,11,10,11,0,10,9,9,0,
	
	// B
	9,10,11,9,10,9,
	// bass
	19,23,0,23,0,23,0,23,0,23,0,23,0,23,0,
	19,23,0,23,0,23,0,23,0,23,0,23,0,23,0,
	
	// C
	1,3,0,1,5,1,0,5,6,5,0,6,
	2,0,2,0,3,1,3,0,1,5,1,0,5,
	6,9,0,
	
	// D
	9,0,10,17,10,0,17,12,17,0,12,13,
	12,0,13,9,0,9,0,10,17,10,0,17,12,17,0,12,10,13,0
};

const int kirbyTimes[] = {
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter DOTHS,STAC,
	kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter EIGH,kquarter EIGH,kquarter EIGH,kquarter EIGH,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter DOTHS,STAC,
	
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter DOTHS,STAC,
	kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter EIGH,kquarter EIGH,kquarter EIGH,kquarter EIGH,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter DOTH,kquarter QUARS, STAC,
	
	kquarter QUAR,kquarter EIGH,kquarter QUAR,kquarter EIGH,kquarter EIGH,kquarter EIGH,
	kquarter EIGH,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,
	kquarter EIGH,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,kquarter EIGHS,STAC,
	
	kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter QUARS,STAC,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter QUAR,kquarter TRIPA,TRIPB,kquarter TRIPC,
	kquarter HALF,kquarter QUARS,STAC,
	
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUARS,STAC,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter QUAR,
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter HALF,kquarter QUAR,kquarter EIGH
};

const char zeldaNotes[] = {
	3,0,5,0,6,3,0,5,0,6,
	3,5,6,0,9,0,8,
	6,7,6,4,2,2,
	1,2,4,2,2,
	
	3,0,5,0,6,3,0,5,0,6,
	3,5,6,0,9,0,8,
	6,7,9,6,4,4,
	6,4,1,2,2,
	
	1,2,3,4,5,6,7,6,2,2,
	3,4,5,6,7,8,9,10,11,11,
	1,2,3,4,5,6,7,6,2,2,
	3,2,0,5,4,0,6,5,0,7,6,0,
	8,7,0,9,8,0,10,9,0,
	6,7,0,5,6,6,6,6,0
};

const int zeldaTimes[] = {
	zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,
	zquarter QUAR,zquarter QUAR,zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,
	zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter DOTH,
	zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter WHOL,
	
	zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,
	zquarter QUAR,zquarter QUAR,zquarter QUARS,STAC,zquarter QUARS,STAC,zquarter HALF,
	zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter DOTH,
	zquarter QUAR,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter WHOL,
	
	zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter WHOL,
	zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter WHOL,
	zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter QUAR,zquarter QUAR,zquarter HALF,zquarter WHOL,
	zquarter QUAR,zquarter QUARS,STAC,zquarter QUAR,zquarter QUARS,STAC,zquarter QUAR,zquarter QUARS,STAC,zquarter QUAR,zquarter QUARS,STAC,
	zquarter QUAR,zquarter QUARS,STAC,zquarter QUAR,zquarter QUARS,STAC,zquarter QUAR,zquarter QUARS,STAC,
	zquarter EIGH,zquarter QUARS,STAC,zquarter EIGH,zquarter WHOL,zquarter WHOL,zquarter WHOL,zquarter HALF,zquarter EIGH
};

#endif
