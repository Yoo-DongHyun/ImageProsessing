
// Test_MFCView.cpp : CTest_MFCView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Test_MFC.h"
#endif

#include "Test_MFCDoc.h"
#include "Test_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest_MFCView

IMPLEMENT_DYNCREATE(CTest_MFCView, CView)

BEGIN_MESSAGE_MAP(CTest_MFCView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTest_MFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTest_MFCView ����/�Ҹ�

CTest_MFCView::CTest_MFCView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTest_MFCView::~CTest_MFCView()
{
}

BOOL CTest_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CTest_MFCView �׸���

void CTest_MFCView::OnDraw(CDC* /*pDC*/)
{
	CTest_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CTest_MFCView �μ�


void CTest_MFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTest_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTest_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTest_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CTest_MFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTest_MFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTest_MFCView ����

#ifdef _DEBUG
void CTest_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CTest_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest_MFCDoc* CTest_MFCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest_MFCDoc)));
	return (CTest_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CTest_MFCView �޽��� ó����
