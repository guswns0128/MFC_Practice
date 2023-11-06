
// FileInOutDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FileInOut.h"
#include "FileInOutDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileInOutDlg 대화 상자



CFileInOutDlg::CFileInOutDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILEINOUT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileInOutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileInOutDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILE, &CFileInOutDlg::OnBnClickedButtonFile)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &CFileInOutDlg::OnBnClickedButtonFind)
END_MESSAGE_MAP()


// CFileInOutDlg 메시지 처리기

BOOL CFileInOutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_thread1 = AfxBeginThread(Thread_Proc1, this);
	m_thread2 = AfxBeginThread(Thread_Proc2, this);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileInOutDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFileInOutDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileInOutDlg::OnBnClickedButtonFile()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,_T("모든파일(*.*)|*.*||"));
	

	if (Dlg.DoModal() == IDOK)
	{
		strFilePath = Dlg.GetPathName();
	}

	

}


void CFileInOutDlg::OnBnClickedButtonFind()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	
}

UINT CFileInOutDlg::Thread_Proc1(LPVOID Param)
{
	//AfxGetApp 를 사용하여 UI 스레드에 직접 접근가능하지만 정석은 PostMessage를 사용하여 접근하는 것
	//직접 접근은 권장하지 않음

	CFileInOutDlg* pMain = (CFileInOutDlg*)AfxGetApp()->m_pMainWnd;
	CString str;
	while (1)
	{
		str += "AAA\r\n";
		pMain->SetDlgItemTextW(IDC_EDIT_PRINT, str);
		Sleep(1000);
	}

	return 0;
}

UINT CFileInOutDlg::Thread_Proc2(LPVOID Param)
{
	return 0;
}


