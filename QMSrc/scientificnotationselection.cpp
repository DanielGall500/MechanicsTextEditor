#include "scientificnotationselection.h"

ScientificNotationSelection::ScientificNotationSelection(QObject *parent) : QObject(parent)
{
    capitalGreekList = (QStringList() << "Γ" << "Δ" << "Λ" << "Ξ" << "Π" << "Σ" << "Φ" << "Ψ" << "Ω");
    mathematicalList = (QStringList() << "+" << "-" << "÷" << "×" << "%" << "(" << ")" << "sin" << "cos" << "tan" << "π" );

    notationWidgetCollection = new QVector<QPushButton*>();
}

ScientificNotationSelection::~ScientificNotationSelection()
{

}

QVector<QPushButton *> ScientificNotationSelection::generateWidgets(QStringList &symbols, QScrollArea *parent)
{
    notationWidgetCollection->clear();

    foreach(QString symbol, symbols)
    {
        QPushButton *symbolButton = new QPushButton(symbol, parent);

        QFont buttonFont = symbolButton->font();
        buttonFont.setPointSize(22);
        buttonFont.setBold(false);
        symbolButton->setFont(buttonFont);

        notationWidgetCollection->append(symbolButton);
    }
    return *notationWidgetCollection;
}



