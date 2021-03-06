/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQAXBASE_H
#define SLOTSQAXBASE_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QAxBase>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QAxBase_release_codeblocks ();
class SlotsQAxBase: public QObject
{
  Q_OBJECT
  public:
  SlotsQAxBase(QObject *parent = 0);
  ~SlotsQAxBase();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void exception ( int code, const QString & source, const QString & desc, const QString & help );
  void propertyChanged ( const QString & name );
  void signal ( const QString & name, int argc, void * argv );
};
#endif
