/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

/*
enum QAbstractPrintDialog::PrintDialogOption
flags QAbstractPrintDialog::PrintDialogOptions
*/
#define QAbstractPrintDialog_None                                    0x0000
#define QAbstractPrintDialog_PrintToFile                             0x0001
#define QAbstractPrintDialog_PrintSelection                          0x0002
#define QAbstractPrintDialog_PrintPageRange                          0x0004
#define QAbstractPrintDialog_PrintShowPageSize                       0x0008
#define QAbstractPrintDialog_PrintCollateCopies                      0x0010
#define QAbstractPrintDialog_PrintCurrentPage                        0x0040
#define QAbstractPrintDialog_DontUseSheet                            0x0020

/*
enum QAbstractPrintDialog::PrintRange
*/
#define QAbstractPrintDialog_AllPages                                0
#define QAbstractPrintDialog_Selection                               1
#define QAbstractPrintDialog_PageRange                               2
#define QAbstractPrintDialog_CurrentPage                             3
