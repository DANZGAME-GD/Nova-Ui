#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/Setting.hpp>

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

        auto makeButton = [&](SEL_MenuHandler cb) {
            auto spr = CCSprite::create("Button.png"_spr);
            auto btn = CCMenuItemSpriteExtra::create(spr, this, cb);
            return btn;
        };
        auto logo = [&] (const char* frame) {
            auto imagelogo = CCSprite::createWithSpriteFrameName(frame);
            return imagelogo;
        };

        // make button
        auto btn1 = makeButton(menu_selector(NovaMenuLayer::onPlay));
        auto btn2 = makeButton(menu_selector(NovaMenuLayer::onCreator));
        auto btn3 = makeButton(menu_selector(NovaMenuLayer::onOptions));
        auto btn4 = makeButton(menu_selector(NovaMenuLayer::onOptions));
        auto btn5 = makeButton(menu_selector(NovaMenuLayer::onOptions));
        auto btn6 = makeButton(menu_selector(NovaMenuLayer::onQuit));

        // logo to button
        auto logo1 = logo("geode.loader/category-dot.png");
        logo1->setPosition({ 0, 0});
        logo1->setScale({0.35});
        logo1->setAnchorPoint({ 0.0f, 0.5f});
        logo1->setID("test-1");
        btn1->addChild(logo1);

        // set position
        btn1->setPosition({ 75, winSize.height / 2 + 60 });
        btn2->setPosition({ 75, winSize.height / 2 + 22 });
        btn3->setPosition({ 75, winSize.height / 2 - 16 });
        btn4->setPosition({ 75, winSize.height / 2 - 52 });
        btn5->setPosition({ 75, winSize.height / 2 - 88 });
        btn6->setPosition({ 75, winSize.height / 2 - 124 });

        //add button to menu
        menuva->addChild(btn1);
        menuva->addChild(btn2);
        menuva->addChild(btn3);
        menuva->addChild(btn4);
        menuva->addChild(btn5);
        menuva->addChild(btn6);

if (!Mod::get()->getSettingValue<bool>("enable-nova-ui"))
    menuva->removeAllChildrenWithCleanup(true);
    return;
    }
    
    void onPlay(CCObject*) {
        MenuLayer::onPlay(nullptr);
    }
};
