// Adopt_AnimalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Adopt_Animal.h"
#include "Adopt_AnimalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CStatic *Pchild;
CStatic *Panimal;
CString Nbox;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdoptAnimalDlg dialog



CAdoptAnimalDlg::CAdoptAnimalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADOPT_ANIMAL_DIALOG, pParent)
	, AnimalCode(_T(""))
{
	numbers = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdoptAnimalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox1);
	DDX_Text(pDX, IDC_EDIT1, AnimalCode);
	DDX_Control(pDX, IDC_LIST2, Lbox2);
}

BEGIN_MESSAGE_MAP(CAdoptAnimalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CAdoptAnimalDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDOK, &CAdoptAnimalDlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST2, &CAdoptAnimalDlg::OnLbnSelchangeList2)
	
	ON_BN_CLICKED(IDC_BUTTON3, &CAdoptAnimalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdoptAnimalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdoptAnimalDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CAdoptAnimalDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CAdoptAnimalDlg message handlers

BOOL CAdoptAnimalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Pchild = (CStatic *)GetDlgItem(IDC_STATIC);
	Panimal = (CStatic *)GetDlgItem(ANIMALS);
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdoptAnimalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAdoptAnimalDlg::OnPaint()
{
	CImage viewImage; CBitmap ViewBitmap;
	viewImage.Load(_T("res\\Child.JPG"));

	ViewBitmap.Attach(viewImage.Detach());
	Pchild->SetBitmap((HBITMAP)ViewBitmap);
	CPaintDC dc(this); // device context for painting
	CFont font;
	CRect rect;
	GetClientRect(&rect);
	font.CreatePointFont(750, _T("Arial"));
	CFont *oldFont = dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);

	CString string = _T("Adopting animals");
	
	rect.OffsetRect(10, -190);
	dc.SetTextColor(RGB(169, 219, 251));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_CENTER | DT_VCENTER);

	rect.OffsetRect(-8, -8);
	dc.SetTextColor(RGB(3, 0, 177));
	dc.DrawText(string, &rect, DT_SINGLELINE |
		DT_CENTER | DT_VCENTER);

	dc.SelectObject(oldFont);
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAdoptAnimalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAdoptAnimalDlg::OnBnClickedOk()
{
	int num = -1;
	UpdateData(TRUE);
	if (AnimalCode == _T("Tadpole"))
		num = 1;
	if (AnimalCode == _T("Frog"))
		num = 2;
	if (AnimalCode == _T("Larva"))
		num = 3;
	if (AnimalCode == _T("Cocoon"))
		num = 4; 
	if (AnimalCode == _T("Butterfly"))
		num = 5;
	setContent(num);
}

void CAdoptAnimalDlg::setContent(int num)
{
	switch (num)
	{
	case 1:
	{
		Aarr[numbers] = new Tadpole(1,_T("Tadpole"), 0);
		break;
	}
	case 2:
	{
		Aarr[numbers] = new Frog(2,_T("Frog"), 2);
		break;
	}
	case 3:
	{
		Aarr[numbers] = new Larva(3,_T("Larva"), 16);
		break;
	}
	case 4:
	{
		Aarr[numbers] = new Cocoon(4,_T("Cocoon"), 0);
		break;
	}
	case 5:
	{
		Aarr[numbers] = new Butterfly(5,_T("Butterfly"), 6);
		break;
	}
	}
	CImage viewImage;
	CBitmap ViewBitmap;
	if (num == -1)
		AfxMessageBox(_T("Wrong input!\nPlease try again"));
	else 
	{
		CString s;
		CImage viewImage;
		CBitmap ViewBitmap;
		viewImage.Load(_T("res\\") + Aarr[numbers]->Get_name() + _T(".JPG"));
		ViewBitmap.Attach(viewImage.Detach());
		Panimal->SetBitmap((HBITMAP)ViewBitmap);
		Lbox1.InsertString(numbers, Aarr[numbers]->Get_name());
		numbers++;
	}
}

void CAdoptAnimalDlg::OnLbnSelchangeList1()
{
	CImage viewImage;
	CBitmap ViewBitmap;
	CListBox * pList1 = (CListBox *)GetDlgItem(IDC_LIST1);
	int nSel = Lbox1.GetCurSel();
    int numL2 = Lbox2.GetCount();

	for(int i=0;i<numL2;i++)
		Lbox2.DeleteString(0);

	if (nSel != LB_ERR)
	{
		CString ItemSelected;
		pList1->GetText(nSel, ItemSelected);
		Nbox = ItemSelected;
		viewImage.Load(_T("res\\") + ItemSelected + _T(".JPG"));
		ViewBitmap.Attach(viewImage.Detach());
		Panimal->SetBitmap((HBITMAP)ViewBitmap);
	}

	Lbox2.AddString(_T("Voice"));
	Lbox2.AddString(_T("Habitat"));
	Lbox2.AddString(_T("Number of legs"));
	if (Nbox == _T("Frog")|| Nbox ==_T("Butterfly"))
	{
		Lbox2.AddString(_T("Abilities"));
	}
}

void CAdoptAnimalDlg::OnLbnSelchangeList2()
{
	CString numString;
	CListBox * pList2 = (CListBox *)GetDlgItem(IDC_LIST2);
	int nSel = Lbox2.GetCurSel();
	if (nSel != LB_ERR)
	{
		CString  ItemSelected2;
		pList2->GetText(nSel, ItemSelected2);
		for (int i = 0;i < 50;i++)
		{
			if (Aarr[i]->Get_name() == Nbox && ItemSelected2 == _T("Voice"))
			{
				//MessageBox(msg, title);
				MessageBox(Aarr[i]->Voice(), Aarr[i]->Get_name() + _T(" Voice:"));
				break;
			}

			if (Aarr[i]->Get_name() == Nbox && ItemSelected2 == _T("Habitat"))
			{
				MessageBox(Aarr[i]->Habitat(), Aarr[i]->Get_name() + _T("Habitat:"));
				break;
			}
			if (Aarr[i]->Get_name() == Nbox && ItemSelected2 == _T("Number of legs"))
			{
				numString.Format(_T("%d"), Aarr[i]->Get_number_of_legs());
				MessageBox(numString, Aarr[i]->Get_name() + _T("Number of legs:"));
				break;
			}
			if (Aarr[i]->Get_name() == Nbox && ItemSelected2 == _T("Abilities"))
			{
				if (Aarr[i]->Get_name() == _T("Frog"))
				{
					Frog* temp = dynamic_cast<Frog*>(Aarr[i]);
					MessageBox(temp->Abilities(), Aarr[i]->Get_name() + _T("Abilities:"));
					break;
				}
				else if (Aarr[i]->Get_name() == _T("Butterfly"))
				{
					Butterfly* temp = dynamic_cast<Butterfly*>(Aarr[i]);
					MessageBox(temp->Abilities(), Aarr[i]->Get_name() + _T("Abilities:"));
					break;
				}
			}
		}
	}
}


void CAdoptAnimalDlg::OnBnClickedButton3()
{
	int i,num1,num2, k = 0;
	CString  ItemSelected2;
	num1 = Lbox1.GetCount();
	num2 = Lbox2.GetCount();

	CListBox *pList1 = (CListBox *)GetDlgItem(IDC_LIST1);
	int nSel = Lbox1.GetCurSel();
	pList1->GetText(nSel,ItemSelected2);
		
	for (int i = 0; i < num1; i++)
		Lbox1.DeleteString(0);
	for (int i = 0; i < num2; i++)
		Lbox2.DeleteString(0);

	for (i = 0; i < numbers; i++)
	{
		if (Aarr[i]->Get_name() == ItemSelected2)
		{
			Aarr[i] = NULL;
		}
		else
		{
			Temp[k++] = Aarr[i];
		}
	}
	numbers--;
	for (i = 0; i < numbers; i++)
	{
		Aarr[i] = Temp[i];
		Lbox1.AddString(Aarr[i]->Get_name());
	}
}

void CAdoptAnimalDlg::clear()
{
	AnimalCode = _T("");
	UpdateData(false);
	Lbox1.ResetContent();
	Lbox2.ResetContent();
	for (int i = 0; i < numbers; i++)
	{
		Temp[i] = Aarr[i] = nullptr;
	}
	numbers = 0;
}

void CAdoptAnimalDlg::OnBnClickedButton1()
{
	CFile file(L"Animals.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	archive << numbers;
	for (int i = 0; i < numbers; i++)
	{
		Aarr[i]->Serialize(archive);
	}		
}

void CAdoptAnimalDlg::OnBnClickedButton2()
{
	clear();
	CFile file(L"Animals.bin", CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	int count;//how many animals
	archive >> count;
	for (int i = 0; i < count; i++)
	{
		int num;//the Type of the animal
		archive >> num;
		setContent(num);
		Aarr[i]->Serialize(archive);
	}
}

void CAdoptAnimalDlg::OnBnClickedButton4()
{
	clear();
}