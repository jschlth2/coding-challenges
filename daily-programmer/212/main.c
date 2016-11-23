//
// AUTHOR : JOSHUA SCHULTHEISS
// LANGUAGE : C
// PROBLEM STATEMENT : https://www.reddit.com/r/dailyprogrammer/comments/341c03/20150427_challenge_212_easy_rövarspråket/
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* rovarspraket(char* in) {
    int index = 0, size = 0;
    while(in[index]!='\0') {
        if(in[index]=='A'||in[index]=='a' ||
           in[index]=='E'||in[index]=='e' ||
           in[index]=='I'||in[index]=='i' ||
           in[index]=='O'||in[index]=='o' ||
           in[index]=='U'||in[index]=='u' ||
           in[index]=='Y'||in[index]=='Y' ||
           in[index]==' '||in[index]=='\''||
           in[index]==','||in[index]=='.') {
            size += 1;
        } else size += 3;
        index++;
    }
    char *out = (char *)malloc(sizeof(char)*size);
    int i, o=0;
    for( i=0 ; i<index ; i++ ) {
        if(in[i]=='A'||in[i]=='a' ||
           in[i]=='E'||in[i]=='e' ||
           in[i]=='I'||in[i]=='i' ||
           in[i]=='O'||in[i]=='o' ||
           in[i]=='U'||in[i]=='u' ||
           in[i]=='Y'||in[i]=='Y' ||
           in[i]==' '||in[i]=='\''||
           in[i]==','||in[i]=='.') {
            out[o] = in[i];
            o++;
        } else {
            out[o] = in[i];
            out[o+1] = 'o';
            out[o+2] = in[i];
            o += 3;
        }
    }
    return out;
}

int main() {
    char input[550] = "Here's to the crazy ones. The misfits. The rebels. The troublemakers. The round pegs in the square holes. The ones who see things differently. They're not fond of rules. And they have no respect for the status quo. You can quote them, disagree with them, glorify or vilify them. About the only thing you can't do is ignore them. Because they change things. They push the human race forward. And while some may see them as the crazy ones, we see genius. Because the people who are crazy enough to think they can change the world, are the ones who do.";
    char *output = rovarspraket(input);
    printf("INPUT:\n%s\n\nOUTPUT:\n%s\n",input,output);
    return 0;
}
