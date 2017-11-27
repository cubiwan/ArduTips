byte random(int analogInput){
   byte rnd = 0;
  
  for(int i = 0; i < 8; i++){
    int aux = analogRead(analogInput)%2 << i;
    rnd += aux;
    delay(10);
  }

  return rnd;
}
