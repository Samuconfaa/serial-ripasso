int numero[100];
int tot = 100; 
int sommaPari = 0;
int sommaDispari = 0;
int media = 0;
int contoP = 0;
int contoD = 0;

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 10; i++) {
        numero[i] = 0;
    }
}

void loop() {
    Serial.println("Ora ti chiedero' alcuni numeri, scrivi <stop> quando vorrai fermari");
    delay(1000);
    for (int i = 0; i < tot; i++) {
        Serial.print("Inserisci un valore per il numero ");
        Serial.println(i);
        while (Serial.available() == 0) {
        }

        String input = Serial.readString(); 


        if (input.equals("stop")) {
            break;
        }

        numero[i] = input.toInt();
    }

    Serial.println("Perfetto! Ora faro' la somma per i numeri pari e la media per quelli dispari.");
    delay(500);

    for (int i = 0; i < tot; i++) {
        if (numero[i] % 2 == 0) {
            sommaPari += numero[i];
            contoP++;
        } else {
            sommaDispari += numero[i];
            contoD++;
        }
    }

    media = sommaDispari / contoD;

    Serial.print("La somma dei ");
    Serial.print(contoP);
    Serial.println(" numeri pari e':");
    Serial.println(sommaPari);

    Serial.println(" ");
    Serial.print("Invece la media dei ");
    Serial.print(contoD);
    Serial.println(" numeri dispari e':");
    Serial.println(media);

    delay(2000);
}
