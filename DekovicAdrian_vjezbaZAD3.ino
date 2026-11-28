char oznaka = 'T';
bool termickaZastita = false;      
unsigned int ulazni_mV = 12500;
unsigned int izlazni_mV = 5000;
unsigned int struja_mA = 450;
unsigned long vrijeme_s = 86400;

float U_pad;
float P_dis;
float E_toplina;

void setup() {
  Serial.begin(9600);
  U_pad = (ulazni_mV - izlazni_mV) / 1000.0;
  P_dis = U_pad * (struja_mA / 1000.0);
  E_toplina = P_dis * vrijeme_s;

  unsigned int SRAM = sizeof(oznaka) + sizeof(termickaZastita) +
  sizeof(ulazni_mV) + sizeof(izlazni_mV) +
  sizeof(struja_mA) + sizeof(vrijeme_s) +
  sizeof(U_pad) + sizeof(P_dis) + sizeof(E_toplina);

  Serial.println("DIJAGNOSTIKA REGULATORA 7805");
  Serial.print("Oznaka kucista: ");
  Serial.println(oznaka);
  Serial.print("Termicka zastita: ");
  Serial.println(termickaZastita ? "UKLJUCENA" : "ISKLJUCENA");
  Serial.print("Pad napona (U_pad): ");
  Serial.print(U_pad);
  Serial.println(" V");
  Serial.print("Disipirana snaga (P_dis): ");
  Serial.print(P_dis);
  Serial.println(" W");
  Serial.print("Toplinska energija (E_toplina): ");
  Serial.print(E_toplina);
  Serial.println(" J");
  Serial.print("Ukupno zauzece SRAM-a: ");
  Serial.print(SRAM);
  Serial.println(" bajtova od 2048 B.");
}

void loop() {
}


