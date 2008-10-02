ALTER TABLE `playercreateinfo`
  DROP KEY `playercreateinfo_index`,
  DROP PRIMARY KEY ,
  DROP `createId` ,
  ADD PRIMARY KEY `playercreateinfo_race_class_index` (`race`,`class`) ;
	