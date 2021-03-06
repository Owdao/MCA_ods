
// MCA_odsView.cpp: CMCAodsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MCA_ods.h"
#endif

#include "MCA_odsDoc.h"
#include "MCA_odsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMCAodsView

IMPLEMENT_DYNCREATE(CMCAodsView, CView)

BEGIN_MESSAGE_MAP(CMCAodsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMCAodsView 构造/析构

CMCAodsView::CMCAodsView()
{
	// TODO: 在此处添加构造代码

}

CMCAodsView::~CMCAodsView()
{
}

BOOL CMCAodsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMCAodsView 绘图

void CMCAodsView::OnDraw(CDC* /*pDC*/)
{
	CMCAodsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMCAodsView 打印

BOOL CMCAodsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMCAodsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMCAodsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMCAodsView 诊断

#ifdef _DEBUG
void CMCAodsView::AssertValid() const
{
	CView::AssertValid();
}

void CMCAodsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMCAodsDoc* CMCAodsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMCAodsDoc)));
	return (CMCAodsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMCAodsView 消息处理程序
