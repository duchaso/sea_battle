#include "boardmodel.h"


BoardModel::BoardModel(QObject *parent)
    : QAbstractListModel{parent}
{
    loadModel("D:/dev/SeaBattle/data/file.txt");
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    return model.count();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if ( !index.isValid() || index.row() < 0 || index.row() >= model.count() )
        return QVariant();
    Unit modelEntry(model[index.row()]);
    if(role == CellRole) return modelEntry.getIsSeaBlock();
    if(role == ExplosedRole) return modelEntry.isExplosed();
    return QVariant();
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CellRole] = "CellType";
    roles[ExplosedRole] = "ExploseType";
    return roles;
}

void BoardModel::explose(int index)
{
    if(model[index].getIsSeaBlock())
    {
        if(!(model[index].isExplosed()))
        {
            model[index].setExplosed(true);
            qDebug() << "Ship on cell " << index%10+1 << " " << index/10+1 << " has been destroyed!";
            QModelIndex topLeft = createIndex(index,0);
            emit dataChanged(topLeft, topLeft);
        }
    }
}

void BoardModel::loadModel(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString ch = in.read(1);
        if(ch == "\n") continue;
        bool zo = ch.toInt();
        Unit u(zo);
        model << u;
    }

}


