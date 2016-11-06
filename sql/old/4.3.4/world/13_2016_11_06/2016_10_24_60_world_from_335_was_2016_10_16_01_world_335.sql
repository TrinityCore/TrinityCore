--
DELETE FROM `conditions` WHERE `SourceGroup`=6685;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 6685, 13062, 0, 0, 12, 0, 50, 0, 0, 0, 0, 0, "", "Show gossip text 13062 for Baron Revilgaz if event Pirates' Day is running");

UPDATE `npc_text` SET `text0_0`="Welcome to Booty Bay, partner.  Don't mind DeMeza and her crew... we let the hellion run riot one day a year, Pirates' Day, and then she leaves us in peace to go plunder the South Seas again.$B$BNow then... what can this humble servant of the Steamwheedle Cartel do for you?  Better still - what can you do for me, eh?" WHERE `ID`=13062;
