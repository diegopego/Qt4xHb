/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QWebElement>

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbapierr.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#define ISNIL HB_ISNIL
#define ISLOG HB_ISLOG
#define ISNUM HB_ISNUM
#define ISCHAR HB_ISCHAR
#define ISPOINTER HB_ISPOINTER
#define ISOBJECT HB_ISOBJECT
#define ISARRAY HB_ISARRAY
#endif
#include "qt4xhb_clsid.h"
#include "qt4xhb_utils.h"

/*
QWebElement ()
*/
HB_FUNC( QWEBELEMENT_NEW1 )
{
  QWebElement * o = NULL;
  o = new QWebElement (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWebElement *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QWebElement ( const QWebElement & other )
*/
HB_FUNC( QWEBELEMENT_NEW2 )
{
  QWebElement * o = NULL;
  QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QWebElement ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QWebElement *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QWebElement ()
//[2]QWebElement ( const QWebElement & other )

HB_FUNC( QWEBELEMENT_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QWEBELEMENT_DELETE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    delete obj;
    obj = NULL;
    PHB_ITEM self = hb_stackSelfItem();
    PHB_ITEM ptr = hb_itemPutPtr( NULL, NULL );
    hb_objSendMsg( self, "_pointer", 1, ptr );
    hb_itemRelease( ptr );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void addClass ( const QString & name )
*/
HB_FUNC( QWEBELEMENT_ADDCLASS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->addClass ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void appendInside ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_APPENDINSIDE1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->appendInside ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void appendInside ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_APPENDINSIDE2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->appendInside ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void appendInside ( const QString & markup )
//[2]void appendInside ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_APPENDINSIDE )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_APPENDINSIDE1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_APPENDINSIDE2 );
  }
}

/*
void appendOutside ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_APPENDOUTSIDE1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->appendOutside ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void appendOutside ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_APPENDOUTSIDE2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->appendOutside ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void appendOutside ( const QString & markup )
//[2]void appendOutside ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_APPENDOUTSIDE )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_APPENDOUTSIDE1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_APPENDOUTSIDE2 );
  }
}

/*
QString attribute ( const QString & name, const QString & defaultValue = QString() ) const
*/
HB_FUNC( QWEBELEMENT_ATTRIBUTE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    QString str1 = obj->attribute ( par1, par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString attributeNS ( const QString & namespaceUri, const QString & name, const QString & defaultValue = QString() ) const
*/
HB_FUNC( QWEBELEMENT_ATTRIBUTENS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QString par3 = ISNIL(3)? QString() : hb_parc(3);
    QString str1 = obj->attributeNS ( par1, par2, par3 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QStringList attributeNames ( const QString & namespaceUri = QString() ) const
*/
HB_FUNC( QWEBELEMENT_ATTRIBUTENAMES )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = ISNIL(1)? QString() : hb_parc(1);
    QStringList strl = obj->attributeNames ( par1 );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QStringList classes () const
*/
HB_FUNC( QWEBELEMENT_CLASSES )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QStringList strl = obj->classes (  );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<strl.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutC( NULL, (const char *) strl[i].toLatin1().data() );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QWebElement clone () const
*/
HB_FUNC( QWEBELEMENT_CLONE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->clone (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QWebElement document () const
*/
HB_FUNC( QWEBELEMENT_DOCUMENT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->document (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
void encloseContentsWith ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_ENCLOSECONTENTSWITH1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->encloseContentsWith ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void encloseContentsWith ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_ENCLOSECONTENTSWITH2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->encloseContentsWith ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void encloseContentsWith ( const QWebElement & element )
//[2]void encloseContentsWith ( const QString & markup )

HB_FUNC( QWEBELEMENT_ENCLOSECONTENTSWITH )
{
  if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_ENCLOSECONTENTSWITH1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_ENCLOSECONTENTSWITH2 );
  }
}

/*
void encloseWith ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_ENCLOSEWITH1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->encloseWith ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void encloseWith ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_ENCLOSEWITH2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->encloseWith ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void encloseWith ( const QString & markup )
//[2]void encloseWith ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_ENCLOSEWITH )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_ENCLOSEWITH1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_ENCLOSEWITH2 );
  }
}

/*
QVariant evaluateJavaScript ( const QString & scriptSource )
*/
HB_FUNC( QWEBELEMENT_EVALUATEJAVASCRIPT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QVariant * ptr = new QVariant( obj->evaluateJavaScript ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QVARIANT", true );  }
}


/*
QWebElementCollection findAll ( const QString & selectorQuery ) const
*/
HB_FUNC( QWEBELEMENT_FINDALL )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QWebElementCollection * ptr = new QWebElementCollection( obj->findAll ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENTCOLLECTION", true );  }
}


/*
QWebElement findFirst ( const QString & selectorQuery ) const
*/
HB_FUNC( QWEBELEMENT_FINDFIRST )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QWebElement * ptr = new QWebElement( obj->findFirst ( par1 ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QWebElement firstChild () const
*/
HB_FUNC( QWEBELEMENT_FIRSTCHILD )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->firstChild (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QRect geometry () const
*/
HB_FUNC( QWEBELEMENT_GEOMETRY )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect * ptr = new QRect( obj->geometry (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRECT", true );  }
}


/*
bool hasAttribute ( const QString & name ) const
*/
HB_FUNC( QWEBELEMENT_HASATTRIBUTE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->hasAttribute ( par1 );
    hb_retl( b );
  }
}


/*
bool hasAttributeNS ( const QString & namespaceUri, const QString & name ) const
*/
HB_FUNC( QWEBELEMENT_HASATTRIBUTENS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    bool b = obj->hasAttributeNS ( par1, par2 );
    hb_retl( b );
  }
}


/*
bool hasAttributes () const
*/
HB_FUNC( QWEBELEMENT_HASATTRIBUTES )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasAttributes (  );
    hb_retl( b );
  }
}


/*
bool hasClass ( const QString & name ) const
*/
HB_FUNC( QWEBELEMENT_HASCLASS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool b = obj->hasClass ( par1 );
    hb_retl( b );
  }
}


/*
bool hasFocus () const
*/
HB_FUNC( QWEBELEMENT_HASFOCUS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasFocus (  );
    hb_retl( b );
  }
}


/*
bool isNull () const
*/
HB_FUNC( QWEBELEMENT_ISNULL )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->isNull (  );
    hb_retl( b );
  }
}


/*
QWebElement lastChild () const
*/
HB_FUNC( QWEBELEMENT_LASTCHILD )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->lastChild (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QString localName () const
*/
HB_FUNC( QWEBELEMENT_LOCALNAME )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->localName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString namespaceUri () const
*/
HB_FUNC( QWEBELEMENT_NAMESPACEURI )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->namespaceUri (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QWebElement nextSibling () const
*/
HB_FUNC( QWEBELEMENT_NEXTSIBLING )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->nextSibling (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QWebElement parent () const
*/
HB_FUNC( QWEBELEMENT_PARENT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->parent (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
QString prefix () const
*/
HB_FUNC( QWEBELEMENT_PREFIX )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->prefix (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void prependInside ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_PREPENDINSIDE1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->prependInside ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void prependInside ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_PREPENDINSIDE2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->prependInside ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void prependInside ( const QString & markup )
//[2]void prependInside ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_PREPENDINSIDE )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_PREPENDINSIDE1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_PREPENDINSIDE2 );
  }
}

/*
void prependOutside ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_PREPENDOUTSIDE1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->prependOutside ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void prependOutside ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_PREPENDOUTSIDE2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->prependOutside ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void prependOutside ( const QString & markup )
//[2]void prependOutside ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_PREPENDOUTSIDE )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_PREPENDOUTSIDE1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_PREPENDOUTSIDE2 );
  }
}

/*
QWebElement previousSibling () const
*/
HB_FUNC( QWEBELEMENT_PREVIOUSSIBLING )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = new QWebElement( obj->previousSibling (  ) );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT", true );  }
}


/*
void removeAllChildren ()
*/
HB_FUNC( QWEBELEMENT_REMOVEALLCHILDREN )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->removeAllChildren (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeAttribute ( const QString & name )
*/
HB_FUNC( QWEBELEMENT_REMOVEATTRIBUTE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->removeAttribute ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeAttributeNS ( const QString & namespaceUri, const QString & name )
*/
HB_FUNC( QWEBELEMENT_REMOVEATTRIBUTENS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->removeAttributeNS ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeClass ( const QString & name )
*/
HB_FUNC( QWEBELEMENT_REMOVECLASS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->removeClass ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void removeFromDocument ()
*/
HB_FUNC( QWEBELEMENT_REMOVEFROMDOCUMENT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->removeFromDocument (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void render ( QPainter * painter )
*/
HB_FUNC( QWEBELEMENT_RENDER1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->render ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void render ( QPainter * painter, const QRect & clip )
*/
HB_FUNC( QWEBELEMENT_RENDER2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QPainter * par1 = (QPainter *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QRect * par2 = (QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->render ( par1, *par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void render ( QPainter * painter )
//[2]void render ( QPainter * painter, const QRect & clip )

HB_FUNC( QWEBELEMENT_RENDER )
{
  if( ISNUMPAR(1) && ISQPAINTER(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_RENDER1 );
  }
  else if( ISNUMPAR(2) && ISQPAINTER(1) && ISQRECT(2) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_RENDER2 );
  }
}

/*
void replace ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_REPLACE1 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->replace ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void replace ( const QWebElement & element )
*/
HB_FUNC( QWEBELEMENT_REPLACE2 )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * par1 = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->replace ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void replace ( const QString & markup )
//[2]void replace ( const QWebElement & element )

HB_FUNC( QWEBELEMENT_REPLACE )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_REPLACE1 );
  }
  else if( ISNUMPAR(1) && ISQWEBELEMENT(1) )
  {
    HB_FUNC_EXEC( QWEBELEMENT_REPLACE2 );
  }
}

/*
void setAttribute ( const QString & name, const QString & value )
*/
HB_FUNC( QWEBELEMENT_SETATTRIBUTE )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->setAttribute ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAttributeNS ( const QString & namespaceUri, const QString & name, const QString & value )
*/
HB_FUNC( QWEBELEMENT_SETATTRIBUTENS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QString par3 = hb_parc(3);
    obj->setAttributeNS ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setFocus ()
*/
HB_FUNC( QWEBELEMENT_SETFOCUS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->setFocus (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setInnerXml ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_SETINNERXML )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setInnerXml ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOuterXml ( const QString & markup )
*/
HB_FUNC( QWEBELEMENT_SETOUTERXML )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setOuterXml ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPlainText ( const QString & text )
*/
HB_FUNC( QWEBELEMENT_SETPLAINTEXT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setPlainText ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStyleProperty ( const QString & name, const QString & value )
*/
HB_FUNC( QWEBELEMENT_SETSTYLEPROPERTY )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->setStyleProperty ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QString styleProperty ( const QString & name, StyleResolveStrategy strategy ) const
*/
HB_FUNC( QWEBELEMENT_STYLEPROPERTY )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    int par2 = hb_parni(2);
    QString str1 = obj->styleProperty ( par1,  (QWebElement::StyleResolveStrategy) par2 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString tagName () const
*/
HB_FUNC( QWEBELEMENT_TAGNAME )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->tagName (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QWebElement & takeFromDocument ()
*/
HB_FUNC( QWEBELEMENT_TAKEFROMDOCUMENT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebElement * ptr = &obj->takeFromDocument (  );
    _qt4xhb_createReturnClass ( ptr, "QWEBELEMENT" );  }
}


/*
QString toInnerXml () const
*/
HB_FUNC( QWEBELEMENT_TOINNERXML )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toInnerXml (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString toOuterXml () const
*/
HB_FUNC( QWEBELEMENT_TOOUTERXML )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toOuterXml (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QString toPlainText () const
*/
HB_FUNC( QWEBELEMENT_TOPLAINTEXT )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->toPlainText (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
void toggleClass ( const QString & name )
*/
HB_FUNC( QWEBELEMENT_TOGGLECLASS )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->toggleClass ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QWebFrame * webFrame () const
*/
HB_FUNC( QWEBELEMENT_WEBFRAME )
{
  QWebElement * obj = (QWebElement *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWebFrame * ptr = obj->webFrame (  );
    _qt4xhb_createReturnClass ( ptr, "QWEBFRAME" );  }
}



