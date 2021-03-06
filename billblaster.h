#ifndef BILLBLASTER_H
#define BILLBLASTER_H

#include "inert.h"
#include "bulletbill.h"

class BillBlaster : public Inert
{
private:
    int shootDelay = 3000; // in ms
    QElapsedTimer shootTimer;
    bool shooting;

public:
    BillBlaster();
    virtual void animate() override;
    bool isShooting() { return shooting; }
    void setShooting(bool b) { shooting = b; }
    void restartShootTimer() { shootTimer.restart(); }
    BulletBill* shoot(QPointF marioPosition);
};

#endif // BILLBLASTER_H
