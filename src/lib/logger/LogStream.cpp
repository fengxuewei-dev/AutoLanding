
// #include "LogStream.hpp"

// template <class T>
// logStream<T>::logStream(){
// 	Suffix = ".log";
// 	Prefix = "log-";
// }

// template <class T>
// logStream<T>::~logStream(){}

// template <class T>
// void logStream<T>::getCurrentTime_TO_string()
// {
// 	LOGGERSTREAM_DOUBLE("获取系统时间转化为字符串中(L'-')...");
// 	updateCurrentTime();
// 	char timebuff____[256];
// 	const struct tm* now_time = current_time;
// 	const wchar_t cSplit = L'-';
//     const wchar_t dSplit = ' ';
//     const wchar_t tSplit = ':';
//     if (L'\0' == cSplit)
// 	{
// 		sprintf(
//                 timebuff____, "%d%02d%02d%02d%02d%02d",
//                 now_time->tm_year + 1900,   now_time->tm_mon + 1,   now_time->tm_mday,
//                 now_time->tm_hour,  		now_time->tm_min,		now_time->tm_sec
//             ); // 20200815150329
// 	}
// 	else
// 	{
// 		sprintf(	
//                 timebuff____, "%d%c%02d%c%02d%c%02d%c%02d%c%02d",
//                 now_time->tm_year + 1900,		cSplit,			
//                 now_time->tm_mon + 1,			cSplit,         now_time->tm_mday,		dSplit,
//                 now_time->tm_hour,  			tSplit,         now_time->tm_min,		tSplit,     now_time->tm_sec
//             ); // 2020-08-15 16:31:01
// 	}
// 	timebuff = timebuff____;
// 	LOGGERSTREAM_DOUBLE("timeBuff: " << timebuff);
// 	LOGGERSTREAM_DOUBLE("获取系统时间转化为字符串完(L'-')...");
    
// }
// template <class T>
// void logStream<T>::getCurrentTime_TO_string(const wchar_t cSplit)
// {
// 	LOGGERSTREAM_DOUBLE("获取系统时间转化为字符串中" << cSplit << "...");
// 	updateCurrentTime();
// 	const struct tm* now_time = current_time;
// 	// const wchar_t cSplit = L'-';
// 	char timebuff____[256];
//     const wchar_t dSplit = ' ';
//     const wchar_t tSplit = ':';
// 	LOGGERSTREAM_DOUBLE("1:1");
//     if (L'\0' == cSplit)
// 	{
// 		LOGGERSTREAM_DOUBLE("1:2");
// 		sprintf(
//                 timebuff____, "%d%02d%02d%02d%02d%02d",
//                 now_time->tm_year + 1900,   now_time->tm_mon + 1,   now_time->tm_mday,
//                 now_time->tm_hour,  		now_time->tm_min,		now_time->tm_sec
//             ); // 20200815150329

// 		LOGGERSTREAM_DOUBLE("1:2:1");
// 	}
// 	else
// 	{
// 		LOGGERSTREAM_DOUBLE("1:3");
// 		sprintf(	
//                 timebuff____, "%d%c%02d%c%02d%c%02d%c%02d%c%02d",
//                 now_time->tm_year + 1900,		cSplit,			
//                 now_time->tm_mon + 1,			cSplit,         now_time->tm_mday,		dSplit,
//                 now_time->tm_hour,  			tSplit,         now_time->tm_min,		tSplit,     
// 				now_time->tm_sec
//             ); // 2020-08-15 16:31:01
// 		LOGGERSTREAM_DOUBLE("1:3:1");
// 	}
// 	timebuff = timebuff____;
// 	LOGGERSTREAM_DOUBLE("timeBuff: " << timebuff);
// 	LOGGERSTREAM_DOUBLE("获取系统时间转化为字符串完" << cSplit << "...");
    
// }

// template <class T>
// int logStream<T>::createFolder(char *pDir)
// {
// 	LOGGERSTREAM_DOUBLE("开始创建路径");
// 	LOGGERSTREAM_DOUBLE("需要创建的路径为: " << pDir);
// 	int i = 0, iRet, iLen;
// 	char* pszDir;
	
// 	if(NULL == pDir)  return 0;
	
// 	pszDir = strdup(pDir);
// 	iLen = strlen(pszDir);
 
// 	// 创建中间目录
// 	LOGGERSTREAM_DOUBLE("pszDir = " << pszDir);
// 	for (i = 1;i < iLen;i ++) // 去掉路径字符串的第一个反斜杠的字符
// 	{
// 		if (pszDir[i] == '\\' || pszDir[i] == '/')
// 		{ 
// 			pszDir[i] = '\0';
 
// 			//如果不存在,创建
// 			LOGGERSTREAM_DOUBLE("pszDir = " << pszDir);
// 			iRet = ACCESS(pszDir,0); // #include <unistd.h>
// 			if (iRet != 0)
// 			{
// 				iRet = MKDIR(pszDir);
// 				if (iRet != 0)
// 				{
// 					LOGGERSTREAM_DOUBLE("EXIT");
// 					return -1;
// 				} 
// 			}
// 			// 支持linux,将所有\换成/
// 			pszDir[i] = '/';
// 		} 
// 	}
 
// 	iRet = MKDIR(pszDir);
// 	free(pszDir);
// 	return iRet;
// }


// template <class T>
// void logStream<T>::configuration(string path_, string name_, string variable_){
// 	LOGGERSTREAM_DOUBLE("开始初始化......");
// 	getCurrentTime_TO_string(L'\0'); // 得到文件夹
// 	if(path_.c_str()[path_.size() - 1] != '/')
// 		path_ = path_ +"/";
// 	// path = path_ + name_ + "_" + variable_;
// 	path = path_ + name_ + "_" + variable_ + "/";
// 	LOGGERSTREAM_DOUBLE("整合之后的路径: " << path);
// 	name = name_;
// 	LOGGERSTREAM_DOUBLE("变量名字: " << name);
// 	variable = variable_;
// 	LOGGERSTREAM_DOUBLE("变量的后缀: " << variable);
// 	logfile();
// 	LOGGERSTREAM_DOUBLE("初始化工作完成......");
// }
// template <class T>
// void logStream<T>::updateCurrentTime(){
// 	LOGGERSTREAM_DOUBLE("更新系统时间中...");
//     time_t time_seconds = time(0);
// 	current_time = localtime(&time_seconds);
// 	LOGGERSTREAM_DOUBLE("更新系统时间完...");
// }
// template <class T>
// void logStream<T>::GeneralFilename()
// {
// 	LOGGERSTREAM_DOUBLE("开始生成文件名字");
// 	std::string var;

// 	wchar_t cSplit = L'-';

// 	getCurrentTime_TO_string();

// 	var = "-" + variable; 
// 	FILENAME = timebuff + Suffix;
// 	LOGGERSTREAM_DOUBLE(FILENAME);
// 	LOGGERSTREAM_DOUBLE(">>>>>>>>>>>>>>>>>>>>>>");
// 	LOGGERSTREAM_DOUBLE("生成的文件名字为: " << FILENAME);
// }
// template <class T>
// void logStream<T>::openLogFile()
// {
// 	LOGGERSTREAM_DOUBLE("打开文件输入流...");
// 	string path_ = path + FILENAME;
// 	LOGGERSTREAM_DOUBLE("打开的文件为: " << path_);
// 	dataFile.open(path_); // 绝对路径 /home/fengxuewei/....
// }

// template <class T>
// int logStream<T>::logfile()
// {
// 	// 1. 创建路径: 确保路径存在
// 	int ret = createFolder((char*)path.c_str());
// 	if(ret == -1) 	LOGGERSTREAM_DOUBLE("路径存在或使用的是相对路径!");
// 	else			LOGGERSTREAM_DOUBLE("路径创建成功");
// 	// 2. 生成文件名
// 	GeneralFilename();
// 	// 3. 打开文件流
// 	openLogFile();

// 	return 0;
// }

// // 打印 单个值
// template<class T>
// void logStream<T>::logPrint(T data){
// 	getCurrentTime_TO_string(L'\0');
// 	dataFile << timebuff << "\t" << data << std::end;
// 	LOGGERSTREAM_DOUBLE(timebuff << "\t" << data << std::end;
// }
// // template <class T1,class T2>
// // void logStream::logPrint(string name, double data){
// // 	dataFile << name << " : " << data << endl;
// //     cout << name << " : " << data << endl;
// // }

// // void logStream::logPrint(string name, double data1, double data2){
// //     dataFile << name << " : (" << data1 << ", " << data2 << ")"<< endl;
// // 	cout << name << " : (" << data1 << ", " << data2 << ")"<< endl;
// // }
// // void logStream::logPrint(string name){
// //     dataFile << name << endl;
// //     cout << name << endl;
// // }

// // void logStream::logPrint(double data){
// //     dataFile << data << endl;
// //     cout << data << endl;
// // }