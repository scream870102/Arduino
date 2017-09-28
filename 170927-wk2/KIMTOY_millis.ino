
int delayTime = 180;//字的寬度    單位：microseconds
int charBreak = 400;//字的間距    
//設定版子上的LED與ATtiny上的腳位
//預設POV顯示的字頂部朝內 如果要改成底部朝內 將下方的腳位順序反過來即可  
int LED1 = 4;    //如果要將字相反，把LED1改成0
int LED2 = 3;    //            :
int LED3 = 2;    //            :
int LED4 = 1;    //            :
int LED5 = 0;    //如果要將字相反，把LED5改成4

unsigned long time;

////////////////////下方設定都不需要改動////////////////////
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

int a[] = {1, 6, 26, 6, 1};
int b[] = {31, 21, 21, 10, 0};
int c2[] = {14, 17, 17, 10, 0};
int d[] = {31, 17, 17, 14, 0};
int e[] = {31, 21, 21, 17, 0};
int f[] = {31, 20, 20, 16, 0};
int g[] = {14, 17, 19, 10, 0};
int h[] = {31, 4, 4, 4, 31};
int i[] = {0, 17, 31, 17, 0};
int j[] = {0, 17, 30, 16, 0};
int k[] = {31, 4, 10, 17, 0};
int l[] = {31, 1, 1, 1, 0};
int m[] = {31, 12, 3, 12, 31};
int n[] = {31, 12, 3, 31, 0};
int o[] = {14, 17, 17, 14, 0};
int p[] = {31, 20, 20, 8, 0};
int q[] = {14, 17, 19, 14, 2};
int r[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};
int t[] = {16, 16, 31, 16, 16};
int u[] = {30, 1, 1, 30, 0};
int v[] = {24, 6, 1, 6, 24};
int w[] = {28, 3, 12, 3, 28};
int x[] = {17, 10, 4, 10, 17};
int y[] = {17, 10, 4, 8, 16};
int z[] = {19, 21, 21, 25, 0};

int eos[] = {0, 1, 0, 0, 0};
int excl[] = {0, 29, 0, 0, 0};
int ques[] = {8, 19, 20, 8, 0};

void displayLine(int line) {
  int myline;
  myline = line;
  if (myline >= 16) {
    digitalWrite(LED1, HIGH);
    myline -= 16;
  } else {
    digitalWrite(LED1, LOW);
  }
  if (myline >= 8)  {
    digitalWrite(LED2, HIGH);
    myline -= 8;
  }  else {
    digitalWrite(LED2, LOW);
  }
  if (myline >= 4)  {
    digitalWrite(LED3, HIGH);
    myline -= 4;
  }  else {
    digitalWrite(LED3, LOW);
  }
  if (myline >= 2)  {
    digitalWrite(LED4, HIGH);
    myline -= 2;
  }  else {
    digitalWrite(LED4, LOW);
  }
  if (myline >= 1)  {
    digitalWrite(LED5, HIGH);
    myline -= 1;
  }  else {
    digitalWrite(LED5, LOW);
  }
}

void displayChar(char c) {
  if (c == 'a') {
    for (int i = 0; i < 5; i++) {
      displayLine(a[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'b') {
    for (int i = 0; i < 5; i++) {
      displayLine(b[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'c') {
    for (int i = 0; i < 5; i++) {
      displayLine(c2[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'd') {
    for (int i = 0; i < 5; i++) {
      displayLine(d[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'e') {
    for (int i = 0; i < 5; i++) {
      displayLine(e[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'f') {
    for (int i = 0; i < 5; i++) {
      displayLine(f[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'g') {
    for (int i = 0; i < 5; i++) {
      displayLine(g[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'h') {
    for (int i = 0; i < 5; i++) {
      displayLine(h[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'i') {
    for (int it = 0; it < 5; it++) {
      displayLine(i[it]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'j') {
    for (int i = 0; i < 5; i++) {
      displayLine(j[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'k') {
    for (int i = 0; i < 5; i++) {
      displayLine(k[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'l') {
    for (int i = 0; i < 5; i++) {
      displayLine(l[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'm') {
    for (int i = 0; i < 5; i++) {
      displayLine(m[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'n') {
    for (int i = 0; i < 5; i++) {
      displayLine(n[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'o') {
    for (int i = 0; i < 5; i++) {
      displayLine(o[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'p') {
    for (int i = 0; i < 5; i++) {
      displayLine(p[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'q') {
    for (int i = 0; i < 5; i++) {
      displayLine(q[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'r') {
    for (int i = 0; i < 5; i++) {
      displayLine(r[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 's') {
    for (int i = 0; i < 5; i++) {
      displayLine(s[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 't') {
    for (int i = 0; i < 5; i++) {
      displayLine(t[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'u') {
    for (int i = 0; i < 5; i++) {
      displayLine(u[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'v') {
    for (int i = 0; i < 5; i++) {
      displayLine(v[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'w') {
    for (int i = 0; i < 5; i++) {
      displayLine(w[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'x') {
    for (int i = 0; i < 5; i++) {
      displayLine(x[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'y') {
    for (int i = 0; i < 5; i++) {
      displayLine(y[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == 'z') {
    for (int i = 0; i < 5; i++) {
      displayLine(z[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == '!') {
    for (int i = 0; i < 5; i++) {
      displayLine(excl[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == '?') {
    for (int i = 0; i < 5; i++) {
      displayLine(ques[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  if (c == '.') {
    for (int i = 0; i < 5; i++) {
      displayLine(eos[i]);
      delayMicroseconds(delayTime);
    } displayLine(0);
  }
  delayMicroseconds(charBreak);
}

void displayString(char* s) {
  for (int i = 0; i <= strlen(s); i++) {
    displayChar(s[i]);
  }
}
////////////////////上方設定都不需要改動////////////////////

//輸入POV文字處，只能輸入英文小寫、空白、!、？、- 這些符號，POV顯示的英文為大寫
void loop() {
  time = millis();
  if(time%500<=250)
  {
    displayString("xuan");
  }else
  {
    displayString("s ");
  }
  
}
