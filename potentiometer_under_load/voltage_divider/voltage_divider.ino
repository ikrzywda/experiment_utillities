
const int PROBE_UL = A3; // probe reading analog signal
const int PROBE_LD = A4; // loaded probe
const int TRANS = 8; // transistor turning on and off the load
bool TRANS_STATE = true;

const float MAPPING_CONST = 5 / 1024;

void setup()
{
    pinMode(TRANS, OUTPUT);
    Serial.begin(115200);
}

void loop()
{
    digitalWrite(TRANS, !TRANS_STATE);

    Serial.print(analogRead(PROBE_UL));
    Serial.print(",");

    digitalWrite(TRANS, TRANS_STATE);

    delay(50);

    Serial.print(analogRead(PROBE_LD));
    Serial.println();

    delay(50);
}
