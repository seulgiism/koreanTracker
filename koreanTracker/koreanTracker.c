#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../KatArrayLib/katarray.h"

// structure for koreandata, the katarray will point to koreandata structs
typedef struct KoreanData{
    short watches;
    char* name;
    char* link;
} korean_data_t;

#define KATARRAY_CAPACITY 50
//typedef struct KatArray{
//    size_t length;
//    size_t capacity;

//    size_t index_start;
//    size_t index_end;

//    char shrinkable;
//    void* initial_value;
//    void* list[KATARRAY_CAPACITY];
//} katarray_voidp_t;


// main functions for add, rm, show, increment
void instruction_add();
void instruction_rm();
void instruction_show();
void instruction_increment();


// will store the positions of add flags into the vars
// 0 means it was not found
void argv_set_flags_add(char **argv, short argc, char** name, char** link, short* watched);
void argv_set_flags_rm(char **argv, short argc, short* id);
void argv_set_flags_show(char **argv, short argc, short* id);
void argv_set_flags_increment(char **argv, short argc, short* id);


// initialize katarray
katarray_voidp_t* katarray_static_init();


// file handling
#define KOREANDATA_FORMAT_PRINT "[%i, %s, %s]\n" // watches, name, link
#define KOREANDATA_FORMAT_SCANF "[%i, %s, %s]"   // watches, name, link
#define WATCHLIST_FORMAT_PRINT "{ %s | %s | %s }" // name, date, link

FILE* fopen_wrapper(char* file_name, char* file_instruction, const char* function_name);



////////* MAIN *////////

int main(int argc, char** argv) {
    argc = (short)argc;

    // entrance to add, remove, show, increment, help
    if (argc > 1) {
        
        // open files
        FILE* file_replist     = fopen_wrapper("./rep-list.dat", "w", __func__);
        FILE* file_watchedlist = fopen_wrapper("./watched-list.txt", "a", __func__);

        // initialize static katarray
        katarray_voidp_t* KatArray_KoreanData = katarray_static_init();

        
        // ADD feature
        if      (strcmp(argv[1], "add") == 0) {

            // store flags
            char* name = NULL;
            char* link = NULL;
            short watched = 0;
            argv_set_flags_add(argv, argc, &name, &link, &watched);

            // perform ADD instruction


            return 0;
        }

        // REMOVE feature
        else if (strcmp(argv[1], "rm") == 0) {
            
            // store flags
            short id = 0;
            argv_set_flags_rm(argv, argc, &id);

            

            return 0;
        }

        // SHOW feature
        else if (strcmp(argv[1], "show") == 0) {
            
            // store flags
            short id = 0;
            argv_set_flags_show(argv, argc, &id);

            

            return 0;
        }

        // INCREMENT feature
        else if (strcmp(argv[1], "increment") == 0) {

            // store flags
            short id = 0;
            argv_set_flags_increment(argv, argc, &id);

            

            return 0;
        }

        else {

            // HELP feature
            if (strcmp(argv[1], "-h") || strcmp(argv[1], "--help")) {
                
            }

            return 0;
        }

        fclose("./rep-list.dat");
        fclose("./watched-list.txt");
    }

    // error occured

    printf("ERROR");

    return 1;
}


////* add, rm, show, increment instructions *////

// add instruction
void instruction_add(FILE* file, katarray_voidp_t KatArray) {

}



////* command line flag position storer *////

// will store the positions of add flags into the vars
// 0 means it was not found
void argv_set_flags_add(char **argv, short argc, char** name, char** link, short* watched) {
    for (short i = 2; i < argc; i++) {

        // set flags
        if (((strcmp(argv[i], "--name")    == 0) || (strcmp(argv[i], "-n") == 0)) && (i + 1) < argc) *name    = argv[i+1];
        if (((strcmp(argv[i], "--link")    == 0) || (strcmp(argv[i], "-l") == 0)) && (i + 1) < argc) *link    = argv[i+1];
        if (((strcmp(argv[i], "--watched") == 0) || (strcmp(argv[i], "-w") == 0)) && (i + 1) < argc) *watched = (short)(atoi(argv[i+1]));
    }
}

// will store the positions of add flags into the vars
// 0 means it was not found
void argv_set_flags_rm(char **argv, short argc, short* id) {
    for (short i = 2; i < argc; i++) {

        // set flags
        if (((strcmp(argv[i], "--id") == 0) || (strcmp(argv[i], "-i") == 0)) && (i + 1) < argc) *id = (short)(atoi(argv[i+1]));
    }
}

// will store the positions of add flags into the vars
// 0 means it was not found
void argv_set_flags_show(char **argv, short argc, short* id) {
    for (short i = 2; i < argc; i++) {

        // set flags
        if (((strcmp(argv[i], "--id") == 0) || (strcmp(argv[i], "-i") == 0)) && (i + 1) < argc) *id = (short)(atoi(argv[i+1]));
    }
}

// will store the positions of add flags into the vars
// 0 means it was not found
void argv_set_flags_increment(char **argv, short argc, short* id) {
    for (short i = 2; i < argc; i++) {

        // set flags
        if (((strcmp(argv[i], "--id") == 0) || (strcmp(argv[i], "-i") == 0)) && (i + 1) < argc) *id = (short)(atoi(argv[i+1]));
    }
}



////* katarray initializer *////
katarray_voidp_t* katarray_static_init() {
    // initialize katarray_voidp_t
    katarray_voidp_t *KatArray;

    KatArray->length        = 0;
    KatArray->capacity      = KATARRAY_CAPACITY;

    KatArray->index_start   = __SIZE_MAX__;
    KatArray->index_end     = __SIZE_MAX__;

    KatArray->initial_value = NULL;
    KatArray->shrinkable    = -1;

    return KatArray;
}




////* FILE HANDLING *////
FILE* fopen_wrapper(char* file_name, char* file_instruction, const char* function_name) {
    FILE *file = fopen(file_name, file_instruction);
    if (!file) {
        fprintf(stderr, "[ERROR] %s: (%s)\n", __func__, function_name);
        exit(EXIT_FAILURE);
    }
    return file;
}
