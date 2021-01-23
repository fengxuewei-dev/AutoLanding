#ifndef LOG_STREAM_H
#define LOG_STREAM_H

/**
 * Document: 按照变量进行保存日志文件
 * 1. 创建指定路径(目前的路径为)
 * 2. 添加logs日志删除功能
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "LogStream_output.hpp"

// #define LOGGERPATH						"/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs"
// #define LOGGERPATH_MATLAB				"/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs/Matlab"
// #define LOGGERPATH_RECEIVE				"/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs/Receive"
// #define LOGGERPATH_COMMUNICATION			"/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs/communication"
// #define LOGGERFILECHACKOUT_COMMAND		"cd /home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src; du -s logs"

// #define PROJECTPATH						\
// 	"/home/pi/fixedWing_ws"

#define PROJECTPATH						\
	"/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws"
#define PROJECTSRCPATH					\
	(std::string(PROJECTPATH) 	 	+ "/src")
#define LOGGERPATH						\
	(std::string(PROJECTSRCPATH) 	+ "/logs")
#define LOGGERFILECHACKOUT_COMMAND		\
	("cd " + std::string(PROJECTSRCPATH) + "; du -s logs")


#define MAX_SIZE_MB					20480
#define ACCESS						access
#define MKDIR(a)	 				mkdir((a),0755) 

using std::ofstream;
using std::string;
using std::cout;
using std::endl;

template <class T>
class logStream{
	private:
		ofstream dataFile;
		string FILENAME;
		string path;
		string name;
		string variable;
		string Suffix;
		std::string timebuff;
		struct tm* current_time;

		bool SHOULE_CLEAR_LOG_FILES;
	public: 
		logStream();
		~logStream();


		// 根据当前的系统时间获得对应字符串
		/**
		 * const struct tm* now_time: 当前的系统时间
		 * const wchar_t cSplit: 输出字符串的格式
		 * char *timebuff: 最后获得的字符串输出
		 * header file
		 *          #include <iostream>
		 *          #include <stdio.h>
		 *          #include <stdlib.h>
		 *          #include <time.h>
		 * example: 
		 *      wchar_t cSplit = L'_';
		 *      char timebuff[256];      // 字符存放
		 *      getCurrentTime_TO_string(now_time, cSplit, timebuff);
		 *      // LOGGERSTREAM_DOUBLE(timebuff);
		*/
		// void getCurrentTime_TO_string(const struct tm*, const wchar_t, char *); 
		void getCurrentTime_TO_string();
		void getCurrentTime_TO_string(const wchar_t);


		/**
		 * 创建目录
		 * pDir: 文件路径(绝对路径, 或者是. 和 ..)(可以逐级创建)
		 */
		int createFolder(char*);

		void openLogFile();
		void GeneralFilename();

		void updateCurrentTime();

		int logfile();

		void configuration(string, string, string variable_ = "");
		int getLogFileSize(const std::string cmd = std::string(LOGGERFILECHACKOUT_COMMAND), const int N = 300);
		
		// 打印 单个值
		void logPrint(T data);
};


template <class T>
logStream<T>::logStream(){
	Suffix = ".log";

	getLogFileSize();

}

template <class T>
logStream<T>::~logStream(){}

template <class T>
void logStream<T>::getCurrentTime_TO_string()
{
	// LOGGERSTREAM("获取系统时间转化为字符串中(L'-')...");
	updateCurrentTime();
	char timebuff____[256];
	const struct tm* now_time = current_time;
	const wchar_t cSplit = L'-';
    const wchar_t dSplit = ' ';
    const wchar_t tSplit = ':';
    if (L'\0' == cSplit)
	{
		sprintf(
                timebuff____, "%d%02d%02d%02d%02d%02d",
                now_time->tm_year + 1900,   now_time->tm_mon + 1,   now_time->tm_mday,
                now_time->tm_hour,  		now_time->tm_min,		now_time->tm_sec
            ); // 20200815150329
	}
	else
	{
		sprintf(	
                timebuff____, "%d%c%02d%c%02d%c%02d%c%02d%c%02d",
                now_time->tm_year + 1900,		cSplit,			
                now_time->tm_mon + 1,			cSplit,         now_time->tm_mday,		dSplit,
                now_time->tm_hour,  			tSplit,         now_time->tm_min,		tSplit,     now_time->tm_sec
            ); // 2020-08-15 16:31:01
	}
	timebuff = timebuff____;
	// LOGGERSTREAM_DOUBLE("timeBuff: ", timebuff);
//	// LOGGERSTREAM("获取系统时间转化为字符串完(L'-')...");
    
}
template <class T>
void logStream<T>::getCurrentTime_TO_string(const wchar_t cSplit)
{
//	// LOGGERSTREAM_TRIPLE("获取系统时间转化为字符串中", cSplit, "...");
	updateCurrentTime();
	const struct tm* now_time = current_time;
	// const wchar_t cSplit = L'-';
	char timebuff____[256];
    const wchar_t dSplit = ' ';
    const wchar_t tSplit = ':';
//	// LOGGERSTREAM("1:1");
    if (L'\0' == cSplit)
	{
//		// LOGGERSTREAM("1:2");
		sprintf(
                timebuff____, "%d%02d%02d%02d%02d%02d",
                now_time->tm_year + 1900,   now_time->tm_mon + 1,   now_time->tm_mday,
                now_time->tm_hour,  		now_time->tm_min,		now_time->tm_sec
            ); // 20200815150329

//		// LOGGERSTREAM("1:2:1");
	}
	else
	{
//		// LOGGERSTREAM("1:3");
		sprintf(	
                timebuff____, "%d%c%02d%c%02d%c%02d%c%02d%c%02d",
                now_time->tm_year + 1900,		cSplit,			
                now_time->tm_mon + 1,			cSplit,         now_time->tm_mday,		dSplit,
                now_time->tm_hour,  			tSplit,         now_time->tm_min,		tSplit,     
				now_time->tm_sec
            ); // 2020-08-15 16:31:01
//		// LOGGERSTREAM("1:3:1");
	}
	timebuff = timebuff____;
	// LOGGERSTREAM_DOUBLE("timeBuff: ", timebuff);
//	// LOGGERSTREAM_TRIPLE("获取系统时间转化为字符串完", cSplit, "...");
    
}

template <class T>
int logStream<T>::createFolder(char *pDir)
{
//	// LOGGERSTREAM("开始创建路径");
//	// LOGGERSTREAM_DOUBLE("需要创建的路径为: ", pDir);
	int i = 0, iRet, iLen;
	char* pszDir;
	
	if(NULL == pDir)  return 0;
	
	pszDir = strdup(pDir);
	iLen = strlen(pszDir);
 
	// 创建中间目录
//	// LOGGERSTREAM_DOUBLE("pszDir = ", pszDir);
	for (i = 1;i < iLen;i ++) // 去掉路径字符串的第一个反斜杠的字符
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{ 
			pszDir[i] = '\0';
 
			//如果不存在,创建
//			// LOGGERSTREAM_DOUBLE("pszDir = ", pszDir);
			iRet = ACCESS(pszDir,0); // #include <unistd.h>
			if (iRet != 0)
			{
				iRet = MKDIR(pszDir);
				if (iRet != 0)
				{
					// LOGGERSTREAM("EXIT");
					return -1;
				} 
			}
			// 支持linux,将所有\换成/
			pszDir[i] = '/';
		} 
	}
 
	iRet = MKDIR(pszDir);
	free(pszDir);
	return iRet;
}


template <class T>
void logStream<T>::configuration(string path_, string name_, string variable_){
	// LOGGERSTREAM("开始初始化......");
	getCurrentTime_TO_string(L'\0'); // 得到文件夹
	if(path_.c_str()[path_.size() - 1] != '/')
		path_ = path_ +"/";
	// path = path_ + name_ + "_" + variable_;
	if(variable_ == "")
		path = path_ + name_ + variable_ + "/";
	else 
		path = path_ + name_ + "_" + variable_ + "/";
	// LOGGERSTREAM_DOUBLE("整合之后的路径: ", path);
	name = name_;
	// LOGGERSTREAM_DOUBLE("变量名字: ", name);
	variable = variable_;
	// LOGGERSTREAM_DOUBLE("变量的后缀: ", variable);
	logfile();
	// LOGGERSTREAM("初始化工作完成......");
}
template <class T>
void logStream<T>::updateCurrentTime(){
//	// LOGGERSTREAM("更新系统时间中...");
    time_t time_seconds = time(0);
	current_time = localtime(&time_seconds);
//	// LOGGERSTREAM("更新系统时间完...");
}
template <class T>
void logStream<T>::GeneralFilename()
{
//	// LOGGERSTREAM("开始生成文件名字");
	std::string var;

	wchar_t cSplit = L'-';

	getCurrentTime_TO_string();

	var = "-" + variable; 
	FILENAME = timebuff + Suffix;

	// LOGGERSTREAM_DOUBLE("生成的文件名字为: ", FILENAME);
}
template <class T>
void logStream<T>::openLogFile()
{
//	// LOGGERSTREAM("打开文件输入流...");
	string path_ = path + FILENAME;
//	// LOGGERSTREAM_DOUBLE("打开的文件为: ", path_);
	dataFile.open(path_); // 绝对路径 /home/fengxuewei/....
}

template <class T>
int logStream<T>::logfile()
{
	// 1. 创建路径: 确保路径存在
	int ret = createFolder((char*)path.c_str());
	// 2. 生成文件名
	GeneralFilename();
	// 3. 打开文件流
	openLogFile();

	return 0;
}

// 打印 单个值
template<class T>
void logStream<T>::logPrint(T data){
	getCurrentTime_TO_string(L'\0'); 
	dataFile << timebuff << "\t" << data << std::endl;
	// if(SHOULE_CLEAR_LOG_FILES)
	// 	LOGGERSTREAM_ERROR("Need to clear the logs/ files because of too bigger!");
}
/**
 * 判断日志文件的大小
 */
template<class T>
int logStream<T>::getLogFileSize(const std::string cmd, const int N){
	char line[N];
    FILE *fp;
	size_t i = 0;
	int size = 0;
    const char *sysCommand = cmd.data();
    if ((fp = popen(sysCommand, "r")) == NULL) {
        LOGGERSTREAM("获取日志文件内存大小失败!");
        return false;
    }
    while (
		fgets(line, sizeof(line)-1, fp) != NULL  // 这个是最初始的代码
	);
	sscanf(line, "%d", &size);
	SHOULE_CLEAR_LOG_FILES = (size >= MAX_SIZE_MB);
    pclose(fp);
    return true;
}

#endif