#include <windows.h>

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) { //窗口处理函数 
	switch(Message) {
		case WM_CREATE:
			//置顶窗口 
			SetWindowPos(hwnd,HWND_TOP,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE);
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//弹出消息框 
	//MessageBox(NULL,"Test MassageBox","Test MassageBox",MB_YESNO | MB_ICONINFORMATION);
	/*
	MessageBox(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UNIT uType)
	弹窗函数：
	HWND：窗口句柄类型    lpText：窗内消息文本    lpCaption：弹窗标题文本    uType：图标按钮组合 
	*/
	wchar_t szAppClassName[] = L"GDATest";
	
	//窗口应用 
	//1.设计窗口类
	/*typedef struct tagWNDCLASSW {   //WNDCLASS的原型和定义 
    UINT        style;
    WNDPROC     lpfnWndProc;  //窗口处理函数，在头顶 
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPCWSTR     lpszMenuName;
    LPCWSTR     lpszClassName;
} WNDCLASSW, *PWNDCLASSW, NEAR *NPWNDCLASSW, FAR *LPWNDCLASSW;*/
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);    //左上角图标 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(51,85,159));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppClassName;
	
	//2.注册窗口类 
	if(FALSE == RegisterClass(&wc))
	{
		MessageBox(NULL,"Error!\nPlease check again.","Test Waring",MB_YESNO | MB_ICONINFORMATION);
		return 0;
	}
	
	//3.创建窗口
	HWND hWnd = CreateWindow(
		szAppClassName,  //窗口类型名 
		"Test Program", //窗口名
		WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX,  //窗口风格 
		200,  //窗口横坐标 
		200,  //窗口纵坐标 
		800,  //窗口宽 
		600,  //窗口高
		NULL, //父窗口
		NULL, //菜单句柄
		hInstance,  //当前程序实例句柄
		NULL  //附加参数 
	);
	
	//4.显示窗口
	ShowWindow(hWnd, SW_SHOW);
	
	//5.更新窗口
	UpdateWindow(hWnd);
	MSG msg;
	//6.消息循环
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		//将消息转化和分发
		DispatchMessage(&msg); 
	}
	
	 
	
	return 0; 
}

