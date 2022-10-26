#define led 3
int num = 0;
char key = '0';


void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  Serial.println("my arduino");
  digitalWrite(led,LOW);
}

void loop() {
  while(Serial.available())
  {
    num = Serial. parseInt();
    Serial.println(num);
    int i;
    for(i=0;i<num;i++)
    {
      digitalWrite(led,HIGH);
      delay(300);
      digitalWrite(led,LOW);
      delay(300);     
    }
   }

}
