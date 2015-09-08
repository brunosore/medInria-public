// Version: $Id$
// 
// 

// Commentary: 
// 
// 

// Change Log:
// 
// 

// Code:

#include "medComposerFactoryExtension.h"

//include nodes
#include "medReaderNodeBase.h"
#include "medWriterNodeBase.h"


// ///////////////////////////////////////////////////////////////////
// 
// ///////////////////////////////////////////////////////////////////

medComposerFactoryExtension::medComposerFactoryExtension(void) : dtkComposerNodeFactoryExtension()
{

}

medComposerFactoryExtension::~medComposerFactoryExtension(void)
{

}

void medComposerFactoryExtension::extend(dtkComposerNodeFactory *factory)
{//record the new nodes
    factory->record(":json/medGenericReaderNode.json", dtkComposerNodeCreator< medGenericReaderNode>);
    factory->record(":json/medImageReaderNode.json"  , dtkComposerNodeCreator< medImageReaderNode  >);
    factory->record(":json/medMeshReaderNode.json"   , dtkComposerNodeCreator< medMeshReaderNode   >);
    factory->record(":json/medGenericWriterNode.json"   , dtkComposerNodeCreator< medWriterNodeBase   >);

}

// 
// medComposerFactoryExtension.cpp ends here