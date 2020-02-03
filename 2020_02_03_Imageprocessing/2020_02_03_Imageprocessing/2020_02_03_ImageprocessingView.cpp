
// 2020_02_03_ImageprocessingView.cpp : CMy2020_02_03_ImageprocessingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2020_02_03_Imageprocessing.h"
#endif

#include "2020_02_03_ImageprocessingDoc.h"
#include "2020_02_03_ImageprocessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020_02_03_ImageprocessingView

IMPLEMENT_DYNCREATE(CMy2020_02_03_ImageprocessingView, CView)

BEGIN_MESSAGE_MAP(CMy2020_02_03_ImageprocessingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2020_02_03_ImageprocessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CHAPTER3_DOWNSAMPLE, &CMy2020_02_03_ImageprocessingView::OnDownSampling)
	ON_COMMAND(ID_CHAPTER3_UPSAMPLE, &CMy2020_02_03_ImageprocessingView::OnUpSampling)
	ON_COMMAND(ID_CHAPTER3_QUANTIZATION, &CMy2020_02_03_ImageprocessingView::OnQuantization)
END_MESSAGE_MAP()

// CMy2020_02_03_ImageprocessingView ����/�Ҹ�

CMy2020_02_03_ImageprocessingView::CMy2020_02_03_ImageprocessingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy2020_02_03_ImageprocessingView::~CMy2020_02_03_ImageprocessingView()
{
}

BOOL CMy2020_02_03_ImageprocessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2020_02_03_ImageprocessingView �׸���

void CMy2020_02_03_ImageprocessingView::OnDraw(CDC* pDC)
{
	
	CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
   int i, j;
   unsigned char R, G, B;

	//�Է� ���� ���
   for(i=0 ; i<pDoc->m_height ; i++){
      for(j=0 ; j<pDoc->m_width ; j++){
         R = G = B = pDoc->m_InputImage[i*pDoc->m_width+j];
         pDC->SetPixel(j+5, i+5, RGB(R, G, B));
      }
   }
   // ��ҵ� ���� ���
   for(i = 0 ; i<pDoc->m_Re_height ; i++){
       for(j = 0 ; j<pDoc->m_Re_width ; j++){
           R = pDoc->m_OutputImage[i*pDoc->m_Re_width+j];
           G = B = R;
           pDC->SetPixel(j+pDoc->m_width+10, i+5, RGB(R, G, B));
       }
   }

}


// CMy2020_02_03_ImageprocessingView �μ�


void CMy2020_02_03_ImageprocessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2020_02_03_ImageprocessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2020_02_03_ImageprocessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2020_02_03_ImageprocessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2020_02_03_ImageprocessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2020_02_03_ImageprocessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2020_02_03_ImageprocessingView ����

#ifdef _DEBUG
void CMy2020_02_03_ImageprocessingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020_02_03_ImageprocessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020_02_03_ImageprocessingDoc* CMy2020_02_03_ImageprocessingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020_02_03_ImageprocessingDoc)));
	return (CMy2020_02_03_ImageprocessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020_02_03_ImageprocessingView �޽��� ó����


void CMy2020_02_03_ImageprocessingView::OnDownSampling()
{
	// TODO: Add your command handler code here
   CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
   ASSERT_VALID(pDoc);

   pDoc->OnDownSampling(); // Doc Ŭ������ OnDownSampling �Լ� ȣ��

   Invalidate(TRUE); // ȭ�� ����

}



void CMy2020_02_03_ImageprocessingView::OnUpSampling()
{
	   // TODO: Add your command handler code here
   CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
   ASSERT_VALID(pDoc);

   pDoc->OnUpSampling(); // Doc Ŭ������ OnUpSampling �Լ� ȣ��
 
   Invalidate(TRUE); // ȭ�� ����

}




void CMy2020_02_03_ImageprocessingView::OnQuantization()
{
	
   // TODO: Add your command handler code here
  CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc Ŭ���� ����
   ASSERT_VALID(pDoc);

   pDoc->OnQuantization(); // Doc Ŭ������ OnQuantization �Լ� ȣ��

   Invalidate(TRUE); // ȭ�� ����

}
