#include "scientificnotationselection.h"

ScientificNotationSelection::ScientificNotationSelection(QObject *parent, SymbolType type) : QObject(parent)
{
    symbolType = type;

    capitalGreekList = (QStringList() << "Γ" << "Δ" << "Λ" << "Ξ" << "Π" << "Σ" << "Φ" << "Ψ" << "Ω");
}

ScientificNotationSelection::~ScientificNotationSelection()
{

}


QStringList ScientificNotationSelection::generateSelectionList()
{
    if(symbolType == CapitalGreek)
        return capitalGreekList;
}

