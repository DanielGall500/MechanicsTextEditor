#ifndef SCIENTIFICNOTATIONSELECTION_H
#define SCIENTIFICNOTATIONSELECTION_H

#include <QObject>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>
#include <QVector>
#include <QPoint>

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

    void generateWidgets(QStringList &symbols, QScrollArea *parent = 0);

    QStringList generateSelectionList(SymbolType type = CapitalGreek);

    QVector<QPushButton*> *notationWidgetCollection;


private:
    SymbolType  symbolType;
    QScrollArea symbolScrollArea;
    QStringList capitalGreekList;

    QPushButton *symbolButton;


signals:

public slots:
};

#endif // SCIENTIFICNOTATIONSELECTION_H
