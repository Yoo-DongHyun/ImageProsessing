// UpSampleDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2020_02_03_Imageprocessing.h"
#include "UpSampleDlg.h"
#include "afxdialogex.h"


// CUpSampleDlg ��ȭ �����Դϴ�.

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


// CUpSampleDlg �޽��� ó�����Դϴ�.


void CUpSampleDlg::OnUpSampling()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
