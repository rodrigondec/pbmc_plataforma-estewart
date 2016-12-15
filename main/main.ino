#include <Servo.h>

Servo servo[6]; 

#define x 1
#define y 2
#define z 3
#define roll_x 4
#define pitch_y 5
#define yaw_z 6
#define motores 7
#define pares 8


int modo, grau, motor, par; 

int inverso(int grau){
    int aux = grau - 90;
    int inverso = 90 - aux;

    return inverso;
}

int inverso_coef(int grau, float coef){
    int aux;

    if(grau >= 90){
        aux = grau - 90;
    }
    else{
        aux = 90 - grau;
    }

    int inverso = 90 - (aux*coef);

    return inverso;
}

int inverso_coef_compl(int grau, float coef){
    int aux;

    if(grau >= 90){
        aux = grau - 90;
    }
    else{
        aux = 90 - grau;
    }

    int inverso = 90 + (aux*coef);

    return inverso;
}

void mover_par(int par, int grau){
    int motor_1, motor_2;

    par *= 2;
    motor_1 = par-2;
    motor_2 = par-1;
    
    servo[motor_1].write(inverso(grau));
    servo[motor_2].write(grau);
}

void mover(int motor, int grau){
    if(motor % 2 == 0){
        servo[motor].write(inverso(grau)); 
    }
    else{
        servo[motor].write(grau);
    }
}

void mover_x(int grau){
    mover(4, grau);
    mover(5, inverso_coef_compl(grau, 0.88) );

    int grau_x = inverso_coef(grau, 0.56);
    mover(0, grau_x);
    mover(1, inverso_coef(grau_x, 0.8) );

    grau_x = inverso_coef_compl(grau, 0.33 );
    mover(2, grau_x);
    mover(3, inverso_coef_compl(grau_x, 0.33 ) );
}

void mover_yaw_z(int grau){
    mover(0, grau);
    mover(1, inverso_coef(grau, 0.153) );
    mover(2, grau);
    mover(3, inverso_coef(grau, 0.153) );
    mover(4, grau);
    mover(5, inverso_coef(grau, 0.153) );
}

void mover_pitch_y(int grau){
    if(grau >= 90){
        if(grau > 160){
            grau = 160;
        }

        int grau_x = inverso(grau);
        mover_par(1, grau);

        mover(3, grau_x);
        mover(4, grau_x);
    }
    else{
        int grau_x = inverso_coef_compl(grau, 0.625);
        mover_par(1, grau);

        mover(3, grau_x);
        mover(4, grau_x);
    }
}

void mover_roll_x(int grau){  
    if(grau <= 40){
        grau = 40;
    }
    
    if(grau > 90){
        mover_par(2, grau);

        mover(0, inverso_coef(grau, 0.214));
        mover(1, inverso_coef_compl(grau, 0.214));

        mover_par(3, inverso(grau));
    }

    else{
        mover_par(2, grau);

        mover(0, inverso_coef_compl(grau, 0.214));
        mover(1, inverso_coef(grau, 0.214));

        mover_par(3, inverso(grau));
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
    Serial.println("5. pith_y");
    Serial.println("6. yaw_z");
    Serial.println("7. motores");
    Serial.println("8. pares");
    
    while(!Serial.available());
    modo = Serial.parseInt();
    
    Serial.print("Modo escolhido: ");
    Serial.println(modo);

    switch(modo){
        case x:
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover_x(grau);
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
                mover(i, grau);
            }
        break;

        case roll_x:
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover_roll_x(grau);
        break;

        case pitch_y:
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover_pitch_y(grau);
        break;

        case yaw_z:
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover_yaw_z(grau);
        break;

        case motores:
            Serial.print("Digite o motor desejado: ");
            while(!Serial.available());
            motor = Serial.parseInt();
            Serial.println(motor);
            
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover(motor, grau);
        break;

        case pares:
            Serial.print("Digite o par desejado: ");
            while(!Serial.available());
            par = Serial.parseInt();
            Serial.println(par);
            
            Serial.print("Digite o Grau desejado: ");
            while(!Serial.available());
            grau = Serial.parseInt();
            Serial.println(grau);

            mover_par(par, grau);
        break;

        default:
            Serial.print("Opção inválida!");
        break;
    }
}
