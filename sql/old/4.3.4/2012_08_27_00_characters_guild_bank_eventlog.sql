DELETE FROM `guild_bank_eventlog` WHERE `EventType` IN (3,7) AND `TabId`=`DestTabId`; -- delete log entries of item moves within one tab
