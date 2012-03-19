ALTER TABLE `channels`
ROW_FORMAT=DEFAULT,
CHANGE `BannedList` `BannedList` TEXT,
DROP PRIMARY KEY, 
ADD PRIMARY KEY (`m_name`, `m_team`);