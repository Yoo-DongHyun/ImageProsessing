
// 2020_02_03_ImageprocessingDoc.h : CMy2020_02_03_ImageprocessingDoc 클래스의 인터페이스
//


#pragma once


class CMy2020_02_03_ImageprocessingDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMy2020_02_03_ImageprocessingDoc();
	DECLARE_DYNCREATE(CMy2020_02_03_ImageprocessingDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMy2020_02_03_ImageprocessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
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
