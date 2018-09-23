#ifndef TRINITY_DBEDIT_CLICKABLELABEL_H
#define TRINITY_DBEDIT_CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT

    public:
        ClickableLabel(QString const& str, QWidget* parent = nullptr) : QLabel(str, parent) {}

    protected:
        void mouseReleaseEvent(QMouseEvent*) override { Q_EMIT Clicked(); }

    Q_SIGNALS:
        void Clicked();
};

#endif
