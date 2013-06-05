SET @ENTRY := 27482; -- Wounded Westfall Infantry npc
SET @SPELL := 48845; -- Renew Infantry spell
SET @ITEM := 37576; -- Renewing Bandage item
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=@ITEM;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL,0,31,1,3,@ENTRY,0,0,0,'', "Item Renewing Bandage target Wounded Westfall Infantry");
