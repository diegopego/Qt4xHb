/*

  Exemplo do projeto Qt4xHb

  (C) 2012-2017 Marcos Antonio Gambeta

  E-mail: marcosgambeta@uol.com.br

  Website: https://github.com/marcosgambeta

*/

PROCEDURE Main ()

   LOCAL oApp
   LOCAL oWindow
   LOCAL oScrollBar

   oApp := QApplication():new()

   oWindow := QWidget():new()
   oWindow:setWindowTitle("Teste")
   oWindow:resize(640,480)
   oWindow:show()

   oScrollBar := QScrollBar():new(oWindow)
   oScrollBar:move(20,20)
   oScrollBar:resize(20,400)
   oScrollBar:setTooltip("Eu sou um ScrollBar")
   oScrollBar:onSliderMoved( {|w,v|test(w,v)} )
   oScrollBar:show()

   oApp:exec()
   
   oWindow:delete()
   
   oApp:delete()

RETURN

STATIC FUNCTION test (w,v)

   qout("slider moved")
   qout(w)
   qout(v)

RETURN NIL
