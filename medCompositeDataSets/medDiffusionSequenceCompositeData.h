// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#ifndef DIFFUSIONSEQUENCECOMPOSITEDATA_H
#define DIFFUSIONSEQUENCECOMPOSITEDATA_H

#include <dtkCore/dtkAbstractData.h>
#include <medCompositeDataSetsPluginExport.h>
#include <medCompositeDataSetsBase.h>
#include <itkGradientFileReader.h>

class medDiffusionSequenceCompositeDataToolBox;

class MEDCOMPOSITEDATASETSPLUGIN_EXPORT medDiffusionSequenceCompositeData: public MedInria::medCompositeDataSetsBase {

    typedef itk::GradientFileReader            GradientReaderType;
    typedef GradientReaderType::VectorType     GradientType;
    typedef GradientReaderType::VectorListType GradientListType;
    typedef QVector<dtkAbstractData*>          Volumes;

public:

    friend class medDiffusionSequenceCompositeDataToolBox;

    medDiffusionSequenceCompositeData(): MedInria::medCompositeDataSetsBase(Tag,this),vers(defaultVersion) { }
    virtual ~medDiffusionSequenceCompositeData() { }

    virtual QString description() const;

    virtual bool has_version(const unsigned num) const { return num==0; }

    virtual MedInria::medCompositeDataSetsBase* clone(const int v) const {
        const unsigned version = (v==-1) ? defaultVersion : v;
        return new medDiffusionSequenceCompositeData(version);
    }

    virtual QString  tag()     const { return Tag;  }
    virtual unsigned version() const { return vers; }

    bool registered() const;

    virtual bool read_description(const QByteArray& buf);
    virtual bool read_data();

    virtual bool write_description(QTextStream& file);
    virtual bool write_data(const QString&,const dtkAbstractData*);

    //  Methods specific to this type.

    void readVolumes(QStringList);
    void setGradientList(const GradientListType& grads) { gradients = grads; }
    void setVolumeList(const Volumes& vols)             { images = vols;     }

private:

    medDiffusionSequenceCompositeData(const unsigned v): MedInria::medCompositeDataSetsBase(Tag,this), vers(v) { }

    const unsigned   vers;
    QStringList      image_list;
    Volumes          images;
    GradientListType gradients;

    static const medDiffusionSequenceCompositeData proto;

    static const char     Tag[];
    static const unsigned defaultVersion = 0;
};

dtkAbstractData* createDiffusionSequenceCompositeData();

#endif
