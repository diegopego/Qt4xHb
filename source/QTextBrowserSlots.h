/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#ifndef SLOTSQTEXTBROWSER_H
#define SLOTSQTEXTBROWSER_H
#include <QObject>
#include <QCoreApplication>
#include <QList>
#include <QTextBrowser>
#include "hbapi.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "hbstack.h"
#ifndef __XHARBOUR__
#include "hbapicls.h"
#endif

void QTextBrowser_release_codeblocks ();
class SlotsQTextBrowser: public QObject
{
  Q_OBJECT
  public:
  SlotsQTextBrowser(QObject *parent = 0);
  ~SlotsQTextBrowser();
  QList<QObject*> list1;
  QList<QString> list2;
  QList<PHB_ITEM> list3;
  QList<bool> list4;
  public slots:
  void anchorClicked ( const QUrl & link );
  void backwardAvailable ( bool available );
  void forwardAvailable ( bool available );
  void highlighted ( const QUrl & link );
  void highlighted ( const QString & link );
  void historyChanged ();
  void sourceChanged ( const QUrl & src );
};
#endif
