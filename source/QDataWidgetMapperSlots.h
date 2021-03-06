/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQDATAWIDGETMAPPER_H
#define SLOTSQDATAWIDGETMAPPER_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QDataWidgetMapper>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QDataWidgetMapper_release_codeblocks ();
class SlotsQDataWidgetMapper: public QObject
{
  Q_OBJECT
  public:
  SlotsQDataWidgetMapper(QObject *parent = 0);
  ~SlotsQDataWidgetMapper();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void currentIndexChanged ( int index );
};
#endif
