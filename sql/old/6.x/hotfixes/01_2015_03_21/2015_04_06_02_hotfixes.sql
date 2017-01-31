UPDATE `gameobjects` SET `Data0`=0 WHERE `ID` IN (239085 /*-Unknown-*/, 239086 /*-Unknown-*/);

ALTER TABLE `gameobjects`
  CHANGE `Data0` `Data0` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data1` `Data1` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data2` `Data2` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data3` `Data3` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data4` `Data4` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data5` `Data5` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data6` `Data6` INT(10) NOT NULL DEFAULT '0',
  CHANGE `Data7` `Data7` INT(10) NOT NULL DEFAULT '0';

UPDATE `gameobjects` SET `Data0`=-1 WHERE `Id` IN (239085 /*-Unknown-*/, 239086 /*-Unknown-*/);
