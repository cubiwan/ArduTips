# Generate random numbers with arduino

## Using analog port

You need connect a wire to the analog port use to "read" random numbers.

To generate a random byte you can use the function:
```C
byte randomAnalog(int analogInput);
```

*analogInput* - indicates the analog input use to read random values.

return a random byte;

*randomAnalog* function read a noisy value from analog port and take last bit eight times to compose a byte

```C
byte randomAnalog(int analogInput){
   byte rnd = 0;
  
  for(int i = 0; i < 8; i++){
    int aux = analogRead(analogInput)%2 << i;
    rnd += aux;
    delay(10);
  }

  return rnd;
}
```
## Fair Generators

A random source is fair when both bits [0,1] have equal probability (50%). 

```C
byte randomFairAnalog(int analogInput){
   byte rnd = 0;
  
  for(int i = 0; i < 8; ){
    delay(5);    
    int aux1 = analogRead(analogInput)%2<< i;
    delay(5);
    int aux2 = analogRead(analogInput)%2<< i;

    if(aux1 == aux2)
      continue;
   
    rnd += aux1;
    i++;
    
  }

  return rnd;
}
```

## Combine Generators

If you need "more randomness" you can combine two diferent random sources to generates one value using xor operator:

```C
byte r0 = randomAnalog(A0);
byte r1 = randomAnalog(A1);

byte r = r1 ^ r0;
```

## Example with both generatos

```C
void setup() {
  Serial.begin(9600);  
}

void loop() {
  //Serial.println(analogRead(0));
  //Serial.println(randomAnalog(0));
  //Serial.println(randomFairAnalog(0));
  delay(500);
}

byte randomAnalog(int analogInput){
   byte rnd = 0;
  
  for(int i = 0; i < 8; i++){
    int aux = analogRead(analogInput)%2 << i;
    rnd += aux;
    delay(10);
  }

  return rnd;
}


byte randomFairAnalog(int analogInput){
  byte rnd = 0;

  for(int i = 0; i < 8; ){
    delay(5);
    int aux1 = analogRead(analogInput)%2;
    delay(5);
    int aux2 = analogRead(analogInput)%2;

    if(aux1 == aux2)
      continue;
 
    rnd += (aux1 << i);
    i++;
  }

  return rnd;
}
```
