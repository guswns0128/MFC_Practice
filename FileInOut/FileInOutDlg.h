﻿
// FileInOutDlg.h: 헤더 파일
//

#pragma once


// CFileInOutDlg 대화 상자
class CFileInOutDlg : public CDialogEx
{
// 생성입니다.
public:
	CFileInOutDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEINOUT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFile();
	CString m_strFilePath;
	afx_msg void OnBnClickedButtonFind();

	static UINT Thread_Proc1(LPVOID Param);
	static UINT Thread_Proc2(LPVOID Param);
	
	void print_string(CString strPath);

	CWinThread* m_thread1;
	CWinThread* m_thread2;

	HANDLE m_hEvent;


};
