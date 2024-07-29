#include "databasehelper.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseHelper::DatabaseHelper(QObject *parent) : QObject(parent)
{
}

void DatabaseHelper::setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("students.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";

        // Create table if not exist
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS students (rollNo TEXT PRIMARY KEY, name TEXT, subject TEXT)");
    }
}

bool DatabaseHelper::addStudent(const QString &rollNo, const QString &name, const QString &subject)
{
    QSqlQuery query;
    query.prepare("INSERT INTO students (rollNo, name, subject) VALUES (:rollNo, :name, :subject)");
    query.bindValue(":rollNo", rollNo);
    query.bindValue(":name", name);
    query.bindValue(":subject", subject);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Add student failed: " << query.lastError();
        return false;
    }
}

bool DatabaseHelper::findStudent(const QString &rollNo, QString &name, QString &subject)
{
    QSqlQuery query;
    query.prepare("SELECT name, subject FROM students WHERE rollNo = :rollNo");
    query.bindValue(":rollNo", rollNo);

    if (query.exec()) {
        if (query.next()) {
            name = query.value(0).toString();
            subject = query.value(1).toString();
            return true;
        } else {
            return false;
        }
    } else {
        qDebug() << "Find student failed: " << query.lastError();
        return false;
    }
}

bool DatabaseHelper::updateStudent(const QString &rollNo, const QString &subject)
{
    QSqlQuery query;
    query.prepare("UPDATE students SET subject = :subject WHERE rollNo = :rollNo");
    query.bindValue(":subject", subject);
    query.bindValue(":rollNo", rollNo);

    if (query.exec()) {
        return query.numRowsAffected() > 0;
    } else {
        qDebug() << "Update student failed: " << query.lastError();
        return false;
    }
}
