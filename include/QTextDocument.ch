/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

/*
enum QTextDocument::FindFlag
flags QTextDocument::FindFlags
*/
#define QTextDocument_FindBackward                                   0x00001
#define QTextDocument_FindCaseSensitively                            0x00002
#define QTextDocument_FindWholeWords                                 0x00004

/*
enum QTextDocument::MetaInformation
*/
#define QTextDocument_DocumentTitle                                  0
#define QTextDocument_DocumentUrl                                    1

/*
enum QTextDocument::ResourceType
*/
#define QTextDocument_HtmlResource                                   1
#define QTextDocument_ImageResource                                  2
#define QTextDocument_StyleSheetResource                             3
#define QTextDocument_UserResource                                   100

/*
enum QTextDocument::Stacks
*/
#define QTextDocument_UndoStack                                      0x01
#define QTextDocument_RedoStack                                      0x02
#define QTextDocument_UndoAndRedoStacks                              hb_bitor(QTextDocument_UndoStack,QTextDocument_RedoStack)
