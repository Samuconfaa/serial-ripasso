int numero[100];
int tot;
int sommaPari = 0;
int sommaDispari = 0;
int media = 0;
int contoP = 0;
int contoD = 0;
char stato;


void setup(){
    Serial.begin(9600);
    for(int i = 0; i < 10; i++){
        numero[i] = 0;
    }

}

void loop(){
    if(game){
        Serial.println("Quanti numeri vuoi inserire? (max 100)");
        while (Serial.available() == 0) {
        }
        tot = Serial.parseInt();
        while(tot > 100){
            Serial.println("Ho detto che puoi inserire massimo 100 numeri!!!");
            while (Serial.available() == 0) {
            }
            tot = Serial.parseInt();
        }
        for(int i = 0; i < tot; i++){
            Serial.print("Inserisci un valore per il numero ");
            Serial.println(i);
            while (Serial.available() == 0) {
            }
            numero[i] = Serial.parseInt();
        }
        Serial.println("Perfetto! Ora farò la somma per i numeri pari e la media per quelli dispari.");
        delay(500);
        for(int i = 0; i < tot; i++){
            if(numero[i] % 2 == 0){
                sommaPari = sommaPari + numero[i];
                contoP = contoP + 1;
            }else{
                sommaDispari = sommaDispari + numero[i];
                contoD = contoD + 1;
            }
        }

        media = sommaDispari/contoD;

        Serial.print("La somma dei ");
        Serial.print(contoP);
        Serial.println(" numeri pari e':");
        Serial.println(sommaPari);

        Serial.println(" ");
        Serial.print("Invece la media dei ");
        Serial.print(contoD);
        Serial.println(" numeri dispari e':");
        Serial.println(media);
    }



}
