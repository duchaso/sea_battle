#include "unit.h"

Unit::Unit(QObject *parent) : QObject{parent}
{
}

Unit::Unit(bool isSeaBlock, QObject *parent) : QObject{parent}, isSeaBlock{isSeaBlock}
{
}

Unit::Unit(const Unit &other)
    : isSeaBlock{other.isSeaBlock},
      explosed{other.explosed}
{
}

Unit &Unit::operator=(const Unit& u)
{
    if(this == &u) return *this;
    isSeaBlock = u.isSeaBlock;
    explosed = u.explosed;
    return *this;
}

bool Unit::getIsSeaBlock()
{
    return isSeaBlock;
}

void Unit::setExplosed(bool boom)
{
    if(explosed != boom)
    {
        explosed = boom;
    }
}

bool Unit::isExplosed() const
{
    return explosed;
}

