const int PROBE = A3;
const int TRANS = 8; 
bool TRANS_STATE = true;

void setup()
{
    pinMode(TRANS, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    unsigned int v_1 = 0;

    digitalWrite(TRANS, !TRANS_STATE);

    v_1 = analogRead(PROBE);

    digitalWrite(TRANS, TRANS_STATE);

    delay(50);

    Serial.print(v_1);
    Serial.print(",");
    Serial.print(analogRead(PROBE));
    Serial.println();

    delay(50);
}
