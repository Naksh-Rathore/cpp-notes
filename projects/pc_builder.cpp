#include <iostream>
#include <string>
#include <string_view>

class PC {
    private:
        std::string m_cpu{};
        std::string m_gpu{};
        std::string m_motherboard{};

        int m_ramGB{};
        double m_ssdTB{};

        int m_price{};

        bool m_isOn { false };

    public:
        PC(std::string_view cpu, std::string_view gpu, std::string_view motherboard, int ramGB, double ssdTB, int price)
            : m_cpu { cpu }
            , m_gpu { gpu }
            , m_motherboard { motherboard }
            , m_ramGB { ramGB }
            , m_ssdTB { ssdTB }
            , m_price { price }
        {
        }

        void printSpecs() {
            std::cout << "CPU: " << m_cpu << "\n";
            std::cout << "GPU: " << m_gpu << "\n";
            std::cout << "RAM (GB): " << m_ramGB << "\n";
            std::cout << "SSD (TB): " << m_ssdTB << "\n";
            std::cout << "Price: $" << m_price << "\n";
        }

        bool turnOn() {
            if (m_isOn) 
                std::cout << "Your PC is already on!" << "\n";

            else if (m_ramGB < 4)
                std::cout << "Your RAM is too low! It has to be 4GB+ to run." << "\n";

            else if (m_ssdTB < 0.064)
                std::cout << "Your SSD is too small! You need to have at least 64GB (0.064TB) free to run." << "\n";

            else {
                std::cout << "Your PC is turning on..." << "\n";
                m_isOn = true;

                return true;
            }

            return false;
        }

        bool turnOff() {
            if (m_isOn) {
                std::cout << "Your PC is turning off..." << "\n";
                m_isOn = false;

                return true;
            }

            else
                std::cout << "Your PC is already off!" << "\n";

            return false;
        }

        std::string getCpu() { return m_cpu; }
        void setCpu(std::string_view cpu) { m_cpu = cpu; }

        std::string getGpu() { return m_gpu; }
        void setGpu(std::string_view gpu) { m_gpu = gpu; }

        std::string getMotherBoard() { return m_motherboard; }
        void setMotherBoard(std::string_view motherboard) { m_motherboard = motherboard; }

        int getRamGB() { return m_ramGB; }
        void setRamGB(int ramGB) { m_ramGB = ramGB; }

        double getSsdTB() { return m_ssdTB; }
        void setSsdTB(double ssdTB) { m_ssdTB = ssdTB; }

        bool getIsOn() { return m_isOn; }
};

int main() {

    PC myPC { "AMD Ryzen 9 9950X", "NVIDIA RTX 5090", "ASUS ROG Crosshair x870e Extreme", 64, 8.0, 2269 };

    myPC.printSpecs();

    std::cout << "\n";

    myPC.turnOn();
    myPC.turnOff();

    return 0;
}
