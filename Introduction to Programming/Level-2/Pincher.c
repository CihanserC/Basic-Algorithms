#include<stdio.h>

int main(){
    char str[] = "11010110110001011010101101110111011011011010101011011101010101101101";
    char ptr[] = "101101"; //The substring to be removed. Let's the removal this as a "pinch".
    int lc, i, j, found_one, found_any;

    printf("%s (The initial string) \n", str);
    //Compute the length of ptr.
    for(lc = 0; ptr[lc] != '\0'; lc++);
    //Outer loop.
    do{
        found_any = 0;
        for(i = 0; str[i+lc] != '\0'; i++){
            found_one = 1;
            for(j = 0; (j < lc) && (found_one != 0); j++){
                if(str[i+j] != ptr[j]){
                    found_one = 0;
                }
            }
            if(found_one == 1){
                found_any = 1;
                for(j = 0; str[i+j+lc] != '\0'; j++){
                    str[i+j] = str[i+j+lc];
                }
                str[i+j] = '\0';
                printf("%s\n", str); //Print after each pinch.
                //break;
            }
        }
    }while(found_any != 0);
    printf("%s (The final string)\n", str);
    return 0;
}

//The answer is not unique.
//It depends on which order we pinch the string.
//As an example uncomment the "break" and run the code again.
//Think & find why!


