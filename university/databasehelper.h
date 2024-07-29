#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <QObject>
#include <QSqlDatabase>

class DatabaseHelper : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHelper(QObject *parent = nullptr);
    void setupDatabase();
    bool addStudent(const QString &rollNo, const QString &name, const QString &subject);
    bool findStudent(const QString &rollNo, QString &name, QString &subject);
    bool updateStudent(const QString &rollNo, const QString &subject);
};

#endif // DATABASEHELPER_H
