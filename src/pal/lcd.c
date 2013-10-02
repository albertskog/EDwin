/******************************************************************************
** Function name:		palLcdInit
**
** Descriptions:		Initializes the LCD display
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void palLcdInit();

/******************************************************************************
** Function name:		palLcdSetText
**
** Descriptions:		Put text on LCD
**
** parameters:
**              line - ex: LCD_LINE_1/LCD_LINE_2
**              text - The text you wish to be displayed
** Returned value:		None
**
******************************************************************************/
void palLcdSetText(uint8 line, char[] text);
