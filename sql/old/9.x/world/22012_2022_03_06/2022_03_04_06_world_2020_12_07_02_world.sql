-- Sniffed
-- Despawn event is triggered only On Passenger Removed, no idea if can be executed only after all waves or in the middle too
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30403 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3040300,3040301) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30403,0,0,0,11,0,100,512,0,0,0,0,0,11,59037,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Respawn - Cast 'The Sum is Greater than the Parts: Nergeld's Freeze Anim'"),
(30403,0,1,0,27,0,100,512,0,0,0,0,0,80,3040300,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Passenger Boarded - Run Script"),
(30403,0,2,0,28,0,100,512,0,0,0,0,0,80,3040301,2,1,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Passenger Removed - Run Script"),

(3040300,9,0,0,0,0,100,512,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Say Line 0"),
(3040300,9,1,0,0,0,100,512,0,0,0,0,0,28,59037,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Remove Aura 'The Sum is Greater than the Parts: Nergeld's Freeze Anim'"),
(3040300,9,2,0,0,0,100,512,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Set Reactstate Passive"),
(3040300,9,3,0,0,0,100,512,10000,10000,0,0,0,107,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,"Nergeld - On Script - Summon Group 0"),
(3040300,9,4,0,0,0,100,512,20000,20000,0,0,0,107,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,"Nergeld - On Script - Summon Group 1"),
(3040300,9,5,0,0,0,100,512,20000,20000,0,0,0,107,2,0,0,0,1,0,0,0,0,0,0,0,0,0,0,"Nergeld - On Script - Summon Group 2"),
(3040300,9,6,0,0,0,100,512,20000,20000,0,0,0,107,3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,"Nergeld - On Script - Summon Group 3"),

(3040301,9,0,0,0,0,100,512,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Say Line 1"),
(3040301,9,1,0,0,0,100,512,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Cast 'Permanent Feign Death'"),
-- Actually one of the effects of Permanent Feign Death, some creatures also becomes not selectable
(3040301,9,2,0,0,0,100,512,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Set Flag Not Selectable"),
(3040301,9,3,0,0,0,100,512,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nergeld - On Script - Delayed Despawn");

-- Sniffed value
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 30403;

-- This text never existed, the "source" was here https://www.wowhead.com/npc=30404/dr-terrible#comments:id=378897:reply=193391
DELETE FROM `creature_text` WHERE `CreatureID` = 30404 AND `GroupID` = 1 AND `BroadcastTextId` = 0;
UPDATE `creature_text` SET `GroupID` = 1 WHERE `CreatureID` = 30404 AND `GroupID` = 2;
UPDATE `smart_scripts` SET `action_param1` = 1, `comment` = "Dr. Terrible - On Link - Say Line 1" WHERE `entryorguid` = 30404 AND `source_type` = 0 AND `id` = 7;
UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 30404 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30404 AND `source_type` = 0 AND `id` = 5;
