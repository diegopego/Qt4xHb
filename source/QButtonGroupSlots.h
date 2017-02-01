/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQBUTTONGROUP_H
#define SLOTSQBUTTONGROUP_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QButtonGroup>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QButtonGroup_release_codeblocks ();
class SlotsQButtonGroup: public QObject
{
  Q_OBJECT
  public:
  SlotsQButtonGroup(QObject *parent = 0);
  ~SlotsQButtonGroup();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void buttonClicked ( QAbstractButton * button );
  void buttonClicked ( int id );
  void buttonPressed ( QAbstractButton * button );
  void buttonPressed ( int id );
  void buttonReleased ( QAbstractButton * button );
  void buttonReleased ( int id );
};
#endif
