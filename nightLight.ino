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

#define LEDPIN 2
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
  Serial.begin(57600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(PIRPIN, INPUT);
}

void loop()
{

  if (analogRead(FOTOPIN) < 100) {
    isDark = true;
  } else {
    isDark = false;
  }

  if (digitalRead(PIRPIN) == HIGH && isDark) {
    isLed = ON;
  }
  else {
    isLed = OFF;
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
