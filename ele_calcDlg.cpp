
// ele_calcDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ele_calc.h"
#include "ele_calcDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CelecalcDlg dialog



CelecalcDlg::CelecalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ELE_CALC_DIALOG, pParent)
	, c_output_text(_T(""))
	, c_history_text(_T(""))
	, c_expressions_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CelecalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_2, button_2);
	DDX_Control(pDX, IDC_BUTTON_1, button_1);
	DDX_Control(pDX, IDC_BUTTON3, button_3);
	DDX_Control(pDX, IDC_BUTTON_4, button_4);
	DDX_Control(pDX, IDC_BUTTON_5, button_5);
	DDX_Control(pDX, IDC_BUTTON_6, button_6);
	DDX_Control(pDX, IDC_BUTTON_7, button_7);
	DDX_Control(pDX, IDC_BUTTON_8, button_8);
	DDX_Control(pDX, IDC_BUTTON_9, button_9);
	DDX_Control(pDX, IDC_BUTTON_DOT, button_dot);
	DDX_Control(pDX, IDC_BUTTON_0, button_0);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, button_equals);
	DDX_Control(pDX, IDC_BUTTON_BIN, button_bin);
	DDX_Control(pDX, IDC_BUTTON_OCT, button_oct);
	DDX_Control(pDX, IDC_BUTTON_DEC, button_dec);
	DDX_Control(pDX, IDC_BUTTON_HEX, button_hex);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, button_multiply);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, button_divide);
	DDX_Control(pDX, IDC_BUTTON_ADD, button_add);
	DDX_Control(pDX, IDC_BUTTON_SUBTRACT, button_subtract);
	DDX_Control(pDX, IDC_INPUT_EXPRESSIONS, c_expressions);
	DDX_Control(pDX, IDC_INPUT_HISTORY, c_history);
	DDX_Control(pDX, IDC_OUTPUT, c_output);
	DDX_Text(pDX, IDC_OUTPUT, c_output_text);
	DDX_Text(pDX, IDC_INPUT_HISTORY, c_history_text);
	DDX_Text(pDX, IDC_INPUT_EXPRESSIONS, c_expressions_text);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, button_clear);
	DDX_Control(pDX, IDC_BUTTON_CLEAR_LAST, button_clear_last);
}

BEGIN_MESSAGE_MAP(CelecalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CelecalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CelecalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CelecalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CelecalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CelecalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CelecalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CelecalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CelecalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CelecalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CelecalcDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_0, &CelecalcDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CelecalcDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_BIN, &CelecalcDlg::OnBnClickedButtonBin)
	ON_BN_CLICKED(IDC_BUTTON_OCT, &CelecalcDlg::OnBnClickedButtonOct)
	ON_BN_CLICKED(IDC_BUTTON_DEC, &CelecalcDlg::OnBnClickedButtonDec)
	ON_BN_CLICKED(IDC_BUTTON_HEX, &CelecalcDlg::OnBnClickedButtonHex)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CelecalcDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CelecalcDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CelecalcDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &CelecalcDlg::OnBnClickedButtonSubtract)
	ON_EN_CHANGE(IDC_INPUT_EXPRESSIONS, &CelecalcDlg::OnEnChangeInputExpressions)
	ON_EN_CHANGE(IDC_INPUT_HISTORY, &CelecalcDlg::OnEnChangeInputHistory)
	ON_EN_CHANGE(IDC_OUTPUT, &CelecalcDlg::OnEnChangeOutput)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CelecalcDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_LAST, &CelecalcDlg::OnBnClickedButtonClearLast)
END_MESSAGE_MAP()


// CelecalcDlg message handlers

BOOL CelecalcDlg::OnInitDialog()
{
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
	// init of class that will contain modifications 

	on_init_settings();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CelecalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CelecalcDlg::OnPaint()
{
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
HCURSOR CelecalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void user_interface::simple_calculator(string data) {
	if (data == "-") {
		output += "-";
		if(output.size() < 2 )
			previous_sign = '-';
	}

	if (output.size() == 0) return;

	if (data == "+") {
		output += "+";
	}
	if (data == "*") {
		output += "*";
	}
	if (data == "/") {
		output += "/";
	}
	if (actual_number == "" && output.size()>1)
	{

		previous_sign = data;
		output.erase(output.size() - 2, 1);
		return;
	}
	if (actual_number == "") return;

	try {
		if (previous_sign == "+") {
			memory +=stod(actual_number);
		}
		else if (previous_sign == "-") {
			memory -=stod(actual_number);
		}
		else if (previous_sign == "*") {
			memory *=stod(actual_number);
		}
		else if (previous_sign == "/") {
			if (actual_number == "0") {
				is_NaN = true;
			}
			else {
				memory /=  stod(actual_number);

			}
		}
		else {
			memory =  stod(actual_number);

		}
	}
	catch (...) {
		is_NaN = true;
	}
	actual_number = "";
	if (is_NaN) {
		history += "NaN\n\r\n";
		output = "NaN";
		clear();
		return;
	}

	if ( data == "=") {
		try {
			history += output;
			output = std::to_string(memory);
			history += "=" + output + "\n\r\n";
			actual_number = output;
		}
		catch (...) {
			output = "NaN";
		}
	}
	previous_sign = data;
}


void user_interface::set_output(string data ) {
	if (is_NaN || previous_sign == "=" ){
		clear();
	}
	if (output == "0") {
		if (data == "0") return;
		actual_number += data;
		output = data;
	}
	else {
		if (data == "." ) {
			if (!is_dot_added && output != "") {
				output += data;
				actual_number += data;
				is_dot_added = true;
			}
		}
		else {
			actual_number += data;
			output += data;
		}
	}
}

string user_interface::get_output() {
	return output;
}

string user_interface::get_history() {
	return history;
}

void user_interface::clear() {
	is_negative = false;
	is_NaN = false;
	output = "";
	actual_number = "";
	memory = 0;
	previous_sign = "";
}

void user_interface::clear_last() {
	if (actual_number.size() > 0 && output.size() > 0) {
		actual_number = actual_number.substr(0,actual_number.size()-1);
		output = output.substr(0, output.size() - 1);
	}
}


void CelecalcDlg::on_init_settings(){
	//mainly visual settings

	button_font.CreateFont(
		32,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_LIGHT,                // nWeight
		FALSE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("Open Sans"));        // lpszFacename

	system_exchange_font.CreateFont(
		24,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_LIGHT,                // nWeight
		FALSE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("Open Sans"));        // lpszFacename

	 button_0.SetFont(&button_font);
	 button_1.SetFont(&button_font);
	 button_2.SetFont(&button_font);
	 button_3.SetFont(&button_font);
	 button_4.SetFont(&button_font);
	 button_5.SetFont(&button_font);
	 button_6.SetFont(&button_font);
	 button_7.SetFont(&button_font);
	 button_8.SetFont(&button_font);
	 button_9.SetFont(&button_font);
	 button_dot.SetFont(&button_font);
	 button_equals.SetFont(&button_font);
	 button_bin.SetFont(&system_exchange_font);
	 button_oct.SetFont(&system_exchange_font);
	 button_dec.SetFont(&system_exchange_font);
	 button_hex.SetFont(&system_exchange_font);
	 button_multiply.SetFont(&button_font);
	 button_divide.SetFont(&button_font);
	 button_add.SetFont(&button_font);
	 button_subtract.SetFont(&button_font);
	 button_clear.SetFont(&system_exchange_font);
	 button_clear_last.SetFont(&system_exchange_font);



	text_font.CreateFont(
		36,                       // nHeight
		0,                        // nWidth
		0,                        // nEscapement
		0,                        // nOrientation
		FW_NORMAL,                // nWeight
		FALSE,                    // bItalic
		FALSE,                    // bUnderline
		0,                        // cStrikeOut
		ANSI_CHARSET,             // nCharSet
		OUT_DEFAULT_PRECIS,       // nOutPrecision
		CLIP_DEFAULT_PRECIS,      // nClipPrecision
		DEFAULT_QUALITY,          // nQuality
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
		_T("Open Sans"));         // lpszFacename

	c_history.SetFont(&text_font);
	c_output.SetFont(&text_font);
	c_expressions.SetFont(&text_font);
}

void CelecalcDlg::OnBnClickedButton1()
{
	user_interface.set_output("1");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton2()
{
	user_interface.set_output("2");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton3()
{
	user_interface.set_output("3");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton4()
{
	user_interface.set_output("4");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton5()
{
	user_interface.set_output("5");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton6()
{
	user_interface.set_output("6");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton7()
{
	user_interface.set_output("7");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton8()
{
	user_interface.set_output("8");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton9()
{
	user_interface.set_output("9");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButtonDot()
{
	user_interface.set_output(".");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButton0()
{
	user_interface.set_output("0");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


#include <cstring>
void CelecalcDlg::OnBnClickedButtonEquals()
{
	user_interface.simple_calculator("=");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;

	CA2CT buffer2(user_interface.get_history().c_str());
	c_history_text = buffer2 + CString(_T("\n"));
	UpdateData(false);

}


void CelecalcDlg::OnBnClickedButtonBin()
{

	UpdateData(true);
	CT2A convertedString(c_expressions_text);
	string input(convertedString);

	if (converter.validate_data(input)) {
		CString converted_CString(converter.converter.BIN_handler().c_str());
		c_output_text = converted_CString;
	}
	else
	{
		c_output_text = "Wrong Data";

	}
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButtonOct()
{

	UpdateData(true);
	CT2A convertedString(c_expressions_text);
	string input(convertedString);

	if (converter.validate_data(input)) {
		CString converted_CString(converter.converter.OCT_handler().c_str());
		c_output_text = converted_CString;
	}
	else
	{
		c_output_text = "Wrong Data";

	}
	UpdateData(false);
}



void CelecalcDlg::OnBnClickedButtonDec()
{
	UpdateData(true);
	CT2A convertedString(c_expressions_text);
	string input(convertedString);

	if (converter.validate_data(input)) {
		CString converted_CString(converter.converter.DEC_handler().c_str());
		c_output_text = converted_CString;
	}
	else
	{
		c_output_text = "Wrong Data";

	}
	UpdateData(false);
}




void CelecalcDlg::OnBnClickedButtonHex()
{
	UpdateData(true);
	CT2A convertedString(c_expressions_text);
	string input(convertedString);

	if (converter.validate_data(input)) {
		CString converted_CString(converter.converter.HEX_handler().c_str());
		c_output_text = converted_CString;
	}
	else
	{
		c_output_text = "Wrong Data";

	}
	UpdateData(false);
}




void CelecalcDlg::OnBnClickedButtonMultiply()
{
	user_interface.simple_calculator("*");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButtonDivide()
{
	user_interface.simple_calculator("/");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButtonAdd()
{
	user_interface.simple_calculator("+");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnBnClickedButtonSubtract()
{
	user_interface.simple_calculator("-");
	CA2CT buffer(user_interface.get_output().c_str());
	c_output_text = buffer;
	UpdateData(false);
}


void CelecalcDlg::OnEnChangeInputExpressions()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CelecalcDlg::OnEnChangeInputHistory()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CelecalcDlg::OnEnChangeOutput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CelecalcDlg::OnBnClickedButtonClear()
{
	user_interface.clear();
	c_output_text = "";
	UpdateData(false);

}




void CelecalcDlg::OnBnClickedButtonClearLast()
{

	user_interface.clear_last();

	// delete last item on display
	if (!c_output_text.IsEmpty()) {
		c_output_text.Delete(c_output_text.GetLength() - 1);
	}

	UpdateData(false);
	// TODO: Add your control notification handler code here
}
