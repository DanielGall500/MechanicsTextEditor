#include "scientificnotationselection.h"

ScientificNotationSelection::ScientificNotationSelection(QObject *parent) : QObject(parent)
{
    advancedSymbols = (QStringList() << "Σ");

    capitalGreekList = (QStringList() << "Γ" << "Δ" << "Λ" << "Ξ" << "Π" << "Σ" << "Φ" << "Ψ" << "Ω");

    lowercaseGreekList = (QStringList() << "α" << "β" << "γ" << "δ" << "ε" << "ζ" << "η" << "θ" << "κ" << "λ" << "μ"
                                        << "ν" << "ξ" << "π" << "ρ" << "σ" << "τ" << "υ" << "φ" << "χ" << "ψ" << "ω");

    mathematicalList = (QStringList() << "+" << "-" << "÷" << "×" << "±" << "%" << "(" << ")" << "=" << "≈"
                                      << "≠" << "∝" << "~" << "<" << ">" << "≤" << "≥" << "∴" << "∞");

    advMathematicalList = (QStringList() << "X!" << "ln(" << "log(" << "√(" << "∛" << "x^y(TODO)" << "sin(" << "cos(" << "tan("
                                         << "EXP" << "Inv(TODO)" << "π" << "e" << "∥" << "⊥" << "∫" << "∬" << "∭" << "∮" << "∯" << "∰");

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














