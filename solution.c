#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

void exitIfError() {
    printf("ERROR\n");
    exit(1);
}

int main(int argc, char **argv) {

    bool ifNodes = false;

    if (argc == 2) {
      if (strcmp(argv[1], "-v") == 0) {
          ifNodes = true;
      }
      else {
          exitIfError();
      }
    }
    else if (argc > 2) {
          exitIfError();
    }

  rootBirth();

  char *word = NULL;
  int i;
  while(scanf("%ms", &word) != EOF) {
        scanf("%d", &i);
        if (strcmp(word, "ADD_NODE") == 0) {
            addNode(i);
        }

        if (strcmp(word, "RIGHTMOST_CHILD") == 0) {
            rightmostChild(i);
        }

        if (strcmp(word, "DELETE_NODE") == 0) {
            deleteNode(i);
        }

        if (strcmp(word, "DELETE_SUBTREE") == 0) {
            deleteSubtree(i);
            OK();
        }

        if (strcmp(word, "SPLIT_NODE") == 0) {
            int j;
            scanf("%d", &j);
            splitNode(i, j);
        }


        if(ifNodes) {
            Nodes();
        }
        free(word);
  }
  deleteSubtree(0);
  delHashtable();
  return 0;
}
