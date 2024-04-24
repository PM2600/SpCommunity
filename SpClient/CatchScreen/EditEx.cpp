// EditEx.cpp : implementation file
//

#include "stdafx.h"
#include "EditEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CEditEx


CEditEx::CEditEx()
{
	m_bMove = TRUE;
}

CEditEx::~CEditEx()
{
}


BEGIN_MESSAGE_MAP(CEditEx, CEdit)
	//{{AFX_MSG_MAP(CEditEx)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_SETFOCUS()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditEx message handlers




int CEditEx::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here
	return 0;
}

void CEditEx::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect rect;
	GetWindowRect(&rect);

	int xScreen = GetSystemMetrics(SM_CXSCREEN);

	if (m_bMove)
	{
		//�ƶ������Ͻ�
		MoveWindow(10, 10, rect.Width(), rect.Height());
		m_bMove = FALSE;
	}
	else
	{
		//�ƶ������Ͻ�
		MoveWindow(xScreen - rect.Width(), 10, rect.Width(), rect.Height());
		m_bMove = TRUE;
	}
	//**************************************************************************************
	CEdit::OnMouseMove(nFlags, point);
}

void CEditEx::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);
	//**********************************************************************************
	   //���ع����ʾ��,��ʵҲ�ò���
	this->HideCaret();
	//*********************************************************************************
		// TODO: Add your message handler code here	
}



HBRUSH CEditEx::CtlColor(CDC* pDC, UINT nCtlColor)
{
	//***************************************************************************************
	//�������ֱ���͸��
	pDC->SetBkMode(TRANSPARENT);
	//**************************************************************************************
	return NULL;
}

BOOL CEditEx::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
//**************************************************************************************
	//ȡ�����ָ�ѡ
	SetSel(0, 0);

	//����λͼ����
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect(rect, &brush);
	return TRUE;
	//*********************************************************************************
}