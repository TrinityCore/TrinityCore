ALTER TABLE `characters`
   ADD COLUMN `deleteInfos_Account` int(11) UNSIGNED default NULL AFTER actionBars,
   ADD COLUMN `deleteInfos_Name` varchar(12) default NULL AFTER deleteInfos_Account,
   ADD COLUMN `deleteDate` bigint(20) default NULL AFTER deleteInfos_Name;

