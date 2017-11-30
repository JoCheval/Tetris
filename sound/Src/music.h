#ifndef __MUSIC_H
#define __MUSIC_H

#define WHOL *4
#define DOTH *3
#define DOTHS *3 - 50
#define HALFS *2 - 50
#define HALF *2
#define DOTQ *3/2
#define DOTQS *3/2 - 50
#define QUARS -50
#define QUAR *1
#define DOTES *3/4 - 50
#define DOTE *3/4
#define EIGHS /2 - 50
#define EIGH /2
#define SIXTS /4 - 50
#define SIXT /4
#define STAC 50
#define TRIPA *2/3 - 50
#define TRIPB 50
#define TRIPC /3

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

const int megaScale[] = {
0, // no note
4360.071827, // B3
4115.206387, // C4
3884.284209, // C#4
3666.244694,
3460.328309, // D#4
3266.066338,
3082.707233, // F4
2909.681578, // F#4
2746.252747, // G4
2592.120821, // G#4
2446.552448, // A4
2309.200525, // A#4
2179.535913,
2057.142526,
1941.607062,
1832.591128,
1729.691968,
1632.557948,
1540.853616,
1454.321122, // F#5
1372.643895, // G5
1295.544801 // G#5
};

const int guileScale[] = {
0, // no note
2057.142526, // C5
1941.607062,
1832.591128,
1729.691968,
1632.557948,
1540.853616,
1454.321122,
1372.643895,
1295.544801,
1222.776224,
1154.087873, // A5
1089.256919, // Bb5
1028.071263,
970.3122915, // C6
915.7955638,
864.3390306, // D6
815.7727791, // Eb6 (17 right now)
769.932327,
726.6605609,
685.8219473,
647.2724004, // G#6
2309.200525 // Bb4
};

const char noise1Notes[] = {1,2,3,4,0};
const int noise1Times[] = {
	n1quarter QUAR,n1quarter QUAR,n1quarter QUAR,n1quarter DOTH,n1quarter SIXT
};

const char noise2Notes[] = {4,0,4,0,4,2,4,0};
const int noise2Times[] = {
	n2quarter EIGH,n2quarter DOTE,n2quarter EIGHS,STAC,
	n2quarter EIGH,n2quarter EIGH,n2quarter HALF,n2quarter SIXT
};

const char noise3Notes[] = {5,6,6,0};
const int noise3Times[] = {
	n3quarter EIGH,n3quarter DOTE,n3quarter EIGH,n3quarter SIXT
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
	tquarter QUAR,tquarter QUAR,tquarter HALFS,STAC,tquarter WHOL,tquarter SIXT
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
	kquarter TRIPA,TRIPB,kquarter TRIPC,kquarter HALF,kquarter QUAR,kquarter SIXT
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
	zquarter EIGH,zquarter QUARS,STAC,zquarter EIGH,zquarter WHOL,zquarter WHOL,zquarter WHOL,zquarter HALF,zquarter SIXT
};

const char megaNotes[] = {
	// A
	3,6,0,6,0,6,0,
	6,0,6,0,6,3,0,
	3,0,3,6,0,6,0,6,0,6,3,0,
	10,8,10,
	
	0,6,0,6,0,6,0,
	6,0,6,0,6,3,0,
	10,0,8,0,6,0,8,0,
	
	0,8,0,8,0,8,0,
	8,0,8,0,8,5,0,
	10,0,8,0,6,0,5,0,3,
	0,3,10,13,12,
	3,0,3,10,13,12,13,15,
	
	// B
	0,6,0,6,0,6,0,
	6,0,6,0,6,3,0,
	3,0,3,6,0,6,0,6,0,6,3,0,
	10,8,10,
	
	0,6,0,6,0,6,0,
	6,0,6,0,6,3,0,
	10,0,8,0,6,0,8,0,
	
	0,8,0,8,0,8,0,
	8,0,8,0,8,5,0,
	10,0,8,0,6,0,5,0,3,
	0,3,10,13,12,
	3,0,3,10,13,12,13,15,
	
	// C
	15,13,18,15,13,15,
	13,0,13,15,10,11,10,6,0,6,10,13,
	
	15,13,18,15,13,15,
	13,0,13,10,13,14,0,14,0,14,17,22,
	
	10,8,13,11,10,11,10,
	10,8,13,11,10,11,6,
	
	6,0,6,8,10,5,
	5,0,3,0,3,10,13,12,3,0,3,10,13,12,1,3
};
const int megaTimes[] = {
	// A
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter SIXTS,STAC,mquarter SIXT,mquarter EIGHS,STAC,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,
	
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUAR,
	
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter DOTQ,
	mquarter QUARS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUAR,mquarter EIGH,mquarter EIGH,
	
	// B
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter SIXTS,STAC,mquarter SIXT,mquarter EIGHS,STAC,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,
	
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUAR,
	
	mquarter EIGH,mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGHS,STAC,
	mquarter SIXTS,STAC,mquarter SIXTS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter DOTQ,
	mquarter QUARS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUAR,mquarter EIGH,mquarter EIGH,
	
	// C
	mquarter DOTH,mquarter EIGH,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter DOTQ,
	mquarter HALFS,STAC,mquarter EIGH,mquarter DOTQ,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUARS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	
	mquarter DOTH,mquarter EIGH,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter DOTQ,
	mquarter HALFS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUARS,STAC,mquarter EIGHS,STAC,mquarter EIGH,mquarter EIGH,mquarter HALF,
	
	mquarter DOTH,mquarter EIGH,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter EIGH,
	mquarter DOTH,mquarter EIGH,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter QUAR,mquarter EIGH,
	
	mquarter HALFS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter EIGH,
	mquarter DOTH,mquarter EIGH,mquarter QUARS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter DOTQ,mquarter QUARS,STAC,mquarter EIGH,mquarter EIGH,mquarter EIGH,mquarter QUAR,mquarter EIGH,mquarter EIGH
};
	
const char guileNotes[] = {
	// high register
	16,0,16,15,0,15,16,16,15,
	16,0,16,15,0,15,16,16,15,
	16,15,16,0,15,18,0,18,16,15,11,
	
	16,0,16,15,0,15,16,16,15,
	16,0,16,15,0,15,16,16,15,
	16,15,16,0,15,18,0,18,16,15,11,
	
	// low register
	1,1,3,4,6,
	8,0,8,6,11,9,8,9,
	3,4,6,0,22,3,6,
	9,11,8,0,8,6,3,
	
	1,1,3,4,6,
	8,0,8,9,6,0,6,8,9,
	11,11,13,15,16,
	20,18,15,11,
	
	13,13,15,16,18,
	13,13,15,16,18,
	20,0,0,0,0,13,0,13,
	
	21,21,20,18,20,
	18,16,15,11,
	13,8,0,0,0,11,0,11,
	
	//13,13,15,
};
const int guileTimes[] = {
	// higher register
	gquarter EIGHS,STAC,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter DOTQ,gquarter EIGH,
	gquarter EIGHS,STAC,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter DOTQ,gquarter EIGH,
	gquarter SIXT,gquarter EIGH,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter EIGH,gquarter EIGH,
	
	gquarter EIGHS,STAC,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter DOTQ,gquarter EIGH,
	gquarter EIGHS,STAC,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter DOTQ,gquarter EIGH,
	gquarter SIXT,gquarter EIGH,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter SIXT,gquarter SIXT,gquarter SIXT,gquarter EIGH,gquarter EIGH,gquarter EIGH,
	
	// lower register
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	gquarter DOTES,STAC,gquarter SIXT,gquarter EIGH,gquarter QUAR,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	gquarter DOTE,gquarter DOTE,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter EIGH,
	gquarter DOTE,gquarter DOTE,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	gquarter DOTES,STAC,gquarter SIXT,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter SIXT,gquarter DOTE,
	gquarter QUAR,gquarter QUAR,gquarter QUAR,gquarter QUAR,
	
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter EIGH,
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter EIGH,gquarter EIGH,
	gquarter HALF,gquarter QUAR,gquarter QUAR,gquarter HALF,gquarter QUAR,gquarter EIGHS,STAC,gquarter EIGH,
	
	gquarter HALF,gquarter EIGH,gquarter EIGH,gquarter DOTE,gquarter DOTE,
	gquarter QUAR,gquarter QUAR,gquarter QUAR,gquarter QUAR,
	gquarter QUAR,gquarter HALF,gquarter QUAR,gquarter QUAR,gquarter HALF, gquarter EIGHS,STAC,gquarter EIGH,
	
	
	
};


#endif
