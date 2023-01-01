-- 
SET @ENTRY := 14100;
DELETE FROM `reference_loot_template` WHERE `Entry` = @ENTRY;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(@ENTRY,32670,0,0,0,1,1,1,1),
(@ENTRY,32671,0,0,0,1,1,1,1),
(@ENTRY,32672,0,0,0,1,1,1,1),
(@ENTRY,32673,0,0,0,1,1,1,1),
(@ENTRY,32674,0,0,0,1,1,1,1),
(@ENTRY,32675,0,0,0,1,1,1,1),
(@ENTRY,32676,0,0,0,1,1,1,1),
(@ENTRY,32677,0,0,0,1,1,1,1),
(@ENTRY,32678,0,0,0,1,1,1,1),
(@ENTRY,32679,0,0,0,1,1,1,1);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (19973,20557,22175,22180,22181,22182,22195,22204,22241,22242,22243,22244,22254,22275,22281,22291,23061,23230,23261,23281,23282,23353,23354,23355) AND (`Item` IN (32670,32671,32672,32673,32674,32675,32676,32677,32678,32679) OR `Item` = @ENTRY AND `Reference` = @ENTRY);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(19973,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(20557,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22175,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22180,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22181,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22182,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22195,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22204,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22241,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22242,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22243,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22244,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22254,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22275,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22281,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(22291,@ENTRY,@ENTRY,1,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23061,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23230,@ENTRY,@ENTRY,100,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23261,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23281,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23282,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23353,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23354,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)"),
(23355,@ENTRY,@ENTRY,10,0,1,0,1,1,"Depleted items (Ogri'la)");
