#include "impl2.h"

int main(){
    int n;
    struct dictionaryADT *t = NULL;
    struct wordMeaning x;

    printf("Enter no.of words:");
    scanf("%d",&n);

    printf("Enter words and their meaning:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s",x.word);
        scanf("%s",x.meaning);
        t = insert(t,x);
    }
    
    inorder(t);
    search(t,"cite");
    return 0;

    
}