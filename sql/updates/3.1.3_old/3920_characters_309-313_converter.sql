CREATE TABLE `character_equipmentsets` (
  `guid` int(11) NOT NULL default '0',
  `setguid` bigint(20) NOT NULL auto_increment,
  `setindex` tinyint(4) NOT NULL default '0',
  `name` varchar(100) NOT NULL,
  `iconname` varchar(100) NOT NULL,
  `item0` int(11) NOT NULL default '0',
  `item1` int(11) NOT NULL default '0',
  `item2` int(11) NOT NULL default '0',
  `item3` int(11) NOT NULL default '0',
  `item4` int(11) NOT NULL default '0',
  `item5` int(11) NOT NULL default '0',
  `item6` int(11) NOT NULL default '0',
  `item7` int(11) NOT NULL default '0',
  `item8` int(11) NOT NULL default '0',
  `item9` int(11) NOT NULL default '0',
  `item10` int(11) NOT NULL default '0',
  `item11` int(11) NOT NULL default '0',
  `item12` int(11) NOT NULL default '0',
  `item13` int(11) NOT NULL default '0',
  `item14` int(11) NOT NULL default '0',
  `item15` int(11) NOT NULL default '0',
  `item16` int(11) NOT NULL default '0',
  `item17` int(11) NOT NULL default '0',
  `item18` int(11) NOT NULL default '0',
  PRIMARY KEY  (`setguid`),
  UNIQUE KEY `idx_set` (`guid`,`setguid`,`setindex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');
UPDATE `characters` SET `data` = CONCAT(
	SUBSTRING_INDEX(`data`, ' ', 257 + 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 1), ' ', -261 + 260 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18 + 1), ' ', -261 - 18 + 260 + 18 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*2 + 1), ' ', -261 - 18*2 + 260 + 18*2 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*3 + 1), ' ', -261 - 18*3 + 260 + 18*3 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*4 + 1), ' ', -261 - 18*4 + 260 + 18*4 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*5 + 1), ' ', -261 - 18*5 + 260 + 18*5 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*6 + 1), ' ', -261 - 18*6 + 260 + 18*6 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*7 + 1), ' ', -261 - 18*7 + 260 + 18*7 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*8 + 1), ' ', -261 - 18*8 + 260 + 18*8 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*9 + 1), ' ', -261 - 18*9 + 260 + 18*9 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*10 + 1), ' ', -261 - 18*10 + 260 + 18*10 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*11 + 1), ' ', -261 - 18*11 + 260 + 18*11 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*12 + 1), ' ', -261 - 18*12 + 260 + 18*12 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*13 + 1), ' ', -261 - 18*13 + 260 + 18*13 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*14 + 1), ' ', -261 - 18*14 + 260 + 18*14 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*15 + 1), ' ', -261 - 18*15 + 260 + 18*15 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*16 + 1), ' ', -261 - 18*16 + 260 + 18*16 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*17 + 1), ' ', -261 - 18*17 + 260 + 18*17 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 261 + 18*18 + 1), ' ', -261 - 18*18 + 260 + 18*18 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 837 + 1), ' ', -837 + 600 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 937 + 1), ' ', -937 + 874 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1007 + 1), ' ', -1007 + 1002 - 1), ' ',
	'0 0 ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1688 + 1), ' ', -1688 + 1008 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1696 + 1), ' ', -1696 + 1691 - 1), ' ',
	SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1700 + 1), ' ', -1700 + 1699 - 1), ' '
	)
WHERE length(SUBSTRING_INDEX(data, ' ', 1700)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 1701)) >= length(data);
UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');
