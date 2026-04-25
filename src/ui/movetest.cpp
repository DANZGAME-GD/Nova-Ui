#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {

    bool init() {

        if (!CreatorLayer::init())
            return false;

        auto bottomCorner = this->getChildByID("bottom-left-corner");

        if (!bottomCorner)
            return true;

        static CCPoint originalPos = bottomCorner->getPosition();

        bool enabled = Mod::get()->getSettingValue<bool>("move-bottom-ui");

        if (enabled) {

            bottomCorner->setPosition({
                originalPos.x + 150,
                originalPos.y + 40
            });

        } else {

            bottomCorner->setPosition(originalPos);

        }

        return true;
    }
};
