#include "Tone.h"

#define Parlante_Izquierdo 13
#define Parlante_Derecho 12

#define SOL_d2 104
#define LA2    110
#define LA_d2  114
#define SI2    124
#define DO3    131
#define DO_d3  139
#define RE3    147
#define RE_d3  156
#define MI3    165
#define FA3    175
#define FA_d3  185
#define SOL3   196
#define SOL_d3 208
#define LA3    220
#define LA_d3  233
#define SI3    247
#define DO4    262
#define DO_d4  277
#define RE4    294
#define RE_d4  311
#define MI4    330
#define FA4    349
#define FA_d4  370
#define SOL4   392
#define SOL_d4 415
#define LA4    440
#define LA_d4  466
#define SI4    494
#define DO5    523
#define DO_d5  554
#define RE5    587
#define RE_d5  622
#define MI5    659
#define FA5    698
#define FA_d5  740
#define SOL5   784
#define SOL_d5 831
#define LA5    880
#define LA_d5  932
#define SI5    988
#define DO6    1046
#define DO_d6  1109
#define RE6    1175
#define RE_d6  1245
#define MI6    1319
#define FA6    1397
#define FA_d6  1480
#define SOL6   1568
#define SOL_d6 1661
#define LA6   1760
#define LA_d6  1865

int tempo = 150;
int redonda = 240000 / tempo;
int blancapto = 180000 / tempo;
int blanca = 120000 / tempo;
int negrapto = 90000 / tempo;
int negra = 60000 / tempo;
int corcheapto = 45000 / tempo;
int corchea = 30000 / tempo;
int semicopto = 22500 / tempo;
int semico = 15000 / tempo;

Tone izquierda;
Tone derecha;

void setup(){
  izquierda.begin(Parlante_Izquierdo);
  derecha.begin(Parlante_Derecho);
}

void loop(){
  titanic1();
  titanic2();
  titanic1();
  titanic3();
  titanic1();
  titanic2();
  titanic1();
  titanic3();
  titanic4();
  titanic6();
  titanic4();
  titanic5();
}

void suenanDos(int nota1, int nota2, int tiempo){
  int retardo = tiempo - 4;
  izquierda.play(nota1, tiempo);
  derecha.play(nota2, tiempo);
  delay(retardo);
  delay(5);
}

void suenaUno(int nota1, int tiempo){
  int retardo = tiempo - 4;
  izquierda.play(nota1, tiempo);
  delay(retardo);
  delay(5);
}

void silencio(int tiempo){
  int retardo = tiempo - 4;
  delay(retardo);
}
  
void titanic1(){
  suenanDos(MI5,MI4,negrapto);
  suenanDos(SI3,MI4,corchea);
  suenanDos(MI5,MI4,negra);
  suenanDos(MI5,MI4,negra);
  suenanDos(SI3,RE_d5,negra);
  suenanDos(SI3,MI5,corchea);
  suenanDos(FA_d3,MI5,corchea);
  suenanDos(SI3,MI5,negra);
  suenanDos(SI3,MI5,negra);

}
void titanic2(){
  suenanDos(LA3,RE_d5,negra);
  suenanDos(LA3,MI5,corchea);
  suenanDos(MI3,MI5,corchea);
  suenanDos(LA3,MI5,negra);
  suenanDos(LA3,FA_d5,negra);
  suenanDos(SI3,SOL_d5,blanca);
  suenanDos(FA_d3,FA_d5,blanca);  
}

void titanic3(){
  suenanDos(LA3,SI4,negrapto);
  suenanDos(MI3,SI4,corchea);
  suenanDos(LA3,SI4,negrapto);
  suenanDos(MI3,SI4,corchea);
  suenanDos(LA3,SI4,negrapto);
  suenanDos(MI3,SI4,corchea);
  suenanDos(SI3,DO_d5,corchea);
  suenanDos(LA3,SI4,corchea);  
  suenanDos(SOL_d3,DO_d5,corchea);  
  suenanDos(FA_d3,RE_d5,corchea);  
}

void titanic4(){
  suenanDos(DO_d4,MI5,negrapto);
  suenanDos(SOL_d3,MI5,corchea);
  suenanDos(DO_d4,MI5,blanca);
  suenanDos(SI3,FA_d5,negrapto);
  suenanDos(FA_d3,FA_d5,corchea);
  suenanDos(SI3,FA_d5,negra);
  suenanDos(SI3,SI4,negra);
  suenanDos(LA3,SI5,negrapto);
  suenanDos(MI3,SI5,corchea);
  suenanDos(LA3,LA5,negra);
  suenanDos(SOL_d3,SOL_d5,negra);
  suenanDos(SI3,FA_d5,negrapto);
  suenanDos(FA_d3,FA_d5,corchea);
  suenanDos(SI3,SOL_d5,negra);
  suenanDos(FA_d3,LA5,negra);
  suenanDos(DO_d4,SOL_d5,negrapto);
  suenanDos(SOL_d3,SOL_d5,corchea);
  suenanDos(DO_d4,FA_d5,negra);
  suenanDos(SOL_d3,MI5,negra);
  suenanDos(SI3,RE_d5,negra);
  suenanDos(SI3,MI5,corchea);
  suenanDos(FA_d3,MI5,corchea);
  suenanDos(SI3,MI5,negra);
}

void titanic5(){
  suenanDos(FA_d3,MI5,negra);
  suenanDos(LA3,RE_d5,negra);
  suenanDos(LA3,MI5,corchea);
  suenanDos(MI3,MI5,corchea);
  suenanDos(LA3,MI5,negra);
  suenanDos(LA3,FA_d5,negra);
  suenanDos(SI3,SOL_d5,blanca);
  suenanDos(FA_d3,FA_d5,blanca);
}  

void titanic6(){
  suenanDos(FA_d3,RE_d5,negra);
  suenanDos(LA3,DO_d5,negrapto);
  suenanDos(MI3,DO_d5,corchea);
  suenanDos(LA3,DO_d5,negrapto);
  suenanDos(MI3,DO_d5,corchea);
  suenanDos(LA3,DO_d5,negrapto);
  suenanDos(MI3,DO_d5,corchea);
  suenanDos(SI3,DO_d5,corchea);
  suenanDos(LA3,SI4,corchea);  
  suenanDos(SOL_d3,DO_d5,corchea);  
  suenanDos(FA_d3,RE_d5,corchea);  
}
