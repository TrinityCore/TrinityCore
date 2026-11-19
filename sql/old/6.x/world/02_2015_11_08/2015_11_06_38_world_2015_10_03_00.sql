--
-- Salanar the Horseman (NPC 28788) say line in Realm of Shadows
SET @ENTRY := 28788;
DELETE FROM `creature_text` WHERE `entry` = @ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(@ENTRY,0,0,'Impressive, death knight. Return to me in the world of the living for your reward.',12,0,100,0,0,0,28835,0,'SALANAR_SAY');

-- Salanar the Horseman (NPC 28653) conditions for the gossip_menu_option to be shown for Into the Realm of Shadows
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9739 AND `ConditionValue1`=12687;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9739,0,0,0,9,0,12687,0,0,0,0,0,'','Salanar the Horseman - Show gossip option only if player has accepted quest 12687, but not completed it.');
