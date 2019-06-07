/*
 * Copyright 2006 Sony Computer Entertainment Inc.
 *
 * Licensed under the MIT Open Source License, for details please see license.txt or the website
 * http://www.opensource.org/licenses/mit-license.php
 *
 */
#include <dae.h>
#include <dae/daeDom.h>
#include <dae/daeMetaElement.h>
#include <dom.h>

#include <dom/domAny.h>
#include <dom/domSource.h>
#include <dom/domCOLLADA.h>
#include <dom/domConstants.h>

daeMetaElement* initializeDomMeta(DAE& dae, const char* specversion)
{
    if( specversion == NULL || strcmp(specversion,"1.4.1") == 0 ) {
        ColladaDOM141::registerDomTypes(dae);
        return ColladaDOM141::registerDomElements(dae);
    }
    return NULL;
}

daeInt GetColladaTypeCount(const char* specversion)
{
    if( specversion == NULL || strcmp(specversion,"1.4.1") == 0 ) {
        return ColladaDOM141::colladaTypeCount();
    }
    return 0;
}

daeString GetCOLLADA_VERSION(const char* specversion)
{
    if( specversion == NULL || strcmp(specversion,"1.4.1") == 0 ) {
        return ColladaDOM141::COLLADA_VERSION;
    }
    return "";
}

daeString GetCOLLADA_NAMESPACE(const char* specversion)
{
    if( specversion == NULL || strcmp(specversion,"1.4.1") == 0 ) {
        return ColladaDOM141::COLLADA_NAMESPACE;
    }
    return "";
}

daeMetaElement * registerElementAny(DAE& dae)
{
    if( strcmp(dae.getDomVersion(),"1.4.1") == 0 ) {
        return ColladaDOM141::domAny::registerElement(dae);
    }
    return NULL;
}

daeInt getDomAnyID(DAE& dae)
{
    if( strcmp(dae.getDomVersion(),"1.4.1") == 0 ) {
        return ColladaDOM141::domAny::ID();
    }
    return NULL;
}

daeInt getDomSourceID(DAE& dae)
{
    if( strcmp(dae.getDomVersion(),"1.4.1") == 0 ) {
        return ColladaDOM141::domSource::ID();
    }
    return NULL;
}

daeInt getDomCOLLADAID(const char* specversion)
{
    if( specversion == NULL || strcmp(specversion,"1.4.1") == 0 ) {
        return ColladaDOM141::domCOLLADA::ID();
    }
    return NULL;
}

void copyElementAny(daeElementRef dstAny, daeElement* srcAny)
{
    if( strcmp(srcAny->getDAE()->getDomVersion(),"1.4.1") == 0 ) {
        ColladaDOM141::domAny* thisAny = (ColladaDOM141::domAny*)srcAny;
        ColladaDOM141::domAny* retAny = (ColladaDOM141::domAny*)dstAny.cast();
        for (daeUInt i = 0; i < (daeUInt)thisAny->getAttributeCount(); i++)
            retAny->setAttribute(thisAny->getAttributeName(i), thisAny->getAttributeValue(i));
        retAny->setValue(thisAny->getValue());
    }
}

daeString COLLADA_ELEMENT_TECHNIQUE_COMMON(DAE& dae)
{
    if( strcmp(dae.getDomVersion(),"1.4.1") == 0 ) {
        return ColladaDOM141::COLLADA_ELEMENT_TECHNIQUE_COMMON;
    }
    return daeString();
}

daeString COLLADA_ELEMENT_TECHNIQUE(DAE& dae)
{
    if( strcmp(dae.getDomVersion(),"1.4.1") == 0 ) {
        return ColladaDOM141::COLLADA_ELEMENT_TECHNIQUE;
    }
    return daeString();
}

daeDoubleArray* getDomSourceFloatArray(daeElement* elt)
{
    if( strcmp(elt->getDAE()->getDomVersion(),"1.4.1") == 0 ) {
        if( elt->typeID() == ColladaDOM141::domSource::ID() ) {
            ColladaDOM141::domFloat_array* floatArray = ((ColladaDOM141::domSource*)elt)->getFloat_array();
            if( floatArray != NULL ) {
                return (daeDoubleArray*)floatArray->getCharDataObject()->get(floatArray);
            }
        }
        return NULL;
    }
    return NULL;
}
