/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QXmlStreamWriter>

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
QXmlStreamWriter()
*/
HB_FUNC( QXMLSTREAMWRITER_NEW1 )
{
  QXmlStreamWriter * o = NULL;
  o = new QXmlStreamWriter (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamWriter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlStreamWriter(QIODevice * device)
*/
HB_FUNC( QXMLSTREAMWRITER_NEW2 )
{
  QXmlStreamWriter * o = NULL;
  QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlStreamWriter ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamWriter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlStreamWriter(QByteArray * array)
*/
HB_FUNC( QXMLSTREAMWRITER_NEW3 )
{
  QXmlStreamWriter * o = NULL;
  QByteArray * par1 = (QByteArray *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QXmlStreamWriter ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamWriter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


/*
QXmlStreamWriter(QString * string)
*/
HB_FUNC( QXMLSTREAMWRITER_NEW4 )
{
  QXmlStreamWriter * o = NULL;
  QString * par1 = NULL;
  o = new QXmlStreamWriter ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QXmlStreamWriter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  PHB_ITEM des = hb_itemPutL( NULL, true );
  hb_objSendMsg( self, "_SELF_DESTRUCTION", 1, des );
  hb_itemRelease( des );
  hb_itemReturn( self );
}


//[1]QXmlStreamWriter()
//[2]QXmlStreamWriter(QIODevice * device)
//[3]QXmlStreamWriter(QByteArray * array)
//[4]QXmlStreamWriter(QString * string)

HB_FUNC( QXMLSTREAMWRITER_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQIODEVICE(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_NEW2 );
  }
  else if( ISNUMPAR(1) && ISQBYTEARRAY(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_NEW3 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_NEW4 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QXMLSTREAMWRITER_DELETE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
bool autoFormatting() const
*/
HB_FUNC( QXMLSTREAMWRITER_AUTOFORMATTING )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->autoFormatting (  );
    hb_retl( b );
  }
}


/*
int autoFormattingIndent() const
*/
HB_FUNC( QXMLSTREAMWRITER_AUTOFORMATTINGINDENT )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->autoFormattingIndent (  );
    hb_retni( i );
  }
}


/*
QTextCodec * codec() const
*/
HB_FUNC( QXMLSTREAMWRITER_CODEC )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCodec * ptr = obj->codec (  );
    _qt4xhb_createReturnClass ( ptr, "QTEXTCODEC" );  }
}


/*
QIODevice * device() const
*/
HB_FUNC( QXMLSTREAMWRITER_DEVICE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * ptr = obj->device (  );
    _qt4xhb_createReturnClass ( ptr, "QIODEVICE" );  }
}


/*
bool hasError() const
*/
HB_FUNC( QXMLSTREAMWRITER_HASERROR )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->hasError (  );
    hb_retl( b );
  }
}


/*
void setAutoFormatting(bool enable)
*/
HB_FUNC( QXMLSTREAMWRITER_SETAUTOFORMATTING )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setAutoFormatting ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setAutoFormattingIndent(int spacesOrTabs)
*/
HB_FUNC( QXMLSTREAMWRITER_SETAUTOFORMATTINGINDENT )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setAutoFormattingIndent ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCodec(QTextCodec * codec)
*/
HB_FUNC( QXMLSTREAMWRITER_SETCODEC1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QTextCodec * par1 = (QTextCodec *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setCodec ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCodec(const char * codecName)
*/
HB_FUNC( QXMLSTREAMWRITER_SETCODEC2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    const char * par1 = hb_parc(1);
    obj->setCodec (  (const char *) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void setCodec(QTextCodec * codec)
//[2]void setCodec(const char * codecName)

HB_FUNC( QXMLSTREAMWRITER_SETCODEC )
{
  if( ISNUMPAR(1) && ISQTEXTCODEC(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_SETCODEC1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_SETCODEC2 );
  }
}

/*
void setDevice(QIODevice * device)
*/
HB_FUNC( QXMLSTREAMWRITER_SETDEVICE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QIODevice * par1 = (QIODevice *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setDevice ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeAttribute(const QString & namespaceUri, const QString & name, const QString & value)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEATTRIBUTE1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QString par3 = hb_parc(3);
    obj->writeAttribute ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeAttribute(const QString & qualifiedName, const QString & value)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEATTRIBUTE2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->writeAttribute ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeAttribute(const QXmlStreamAttribute & attribute)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEATTRIBUTE3 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlStreamAttribute * par1 = (QXmlStreamAttribute *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->writeAttribute ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void writeAttribute(const QString & namespaceUri, const QString & name, const QString & value)
//[2]void writeAttribute(const QString & qualifiedName, const QString & value)
//[3]void writeAttribute(const QXmlStreamAttribute & attribute)

HB_FUNC( QXMLSTREAMWRITER_WRITEATTRIBUTE )
{
  if( ISNUMPAR(3) && ISCHAR(1) && ISCHAR(2) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITEATTRIBUTE1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITEATTRIBUTE2 );
  }
  else if( ISNUMPAR(1) && ISQXMLSTREAMATTRIBUTE(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITEATTRIBUTE3 );
  }
}

/*
void writeAttributes(const QXmlStreamAttributes & attributes)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEATTRIBUTES )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlStreamAttributes * par1 = (QXmlStreamAttributes *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->writeAttributes ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeCDATA(const QString & text)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITECDATA )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeCDATA ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeCharacters(const QString & text)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITECHARACTERS )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeCharacters ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeComment(const QString & text)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITECOMMENT )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeComment ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeCurrentToken(const QXmlStreamReader & reader)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITECURRENTTOKEN )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QXmlStreamReader * par1 = (QXmlStreamReader *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->writeCurrentToken ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeDTD(const QString & dtd)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEDTD )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeDTD ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeDefaultNamespace(const QString & namespaceUri)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEDEFAULTNAMESPACE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeDefaultNamespace ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeEmptyElement(const QString & namespaceUri, const QString & name)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEEMPTYELEMENT1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->writeEmptyElement ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeEmptyElement(const QString & qualifiedName)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEEMPTYELEMENT2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeEmptyElement ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void writeEmptyElement(const QString & namespaceUri, const QString & name)
//[2]void writeEmptyElement(const QString & qualifiedName)

HB_FUNC( QXMLSTREAMWRITER_WRITEEMPTYELEMENT )
{
  if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITEEMPTYELEMENT1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITEEMPTYELEMENT2 );
  }
}

/*
void writeEndDocument()
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEENDDOCUMENT )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->writeEndDocument (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeEndElement()
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEENDELEMENT )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->writeEndElement (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeEntityReference(const QString & name)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEENTITYREFERENCE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeEntityReference ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeNamespace(const QString & namespaceUri, const QString & prefix = QString())
*/
HB_FUNC( QXMLSTREAMWRITER_WRITENAMESPACE )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    obj->writeNamespace ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeProcessingInstruction(const QString & target, const QString & data = QString())
*/
HB_FUNC( QXMLSTREAMWRITER_WRITEPROCESSINGINSTRUCTION )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = ISNIL(2)? QString() : hb_parc(2);
    obj->writeProcessingInstruction ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeStartDocument(const QString & version)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeStartDocument ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeStartDocument(const QString & version, bool standalone)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    bool par2 = hb_parl(2);
    obj->writeStartDocument ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeStartDocument()
*/
HB_FUNC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT3 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->writeStartDocument (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void writeStartDocument(const QString & version)
//[2]void writeStartDocument(const QString & version, bool standalone)
//[3]void writeStartDocument()

HB_FUNC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT )
{
  if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISLOG(2) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT2 );
  }
  else if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITESTARTDOCUMENT3 );
  }
}

/*
void writeStartElement(const QString & namespaceUri, const QString & name)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITESTARTELEMENT1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->writeStartElement ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeStartElement(const QString & qualifiedName)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITESTARTELEMENT2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->writeStartElement ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void writeStartElement(const QString & namespaceUri, const QString & name)
//[2]void writeStartElement(const QString & qualifiedName)

HB_FUNC( QXMLSTREAMWRITER_WRITESTARTELEMENT )
{
  if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITESTARTELEMENT1 );
  }
  else if( ISNUMPAR(1) && ISCHAR(1) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITESTARTELEMENT2 );
  }
}

/*
void writeTextElement(const QString & namespaceUri, const QString & name, const QString & text)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITETEXTELEMENT1 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    QString par3 = hb_parc(3);
    obj->writeTextElement ( par1, par2, par3 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void writeTextElement(const QString & qualifiedName, const QString & text)
*/
HB_FUNC( QXMLSTREAMWRITER_WRITETEXTELEMENT2 )
{
  QXmlStreamWriter * obj = (QXmlStreamWriter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QString par2 = hb_parc(2);
    obj->writeTextElement ( par1, par2 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


//[1]void writeTextElement(const QString & namespaceUri, const QString & name, const QString & text)
//[2]void writeTextElement(const QString & qualifiedName, const QString & text)

HB_FUNC( QXMLSTREAMWRITER_WRITETEXTELEMENT )
{
  if( ISNUMPAR(3) && ISCHAR(1) && ISCHAR(2) && ISCHAR(3) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITETEXTELEMENT1 );
  }
  else if( ISNUMPAR(2) && ISCHAR(1) && ISCHAR(2) )
  {
    HB_FUNC_EXEC( QXMLSTREAMWRITER_WRITETEXTELEMENT2 );
  }
}


