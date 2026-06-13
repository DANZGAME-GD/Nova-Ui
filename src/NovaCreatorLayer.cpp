#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include "SetupUI.hpp"

using namespace geode::prelude;

class $modify (NovaCreatorLayer, CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;
        this->setupNovaUI();
        return true;
    }
    void setupNovaUI() {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        //hide menu
        bool enableuserinterface = Mod::get()->getSettingValue<bool>("enable-user-interface");
        
        auto creator_menu = this->getChildByID("creator-buttons-menu");

        if (enableuserinterface) {
            creator_menu->setVisible(false);
            return;
        }
        creator_menu->setVisible(true);
    }
};