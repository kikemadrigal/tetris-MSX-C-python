#define NUMERO_FILAS 18
#define NUMERO_COLUMNAS 10

/*char empty_table[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
  };*/
  //Otra forma es definirlo como strings
/*char new_table[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "},
    {"          "}
  };*/

/*char table[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
  };*/
  char table[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };
  char table_empty[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };
  /*char table[NUMERO_FILAS][NUMERO_COLUMNAS]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1}
  };*/
  /*char table[NUMERO_FILAS][NUMERO_COLUMNAS]={
  {"X       "},
  {"XXX     "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "},
  {"        "}
};*/

unsigned char TILESET_pat[]={
  0,0,0,0,0,0,0,0,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  255,255,255,255,255,255,255,255,
  0,0,0,0,0,0,0,0,
  255,255,255,255,255,255,255,255,
  5,5,5,5,5,5,5,5,
  160,160,160,160,160,160,160,160,
  255,0,255,0,0,0,0,0,
  0,0,0,0,0,255,0,255,
  7,5,7,5,5,5,5,5,
  224,160,224,160,160,160,160,160,
  5,5,5,5,5,7,5,7,
  160,160,160,160,160,224,160,224,
  0,56,68,76,16,100,68,56,
  0,12,4,4,0,4,4,4,
  0,56,4,4,56,64,64,120,
  0,56,4,4,56,4,4,56,
  0,68,68,68,56,4,4,4,
  0,56,64,64,56,4,4,56,
  0,56,64,64,56,68,68,56,
  0,112,8,8,0,8,8,8,
  0,28,34,34,28,34,34,28,
  0,56,68,68,56,4,4,56,
  0,28,34,34,28,34,34,34,
  0,60,34,34,28,34,34,60,
  0,28,32,32,0,32,32,28,
  0,60,34,34,0,34,34,60,
  0,60,32,32,28,32,32,60,
  0,28,32,32,6,34,34,28,
  0,34,34,34,28,34,34,34,
  0,8,8,8,0,8,8,8,
  0,2,2,2,0,34,34,28,
  0,34,36,40,28,34,34,34,
  0,32,32,32,0,32,32,30,
  0,28,42,42,0,34,34,34,
  0,50,42,38,0,34,34,34,
  0,28,34,34,0,34,34,28,
  0,60,34,34,28,32,32,32,
  0,28,34,34,0,34,36,26,
  0,60,34,34,28,40,36,34,
  0,30,32,32,28,2,2,60,
  0,62,8,8,0,8,8,8,
  0,34,34,34,0,34,34,28,
  0,34,34,34,4,40,48,32,
  0,34,34,34,0,42,42,28,
  0,34,34,20,8,20,34,34,
  0,34,34,34,28,2,2,28,
  0,30,2,4,8,16,32,60
};



//60 tiles de colores
unsigned char TILESET_col[]={
  17,17,17,17,17,17,17,17,
  145,145,145,145,145,145,145,145,
  113,113,113,113,113,113,113,113,
  129,129,129,129,129,129,129,129,
  33,33,33,33,33,33,33,33,
  97,97,97,97,97,97,97,97,
  161,161,161,161,161,161,161,161,
  81,81,81,81,81,81,81,81,
  145,145,145,145,145,145,145,145,
  113,113,113,113,113,113,113,113,
  129,129,129,129,129,129,129,129,
  33,33,33,33,33,33,33,33,
  97,97,97,97,97,97,97,97,
  161,161,161,161,161,161,161,161,
  81,81,81,81,81,81,81,81,
  81,81,81,81,81,81,81,81,
  225,225,225,225,225,225,225,225,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  254,254,254,254,254,254,254,254,
  17,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,33,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,33,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49,
  49,49,49,49,49,49,49,49

};






//Las ultimas 2 (debería de ser 24 filas) las dejamos para escribir con PutTex
char scene[22][32]={
  {17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,17,21,21,21,21,21,21,21,21,21,21,17,17,17,17,17,17,17,17,54,52,43,54,43,53,17,17,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,47,53,58,17,53,50,36,43,48,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,15,21,21,21,21,21,21,21,21,21,21,21,21,21,15,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,1,1,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,53,38,49,52,40,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,0,0,0,0,0,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,1,1,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,50,43,40,38,40,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,0,0,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,1,1,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,46,40,56,40,46,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,0,0,19,17,17,18,1,1,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,18,1,1,1,1,1,1,1,1,1,1,1,1,1,19,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,15,20,20,20,20,20,20,20,20,20,20,20,20,20,15,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,18,1,1,1,1,1,1,1,1,1,0,19,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,17,20,20,20,20,20,20,20,20,20,20,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17},
  {17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17}


};