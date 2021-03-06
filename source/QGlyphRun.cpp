/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QGlyphRun>

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
QGlyphRun ()
*/
HB_FUNC( QGLYPHRUN_NEW1 )
{
  QGlyphRun * o = NULL;
  o = new QGlyphRun (  );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGlyphRun *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QGlyphRun ( const QGlyphRun & other )
*/
HB_FUNC( QGLYPHRUN_NEW2 )
{
  QGlyphRun * o = NULL;
  QGlyphRun * par1 = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QGlyphRun ( *par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QGlyphRun *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QGlyphRun ()
//[2]QGlyphRun ( const QGlyphRun & other )

HB_FUNC( QGLYPHRUN_NEW )
{
  if( ISNUMPAR(0) )
  {
    HB_FUNC_EXEC( QGLYPHRUN_NEW1 );
  }
  else if( ISNUMPAR(1) && ISQGLYPHRUN(1) )
  {
    HB_FUNC_EXEC( QGLYPHRUN_NEW2 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QGLYPHRUN_DELETE )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
void clear ()
*/
HB_FUNC( QGLYPHRUN_CLEAR )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    obj->clear (  );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
QVector<quint32> glyphIndexes () const
*/
HB_FUNC( QGLYPHRUN_GLYPHINDEXES )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector<quint32> list = obj->glyphIndexes (  );
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      PHB_ITEM pItem = hb_itemPutNI( NULL, list[i] );
      hb_arrayAddForward( pArray, pItem );
      hb_itemRelease(pItem);
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
bool overline () const
*/
HB_FUNC( QGLYPHRUN_OVERLINE )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->overline (  );
    hb_retl( b );
  }
}


/*
QVector<QPointF> positions () const
*/
HB_FUNC( QGLYPHRUN_POSITIONS )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QVector<QPointF> list = obj->positions (  );
    PHB_DYNS pDynSym;
    #ifdef __XHARBOUR__
    pDynSym = hb_dynsymFind( "QPOINTF" );
    #else
    pDynSym = hb_dynsymFindName( "QPOINTF" );
    #endif
    PHB_ITEM pArray;
    pArray = hb_itemArrayNew(0);
    int i;
    for(i=0;i<list.count();i++)
    {
      if( pDynSym )
      {
        #ifdef __XHARBOUR__
        hb_vmPushSymbol( pDynSym->pSymbol );
        #else
        hb_vmPushDynSym( pDynSym );
        #endif
        hb_vmPushNil();
        hb_vmDo( 0 );
        PHB_ITEM pObject = hb_itemNew( NULL );
        hb_itemCopy( pObject, hb_stackReturnItem() );
        PHB_ITEM pItem = hb_itemNew( NULL );
        hb_itemPutPtr( pItem, (QPointF *) new QPointF ( list[i] ) );
        hb_objSendMsg( pObject, "_POINTER", 1, pItem );
        hb_arrayAddForward( pArray, pObject );
        hb_itemRelease( pObject );
        hb_itemRelease( pItem );
      }
    }
    hb_itemReturnRelease(pArray);
  }
}


/*
QRawFont rawFont () const
*/
HB_FUNC( QGLYPHRUN_RAWFONT )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRawFont * ptr = new QRawFont( obj->rawFont (  ) );
    _qt4xhb_createReturnClass ( ptr, "QRAWFONT", true );  }
}


/*
void setGlyphIndexes ( const QVector<quint32> & glyphIndexes )
*/
HB_FUNC( QGLYPHRUN_SETGLYPHINDEXES )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QVector<quint32> par1;
PHB_ITEM aValues1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aValues1);
int temp1;
for (i1=0;i1<nLen1;i1++)
{
temp1 = hb_arrayGetNI(aValues1, i1+1);
par1 << temp1;
}
    obj->setGlyphIndexes ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setOverline ( bool overline )
*/
HB_FUNC( QGLYPHRUN_SETOVERLINE )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setOverline ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPositions ( const QVector<QPointF> & positions )
*/
HB_FUNC( QGLYPHRUN_SETPOSITIONS )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
QVector<QPointF> par1;
PHB_ITEM aList1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aList1);
for (i1=0;i1<nLen1;i1++)
{
par1 << *(QPointF *) hb_itemGetPtr( hb_objSendMsg( hb_arrayGetItemPtr( aList1, i1+1 ), "POINTER", 0 ) );
}
    obj->setPositions ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}



/*
void setRawFont ( const QRawFont & rawFont )
*/
HB_FUNC( QGLYPHRUN_SETRAWFONT )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRawFont * par1 = (QRawFont *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setRawFont ( *par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setStrikeOut ( bool strikeOut )
*/
HB_FUNC( QGLYPHRUN_SETSTRIKEOUT )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setStrikeOut ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setUnderline ( bool underline )
*/
HB_FUNC( QGLYPHRUN_SETUNDERLINE )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setUnderline ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool strikeOut () const
*/
HB_FUNC( QGLYPHRUN_STRIKEOUT )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->strikeOut (  );
    hb_retl( b );
  }
}


/*
bool underline () const
*/
HB_FUNC( QGLYPHRUN_UNDERLINE )
{
  QGlyphRun * obj = (QGlyphRun *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->underline (  );
    hb_retl( b );
  }
}




