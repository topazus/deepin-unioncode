#include "abstractmenubar.h"
#include "abstractmenu.h"
#include "abstractaction.h"

#include <QMenuBar>
#include <QDebug>

class AbstractMenuBarPrivate
{
    friend class AbstractMenuBar;
    QMenuBar *menuBar;
};

AbstractMenuBar::~AbstractMenuBar()
{
    if (d) {
        delete d;
    }
}

void *AbstractMenuBar::qMenuBar()
{
    return d->menuBar;
}

AbstractMenuBar::AbstractMenuBar(void *qMenuBar)
    : d(new AbstractMenuBarPrivate())
{
    if (!qMenuBar) {
        qCritical() << "Failed, use QMenuBar(0x0) to AbstractMenuBar";
        abort();
    }

    d->menuBar = (QMenuBar*)qMenuBar;
    QMenuBar::connect(d->menuBar, &QMenuBar::destroyed,
                      d->menuBar, [this]() {
        delete this;
    }, Qt::UniqueConnection);
}
