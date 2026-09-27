#include "GameButton.h"
#include "../../LawnApp.h"
#include "../ToolTipWidget.h"
#include "../../GameConstants.h"
#include "../../SexyAppFramework/WidgetManager.h"
#include "../../Resources.h"
#include "StartingSunDialog.h"

StartingSunDialog::StartingSunDialog(LawnApp* theApp) : LawnDialog(
	theApp,
	Dialogs::DIALOG_STARTING_SUN,
	true,
	_S("[NEW_STARTING_SUN]"),
	_S("[PLEASE_ENTER_STARTING_SUN]"),
	_S("[DIALOG_BUTTON_OK]"),
	Dialog::BUTTONS_OK_CANCEL)
{
	mApp = theApp;
	mVerticalCenterText = false;
	mSunEditWidget = CreateEditWidget(0, this, this);
	mSunEditWidget->mMaxChars = 4;
	mSunEditWidget->AddWidthCheckFont(FONT_BRIANNETOD16, 220);
	mToolTip = new ToolTipWidget();
	mClip = false;
	mLawnYesButton->mBtnNoDraw = true;
	mLawnYesButton->mMouseVisible = false;
	mLawnNoButton->mBtnNoDraw = true;
	mLawnNoButton->mMouseVisible = false;
	CalcSize(110, 40);
}

StartingSunDialog::~StartingSunDialog()
{
	delete mSunEditWidget;
	delete mToolTip;
}

void StartingSunDialog::AddedToManager(WidgetManager* theWidgetManager)
{
	LawnDialog::AddedToManager(theWidgetManager);
	AddWidget(mSunEditWidget);
	theWidgetManager->SetFocus(mSunEditWidget);
}

void StartingSunDialog::RemovedFromManager(WidgetManager* theWidgetManager)
{
	LawnDialog::RemovedFromManager(theWidgetManager);
	RemoveWidget(mSunEditWidget);
}

int StartingSunDialog::GetPreferredHeight(int theWidth)
{
	return LawnDialog::GetPreferredHeight(theWidth) + 40;
}

void StartingSunDialog::Resize(int theX, int theY, int theWidth, int theHeight)
{
	LawnDialog::Resize(theX, theY, theWidth, theHeight);
	mSunEditWidget->Resize(mContentInsets.mLeft + 12, mHeight - 155, mWidth - mContentInsets.mLeft - mContentInsets.mRight - 24, 28);
}

void StartingSunDialog::Draw(Graphics* g)
{
	LawnDialog::Draw(g);
	DrawEditBox(g, mSunEditWidget);
}

void StartingSunDialog::EditWidgetText(int theId, const SexyString& theString)
{
	mApp->ButtonDepress(mId + 2000);
}

bool StartingSunDialog::AllowChar(int, SexyChar theChar)
{
	return isdigit(theChar) || theChar == '-';
}

SexyString StartingSunDialog::GetStartingSun()
{
	auto hyphen_count = std::ranges::count(mSunEditWidget->mString, '-');

	if ((mSunEditWidget->mString.empty() ||
		hyphen_count > 1) ||
		(mSunEditWidget->mString[0] != '-' && hyphen_count == 1))
		mSunEditWidget->mString = "0";

	return mSunEditWidget->mString;
}

void StartingSunDialog::SetStartingSun(const SexyString& theSun)
{
	mSunEditWidget->mString = theSun;
	mSunEditWidget->mCursorPos = theSun.size();
	mSunEditWidget->mHilitePos = 0;
}