/*

  Qt4xHb - bibliotecas de liga��o entre Harbour/xHarbour e Qt Framework 4

  Copyright (C) 2012-2017 Marcos Antonio Gambeta <marcosgambeta@uol.com.br>

*/

#include "hbclass.ch"
#include "qt4xhb_clsid.ch"


REQUEST QACTION
REQUEST QSIZE
REQUEST QWIDGET
REQUEST QRECT
REQUEST QREGION
REQUEST QMARGINS
REQUEST QCURSOR
REQUEST QFONT
REQUEST QFONTINFO
REQUEST QFONTMETRICS
REQUEST QGRAPHICSEFFECT
REQUEST QGRAPHICSPROXYWIDGET
REQUEST QINPUTCONTEXT
REQUEST QVARIANT
REQUEST QLAYOUT
REQUEST QLOCALE
REQUEST QPOINT
REQUEST QPALETTE
REQUEST QBYTEARRAY
REQUEST QSIZEPOLICY
REQUEST QSTYLE
REQUEST QICON
REQUEST QPAINTENGINE

CLASS QWidget INHERIT QObject

   DATA class_id INIT Class_Id_QWidget
   DATA class_flags INIT 2
   DATA self_destruction INIT .f.

   METHOD new
   METHOD delete
   METHOD acceptDrops
   METHOD accessibleDescription
   METHOD accessibleName
   METHOD actions
   METHOD activateWindow
   METHOD addAction
   METHOD addActions
   METHOD adjustSize
   METHOD autoFillBackground
   METHOD backgroundRole
   METHOD baseSize
   METHOD childAt1
   METHOD childAt2
   METHOD childAt
   METHOD childrenRect
   METHOD childrenRegion
   METHOD clearFocus
   METHOD clearMask
   METHOD contentsMargins
   METHOD contentsRect
   METHOD contextMenuPolicy
   METHOD cursor
   METHOD effectiveWinId
   METHOD ensurePolished
   METHOD focusPolicy
   METHOD focusProxy
   METHOD focusWidget
   METHOD font
   METHOD fontInfo
   METHOD fontMetrics
   METHOD foregroundRole
   METHOD frameGeometry
   METHOD frameSize
   METHOD geometry
   METHOD getContentsMargins
   METHOD grabGesture
   METHOD grabKeyboard
   METHOD grabMouse1
   METHOD grabMouse2
   METHOD grabMouse
   METHOD grabShortcut
   METHOD graphicsEffect
   METHOD graphicsProxyWidget
   METHOD hasFocus
   METHOD hasMouseTracking
   METHOD height
   METHOD heightForWidth
   METHOD inputContext
   METHOD inputMethodHints
   METHOD inputMethodQuery
   METHOD insertAction
   METHOD insertActions
   METHOD isActiveWindow
   METHOD isAncestorOf
   METHOD isEnabled
   METHOD isEnabledTo
   METHOD isFullScreen
   METHOD isHidden
   METHOD isMaximized
   METHOD isMinimized
   METHOD isModal
   METHOD isVisible
   METHOD isVisibleTo
   METHOD isWindow
   METHOD isWindowModified
   METHOD layout
   METHOD layoutDirection
   METHOD locale
   METHOD mapFrom
   METHOD mapFromGlobal
   METHOD mapFromParent
   METHOD mapTo
   METHOD mapToGlobal
   METHOD mapToParent
   METHOD mask
   METHOD maximumHeight
   METHOD maximumSize
   METHOD maximumWidth
   METHOD minimumHeight
   METHOD minimumSize
   METHOD minimumSizeHint
   METHOD minimumWidth
   METHOD move1
   METHOD move2
   METHOD move
   METHOD nativeParentWidget
   METHOD nextInFocusChain
   METHOD normalGeometry
   METHOD overrideWindowFlags
   METHOD palette
   METHOD parentWidget
   METHOD pos
   METHOD previousInFocusChain
   METHOD rect
   METHOD releaseKeyboard
   METHOD releaseMouse
   METHOD releaseShortcut
   METHOD removeAction
   METHOD render1
   METHOD render2
   METHOD render
   METHOD repaint1
   METHOD repaint2
   METHOD repaint3
   METHOD repaint
   METHOD resize1
   METHOD resize2
   METHOD resize
   METHOD restoreGeometry
   METHOD saveGeometry
   METHOD scroll1
   METHOD scroll2
   METHOD scroll
   METHOD setAcceptDrops
   METHOD setAccessibleDescription
   METHOD setAccessibleName
   METHOD setAttribute
   METHOD setAutoFillBackground
   METHOD setBackgroundRole
   METHOD setBaseSize1
   METHOD setBaseSize2
   METHOD setBaseSize
   METHOD setContentsMargins1
   METHOD setContentsMargins2
   METHOD setContentsMargins
   METHOD setContextMenuPolicy
   METHOD setCursor
   METHOD setFixedHeight
   METHOD setFixedSize1
   METHOD setFixedSize2
   METHOD setFixedSize
   METHOD setFixedWidth
   METHOD setFocus1
   METHOD setFocus2
   METHOD setFocus
   METHOD setFocusPolicy
   METHOD setFocusProxy
   METHOD setFont
   METHOD setForegroundRole
   METHOD setGeometry1
   METHOD setGeometry2
   METHOD setGeometry
   METHOD setGraphicsEffect
   METHOD setInputContext
   METHOD setInputMethodHints
   METHOD setLayout
   METHOD setLayoutDirection
   METHOD setLocale
   METHOD setMask1
   METHOD setMask2
   METHOD setMask
   METHOD setMaximumHeight
   METHOD setMaximumSize1
   METHOD setMaximumSize2
   METHOD setMaximumSize
   METHOD setMaximumWidth
   METHOD setMinimumHeight
   METHOD setMinimumSize1
   METHOD setMinimumSize2
   METHOD setMinimumSize
   METHOD setMinimumWidth
   METHOD setMouseTracking
   METHOD setPalette
   METHOD setParent1
   METHOD setParent2
   METHOD setParent
   METHOD setShortcutAutoRepeat
   METHOD setShortcutEnabled
   METHOD setSizeIncrement1
   METHOD setSizeIncrement2
   METHOD setSizeIncrement
   METHOD setSizePolicy1
   METHOD setSizePolicy2
   METHOD setSizePolicy
   METHOD setStatusTip
   METHOD setStyle
   METHOD setToolTip
   METHOD setUpdatesEnabled
   METHOD setWhatsThis
   METHOD setWindowFilePath
   METHOD setWindowFlags
   METHOD setWindowIcon
   METHOD setWindowIconText
   METHOD setWindowModality
   METHOD setWindowOpacity
   METHOD setWindowRole
   METHOD setWindowState
   METHOD size
   METHOD sizeHint
   METHOD sizeIncrement
   METHOD sizePolicy
   METHOD stackUnder
   METHOD statusTip
   METHOD style
   METHOD styleSheet
   METHOD testAttribute
   METHOD toolTip
   METHOD underMouse
   METHOD ungrabGesture
   METHOD unsetCursor
   METHOD unsetLayoutDirection
   METHOD unsetLocale
   METHOD update1
   METHOD update2
   METHOD update3
   METHOD update4
   METHOD update
   METHOD updateGeometry
   METHOD updatesEnabled
   METHOD visibleRegion
   METHOD whatsThis
   METHOD width
   METHOD winId
   METHOD window
   METHOD windowFilePath
   METHOD windowFlags
   METHOD windowIcon
   METHOD windowIconText
   METHOD windowModality
   METHOD windowOpacity
   METHOD windowRole
   METHOD windowState
   METHOD windowTitle
   METHOD windowType
   METHOD x
   METHOD y
   METHOD paintEngine
   METHOD close
   METHOD hide
   METHOD lower
   METHOD raise
   METHOD setDisabled
   METHOD setEnabled
   METHOD setHidden
   METHOD setStyleSheet
   METHOD setVisible
   METHOD setWindowModified
   METHOD setWindowTitle
   METHOD show
   METHOD showFullScreen
   METHOD showMaximized
   METHOD showMinimized
   METHOD showNormal
   METHOD colorCount
   METHOD depth
   METHOD heightMM
   METHOD logicalDpiX
   METHOD logicalDpiY
   METHOD numColors
   METHOD paintingActive
   METHOD physicalDpiX
   METHOD physicalDpiY
   METHOD widthMM
   METHOD find
   METHOD keyboardGrabber
   METHOD mouseGrabber
   METHOD setTabOrder
   METHOD onCustomContextMenuRequested
   DESTRUCTOR destroyObject

END CLASS

PROCEDURE destroyObject () CLASS QWidget
   IF ::self_destruction
      ::delete()
   ENDIF
RETURN
