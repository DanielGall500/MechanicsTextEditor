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

void ScientificNotationSelection::generateWidgets(QStringList &symbols, QScrollArea *parent)
{
    for (unsigned int i = 0; i <= symbols.length(); i++)
    {
        symbolButton = new QPushButton(symbols[i]);

        symbolButton->setMaximumWidth(parent->width() / 10);
        symbolButton->setMaximumHeight(parent->height() / 20);

        notationWidgetCollection->append(symbolButton);
    }
}

