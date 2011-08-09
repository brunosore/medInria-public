#ifndef MEDABSTRACTDATASOURCE_H
#define MEDABSTRACTDATASOURCE_H

#include <QWidget>
#include <QtCore>
#include "medCoreExport.h"

class medToolBox;
class medDataIndex;
class dtkAbstractData;

/** 
 * @class medAbstractDataSource
 * @brief Abstract base class for dynamic data sources, e.g. plugins that act as database clients
 * This class defines access methods to the following widgets: a mainViewWidget, 
 * a source selection widget and several toolboxes.
 * All dynamic data source implementation should derive from this class.
 **/
class MEDCORE_EXPORT medAbstractDataSource : public QWidget
{
    Q_OBJECT
    
public:
    medAbstractDataSource(QWidget *parent = 0);
    ~medAbstractDataSource(void);

    /** 
    * Returns the main view widget 
    * This widget is used to navigate within the data, e.g. a qTreeWidget
    */
    virtual QWidget *mainViewWidget() = 0;
    
    /** 
    * Returns the source selector widget 
    * A widget that let's the user choose between different data locations
    */
    virtual QWidget *sourceSelectorWidget() = 0;
    
    /** Returns the tab name for the plugin using the data source*/
    virtual QString tabName() = 0;
  
    /** Returns all toolboxes owned by the source data plugin*/
    virtual QList<medToolBox*> getToolboxes() = 0;

signals:
    /** A source data may emit a signal to a file on disk when it successfully received the data and is ready for importing*/
    void dataToImportReceived(QString pathToData);

    /** A source data may emit a signal to a file on disk when it successfully received the data and is ready for indexing*/
    void dataToIndexReceived(QString pathToData);
    
    /** A source data may emit a signal to a dtkabstractdata in memory when it successfully received the data and is ready for importing*/
    void dataReceived(dtkAbstractData *data);
    
    /** A data source emits a signal when it failed to get the data*/
    void dataReceivingFailed(QString pathToData);

    /**
     * @brief Emits this signal when the source wants to export some data to a file.
     *
     * The medBrowserArea will treat the demand based on the medDataIndex.
     * @param index
    */
    void exportData(const medDataIndex& index);

    /** emitted when the source is about to remove a data.*/
    void dataRemoved(const medDataIndex& index);
};

#endif