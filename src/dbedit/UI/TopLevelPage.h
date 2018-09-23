#ifndef TRINITY_DBEDIT_TOPLEVELPAGE_H
#define TRINITY_DBEDIT_TOPLEVELPAGE_H

#include <QWidget>

class TopLevelPage : public QWidget
{
    public:
        TopLevelPage(QWidget* parent) : QWidget(parent) {}
        virtual void Setup() = 0;
};

#endif
