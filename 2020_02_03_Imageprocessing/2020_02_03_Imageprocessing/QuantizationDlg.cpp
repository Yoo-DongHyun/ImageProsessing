// QuantizationDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "2020_02_03_Imageprocessing.h"
#include "QuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg ��ȭ �����Դϴ�.

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


// CQuantizationDlg �޽��� ó�����Դϴ�.


void CQuantizationDlg::OnQuantization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
