#include "SetupUI.hpp"

using namespace geode::prelude;

void PositionHelper::hitungPosisiAnchor(std::string tipeLayout, PositionCallback callback) {
    // Ambil ukuran layar Geometry Dash saat ini (lebar & tinggi)
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    float w = winSize.width;
    float h = winSize.height;

    cocos2d::CCPoint posisiBaru;
    cocos2d::CCPoint anchorBaru;

    // 1. TOP (Atas)
    if (tipeLayout == "top-left") {
        posisiBaru = ccp(0, h);
        anchorBaru = ccp(0.0f, 1.0f);
    } 
    else if (tipeLayout == "top-center") {
        posisiBaru = ccp(w / 2, h);
        anchorBaru = ccp(0.5f, 1.0f);
    } 
    else if (tipeLayout == "top-right") {
        posisiBaru = ccp(w, h);
        anchorBaru = ccp(1.0f, 1.0f);
    }
    // 2. CENTER (Tengah)
    else if (tipeLayout == "center-left") {
        posisiBaru = ccp(0, h / 2);
        anchorBaru = ccp(0.0f, 0.5f);
    } 
    else if (tipeLayout == "center") {
        posisiBaru = ccp(w / 2, h / 2);
        anchorBaru = ccp(0.5f, 0.5f);
    } 
    else if (tipeLayout == "center-right") {
        posisiBaru = ccp(w, h / 2);
        anchorBaru = ccp(1.0f, 0.5f);
    }
    // 3. BOTTOM (Bawah)
    else if (tipeLayout == "bottom-left") {
        posisiBaru = ccp(0, 0);
        anchorBaru = ccp(0.0f, 0.0f);
    } 
    else if (tipeLayout == "bottom-center") {
        posisiBaru = ccp(w / 2, 0);
        anchorBaru = ccp(0.5f, 0.0f);
    } 
    else if (tipeLayout == "bottom-right") {
        posisiBaru = ccp(w, 0);
        anchorBaru = ccp(1.0f, 0.0f);
    }
    // Default jika string tidak cocok (diatur ke tengah)
    else {
        posisiBaru = ccp(w / 2, h / 2);
        anchorBaru = ccp(0.5f, 0.5f);
    }

    // Jalankan callback ke File B
    if (callback) {
        callback(posisiBaru, anchorBaru);
    }
}