#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXWORDS 1640

int r_slen() {
    return (rand() % (30 - 7)) + 7;
}

int n_pgraphs() {
    return (rand() % 7) + 1;
}

int drand(int x) {
    return (rand() % x);
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
    char word[30]; /* boy makes up some long ass words */

    for(int j = r_slen(); j != 0; j--) {
	getnewword(ifp, word, drand(MAXWORDS));
	fputs(word, ofp);

	if(drand(2)) { /* coin flip with a safety */
	    if(drand(9) < 2)
		fputc(punctuation[drand(5)], ofp);
	}

	if(j > 1)
	    fputc(' ', ofp);

	memset(word, 0, strlen(word));
    }
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
    for(int i = n_pgraphs(); i != 0; i--) {
	writesentence(dict_fp, outp_fp);
	fputc('.', outp_fp);
	fputs(spread, outp_fp);
    }
    fputs(closer, outp_fp);

    fclose(outp_fp);
    fclose(dict_fp);
    return EXIT_SUCCESS;
}
