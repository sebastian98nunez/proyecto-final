//MENU CON FUNCIONES
#include <allegro.h>
#include<Tipos.h>
#include <stdio.h>
#include<vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#define MAXFILAS 8 //eje y...
#define LIMITE 20
using namespace std;
int MAXCOLS=7; //eje x...
int p1=1000;
int p2=1000;
BITMAP *FONDO_LOGO;//fondos iniciales
BITMAP *FONDO2;
BITMAP *FONDO3;
BITMAP *HIGHSCORE;
BITMAP *INSTRUCCIONES;

BITMAP *FONDO_MENU;//IAMGENES MENU DE NUEVA PARTIDA
BITMAP *CLASICO1;
BITMAP *CONECTA3;
BITMAP *CONECTA5;
BITMAP *RFILA;
BITMAP *SALIR2;

BITMAP *buffer;
BITMAP *CURSOR;

BITMAP *casilla_vacia;//IMAGENES DE TABLERO.H
BITMAP *barra_vacia;
BITMAP *barra_flecha;
BITMAP *casilla_j1;
BITMAP *casilla_j2;
BITMAP *casilla_j3;
BITMAP *flecha;

BITMAP *jugadores_j1;
BITMAP *jugadores_j2;

SAMPLE *FONDO;//reconocedor de sonidos WAV PARA TABLERO.H
SAMPLE *CAIDA;

//////////////////////////////////////FUNCIONES TABLERO.H
//DEFINIR VARIABLES GLOBALES
int px=0;//para mover la flechita en horizontal
int py=0;//para mover la ficha en la columna
int jugador=1;
bool connect5_val=FALSE;
bool pop=FALSE;

//VARIABLES GLOBALES USADAS EN PUNTUACION
BITMAP* letras_bmp;
BITMAP* letra_buff;
BITMAP* NEGRO;
int x=130;
int y=100;            // Coordenadas desde donde se empecasara a imprimir el menu
int xc=0;          // Componentes del cursor
int yc=0;
char nombre[LIMITE];  // Para guardar el nombre
int cord_x;           // Para controlar desde que punto se tomara la imagen de las letras para imprimir solo la parte deseada
int j=0;                // control para el indice de las matrices
bool VAL=false;

void menu_juegos();
void menu_inicio();
void tablero_();
void puntuaciones();


TableroPop mapa;
Memento copia(mapa.map);
//TableroPop mapa;

void dibujar_buffer(){
    int row, col;
    for(row=0;row<MAXFILAS-1;row++){
        for(col=0;col<MAXCOLS;col++){
            if (mapa.map[row][col]==8){
                draw_sprite(buffer,barra_vacia,col*50,row*50);
            }
            else if (mapa.map[row][col]==0){
                draw_sprite(buffer,casilla_vacia,col*50,row*50);
            }
            else if (mapa.map[row][col]==1){
                draw_sprite(buffer,casilla_j1,col*50,row*50);
            }
            else if (mapa.map[row][col]==2){
                draw_sprite(buffer,casilla_j2,col*50,row*50);
            }
            else if (mapa.map[row][col]==3){
                draw_sprite(buffer,casilla_j3,col*50,row*50);
            }
        }
    }
    if(!connect5_val){
        if(mapa.getPlayer()==1)
            draw_sprite(buffer,jugadores_j1,350,0);
        else
            draw_sprite(buffer,jugadores_j2,350,0);
    }

}

void pantalla(){//dibujar el buffer(pantalla) en la pantalla
    blit(buffer, screen, 0,0,0,0,440,360);
}

void dibujar_flecha(){//movimiento de la flechita
    blit(barra_flecha,flecha,0,0,0,0,50,50);
    draw_sprite(buffer,flecha,px*50,0);
}

void flechita(){//empieze a correr la flecha
    clear(buffer);
    dibujar_buffer();
    dibujar_flecha();
    pantalla();
    rest(70);
}

void dibujar_esfera(){//cambie de color la esfera que entre segun jugador
    if(mapa.getPlayer()==1){
        draw_sprite(buffer,casilla_j1,px*50,py*50);
        p1-=50;
    }
    else{
        draw_sprite(buffer,casilla_j2,px*50,py*50);
        p2-=50;
    }
}

void fichita(){//empieze a mover la ficha continuamente
    py=0;
    while(py!=mapa.searchFila(px)&&!key[KEY_ESC]){
        py+=1;
        clear(buffer);
        dibujar_buffer();
        dibujar_flecha();
        dibujar_esfera();
        pantalla();
        rest(150);
    }
}

void caer(){
    dibujar_buffer();
    dibujar_flecha();
    draw_sprite(buffer,casilla_vacia,px*50,300);
    pantalla();
    for(int row=5;row>mapa.searchFila(px);row--){
        if (mapa.map[row][px]==1){
            draw_sprite(buffer,casilla_j1,px*50,row*50+50);
            draw_sprite(buffer,casilla_vacia,px*50,row*50);
        }
        else if (mapa.map[row][px]==2){
            draw_sprite(buffer,casilla_j2,px*50,row*50+50);
            draw_sprite(buffer,casilla_vacia,px*50,row*50);
        }
        pantalla();
        rest(300);
    }
}

void tablero_(){
    buffer= create_bitmap(440,360);
    casilla_vacia= load_bitmap("casilla_vacia.bmp",NULL);
    barra_vacia= load_bitmap("barra_vacia.bmp",NULL);
    barra_flecha= load_bitmap("barra_flecha.bmp",NULL);
    flecha = create_bitmap(50,50);
    casilla_j1=load_bitmap("casilla_j1.bmp",NULL);
    casilla_j2=load_bitmap("casilla_j2.bmp",NULL);
    casilla_j3=load_bitmap("casilla_j3.bmp",NULL);
    jugadores_j1=load_bitmap("jugadores_j1.bmp",NULL);
    jugadores_j2=load_bitmap("jugadores_j2.bmp",NULL);
    CAIDA=load_wav("caida.wav");

    dibujar_buffer();
    pantalla();
    flechita();
        while(!key[KEY_ESC]&&!mapa.win())
    {
        if(!mapa.space()){
            if(key[KEY_RIGHT]||key[KEY_UP]){
                if(px>=MAXCOLS-1){
                    px=0;
                }
                else px+=1;
                flechita();
            }
            else if(key[KEY_LEFT]||key[KEY_DOWN]){
                if(px<0){
                    px=MAXCOLS-1;
                }
                else px-=1;
                flechita();
            }
            else if(key[KEY_SPACE]&&!mapa.columnFull(px)){
                play_sample(CAIDA,250,150,1000,0);
                fichita();
                mapa.addFicha(px);
                if(mapa.win()){
                    /*const char *a="Gano el jugador " + (char)mapa.getPlayer();*/
                    dibujar_buffer();
                    pantalla();
                    rest(1000);
                    textout_centre_ex(screen, font,"GANO EL JUGADOR: ", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), 100);
                    rest(3000);
                    puntuaciones();
                while(TRUE){
                        if(key[KEY_C]){
                            return;
                        }
                    }
                }
                else mapa.changePlayer();
                if(mapa.win()){
                    dibujar_buffer();
                    pantalla();
                    rest(1000);
                    textout_centre_ex(screen, font,"GANO EL JUGADOR: ", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), 100);
                    rest(3000);
                    puntuaciones();
                while(TRUE){
                        if(key[KEY_C]){
                            return;
                        }
                    }

                }
            }
            else if(pop){
                if(key[KEY_A]&&!mapa.emptyColumn(px)){
                    caer();
                    mapa.bump(px);
                    if(mapa.win()){
                        dibujar_buffer();
                        pantalla();
                        rest(1000);
                    textout_centre_ex(screen, font,"GANO EL JUGADOR: ", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), 100);
                    rest(3000);
                    puntuaciones();
                    while(TRUE){
                            if(key[KEY_C]){
                                return;
                            }
                        }
                    }
                    else mapa.changePlayer();
                    if(mapa.win()){
                        dibujar_buffer();
                        pantalla();
                        rest(400);
                        textout_centre_ex(screen, font,"HICISTE GANAR A TU OPONENTE :V ", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), 100);
                        textout_centre_ex(screen, font,"PRESIONE 'C' PARA REGRESAR AL MENU", SCREEN_W/2, SCREEN_H/2+100, makecol(255, 255, 255), 100);
                        while(TRUE){
                            if(key[KEY_C]){
                                return;
                            }
                        }

                    }
                }
            }
        }
        else{
            textout_centre_ex(screen, font,"EMPATE ", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255), 100);
            textout_centre_ex(screen, font,"PRESIONE 'C' PARA REGRESAR AL MENU", SCREEN_W/2, SCREEN_H/2+100, makecol(255, 255, 255), 100);
            while(TRUE){
                if(key[KEY_C]){
                    return;
                }
            }

        }
    }
}

//FIN DE FUNCIONES TABLERO.H
//////////////////////////////


/////////////////////////////////PUNTUACIONES
fstream archivo;
static bool val=true;
//Sobrecarga del operador + para sumar enteros y strings
string operator+(int number, string cadena)
{
    ostringstream ostr;
	ostr << number;
	string theNumberString = ostr.str();
	return theNumberString + cadena;
}

//Comparar puntuaciones
void CompPunt(string nombr, int punt){
    archivo.open("score.txt",ios::in);
    string cadena1,cadena2,cadena3,cadena4;
    cadena4=punt+nombr;
    if (archivo.is_open()){
    getline(archivo,cadena1);
    getline(archivo,cadena2);
    getline(archivo,cadena3);
    archivo.close();
    }

    if(cadena4<cadena3)
        return;

    if(cadena1<cadena2)
    swap(cadena1,cadena2);
    if(cadena1<cadena4)
    swap(cadena1,cadena4);
    if(cadena2<cadena4)
    swap(cadena2,cadena4);

    archivo.open("score.txt",ios::out);
    if (archivo.is_open()){
        archivo<<cadena1<<"\n"<<cadena2<<"\n"<<cadena4<<"\n";
        archivo.close();
    }

}

void imprimir_pantalla(){
     blit(buffer, screen , 0,0,0,0,440,360);
}

void PINTAR_ABC(){

   int letra = 0;
   for(int i = 0 ; i< 5 ; i++){
       for(int j = 0 ; j< 6 ; j++){
             blit(letras_bmp,letra_buff,letra*27,0,0,0,27,24);
             draw_sprite(buffer,letra_buff,x+j*27,y+24*i);
             letra++;
        }
    }
}
void CURSOR_(){
     rectfill(buffer,(xc*27)+x,(yc*24)+124,(xc*27)+157,(yc*24)+120,0x000000); // se borra el cursor

     if(xc<5){if(key[KEY_RIGHT]) xc ++; }// DERECHA
     if(xc>0){if(key[KEY_LEFT]) xc --; } // IZQUIERDA
     if(yc>0){if(key[KEY_UP]) yc --;}
     if(yc<4){if(key[KEY_DOWN]) yc ++;}

     rectfill(buffer,(xc*27)+x,(yc*24)+124,(xc*27)+157,(yc*24)+120,0x999999); // se pinta el cursor
     cord_x = 6*yc + xc; // se guarda el numero que multiplicado  27 nos da la corrdenada x de la letra que se seleciono
                         // de la imagen

     if(key[KEY_SPACE] && j<6){

           blit(letras_bmp,letra_buff,cord_x*27,0,0,0,27,24); // hacemos h*27 para tomar la letra selecionada por el cursor
           draw_sprite(buffer,letra_buff,j*27+130,300);
           nombre[j] = 'A' + cord_x; // se guarda el nombre (con esto se puede hacer un registro para guardar los datos)
           j++;
     }


      if(j == 6 || key[KEY_ENTER] ){
        string str(nombre);
        if(mapa.getPlayer()==1)
            CompPunt(nombre,p1);
        else
            CompPunt(nombre,p2);
        clear_bitmap(buffer);
        val=false;
    }
}

void MostrarPuntuaciones(){
    archivo.open("score.txt",ios::in);
    char cadena1[LIMITE],cadena2[LIMITE],cadena3[LIMITE];
    while(!archivo.eof()){
    archivo>>cadena1>>cadena2>>cadena3;
    }
    archivo.close();
    blit(NEGRO, buffer, 0,0,0,0,440,360);
    pantalla();
    while(!key[KEY_C]&&!key[KEY_ESC]){

        textout(screen,font,"Puntuaciones Altas:",10,20,makecol(255,0,0));
        textout(screen,font,"1:",10,45,makecol(255,0,0));
        textout(screen,font, cadena1,40,45,makecol(255,0,0));
        textout(screen,font,"2:",10,75,makecol(255,0,0));
        textout(screen,font, cadena2,40,75,makecol(255,0,0));
        textout(screen,font,"3:",10,105,makecol(255,0,0));
        textout(screen,font,cadena3,40,105,makecol(255,0,0));
        textout(screen,font,"PRESIONE C PARA REGRESAR AL MENU ANTERIOR",10,135,makecol(255,0,0));
    }
}

void puntuaciones(){//FUNCION QUE LLAMA A LAS DEMAS FUNCIONES DE PUNTUACIONES
    letras_bmp = load_bitmap("letras.bmp",NULL);
    letra_buff = create_bitmap(27,24);
    clear(buffer);
    while(!key[KEY_ESC] || val){
            PINTAR_ABC();
            CURSOR_();
            imprimir_pantalla();
            if (val)
                readkey();
            else
                break;
        }
        while(!key[KEY_C]){
            MostrarPuntuaciones();
        }
}

//////////////////////////////////////FIN DE PUNTUACIONES

//fondo menu de juegos
////////////////////////////
bool salir = false;

void menu_juegos(){//menu tipos de juegos
    if(key[KEY_ESC]){
        salir=true;
        return;
    }
    if(mouse_x>100 && mouse_x <271 && mouse_y>136 && mouse_y <166  ){//CLASICO
        blit(CLASICO1,buffer,0,0,0,0,440,360);
        if(mouse_b & 2){
            connect5_val=FALSE;
            MAXCOLS=7;
            pop=FALSE;
            copia.backup(mapa.map);
            tablero_();
        }
    }
    else if(mouse_x>100 && mouse_x <344 && mouse_y>173 && mouse_y <198     ){//TABLERO POP
        blit(RFILA,buffer,0,0,0,0,440,360);
        if(mouse_b & 2){
            connect5_val=FALSE;
            MAXCOLS=7;
            pop=TRUE;
            copia.backup(mapa.map);
            tablero_();
        }
    }
    else if(mouse_x>100 && mouse_x <304 && mouse_y>205 && mouse_y <230  ){//CONNECT 5
        blit(CONECTA5,buffer,0,0,0,0,440,360);
        if(mouse_b & 2){
            MAXCOLS=9;
            connect5_val=TRUE;
            pop=FALSE;
            copia.backup(mapa.map);
            tablero_();
        }
    }
    else if(mouse_x>100 && mouse_x <304 && mouse_y>238 && mouse_y <262  ){//CONNECT 3
        blit(CONECTA3,buffer,0,0,0,0,440,360);
        if(mouse_b & 2){
            connect5_val=FALSE;
            MAXCOLS=7;
            pop=false;
            copia.backup(mapa.map);
            tablero_();
        }
    }
    else if(mouse_x>103 && mouse_x <271 && mouse_y>270 && mouse_y <294  ) {//SALIR
        blit(SALIR2,buffer,0,0,0,0,440,360);
        if(mouse_b & 2){
            salir=true;
            return;
        }
    }
    else blit(FONDO_MENU,buffer,0,0,0,0,440,360);

    masked_blit(CURSOR,buffer,0,0,mouse_x,mouse_y,22,32);
    pantalla();
    menu_juegos();
}

void menu_inicio(){
    if(key[KEY_ESC]){
        salir=true;
        return;
    }
    if(mouse_x>96 && mouse_x <326 && mouse_y>143 && mouse_y <169  ){//NUEVO JUEGO
        blit(FONDO2,buffer,0,0,0,0,440,360);
        if(mouse_b & 1){
            menu_juegos();
            return;
        }
    }
    else if(mouse_x>96 && mouse_x <366 && mouse_y>178 && mouse_y <202  ){//INSTRUCCIONES
        blit(INSTRUCCIONES,buffer,0,0,0,0,440,360);
        if(mouse_b & 1){

        }
    }
    else if(mouse_x>96 && mouse_x <326 && mouse_y>211 && mouse_y <235  ){//HIGH SCORES
        blit(HIGHSCORE,buffer,0,0,0,0,440,360);
        if(mouse_b & 1){
            MostrarPuntuaciones();
        }
    }
    else if(mouse_x>93 && mouse_x <223 && mouse_y>242 && mouse_y <270  ){//SALIR
        blit(FONDO3,buffer,0,0,0,0,440,360);
        if(mouse_b & 1){
            salir=true;
            return;
        }
    }
    else blit(FONDO_LOGO,buffer,0,0,0,0,440,360);

    masked_blit(CURSOR,buffer,0,0,mouse_x,mouse_y,22,32);
    pantalla();
    menu_inicio();
}

int main(){
    allegro_init();
    install_keyboard();
    install_mouse();//instalar el raton
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 440,360, 0, 0);
    set_window_title("¡CONNECT 4!");
    buffer=create_bitmap(440,360);
    //Instalamos el audio

    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
            allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error); return 1;
    }
    set_volume(70, 70);//volumen por cada lado del parlante

    FONDO_LOGO= load_bitmap("1fondo_logo.bmp",NULL);//fondos iniciales
    FONDO2= load_bitmap("1fondo2.bmp",NULL);
    FONDO3= load_bitmap("1fondo3.bmp",NULL);
    CURSOR= load_bitmap("0cursor.bmp",NULL);
    FONDO_MENU=load_bitmap("2fondo_menu.bmp",NULL);//fondo menu de juegos
    HIGHSCORE=load_bitmap("1highscore.bmp",NULL);
    INSTRUCCIONES=load_bitmap("1instrucciones.bmp",NULL);
    CLASICO1=load_bitmap("2clasico.bmp",NULL);
    CONECTA3=load_bitmap("2connect3.bmp",NULL);
    CONECTA5=load_bitmap("2connect5.bmp",NULL);
    RFILA=load_bitmap("2rowByrow.bmp",NULL);
    SALIR2=load_bitmap("2salir_menuinicio.bmp",NULL);
    NEGRO=load_bitmap("negro.bmp",NULL);
    FONDO=load_wav("fondo.wav");

    while(!salir){

        play_sample(FONDO,250,150,1000,0);
        menu_inicio();
    }

    destroy_bitmap(buffer);
}END_OF_MAIN()

