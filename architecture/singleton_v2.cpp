/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
// Версия 2 без динамична памет и с статично променлива
class System {
  private:
   unsigned generalData;
 
   // Private constructor so that no objects can be created.
   System(unsigned data) {
      generalData = data;
   }

  public:
   // Резултатът се връща по рефенция, за да не се прави копие и да се използва конструктор за копиране, който е премахнат
   static System& getInstance() {
      static System instance(1); // ИЗползва се статична променлива, няма динамична памет
      return instance;
   }

   int getData() {
      return this -> generalData;
   }

   void setData(int data) {
      this -> generalData = data;
   }
   
   System(System const & other) = delete;
   System& operator=(System const & other) = delete;
   System() = delete;
};

int main() {
   System& client = client.getInstance();
   std::cout << client.getData() << std::endl;
   client.setData(100);
   std::cout << client.getData() << std::endl;
   return 0;
}
