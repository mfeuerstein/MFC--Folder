
#include <afxwin.h>
#include <afxdlgs.h>
#include "resource.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include "MoveFileDialog.h"
#include "CopyFileDialog.h"
#include "NewFileDialog.h"
#include "TypeDialog.h"
#include "RemoveDirDialog.h"
#include "RenameDialog.h"
#include "DirDialog.h"
//#include "SplashDlg.h"
#define IDC_EDIT 500
using namespace std;
//Define filters for use with File Dialog
const char fileDialogFilter[] =
"C++ Files (*.cpp) | *.cpp|Header Files\
(*.h)|*.h|Resource Files (*.rc) | *.rc |Text Files (*.txt)|*.txt| All Files (*.*)| *.*||";
const char fileDialogExt[] = "cpp";
  
	
	CString findString;
	CString fDog;
	CString fDEfileDialogExt = CString(fileDialogExt);
	CString fDEfileDialogFilter = CString(fileDialogFilter);
	

//Define the application object class


class CApp: public CWinApp
{
public:
	virtual BOOL InitInstance();
} ;


//Define the edit window class


class CWindow : public CFrameWnd
{
 private:
	 static UINT findMessage;
	 CMenu *menu;
	CEdit m_edit;

	 
 public:
	CWindow();
	afx_msg void HandleOpen();
	afx_msg void HandlePrint();
	afx_msg void HandleQuit();
	afx_msg void HandleFind();
	afx_msg void HandleDelete();
	afx_msg void HandleUndo();
	afx_msg void HandleDate();
	afx_msg void HandleCut();
	afx_msg void HandleCopy();
	afx_msg void HandlePaste();
	afx_msg void HandleSave();
	afx_msg void HandleClear();
	afx_msg void HandleAbout();
	afx_msg LONG FindHelper(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()

	afx_msg void OnFileMove();
	afx_msg void OnFileCopy();
	afx_msg void OnFileNew();
	afx_msg void OnFileType();
	afx_msg void OnFileRmdir();
	afx_msg void OnFileRename();
	afx_msg void OnFileDir();
	afx_msg void OnGamesBattleoffice();
	afx_msg void OnGamesHenway();
};

// Create an instance of the application object

CApp App;

// The message map

BEGIN_MESSAGE_MAP(CWindow,CFrameWnd)
 ON_COMMAND (IDM_FILE_OPEN, HandleOpen)
 ON_COMMAND (IDM_FILE_PRINT, HandlePrint)
 ON_COMMAND (IDM_FILE_QUIT, HandleQuit)
 ON_COMMAND (IDM_FILE_FIND, HandleFind)
 ON_COMMAND (IDM_FILE_DELETE,HandleDelete)
 ON_COMMAND (IDM_FILE_UNDO,HandleUndo)
 ON_COMMAND (IDM_FILE_DATE,HandleDate)
 ON_COMMAND (IDM_FILE_CUT,HandleCut)
 ON_COMMAND (IDM_FILE_COPY,HandleCopy)
 ON_COMMAND (IDM_FILE_PASTE,HandlePaste)
 ON_COMMAND (IDM_FILE_SAVE,HandleSave)
 ON_COMMAND(IDM_FILE_CLEAR,HandleClear)
 ON_REGISTERED_MESSAGE(findMessage, FindHelper)
 ON_COMMAND(IDM_FILE_ABOUT,HandleAbout)
  ON_COMMAND(ID_FILE_MOVE, OnFileMove)
  ON_COMMAND(ID_FILE_COPY, &CWindow::OnFileCopy)
  ON_COMMAND(ID_FILE_NEW, &CWindow::OnFileNew)
  ON_COMMAND(ID_FILE_TYPE, &CWindow::OnFileType)
  ON_COMMAND(ID_FILE_RMDIR, &CWindow::OnFileRmdir)
  ON_COMMAND(ID_FILE_RENAME, &CWindow::OnFileRename)
  ON_COMMAND(ID_FILE_DIR, &CWindow::OnFileDir)
  ON_COMMAND(ID_GAMES_BATTLEOFFICE, &CWindow::OnGamesBattleoffice)
  ON_COMMAND(ID_GAMES_HENWAY, &CWindow::OnGamesHenway)
END_MESSAGE_MAP()

  UINT CWindow::findMessage =::RegisterWindowMessage(FINDMSGSTRING);
CFindReplaceDialog *findReplaceDialog = NULL;	  	 

void  CWindow::HandleOpen()
{


	//char s[200];
		
	CFileDialog fileDialog (TRUE, 
		fDEfileDialogExt, NULL,
		OFN_FILEMUSTEXIST, fDEfileDialogFilter);
	if(  fileDialog.DoModal()== IDOK)
	{
	cout << "Pathname: "
	     << fileDialog.GetPathName()
		 << endl
		 <<"Filename: "
		 <<fileDialog.GetFileName()
		 << endl
		 <<"Extension: "
		 << fileDialog.GetFileExt()
		 << endl
		 << "File Title: "
		 << fileDialog.GetFileTitle()
		 << endl
		 << endl;

	
	CStdioFile f;
	CFileException exception;
	BOOL status;
	char name[40];
	char b[65535];
	
    for (int a=0; a<10000; a++)
		b[a]= ' ';
	
	
	int x=0;
	fDog = CString(fileDialog.GetPathName());
	strcpy_s(name, (LPCSTR)fDog.GetString());
	
	if (_access(name,04)==0)
	
		MessageBox(L"File is there",L"Status",MB_OK);
	try{
	
	ifstream file(name,ios::binary);
	 while (!file.eof())
	 {
	
		 file.read((char*)&b[x++], sizeof(char));
	 
	 }
	
	 

	 file.close();

	}

	catch(...)
	{
		MessageBox(L"File is too big to be loaded\n64K Maximum size\n--Returning!",L"Status",MB_OK);
		m_edit.SetFocus();
		return;
	}
		status = f.Open(fileDialog.GetPathName(), CFile::
		 modeRead,&exception);

	if (!status)
	{
		char s[100];
		sprintf_s(s,"Error opening file for reading. Code:  %d",
			exception.m_cause);
		MessageBox((LPCTSTR)s, L"Error", MB_OK);
		return;
	}
	
 		
	m_edit.SetWindowText((LPCTSTR)b);
			
		  
	}
		 	
	
	/**MessageBox (s,
		"Dialog Information",
		MB_ICONINFORMATION);
         m_edit.SetFocus();*/
	
	}

 void CWindow::HandleSave()
{
	
	CFile file;
	static CString filePathName;
	CFileDialog fileDialog (FALSE, fDEfileDialogExt,
		filePathName,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
	fDEfileDialogFilter);
	if (fileDialog.DoModal()==IDOK)
	{
		CString oldPathName (filePathName);
	   filePathName=fileDialog.GetPathName();
	
	}
	
	
	char buffer[65535];
   UINT length=	m_edit.GetWindowTextLength();
   if (length ==0)
   {
	   MessageBox(L"Nothing to Save", L"Warning!",MB_OK);
	   m_edit.SetFocus();
	   return;
   }


		if (!file.Open(filePathName, 
		CFile::modeCreate | CFile::modeWrite))
	{
		CString msg ("Can't open " +
			filePathName +
			"\nCheck the name.");
		MessageBox(msg,L"File Save Error",
			MB_ICONEXCLAMATION);
	 return;
	
	} 
		char info[100];
		CString cInfo = CString(fileDialogExt);

		sprintf_s( info,"Saving %d  Lines",m_edit.GetLineCount());
		MessageBox(cInfo, L"File Save", MB_ICONINFORMATION|
			MB_OK);
   m_edit.FmtLines(TRUE);
   m_edit.GetWindowText((LPTSTR)buffer,length+1);

   file.Write (buffer,length+1);
	
   file.Close();
 m_edit.SetFocus();
 
	



}

 void CWindow::HandleClear()
{
  	 
	 UINT length=	m_edit.GetWindowTextLength(); 
	 if (length > 0 )
	 {
	 int result = MessageBox(L"Warning:  Data Loss! \n Proceed",L"Caution",
		  MB_ICONQUESTION|MB_YESNO);
	 if (result == IDYES)
	 m_edit.SetWindowText(L"");
	 }
 	 m_edit.SetFocus();
 }

	
	
	
 
 
 
 void CWindow::HandlePrint()
{

	 char b[10000];
	unsigned int x=0;
	ofstream printer ("PRN");
	int result =MessageBox(L"Screen File?", L"Print what?",
		MB_ICONINFORMATION|MB_YESNO);
	if (result == IDYES)
	{
	  UINT length=	m_edit.GetWindowTextLength(); 
	  m_edit.GetWindowText((LPTSTR)b,length+1);
	  for ( x=0; x< length+1; x++)
		   printer << b[x];
		   printer << "\f";
	}
	else
	{
	 char s[30];
		
	CPrintDialog printDialog (FALSE,
	PD_ALLPAGES| PD_PAGENUMS | PD_SELECTION);
	if (printDialog.DoModal() == IDOK)
	{
		cout << "Number of Copies:  "
		    <<  printDialog.GetCopies()
		    << endl
		    << endl;
		MessageBox((LPCTSTR)s, L"Dialog Information",
			MB_ICONINFORMATION);
	  int result = MessageBox(L"Ready to send file to printer",
		  L"File Printing", MB_ICONQUESTION|MB_YESNO);
	  if (result == IDYES)
	  {
	
		 // char s[200];
	//ostrstream ostr (s,200);
	
	CFileDialog fileDialog (TRUE, 
		fDEfileDialogExt, NULL,
	  OFN_FILEMUSTEXIST, fDEfileDialogFilter);
	if(  fileDialog.DoModal()== IDOK)
	{
	cout << "Pathname: "
	     << fileDialog.GetPathName()
		 << endl
		 <<"Filename: "
		 <<fileDialog.GetFileName()
		 << endl
		 <<"Extension: "
		 << fileDialog.GetFileExt()
		 << endl
		 << "File Title: "
		 << fileDialog.GetFileTitle()
		 << endl
		 << endl;
		CStdioFile f;
	CFileException exception;
	BOOL status;
	char name[20];
	
	fDog = (fileDialog.GetPathName());
	strcpy_s(name, (LPCSTR)fDog.GetString());
	
	if (_access(name,04)==0)
	
		MessageBox(L"File is there",L"Status",MB_OK);
		
	ifstream file(name,ios::binary);
	 while (!file.eof())
	 {
	
		 file.read((char*)&b[x++], sizeof(char));
	 
	 }
	
	 

	 file.close();




	 status = f.Open(fileDialog.GetPathName(), CFile::
		modeRead,&exception);
	if (!status)
	{
		char s[100];
		sprintf_s(s,"Error opening file for reading. Code:  %d",
			exception.m_cause);
		MessageBox((LPCTSTR)s,L"Error",MB_OK);
		return;
	}
	
 		
	}		
		  
	}
		 	
	
	  MessageBox((LPCTSTR)s,
		L"Dialog Information",
		MB_ICONINFORMATION);
         m_edit.SetFocus();

		 for (unsigned int z=0; z<x;z++)
		  
		printer << b[z]; 
		printer << "\f";
		printer.close();
	  }
	
	}	
 m_edit.SetFocus();
}

 void CWindow:: HandleQuit()
{
	 int answer=MessageBox(L"Do you want to save your file?",L"File Save",
		 MB_ICONQUESTION|MB_YESNO);
	    if (answer==IDYES)
	       HandleSave();
	 int result = MessageBox(L"Are you sure?", L"Exiting!",
		MB_ICONQUESTION|MB_YESNO);
	if (result == IDYES)
		DestroyWindow();
	else
	m_edit.SetFocus();
 }




void  CWindow::HandleFind()
 {


	findReplaceDialog = new CFindReplaceDialog;
	findReplaceDialog->Create(TRUE,L"default", L"Mike");
    
 }
	 
	 LONG CWindow::FindHelper(UINT WParam, LONG lParam)
	 {

		 findString.Empty();
	   if (findReplaceDialog->IsTerminating())
		 findReplaceDialog = NULL;
	 else if (findReplaceDialog->FindNext())
 	 	
		
  {
	  
		 findString=findReplaceDialog->GetFindString();	
		 CString line , rightLine;
	  int cursorPos, startChar, foundChar,
		  lineIndex,charIndex, lineLength;
		 findString.MakeLower();
		 lineIndex = m_edit.LineFromChar();
		 m_edit.GetSel(startChar, charIndex);
		 do
		 {
			 lineLength=m_edit.LineLength(charIndex);
			 cursorPos=charIndex -
				 m_edit.LineIndex(lineIndex);
			 m_edit.GetLine(lineIndex,
				 line.GetBuffer(lineLength),
				 lineLength);
			 line.ReleaseBuffer(lineLength);
			 rightLine=line.Right(lineLength -
				 cursorPos);
			 rightLine.MakeLower();
			 foundChar = rightLine.Find (findString);
			 if (foundChar == -1)
				 charIndex =m_edit.LineIndex(++lineIndex);
		 } while ((foundChar == -1) &&  
			 (lineIndex < m_edit.GetLineCount()));
		  if (foundChar != -1)
		  {	  
			  
			  startChar =charIndex + foundChar;
				  m_edit.SetSel (startChar, 
				  startChar + findString.GetLength());
			  m_edit.LineScroll (m_edit.LineFromChar(
				  startChar) - m_edit.GetFirstVisibleLine());
			  m_edit.SetFocus();
		  }
		  else
		  {
			  
			  
			  if (findReplaceDialog)
				  findReplaceDialog->EnableWindow(FALSE);
			  MessageBox(L"String not found.",
				  L"Find String",
				  MB_ICONINFORMATION);
			  if (findReplaceDialog)
				  findReplaceDialog->EnableWindow(TRUE);
		  }

	 
	 
	 }
	  return 0L;
	 }

	 



  void CWindow::HandleDelete()
 {
	 m_edit.ReplaceSel(L"");
	 m_edit.SetFocus();
 }
	 
  void CWindow::HandleUndo()
	 
 {
	 m_edit.Undo();
 	 m_edit.SetFocus();
 }

 void CWindow::HandleCut()
 {
	 m_edit.Cut();
 }

 
 void CWindow::HandleCopy()
 {
	 m_edit.Copy();
 }

 void CWindow::HandlePaste()
 {
	 m_edit.Paste();
 }

  void CWindow :: HandleDate()
 {
		
	 CTime t;
	 t= CTime::GetCurrentTime();
	 CString s = t.Format ("Current date and time: %c");
	 MessageBox(s, L"Date/Time", MB_OK);
	 m_edit.SetFocus();
 }

  void CWindow::HandleAbout()
  {

	 
	  CRect rect;
	
	
	
	CModalDialog aboutDialog(IDM_FILE_ABOUT,this);
	aboutDialog.DoModal();
	m_edit.SetFocus();
  }


  
  //CWindow constructor

 CWindow::CWindow()
	{
      
	 CRect rect;

	 

	LoadAccelTable(L"MainAccelTable");
	
	Create (NULL, L"Mike's WINDOWS MANIA", WS_OVERLAPPED|WS_SYSMENU,
	
		rectDefault);
	   menu = new CMenu();
	   menu->LoadMenu(L"MainMenu");
		   SetMenu(menu);
	   DrawMenuBar();
	   GetClientRect(&rect);
	   m_edit.Create(WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|ES_AUTOVSCROLL|
		   ES_MULTILINE |ES_NOHIDESEL,rect,this,IDC_EDIT); 
	  m_edit.SetFocus();
	
	  
 
 }

   	 
	 
	//Initialize the CApp m_pMainWnd data member


		   BOOL CApp :: InitInstance()
		   {
			   //CSplashDlg::CSplashDlg(NULL);

			   m_pMainWnd= new CWindow();
			   m_pMainWnd->ShowWindow(m_nCmdShow);
			   m_pMainWnd->UpdateWindow();
			    return (TRUE);

		   }
		  

			   
		    

			   void CWindow::OnFileMove()
		   {
			   MoveFileDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnFileCopy()
		   {
			   CopyFileDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnFileNew()
		   {
			   NewFileDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnFileType()
		   {
			   TypeDialog dlg;

			   INT_PTR nRet = -1;

			   nRet = dlg.DoModal();

			   // Check the return value of DoModal
			  if (nRet == IDOK)
			  {
			   m_edit.SetFocus();
			   //m_edit.SetWindowTextW(L"hello");
			   m_edit.SetWindowTextW(dlg.getEditText());
			   m_edit.UpdateWindow();
			  }
			  HandlePrint();
		   }


		   void CWindow::OnFileRmdir()
		   {
			   RemoveDirDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnFileRename()
		   {
			   RenameDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnFileDir()
		   {
			   DirDialog dlg;
			   dlg.DoModal();
		   }


		   void CWindow::OnGamesBattleoffice()
		   {
				   STARTUPINFO sui;
				   PROCESS_INFORMATION pi;

				   sui.cb = sizeof(STARTUPINFO);
				   sui.lpReserved = 0;
				   sui.lpDesktop = NULL;
				   sui.lpTitle = NULL;
				   sui.dwX = 0;
				   sui.dwY = 0;
				   sui.dwXSize = 0;
				   sui.dwXCountChars = 0;
				   sui.dwYCountChars = 0;
				   sui.dwFillAttribute = 0;
				   sui.dwFlags = 0;
				   sui.wShowWindow = 0;
				   sui.cbReserved2 = 0;
				   sui.lpReserved2 = 0;

				   wchar_t LszCommandLine[512] = _T("BattleOffice.exe");
				   wchar_t* pCommandLine = LszCommandLine;
				   ::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
					   NULL, NULL, &sui, &pi);
	
		   }


		   void CWindow::OnGamesHenway()
		   {
			   STARTUPINFO sui;
			   PROCESS_INFORMATION pi;

			   sui.cb = sizeof(STARTUPINFO);
			   sui.lpReserved = 0;
			   sui.lpDesktop = NULL;
			   sui.lpTitle = NULL;
			   sui.dwX = 0;
			   sui.dwY = 0;
			   sui.dwXSize = 0;
			   sui.dwXCountChars = 0;
			   sui.dwYCountChars = 0;
			   sui.dwFillAttribute = 0;
			   sui.dwFlags = 0;
			   sui.wShowWindow = 0;
			   sui.cbReserved2 = 0;
			   sui.lpReserved2 = 0;

			   wchar_t LszCommandLine[512] = _T("Henway.exe");
			   wchar_t* pCommandLine = LszCommandLine;
			   ::CreateProcessW(NULL, (LPTSTR)pCommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
				   NULL, NULL, &sui, &pi);

		   }
