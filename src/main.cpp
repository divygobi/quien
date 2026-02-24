#include <cstdio>
#include <stdio.h>
#include <string>

int main()
{
    char buf[2048];
    const char *self = "?";
    
    while(true) {
        char *s = fgets(buf, sizeof(buf), stdin);

        if (s == NULL) {
          printf("Null");
          return 0;
        }
        
        std::string meowArr = "meow";

        while (*s){
          bool found = true;
          for (int i = 0; i < 4; i++){
            //TODO see behavior of s[i] on random garbage values 
            found &= (s[i] && meowArr[i] == s[i]);
          }
          if (found){

            int n = strlen(self);
            printf("Made it in here, with len %i", n);
          
            //Loop through self to replace anchor point with 
            for (int i = 0; i < n; i++){

              printf("%i", self[i]);
              if (self[i] == '?'){
                //Need to add escape logic to process string
                for (int j = 0; j < n; j++){
                  switch (self[j]){
                    case '\n': printf("\\n"); break;
                    case '\\': printf("\\\\"); break;
                    case '\"': printf("\\\""); break;
                    default: printf("%c", self[j]);
                  }
               }
              } 
              else {
              printf("%c", self[i]);
            }

            return 0;
           }
          }
        
        }

    return 0;
}
}

