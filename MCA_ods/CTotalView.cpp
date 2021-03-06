// CTotalView.cpp: 实现文件
//

#include "stdafx.h"
#include "MCA_ods.h"
#include "CTotalView.h"
#include "MCA_odsDoc.h"


// CTotalView

IMPLEMENT_DYNCREATE(CTotalView, CView)

CTotalView::CTotalView()
{

	m_MemDCWidth = DotNumber;
	m_MemDCHeight = 1000;

	m_MemDCSrcX = 0;
	m_MemDCSrcY = 0;
	m_MemDCSrcWidth = m_MemDCWidth;
	m_MemDCSrcHeight = m_MemDCHeight;
}

CTotalView::~CTotalView()
{
}

BEGIN_MESSAGE_MAP(CTotalView, CView)
END_MESSAGE_MAP()


// CTotalView 绘图

void CTotalView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

	CRect rect_client;
	GetClientRect(&rect_client);

	//声明内存DC
	CDC MemDC;		
	MemDC.CreateCompatibleDC(pDC);

	//声明内存位图以用于绘图
	CBitmap MemBitmap, *OldBitmap;
	MemBitmap.CreateCompatibleBitmap(pDC, m_MemDCWidth, m_MemDCHeight);
	OldBitmap = MemDC.SelectObject(&MemBitmap);

	//绘图
	MemDC.FillSolidRect(0, 0, m_MemDCWidth, m_MemDCHeight, RGB(0, 0, 0));


	//复制显示
	pDC->StretchBlt(0, 0, rect_client.Width(), rect_client.Height(),
		&MemDC, m_MemDCSrcX, m_MemDCSrcY, m_MemDCSrcWidth, m_MemDCSrcHeight, SRCCOPY);
	pDC->SetStretchBltMode(HALFTONE);  //设置拉伸模式为半色调

	//清除缓存
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}


// CTotalView 诊断

#ifdef _DEBUG
void CTotalView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CTotalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CTotalView 消息处理程序
