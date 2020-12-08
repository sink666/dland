#include <stdio.h>
#include <string.h>
#include <bsd/stdlib.h>
#include <time.h>

#define MAXWORDS 1640

int eva(int n1, int n2, int n3) {
    return (arc4random() % (n1 - n2)) + n3;
}

void getnewword(FILE *fp, char* word, int line)
{
    char seek, c;
    int i;

    rewind(fp);
    for(i = 0; (seek = fgetc(fp)) != EOF;) {
	if(seek == '\n') {
	    if(++i == line)
		break;
	}
    }

    for(i = 0; (c = fgetc(fp)) != '\n' && c != EOF; i++)
	word[i] = c;

    word[++i] = '\0';
}

void writesentence(FILE* ifp, FILE* ofp)
{
    char punctuation[] = ".,?;.";
    char word[60]; /* boy makes up some long ass words */

    for(int j = eva(30, 7, 7); j != 0; j--) {
	getnewword(ifp, word, eva(MAXWORDS, 0, 0));
	fputs(word, ofp);

	if(eva(2, 0, 0)) {
	    if(eva(9, 0, 0) < 2)
		fputc(punctuation[eva(5, 0, 0)], ofp);
	}

	if(j > 1) { /* invent a whole new word lmao */
	    if(eva(16, 0, 0))
		fputc(' ', ofp);
	    else
		fputc('-', ofp);
	}

	memset(word, 0, strlen(word));
    }

    fputc('.', ofp);
}

int main(void)
{
    srand(time(NULL));

    char* p_head = "[[ ]] ";
    char* opener = "The story goes like this: ";
    char* spread = "\n\n";
    char* closer = "To be continued.\n";

    FILE* dict_fp = fopen("dict-meltdown.txt", "r");
    FILE* outp_fp = fopen("dland-out.txt", "w");

    fputs(p_head, outp_fp);
    fputs(opener, outp_fp);
    for(int i = eva(7, 0, 1); i != 0; i--) {
	writesentence(dict_fp, outp_fp);
	fputs(spread, outp_fp);
	if(eva(2, 0, 0) && i != 1)
	    fputs(p_head, outp_fp);
    }
    fputs(closer, outp_fp);

    fclose(outp_fp);
    fclose(dict_fp);
    return EXIT_SUCCESS;
}
