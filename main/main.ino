#include <Servo.h>

Servo servo[6]; 

#define x 1
#define y 2
#define z 3
#define roll_x 4
#define yaw_y 5
#define pitch_z 6

int modo, grau, motor; 

void mover_par(int motor_1, int motor_2, int grau){
    int aux = grau - 90;
    int inverso = 90 - aux;
    servo[motor_1].write(inverso);
    servo[motor_2].write(grau);
}

void mover(int motor, int grau){
    if(motor % 2 == 0){
        int aux = grau - 90;
        int inverso = 90 - aux;
        servo[motor].write(inverso); 
    }
    else{
        servo[motor].write(grau);
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
            Serial.print("Não implementado.");
        break;

        case y:
            Serial.print("Não implementado.");
        break;

        case z:
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            for(int i = 0; i < 6; i++){
                mover(i, grau)
                delay(150);
            }
        break;

        case roll_x:
            Serial.print("Não implementado.");
        break;

        case yaw_y:
            Serial.print("Não implementado.");
        break;

        case pitch_z:
            Serial.print("Não implementado.");
        break;

        default:
            Serial.print("Opção inválida!");
        break;
    }
}