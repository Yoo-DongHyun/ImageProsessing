
// Test_MFCView.h : CTest_MFCView Ŭ������ �������̽�
//

#pragma once


class CTest_MFCView : public CView
{
protected: // serialization������ ��������ϴ�.
	CTest_MFCView();
	DECLARE_DYNCREATE(CTest_MFCView)

// Ư���Դϴ�.
public:
	CTest_MFCDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CTest_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Test_MFCView.cpp�� ����� ����
inline CTest_MFCDoc* CTest_MFCView::GetDocument() const
   { return reinterpret_cast<CTest_MFCDoc*>(m_pDocument); }
#endif

