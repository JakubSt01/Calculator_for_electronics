
// ele_calcDlg.h : header file
//

#pragma once


class user_interface {
public:

	void set_output(string data);

	string get_output();
	string get_history();
	void clear();
	void clear_last();

	void simple_calculator(string data);

private:
	string history;
	string output;
	string expression;

	string previous_sign;
	string actual_number;

	double memory;
	bool is_dot_added;
	bool is_NaN;
	bool is_negative;

};




// CelecalcDlg dialog
class CelecalcDlg : public CDialogEx
{
// Construction
public:
	CelecalcDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ELE_CALC_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonBin();
	afx_msg void OnBnClickedButtonOct();
	afx_msg void OnBnClickedButtonDec();
	afx_msg void OnBnClickedButtonHex();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSubtract();
	afx_msg void OnEnChangeInputExpressions();
	afx_msg void OnEnChangeInputHistory();
	afx_msg void OnEnChangeOutput();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonClearLast();

	void on_init_settings();

	CFont button_font, text_font, system_exchange_font;
	CButton button_2;
	CButton button_1;
	CButton button_3;
	CButton button_4;
	CButton button_5;
	CButton button_6;
	CButton button_7;
	CButton button_8;
	CButton button_9;
	CButton button_dot;
	CButton button_0;
	CButton button_equals;
	CButton button_bin;
	CButton button_oct;
	CButton button_dec;
	CButton button_hex;
	CButton button_multiply;
	CButton button_divide;
	CButton button_add;
	CButton button_subtract;

	CEdit c_expressions;
	CEdit c_history;
	CEdit c_output;
	CString c_output_text;
	CString c_history_text;
	CString c_expressions_text;



	data_converter::data_validation converter;
	user_interface user_interface;

	CButton button_eval_exp;
	CButton button_clear;
	CButton button_clear_last;
};


