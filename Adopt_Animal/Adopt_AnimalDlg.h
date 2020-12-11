
// Adopt_AnimalDlg.h : header file
//
#include "Animals.h"
#pragma once


// CAdoptAnimalDlg dialog
class CAdoptAnimalDlg : public CDialogEx
{
// Construction
public:
	int numbers;
	Animals *Aarr[100];
	Animals *Temp[100];
	CAdoptAnimalDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADOPT_ANIMAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void setContent(int);
	void clear();
	CListBox Lbox1;
	CString AnimalCode;
	CListBox Lbox2;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeList2();

	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
//	afx_msg void OnAcnStartAnimate1();
};
