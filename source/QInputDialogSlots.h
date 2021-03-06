/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQINPUTDIALOG_H
#define SLOTSQINPUTDIALOG_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QInputDialog>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QInputDialog_release_codeblocks ();
class SlotsQInputDialog: public QObject
{
  Q_OBJECT
  public:
  SlotsQInputDialog(QObject *parent = 0);
  ~SlotsQInputDialog();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void doubleValueChanged ( double value );
  void doubleValueSelected ( double value );
  void intValueChanged ( int value );
  void intValueSelected ( int value );
  void textValueChanged ( const QString & text );
  void textValueSelected ( const QString & text );
};
#endif
