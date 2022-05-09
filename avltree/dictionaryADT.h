struct wordMeaning{
    char word[20];
    char meaning[20];
};

struct dictionaryADT
{
	struct wordMeaning element;
	struct dictionaryADT *left;
    struct dictionaryADT *right;
	int height;
};


struct dictionaryADT *insert(struct dictionaryADT *, struct wordMeaning );
void inorder(struct dictionaryADT *);
void search(struct dictionaryADT *, char * );