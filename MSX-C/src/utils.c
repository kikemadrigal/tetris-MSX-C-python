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