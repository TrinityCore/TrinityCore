// #include "AAVerify.h"
// #include "World.h"
// #include <iostream>
// #include <istream>
// #include <ostream>
// #include <string>
// #include <regex>
// #include <curl/curl.h>

// #ifdef WIN32
// #pragma comment(lib,"ws2_32.lib")
// #include <WinSock2.h>
// #include <Iphlpapi.h>
// #endif

// #include <iostream>
// #pragma comment(lib,"Iphlpapi.lib") //需要添加Iphlpapi.lib库

// using std::string;

// AAVerify* AAVerify::instance()
// {
//     static AAVerify instance;
//     return &instance;
// }

// //get请求和post请求数据响应函数
// size_t req_reply(void* buffer, size_t size, size_t nmemb, void* lpVoid)
// {
//     std::string* str = dynamic_cast<std::string*>((std::string*)lpVoid);
//     if (NULL == str || NULL == buffer)
//     {
//         return -1;
//     }

//     char* pData = (char*)buffer;
//     str->append(pData, size * nmemb);
//     return nmemb;
// }
// //http POST请求
// CURLcode post(const string& url, const string& postParams, string& response)
// {
//     // curl初始化
//     CURL* curl = curl_easy_init();
//     // curl返回值
//     CURLcode res;
//     if (curl)
//     {
//         // set params
//         //设置curl的请求头
//         struct curl_slist* header_list = NULL;
//         header_list = curl_slist_append(header_list, "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko");
//         header_list = curl_slist_append(header_list, "Content-Type:application/x-www-form-urlencoded; charset=UTF-8");
//         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

//         //不接收响应头数据0代表不接收 1代表接收
//         curl_easy_setopt(curl, CURLOPT_HEADER, 0);

//         //设置请求为post请求
//         curl_easy_setopt(curl, CURLOPT_POST, 1);

//         //设置请求的URL地址
//         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//         //设置post请求的参数
//         curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postParams.c_str());

//         //设置ssl验证
//         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
//         curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

//         //CURLOPT_VERBOSE的值为1时，会显示详细的调试信息
//         curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);

//         curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

//         //设置数据接收和写入函数
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, req_reply);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&response);

//         curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

//         //设置超时时间
//         curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 6);
//         curl_easy_setopt(curl, CURLOPT_TIMEOUT, 6);

//         // 开启post请求
//         res = curl_easy_perform(curl);
//     }
//     //释放curl
//     curl_easy_cleanup(curl);
//     return res;
// }

// std::string AAVerify::AA_Login()
// {
//     try
//     {
//         AA_Realmlist conf = aaCenter.aa_realmlists[1];
//         string reponse_data;

//         string url = "http://120.48.70.156";
//         string response_data = "";
//         string data = "version=" + aaCenter.aa_version.version + "&uuid=" + aaCenter.aa_version.uuid + "&count=" + std::to_string(sWorld->GetActiveSessionCount()) + "&status=" + aaCenter.aa_version.status +
//             "&aname=" + conf.name + "&aport=" + std::to_string(conf.port) + "&ip=" + conf.address;
//         auto ret = post(url, data, response_data);
//         if (ret != CURLE_OK)
//             return "1";
//         if (aaCenter.aa_version.uuid == "")
//         {
//             return "1";
//         }
//         if (response_data == "")
//         {
//             return "";
//         }
//         return response_data;
//     }
//     catch (std::exception const& e)
//     {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return "1";
//     }
//     return "1";
// }

// std::string AAVerify::AA_GetUUID() {
//     //PIP_ADAPTER_INFO结构体指针存储本机网卡信息
//     PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
//     //得到结构体大小,用于GetAdaptersInfo参数
//     unsigned long stSize = sizeof(IP_ADAPTER_INFO);
//     //调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量;其中stSize参数既是一个输入量也是一个输出量
//     int nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
//     //记录网卡数量
//     int netCardNum = 0;
//     //记录每张网卡上的IP地址数量
//     int IPnumPerNetCard = 0;
//     std::string result = "";
//     if (ERROR_BUFFER_OVERFLOW == nRel)
//     {
//         //如果函数返回的是ERROR_BUFFER_OVERFLOW
//         //则说明GetAdaptersInfo参数传递的内存空间不够,同时其传出stSize,表示需要的空间大小
//         //这也是说明为什么stSize既是一个输入量也是一个输出量
//         //释放原来的内存空间
//         delete pIpAdapterInfo;
//         //重新申请内存空间用来存储所有网卡信息
//         pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[stSize];
//         //再次调用GetAdaptersInfo函数,填充pIpAdapterInfo指针变量
//         nRel = GetAdaptersInfo(pIpAdapterInfo, &stSize);
//     }
//     if (ERROR_SUCCESS == nRel)
//     {
//         std::regex e("([a-z0-9A-Z]?)");
//         //输出网卡信息
//         //可能有多网卡,因此通过循环去判断
//         while (pIpAdapterInfo)
//         {
//             std::smatch m;
//             std::string s = pIpAdapterInfo->AdapterName;
//             if (s != "" && s != "{}" && s != " " && s != "") {
//                 for (int i = 0; i < s.size(); i++) {
//                     string x(1, s[i]);
//                     regex_search(x, m, e);
//                     if (m.str() != " ") {
//                         result += m.str();
//                     }
//                 }
//                 break;
//             }
//             pIpAdapterInfo = pIpAdapterInfo->Next;
//         }

//     }
//     //释放内存空间
//     if (pIpAdapterInfo)
//     {
//         delete pIpAdapterInfo;
//     }

//     SYSTEM_INFO  sysInfo;    //该结构体包含了当前计算机的信息：计算机的体系结构、中央处理器的类型、系统中中央处理器的数量、页面的大小以及其他信息。
//     OSVERSIONINFOEX osvi;
//     GetSystemInfo(&sysInfo);
//     osvi.dwOSVersionInfoSize = sizeof(osvi);
//     std::string cpuversion = std::to_string(sysInfo.wProcessorRevision);
//     if (result != "") {
//         return "A" + result + "A" + cpuversion;
//     }
//     else {
//         return "";
//     }
// }
