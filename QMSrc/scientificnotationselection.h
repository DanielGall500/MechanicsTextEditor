#ifndef SCIENTIFICNOTATIONSELECTION_H
#define SCIENTIFICNOTATIONSELECTION_H

#include <QObject>
#include <QScrollArea>
#include <QPushButton>
#include <QStringList>

enum SymbolType {
    LowerCaseGreek,
    CapitalGreek
};

class ScientificNotationSelection : public QObject
{
    Q_OBJECT
public:
    explicit ScientificNotationSelection(QObject *parent = 0, SymbolType type = CapitalGreek);
    ~ScientificNotationSelection();

private:
    SymbolType symbolType;
    QScrollArea symbolScrollArea;

    QStringList capitalGreekList;

    QStringList generateSelectionList();


signals:

public slots:
};

#endif // SCIENTIFICNOTATIONSELECTION_H
