UPDATE `gameobject_template` SET `Data20`=0 WHERE `type`=3;

UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0001 WHERE `type`=3 AND `Data3`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0002 WHERE `type`=3 AND `Data10`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0004 WHERE `type`=3 AND `Data11`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0008 WHERE `type`=3 AND `Data12`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0010 WHERE `type`=3 AND `Data13`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0020 WHERE `type`=3 AND `Data15`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0040 WHERE `type`=3 AND `Data16`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0080 WHERE `type`=3 AND `Data21`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0100 WHERE `type`=3 AND `Data22`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0200 WHERE `type`=3 AND `Data27`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0400 WHERE `type`=3 AND `Data28`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x0800 WHERE `type`=3 AND `Data31`!=0;
UPDATE `gameobject_template` SET `Data20`=`Data20`|0x1000 WHERE `type`=3 AND `Data34`!=0;

-- reset fields that were reused for something else
UPDATE `gameobject_template` SET `Data21`=0 WHERE `type`=3;
UPDATE `gameobject_template` SET `Data22`=0 WHERE `type`=3;
