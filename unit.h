#ifndef UNIT_H
#define UNIT_H

#include <QObject>

class Unit : public QObject
{
    Q_OBJECT
public:
    explicit Unit(QObject *parent = nullptr);
    explicit Unit(bool isSeaBlock, QObject *parent = nullptr);
    explicit Unit(const Unit& other);
    Unit& operator=(const Unit& u);

    bool getIsSeaBlock();
    bool isExplosed() const;

public slots:
    void setExplosed(bool boom);
private:
    bool isSeaBlock;
    bool explosed{false};
};

#endif // UNIT_H
