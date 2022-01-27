#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QFile>
#include <QDebug>

#include "unit.h"

class BoardModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit BoardModel(QObject *parent = nullptr);

    enum DataRoles {
        CellRole = Qt::UserRole + 1,
        ExplosedRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    void loadModel(QString path);
public slots:
    void explose(int index);

private:
    QList<Unit> model;
};

#endif // BOARDMODEL_H
