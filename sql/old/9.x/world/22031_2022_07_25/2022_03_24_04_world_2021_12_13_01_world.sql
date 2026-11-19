-- Random
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (33303,-201066,-200966,37011,16544,32406) AND `source_type` = 0 AND `action_type` = 75;
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (3330300,2242405) AND `source_type` = 9 AND `action_type` = 75;

-- Kirin Tor Mage
-- They should be spawned at different time
-- Or maybe in waves, depends on spawn groups type
UPDATE `creature` SET `spawntimesecs` = 25 WHERE `id` = 33672 AND `guid` IN (136552,136553);

-- X: -814.1099 Y: -201.1249 Z: 429.92508
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-136553,-136552) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (13655200,13655300) AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3367200 AND 3367205 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-136553,0,0,0,11,0,100,0,0,0,0,0,0,80,3367200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Spawn - Run Script"),
(-136553,0,1,0,34,0,100,0,8,1,0,0,0,80,3367201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Reached Point 1 - Run Script"),
(-136553,0,2,0,34,0,100,0,8,2,0,0,0,80,3367202,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Reached Point 2 - Run Script"),

(3367200,9,0,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Cast 'Simple Teleport'"),
(3367200,9,1,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-817.307,-209.5039,429.84174,0,"Kirin Tor Mage - On Script - Move To Position"),

(3367201,9,0,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Set Flag Standstate Kneel"),
(3367201,9,1,0,0,0,100,0,10000,10000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Remove Flag Standstate Kneel"),
(3367201,9,2,0,0,0,100,0,0,0,0,0,0,69,2,0,0,0,0,0,8,0,0,0,0,-814.53357,-201.15007,429.84174,0,"Kirin Tor Mage - On Script - Move To Position"),

(3367202,9,0,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Despawn"),

-- X: -814.1326 Y: -201.19998 Z: 429.92508
(-136552,0,0,0,11,0,100,0,0,0,0,0,0,80,3367203,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Spawn - Run Script"),
(-136552,0,1,0,34,0,100,0,8,1,0,0,0,80,3367204,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Reached Point 1 - Run Script"),
(-136552,0,2,0,34,0,100,0,8,2,0,0,0,80,3367205,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Reached Point 2 - Run Script"),

(3367203,9,0,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Cast 'Simple Teleport'"),
(3367203,9,1,0,0,0,100,0,2000,2000,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,-815.7669,-228.93077,429.84174,0,"Kirin Tor Mage - On Script - Move To Position"),

(3367204,9,0,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Set Flag Standstate Kneel"),
(3367204,9,1,0,0,0,100,0,10000,10000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Remove Flag Standstate Kneel"),
(3367204,9,2,0,0,0,100,0,0,0,0,0,0,69,2,0,0,0,0,0,8,0,0,0,0,-814.2386,-201.278,429.84174,0,"Kirin Tor Mage - On Script - Move To Position"),

(3367205,9,0,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kirin Tor Mage - On Script - Despawn");

UPDATE `smart_scripts` SET `event_type` = 11, `event_param1` = 0, `event_param2` = 0, `event_param3` = 0, `event_param4` = 0, `comment` = "Kirin Tor Battle-Mage - On Spawn - Cast 'Arcane Channeling'" WHERE `entryorguid` = -136523 AND `source_type` = 0 AND `id` = 0;

-- High-Oracle Soo-say
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` = 28027 AND `source_type` = 0 AND `action_type` = 75;
