#include "sendevents.h"
#include "framework.h"
#include "common/util/eventdefinitions.h"

void SendEvents::treeViewDoublueClicked(const QString &filePath)
{
    dpf::Event event;
    event.setTopic(T_FILEBROWSER);
    event.setData("Item.DoubleClicked");
    event.setProperty("FilePath", filePath);
    dpf::EventCallProxy::instance().pubEvent(event);
}

void SendEvents::buildProject(const QString &buildSystem,
                              const QString &buildDir,
                              const QString &buildFilePath,
                              const QStringList &buildArgs)
{
    dpf::Event event;
    event.setTopic(T_FILEBROWSER);
    event.setData(D_ITEM_MENU_BUILD);
    event.setProperty(P_BUILDSYSTEM, buildSystem);
    event.setProperty(P_BUILDDIRECTORY, buildDir);
    event.setProperty(P_BUILDFILEPATH, buildFilePath);
    event.setProperty(P_BUILDARGUMENTS, buildArgs);
    qInfo() << __FUNCTION__ << event;
    dpf::EventCallProxy::instance().pubEvent(event);
}
