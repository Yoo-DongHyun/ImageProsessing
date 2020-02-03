// QuantizationDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "2020_02_03_Imageprocessing.h"
#include "QuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialog)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQuantizationDlg::IDD, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
	DDV_MinMaxInt(pDX, m_QuantBit, 1, 8);
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialog)
	ON_COMMAND(ID_CHAPTER3_QUANTIZATION, &CQuantizationDlg::OnQuantization)
END_MESSAGE_MAP()


// CQuantizationDlg 메시지 처리기입니다.


void CQuantizationDlg::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
