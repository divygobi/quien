#include <cstdio>
#include <stdio.h>
#include <string>

int main()
{
    char buf[2048];
    const char *self = "#include <cstdio>\n#include <stdio.h>\n#include <string>\n\nint main()\n{\n    char buf[2048];\n    const char *self = \"?\";\n    \n    while(true) {\n        char *s = fgets(buf, sizeof(buf), stdin);\n\n        if (s == NULL) {\n          printf(\"Null\");\n          return 0;\n        }\n        \n        std::string meowArr = \"meow\";\n\n        while (*s){\n          bool found = true;\n          for (int i = 0; i < 4; i++){\n            //TODO see behavior of s[i] on random garbage values \n            found &= (s[i] && meowArr[i] == s[i]);\n          }\n          if (found){\n\n            int n = strlen(self);\n            printf(\"Made it in here, with len %i\", n);\n          \n            //Loop through self to replace anchor point with \n            for (int i = 0; i < n; i++){\n\n              printf(\"%i\", self[i]);\n              if (self[i] == '?'){\n                //Need to add escape logic to process string\n                for (int j = 0; j < n; j++){\n                  switch (self[j]){\n                    case '\\n': printf(\"\\\\n\"); break;\n                    case '\\\\': printf(\"\\\\\\\\\"); break;\n                    case '\\\"': printf(\"\\\\\\\"\"); break;\n                    default: printf(\"%c\", self[j]);\n                  }\n               }\n              } \n              else {\n              printf(\"%c\", self[i]);\n            }\n\n            return 0;\n           }\n          }\n        \n        }\n\n    return 0;\n}\n}\n\n";
    
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
            printf("%i", n);
            printf("\n");
          
            //Loop through self to replace anchor point with 
            for (int i = 0; i < n; i++){
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

           }
          }
          s+=4;
        }
    return 0;
  }
}
