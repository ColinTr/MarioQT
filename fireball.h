#ifndef FIREBALL_H
#define FIREBALL_H

#include "entity.h"
#include "collectableitem.h"
#include "coin.h"

class FireBall : public Entity
{
private:
    QPixmap textures[4];
    QElapsedTimer animationTimer;
    int animationDelay = 100; // in ms
    int textureNumber;

    int deathFrameCounter;
    QPixmap deathTextures[3];

    bool fireballOfFirebar;

    float bounceHeight = BLOCSIZE;
    float bounceDuration = 10; // in number of frames
    float bounceSpeed = -2*bounceHeight/bounceDuration;
    float bounceGravity = 2*bounceHeight/(bounceDuration*bounceDuration);

public:
    FireBall(Direction direction);

    virtual void advance() override;
    virtual void animate() override;
    virtual void die() override;

    void setFireballOfFirebar(bool b) { fireballOfFirebar = b; }
    bool getFireballOfFirebar() { return fireballOfFirebar; }

    virtual void collisionByDefaultHandler(ObjectModel *o) override;
    void collisionOnBottomHandler(ObjectModel *o) override;
    void collisionOnLeftHandler(ObjectModel * o) override;
    void collisionOnRightHandler(ObjectModel * o) override;
    void collisionOnTopHandler(ObjectModel * o) override;
};

#endif // FIREBALL_H
