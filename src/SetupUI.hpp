#pragma once
#include <Geode/Geode.hpp>
#include <functional>

class PositionHelper {
public:
    // Callback ini akan mengirimkan (CCPoint posisi, CCPoint anchor)
    using PositionCallback = std::function<void(cocos2d::CCPoint, cocos2d::CCPoint)>;

    // Fungsi untuk menghitung posisi berdasarkan tipe alignment (misal: Tengah, Kiri, Kanan)
    static void hitungPosisiAnchor(std::string tipeLayout, PositionCallback callback);
};   