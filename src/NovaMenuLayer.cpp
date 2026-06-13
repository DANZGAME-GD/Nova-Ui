#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/Setting.hpp>
#include "SetupUI.hpp"

using namespace geode::prelude;

class $modify(NovaMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        this->setupNovaUI();
        return true;
    }

    void setupNovaUI() {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto menuva = CCMenu::create();
        menuva->setPosition({ 0, 0 });
        menuva->setID("nova_menu");
        this->addChild(menuva);

        //hide menu
        bool enableuserinterface = Mod::get()->getSettingValue<bool>("enable-user-interface");
        
        auto playbtn = this->getChildByID("main-menu");
        auto media = this->getChildByID("social-media-menu");
        auto more = this->getChildByID("more-games-menu");
        auto gdtitle = this->getChildByID("main-title");
        auto profile = this->getChildByID("profile-menu");

        // make button
        auto makeButton = [&](const char* logoframe, const char* text, const char* fnt, const char* idspr, const char* idlogo, const char* idtext,  SEL_MenuHandler cb) {
            auto spr = CCSprite::create("Button.png"_spr);
            auto logo = CCSprite::create(logoframe);
            auto label = CCLabelBMFont::create(text, fnt);
            spr->setID(idspr);
            logo->setID(idlogo);
            label->setID(idtext);
            logo->setPosition({
                spr->getContentSize().width / 2 - 50,
                spr->getContentSize().height / 2
            });
            label->setPosition({ 
                spr->getContentSize().width / 2 - 36,
                spr->getContentSize().height / 2 
            });
            label->setAnchorPoint({ 0.0f, 0.5f });
            logo->setScale(0.4);
            label->setScale(0.4);
            
            
            spr->addChild(logo);
            spr->addChild(label);
            return CCMenuItemSpriteExtra::create(spr, this, cb);
        };
        
        auto mainlevelbtn = makeButton("main_icon.png"_spr, "Main Levels", "gjFont52.fnt", "main-levels-btn", "main-levels-icon", "main-levels-label",  menu_selector(NovaMenuLayer::onPlay));
        auto creatorbtn = makeButton("creator_point.png"_spr, "Creator", "gjFont52.fnt", "creator-btn", "creator-icon", "creator-label", menu_selector(NovaMenuLayer::onCreator));
        auto iconbtn = makeButton("exit.png"_spr, "Icon", "gjFont52.fnt", "icons-btn", "icons-logo", "icons-label", menu_selector(NovaMenuLayer::onGarage));
        auto settingsbtn = makeButton("settings.png"_spr, "Settings", "gjFont52.fnt", "settings-btn", "settings-icon", "settings-label", menu_selector(NovaMenuLayer::onOptions));
        auto geodebtn = makeButton("geode_logo.png"_spr, "Geode", "gjFont52.fnt", "geoode-btn", "geode-icons", "geode-label", menu_selector(NovaMenuLayer::onOptions));
        auto exitbtn = makeButton("exit.png"_spr, "Quit", "gjFont52.fnt", "exit-btn", "exit-icon", "exit-label", menu_selector(NovaMenuLayer::onQuit));
        
        auto searchbtn = CCMenuItemSpriteExtra::create(
            CCSprite::create("search.png"_spr),
            this,
            menu_selector(NovaMenuLayer::onOptions)
        );
        PositionHelper::hitungPosisiAnchor("center-right", [&](CCPoint pos, CCPoint anchor) {
            searchbtn->setPosition(pos);
            searchbtn->setID("search-button");
            searchbtn->setPositionX(searchbtn->getPositionX() - 108);
            searchbtn->setPositionY(searchbtn->getPositionY() - 94);
            searchbtn->setScale(1.8);
            searchbtn->m_baseScale = 1.8;
            menuva->addChild(searchbtn);
        });
        // set position
        mainlevelbtn->setPosition({ 75, winSize.height / 2 + 60 });
        mainlevelbtn->setID("main-levels-button");
        creatorbtn->setPosition({ 75, winSize.height / 2 + 22 });
        creatorbtn->setID("creator-buttonn");
        iconbtn->setPosition({ 75, winSize.height / 2 - 16 });
        iconbtn->setID("icons-button");
        settingsbtn->setPosition({ 75, winSize.height / 2 - 52 });
        settingsbtn->setID("settings-button");
        geodebtn->setPosition({ 75, winSize.height / 2 - 88 });
        exitbtn->setPosition({ 75, winSize.height / 2 - 124 });
        exitbtn->setID("quit-button");

        //add button to menu
        menuva->addChild(mainlevelbtn);
        menuva->addChild(creatorbtn);
        menuva->addChild(iconbtn);
        menuva->addChild(settingsbtn);
        menuva->addChild(geodebtn);
        menuva->addChild(exitbtn);

        if (enableuserinterface) {
            menuva->setVisible(true);
            playbtn->setVisible(false);
            media->setVisible(false);
            more->setVisible(false);
            gdtitle->setVisible(false);
            profile->setVisible(true);
            return;
        }
        menuva->setVisible(false);
        playbtn->setVisible(true);
        media->setVisible(true);
        more->setVisible(true);
        gdtitle->setVisible(true);
        profile->setVisible(true);
    }
    
    void onPlay(CCObject*) {
        MenuLayer::onPlay(nullptr);
    }
};