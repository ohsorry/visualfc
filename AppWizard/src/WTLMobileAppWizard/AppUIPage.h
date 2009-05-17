// AppUIPage.h: interface for the CAppUIPage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APPUIPAGE_H__BD6ADDE1_BF0C_4780_BF44_0440CC9123B1__INCLUDED_)
#define AFX_APPUIPAGE_H__BD6ADDE1_BF0C_4780_BF44_0440CC9123B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"
#include "wizardinfo.h"

class CAppUIPage  : public CWizardPageImpl<CAppUIPage, CWizardInfo>
{
public:
	BEGIN_DDX_MAP(CAppUIPage)
		DDX_CHECK(IDC_ENABLE_ZOOM, info->m_bEnableZoom)
		DDX_CHECK(IDC_ENABLE_SCROLL, info->m_bEnableScroll)
		DDX_RADIO(IDC_MENU_TYPE2003, info->m_nMenuType)
		DDX_CHECK(IDC_USE_CREATEVIEWCLASS, info->m_bCreateViewClass)
		//bSaveAndValidate
		CComboBox box = GetDlgItem(IDC_VIEWTYPE);
		if (box.GetCount() == 0)
		{
			for (int i = 0; i < info->ar_view.size(); i++)
			{
				box.AddString(info->ar_view[i]);
			}
		}
		if (bSaveAndValidate == DDX_LOAD)
		{
			box.SetCurSel(info->nViewType);
		}
		else if (bSaveAndValidate == DDX_SAVE)
		{
			info->nViewType = box.GetCurSel();
		}
		//DDX_CHECK(IDC_TOOLBAR, info->bToolBar)
		DDX_CHECK(IDC_STATUSBAR, info->bStatusBar)
		DDX_CHECK(IDC_USEVIEW,info->bUseView)
		DDX_CHECK(IDC_ACTIVEX, info->bHostActiveX)
	END_DDX_MAP();

	BEGIN_UPDATE_UI_MAP(CAppUIPage)
		UPDATE_ELEMENT(IDC_TOOLBAR, UPDUI_CHILDWINDOW)
		UPDATE_ELEMENT(IDC_STATUSBAR, UPDUI_CHILDWINDOW)
		UPDATE_ELEMENT(IDC_USEVIEW, UPDUI_CHILDWINDOW)
		UPDATE_ELEMENT(IDC_VIEWTYPE, UPDUI_CHILDWINDOW)
		UPDATE_ELEMENT(IDC_ACTIVEX, UPDUI_CHILDWINDOW)
	END_UPDATE_UI_MAP();

	void DoUpdateUI(UINT id)
	{
		DoDataExchange(true);

		UIEnable(IDC_ACTIVEX,info->bEnableActiveX);
		UIEnable(IDC_TOOLBAR,info->nAppType != 5 );
		UIEnable(IDC_STATUSBAR,info->nAppType != 5);


		UIEnable(IDC_USEVIEW, info->nAppType != 3 && info->nAppType != 4 && info->nAppType != 5);

		UIEnable(IDC_VIEWTYPE, info->nAppType != 5);
		UIEnable(IDC_ACTIVEX, info->nAppType != 5 && info->bEnableActiveX && info->nViewType == 1);

		UISetCheck(IDC_USEVIEW,info->bUseView);
		UISetCheck(IDC_STATUSBAR, info->bStatusBar);
	}
	
	enum { IDD = IDD_APPUI_PAGE };

	CAppUIPage();
	virtual ~CAppUIPage();
};

#endif // !defined(AFX_APPUIPAGE_H__BD6ADDE1_BF0C_4780_BF44_0440CC9123B1__INCLUDED_)
