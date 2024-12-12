#include<iostream>
using namespace std;

class CPU
{
private:

    string model;
    double Ghz;

public:
    CPU() = default;
    CPU(const char* mod, double g)
    {
        model.append(mod);
        Ghz = g;
    }
    string GetModel()
    {
        return model;
    }

    void SetModel(string m)
    {
        model = m;
    }

    double GetGhz()
    {
        return Ghz;
    }

    void SetGhz(double g)
    {
        Ghz = g;
    }
};

class SSD
{
private:

    string model;
    double val;

public:
    SSD() = default;
    SSD(const char* mod, double v)
    {
        model.append(mod);
        val = v;
    }
    string GetModel()
    {
        return model;
    }

    void SetModel(string m)
    {
        model = m;
    }

    double GetVal()
    {
        return val;
    }

    void SetVal(double v)
    {
        val = v;
    }
};

class RAM
{
private:

    string model;
    double memory;

public:
    RAM() = default;
    RAM(const char* mod, double m)
    {
        model.append(mod);
        memory = m;
    }
    string GetModel()
    {
        return model;
    }

    void SetModel(string m)
    {
        model = m;
    }

    double GetMemory()
    {
        return memory;
    }

    void SetMemory(double m)
    {
        memory = m;
    }
};

class GPU
{
private:

    string model;

public:
    GPU() = default;
    GPU(const char* mod)
    {
        model = mod;
    }
    string GetModel()
    {
        return model;
    }

    void SetModel(string m)
    {
        model = m;
    }
};

class Mouse
{
private:

    string model;
    string type;

public:
    Mouse() = default;
    Mouse(const char* mod, const char* t)
    {
        model = mod;
        type = t;
    }
    string GetModel()
    {
        return model;
    }

    void SetModel(string m)
    {
        model = m;
    }

    string GetType()
    {
        return type;
    }

    void SetType(string t)
    {
        type = t;
    }
};

class Laptop
{
private:

    CPU cpu;
    SSD ssd;
    RAM ram;
    GPU gpu;
    Mouse* mouse;

public:

    Laptop() = default;
    Laptop(const char* cpuModel, double g, const char* ssdModel, double v, const char* ramModel, double mm, const char* gpuModel, Mouse* m) :cpu(cpuModel, g), ssd(ssdModel, v), ram(ramModel, mm), gpu(gpuModel)
    {
        mouse = m;
    }
    void Print()
    {
        cout << "CPU " << cpu.GetModel() << " " << cpu.GetGhz() << endl;
        cout << "SSD " << ssd.GetModel() << " " << ssd.GetVal() << endl;
        cout << "RAM " << ram.GetModel() << " " << ram.GetMemory() << endl;
        cout << "GPU " << gpu.GetModel() << endl;
        cout << "Mouse " << mouse->GetModel() << " " << mouse->GetType() << endl;
    }
};

int main()
{
    Mouse mouse("Razer", "wired");
    Laptop* laptop = new Laptop("AMD", 3.8, "DDR5", 32, "Kingston", 1024, "AMD", &mouse);
    laptop->Print();
    delete laptop;
    cout << "Mouse " << mouse.GetModel() << " " << mouse.GetType() << endl;
}