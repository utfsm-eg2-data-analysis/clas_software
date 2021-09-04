c      include file draw_general
c
c_begin_doc
c  RCS ID string
c  $Id: draw_general.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file DRAW_GENERAL
c
c  Purpose: General arrays for the DCM drawing
c  -------- 
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov      Created:  Fri May  9 10:29:00 EST 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c
c
c  Remember NO NESTED INCLUDES
c
c  COMMON BLOCK NAME should be the same as include file name!
c
c_begin_var
c  variables for include file DRAW_GENERAL:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CIDRAW_GENERAL
      DATA CIDRAW_GENERAL/
     +'$Id: draw_general.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'
     +/
c----6----------------------------------------------------------------72
c  
c  Variables contained in DRAW_GENERAL
c  ---------------------------------------------------------------------
c
c display - a display name (addreass, number)
c iwid - window number (identifier - used lockaly only during initialization)
c ixopnds - open display subroutine name
c ixopnwi - open window subroutine name
c gra_was_init - 'has been initialized' flag for the RED drawing package
c ixyln - working address for lines, poligons and markers
c idash - segment length for line style definition (6,3,1,3):'======   =   '
C zoom_draw - a new scale, which is calculated from the zoom box
C r0_draw - an ancer point for the zoom
C draw_zoom (dr1_z,dr2_z,dr3_z) - zoom's for the 4 quadrants of the purefire
C draw_shx (dr1_x,dr2_x,dr3_x) - x-shifts for the 4 quadrants of the purefire
C draw_shy (dr1_y,dr2_y,dr3_y) - y-shifts for the 4 quadrants of the purefire
c draw_zshift - constant, which should be added to any z-coordinate for drawing
c draw_xshift - constant, which should be added to get bottom sectors (3,4,5)
c yellow,green,cyan,blue,margenta,red,black - indices for standard colours
C-----------------------------------------------------------------------
C
      CHARACTER*16 display
      INTEGER iwid, gra_was_init, draw_xshift, draw_zshift, tops ,bots
      INTEGER*2 ixyln(2,1000)
      INTEGER idash(12), yellow, green, cyan, blue, margenta, red, black
      REAL r0_draw(2), zoom_draw, draw_zoom, draw_shx, draw_shy
      REAL dr1_z,dr1_x,dr1_y,dr2_z,dr2_x,dr2_y,dr3_z,dr3_x,dr3_y
C
      COMMON/DRAW_GENERAL/display,iwid,gra_was_init,idash,ixyln,
     &                    r0_draw, zoom_draw, tops, bots, draw_zoom,
     &                    draw_shx, draw_shy, dr1_z, dr1_x, dr1_y,
     &                    dr2_z, dr2_x, dr2_y, dr3_z, dr3_x, dr3_y,
     &                    draw_xshift, draw_zshift,
     &                    yellow,green,cyan,blue,margenta,red,black
C
      SAVE  /DRAW_GENERAL/
c
c_end_var
c
c----6----------------------------------------------------------------72
