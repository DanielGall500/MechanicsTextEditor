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
    QStringList getLowerGreekList() { return lowercaseGreekList; }

    QStringList getBasicMathematicalList() { return mathematicalList; }
    QStringList getAdvancedMathematicalList() { return advMathematicalList; }

private:
    SymbolType  symbolType;
    QScrollArea symbolScrollArea;

    //lists
    QStringList capitalGreekList;
    QStringList lowercaseGreekList;
    QStringList mathematicalList;
    QStringList advMathematicalList;

protected:

    QVector<QPushButton*> *notationWidgetCollection;

public slots:
};

#endif // SCIENTIFICNOTATIONSELECTION_H
