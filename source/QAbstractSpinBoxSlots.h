/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQABSTRACTSPINBOX_H
#define SLOTSQABSTRACTSPINBOX_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QAbstractSpinBox>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QAbstractSpinBox_release_codeblocks ();
class SlotsQAbstractSpinBox: public QObject
{
  Q_OBJECT
  public:
  SlotsQAbstractSpinBox(QObject *parent = 0);
  ~SlotsQAbstractSpinBox();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void editingFinished ();
};
#endif
