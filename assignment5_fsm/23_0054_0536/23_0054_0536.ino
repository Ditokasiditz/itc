
// West
#define WB 6
#define WR 7
#define WY 8
#define WG 9
// South
#define SB 2
#define SR 3
#define SY 4
#define SG 5
// zebra walk Dern
#define DB 10
#define DR 11
#define DG 12

int RYGpin[8] = {SG, SY, SR, WG, WY, WR, DG, DR};

// zebra(R G) West(R Y G) South(R Y G)

#define waitWbin B10010100
#define dernbin B01100100
#define waitDbin B00100100
#define goSbin B10100001
#define waitSbin B10100010
#define goWbin B10001100 

struct FiniteState
{
    unsigned int display;
    unsigned long time;
    unsigned int next[8];
};

FiniteState state[] = {
    {goSbin, 200, {0, 0, 1, 1, 2, 2, 2, 1}},
    {waitSbin, 300, {3, 3, 3, 3, 3, 3, 3, 3}},
    {waitSbin, 300, {6, 6, 6, 6, 6, 6, 6, 6}},
    {goWbin, 200, {3, 4, 3, 4, 5, 5, 5, 5}},
    {waitWbin, 300, {0, 0, 0, 0, 0, 0, 0, 0}},
    {waitWbin, 300, {6, 6, 6, 6, 6, 6, 6, 6}},
    {dernbin, 200, {6, 7, 13, 7, 6, 7, 13, 7}},
    {waitDbin, 500, {8, 8, 8, 8, 8, 8, 8, 8}},
    {dernbin,  500, {9, 9, 9, 9, 9, 9, 9, 9}},
    {waitDbin, 500, {10, 10, 10, 10, 10, 10, 10, 10}},
    {dernbin,  500, {11, 11, 11, 11, 11, 11, 11, 11}},
    {waitDbin, 500, {12, 12, 12, 12, 12, 12, 12, 12}},
    {dernbin,  500, {0, 0, 0, 0, 0, 0, 0, 0}},
    {waitDbin, 500, {14, 14, 14, 14, 14, 14, 14, 14}},
    {dernbin,  500, {15, 15, 15, 15, 15, 15, 15, 15}},
    {waitDbin, 500, {16, 16, 16, 16, 16, 16, 16, 16}},
    {dernbin,  500, {17, 17, 17, 17, 17, 17, 17, 17}},
    {waitDbin, 500, {18, 18, 18, 18, 18, 18, 18, 18}},
    {dernbin,  500, {3, 3, 3, 3, 3, 3, 3, 3}},
};

void setup()
{
    pinMode(DB, INPUT_PULLUP);
    pinMode(WB, INPUT_PULLUP);
    pinMode(SB, INPUT_PULLUP);
    for (size_t i = 0; i < 8; i++)
    {
        pinMode(RYGpin[i], OUTPUT);
    }
}

void traffic(int bin)
{
    for (size_t i = 0; i < 8; i++)
    {
        digitalWrite(RYGpin[i], bitRead(bin, i));
    }
}

int s;

void loop()
{
    traffic(state[s].display);

    delay(state[s].time);

    int dernButton = !digitalRead(DB);
    int westButton = !digitalRead(WB);
    int southButton = !digitalRead(SB);
    int input = dernButton * 4 + westButton * 2 + southButton;
    s = state[s].next[input];
}
