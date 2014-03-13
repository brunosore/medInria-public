/*=========================================================================

 medInria

 Copyright (c) INRIA 2013. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medToolBox.h>
#include <medGuiExport.h>
#include <medJobItem.h>

class dtkAbstractView;
class dtkAbstractProcess;
class medAbstractImageView;
class medAbstractImageData;
class medDataIndex;
class medRegistrationSelectorToolBoxPrivate;
class medAbstractProcess;

class MEDGUI_EXPORT medRegistrationSelectorToolBox : public medToolBox
{
    Q_OBJECT

public:
     medRegistrationSelectorToolBox(QWidget *parent = 0);
    ~medRegistrationSelectorToolBox();

    medAbstractData *fixedData();
    medAbstractData *movingData();

    medAbstractProcess * process();
    void setProcess(medAbstractProcess *process);

    medAbstractProcess * undoRedoProcess();
    void setUndoRedoProcess(medAbstractProcess *proc);

    QString getNameOfCurrentAlgorithm();

    void setFixedData(medAbstractData* data);
    void setMovingData(medAbstractData* data);

    enum typeOfOperation { algorithm, undo, redo, reset };

signals:
    void showError (const QString&,unsigned int timeout);
    void showInfo(const QString&,unsigned int timeout);
    void movingDataRegistered(medAbstractData *output);

public slots:

    void changeCurrentToolBox(int index);
    void clear();
    void onSaveTrans();
    void handleOutput(typeOfOperation type=algorithm,QString algoName="");
    void enableSelectorToolBox(bool enable = true);
    void onJobAdded(medJobItem* item, QString jobName);

private:
    medRegistrationSelectorToolBoxPrivate *d;
};


