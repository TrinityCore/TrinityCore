/**
 @file prompt.cpp
 
 @author Morgan McGuire, http://graphics.cs.williams.edu 
 @cite Windows dialog interface by Max McGuire, mmcguire@ironlore.com
 @cite Font setting code by Kurt Miller, kurt@flipcode.com

 @created 2000-08-26
 @edited  2005-01-14
 */

#include "G3D/prompt.h"
#include "G3D/platform.h"

#include <stdio.h>

#ifdef G3D_WINDOWS
#    include <sstream>
#    include <conio.h>
#else
#    define _getch getchar
#endif

#if 0 /* G3DFIX: exclude GUI prompt code */
#ifdef G3D_OSX

/*#ifdef __LP64__
#    undef __LP64__
#endif
*/

#    include "G3D/prompt_cocoa.h"

/*
#ifdef G3D_64BIT
#    define __LP64__
#endif
*/

#endif
#endif /* G3DFIX: exclude GUI prompt code */

namespace G3D {

#if 0 /* G3DFIX: exclude GUI prompt code */
#ifdef G3D_WINDOWS

namespace _internal {
/**
 Generic Win32 dialog facility.
 @author Max McGuire
 */
class DialogTemplate {
public:

    DialogTemplate(LPCSTR caption, DWORD style, 
                 int x, int y, int w, int h,
                 LPCSTR font = NULL, WORD fontSize = 8) {
    
      usedBufferLength = sizeof(DLGTEMPLATE);
      totalBufferLength = usedBufferLength;

      dialogTemplate = (DLGTEMPLATE*)malloc(totalBufferLength);

      dialogTemplate->style = style;
        
      if (font != NULL) {
        dialogTemplate->style |= DS_SETFONT;
      }
        
      dialogTemplate->x     = (short)x;
      dialogTemplate->y     = (short)y;
      dialogTemplate->cx    = (short)w;
      dialogTemplate->cy    = (short)h;
      dialogTemplate->cdit  = 0;
        
      dialogTemplate->dwExtendedStyle = 0;

      // The dialog box doesn't have a menu or a special class
      AppendData("\0", 2);
      AppendData("\0", 2);

      // Add the dialog's caption to the template

      AppendString(caption);

      if (font != NULL) {
          AppendData(&fontSize, sizeof(WORD));
          AppendString(font);
      }
    }

  void AddComponent(LPCSTR type, LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      DLGITEMTEMPLATE item;

      item.style = style;
      item.x     = (short)x;
      item.y     = (short)y;
      item.cx    = (short)w;
      item.cy    = (short)h;
      item.id    = id;

      item.dwExtendedStyle = exStyle;

      AppendData(&item, sizeof(DLGITEMTEMPLATE));
        
      AppendString(type);
      AppendString(caption);

      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));

      // Increment the component count
      dialogTemplate->cdit++;

    }


  void AddButton(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0080, caption, style, exStyle, x, y, w, h, id);

      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));

    }


  void AddEditBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0081, caption, style, exStyle, x, y, w, h, id);
    
      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));
    
    }


  void AddStatic(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0082, caption, style, exStyle, x, y, w, h, id);
    
      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));
    
    }


  void AddListBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0083, caption, style, exStyle, x, y, w, h, id);
    
      WORD creationDataLength = sizeof(WORD) + 5 * sizeof(WCHAR);
      AppendData(&creationDataLength, sizeof(WORD));

      AppendString("TEST");
    
    }
    

  void AddScrollBar(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0084, caption, style, exStyle, x, y, w, h, id);
    
      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));
    
    }


  void AddComboBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y, int w, int h, WORD id) {

      AddStandardComponent(0x0085, caption, style, exStyle, x, y, w, h, id);
    
      WORD creationDataLength = 0;
      AppendData(&creationDataLength, sizeof(WORD));

    }


  /**
   *
   * Returns a pointer to the Win32 dialog template which the object
   * represents. This pointer may become invalid if additional components
   * are added to the template.
   *
   */
  operator const DLGTEMPLATE*() const {
      return dialogTemplate;
  }

  virtual ~DialogTemplate() {
      free(dialogTemplate);
  }

protected:

  void AddStandardComponent(WORD type, LPCSTR caption, DWORD style, DWORD exStyle, 
                            int x, int y, int w, int h, WORD id, LPSTR font = NULL, WORD fontSize = 8) {

      DLGITEMTEMPLATE item;

      // DWORD align the beginning of the component data
        
      AlignData(sizeof(DWORD));

      item.style = style;
      if (font != NULL) {
          item.style |= DS_SETFONT;
      }
      item.x     = (short)x;
      item.y     = (short)y;
      item.cx    = (short)w;
      item.cy    = (short)h;
      item.id    = id;

      item.dwExtendedStyle = exStyle;

      AppendData(&item, sizeof(DLGITEMTEMPLATE));
        
      WORD preType = 0xFFFF;
        
      AppendData(&preType, sizeof(WORD));
      AppendData(&type, sizeof(WORD));

      AppendString(caption);

      if (font != NULL) {
          AppendData(&fontSize, sizeof(WORD));
          AppendString(font);
      }

      // Increment the component count
      dialogTemplate->cdit++;
  }

    
  void AlignData(int size) {

      int paddingSize = usedBufferLength % size;
        
      if (paddingSize != 0) {
          EnsureSpace(paddingSize);
          usedBufferLength += paddingSize;
      }

  }

  void AppendString(LPCSTR string) {

      int length = MultiByteToWideChar(CP_ACP, 0, string, -1, NULL, 0);

      WCHAR* wideString = (WCHAR*)malloc(sizeof(WCHAR) * length);
      MultiByteToWideChar(CP_ACP, 0, string, -1, wideString, length);

      AppendData(wideString, length * sizeof(WCHAR));
      free(wideString);

  }

  void AppendData(const void* data, int dataLength) {

      EnsureSpace(dataLength);

      memcpy((char*)dialogTemplate + usedBufferLength, data, dataLength);
      usedBufferLength += dataLength;

  }

  void EnsureSpace(int length) {
      if (length + usedBufferLength > totalBufferLength) {
          totalBufferLength += length * 2;

          void* newBuffer = malloc(totalBufferLength);
          memcpy(newBuffer, dialogTemplate, usedBufferLength);
            
          free(dialogTemplate);
          dialogTemplate = (DLGTEMPLATE*)newBuffer;
      }
  }

private:

  DLGTEMPLATE*      dialogTemplate;

  int               totalBufferLength;
  int               usedBufferLength;

};


struct PromptParams {
    const char* message;
    const char* title;
};

/**
 * Constants for controls.
 */
#define IDC_MESSAGE     1000
#define IDC_BUTTON0     2000

INT_PTR CALLBACK PromptDlgProc(HWND hDlg, UINT msg,
                               WPARAM wParam, LPARAM lParam) {
  switch(msg) {
    case WM_INITDIALOG:
      {
        PromptParams *params = (PromptParams*)lParam;
        ::SetWindowTextA(::GetDlgItem(hDlg, IDC_MESSAGE), params->message);

        ::SetFocus(::GetDlgItem(hDlg, IDC_BUTTON0));

        SetWindowTextA(hDlg, params->title);

        HFONT hfont =
            CreateFontA(16, 0, 0, 0, FW_NORMAL,
                       FALSE, FALSE, FALSE, 
                       ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
                        PROOF_QUALITY, FIXED_PITCH | FF_MODERN, "Courier New");
                        
        SendDlgItemMessage(hDlg, IDC_MESSAGE, WM_SETFONT, (WPARAM)hfont, MAKELPARAM(TRUE,0));


        break;
      }
    case WM_COMMAND:
      {
          int choiceNumber = LOWORD(wParam) - IDC_BUTTON0;
          if ((choiceNumber >= 0) && (choiceNumber < 10)) {
              EndDialog(hDlg, choiceNumber);
              return TRUE;
          }
      }

      break;

    case WM_NCDESTROY:
        // Under SDL 1.2.6 we get a NCDESTROY message for no reason and the
        // window is immediately closed.  This is here to debug the problem.
        (void)0;
        break;

    }

    return FALSE;
}

}; // namespace _internal


using namespace _internal;

/**
 * Show a dialog prompt.
 */
static int guiPrompt(
    const char*         windowTitle,
    const char*         prompt,
    const char**        choice,
    int                 numChoices) {

    int width = 340;
    int height = 220;

    const int buttonSpacing = 2;
    const int buttonWidth = 
        (width - buttonSpacing * 2 - 
          buttonSpacing * (numChoices - 1)) / numChoices;
    const int buttonHeight = 13;


    DialogTemplate dialogTemplate(
        windowTitle,
        WS_CAPTION | DS_CENTER | WS_SYSMENU,
        10, 10, width, height,
        "Tahoma");

    dialogTemplate.AddEditBox(
        "Edit", WS_VISIBLE | ES_READONLY | ES_OEMCONVERT | ES_MULTILINE | WS_TABSTOP, WS_EX_STATICEDGE,
        2, 2, width - 4, height - buttonHeight - 7, IDC_MESSAGE);

    int i;
    for (i = 0; i < numChoices; ++i) {

        int x = buttonSpacing + i * (buttonWidth + buttonSpacing);
        int y = height - buttonHeight - buttonSpacing;

        dialogTemplate.AddButton(choice[i], WS_VISIBLE | WS_TABSTOP, 0,
                           x, y, buttonWidth, buttonHeight, IDC_BUTTON0 + (WORD)i);
        
    }

    // Convert all single \n characters to \r\n for proper printing
    int strLen = 0;
    const char* pStr = prompt;

    while (*pStr != '\0') {
        if ((*pStr == '\n') && (pStr != prompt)) {
            if (*(pStr - 1) != '\r') {
                ++strLen;
            }
        }
        ++strLen;
        ++pStr;
    }

    char* newStr = (char*)malloc(strLen + 1);
    
    const char* pStr2 = prompt;
    char* pNew = newStr;

    while (*pStr2 != '\0') {
        if ((*pStr2 == '\n') && (pStr2 != prompt)) {
            if (*(pStr2 - 1) != '\r') {
                *pNew = '\r';
                ++pNew;
            }
        }
        *pNew = *pStr2;
        ++pNew;
        ++pStr2;
    }

    *pNew = '\0';

    PromptParams params;
    params.message  = newStr;;
    params.title    = windowTitle;

    HMODULE module = GetModuleHandle(0);
    int ret = (int)DialogBoxIndirectParam(module, dialogTemplate, NULL, (DLGPROC) PromptDlgProc, (DWORD)&params);

    free(newStr);

    /*
     For debugging when DialogBoxIndirectParam fails:

        // The last error value.  (Which is preserved across the call).
        DWORD lastErr = GetLastError();
    
        // The decoded message from FormatMessage
        LPTSTR formatMsg = NULL;

        if (NULL == formatMsg) {
            FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                          FORMAT_MESSAGE_IGNORE_INSERTS |
                          FORMAT_MESSAGE_FROM_SYSTEM,
                            NULL,
                            lastErr,
                            0,
                            (LPTSTR)&formatMsg,
                            0,
                            NULL);
        }

        // Make sure the message got translated into something.
        LPTSTR realLastErr;
        if (NULL != formatMsg) {
            realLastErr = formatMsg;
        } else {
            realLastErr = "Last error code does not exist.";
        }

        // Get rid of the allocated memory from FormatMessage.
        if (NULL != formatMsg) {
            LocalFree((LPVOID)formatMsg);
        }
        */

    return ret;
}

#endif
#endif /* G3DFIX: exclude GUI prompt code */


/**
 * Show a prompt on stdout 
 */
static int textPrompt(
    const char*         windowTitle,
    const char*         prompt,
    const char**        choice,
    int                 numChoices) {

    printf("\n___________________________________________________\n");
    printf("%s\n", windowTitle);
    printf("%s", prompt);

    if (numChoices > 10) {
        numChoices = 10;
    }

    int c = -1;
    if (numChoices > 1) {
        printf("\n");
        printf("Choose an option by number:");

        while ((c < 0) || (c >= numChoices)) { 
            printf("\n");

            for (int i = 0; i < numChoices; ++i) {
                if (numChoices <= 3) {
                    printf("  (%d) %s ", i, choice[i]);
                } else {
                    printf("  (%d) %s\n", i, choice[i]);
                }
            }

            printf("\n> ");
            c = _getch() - '0';

            if ((c < 0) || (c >= numChoices)) {
                printf("'%d' is not a valid choice.", c);
            } else {
                printf("%d", c);
            }
        }
    
    } else if (numChoices == 1) {
        
        printf("\nPress any key for '%s'...", choice[0]);
        _getch();
        c = 0;

    } else {

        printf("\nPress any key...");
        _getch();
        c = 0;
    }

    printf("\n___________________________________________________\n");
    return c;
}

#if 0 /* G3DFIX: exclude GUI prompt code */
#ifdef G3D_OSX

static int guiPrompt
(const char*         windowTitle,
 const char*         prompt,
 const char**        choice,
 int                 numChoices) {
  
  return prompt_cocoa(windowTitle, prompt, choice, numChoices);
}

#endif

#endif /* G3DFIX: exclude GUI prompt code */
int prompt(
    const char*      windowTitle,
    const char*      prompt, 
    const char**     choice,
    int              numChoices,
    bool             useGui) {
#if 0 /* G3DFIX: exclude GUI prompt code */
    #ifdef G3D_WINDOWS
        if (useGui) {
            // Build the message box
            return guiPrompt(windowTitle, prompt, choice, numChoices);
        }
    #endif
    
        #ifdef G3D_OSX
                if (useGui){
                    //Will default to text prompt if numChoices > 4
		  int result = guiPrompt(windowTitle, prompt, choice, numChoices);
		  fprintf(stderr, "%d\n", result);
		  return result;
                }
        #endif
#else
    (void)useGui;
#endif /* G3DFIX: exclude GUI prompt code */
    return textPrompt(windowTitle, prompt, choice, numChoices);
}


void msgBox(
    const std::string& message,
    const std::string& title) {

    const char *choice[] = {"Ok"};
    prompt(title.c_str(), message.c_str(), choice, 1, true); 
}

#ifndef G3D_WINDOWS
    #undef _getch
#endif

}// namespace

