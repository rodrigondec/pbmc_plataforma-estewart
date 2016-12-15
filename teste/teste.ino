/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo servo[6]; 

int graus, motor, inverso, aux; 

void setup()
{
  servo[0].attach(2);  // attaches the servo on pin 9 to the servo object
  servo[1].attach(3);  // attaches the servo on pin 9 to the servo object
  servo[2].attach(4);  // attaches the servo on pin 9 to the servo object
  servo[3].attach(5);  // attaches the servo on pin 9 to the servo object
  servo[4].attach(6);  // attaches the servo on pin 9 to the servo object
  servo[5].attach(7);  // attaches the servo on pin 9 to the servo object

  
  servo[0].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  servo[1].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  servo[2].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  servo[3].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  servo[4].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  servo[5].write(90);  // attaches the servo on pin 9 to the servo object
  delay(400);
  
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite o Numero do Motor: ");
  while(!Serial.available());
  
  motor = Serial.parseInt();
  Serial.println(motor);
  
  Serial.println("Digite o Grau desejado: ");
  while(!Serial.available());
  
  graus = Serial.parseInt();
  Serial.println(graus);

  if( motor < 7 )
  {
    servo[motor-1].write(graus);
    
    Serial.print("Motor: ");
    Serial.println(motor);
    Serial.print(graus);
    Serial.println(" Graus");
    Serial.println();
  }
  else if( motor == 7)
  {
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

        if(pares == 2)
        {
          for(int i = 0; i < 6; i++)
          {
            if(i % 2 == 0)
            {
              servo[i].write(inverso);
            }
            else
            {
              servo[i].write(graus);
            }
            
            delay(150);
          }
        }
        else if(pares == 1)
        {
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
  else if( motor == 8)
  {
    switch(graus)
    {
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

