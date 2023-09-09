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
void check_lines(void);
char esta_suelto(char fila, char columna);

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

  //inicializar_sprites();
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
    check_lines();
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
        if(is_static_piece(letter_down) || new_row_index==NUMERO_FILAS){
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
            insert_piece_into_table();
          }
 

          return;
        }

 

        
        //if(new_row_index<1 || new_row_index>=NUMERO_FILAS-1 || new_column_index<1 || new_column_index>=NUMERO_COLUMNAS-1){
        if(new_row_index<0 || new_row_index>=NUMERO_FILAS || new_column_index<0 || new_column_index>=NUMERO_COLUMNAS){
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
  char rand_piece=rand()%sizeof(array_number_pieces);
  //char piece_letter=get_piece_Letter(rand_piece);
  //TPiece *piece=create_piece(piece_letter);
  //piece_number=piece->number;
  //switch (piece->number)
  piece_number=rand_piece;
  switch (rand_piece)
  {
    //char array_numbre_pieces[]={'L','J','Z','S','O','T','I'};
    //Si es la L
    case 1:
        memcpy(table,lPiece,sizeof(lPiece));
        break;
    //Si es la J
    case 2:
        memcpy(table,jPiece,sizeof(jPiece));
        break;
    //Si es la Z
    case 3:
        memcpy(table,zPiece,sizeof(zPiece));
        break;
    //Si es la S
    case 4:
        memcpy(table,sPiece,sizeof(sPiece));
        break;
    //Si es la O
    case 5:
        memcpy(table,tPiece,sizeof(oPiece));
        break;
    //Si es la T
    case 6:
        memcpy(table,oPiece,sizeof(tPiece));
        break;
    //Si es la I
    case 7:
        memcpy(table,iPiece,sizeof(iPiece));
        break;
  }
  print_table();
  HUD();
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


void check_lines(void){
  //char completed_line=0;
  char lines_completes[NUMERO_FILAS]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char clean_lines_completed=0;
  char number_line=0;
  char check_sueltos=0;
  char item=0;
  for(signed int f=0;f<NUMERO_FILAS;f++){
        char item0=table[f][0];
        char item1=table[f][1];
        char item2=table[f][2];
        char item3=table[f][3];
        char item4=table[f][4];
        char item5=table[f][5];
        char item6=table[f][6];
        char item7=table[f][7];
        char item8=table[f][8];
        char item9=table[f][9];
        if(item0>7 && item1>7 && item2>7 && item3>7 && item4>7 && item5>7 && item6>7 && item7>7 && item8>7 && item9>7){
          lines_completes[clean_lines_completed]=f;
          score+=1;
          HUD();
          clean_lines_completed++;
          check_sueltos=1;
        }
  }
  //HUD( clean_lines_completed,number_line,0);
  //Se borra la linea
  for(char i=0;i<clean_lines_completed;i++){
    for(signed int f=0;f<NUMERO_FILAS;f++){
      for(signed int c=0;c<NUMERO_COLUMNAS;c++){
        if (f==lines_completes[i])
        {
          table[f][c]=0;
          Beep();
        }
      }
    }
  }
  
  if(check_sueltos){
      for(signed int f=0;f<NUMERO_FILAS;f++){
        for(signed int c=0;c<NUMERO_COLUMNAS;c++){
          while (esta_suelto(f,c)==1)
          {
            if (table[f][c]>7)
            {
              table[f+1][c]=table[f][c];
              table[f][c]=0;
            }
          }
        }
      }
  }

  
}



char esta_suelto(char fila, char columna){
  char suelto=0;
  for(signed int f=0;f<NUMERO_FILAS;f++){
    for(signed int c=0;c<NUMERO_COLUMNAS;c++){
      if(f==fila && c==columna){
        char piece_number=table[f][c];
        char piece_down=table[f+1][c];
        if(piece_number>7 && piece_down==0){
          suelto= 1;
        }
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
















