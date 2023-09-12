//
// MSX Murcia 2023
// @author:MSX spain
// 

/**************DECLARACIONES************/

#include "fusion-c/header/msx_fusion.h"
#include "fusion-c/header/vdp_graph1.h"
//#include "fusion-c/header/vdp_graph2.h"
#include "fusion-c/header/vdp_sprites.h"
#include "src/definitions.c"
#include "src/pieces.c"
#include "src/utils.c"
#include<stdio.h>
// Para el memcpy
#include <string.h>
//rand y srand http://cplusplus.com/reference/cstdlib/rand/
#include <stdlib.h>




void print_table(void);
void move_piece(char movement);
void convertir_piece_to_static(char piece_number);
void check_completed_lines(void);
char check_sueltos(void);
// Consiguración del VDP
void inicializar_sprites(void);
//Para ir poniendo los sprites de los players del 1 al 4
void copy_sprites_definition_to_VRAM(void);
void insert_piece_into_table(void);
void paint_stage(void);
void HUD();
void debug(char word1, char word2, char word3);
void print_message_with_pause(char message[]);
void menu(void);
void show_end_game(void);

//La tabla y los tamaños de la tabla está definidos en src/definitions.c

char piece_number=1;
int counter=0;
int old_counter=0;


char movement=0; 
char rotation=0;
int score=0;
int level=0;
char game_over=0;
char new_piece=0;
int time=0;
void main(void) 
{




  inicio:
  KeySound(0);
  SetColors(15,1,1);
  SetRealTimer(0);
  menu();
  Screen(2);
  inicializar_sprites();
  //Tileset
  unsigned int vram_adr_tiles_pat=Peekw(0x0);		
  unsigned int vram_adr_tiles_col=Peekw(0x2000);		
  CopyRamToVram(TILESET_pat,0,8*60);
  CopyRamToVram(TILESET_pat,2048,8*60);
  CopyRamToVram(TILESET_pat,4096,8*60);
  CopyRamToVram(TILESET_col,8192,8*60);
  CopyRamToVram(TILESET_col,10240,8*60);
  CopyRamToVram(TILESET_col,12288,8*60);
  //ponemos la tabla de nombres todo a 255
  FillVram(6144,255,768);
  /********Final menú bienvenida*********/

  paint_stage();
  print_table();
  insert_piece_into_table();
  print_message_with_pause("Press any key to start");
  KillKeyBuffer();
  game_over=0;
  old_counter=0;
  level=0;
  while (game_over==0)
  {
    movement=procesar_entrada_joyStick();
    time=RealTimer();
    counter=time/60;
    if ((counter-old_counter)>0.20){
      move_piece(DOWN);
      HUD();
      old_counter=counter;
    }
    if(movement!=0){
      move_piece(movement);   
    }
    //check_lines();
  }
  goto inicio;
}










void move_piece(char movement){

  signed char new_row_index=0;
  signed char new_column_index=0;
  //Rotation es una variable global y determina la rotación de la pieza que hay en uso
  if (movement==ROTATE){
    if (rotation==3){
      rotation=0;
    }else{
     rotation++;
    } 
  }

  char rotation_item=0;
  signed char indezex[4][2];
  signed int new_indezex[4][2];
  char item=0;
  char toca_abajo=0;
  char permitido=1;
  //Recorremos todo el tablero en busca de los 4 itms de la pieza
  for(signed int f=0;f<NUMERO_FILAS;f++){
    for(signed int c=0;c<NUMERO_COLUMNAS;c++){
      if(table[f][c]==piece_number){
        if (movement==UP){
          //new_row_index=f-1;
          //new_column_index=c;
        }else if(movement==RIGHT){
          new_row_index=f;
          new_column_index=c+1;
        }else if(movement==DOWN){
          new_row_index=f+1;
          new_column_index=c;
        }else if(movement==LEFT){
          new_row_index=f;
          new_column_index=c-1;
        }else if(movement==ROTATE){
          switch (piece_number)
          {
            //Si es la L
            case 1:
                new_row_index=f+lRotations[rotation][rotation_item][0];
                new_column_index=c+lRotations[rotation][rotation_item][1];
              break;
            //Si es la J
            case 2:
                new_row_index=f+jRotations[rotation][rotation_item][0];
                new_column_index=c+jRotations[rotation][rotation_item][1];
                break;
            //Si es la Z
            case 3:
                new_row_index=f+zRotations[rotation][rotation_item][0];
                new_column_index=c+zRotations[rotation][rotation_item][1];
                break;
            //Si es la S
            case 4:
                new_row_index=f+sRotations[rotation][rotation_item][0];
                new_column_index=c+sRotations[rotation][rotation_item][1];
                break;
            //Si es la T
            case 5:
                new_row_index=f+tRotations[rotation][rotation_item][0];
                new_column_index=c+tRotations[rotation][rotation_item][1];
                break;
            //Si es la O
            case 6:
                new_row_index=f+oRotations[rotation][rotation_item][0];
                new_column_index=c+oRotations[rotation][rotation_item][1];
                break;
            //Si es la I
            case 7:
                new_row_index=f+iRotations[rotation][rotation_item][0];
                new_column_index=c+iRotations[rotation][rotation_item][1];
                break;
          }
          if( new_row_index>=NUMERO_FILAS || new_column_index<0 || new_column_index>=NUMERO_COLUMNAS){
            rotation--;
            //Beep();
            return;
          }
          rotation_item+=1;
        }

        
        /*
        if(new_row_index<6 && new_piece==0){
          //game_over=1;
        }else if(new_row_index>5 && new_row_index<10 && new_piece==1){
          new_piece=0;
        }
        debug(new_row_index,new_piece,game_over);
        */
        
        
        char letter_down=table[f+1][c];
        /*char letter_left=table[f][c-1];
        char letter_right=table[f][c+1];
        if(letter_left!=0 || letter_right!=0)
        {
          //Beep();
          permitido=0;
        }*/

 
        //if(is_static_piece(letter_down) && !is_static_piece(letter_left) && !is_static_piece(letter_right)){
        //Si la pieza de abajo es una estática o Si es la última fila la convertimos en estática salimos, ponemos rotation 0 ya que es global 
        if(is_static_piece(letter_down) || new_row_index>=NUMERO_FILAS){
           Beep();

          if(new_row_index<6) {
            game_over=1;
            show_end_game();
            KillKeyBuffer();
            print_message_with_pause("Game over");
            memcpy(table,table_empty,sizeof(table));
          }else{
            rotation=0;
            convertir_piece_to_static(piece_number); 
            //Kitamos todas las líneas compleatadas
            check_completed_lines();
            //Miramos i hay alguna pieza suelta
            //while(check_sueltos()==1){
              //Beep();
              //move_piece(DOWN);
              //check_completed_lines();
            //}           
            insert_piece_into_table();

          }
 

          return;
        }

 

        
        //if(new_row_index<1 || new_row_index>=NUMERO_FILAS-1 || new_column_index<1 || new_column_index>=NUMERO_COLUMNAS-1){
        if(new_column_index<0 || new_column_index>=NUMERO_COLUMNAS){
          return;
        }else{
          
          indezex[item][0]=f;
          indezex[item][1]=c;
          new_indezex[item][0]=new_row_index;
          new_indezex[item][1]=new_column_index;
          item++;
        }

      }//Fin del if=X
    }//Fin del for c
  }//Fin del for f

 


  //Ponemos un 0 o la letra según lo hayamos almacenado en los 2 arrays
  for(char i=0;i<4;i++){
    table[indezex[i][0]][indezex[i][1]]=0;
  }
  for(char i=0;i<4;i++){
    table[new_indezex[i][0]][new_indezex[i][1]]=piece_number;
  }
  print_table();
}



void HUD(){
  /*char size_score=lenHelper(score);
  for(char i=0;i<size_score;i++){
    char value_score=score%10;
    Vpoke(6390+i,24+value_score);
  }*/
  Vpoke(6390,25+score);
  //Imprimimos la letra
  Vpoke(6486,25+piece_number);
  //imprimimos el tiempo
  Vpoke(6582,25+level);
}

void debug(char word1, char word2, char word3){
  //for (char i=0;i<sizeof(word1);i++)
  /*char size_word1=lenHelper(word1);
  for(char i=0;i<size_word1;i++){
    char value_word1=word1%10;
    Vpoke(6390+i,24+value_word1);
  }*/
  Vpoke(6422,24+word1);
  Vpoke(6518,24+word2);
  Vpoke(6614,24+word3);
}



void insert_piece_into_table(void){
  //Obtenemos la letra que vamos a soltar
  char rand_piece=rand()%(8-1)+1;
  piece_number=rand_piece;
  
  switch (rand_piece)
  {
    //char array_numbre_pieces[]={'L','J','Z','S','O','T','I'};
    //Si es la L
    case 1:
        memcpy(table,lPiece,sizeof(lPiece));
        //Pieza L color naranja 
        PutSprite(piece_number,0,140,140,9);
        break;
    //Si es la J
    case 2:
      //Pieza J color azul  
        memcpy(table,jPiece,sizeof(jPiece));
        PutSprite(piece_number,0,140,140,7);
        break;
    //Si es la Z
    case 3:
        //Pieza Z color rojo
        memcpy(table,zPiece,sizeof(zPiece));
        PutSprite(piece_number,0,140,140,6);
        break;
    //Si es la S
    case 4:
        //Pieza S color verde
        memcpy(table,sPiece,sizeof(sPiece));
        PutSprite(piece_number,0,140,140,2);
        break;
    //Si es la O
    case 5:
        //Pieza T color Morado  
        memcpy(table,tPiece,sizeof(oPiece));
        PutSprite(piece_number,0,140,140,13);
        break;
    //Si es la T
    case 6:
        //Pieza O color amarillo
        memcpy(table,oPiece,sizeof(tPiece));
        PutSprite(piece_number,0,140,140,11);
        break;
    //Si es la I
    case 7:
        //Pieza I color Cyan
        memcpy(table,iPiece,sizeof(iPiece));
        PutSprite(piece_number,0,140,140,5);
        break;
  }
  print_table();
  //HUD();
}



void convertir_piece_to_static(char piece_number){
  for(signed int f=0;f<NUMERO_FILAS;f++){
    for(signed int c=0;c<NUMERO_COLUMNAS;c++){
      if(table[f][c]==piece_number){
        table[f][c]=piece_number+7;
      }
    }
  }
  print_table();
}


void check_completed_lines(void){
  //char completed_line=0;
  char lines_completes[NUMERO_FILAS]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char clean_lines_completed=0;
  //Recorremos todas las líneas y columnas cada vez que toca con el suelo o con una pieza
  // y vamos comprobando si se ha hecho una línea completa
  for(signed int f=0;f<NUMERO_FILAS;f++){
    if(table[f][0]>7 && table[f][1]>7 && table[f][2]>7 && table[f][3]>7 && table[f][4]>7 && table[f][5]>7 && table[f][6]>7 && table[f][7]>7 && table[f][8]>7 && table[f][9]>7){
      lines_completes[clean_lines_completed]=f;
      score+=1;
      //HUD();
      clean_lines_completed++;
    }
  }
  
  //Se borra la lineas que hemos encintrado y hemos ido almacenando en un array
  for(char i=0;i<clean_lines_completed;i++){
    char fila_completada=lines_completes[i];
    for(char c=0;c<NUMERO_COLUMNAS;c++){
        table[fila_completada][c]=0;
        //table[fila_completada][c]=table[fila_completada-1][c];  
        //Movemos todas las filas hacia abajo
        for (char w = 0; w < NUMERO_FILAS/2; w++)
        {
          table[fila_completada-w][c]=table[fila_completada-(w+1)][c];  
        }
    }
  }
}



char check_sueltos(){
  char suelto=0;
  for(signed int f=0;f<NUMERO_FILAS;f++){
    for(signed int c=0;c<NUMERO_COLUMNAS;c++){
      char piece=table[f][c];
      char piece_down=table[f+1][c];
      if(piece>7 && piece_down==0){
        //table[f][c]=table[f][c]-7;
        //table[f][c]=table[f][c]-7;
        //Beep();
        suelto=1;
      }
    }
  }
  return suelto;
}














void print_table(void){
  int direction=6210;
  //6144+32(1 fila)+32(2 fila)+2(margen izquierdo)
  for(int f=0;f<NUMERO_FILAS;f++){
    for(int c=0;c<NUMERO_COLUMNAS;c++){  
      char piece=table[f][c];
      if(f<8) Vpoke(direction+c,piece);
      else if(f>=8 && f<16) Vpoke(direction+c,piece);
      else if(f>=16 && f<24) Vpoke(direction+c,piece);
    }
    direction+=32;
  }
}
void paint_stage(void){
  int direction=6144;
  for (char f=0; f<22;f++){
      for (char c=0; c<32;c++){
        if(f<8) Vpoke(direction+c,scene[f][c]-1);
        else if(f>=8 && f<16) Vpoke(direction+c,scene[f][c]-1);
        else if(f>=16 && f<24) Vpoke(direction+c,scene[f][c]-1);
      }
      direction+=32;
  }
}

void print_message_with_pause(char *message ){
    int i=0;
    while(message[i]!='\0'){
      char value=get_letter(message[i]);
      Vpoke(6848+i,value);
      i++;
    }
    WaitKey();
    for (char i=0;i<32;i++) Vpoke(6848+i,15);
}

void show_end_game(void){
  int direction=6210;
  //6144+32(1 fila)+32(2 fila)+2(margen izquierdo)
  for(int f=0;f<NUMERO_FILAS;f++){
    for(int c=0;c<NUMERO_COLUMNAS;c++){  
      if(table[f][c]>7 && table[f][c]<15){
        table[f][c]=16;
      }

    }
    direction+=32;
  }
  print_table();
}

void menu(void){
  Screen(1);
    /**********Menú de bienvenida *********/
  Locate(9,5);
  Print("Titris");
  Locate(7,7);
  Print("by MSX spain");
  Locate(0,12);
  Print("Type the number of players");
  Locate(6,14);
  Print("1 to 2 players");
  Locate(7,15);
  for(char i=11;i<14;i++){
    Locate(i,17);
    //printf("%c",255);
    PrintChar(255);
  }
  Locate(12,18);
  WaitKey();
  Cls();

}



void inicializar_sprites(){
  //Ponemos a 0 todos los sprites
  SpriteReset(); 
  // tamaño de sprites 16x16
  Sprite16(); 
  // tamaño de sprites sin ampliar   
  SpriteSmall(); 
  SetSpritePattern(0,sprite_piece_l,32);
  SetSpritePattern(1*4,sprite_piece_j,32);
  SetSpritePattern(2*4,sprite_piece_z,32);
  SetSpritePattern(3*4,sprite_piece_s,32);
  SetSpritePattern(4*4,sprite_piece_o,32);
  SetSpritePattern(5*4,sprite_piece_t,32);
  SetSpritePattern(6*4,sprite_piece_i,32);

}














