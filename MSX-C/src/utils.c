#define RIGHT 3
#define LEFT 7
#define UP 1
#define DOWN 5
#define ROTATE 10
char get_piece_Letter(char piece_in_array);
char procesar_entrada_joyStick(void);
char procesar_entrada_teclado(char movement);
char is_piece(char piece_number);
char is_static_piece(char piece_number);
int lenHelper(float x);

char get_piece_Letter(char piece_in_array){
  char letter=' ';
  switch (piece_in_array)
  {
    case 1:
        letter='L';
        break;
    case 2:
        letter='J';
        break;
    case 3:
        letter='Z';
        break;
    case 4:
        letter='S';
        break;
    case 5:
        letter='T';
        break;
    case 6:
        letter='O';
        break;
    case 7:
        letter='I';
        break;
  }
  return letter;
}




char procesar_entrada_joyStick(void){
  //Leemos el disparo
  char movement=0;
  char joy=JoystickRead(0);
  switch (joy)
  {
    //Movimiento arriba
    case 1:
        //movement=UP;
        break;
    //Moviemiento derecha
    case 3:
        movement=RIGHT;
        break;
    //Mociemiento abajo
    case 5:
        movement=DOWN;
        break;
    //Moviemiento izquierda
    case 7:
        movement=LEFT;
        break;
    default:
        movement=0;
        break;
  } 
  char trigger = TriggerRead(0);
  if (trigger!=0) {
    movement=ROTATE;
  }
#ifdef __SDCC
    __asm
        Halt
    __endasm; 
  #endif
  return movement;
}

char procesar_entrada_teclado(char movement){
  char key=WaitKey();
  switch (key)
  {
    //Movimiento arriba
    case 30:
        //movement=UP;
        break;
    //Moviemiento derecha
    case 28:
        movement=RIGHT;
        break;
    //Mociemiento abajo
    case 31:
        movement=DOWN;
        break;
    //Moviemiento izquierda
    case 29:
        movement=LEFT;
        break;
    default:
        movement=0;
        break;
  } 
  return movement;
}

char is_static_piece(char piece_number){
    if(piece_number>7 && piece_number<15)
        return 1;
    else
        return 0;
}

char is_piece(char piece_number){
    if(piece_number>0 && piece_number<8)
        return 1;
    else
        return 0;
}

//devuelve el tamaño de un integer
int lenHelper( float x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}


char get_letter(char letter){
  char letter_in_tileset=0;
  char position_letter_in_tileset=35;
  switch (letter){
    case ' ' :
      letter_in_tileset=0;
    case 'A':
      letter_in_tileset=34;
      break;
    case 'a':
      letter_in_tileset=34;
      break;
    case 'B':
      letter_in_tileset=position_letter_in_tileset;
      break;
    case 'b':
      letter_in_tileset=position_letter_in_tileset;
      break;
    case 'C':
      letter_in_tileset=position_letter_in_tileset+1;
      break;
    case 'c':
      letter_in_tileset=position_letter_in_tileset+1;
      break;
    case 'D':
      letter_in_tileset=position_letter_in_tileset+2;
      break;
    case 'd':
      letter_in_tileset=position_letter_in_tileset+2;
      break;
    case 'E':
      letter_in_tileset=position_letter_in_tileset+3;
      break;
    case 'e':
      letter_in_tileset=position_letter_in_tileset+3;
      break;
    case 'F':
      letter_in_tileset=position_letter_in_tileset+4;
      break;
    case 'f':
      letter_in_tileset=position_letter_in_tileset+4;
      break;
    case 'G':
      letter_in_tileset=position_letter_in_tileset+5;
      break;
    case 'g':
      letter_in_tileset=position_letter_in_tileset+5;
      break;
    case 'H': 
      letter_in_tileset=position_letter_in_tileset+6;
      break;
    case 'h': 
      letter_in_tileset=position_letter_in_tileset+6;
      break;
    case 'I':
      letter_in_tileset=position_letter_in_tileset+7;
      break;
    case 'i':
      letter_in_tileset=position_letter_in_tileset+7;
      break;
    case 'J':
      letter_in_tileset=position_letter_in_tileset+8;
      break;
    case 'j':
      letter_in_tileset=position_letter_in_tileset+8;
      break;
    case 'K':
      letter_in_tileset=position_letter_in_tileset+9;
      break;
    case 'k':
      letter_in_tileset=position_letter_in_tileset+9;
      break;
    case 'L':
      letter_in_tileset=position_letter_in_tileset+10;
      break;
    case 'l':
      letter_in_tileset=position_letter_in_tileset+10;
      break;
    case 'M':
      letter_in_tileset=position_letter_in_tileset+11;
      break;
    case 'm':
      letter_in_tileset=position_letter_in_tileset+11;
      break;
    case 'N':
      letter_in_tileset=position_letter_in_tileset+12;
      break;
    case 'n':
      letter_in_tileset=position_letter_in_tileset+12;
      break;
    case 'O':
      letter_in_tileset=position_letter_in_tileset+13;
      break;
    case 'o':
      letter_in_tileset=position_letter_in_tileset+13;
      break;
    case 'P':
      letter_in_tileset=position_letter_in_tileset+14;
      break;
    case 'p':
      letter_in_tileset=position_letter_in_tileset+14;
      break;
    case 'Q':
      letter_in_tileset=position_letter_in_tileset+15;
      break;
    case 'q':
      letter_in_tileset=position_letter_in_tileset+15;
      break;
    case 'R':
      letter_in_tileset=position_letter_in_tileset+16;
      break;
    case 'r':
      letter_in_tileset=position_letter_in_tileset+16;
      break;
    case 'S':
      letter_in_tileset=position_letter_in_tileset+17;
      break;
    case 's':
      letter_in_tileset=position_letter_in_tileset+17;
      break;
    case 'T': 
      letter_in_tileset=position_letter_in_tileset+18;
      break;
    case 't': 
      letter_in_tileset=position_letter_in_tileset+18;
      break;
    case 'U':
      letter_in_tileset=position_letter_in_tileset+19;
      break;
    case 'u':
      letter_in_tileset=position_letter_in_tileset+19;
      break;
    case 'V': 
      letter_in_tileset=position_letter_in_tileset+20;
      break;
    case 'v': 
      letter_in_tileset=position_letter_in_tileset+20;
      break;
    case 'W':
      letter_in_tileset=position_letter_in_tileset+21;
      break;
    case 'w':
      letter_in_tileset=position_letter_in_tileset+21;
      break;
    case 'X':
      letter_in_tileset=position_letter_in_tileset+22;
      break;
    case 'x':
      letter_in_tileset=position_letter_in_tileset+22;
      break;
    case 'Y':
      letter_in_tileset=position_letter_in_tileset+23;
      break;
    case 'y':
      letter_in_tileset=position_letter_in_tileset+23;
      break;
    case 'Z':
      letter_in_tileset=position_letter_in_tileset+24;
      break;
    case 'z':
      letter_in_tileset=position_letter_in_tileset+24;
      break;
  }
  return letter_in_tileset;
}