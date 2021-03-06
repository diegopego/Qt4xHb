/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQSIGNALMAPPER_H
#define SLOTSQSIGNALMAPPER_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QSignalMapper>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QSignalMapper_release_codeblocks ();
class SlotsQSignalMapper: public QObject
{
  Q_OBJECT
  public:
  SlotsQSignalMapper(QObject *parent = 0);
  ~SlotsQSignalMapper();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void mapped(int i);
  void mapped(const QString & s);
  void mapped(QWidget * w);
  void mapped(QObject * o);
};
#endif
