
#ifndef __SYSTEM_CONFIG_H__
#define __SYSTEM_CONFIG_H__

// 服务器配置文件名
#define SERVER_OPTION_FILE "config.ini"

// 消息类型
#define MB_NORMAL_PACKET	0x201		// 普通
#define MB_CONNECT_PACKET	0x202		// 连接建立
#define MB_CLOSE_PACKET		0x203		// 连接关闭
#define MB_TIMER_PACKET		0x204		// 定时器
#define MB_DBRETURN_PACKET	0x205		// 数据库返回

// 监听端口
#define SERVER_LISTEN_PORT 3724

#endif // __SYSTEM_CONFIG_H__
