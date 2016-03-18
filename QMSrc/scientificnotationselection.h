#ifndef SCIENTIFICNOTATIONSELECTION_H
#define SCIENTIFICNOTATIONSELECTION_H

#include <QObject>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>
#include <QVector>
#include <QPoint>
#include <cstdlib>
#include <QSharedPointer>
#include <QTextEdit>
#include <iostream>

enum SymbolType {
    LowerCaseGreek,
    CapitalGreek
};

class ScientificNotationSelection : public QObject
{
    Q_OBJECT
public:
    explicit ScientificNotationSelection(QObject *parent = 0);
    ~ScientificNotationSelection();

    QVector<QPushButton *> generateWidgets(QStringList &symbols, QScrollArea *parent = 0);

    QStringList getCapitalGreekList() { return capitalGreekList; }
    QStringList getBasicMathematicalList() { return mathematicalList; }


private:
    SymbolType  symbolType;
    QScrollArea symbolScrollArea;

    //lists
    QStringList capitalGreekList;
    QStringList mathematicalList;

protected:

    QVector<QPushButton*> *notationWidgetCollection;

public slots:
};

#endif // SCIENTIFICNOTATIONSELECTION_H
