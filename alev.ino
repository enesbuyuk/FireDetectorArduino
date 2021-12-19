int alevsiddeti;//ldr'nin ölçtüğü değeri saklayabilmek için bir değişken oluşturduk.
#include <LiquidCrystal.h> //lcd ekran için gereken kod kütüphanesini ekledik.
LiquidCrystal lcd(12,10,5,4,3,2); //lcd ekran için yaptığımız bağlantıları tanımladık ve isim verdik.
int buzzer = 11;      // sesli uyarı seviyesini seçin
int valorSensor = 0;  // sensördeki değeri saklamak için değişken
void setup() {
 // Seri port hız ayarı
 Serial.begin(9600);
  lcd.begin(16,2);//Modelini de belirterek lcd ekranı başlattık
 // sesli uyarı ÇIKIŞ olarak ayarlandı:
  pinMode(buzzer, OUTPUT);
}
void loop() {
  // 
  valorSensor = analogRead(A0);
   //Serial.println(valorSensor);  burası sensor verileri yazılıyor.
  // sesli uyarıyı etkinleştir
  if (valorSensor < 500){
   Serial.println("uyariver"); // c# programiyla iletisim kurmak icin gerekli!
   digitalWrite(buzzer, HIGH);
   delay(200);
  // Sesli uyarıyı devre dışı bırak
  digitalWrite(buzzer, LOW);
  delay(100);
  alevsiddeti=analogRead(A0); //ldr'nin ölçtüğü değeri A0 pininden okuduk ve değişken içine attık.
  lcd.clear();//lcd üzerinde yazanları temizledik.
  lcd.setCursor(0,0);//İmleci birinci satırda birinci harfe getirdik.
  lcd.print("alevsiddeti : ");//Ekrana istediğimiz mesajı yazdırdık.
  lcd.setCursor(0,1);//İmleci ikinci satırda birinci harfe getirdik.
  lcd.print(alevsiddeti);//ldr'nin ölçtüğü değeri ekrana yazdırdık.
  delay(500);
    }
 }
