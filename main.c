#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "queue.h"
#include "queue.c"

int main() {

    Eile eil;
    int input, a, b, err;
    Data in, out;


    printf("Pasirinkite norima funkcija:\n");
    printf("1. Sukurti tuscia eile;\n");
    printf("2. Patikrinti, ar eile tuscia;\n");
    printf("3. Patikrinti, ar eile pilna;\n");
    printf("4. Ideti nauja elementa i eile;\n");
    printf("5. Isimti pirma elementa is eiles;\n");
    printf("6. Gauti pirmo eiles elemento reiksme;\n");
    printf("7. Gauti eiles elementu skaiciu;\n");
    printf("8. Sunaikinti eile;\n");
    printf("Iveskite 0 noredami baigti darba\n");
    printf("9. Stress testas;\n");

    while(1){
        printf("Iveskite operacijos numeri: ");
        scanf("%d", &input);
        switch(input){
            case 1:
                InicijuotiEile(&eil);
                printf("Eile sukurta\n");
                break;
            case 2:
                a = ArTuscia(&eil);
                a!=0 ? printf("Eile tuscia\n") : printf("Eile netuscia\n");
                break;
            case 3:
                b = ArPilna();
                b != 0 ? printf("Eile pilna\n") : printf("Eile nepilna\n");
                break;
            case 4:
                printf("Iveskite norima elementa: ");
                scanf("%d", &in);
                int k;
                k = IdetiElementa(in, &eil);
                if(k == 0){
                printf("Eile pilna\n");
                break;
                }
                printf("Elementas idetas\n");
                break;
            case 5:
                err = 1;
                out = IsimtiElementa(&eil, &err); //err = 0 = eile tuscia
                if(err == 0) {                    //err = 1 = elementas isimtas
                    printf("Eile tuscia\n");
                    printf(out);
		            break;
                }
                printf("Isimtas elementas: %d\n", out);

                break;
            case 6:
                a = ArTuscia(&eil);
                if(a!=0){
                    printf("Eile tuscia\n");
                    break;
                }
                printf("Pirmo elemento reiksme: %d\n", GautiReiksme(&eil));
                break;
            case 7:
                printf("Eileje yra %d elementai(-u). \n", KiekElementu(&eil));
                break;
            case 8:
                Istrinti(&eil);
                printf("Eile sunaikinta.\n");
                break;
            case 9:
                printf("prasides stress testas. Iveskite skaiciu: \n");
                Data s, x;

		int i, j, p, t;
		scanf("%d", &s);
		for (i=0; i<1000000; i++){

		    for (j=0; j<10000; j++){
                t = IdetiElementa(s, &eil);
		    }
		    for (p=0; p<10000; p++){
		        x = IsimtiElementa(&eil, &err);

		    }
		}
		break;
            case 0:
                return 0;
            default:
                printf("Prasome ivesti tinkama komandos numeri!\n");

        }
    }


    return 0;

}
