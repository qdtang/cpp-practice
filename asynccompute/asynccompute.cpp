#include <iostream>
#include <future>
#include <thread>
#include <random>

int accurateCompute()
{
    std::random_device rd;  // only used to seed an engine
    std::default_random_engine re(rd());
    std::uniform_int_distribution<int> ud(1000, 5000);
    int computeTime = ud(re);
    std::cout << "accurate computation spends " << computeTime << " milliseconds\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(computeTime));
    return 7;
}

int compute()
{
    auto deadline = std::chrono::system_clock::now() + std::chrono::seconds(3);
    auto fut = std::async(std::launch::async, accurateCompute);
    // time for rough computation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int guess = 6;
    std::future_status st = fut.wait_until(deadline);
    if (st == std::future_status::ready) {
        return fut.get();
    }
    else {
        return guess;
    }
}

int main()
{
    std::cout << "result is " << compute() << "\n";
    return 0;
}
