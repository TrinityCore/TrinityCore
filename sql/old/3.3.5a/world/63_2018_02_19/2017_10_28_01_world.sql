--
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|512 WHERE `entryorguid` IN  (2482300,2485200) AND `source_type`=9;
-- readd missing text from 2015_03_02_03_world.sql
DELETE FROM `creature_text` WHERE `CreatureID`=24718 AND `GroupID` IN (1, 2);  
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`, `BroadcastTextId`,`TextRange`,`comment`) VALUES
(24718,1,0,"What do you think you're doing, man? Lebronski does NOT appreciate you dragging your loose metal parts all over his rug.",12,7,100,0,0,0, 23890,0,'Lebronski'),
(24718,2,0,"Far out, man. This bucket of bolts might make it after all...",12,7,100,0,0,0, 23891,0,'Lebronski');
