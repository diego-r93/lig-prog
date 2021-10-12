#ifndef FIBONACCI
#define FIBONACCI "fibonacci.h"

class Fibonacci {
   public:
      void setFibonacci(int);
      int getFibonacci();

   private:
      int computeFibonacci(int);
      int resultado;
};

#endif