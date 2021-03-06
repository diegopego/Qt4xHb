/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include <QCompleter>

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

#include <QStringList>

/*
QCompleter ( QObject * parent = 0 )
*/
HB_FUNC( QCOMPLETER_NEW1 )
{
  QCompleter * o = NULL;
  QObject * par1 = ISNIL(1)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QCompleter ( par1 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QCompleter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QCompleter ( QAbstractItemModel * model, QObject * parent = 0 )
*/
HB_FUNC( QCOMPLETER_NEW2 )
{
  QCompleter * o = NULL;
  QAbstractItemModel * par1 = (QAbstractItemModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QCompleter ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QCompleter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


/*
QCompleter ( const QStringList & list, QObject * parent = 0 )
*/
HB_FUNC( QCOMPLETER_NEW3 )
{
  QCompleter * o = NULL;
QStringList par1;
PHB_ITEM aStrings1 = hb_param(1, HB_IT_ARRAY);
int i1;
int nLen1 = hb_arrayLen(aStrings1);
for (i1=0;i1<nLen1;i1++)
{
QString temp = hb_arrayGetCPtr(aStrings1, i1+1);
par1 << temp;
}
  QObject * par2 = ISNIL(2)? 0 : (QObject *) hb_itemGetPtr( hb_objSendMsg( hb_param(2, HB_IT_OBJECT ), "POINTER", 0 ) );
  o = new QCompleter ( par1, par2 );
  PHB_ITEM self = hb_stackSelfItem();
  PHB_ITEM ptr = hb_itemPutPtr( NULL,(QCompleter *) o );
  hb_objSendMsg( self, "_pointer", 1, ptr );
  hb_itemRelease( ptr );
  hb_itemReturn( self );
}


//[1]QCompleter ( QObject * parent = 0 )
//[2]QCompleter ( QAbstractItemModel * model, QObject * parent = 0 )
//[3]QCompleter ( const QStringList & list, QObject * parent = 0 )

HB_FUNC( QCOMPLETER_NEW )
{
  if( ISBETWEEN(0,1) && (ISQOBJECT(1)||ISNIL(1)) )
  {
    HB_FUNC_EXEC( QCOMPLETER_NEW1 );
  }
  else if( ISBETWEEN(1,2) && ISQABSTRACTITEMMODEL(1) && (ISQOBJECT(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QCOMPLETER_NEW2 );
  }
  else if( ISBETWEEN(1,2) && ISARRAY(1) && (ISQOBJECT(2)||ISNIL(2)) )
  {
    HB_FUNC_EXEC( QCOMPLETER_NEW3 );
  }
  else
  {
    hb_errRT_BASE( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS );
  }
}

HB_FUNC( QCOMPLETER_DELETE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
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
Qt::CaseSensitivity caseSensitivity () const
*/
HB_FUNC( QCOMPLETER_CASESENSITIVITY )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->caseSensitivity (  );
    hb_retni( i );
  }
}


/*
int completionColumn () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONCOLUMN )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->completionColumn (  );
    hb_retni( i );
  }
}


/*
int completionCount () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONCOUNT )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->completionCount (  );
    hb_retni( i );
  }
}


/*
CompletionMode completionMode () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONMODE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->completionMode (  );
    hb_retni( i );
  }
}


/*
QAbstractItemModel * completionModel () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONMODEL )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * ptr = obj->completionModel (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMMODEL" );  }
}


/*
QString completionPrefix () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONPREFIX )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->completionPrefix (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
int completionRole () const
*/
HB_FUNC( QCOMPLETER_COMPLETIONROLE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->completionRole (  );
    hb_retni( i );
  }
}


/*
QString currentCompletion () const
*/
HB_FUNC( QCOMPLETER_CURRENTCOMPLETION )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString str1 = obj->currentCompletion (  );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QModelIndex currentIndex () const
*/
HB_FUNC( QCOMPLETER_CURRENTINDEX )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * ptr = new QModelIndex( obj->currentIndex (  ) );
    _qt4xhb_createReturnClass ( ptr, "QMODELINDEX", true );  }
}


/*
int currentRow () const
*/
HB_FUNC( QCOMPLETER_CURRENTROW )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->currentRow (  );
    hb_retni( i );
  }
}


/*
int maxVisibleItems () const
*/
HB_FUNC( QCOMPLETER_MAXVISIBLEITEMS )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->maxVisibleItems (  );
    hb_retni( i );
  }
}


/*
QAbstractItemModel * model () const
*/
HB_FUNC( QCOMPLETER_MODEL )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * ptr = obj->model (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMMODEL" );  }
}


/*
ModelSorting modelSorting () const
*/
HB_FUNC( QCOMPLETER_MODELSORTING )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int i = obj->modelSorting (  );
    hb_retni( i );
  }
}


/*
virtual QString pathFromIndex ( const QModelIndex & index ) const
*/
HB_FUNC( QCOMPLETER_PATHFROMINDEX )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QModelIndex * par1 = (QModelIndex *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    QString str1 = obj->pathFromIndex ( *par1 );
    hb_retc( (const char *) str1.toLatin1().data() );
  }
}


/*
QAbstractItemView * popup () const
*/
HB_FUNC( QCOMPLETER_POPUP )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemView * ptr = obj->popup (  );
    _qt4xhb_createReturnClass ( ptr, "QABSTRACTITEMVIEW" );  }
}


/*
void setCaseSensitivity ( Qt::CaseSensitivity caseSensitivity )
*/
HB_FUNC( QCOMPLETER_SETCASESENSITIVITY )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCaseSensitivity (  (Qt::CaseSensitivity) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCompletionColumn ( int column )
*/
HB_FUNC( QCOMPLETER_SETCOMPLETIONCOLUMN )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCompletionColumn ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCompletionMode ( CompletionMode mode )
*/
HB_FUNC( QCOMPLETER_SETCOMPLETIONMODE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCompletionMode (  (QCompleter::CompletionMode) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCompletionRole ( int role )
*/
HB_FUNC( QCOMPLETER_SETCOMPLETIONROLE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setCompletionRole ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
bool setCurrentRow ( int row )
*/
HB_FUNC( QCOMPLETER_SETCURRENTROW )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    bool b = obj->setCurrentRow ( par1 );
    hb_retl( b );
  }
}


/*
void setMaxVisibleItems ( int maxItems )
*/
HB_FUNC( QCOMPLETER_SETMAXVISIBLEITEMS )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setMaxVisibleItems ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setModel ( QAbstractItemModel * model )
*/
HB_FUNC( QCOMPLETER_SETMODEL )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemModel * par1 = (QAbstractItemModel *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setModel ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setModelSorting ( ModelSorting sorting )
*/
HB_FUNC( QCOMPLETER_SETMODELSORTING )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    int par1 = hb_parni(1);
    obj->setModelSorting (  (QCompleter::ModelSorting) par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setPopup ( QAbstractItemView * popup )
*/
HB_FUNC( QCOMPLETER_SETPOPUP )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QAbstractItemView * par1 = (QAbstractItemView *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setPopup ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWidget ( QWidget * widget )
*/
HB_FUNC( QCOMPLETER_SETWIDGET )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * par1 = (QWidget *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->setWidget ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
virtual QStringList splitPath ( const QString & path ) const
*/
HB_FUNC( QCOMPLETER_SPLITPATH )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    QStringList strl = obj->splitPath ( par1 );
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
QWidget * widget () const
*/
HB_FUNC( QCOMPLETER_WIDGET )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QWidget * ptr = obj->widget (  );
    _qt4xhb_createReturnClass ( ptr, "QWIDGET" );  }
}


/*
bool wrapAround () const
*/
HB_FUNC( QCOMPLETER_WRAPAROUND )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool b = obj->wrapAround (  );
    hb_retl( b );
  }
}


/*
void complete ( const QRect & rect = QRect() )
*/
HB_FUNC( QCOMPLETER_COMPLETE )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QRect par1 = ISNIL(1)? QRect() : *(QRect *) hb_itemGetPtr( hb_objSendMsg( hb_param(1, HB_IT_OBJECT ), "POINTER", 0 ) );
    obj->complete ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setCompletionPrefix ( const QString & prefix )
*/
HB_FUNC( QCOMPLETER_SETCOMPLETIONPREFIX )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    QString par1 = hb_parc(1);
    obj->setCompletionPrefix ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}


/*
void setWrapAround ( bool wrap )
*/
HB_FUNC( QCOMPLETER_SETWRAPAROUND )
{
  QCompleter * obj = (QCompleter *) hb_itemGetPtr( hb_objSendMsg( hb_stackSelfItem(), "POINTER", 0 ) );
  if( obj )
  {
    bool par1 = hb_parl(1);
    obj->setWrapAround ( par1 );
  }
  hb_itemReturn( hb_stackSelfItem() );
}




