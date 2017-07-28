#ifndef IMMUTABLETYPE1_H
#define IMMUTABLETYPE1_H

#include <QObject>
#include <QSharedDataPointer>
#include <QVariant>

class ImmutableType1Data;

class ImmutableType1
{
    Q_GADGET
    Q_PROPERTY(QString id READ id WRITE setId)

public:
    ImmutableType1();
    ImmutableType1(const ImmutableType1 &);
    ImmutableType1 &operator=(const ImmutableType1 &);
    ~ImmutableType1();

    bool isSharedWith(const ImmutableType1& other) const;

    QString id() const;

    void setId(QString id);

    Q_INVOKABLE QString key() const;

private:
    QSharedDataPointer<ImmutableType1Data> data;
};

#endif // IMMUTABLETYPE1_H