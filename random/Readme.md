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
## Using function micros()

Micros returns the number of microseconds (1 second = 1.000.000 microseconds) since the Arduino board began running. 

To generate a random byte you can use the function:
```C
byte randomMicros();
```

return a random byte;

*randomMicros* function read a noisy value from analog port and take last bit eight times to compose a byte

```C
byte randomMicros(){
  byte rnd = 0;
  
  for(int i = 0; i < 8; i++){
    int aux = micros()%2 << i;
    rnd += aux;
    delay(10);
  }

  return rnd;
}
```

## Combine Generators

If you need "more randomness" you can combine two diferent random sources to generates one value using xor operator:

```C
byte r0 = randomAnalog(A0);
byte r1 = randomMicros();

byte r = r1 ^ r0;
```
