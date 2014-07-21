#include <iostream>
#include <string.h>
using namespace std;

char* reverse(char *s);
void swap(char *a, char *b);
void reverse_string(char *str);

int main(){
    char *s = "Helloo";
    //strcpy(s, "Hello");
    cout << s << endl;
    reverse_string(s);
    cout << s << endl;
}

char* reverse(char *s){
    cout << "length = " << strlen(s) << endl;
    int l = strlen(s)-1;
    char *end;
    end = s + l;
    char temp = *(s+l-1);
    *end = temp;
    cout <<*end << endl;
    int swapPair = 2;
    // for (int i = 0; i < swapPair; i++){
    //     temp = *(s+i);
    //     *(s+i) = *(s+2);
    //     cout <<temp << endl;
    // }
    
    return s;
}

void reverse_string(char *str)
{
    /* skip null */
    if (str == 0)
    {
    	return;
    }

    /* skip empty string */
    if (*str == 0)
    {
    	return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
    	/* swap */
    	temp = *start;
    	*start = *end;
    	*end = temp;

    	/* move */
    	++start;
    	--end;
    }
}

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}