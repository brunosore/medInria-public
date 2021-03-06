/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <QtGui>
#include <QUuid>
#include <QtWidgets>

#include <medCoreLegacyExport.h>

class medAbstractData;
class medAbstractView;
class medDataIndex;
class medViewContainer;
class medViewContainerSplitter;
class medAbstractWorkspaceLegacy;
class medTabbedViewContainersPrivate;

/**
 * @brief A QStackedWidget that contains medViewContainers.
 * There is one such stack per medViewWorkspace.
 *
*/
class MEDCORELEGACY_EXPORT medTabbedViewContainers : public QTabWidget
{
    Q_OBJECT

public:
     medTabbedViewContainers(medAbstractWorkspaceLegacy* owningWorkspace, QWidget *parent = 0);
    ~medTabbedViewContainers();

    void lockTabs();
    void unlockTabs();
    void hideTabBar();
    QList<QUuid> containersSelected();
    void adjustContainersSize();
    QList<medAbstractView*> viewsInTab(int index = 0);
    QList<medViewContainer*> containersInTab(int index = 0);

    medAbstractWorkspaceLegacy * owningWorkspace() const;

public slots:
    medViewContainer* addContainerInTab();
    medViewContainer* addContainerInTab(const QString &name);
    medViewContainer* insertContainerInTab(int index, const QString &name);
    // TODO mutualize all of this
    void setSplitter(int index, medViewContainerSplitter* splitter);

    void closeCurrentTab();
    void closeTab(int index);

protected:


private slots:
    void disconnectTabFromSplitter(int index);
    void repopulateCurrentTab();
    void addContainerToSelection(QUuid container);
    void removeContainerFromSelection(QUuid container);
    void connectContainer(QUuid container);
    void buildTemporaryPool();
    void connectContainerSelectedForCurrentTab();
    void minimizeOtherContainers(QUuid containerMaximized, bool maximized);
    void minimizeSplitterContainers(QUuid containerMaximized, bool maximized,
                                                             medViewContainerSplitter *splitter);
    // Not sure of the name - RDE
    void resetTabState();

signals:
    void containersSelectedChanged();

private:
    medTabbedViewContainersPrivate *d;
};


