/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQDESIGNERFORMWINDOWINTERFACE_H
#define SLOTSQDESIGNERFORMWINDOWINTERFACE_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QDesignerFormWindowInterface>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QDesignerFormWindowInterface_release_codeblocks ();
class SlotsQDesignerFormWindowInterface: public QObject
{
  Q_OBJECT
  public:
  SlotsQDesignerFormWindowInterface(QObject *parent = 0);
  ~SlotsQDesignerFormWindowInterface();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void aboutToUnmanageWidget ( QWidget * widget );
  void activated ( QWidget * widget );
  void changed ();
  void featureChanged ( QDesignerFormWindowInterface::Feature feature );
  void fileNameChanged ( const QString & fileName );
  void geometryChanged ();
  void mainContainerChanged ( QWidget * mainContainer );
  void objectRemoved ( QObject * object2 );
  void resourceFilesChanged ();
  void selectionChanged ();
  void widgetManaged ( QWidget * widget );
  void widgetRemoved ( QWidget * widget );
  void widgetUnmanaged ( QWidget * widget );
};
#endif
