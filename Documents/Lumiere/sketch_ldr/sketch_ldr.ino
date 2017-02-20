#define MINVAL  300
#define LDR_PIN A0
#define EXPOSE  5

short     i = 0;
short   set = 0;
int     val = 0;

void  inc(short *set, int val, short i)
{
  *set += (val < MINVAL ? 0 : 1);
}

int   reset(short set, short i)
{
  if (set > EXPOSE)
    return (1);
  else
    return (0);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LDR_PIN);
  inc(&set, val, i);
  i++;
  if (i == 7)
  {
    if (reset(set, i))
      Serial.println("[Enought light]");
    else
      Serial.println("[NOT ENOUGHT]");
    i = 0;
    set = 0;
  }
  Serial.println(set, BIN);
  delay(5000);
}
