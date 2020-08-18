#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define WORD 100
#define true 1
#define false 0

struct Occorrenza{
    char *word;
    int n;
};

struct Bis_Node{
    struct Bis_Node *l, *r;
    struct Occorrenza occorrenza;
};

typedef struct Bis_Node *BisNode;

BisNode bis_new( char *word ){
    BisNode newnode = (BisNode) malloc( sizeof( struct Bis_Node ) );
    newnode->occorrenza.word = word;
    newnode->occorrenza.n = 1;
    newnode->l = NULL;
    newnode->r = NULL;

    return newnode; 
}

BisNode bis_add( BisNode tree, BisNode to_add ){
    if( tree == NULL ){
        return to_add;
    }
    int compare = strcmp( tree->occorrenza.word, to_add->occorrenza.word );
    if( compare == 0 ){
        tree->occorrenza.n++;
    } else if( compare < 0 ){
        // Inserimento a destra
        if( tree->r == NULL ){
            tree->r = to_add;
        } else {
            tree->r = bis_add( tree->r, to_add );
        }
    } else {
        // Inserimento a sx
        if( tree->l == NULL ){
            tree->l = to_add;
        } else {
            tree->l =  bis_add( tree->l , to_add );
        }
    }
    return tree;
}

void bis_print( BisNode tree, int spaces ){
    int i;
    for( i = 0; i < spaces; i++ ){
        printf(" ");
    }
    printf("* ");
    if( tree ){
        printf("%s(%d)\n", tree->occorrenza.word, tree->occorrenza.n );
        if( !( tree->l == NULL && tree->r == NULL ) ){
            bis_print( tree->l, spaces + 1 );
            bis_print( tree->r, spaces + 1 );
        }
    } else {
        printf( "\n" );
    }
}

void bis_orderprint( BisNode tree ){
    if( tree ){
        bis_orderprint( tree->l );
        printf( "%s (%d)\n", tree->occorrenza.word, tree->occorrenza.n );
        bis_orderprint( tree->r );
    }
}

void bis_invorderprint( BisNode tree) {
    if( tree) {
        bis_invorderprint( tree->r );
        printf( "%s (%d)\n", tree->occorrenza.word, tree->occorrenza.n );
        bis_invorderprint( tree->l );
    }
}

BisNode bis_find( BisNode tree, char* key ){
    if( tree == NULL ){
        return NULL;
    }
    int compare = strcmp( tree->occorrenza.word, key );
    if( compare == 0 ){
        return tree;
    } else if( compare < 0 ){
        return bis_find( tree->r, key );
    } else {
        return bis_find( tree->l, key );
    }
}

int main( int argc, char *argv[] ){
    BisNode tree = NULL;
    
    // Lettura delle parole del testo
    char* word = (char*) calloc( sizeof(char), WORD );
    int index = 0;
    int stop = 0;
    while( !stop ){
        char c = getchar();
        if( tolower(c) >= 'a' && tolower(c) <= 'z' ){
            word[index++] = tolower(c);
        }
        if( c == ' ' || c == '\n' ){
            if( index > 0 ){
                word[index] = '\0';
                if( 0 == strcmp(word, "stop") ){
                    stop = true;
                    free( word );
                } else {
                    tree = bis_add( tree, bis_new( word ) );
                }

                index = 0;
                word = (char*) malloc( sizeof(char) * WORD );
            }
        }
    }

    // Lettura delle parole da cercare
    word = (char*) calloc( sizeof(char), WORD );
    index = 0;
    stop = false;
    int array_size = 10;
    int array_length = 0;
    char** to_search = (char**) calloc( sizeof(char*), array_size );
    while( !stop ){
        char c;
        while( ( c = getchar() ) != '\n' ){
            word[index++] = c;
        }
        index = 0;
        printf("[[%s]]\n", word);
        if( array_length == array_size ){
            array_size *= 2;
            to_search = realloc( to_search, sizeof(char*) * array_size );
        }
        if( strcmp( "STOP", word ) == 0 ){
            stop = true;
        } else {
            to_search[array_length++] = word;
            word = (char*) calloc( sizeof(char), WORD );
        }
    }

    printf( "OCCORRENZE DELLE PAROLE NEL TESTO:\n" );
    printf( "**********************************\n" );
    bis_orderprint( tree );

    printf( "\n" );
    printf( "OCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO:\n" );
    printf( "*************************************************\n" );
    bis_invorderprint( tree );

    printf( "\n" );
    printf( "RICERCA DI PAROLE:\n" );
    printf( "******************\n" );
    int i;
    for( i = 0; i < array_length; i++ ){
        BisNode n = bis_find( tree, to_search[i] );
        if( !n ){
            printf("La parola '%s' non e' nell'albero\n", to_search[i] );
        } else {
            printf("La parola '%s' compare %d volte\n", n->occorrenza.word, n->occorrenza.n );
        }
    }


    return 0;
}
