#ifndef __STARTINGSUNDIALOG_H__
#define __STARTINGSUNDIALOG_H__

#include "LawnDialog.h"
#include "../../SexyAppFramework/EditListener.h"
#include "../Board.h"

class ToolTipWidget;
class StartingSunDialog : public LawnDialog, public EditListener
{
public:
	LawnApp*				mApp;
	EditWidget*				mSunEditWidget;
    ToolTipWidget*          mToolTip;

public:
	StartingSunDialog(LawnApp* mApp);
    virtual ~StartingSunDialog();

	virtual int			GetPreferredHeight(int theWidth);
	virtual void		Resize(int theX, int theY, int theWidth, int theHeight);
	virtual void		AddedToManager(WidgetManager* theWidgetManager);
	virtual void		RemovedFromManager(WidgetManager* theWidgetManager);
	virtual void		Draw(Graphics* g);
	virtual void		EditWidgetText(int theId, const SexyString& theString);
	virtual bool		AllowChar(int, SexyChar theChar);
	SexyString			GetStartingSun();
	void				SetStartingSun(const SexyString& theSun);
};

#endif