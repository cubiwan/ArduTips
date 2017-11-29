
### Stop program

Best option to stop an Arduino program is put it into a infinite loop. You need disable interrupts or one could break your "infinite" loop.

````C
void stop(){
  noInterrupts();
  while(1){
    delay(1000);
  };
}
````

### Reset program

This code doesn't work always. You do a jump to address 0.

````C
void reset() {
  asm volatile ("  jmp 0");
}

````
