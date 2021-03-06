#pragma once


// CControl 视图

class CControl : public CFormView
{
	DECLARE_DYNCREATE(CControl)

protected:
	CControl();           // 动态创建所使用的受保护的构造函数
	virtual ~CControl();

public:
	//virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
	enum { IDD = IDD_DIALOG_CONTROL };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
};


