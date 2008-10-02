ALTER TABLE `petition` 
  DROP KEY `index_ownerguid_charterguid`,
  CHANGE COLUMN `charterguid` `petitionguid` int(10) unsigned default '0',
  ADD UNIQUE KEY `index_ownerguid_petitionguid` (`ownerguid`,`petitionguid`);
ALTER TABLE `petition_sign` 
  DROP PRIMARY KEY,
  CHANGE COLUMN `charterguid` `petitionguid` int(10) unsigned default '0',
  ADD PRIMARY KEY (`petitionguid`,`playerguid`);
