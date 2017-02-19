---
layout: post
title: Extending Notepad
propaganda: 2
tags: [reverse, engineering, cracking, reversing, notepad, windows]
---
It has been a very very long time since I posted anything like this on the "Internets". The last time, 
if I recall correctly, was in the late 90s or early 2ks. Those were the days. Oh well ...

Anyway, I am not here to give you a *history lesson* of any sorts, but rather present you with a
*digestable* walk-through about extending *Notepad* in a reasonable way, without going insane.

To make the most of it, a healthy dose of **assembly**, **C** and the **Win32 API** is required.

On a different note, I do hope that you are not using *M$ Wind0ze* anymore for anything other than:

- playing/testing video games
- analyzing/cracking/reversing malware/software

There are decent cross-compilers out there, which in turn render *software developmet* under windows 
pretty much obsolete; no, no, no, don't tell me that Visual Studio is irreplaceable, just STOP IT.

Get a Mac or install Linux, masochists, take a turn to the right and install BSD.

Anyway, let's start by making a *copy* of **notepad.exe** for our evil purposes. Hold on, hold on ... 
Do I even have to say this in a public setting? Everything presented here is *purely* for educational 
purposes only, absolutely no warranties expressed or implied, use at your own risk.

Enough with the legal mambo-jumbo, let's jump into it ...

![](/images/2017/02/18/step00.png)

We have our own copy, let's create our DLL which will *house* all our custom code. This way 
we can go nuts, without having to worry about *space to spare* inside the executable. 

If the **variable names** look funny to you, it's because we are using [Hungarian Notation](https://en.wikipedia.org/wiki/Hungarian_notation). 
Why? Just for the lolz and to make [Simonyi Karoly](https://en.wikipedia.org/wiki/Charles_Simonyi) chuckle at the idiotic
**conventions** he created, when he Googles himself. Now you know. Welcome to the club. Just so you know, the password is *fidelio*.

```c
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      MessageBoxW(NULL, L"DLL Attached", L"WScrpad", 0);
      break;

    case DLL_PROCESS_DETACH:
      MessageBoxW(NULL, L"DLL Detached", L"WScrpad", 0);
      break;
  }

  return TRUE;
}
```

Save this as `wscrpad.c` and compile it as `wscrpad.dll`. I am not going to tell you how to *compile* 
a freaking *DLL*, come on, have some pride, will you?

To *load* the DLL itself, we'll only need a few spare bytes inside the executable. Always make a backup
copy of `wscrpad.exe` before performing any changes so that you can return back to a known working version,
without having to redo a lot of back-breaking work.

Let's use [Olly Debugger](http://www.ollydbg.de) to modify `wscrpad.exe` and *inject* a couple of lines of code necessary
to load `wscrpad.dll`.

But where to *inject* it and how are we going to *execute* it you might ask?

Well, it would be preferable to load our DLL sometime after the window and possibly the edit control have been 
created and initialized. Our expert knowledge of the Win32 API tells us, that maybe, we should look for calls to 
**CreateWindow()** or **CreateWindowEx()**.

![](/images/2017/02/18/step01.png)

Let's take a look at the imports.

![](/images/2017/02/18/step02.png)

And find all the references to **CreateWindowEx()**.

![](/images/2017/02/18/step03.png)

Now that we located it, scroll down, remember we want to find the *perfect spot*.

![](/images/2017/02/18/step04.png)

Oh and here is our **Edit** *control*, scroll down some more ...

![](/images/2017/02/18/step05.png)

And finally we arrive at our destination. Why this exact spot, couldn't
it be somewhere else? It certainly could and it's really up to us decide, no hard feelings.

![](/images/2017/02/18/step06.png)

Now that we have our *spot*, it's time to write down the addresses so that we can jump back to it with ease.

However, this is not enough, we still need to find some spare space to load our DLL.

![](/images/2017/02/18/step07.png)

After scrolling down quite a lot, we arrive at our second destination.

![](/images/2017/02/18/step08.png)
![](/images/2017/02/18/step09.png)
![](/images/2017/02/18/step10.png)

Hmm, that doesn't look right, relax, just press **Ctrl+A**, see? It's just a
plain old **null terminated** ANSI *string*.

![](/images/2017/02/18/step11.png)
![](/images/2017/02/18/step12.png)

Let me explain what went down in the past few screenshots.

```asm
ASCII "wscrpad.dll", 0

pushad                    ; save all registers
push ASCII "wscrpad.dll"  ; push the name of the DLL into the stack
call LoadLibraryA         ; call Kernel32.LoadLibraryA (ANSI)
popad                     ; restore all registers

push 1                    ; push 1 into the stack
call 01001C42             ; call the original "function" from our "first spot"

jmp 010047BE              ; jump back to our "first spot" (see below)
```

![](/images/2017/02/18/step13.png)

It's time to return to our "first spot" (remember?) and "overwrite" these two lines:

```asm
push 1
call 01001C42
```

with:

```asm
jmp 01008755 ; jump to our "second spot" (see above)
nop
nop
```

![](/images/2017/02/18/step14.png)
![](/images/2017/02/18/step15.png)

Copy all the changes and save them as an executable into the same directory with our DLL.

![](/images/2017/02/18/step16.png)

If everything went according to plan, when we launch the executable our DLL should be loaded
and we shall see the **MessageBox()** popping up from **DLL_PROCESS_ATTACH**.

![](/images/2017/02/18/step17.png)

When we quit the executable, the second **MessageBox()** should popup from 
**DLL_PROCESS_DETACH**.

Believe it or not, the *hard part* is behind us. We can take *assembly* and put it back
into the closet. We don't need it anymore, from this moment on it's all in glorious *C*.

Well, I said *C*, but it could be *Delphi* or any language really, as long as it can *produce*
a valid and working DLL.

When we looked at all the references to **CreateWindowEx()**, the observant reader noticed that
Notepad uses *Notepad* as a class name when it calls **CreateWindowEx()**.

It would be customary to change this to something more *appropriate*, like *WScrpad*.

To do this, fire up your favorite hex editor, I am going to use [HxD](https://mh-nexus.de/en/hxd/).

![](/images/2017/02/18/step20.png)

Search for **Notepad**, you'll get a couple of matches, **00007C20** is the one
you are looking for. Pay attention to the **00** between the characters, this is a **WCHAR**
string, which means roughly *two bytes* per character.

![](/images/2017/02/18/step22.png)

With that behind us, let's use **FindWindow()** with *WScrpad* as class name to locate the
*window* and then disable the **Help** menu item from the *main menu*.

```c
#include <windows.h>

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  EnableMenuItem(GetMenu(hWnd), 4, MF_BYPOSITION | MF_GRAYED);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

![](/images/2017/02/18/step39.png)

```!notice
Exercise: We are using **FindWindow()** with the *class name* set to **WScrpad**, if there is more 
than one window open this could lead to problems, because multiple windows could match.

Replace **FindWindow()** with **EnumWindows()** and locate the first window with the class set to 
**WScrpad** that also matches the current process id.

Use **GetCurrentProcessId()** to get the **id** of the current process.
```

Disabling the *menu item* was interesting, but what if we add our *own menu item*?

```c
#include <windows.h>

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  HMENU hMenu = GetMenu(hWnd);
  HMENU hNewMenu = CreateMenu();

  AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hNewMenu, L"Run");
  AppendMenu(hNewMenu, MF_STRING, RUN_MENU_ID, L"&Run");

  DrawMenuBar(hWnd);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

![](/images/2017/02/18/step24.png)

The *menu item* is there, but we do not have any *action* associated with it. In order to do this,
it is necessary to *replace* Notepad's *Window Procecure* (WndProc) with our own and then call
the *original*. This way we have full control and can even *swallow* events if it's necessary.

This feat can be achieved by replacing the `GLW_WNDPROC` of Notepad's *window*.

```c
pOldWndProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
```

```c
#include <windows.h>

#define IDC_MENU_RUN 1337

WNDPROC pOldWndProc = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_MENU_RUN:
          MessageBox(hWnd, L"Hello World", L"Run", MB_ICONERROR);
          break;
      }
    }
    break;
  }

  return CallWindowProc(pOldWndProc, hWnd, uMsg, wParam, lParam);
}

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  HMENU hMenu = GetMenu(hWnd);
  HMENU hNewMenu = CreateMenu();

  AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hNewMenu, L"Run");
  AppendMenu(hNewMenu, MF_STRING, IDC_MENU_RUN, L"&Run");

  DrawMenuBar(hWnd);

  pOldWndProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

When we *press* **Run** ... Voila! Lo and behold a wild **MessageBox()** appears from the dark.

![](/images/2017/02/18/step25.png)

While it is possible to achieve *most* of what we want *programatically*, there are some downsides.

One of them being that we can't **register** new **accelerators**, not easily at least. It's possible
to do some *hacks* and get around it, but it just doesn't worth it.

What is the alternative? We'll make use of a **resource editor** like 
[Resource Hacker](http://www.angusj.com/resourcehacker/) and add/modify/replace **resources** within
the executable itself. Easy peasy, lemon squeezy.

Add a new menu item ...

![](/images/2017/02/18/step31.png)

... and change the **accelerator** for **Time/&Date** date to **F7**. Be sure to
adjust it in both of the *resources*.

![](/images/2017/02/18/step30.png)

Our custom **&Run** menu item will respond to **F5** and the **Time/&Date** to **F7**.

Before closing *Resource Hacker*, let's make a couple of *cosmetic* changes.

Change the *icon*, to something nicer and more suitable.

![](/images/2017/02/18/step26.png)
![](/images/2017/02/18/step27.png)
![](/images/2017/02/18/step28.png)
![](/images/2017/02/18/step29.png)

Adjust the *string tables* and replace all references to *Notepad*.

![](/images/2017/02/18/step32.png)
![](/images/2017/02/18/step33.png)
![](/images/2017/02/18/step34.png)

Enough with the *resource editing* for now. Let's code.

```c
#include <windows.h>
#include <shellapi.h>

#define IDC_MENU_RUN 1337

#define MAX_TEXT_LENGTH 0xffff >> 1

WNDPROC pOldWndProc = NULL;

void Run(HWND hWnd);

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_MENU_RUN:
          Run(hWnd);
          break;
      }
    }
    break;
  }

  return CallWindowProc(pOldWndProc, hWnd, uMsg, wParam, lParam);
}

void Run(HWND hWnd)
{
  HANDLE hFile;
  HWND hEdit;
  DWORD dwWritten;
  DWORD dwTextLength;
  CHAR szText[MAX_TEXT_LENGTH] = {0, };
  WCHAR wszPath[MAX_PATH] = {0, };
  WCHAR wszFileName[MAX_PATH] = {0, };
  WCHAR wszCmd[MAX_PATH] = {0, };

  hEdit = FindWindowEx(hWnd, NULL, L"Edit", NULL);

  dwTextLength = GetWindowTextLength(hEdit);
  if(dwTextLength == 0)
    return;

  dwTextLength++;

  if(dwTextLength >= MAX_TEXT_LENGTH)
    return;

  if(GetWindowTextA(hEdit, szText, dwTextLength) == 0)
    return;

  if(GetTempPath(MAX_PATH, wszPath) == 0)
    return;

  // FIXME: wnsprintf
  wsprintf(wszFileName, L"%swscrpad.tmp", wszPath);

  hFile = CreateFile(wszFileName,
                     GENERIC_WRITE,
                     NULL,
                     0,
                     CREATE_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL,
                     NULL);
  if(hFile == INVALID_HANDLE_VALUE)
    return;

  if(WriteFile(hFile, szText, dwTextLength, &dwWritten, NULL) == FALSE)
  {
    CloseHandle(hFile);
    return;
  }

  CloseHandle(hFile);

  // FIXME: wnsprintf
  wsprintf(wszCmd, L"//E:vbscript %s", wszFileName);
  ShellExecute(hWnd, L"open", L"wscript", wszCmd, NULL, SW_SHOWNORMAL);
}

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  pOldWndProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

```!notice
Exercise: Right now, we have a buffer with a *fixed size* that we pass to 
**GetWindowTextA()**, this limits the number of characters to **32767**. 

This is not ideal and should be changed by allocating from **heap** a buffer 
that is large enough to hold the *entire* contents of the *edit control*.

In the same vain, we should replace the ANSI **GetWindowTextA()** with its UNICODE
variant **GetWindowTextW()** then run the results through **WideCharToMultiByte()**
before writing it to disk.
```

![](/images/2017/02/18/step40.png)

```!notice
Exercise: It would be nice to delete the temp file in **DLL_PROCESS_ATTACH** so that we don't leave
crap behind in the user's **%temp%** by adding a **Uninitialize()** method and then 
calling **DeleteFile()** inside it.

In addition to this, we should use **GetTempFileName()** to generate a unique filename instead
of using the *hard-coded* **wscrpad.tmp**, which in turn can cause issues if there is more than 
one instance of the editor running.
```

To summarize what happened, in a nutshell, copied the *contents* of the **edit control** in a buffer,
saved the buffer into a **temporary file**, then executed **wscript //E:vbscript %tempfile%** via 
**ShellExecute()**.

```ruby
MsgBox "Welcome to WScrpad!", vbOkOnly & vbExclamation, "Welcome"
```

It is time to press **F5** and clap, clap, clap.

![](/images/2017/02/18/step38.png)

The **Windows Script Host** has two engines. We *hard-coded* **vbscript** but there's also a
**jscript** engine.

Would be absolutely lovely, to allow to switch between these two *engines*. What better way
to do this than to add a new **Settings** menu item and a **Run Settings** dialog with two
radio buttons.

Fire up Resource Hacker once again and create a new **DIALOG** resource. 

![](/images/2017/02/18/step35.png)

```!notice
Exercise: Instead of adding the **DIALOG** resource via Resource Hacker, create an **RC**
resource file, compile it and bundle it inside the DLL.
```

Do not forget about the **Settings** *menu item*, which will be used to *open* the dialog.

![](/images/2017/02/18/step36.png)

```c
#include <windows.h>
#include <shellapi.h>

#define IDD_RUN_SETTINGS 42

#define IDC_SAVE      43
#define IDC_CANCEL    44
#define IDC_VBSCRIPT  46
#define IDC_JSCRIPT   47

#define IDC_MENU_RUN 1337
#define IDC_MENU_RUN_SETTINGS 1338

#define MAX_TEXT_LENGTH 0xffff >> 1

WNDPROC pOldWndProc = NULL;
DWORD dwWSHEngine = 0;

void Run(HWND hWnd, DWORD dwWSHEngine);

LRESULT CALLBACK DlgWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_INITDIALOG:
      CheckDlgButton(hDlg, dwWSHEngine ? IDC_JSCRIPT : IDC_VBSCRIPT, BST_CHECKED);
      return TRUE;

    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_SAVE:
        {
          dwWSHEngine = IsDlgButtonChecked(hDlg, IDC_JSCRIPT);
          EndDialog(hDlg, TRUE);
        }
        break;

        case IDC_CANCEL:
          EndDialog(hDlg, FALSE);
          break;
      }
    }
    break;

    case WM_CLOSE:
      EndDialog(hDlg, FALSE);
      break;
  }

  return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_MENU_RUN:
          Run(hWnd, dwWSHEngine);
          break;

        case IDC_MENU_RUN_SETTINGS:
          DialogBox(GetModuleHandle(NULL),
                    MAKEINTRESOURCE(IDD_RUN_SETTINGS), 
                    hWnd,
                    (DLGPROC) DlgWndProc);
          break;
      }
    }
    break;
  }

  return CallWindowProc(pOldWndProc, hWnd, uMsg, wParam, lParam);
}

void Run(HWND hWnd, DWORD dwWSHEngine)
{
  HANDLE hFile;
  HWND hEdit;
  DWORD dwWritten;
  DWORD dwTextLength;
  CHAR szText[MAX_TEXT_LENGTH] = {0, };
  WCHAR wszPath[MAX_PATH] = {0, };
  WCHAR wszFileName[MAX_PATH] = {0, };
  WCHAR wszCmd[MAX_PATH] = {0, };

  hEdit = FindWindowEx(hWnd, NULL, L"Edit", NULL);

  dwTextLength = GetWindowTextLength(hEdit);
  if(dwTextLength == 0)
    return;

  dwTextLength++;

  if(dwTextLength >= MAX_TEXT_LENGTH)
    return;

  if(GetWindowTextA(hEdit, szText, dwTextLength) == 0)
    return;

  if(GetTempPath(MAX_PATH, wszPath) == 0)
    return;

  // FIXME: wnsprintf
  wsprintf(wszFileName, L"%swscrpad.tmp", wszPath);

  hFile = CreateFile(wszFileName,
                     GENERIC_WRITE,
                     NULL,
                     0,
                     CREATE_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL,
                     NULL);
  if(hFile == INVALID_HANDLE_VALUE)
    return;

  if(WriteFile(hFile, szText, dwTextLength, &dwWritten, NULL) == FALSE)
  {
    CloseHandle(hFile);
    return;
  }

  CloseHandle(hFile);

  // FIXME: wnsprintf
  wsprintf(wszCmd,
           L"//E:%s %s", 
           dwWSHEngine ? L"jscript" : L"vbscript",
           wszFileName);
  ShellExecute(hWnd, L"open", L"wscript", wszCmd, NULL, SW_SHOWNORMAL);
}

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  pOldWndProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

That was quite a lot of code, let's take a look at the result in action, before delving into
the details.

![](/images/2017/02/18/step37.png)

We added a **DIALOG** resource, which is presented to the user via **DialogBox()** when the
**Settings** menu item is selected.

The **selected** radio button is stored in the **dwWSHEngine** global variable (they are bad!!!),
whenever the user hits the **Save** button.

During **Run()**, the selected engine is used based on the value of the **dwWSHEngine** variable.

```c
// FIXME: wnsprintf
wsprintf(wszCmd,
         L"//E:%s %s", 
         dwWSHEngine ? L"jscript" : L"vbscript",
         wszFileName);
```

It is time to test out the **JScript** engine.

```js
new ActiveXObject("WScript.Shell").Popup("Welcome to WScrpad");
```

![](/images/2017/02/18/step41.png)

There is one problem though, when the application is closed, our settings are lost. Would be nice
to persist them in the Windows Registry.

By examining the executable in Olly Debugger once more, it becomes clear that Notepad saves its settings
in the Windows Registry under **HKEY_CURRENT_USER\Software\Microsoft\Notepad**.

![](/images/2017/02/18/step18.png)

Since we rebranded our version, and called it WScrpad, we should change the location of the settings
to something slightly more appropriate like **HKEY_CURRENT_USER\Software\Microsoft\WScrpad**.

![](/images/2017/02/18/step19.png)

To do this, open up the executable in HxD and look for our string.

![](/images/2017/02/18/step21.png)

Save the changes, launch and quit the application, and **BOOM**.

![](/images/2017/02/18/step23.png)

It is now time to store our own custom settings.

```c
#include <windows.h>
#include <shellapi.h>

#define IDD_RUN_SETTINGS 42

#define IDC_SAVE      43
#define IDC_CANCEL    44
#define IDC_VBSCRIPT  46
#define IDC_JSCRIPT   47

#define IDC_MENU_RUN 1337
#define IDC_MENU_RUN_SETTINGS 1338

#define REGISTRY_KEY L"Software\\Microsoft\\WScrpad"
#define REGISTRY_VALUE_NAME L"iWSHEngine"

#define MAX_TEXT_LENGTH 0xffff >> 1

WNDPROC pOldWndProc = NULL;
DWORD dwWSHEngine = 0;

void Run(HWND hWnd, DWORD dwWSHEngine);

void WriteDWORD(LPWSTR lpName, DWORD dwValue)
{
  HKEY hKey;

  if(RegOpenKeyEx(HKEY_CURRENT_USER, REGISTRY_KEY, 0, KEY_WRITE, &hKey)
    != ERROR_SUCCESS)
    return;

  RegSetValueEx(hKey, lpName, 0, REG_DWORD, (LPBYTE) &dwValue, sizeof(dwValue));
  RegCloseKey(hKey);
}

DWORD QueryDWORD(LPWSTR lpName)
{
  HKEY hKey;
  DWORD dwSize;
  DWORD dwType;
  DWORD dwValue;

  if(RegOpenKeyEx(HKEY_CURRENT_USER, REGISTRY_KEY, 0, KEY_READ, &hKey)
    != ERROR_SUCCESS)
    return 0;

  dwValue = 0;
  dwSize	= sizeof(DWORD);
  dwType	= REG_DWORD;

  RegQueryValueEx(hKey, lpName, 0, &dwType, (LPBYTE) &dwValue, &dwSize);
  RegCloseKey(hKey);

  return dwValue;
}

LRESULT CALLBACK DlgWndProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_INITDIALOG:
      CheckDlgButton(hDlg, dwWSHEngine ? IDC_JSCRIPT : IDC_VBSCRIPT, BST_CHECKED);
      return TRUE;

    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_SAVE:
        {
          dwWSHEngine = IsDlgButtonChecked(hDlg, IDC_JSCRIPT);
          WriteDWORD(REGISTRY_VALUE_NAME, dwWSHEngine);
          EndDialog(hDlg, TRUE);
        }
        break;

        case IDC_CANCEL:
          EndDialog(hDlg, FALSE);
          break;
      }
    }
    break;

    case WM_CLOSE:
      EndDialog(hDlg, FALSE);
      break;
  }

  return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
    case WM_COMMAND:
    {
      switch(LOWORD(wParam))
      {
        case IDC_MENU_RUN:
          Run(hWnd, dwWSHEngine);
          break;

        case IDC_MENU_RUN_SETTINGS:
          DialogBox(GetModuleHandle(NULL),
                    MAKEINTRESOURCE(IDD_RUN_SETTINGS),
                    hWnd,
                    (DLGPROC) DlgWndProc);
          break;
      }
    }
    break;
  }

  return CallWindowProc(pOldWndProc, hWnd, uMsg, wParam, lParam);
}

void Run(HWND hWnd, DWORD dwWSHEngine)
{
  HANDLE hFile;
  HWND hEdit;
  DWORD dwWritten;
  DWORD dwTextLength;
  CHAR szText[MAX_TEXT_LENGTH] = {0, };
  WCHAR wszPath[MAX_PATH] = {0, };
  WCHAR wszFileName[MAX_PATH] = {0, };
  WCHAR wszCmd[MAX_PATH] = {0, };

  hEdit = FindWindowEx(hWnd, NULL, L"Edit", NULL);

  dwTextLength = GetWindowTextLength(hEdit);
  if(dwTextLength == 0)
    return;

  dwTextLength++;

  if(dwTextLength >= MAX_TEXT_LENGTH)
    return;

  if(GetWindowTextA(hEdit, szText, dwTextLength) == 0)
    return;

  if(GetTempPath(MAX_PATH, wszPath) == 0)
    return;

  // FIXME: wnsprintf
  wsprintf(wszFileName, L"%swscrpad.tmp", wszPath);

  hFile = CreateFile(wszFileName,
                     GENERIC_WRITE,
                     NULL,
                     0,
                     CREATE_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL,
                     NULL);
  if(hFile == INVALID_HANDLE_VALUE)
    return;

  if(WriteFile(hFile, szText, dwTextLength, &dwWritten, NULL) == FALSE)
  {
    CloseHandle(hFile);
    return;
  }

  CloseHandle(hFile);

  // FIXME: wnsprintf
  wsprintf(wszCmd,
           L"//E:%s %s",
           dwWSHEngine ? L"jscript" : L"vbscript", 
           wszFileName);
  ShellExecute(hWnd, L"open", L"wscript", wszCmd, NULL, SW_SHOWNORMAL);
}

void Initialize(HMODULE hModule)
{
  HWND hWnd = FindWindow(L"WScrpad", NULL);
  pOldWndProc = (WNDPROC) SetWindowLong(hWnd, GWL_WNDPROC, (LONG) WndProc);
  dwWSHEngine = QueryDWORD(REGISTRY_VALUE_NAME);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      Initialize(hModule);
      break;
  }

  return TRUE;
}
```

We store the value of **dwWSHEngine** as a **DWORD** called **iWSHEngine** when the settings
are saved by hitting the **Save** button in the **Run Settings** dialog.

In addition to this, we **query** the **DWORD** value in our **Initialize()** method
and store it in our **dwWSHEngine** variable.

```!notice
Exercise: Add a **Preview HTML** menu item which opens up the contents of the edit control in the
user's default browser via **ShellExecute()**.

Add user-definable templates, which can be defined in **DIALOG** and can be inserted via menu items,
by sending the **EM_REPLACESEL** message via **SendMessage()** to the edit control.
```

This is **THE END**. Where to go from here? You probably figured it out by now that the possibilities
are endless and that the very same technique could be applied to other pieces of software, 
not just our **poor** little Notepad. (**sob, sob**)
