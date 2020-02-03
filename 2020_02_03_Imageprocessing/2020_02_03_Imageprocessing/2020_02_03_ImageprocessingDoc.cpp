
// 2020_02_03_ImageprocessingDoc.cpp : CMy2020_02_03_ImageprocessingDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2020_02_03_Imageprocessing.h"
#endif

#include "2020_02_03_ImageprocessingDoc.h"
#include "DownSampleDlg.h" 
#include "UpSampleDlg.h"
#include "QuantizationDlg.h" // ��ȭ���� ����� ���� ��� ����
#include "math.h" // ���� �Լ� ����� ���� ��� ����

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy2020_02_03_ImageprocessingDoc

IMPLEMENT_DYNCREATE(CMy2020_02_03_ImageprocessingDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy2020_02_03_ImageprocessingDoc, CDocument)
END_MESSAGE_MAP()


// CMy2020_02_03_ImageprocessingDoc ����/�Ҹ�

CMy2020_02_03_ImageprocessingDoc::CMy2020_02_03_ImageprocessingDoc()
	: m_InputImage(NULL)
	, m_OutputImage(NULL)
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy2020_02_03_ImageprocessingDoc::~CMy2020_02_03_ImageprocessingDoc()
{
}

BOOL CMy2020_02_03_ImageprocessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy2020_02_03_ImageprocessingDoc serialization

void CMy2020_02_03_ImageprocessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy2020_02_03_ImageprocessingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMy2020_02_03_ImageprocessingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy2020_02_03_ImageprocessingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy2020_02_03_ImageprocessingDoc ����

#ifdef _DEBUG
void CMy2020_02_03_ImageprocessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy2020_02_03_ImageprocessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy2020_02_03_ImageprocessingDoc ���


BOOL CMy2020_02_03_ImageprocessingDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	      CFile File; // ���� ��ü ����

      File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);
      // ���� ���� ��ȭ���ڿ��� ������ ������ �����ϰ� �б� ��� ����

      // �� å������ ������ ũ�� 256*256, 512*512, 640*480���� ����Ѵ�.
      if(File.GetLength() == 256*256){ // RAW ������ ũ�� ����

      m_height = 256;
      m_width = 256;
   }
   else if(File.GetLength() == 512*512){ // RAW ������ ũ�� ����
      m_height = 512;
      m_width = 512;
   }
   else if(File.GetLength() == 640*480){ // RAW ������ ũ�� ����
      m_height = 480;
      m_width = 640;
   }
   else{
      AfxMessageBox(_T("Not Support Image Size")); // �ش� ũ�Ⱑ ���� ���
      return 0;
   }
   m_size = m_width * m_height; // ������ ũ�� ���

   m_InputImage = new unsigned char [m_size];
   // �Է� ������ ũ�⿡ �´� �޸� �Ҵ�

   for(int i = 0 ; i<m_size ; i++)
      m_InputImage[i] = 255; // �ʱ�ȭ
   File.Read(m_InputImage, m_size); // �Է� ���� ���� �б�
   File.Close(); // ���� �ݱ�

   return TRUE;

}


void CMy2020_02_03_ImageprocessingDoc::OnDownSampling(void)
{
	int i, j;
   CDownSampleDlg dlg;
   if(dlg.DoModal() == IDOK) // ��ȭ������ Ȱ��ȭ ����
   {
      m_Re_height = m_height / dlg.m_DownSampleRate;
      // ��� ������ ���� ���̸� ���
      m_Re_width = m_width / dlg.m_DownSampleRate;
      // ��� ������ ���� ���̸� ���
      m_Re_size = m_Re_height * m_Re_width;
      // ��� ������ ũ�⸦ ���

      m_OutputImage = new unsigned char [m_Re_size];     
      // ��� ������ ���� �޸� �Ҵ�

      for(i=0 ; i<m_Re_height ; i++){
       for(j=0 ; j<m_Re_width ; j++){
         m_OutputImage[i*m_Re_width + j]
          = m_InputImage[(i*dlg.m_DownSampleRate*m_width)+dlg.m_DownSampleRate*j];
                // ��� ������ ����
         }
     }
   }

}




void CMy2020_02_03_ImageprocessingDoc::OnUpSampling(void)
{
    int i, j;
   
   CUpSampleDlg dlg;
   if(dlg.DoModal() == IDOK){ // DoModal ��ȭ������ Ȱ��ȭ ����
       m_Re_height = m_height * dlg.m_UpSampleRate;
       // Ȯ�� ������ ���� ���� ���
       m_Re_width = m_width * dlg.m_UpSampleRate;
       // Ȯ�� ������ ���� ���� ���
       m_Re_size = m_Re_height * m_Re_width;
       // Ȯ�� ������ ũ�� ���
       m_OutputImage = new unsigned char[m_Re_size];
       // Ȯ�� ������ ���� �޸� �Ҵ�

       for(i=0 ; i<m_Re_size ; i++)
           m_OutputImage[i] = 0; // �ʱ�ȭ

       for(i=0 ; i<m_height ; i++){
           for(j=0 ; j<m_width ; j++){
              m_OutputImage[i*dlg.m_UpSampleRate*m_Re_width +
              dlg.m_UpSampleRate*j]= m_InputImage[i*m_width + j];
           } // ���ġ�Ͽ� ���� Ȯ��
       }
   }

}


void CMy2020_02_03_ImageprocessingDoc::OnQuantization(void)
{
  CQuantizationDlg dlg;
   if(dlg.DoModal() == IDOK)
   // ����ȭ ��Ʈ ���� �����ϴ� ��ȭ������ Ȱ��ȭ ����
   {
      int i, j, value, LEVEL;
      double HIGH, *TEMP;

      m_Re_height = m_height;
      m_Re_width = m_width;
      m_Re_size = m_Re_height * m_Re_width;

      m_OutputImage = new unsigned char[m_Re_size];
      // ����ȭ ó���� ������ ����ϱ� ���� �޸� �Ҵ�

      TEMP = new double [m_size];
      // �Է� ���� ũ��(m_size)�� ������ �޸� �Ҵ�

      LEVEL=256; // �Է� ������ ����ȭ �ܰ�(28=256)
      HIGH=256.;

      value = (int)pow((double)2, dlg.m_QuantBit);
      // ����ȭ �ܰ� ����(�� : 24=16)

      for(i=0 ; i<m_size ; i++){
         for(j=0 ; j<value ; j++){
            if(m_InputImage[i] >=(LEVEL/value)*j &&
               m_InputImage[i]<(LEVEL/value)*(j+1)){
                  TEMP[i]=(double)(HIGH/value)*j; // ����ȭ ����
            }
         }
      }
      for(i=0 ; i<m_size ; i++){
         m_OutputImage[i] = (unsigned char)TEMP[i];
         // ��� ���� ����
      }
   }

}
