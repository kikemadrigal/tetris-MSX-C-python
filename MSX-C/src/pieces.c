/*
////////PIEZAS///////////


N                           
N                            
N                               RR
NN                               RR   
Pieza L color naranja          Pieza Z color rojo
 J
 J
 J                              VV
JJ                             VV
Pieza J color azul            Pieza S color verde
 M                            AA
MMM                           AA
Pieza T color Morado          Pieza O color amarillo
 C
 C
 C
 C
Pieza I color Cyan
*/
char arrayPieces[]={'L','J','Z','S','O','T','I'};

typedef struct{
    char type;
    char color;
    char *piece_definition;
    char rotation;
    char *rotations;
} TPiece;

/*
N                           
N                            
NN                                                           
Pieza L color naranja 
*/

/*unsigned char lPiece[4][2]={
    {0,0},
    {1,0},
    {2,0},
    {2,1}
};*/ 
unsigned char lPieceString[4][10]={
    {' ',' ',' ',' ','L',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','L',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','L','L',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};
/*
 J
 J  
JJ   
Pieza J color azul  
*/
/*unsigned char jPiece[4][2]={
    {0,1},
    {1,1},
    {2,1},
    {2,0}
};*/
unsigned char jPieceString[4][10]={
    {' ',' ',' ',' ','J',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','J','J','J',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};
/*
 RR
  RR   
Pieza Z color rojo
*/
/*unsigned char zPiece[4][2]={
    {0,0},
    {0,1},
    {1,1},
    {1,2}
};*/
unsigned char zPieceString[4][10]={
    {' ',' ',' ','Z','Z',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','Z','Z',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};
/*
 VV
VV
Pieza S color verde
*/
/*unsigned char sPiece[4][2]={
    {0,1},
    {0,2},
    {1,0},
    {1,1}
};*/
unsigned char sPieceString[4][10]={
    {' ',' ',' ',' ','S','S',' ',' ',' ',' '},
    {' ',' ',' ','S','S',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};
/*
 M                     
MMM  
Pieza T color Morado        
*/
/*unsigned char tPiece[4][2]={
    {0,1},
    {1,0},
    {1,1},
    {1,2}
};*/
unsigned char tPieceString[4][10]={
    {' ',' ',' ',' ','T',' ',' ',' ',' ',' '},
    {' ',' ',' ','T','T','T',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};

/*
AA
AA
Pieza O color amarillo
*/
/*unsigned char oPiece[4][2]={
    {0,0},
    {0,1},
    {1,0},
    {1,1}
};*/
unsigned char oPieceString[4][10]={
    {' ',' ',' ',' ','O','O',' ',' ',' ',' '},
    {' ',' ',' ',' ','O','O',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};
/*
 C
 C
 C
 C
Pieza I color Cyan
*/
/*unsigned char iPiece[4][2]={
    {0,0},
    {1,0},
    {2,0},
    {3,0}
};*/
unsigned char iPieceString[4][10]={
    {' ',' ',' ',' ','I',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','I',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','I',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','I',' ',' ',' ',' ',' '}
};

/*****************ROTATIONS**************/
//PIECE L
/*    

    - 1 - - - - - - - - -
    - 2 3 4 - - - - - - - 
    - - - - - - - - - - -
    Para rotarlo
    Movimiento 1
      1      2     3      4
     f c    f c    f c    f c
    {0,1},{-1,0},{0,-1},{1,-2}
    - 2 1 - - - - - - - -
    - 3 - - - - - - - - -
    - 4 - - - - - - - - -
    Movimiento 2
    {0,2},{1,1},{-1,1},{-2,0}
    - 4 3 2 - - - - - - -
    - - - 1 - - - - - - -
    - - - - - - - - - - -
    Movimiento 3
    {0,1},{1,0},{2,-1},{1,-2}
    - - - 4 - - - - - - -
    - - - 3 - - - - - - -
    - - 1 2 - - - - - - -
    Movimiento4 (volver a la posición inicial)
    {1,1},{0,0},{-2,0},{-1,-1}    
    - 1 - - - - - - - - -
    - 2 3 4 - - - - - - - 
    - - - - - - - - - - -
*/
signed char jRotations[4][4][2]={
    {
        {1,1},{0,0},{-2,0},{-1,-1}
    },
    {
        {0,1},{-1,0},{0,-1},{1,-2}
    },
    {
        {0,2},{1,1},{-1,1},{-2,0}
    },
    {
        {0,1},{1,0},{2,-1},{1,-2}
    }
};
signed char lRotations[4][4][2]={
    {
        {1,1},{0,0},{-2,0},{-1,-1}
    },
    {
        {0,1},{-1,0},{0,-1},{1,-2}
    },
    {
        {0,2},{1,1},{-1,1},{-2,0}
    },
    {
        {0,1},{1,0},{2,-1},{1,-2}
    }
};