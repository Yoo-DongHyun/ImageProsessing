
// 2020_02_03_ImageprocessingDoc.h : CMy2020_02_03_ImageprocessingDoc Ŭ������ �������̽�
//


#pragma once


class CMy2020_02_03_ImageprocessingDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy2020_02_03_ImageprocessingDoc();
	DECLARE_DYNCREATE(CMy2020_02_03_ImageprocessingDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMy2020_02_03_ImageprocessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	unsigned char*m_InputImage;
	int m_height;
	int m_width;
	int m_size;
	void OnDownSampling(void);
	unsigned char*m_OutputImage;
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;
	void OnUpSampling(void);
	void OnQuantization(void);
};
