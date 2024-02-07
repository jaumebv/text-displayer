#include <stdio.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <cctype>
#include <windows.h>

void main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char target[1000];
    char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};      
    printf("WRITE\n");
    fgets(target, sizeof(target), stdin);
    for(int i = 0; i < strlen(target); i++){
        if(target[i] == '\0')
            break;
        if(isspace(target[i]))
            continue;
        for(int j = 0; j < strlen(abc); j++){
            SetConsoleTextAttribute(hConsole, 7);       
            for(int k = 0; k < i; k++)
                printf("%c", target[k]);
            SetConsoleTextAttribute(hConsole, (j % 14) + 1); 
            if(((j % 14) + 1) == 7)
                SetConsoleTextAttribute(hConsole, 12); 
            printf("%c",abc[j]);
            printf("\n");
            std::chrono::milliseconds dura(50);
            std::this_thread::sleep_for( dura );
            if(target[i] != abc[j])
                continue;
            break;
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
    for(int i = 0; i < strlen(target); i++)
        printf("%c", target[i]);

    getchar();
    
}
