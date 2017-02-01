/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QIMAGEIOHANDLER

CLASS QImageIOPlugin INHERIT QObject

   DATA class_id INIT Class_Id_QImageIOPlugin
   DATA self_destruction INIT .f.

   METHOD delete
   METHOD capabilities
   METHOD create
   METHOD keys
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QImageIOPlugin
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
