
// 2020_02_03_ImageprocessingView.h : CMy2020_02_03_ImageprocessingView Ŭ������ �������̽�
//

#pragma once


class CMy2020_02_03_ImageprocessingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2020_02_03_ImageprocessingView();
	DECLARE_DYNCREATE(CMy2020_02_03_ImageprocessingView)

// Ư���Դϴ�.
public:
	CMy2020_02_03_ImageprocessingDoc* GetDocument() const;

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
	virtual ~CMy2020_02_03_ImageprocessingView();
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
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	
	afx_msg void OnQuantization();
};

#ifndef _DEBUG  // 2020_02_03_ImageprocessingView.cpp�� ����� ����
inline CMy2020_02_03_ImageprocessingDoc* CMy2020_02_03_ImageprocessingView::GetDocument() const
   { return reinterpret_cast<CMy2020_02_03_ImageprocessingDoc*>(m_pDocument); }
#endif

