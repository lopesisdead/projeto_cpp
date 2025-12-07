#include <iostream>
#include <string>

class Animal{
    
    private:
        std::string name;
        std::string color;
        int length;
    
    public:
        // Construtor da classe
        Animal(std::string name, std::string color, int length){
            this->name = name;
            this->color = color;
            this->length = length;
        }

        // métodos de get
        std::string getName(){ return name; }
        std::string getColor(){ return color; }
        int getLength(){ return length; }

        // métodos de set
        void setName(std::string name){ this->name = name; }
        void setColor(std::string color){ this->color = color; }
        void setLength(int length){ this->length = length; }

        // métodos de instância

        void showInfos(){
            std::cout << "Nome: " << name << std::endl;
            std::cout << "Cor: " << color << std::endl;
            std::cout << "Comprimento: " << length << std::endl;
        }

        // métodos virtuais puros
        virtual void makeNoise() = 0;
        virtual void uniqueAction() = 0;

        // Destrutor virtual é importante ao usar herança com new/delete
        virtual ~Animal() = default; 
};

class Cat : public Animal{
    public:
        // Construtor de Cat chamando o construtor da classe base Animal
        Cat(std::string name, std::string color, int length)
            : Animal(name, color, length) {}

        void makeNoise() override{
            std::cout << "Gato: Miau..." << std::endl;
        }

        void uniqueAction() override{
            std::cout << "Gato: Se limpando..." << std::endl;
        }
};

int main() {
    Cat juno("Juno", "Escaminha", 35);
    juno.showInfos();
    std::cout << "Cor teste: " << juno.getColor() << std::endl;
    std::cout << "---" << std::endl;

    Animal* minhaGata = new Cat("Flora", "Tricolor", 15);
    
    minhaGata->makeNoise(); 
    minhaGata->uniqueAction();
    minhaGata->showInfos();

    // desalocando a memória
    delete minhaGata; 
    minhaGata = nullptr; // boa prática após delete

    return 0;
}