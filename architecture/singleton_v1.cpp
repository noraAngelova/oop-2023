#include <iostream>
// Версия 1 с използване на динамична памет и стандартна статично поле
class System {
  private:
   System *instance;
   unsigned generalData;
 
   // Private constructor so that no objects can be created.
   System(unsigned data) {
      generalData = data;
   }

  public:
   static System *getInstance() {
      if (!instance) {
        instance = new System(1); // Не се изтрива, дори да се направи конструктор, никъде не се вика delete
      }
      return instance;
   }

   int getData() {
      return this -> generalData;
   }

   void setData(unsigned data) {
      this -> generalData = data;
   }
   
   System(System const & other) = delete;
   System& operator=(System const & other) = delete;
   System() = delete;
};

// Инициализация на статичното поле, за да е различимо
System *System::instance = nullptr;

int main() {
   System * client= client->getInstance();
   std::cout << client->getData() << std::endl;
   client->setData(100);
   std::cout << client->getData() << std::endl;
   return 0;
}
