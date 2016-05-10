#include <chrono>
using namespace std;

class SimpleTimer
{
    public:
    void Start()
    {
        m_beginTime = chrono::system_clock::now();
    }

    double GetElapsed()
    {
        chrono::time_point<chrono::system_clock> endTime;
        endTime = chrono::system_clock::now();
        chrono::duration<double> delta = endTime - m_beginTime;
        return delta.count();
    }

    private:
    chrono::time_point<chrono::system_clock> m_beginTime;
};
