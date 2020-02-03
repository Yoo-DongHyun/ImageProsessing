// UpSampleDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "2020_02_03_Imageprocessing.h"
#include "UpSampleDlg.h"
#include "afxdialogex.h"


// CUpSampleDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUpSampleDlg, CDialog)

CUpSampleDlg::CUpSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpSampleDlg::IDD, pParent)
	, m_UpSampleRate(0)
{

}

CUpSampleDlg::~CUpSampleDlg()
{
}

void CUpSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSampleDlg, CDialog)
	ON_COMMAND(ID_CHAPTER3_UPSAMPLE, &CUpSampleDlg::OnUpSampling)
END_MESSAGE_MAP()


// CUpSampleDlg 메시지 처리기입니다.


void CUpSampleDlg::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
