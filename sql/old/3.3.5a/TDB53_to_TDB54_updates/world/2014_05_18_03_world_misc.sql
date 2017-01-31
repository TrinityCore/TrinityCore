--
-- Nesingwary Lackey Ear (35188) drop chance fix by nelegalno
-- Needed for Can't Get Ear-nough... (11867) "turn in only" repeatable quest
SET @EAR := 35188;

UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = ABS(`ChanceOrQuestChance`) WHERE `item`=@EAR;

-- Clam Master K
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25800 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25800,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Clam Master K only if Ears of Our Enemies quest taken"),
(1,25800,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Clam Master K only if Ears of Our Enemies quest rewarded");

-- Loot Crazed Poacher
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25806 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25806,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Poacher only if Ears of Our Enemies quest taken"),
(1,25806,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Poacher only if Ears of Our Enemies quest rewarded");

-- Loot Crazed Diver
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25836 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25836,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Diver only if Ears of Our Enemies quest taken"),
(1,25836,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Diver only if Ears of Our Enemies quest rewarded");

-- Northsea Mercenary
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25839 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25839,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Northsea Mercenary only if Ears of Our Enemies quest taken"),
(1,25839,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Northsea Mercenary only if Ears of Our Enemies quest rewarded");

-- Northsea Thug
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25843 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25843,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Northsea Thug only if Ears of Our Enemies quest taken"),
(1,25843,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Northsea Thug only if Ears of Our Enemies quest rewarded");

 -- Minion of Kaw
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25880 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25880,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Minion of Kaw only if Ears of Our Enemies quest taken"),
(1,25880,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Minion of Kaw only if Ears of Our Enemies quest rewarded");

 -- Loot Crazed Hunter
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=25979 AND `SourceEntry`=@EAR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,25979,@EAR,0,0,9,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Hunter only if Ears of Our Enemies quest taken"),
(1,25979,@EAR,0,1,8,0,11866,0,0,0,0,'',"Nesingwary Lackey Ear drops from Loot Crazed Hunter only if Ears of Our Enemies quest rewarded");
