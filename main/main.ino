#include <Servo.h>

Servo servo[6]; 

#define x 1
#define y 2
#define z 3
#define roll_x 4
#define yaw_y 5
#define pitch_z 6

int modo, graus, motor, inverso, aux; 

void mover_par(int motor_1, int motor_2, int graus){
    int aux = graus - 90;
    int inverso = 90 - aux;
    servo[motor_1].write(inverso);
    servo[motor_2].write(graus);
}

void mover(int motor, int graus){
    if(motor % 2 == 0){
        int aux = graus - 90;
        int inverso = 90 - aux;
        servo[motor].write(inverso); 
    }
    else{
        servo[motor].write(graus);
    }
}

void setup(){
    servo[0].attach(2);  // attaches the servo on pin 2 to the servo object
    servo[1].attach(3);  // attaches the servo on pin 3 to the servo object
    servo[2].attach(4);  // attaches the servo on pin 4 to the servo object
    servo[3].attach(5);  // attaches the servo on pin 5 to the servo object
    servo[4].attach(6);  // attaches the servo on pin 6 to the servo object
    servo[5].attach(7);  // attaches the servo on pin 7 to the servo object


    servo[0].write(90);  // move servo to 90º
    delay(400);
    servo[1].write(90);  // move servo to 90º
    delay(400);
    servo[2].write(90);  // move servo to 90º
    delay(400);
    servo[3].write(90);  // move servo to 90º
    delay(400);
    servo[4].write(90);  // move servo to 90º
    delay(400);
    servo[5].write(90);  // move servo to 90º
    delay(400);

    Serial.begin(9600);
}

void loop(){

    Serial.println("Digite o modo desejado: ");
    Serial.println("1. x");
    Serial.println("2. y");
    Serial.println("3. z");
    Serial.println("4. roll_x");
    Serial.println("5. yaw_y");
    Serial.println("6. pitch_z");
    while(!Serial.available());
    Serial.print("Modo escolhido: ");
    modo = Serial.parseInt();
    Serial.println(modo);

    switch(modo){
        case x:
            //
        break;

        case y:
            //
        break;

        case z:
            //
        break;

        case roll_x:
            //
        break;

        case yaw_y:
            //
        break;

        case pitch_z:
            //
        break;

        default:
            //
        break;
    }


    Serial.println("Digite o Numero do Motor: ");
    while(!Serial.available());

    motor = Serial.parseInt();
    Serial.println(motor);

    Serial.println("Digite o Grau desejado: ");
    while(!Serial.available());

    graus = Serial.parseInt();
    Serial.println(graus);

    if( motor < 7 ){
        servo[motor-1].write(graus);

        Serial.print("Motor: ");
        Serial.println(motor);
        Serial.print(graus);
        Serial.println(" Graus");
        Serial.println();
    }
    else if( motor == 7){
        if(graus == 90)
        {
            for(int i = 0; i < 6; i++)
            {
                servo[i].write(graus);
                delay(150);
            }

            Serial.print("Todos os Motores em ");
            Serial.print(graus);
            Serial.println(" Graus");
            Serial.println();
        }
        else
        {
            aux = graus - 90;
            inverso = 90 - aux;

            int pares = 2;

            Serial.println("Mover em pares ? (1) Sim (2) Nao");
            while(!Serial.available());

            pares = Serial.parseInt();

            if(pares == 2){
                for(int i = 0; i < 6; i++){
                    if(i % 2 == 0){
                        servo[i].write(inverso);
                    }
                    else{
                        servo[i].write(graus);
                    }

                    delay(150);
                }
            }
            else if(pares == 1){
                servo[0].write(graus);
                servo[1].write(inverso);
                delay(150);

                servo[2].write(graus);
                servo[3].write(inverso);
                delay(150);

                servo[4].write(graus);
                servo[5].write(inverso);
                delay(150);
            }

            Serial.print("Todos os Motores em ");
            Serial.print(graus);
            Serial.print(" Graus ");
            Serial.println(" Inverso:");
            Serial.println(inverso);
        }
    }
    else if( motor == 8){
        switch(graus){
            case 1:
            servo[0].write(30);
            delay(300);
            servo[1].write(150);
            delay(300);
            break;

            case 2:
            servo[2].write(30);
            delay(300);
            servo[3].write(150);
            delay(300);
            break;

            case 3:
            servo[4].write(30);
            delay(300);
            servo[5].write(150);
            delay(300);
            break;
        }
    }
    delay(15);                           // waits for the servo to get there
}