#include "scientificnotationselection.h"

ScientificNotationSelection::ScientificNotationSelection(QObject *parent, SymbolType type) : QObject(parent)
{
    symbolType = &type;
}

ScientificNotationSelection::~ScientificNotationSelection()
{

}

QStringList ScientificNotationSelection::generateSelection(SymbolType type)
{

}

