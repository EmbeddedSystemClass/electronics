#define LDR_PIN A0
#define EXPOSURE_MIN 300
#define EXPOSURE_TIME_WEEK 5
#define SCREEN_TIME 50
#define CAP 1800 // 1800 = 30 minutes


int     timer = 0;
int     screen_timer = 0;
short   mesure = 0;
int     day_total = 0;
short   week = 0;
short   week_count = 0;
int     val_actu = 0;
int     val_prec = 0;

void  week_inc(short *week, int day_average)
{
  *week += (day_average < EXPOSURE_MIN ? 0 : 1);
}

void  week_result(short week)
{
  if (week >= EXPOSURE_TIME_WEEK)
    Serial.println("ENOUGHT LIGHT");
  else
    Serial.println("NOT ENOUGHT LIGHT");
}

void  set_screen(int *screen_timer, int opt)
{
  *screen_timer = 0;
  if (opt)
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);  
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  val_actu = analogRead(LDR_PIN);
//  Serial.print("LDR val_actu :");
//  Serial.println(val_actu);
  
  //SET THE SCREEN ON OR OFF
  
  if (val_actu - val_prec > 20)
    set_screen(&screen_timer, 1);
  if (screen_timer == SCREEN_TIME)
    set_screen(&screen_timer, 0);
  
  //MESURE LOOP
  
  if (timer == CAP)
  {
    day_total += val_actu;
    mesure++;
    //Serial.print("mesure :");
    //Serial.println(mesure);
    if (mesure == 48)
    {
      week_inc(&week, (mesure / 48));
      week_count++;
      mesure = 0;
      //Serial.print("week_count :");
      //Serial.println(week_count);
    }
    if (week_count == 7)
    {
      week_result(week);
      week = 0;
      week_count = 0;
    }
    timer = 0;  
  }
  
  timer++;
  screen_timer++;
  val_prec = val_actu;
  delay(100);
}
