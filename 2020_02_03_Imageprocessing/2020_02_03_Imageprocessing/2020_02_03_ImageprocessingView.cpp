
// 2020_02_03_ImageprocessingView.cpp : CMy2020_02_03_ImageprocessingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2020_02_03_ImageprocessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CHAPTER3_DOWNSAMPLE, &CMy2020_02_03_ImageprocessingView::OnDownSampling)
	ON_COMMAND(ID_CHAPTER3_UPSAMPLE, &CMy2020_02_03_ImageprocessingView::OnUpSampling)
	ON_COMMAND(ID_CHAPTER3_QUANTIZATION, &CMy2020_02_03_ImageprocessingView::OnQuantization)
END_MESSAGE_MAP()

// CMy2020_02_03_ImageprocessingView 생성/소멸

CMy2020_02_03_ImageprocessingView::CMy2020_02_03_ImageprocessingView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy2020_02_03_ImageprocessingView::~CMy2020_02_03_ImageprocessingView()
{
}

BOOL CMy2020_02_03_ImageprocessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2020_02_03_ImageprocessingView 그리기

void CMy2020_02_03_ImageprocessingView::OnDraw(CDC* pDC)
{
	
	CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
   int i, j;
   unsigned char R, G, B;

	//입력 영상 출력
   for(i=0 ; i<pDoc->m_height ; i++){
      for(j=0 ; j<pDoc->m_width ; j++){
         R = G = B = pDoc->m_InputImage[i*pDoc->m_width+j];
         pDC->SetPixel(j+5, i+5, RGB(R, G, B));
      }
   }
   // 축소된 영상 출력
   for(i = 0 ; i<pDoc->m_Re_height ; i++){
       for(j = 0 ; j<pDoc->m_Re_width ; j++){
           R = pDoc->m_OutputImage[i*pDoc->m_Re_width+j];
           G = B = R;
           pDC->SetPixel(j+pDoc->m_width+10, i+5, RGB(R, G, B));
       }
   }

}


// CMy2020_02_03_ImageprocessingView 인쇄


void CMy2020_02_03_ImageprocessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2020_02_03_ImageprocessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2020_02_03_ImageprocessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2020_02_03_ImageprocessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2020_02_03_ImageprocessingView 진단

#ifdef _DEBUG
void CMy2020_02_03_ImageprocessingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020_02_03_ImageprocessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020_02_03_ImageprocessingDoc* CMy2020_02_03_ImageprocessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020_02_03_ImageprocessingDoc)));
	return (CMy2020_02_03_ImageprocessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020_02_03_ImageprocessingView 메시지 처리기


void CMy2020_02_03_ImageprocessingView::OnDownSampling()
{
	// TODO: Add your command handler code here
   CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

   Invalidate(TRUE); // 화면 갱신

}



void CMy2020_02_03_ImageprocessingView::OnUpSampling()
{
	   // TODO: Add your command handler code here
   CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출
 
   Invalidate(TRUE); // 화면 갱신

}




void CMy2020_02_03_ImageprocessingView::OnQuantization()
{
	
   // TODO: Add your command handler code here
  CMy2020_02_03_ImageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
   ASSERT_VALID(pDoc);

   pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

   Invalidate(TRUE); // 화면 갱신

}
