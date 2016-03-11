#include "scientificnotationselection.h"

ScientificNotationSelection::ScientificNotationSelection(QObject *parent) : QObject(parent)
{
    capitalGreekList = (QStringList() << "Γ" << "Δ" << "Λ" << "Ξ" << "Π" << "Σ" << "Φ" << "Ψ" << "Ω");

    notationWidgetCollection = new QVector<QPushButton*>();
}

ScientificNotationSelection::~ScientificNotationSelection()
{

}


QStringList ScientificNotationSelection::generateSelectionList(SymbolType type)
{
    symbolType = type;

    if(symbolType == CapitalGreek)
        return capitalGreekList;
}

QVector<QPushButton *> ScientificNotationSelection::generateWidgets(QStringList &symbols, QScrollArea *parent)
{
    foreach(QString symbol, symbols)
    {
        QPushButton *symbolButton = new QPushButton(symbol, parent);
        notationWidgetCollection->append(symbolButton);
    }
    return *notationWidgetCollection;
}
