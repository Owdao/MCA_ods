// CControl.cpp: 实现文件
//

#include "stdafx.h"
#include "MCA_ods.h"
#include "CControl.h"


// CControl

IMPLEMENT_DYNCREATE(CControl, CFormView)

CControl::CControl()
	: CFormView(CControl::IDD)
{

}

CControl::~CControl()
{
}

void CControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

}
BEGIN_MESSAGE_MAP(CControl, CFormView)
END_MESSAGE_MAP()

// CControl 诊断

#ifdef _DEBUG
void CControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CControl 消息处理程序
