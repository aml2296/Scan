#ifndef DDisplay
#define DDisplay
#include <Windows.h>
#include "../../Scan/FManager.h"
#include "../../Scan/JobDataB.h"
#include "../../Scan/HelpfulFunctions.h"

class DataNode
{
private:
	//JobData data = JobData("No","Name",-1);
	int hCount = 0;
	HWND *handles = nullptr;
public:
	const int Height = 30;
	inline DataNode()
	{
		//data = JobData();
		hCount = 0;
	}
	inline DataNode(JobData job)
	{
		//data = job;
		hCount = 0;
	}

	inline void SetUpHandle(HWND hWnd, int h)
	{
		/*handles = new HWND[data.Count()];
		wchar_t *name;
		for (int i = 0; i < data.Count(); i++)
		{
			name = HFunc::charToWChar(data.Name().c_str());

			handles[i] = CreateWindow(L"Button", name, WS_CHILD | WS_BORDER | WS_VISIBLE, 0, h, 100, Height, hWnd, NULL, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
			delete[] name;
		}*/
	}
};
class DataDisplay
{
private:
	FManager fileManager;
	JobDataB database;

public:
	DataDisplay() {};

};

#endif