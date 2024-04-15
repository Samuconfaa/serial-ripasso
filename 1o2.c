void setup(){
    Serial.begin(9600);
}

void loop(){
    while (Serial.available() == 0) {
    }
    int numero = Serial.parseInt();
    if((numero > 2) || (numero == 0)){
        Serial.println("Numero non accettato. Deve essere 1 o 2");
    }else{
        Serial.println(numero);
    }

    delay(500);
}
