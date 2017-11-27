# Generate random numbers with arduino

You need connect a wire to the analog port use to "read" random number.

For generate a random byte you can use the function:
```C
byte random(int analogInput);
```

*analogInput* - indicates the analog input use to read random values.

return a random byte;
