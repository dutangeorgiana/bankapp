// bankApp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "bankApp.h"
#include "Login.h"
#include <vector>
#include <locale> 
#include <sstream>
#include  <codecvt>
#include "customer.h"
#include "Bank.h"
#include  "ui.h"

#define MAX_LOADSTRING 100


HWND hwndButtonLogin, hwndButtonCancel;
HWND txtEditHandleUser, txtEditHandlePassword = NULL;
HWND txtEditHandleName, txtEditHandleFirstName, txtEditHandleAdress, txtEditHandlePhoneNo, txtEditHandleAccountNo , txtEditHandleAmount =NULL;
HWND hwndButtonWithdrawal, hwndButtonDeposit;
HWND txtEditHandleInfoCustomer;
HWND txtEditHandleInfoCustomerTransaction, txtEditHandleNameCustomerTransaction;
HWND hwndbuttonTransactionDeposit;

void CenterWindow(HWND);
void createwindowMainMenu(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowCustomerOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowAddCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowRemoveCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowSearchCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowAccountOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowCreateAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowSearchAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowUpdateAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowDeleteAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowTransactionOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowTransactionDeposit(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowTransactionWithdrawal(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowDisplayInformationCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);
void createwindowBankOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd);

typedef struct SizeAndPos_s
{
	int x, y, width, height;
} SizeAndPos_t;

 WORD ID_User = 1;
 WORD ID_Password = 2;
 WORD ID_Login = 3;
 WORD ID_Cancel = 4;
 WORD ID_BankOption = 5;
 WORD ID_CustomerOption = 6;
 WORD ID_AccountOption = 7;
 WORD ID_TransactionOption = 8;
 WORD ID_AddCustomer = 9;
 WORD ID_RemoveCustomer = 10;
 WORD ID_SearchCustomer = 11;
 WORD ID_Save = 12;
 WORD ID_Remove = 13;
 WORD ID_Search = 14;
 WORD ID_CreateAccount = 15;
 WORD ID_SearchAccount = 16;
 WORD ID_UpdateAccount = 17;
 WORD ID_DeleteAccount = 18;
 WORD ID_Withdrawal = 19;
 DWORD ID_Deposit = 20;
 DWORD ID_TransactionDeposit = 21;


								//	x		y	  width   height
 const SizeAndPos_t loginWindow = { 600,    200,    400,    250 };
 const SizeAndPos_t mainWindow = { 1000,    500,    800,    500 };

 const SizeAndPos_t btnUser = { 150, 20, 180, 30 };
 const SizeAndPos_t btnPassword = { 150, 80, 180, 30 };
 const SizeAndPos_t btnLogin = { 150, 120, 80, 30 };
 const SizeAndPos_t btnCancel = { 250, 120, 80, 30 };


 const SizeAndPos_t btnBankOption =       {150, 50, 300, 60 };
 const SizeAndPos_t btnCustomerOption =   { 150, 120, 300, 60 };
 const SizeAndPos_t btnAccountOption =     {150,190, 300, 60 };
 const SizeAndPos_t btnTransactionOption = { 150,260, 300, 60 };


 const SizeAndPos_t btnAddCustomer = { 150, 50, 300, 60 };
 const SizeAndPos_t btnRemoveCustomer = { 150, 120, 300, 60 };
 const SizeAndPos_t btnSearchCustomer = { 150,190, 300, 60 };

 const SizeAndPos_t btnSave = { 230, 370, 150, 60 };
 const SizeAndPos_t btnRemove = { 230, 350, 150, 60 };
 const SizeAndPos_t btnSearch = { 230, 350, 150, 60 };

 const SizeAndPos_t btnCreateAccount = { 150, 50, 300, 60 };
 const SizeAndPos_t btnSearchAccount = { 150, 120,300, 60 };
 const SizeAndPos_t btnUpdateAccount = { 150,190, 300, 60 };
 const SizeAndPos_t btnDeleteAccount = { 150,260, 300, 60 };

 const SizeAndPos_t btnWithdrawal = { 150, 50, 300, 60 };
 const SizeAndPos_t btnDeposit = { 150, 120, 300, 60 };

 const SizeAndPos_t buttonTransactionDeposit = { 5, 40, 125, 40 }; 

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	
    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BANKAPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BANKAPP));

   MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BANKAPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BANKAPP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   
 
  HWND hWnd= CreateWindow(szWindowClass, L"BankApp", WS_BORDER | WS_SYSMENU | WS_CAPTION | WS_VISIBLE, loginWindow.x, loginWindow.y, loginWindow.width, loginWindow.height, NULL, 0, hInstance, NULL);
  

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

  /* if (!hWnd1)
   {
	   return FALSE;
   }

   ShowWindow(hWnd1, nCmdShow);
   UpdateWindow(hWnd1);*/

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
		switch (message)
		{
		case WM_CREATE:

			CenterWindow(hWnd);
			txtEditHandleUser = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, btnUser.x, btnUser.y, btnUser.width, btnUser.height, hWnd, (HMENU)ID_User, NULL, NULL);
			txtEditHandlePassword = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, btnUser.x, btnPassword.y, btnPassword.width, btnPassword.height, hWnd, (HMENU)ID_Password, NULL, NULL);
			CreateWindow(TEXT("Button"), TEXT("LOGIN"), WS_VISIBLE | WS_CHILD, btnLogin.x, btnLogin.y, btnLogin.width, btnLogin.height, hWnd, (HMENU)ID_Login, NULL, NULL);
			CreateWindow(TEXT("Button"), TEXT("CANCEL"), WS_VISIBLE | WS_CHILD, btnCancel.x, btnCancel.y, btnCancel.width, btnCancel.height, hWnd, (HMENU)ID_Cancel, NULL, NULL);

			break;
		case WM_COMMAND:
		{

			if (LOWORD(wParam) == ID_Cancel)
			{
				PostQuitMessage(0);
			}
			if (LOWORD(wParam) == ID_Login)
			{

				int textLength_WithNUL = GetWindowTextLength(txtEditHandleUser) + 1;
				char userName[256];
				char userPassword[256];
				
				/*using convert_type = std::codecvt_utf8<wchar_t>;
				std::wstring_convert<convert_type, wchar_t> converter;*/

				GetWindowTextA(txtEditHandleUser, &userName[0], sizeof(userName));
				GetWindowTextA(txtEditHandlePassword, &userPassword[0], sizeof(userPassword));
				
				
				
				Bank employee1;
				bool res= employee1.ValidUser(userName, userPassword);
				
				if (!res)
				{
					MessageBoxA(NULL, "Invalid user name or password", "Invalid user name or password", MB_ICONERROR | MB_OK);
				}

				else
				{
					WNDCLASSEX windowclassforwindowMainMenu;
					HWND handleforwindowMainMenu;
					int nShowCmd = 5;
					createwindowMainMenu(windowclassforwindowMainMenu, handleforwindowMainMenu, hInst, nShowCmd);
					ShowWindow( hWnd, SW_HIDE);


				}

			
			}


			int wmId = LOWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}


		}
		break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			TextOut(hdc, 10, 30, TEXT("USSER NAME: "), 12);
			TextOut(hdc, 10, 90, TEXT("PASSWORD: "), 10);
			// TODO: Add any drawing code that uses hdc here...
			EndPaint(hWnd, &ps);

		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_SETFOCUS:
			// SetFocus(GetNextDlgTabItem(GetParent((HWND)wParam), (HWND)wParam, FALSE));
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		

	
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
void CenterWindow(HWND hwnd) {

	RECT rc = { 0 };

	GetWindowRect(hwnd, &rc);
	int win_w = rc.right - rc.left;
	int win_h = rc.bottom - rc.top;

	int screen_w = GetSystemMetrics(SM_CXSCREEN);
	int screen_h = GetSystemMetrics(SM_CYSCREEN);

	SetWindowPos(hwnd, HWND_TOP, (screen_w - win_w) / 2,
		(screen_h - win_h) / 2, 0, 0, SWP_NOSIZE);
}

LRESULT CALLBACK windowprocessforwindowMainMenu(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_CREATE:
		CreateWindow(TEXT("Button"), TEXT("BANK OPTION"), WS_VISIBLE | WS_CHILD, btnBankOption.x, btnBankOption.y, btnBankOption.width, btnBankOption.height, hwnd, (HMENU)ID_BankOption, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("CUSTOMER OPTION"), WS_VISIBLE | WS_CHILD, btnCustomerOption.x, btnCustomerOption.y, btnCustomerOption.width, btnCustomerOption.height, hwnd, (HMENU)ID_CustomerOption, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("ACCOUNT OPTION"), WS_VISIBLE | WS_CHILD, btnAccountOption.x, btnAccountOption.y, btnAccountOption.width, btnAccountOption.height, hwnd, (HMENU)ID_AccountOption, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("TRANSACTION OPTION"), WS_VISIBLE | WS_CHILD, btnTransactionOption.x, btnTransactionOption.y, btnTransactionOption.width, btnTransactionOption.height, hwnd, (HMENU)ID_TransactionOption, NULL, NULL);

		break;
	case WM_DESTROY:
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_CustomerOption)
		{
			WNDCLASSEX windowclassforwindowCustomerOption;
			HWND handleforwindowCustomerOption;
			int nShowCmd = 5;
			createwindowCustomerOption(windowclassforwindowCustomerOption, handleforwindowCustomerOption, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_BankOption)
		{
			WNDCLASSEX windowclassforwindowBankOption;
			HWND handleforwindowBankOption;
			int nShowCmd = 5;
			createwindowBankOption(windowclassforwindowBankOption, handleforwindowBankOption, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_AccountOption)
		{
			WNDCLASSEX windowclassforwindowAccountOption;
			HWND handleforwindowAccountOption;
			int nShowCmd = 5;
			createwindowAccountOption(windowclassforwindowAccountOption, handleforwindowAccountOption, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_TransactionOption)
		{
			WNDCLASSEX windowclassforwindowTransactionOption;
			HWND handleforwindowTransactionOption;
			int nShowCmd = 5;
			createwindowTransactionOption(windowclassforwindowTransactionOption, handleforwindowTransactionOption, hInst, nShowCmd);
		}
			break;
		
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowMainMenu(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd) 
{
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = (WNDPROC)windowprocessforwindowMainMenu;
		wc.lpszClassName = L"wc2";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;

		if (!RegisterClassEx(&wc))
		{
			int nResult = GetLastError();
			MessageBox(NULL,
				L"Window class creation failed",
				L"Window Class Failed",
				MB_ICONERROR);
		}
		


	hwnd = CreateWindowEx(NULL,
		wc.lpszClassName,
		L"",
		WS_OVERLAPPEDWINDOW,
		200,
		170,
		640,
		480,
		NULL,
		NULL,
		hInst,
		NULL             
	);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
LRESULT CALLBACK windowprocessforwindowCustomerOption(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		CreateWindow(TEXT("Button"), TEXT("ADD CUSTOMER"), WS_VISIBLE | WS_CHILD, btnAddCustomer.x, btnAddCustomer.y, btnAddCustomer.width, btnAddCustomer.height, hwnd, (HMENU)ID_AddCustomer, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("REMOVE CUSTOMER"), WS_VISIBLE | WS_CHILD, btnRemoveCustomer.x, btnRemoveCustomer.y, btnRemoveCustomer.width, btnRemoveCustomer.height, hwnd, (HMENU)ID_RemoveCustomer, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SEARCH CUSTOMER"), WS_VISIBLE | WS_CHILD, btnSearchCustomer.x, btnSearchCustomer.y, btnSearchCustomer.width, btnSearchCustomer.height, hwnd, (HMENU)ID_SearchCustomer, NULL, NULL);
		
		break;
	case WM_DESTROY:
		
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_AddCustomer)
		{
			WNDCLASSEX windowclassforwindowAddCustomer;
			HWND handleforwindowAddCustomer;
			int nShowCmd = 5;
			createwindowAddCustomer(windowclassforwindowAddCustomer, handleforwindowAddCustomer, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_RemoveCustomer)
		{
			WNDCLASSEX windowclassforwindowRemoveCustomer;
			HWND handleforwindowRemoveCustomer;
			int nShowCmd = 5;
			createwindowRemoveCustomer(windowclassforwindowRemoveCustomer, handleforwindowRemoveCustomer, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_SearchCustomer)
		{
			WNDCLASSEX windowclassforwindowSearchCustomer;
			HWND handleforwindowSearchCustomer;
			int nShowCmd = 5;
			createwindowSearchCustomer(windowclassforwindowSearchCustomer, handleforwindowSearchCustomer, hInst, nShowCmd);
		}
		
		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowCustomerOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowCustomerOption;
	wc.lpszClassName = L"wc4";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}


LRESULT CALLBACK windowprocessforwindowAddCustomer(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:

		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 10, 300,50, hwnd, 0, NULL, NULL);
		txtEditHandleFirstName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 70, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAdress = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 130, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandlePhoneNo = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 190, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAccountNo = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 250, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAmount = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 310, 300, 50, hwnd, 0, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SAVE"), WS_VISIBLE | WS_CHILD, btnSave.x, btnSave.y, btnSave.width, btnSave.height, hwnd, (HMENU)ID_Save, NULL, NULL);

		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:

		if (LOWORD(wParam) == ID_Save)
		{

			char name[256] = { 0 };
			char firstname[256] = { 0 };
			char adress[256] = { 0 };
			char phoneNumber[256] = { 0 };
			char accountNumber[256] = { 0 };
			char amount[256] = { 0 };

			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));
			GetWindowTextA(txtEditHandleFirstName, &firstname[0], sizeof(firstname));
			GetWindowTextA(txtEditHandleAdress, &adress[0], sizeof(adress));
			GetWindowTextA(txtEditHandlePhoneNo, &phoneNumber[0], sizeof(phoneNumber));
			GetWindowTextA(txtEditHandleAccountNo, &accountNumber[0], sizeof(accountNumber));
			GetWindowTextA(txtEditHandleAmount, &amount[0], sizeof(amount));

			Customer c;
			c.addCustomerName(name);
			c.addCustomerFirstName(firstname);
			c.addCustomerAdress(adress);
			c.addCustomerPhoneNo(phoneNumber);
			c.addCustomerAccountNo(accountNumber);
			c.addCustomerAmount(amount);
		}


		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 90, 30, TEXT("NAME: "), 5);
		TextOut(hdc, 40, 90, TEXT("FIRST NAME: "), 11);
		TextOut(hdc, 60, 150, TEXT("ADRESS: "), 7);
		TextOut(hdc,5, 210, TEXT("PHONE NUMBER: "), 13);
		TextOut(hdc, 5, 270, TEXT("ACCOUNT NUMBER: "),15);
		TextOut(hdc, 70, 330, TEXT("AMOUNT: "), 7);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowAddCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{
	
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowAddCustomer;
	wc.lpszClassName = L"wc5";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
LRESULT CALLBACK windowprocessforwindowRemoveCustomer(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message) 
	{
	case WM_CREATE:

		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 300, 60, hwnd, (HMENU)ID_User, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("REMOVE"), WS_VISIBLE | WS_CHILD, btnRemove.x, btnRemove.y, btnRemove.width, btnRemove.height, hwnd, (HMENU)ID_Remove, NULL, NULL);

		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_Remove)
		{
			char name[256] = { 0 };
			infoCustomer info;

			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));


			Customer c;
			int res = c.removeCustomer(name);

			if (!res)
			{
				MessageBoxA(NULL, "Customer not found", "", MB_ICONERROR | MB_OK);
			}

		}

		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 80, 70, TEXT("NAME: "), 5);
		
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowRemoveCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowRemoveCustomer;
	wc.lpszClassName = L"wc6";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowSearchCustomer(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:

		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 300, 60, hwnd, (HMENU)ID_User, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SEARCH"), WS_VISIBLE | WS_CHILD, btnSearch.x, btnSearch.y, btnSearch.width, btnSearch.height, hwnd, (HMENU)ID_Search, NULL, NULL);
		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_Search)
		{
			char name[256] = { 0 };
			infoCustomer info;
			
			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));
			
			Customer c;
			int res = c.searchCustomer(name,info);
			
			
			WNDCLASSEX windowclassforDisplayInformationCustomer;
			HWND handleforwindowDisplayInformationCustomer;
			int nShowCmd = 5;
			createwindowDisplayInformationCustomer(windowclassforDisplayInformationCustomer, handleforwindowDisplayInformationCustomer, hInst, nShowCmd);
			
			string infoCust = string("name: ") + string(name);
			infoCust += "\r\n";
			infoCust += info.firstname;
			infoCust += "\r\n";
			infoCust += info.adress;
			infoCust += "\r\n";
			infoCust += info.phoneno;
			infoCust += "\r\n";
			infoCust += info.accountno;
			//infoCust += info.amount;
			std::ostringstream ss;
			ss << info.amount;
			infoCust += string("\r\namount: ") + ss.str();

			SetWindowTextA(txtEditHandleInfoCustomer, infoCust.c_str());
			//SetWindowText(txtEditHandleInfoCustomer, TEXT("\r\nFirst string\r\n\r\nSecond string"));

			if (!res)
			{
				MessageBoxA(NULL, "Customer not found", "", MB_ICONERROR | MB_OK);
			}
			
		}

		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 80, 70, TEXT("NAME: "), 5);

		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowSearchCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowSearchCustomer;
	wc.lpszClassName = L"wc7";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowAccountOption(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		CreateWindow(TEXT("Button"), TEXT("CREATE ACCOUNT"), WS_VISIBLE | WS_CHILD, btnCreateAccount.x, btnCreateAccount.y, btnCreateAccount.width, btnCreateAccount.height, hwnd, (HMENU)ID_CreateAccount, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SEARCH ACCOUNT"), WS_VISIBLE | WS_CHILD, btnSearchAccount.x, btnSearchAccount.y, btnSearchAccount.width, btnSearchAccount.height, hwnd, (HMENU)ID_SearchAccount, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("UPDATE ACCOUNT"), WS_VISIBLE | WS_CHILD, btnUpdateAccount.x, btnUpdateAccount.y, btnUpdateAccount.width, btnUpdateAccount.height, hwnd, (HMENU)ID_UpdateAccount, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("DELETE ACCOUNT"), WS_VISIBLE | WS_CHILD, btnDeleteAccount.x, btnDeleteAccount.y, btnDeleteAccount.width, btnDeleteAccount.height, hwnd, (HMENU)ID_DeleteAccount, NULL, NULL);

		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_CreateAccount)
		{
			WNDCLASSEX windowclassforwindowCreateAccount;
			HWND handleforwindowCreateAccount;
			int nShowCmd = 5;
			createwindowCreateAccount(windowclassforwindowCreateAccount, handleforwindowCreateAccount, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_SearchAccount)
		{
			WNDCLASSEX windowclassforwindowSearchAccount;
			HWND handleforwindowSearchAccount;
			int nShowCmd = 5;
			createwindowSearchAccount(windowclassforwindowSearchAccount, handleforwindowSearchAccount, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_UpdateAccount)
		{
			WNDCLASSEX windowclassforwindowUpdateAccount;
			HWND handleforwindowpdateAccount;
			int nShowCmd = 5;
			createwindowUpdateAccount(windowclassforwindowUpdateAccount, handleforwindowpdateAccount, hInst, nShowCmd);
		}
		if (LOWORD(wParam) == ID_DeleteAccount)
		{
			WNDCLASSEX windowclassforwindowDeleteAccount;
			HWND handleforwindowDeleteAccount;
			int nShowCmd = 5;
			createwindowDeleteAccount(windowclassforwindowDeleteAccount, handleforwindowDeleteAccount, hInst, nShowCmd);
		}
	

		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowAccountOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowAccountOption;
	wc.lpszClassName = L"wc8";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowCreateAccount(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:

		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 10, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleFirstName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 70, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAdress = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 130, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandlePhoneNo = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 190, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAccountNo = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 250, 300, 50, hwnd, 0, NULL, NULL);
		txtEditHandleAmount = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 310, 300, 50, hwnd, 0, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SAVE"), WS_VISIBLE | WS_CHILD, btnSave.x, btnSave.y, btnSave.width, btnSave.height, hwnd, (HMENU)ID_Save, NULL, NULL);

		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:

		if (LOWORD(wParam) == ID_Save)
		{
			char name[256] = { 0 };
			char firstname[256] = { 0 };
			char adress[256] = { 0 };
			char phoneNumber[256] = { 0 };
			char accountNumber[256] = { 0 };
			char amount[256] = { 0 };

			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));
			GetWindowTextA(txtEditHandleFirstName, &firstname[0], sizeof(firstname));
			GetWindowTextA(txtEditHandleAdress, &adress[0], sizeof(adress));
			GetWindowTextA(txtEditHandlePhoneNo, &phoneNumber[0], sizeof(phoneNumber));
			GetWindowTextA(txtEditHandleAccountNo, &accountNumber[0], sizeof(accountNumber));
			GetWindowTextA(txtEditHandleAmount, &amount[0], sizeof(amount));

			Customer c;
			c.addCustomerName(name);
			c.addCustomerFirstName(firstname);
			c.addCustomerAdress(adress);
			c.addCustomerPhoneNo(phoneNumber);
			c.addCustomerAccountNo(accountNumber);
			c.addCustomerAmount(amount);

		}
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 90, 30, TEXT("NAME: "), 5);
		TextOut(hdc, 40, 90, TEXT("FIRST NAME: "), 11);
		TextOut(hdc, 60, 150, TEXT("ADRESS: "), 7);
		TextOut(hdc, 5, 210, TEXT("PHONE NUMBER: "), 13);
		TextOut(hdc, 5, 270, TEXT("ACCOUNT NUMBER: "), 15);
		TextOut(hdc, 70, 330, TEXT("AMOUNT: "), 7);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowCreateAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowCreateAccount;
	wc.lpszClassName = L"wc9";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowSearchAccount(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_CREATE:

		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 300, 60, hwnd, (HMENU)ID_User, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("SEARCH"), WS_VISIBLE | WS_CHILD, btnSearch.x, btnSearch.y, btnSearch.width, btnSearch.height, hwnd, (HMENU)ID_Search, NULL, NULL);
		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_Search)
		{
			char name[256] = { 0 };
			infoCustomer info;

			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));

			Customer c;
			int res = c.searchCustomer(name, info);


			WNDCLASSEX windowclassforDisplayInformationCustomer;
			HWND handleforwindowDisplayInformationCustomer;
			int nShowCmd = 5;
			createwindowDisplayInformationCustomer(windowclassforDisplayInformationCustomer, handleforwindowDisplayInformationCustomer, hInst, nShowCmd);

			string infoCust = string("name: ") + string(name);
			infoCust += "\r\n";
			infoCust += info.firstname;
			infoCust += "\r\n";
			infoCust += info.adress;
			infoCust += "\r\n";
			infoCust += info.phoneno;
			infoCust += "\r\n";
			infoCust += info.accountno;
			//infoCust += info.amount;
			std::ostringstream ss;
			ss << info.amount;
			infoCust += string("\r\namount: ") + ss.str();

			SetWindowTextA(txtEditHandleInfoCustomer, infoCust.c_str());
			//SetWindowText(txtEditHandleInfoCustomer, TEXT("\r\nFirst string\r\n\r\nSecond string"));

			if (!res)
			{
				MessageBoxA(NULL, "Customer not found", "", MB_ICONERROR | MB_OK);
			}

		}


		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 80, 70, TEXT("NAME: "), 5);

		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowSearchAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowSearchAccount;
	wc.lpszClassName = L"wc10";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowUpdateAccount(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:


		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:


		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowUpdateAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowUpdateAccount;
	wc.lpszClassName = L"wc11";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
LRESULT CALLBACK windowprocessforwindowDeleteAccount(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) 
	{
	case WM_CREATE:
		txtEditHandleName = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 300, 60, hwnd, 0, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("REMOVE"), WS_VISIBLE | WS_CHILD, btnRemove.x, btnRemove.y, btnRemove.width, btnRemove.height, hwnd, (HMENU)ID_Remove, NULL, NULL);


		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:


		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		
		TextOut(hdc, 80, 70, TEXT("NAME: "), 5);

		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowDeleteAccount(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowDeleteAccount;
	wc.lpszClassName = L"wc12";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowTransactionOption(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) 
	{
	case WM_CREATE:

		CreateWindow(TEXT("Button"), TEXT("WITHDRAWAL"), WS_VISIBLE | WS_CHILD, btnWithdrawal.x, btnWithdrawal.y, btnWithdrawal.width, btnWithdrawal.height, hwnd, (HMENU)ID_Withdrawal, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("DEPOSIT"), WS_VISIBLE | WS_CHILD, btnDeposit.x, btnDeposit.y, btnDeposit.width, btnDeposit.height, hwnd, (HMENU)ID_Deposit, NULL, NULL);
		
		
		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_Withdrawal)
		{
			WNDCLASSEX windowclassforwindowWithdrawal;
			HWND handleforwindowWithdrawal;
			int nShowCmd = 5;
			createwindowTransactionWithdrawal(windowclassforwindowWithdrawal, handleforwindowWithdrawal, hInst, nShowCmd);
		}

			if (LOWORD(wParam) == ID_Deposit)
		{
			WNDCLASSEX windowclassforwindowDeposit;
			HWND handleforwindowDeposit;
			int nShowCmd = 5;
			createwindowTransactionDeposit(windowclassforwindowDeposit, handleforwindowDeposit, hInst, nShowCmd);
		}

		

		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowTransactionOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowTransactionOption;
	wc.lpszClassName = L"wc13";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowTransactionWithdrawal(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_CREATE:


		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:

		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

	
void createwindowTransactionWithdrawal(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowTransactionWithdrawal;
	wc.lpszClassName = L"wc14";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}



LRESULT CALLBACK windowprocessforwindowTransactionDeposit(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_CREATE:

		txtEditHandleNameCustomerTransaction = CreateWindow(TEXT("Edit"), TEXT(" "), WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 40, 200, 40, hwnd, 0, NULL, NULL);
		CreateWindow(TEXT("Button"), TEXT("Search Customer"), WS_VISIBLE | WS_CHILD, buttonTransactionDeposit.x, buttonTransactionDeposit.y, buttonTransactionDeposit.width, buttonTransactionDeposit.height, hwnd, (HMENU)ID_TransactionDeposit, NULL, NULL);
		txtEditHandleInfoCustomerTransaction = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE, 200,100, 200, 100, hwnd, 0, NULL, NULL);


		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_TransactionDeposit)
		{
			char name[256] = { 0 };
			infoCustomer info;

			GetWindowTextA(txtEditHandleName, &name[0], sizeof(name));

			Customer c;
			int res = c.searchCustomer(name, info);


		

			string infoCust = string("name: ") + string(name);
			infoCust += "\r\n";
			infoCust += info.firstname;
			infoCust += "\r\n";
			infoCust += info.adress;
			infoCust += "\r\n";
			infoCust += info.phoneno;
			infoCust += "\r\n";
			infoCust += info.accountno;
			//infoCust += info.amount;
			std::ostringstream ss;
			ss << info.amount;
			infoCust += string("\r\namount: ") + ss.str();

			SetWindowTextA(txtEditHandleInfoCustomerTransaction, infoCust.c_str());
			//SetWindowText(txtEditHandleInfoCustomer, TEXT("\r\nFirst string\r\n\r\nSecond string"));

			if (!res)
			{
				MessageBoxA(NULL, "Customer not found", "", MB_ICONERROR | MB_OK);
			}

		}


		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowTransactionDeposit(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowTransactionDeposit;
	wc.lpszClassName = L"wc15";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}
LRESULT CALLBACK windowprocessforwindowDisplayInformationCustomer(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_CREATE:

		txtEditHandleInfoCustomer = CreateWindow(TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE, 150, 50, 300, 300, hwnd, 0, NULL, NULL);
		



		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:

		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);

	}
	break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowDisplayInformationCustomer(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowDisplayInformationCustomer;
	wc.lpszClassName = L"wc16";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}

LRESULT CALLBACK windowprocessforwindowBankOption(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_CREATE:
		
		break;
	case WM_DESTROY:

		break;
	case WM_COMMAND:
		
		break;

	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void createwindowBankOption(WNDCLASSEX& wc, HWND& hwnd, HINSTANCE hInst, int nShowCmd)
{

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInst;
	wc.lpfnWndProc = (WNDPROC)windowprocessforwindowBankOption;
	wc.lpszClassName = L"wc17";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
			L"Window class creation failed",
			L"Window Class Failed",
			MB_ICONERROR);
	}

	hwnd = CreateWindowEx(NULL, wc.lpszClassName, L"", WS_OVERLAPPEDWINDOW, 500, 170, 640, 480, NULL, NULL, hInst, NULL);

	if (!hwnd)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hwnd, nShowCmd);
}







