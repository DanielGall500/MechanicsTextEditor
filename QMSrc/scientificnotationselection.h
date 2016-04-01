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

    QStringList getAdvancedSymbols() { return advancedSymbols; }

private:
    QScrollArea symbolScrollArea;

    //lists
    QStringList advancedSymbols;
    QStringList capitalGreekList;
    QStringList lowercaseGreekList;
    QStringList mathematicalList;
    QStringList advMathematicalList;

protected:

    QVector<QPushButton*> *notationWidgetCollection;

public slots:

};

#endif // SCIENTIFICNOTATIONSELECTION_H
