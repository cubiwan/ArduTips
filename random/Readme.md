# Generate random numbers with arduino

You need connect a wire to the analog port use to "read" random number.

For generate a random byte you can use the function:
```C
byte random(int analogInput);
```

*analogInput* - indicates the analog input use to read random values.

return a random byte;

If you need por randomness you can combine two diferent random sources to generates one value using xor operator:

```C
byte r0 = random(A0);
byte r1 = random(A1);

byte r = r1 ^ r0;
```
