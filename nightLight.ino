/**
Ночник

Счетч для ардуино, ночное освещение.
Принцип действие:
Освещение включается только когда освещённость ниже порогового и датчик движение говорит о наличии движения.

Схема подключения:

Фоторезистор: A0
Датчик движение D3
ШИМ светодиода: D2

Кузин Сергей <sergey@kuzin.name>
*/

#define LEDPIN 5
#define MOVELEDPIN 13
#define PIRPIN 3
#define FOTOPIN 0

#define ON true
#define OFF false

#define FASTSPEED 20
#define MINLEDLEVEL 0
#define MAXLEDLEVEL 255

bool isDark = false;
bool isLed = OFF;
bool isMotion = false;
int  currentLevel = MINLEDLEVEL;

void setup()
{ 
  pinMode(LEDPIN, OUTPUT);
  pinMode(PIRPIN, INPUT);
  pinMode(MOVELEDPIN, OUTPUT);
}

void loop()
{

  if (analogRead(FOTOPIN) < 100) {
    isDark = true;
  } else {
    isDark = false;
  }

  if (digitalRead(PIRPIN) == HIGH) {    
    digitalWrite(13, HIGH);
    if (isDark) {
      isLed = ON;
    }
  }
  else {
    isLed = OFF;
    digitalWrite(13, LOW);    
  }

  if (isLed) {
    if (currentLevel < MAXLEDLEVEL) {
      currentLevel++;
      analogWrite(LEDPIN, currentLevel);
      delay(FASTSPEED);
    }
  } else {
    if (currentLevel > MINLEDLEVEL) {
      currentLevel--;
      analogWrite(LEDPIN, currentLevel);
      delay(FASTSPEED);
    }
  }

  delay(FASTSPEED);

}
