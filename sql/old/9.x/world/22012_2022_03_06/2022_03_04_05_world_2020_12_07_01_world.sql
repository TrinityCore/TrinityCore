-- Sniffed
-- Thane Illskar the Damned
UPDATE `creature_text` SET `Duration` = 0, `comment` = "Thane Illskar the Damned" WHERE `CreatureID` = 30523 AND `GroupID` = 0;
UPDATE `creature_template` SET `speed_run` = 1.07143 WHERE `entry` = 30523;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30523 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3052300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30523,0,0,0,54,0,100,0,0,0,0,0,0,80,3052300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Just Summoned - Run Script"),

(3052300,9,0,0,0,0,100,0,0,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Script - Remove Flag Standstate Submerged"),
(3052300,9,1,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Script - Say Line 0"),
(3052300,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,30501,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Script - Set Orientation Closest Creature 'Val'kyr Arbiter'"),
(3052300,9,3,0,0,0,100,0,5000,5000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Script - Set Flag Standstate Kneel"),
(3052300,9,4,0,0,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar the Damned - On Script - Delayed Despawn");

-- Val'kyr Arbiter
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30501 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3050100,30501000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30501,0,0,0,54,0,100,0,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Just Summoned - Cast 'Ethereal Teleport'"),
(30501,0,1,0,60,0,100,0,0,0,2000,2000,0,66,0,0,0,0,0,0,19,30475,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Update - Set Orientation Closest Creature 'Thane Illskar'"),
(30501,0,2,0,38,0,100,0,0,1,0,0,0,69,1,0,0,5,0,0,7,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Data Set 0 1 - Move To Invoker"),
(30501,0,3,0,34,0,100,0,8,1,0,0,0,80,3050100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Reached Point 1 - Run Script"),
(30501,0,4,5,34,0,100,0,8,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.752457857131958007,"Val'kyr Arbiter - On Reached Point 2 - Set Orientation"),
(30501,0,5,0,61,0,100,0,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Link - Delayed Despawn"),

(3050100,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,30475,0,1,0,0,0,0,0,"Val'kyr Arbiter - On Script - Set Orientation Closest Creature 'Thane Illskar'"),
(3050100,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Script - Say Line 0"),
(3050100,9,2,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Script - Say Line 1"),
(3050100,9,3,0,0,0,100,0,3000,3000,0,0,0,11,55063,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Script - Cast 'Arbiter's Judgment'"),
(3050100,9,4,0,0,0,100,0,5000,5000,0,0,0,86,55064,2,19,30475,0,1,1,0,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Script - Cross Cast 'Revenge for the Vargul: Summon Thane Illskar the Damned' (Thane Illskar)"),
(3050100,9,5,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,19,30475,0,1,0,0,0,0,0,"Val'kyr Arbiter - On Script - Despawn Instant (Thane Illskar)"),
(3050100,9,6,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,30483,0,1,0,0,0,0,0,"Val'kyr Arbiter - On Script - Despawn Instant (Volgur)"),
(3050100,9,7,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,30484,0,1,0,0,0,0,0,"Val'kyr Arbiter - On Script - Despawn Instant (Brita)"),
(3050100,9,8,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,192558,0,0,0,0,0,0,0,"Val'kyr Arbiter - On Script - Despawn Instant (Bethod's Sword)"),
(3050100,9,9,0,0,0,100,0,2000,2000,0,0,0,69,2,0,0,0,0,0,8,0,0,0,0,7848.1895,3400.8743,663.6719,3.752457857131958007,"Val'kyr Arbiter - On Script - Move To Position");

UPDATE `creature_text` SET `Duration` = 0, `comment` = "Val'kyr Arbiter" WHERE `CreatureID` = 30501;
UPDATE `creature_template_addon` SET `bytes1` = 50331648 WHERE `entry` = 30501;

-- Thane Illskar
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30475 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30475,3047500,3047501,3047502,30475000,30475001) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30475,0,0,0,11,0,100,0,0,0,0,0,0,133,1,99728,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Respawn - Respawn Gameobject 'Thane Illskar's Spell Focus'"),
(30475,0,1,0,8,0,100,0,36851,0,0,0,0,80,3047500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Spellhit 'Bethod's Sword Challenge' - Run Script"),
(30475,0,2,0,1,1,100,0,0,0,2000,2000,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - Out of Combat - Set Orientation Stored Target 1 (Phase 1)"),
(30475,0,3,0,38,0,100,0,0,1,0,0,0,80,3047501,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Data Set 0 1 - Run Script"),
(30475,0,4,0,38,0,100,0,0,2,0,0,0,80,3047502,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Data Set 0 2 - Run Script"),

(30475,0,5,0,0,0,100,0,0,0,3000,4000,0,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thane Illskar - In Combat CMC - Cast 'Fireball'"),
(30475,0,6,0,0,0,100,0,5000,10000,10000,15000,0,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thane Illskar - In Combat - Cast 'Frostfire Bolt'"),
(30475,0,7,0,0,0,100,0,10000,15000,17000,25000,0,11,17145,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - In Combat - Cast 'Blast Wave'"),
(30475,0,8,0,0,0,100,0,13000,18000,25000,35000,0,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thane Illskar - In Combat - Cast 'Rain of Fire'"),

(30475,0,9,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,30501,0,0,0,0,0,0,0,"Thane Illskar - On Just Died - Set Data 0 1 (Val'kyr Arbiter)"),

(3047500,9,0,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,20,192560,0,0,0,0,0,0,0,"Thane Illskar - On Script - Despawn Instant (Thane Illskar's Spell Focus)"),
(3047500,9,1,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Store Targetlist"),
(3047500,9,2,0,0,0,100,0,0,0,0,0,0,134,61779,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Invoker Cast 'Revenge for the Vargul: Challenge Issued Kill Credit'"),
-- Well, well, well
(3047500,9,3,0,0,0,100,0,0,0,0,0,0,11,52353,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Cast 'Script Effect - Creature Capture GUID to Dot Variable'"),
(3047500,9,4,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Set Orientation Invoker"),
(3047500,9,5,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Say Line 0"),
(3047500,9,6,0,0,0,100,0,5000,5000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Set Event Phase 1"),

(3047501,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - On Script - Say Line 1"),
(3047501,9,1,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - On Script - Say Line 2"),
(3047501,9,2,0,0,0,100,0,2000,2000,0,0,0,45,0,1,0,0,0,0,19,30484,0,0,0,0,0,0,0,"Thane Illskar - On Script - Set Data 0 1 (Brita)"),

(3047502,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Set Event Phase 0"),
(3047502,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - On Script - Say Line 3"),
(3047502,9,2,0,0,0,100,0,0,0,0,0,0,12,30501,2,180000,0,0,0,8,0,0,0,0,7848.1895,3400.8743,663.7552,3.784564971923828125,"Thane Illskar - On Script - Summon Creature 'Val'kyr Arbiter'"),
(3047502,9,3,0,0,0,100,0,5000,5000,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - On Script - Say Line 4"),
(3047502,9,4,0,0,0,100,0,5000,5000,0,0,0,11,52354,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Cast 'Script Effect - Creature Attack GUID from Dot Variable'"),
(3047502,9,5,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Illskar - On Script - Remove Flag Immune To Players"),
(3047502,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Thane Illskar - On Script - Start Attack Stored Target 1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 36851;
UPDATE `gameobject` SET `spawntimesecs` = 600 WHERE `id` = 192560;

DELETE FROM `creature_text` WHERE `CreatureID` = 30475;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(30475,0,0,"Bethod's Sword?!! Very well, $r, I accept your challenge. But first, you must best my champions. Volgur! Squash this insect!",14,0,100,15,0,0,31209,0,"Thane Illskar"),
(30475,1,0,"The thane spits as the first of his champions falls.",16,0,100,0,0,0,31210,0,"Thane Illskar"),
(30475,2,0,"Brita, create a pincushion of this puny $c!",14,0,100,22,0,0,31211,0,"Thane Illskar"),
(30475,3,0,"You may have defeated my champions, $c. I am something else entirely.",14,0,100,66,0,0,31212,0,"Thane Illskar"),
(30475,4,0,"Pray to your gods for a quick death.",14,0,100,53,0,0,31213,0,"Thane Illskar");

-- Volgur
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30483 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3048300) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30483,0,0,0,8,0,100,0,36851,0,0,0,0,80,3048300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Spellhit 'Bethod's Sword Challenge' - Run Script"),

(3048300,9,0,0,0,0,100,0,0,0,0,0,0,11,52353,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volgur - On Script - Cast 'Script Effect - Creature Capture GUID to Dot Variable'"),
(3048300,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volgur - On Script - Set Orientation Invoker"),
(3048300,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volgur - On Script - Set Orientation Invoker"),
(3048300,9,3,0,0,0,100,0,0,0,0,0,0,11,52354,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Cast 'Script Effect - Creature Attack GUID from Dot Variable'"),
(3048300,9,4,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Remove Flag Immune To Players"),
(3048300,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Volgur - On Script - Start Attack Invoker"),

(30483,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Aggro - Say Line 0"),
(30483,0,2,0,0,0,100,0,5000,5000,30000,31000,0,11,23262,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - In Combat - Cast 'Demoralize'"),
(30483,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Volgur - In Combat - Cast 'Chop'"),
(30483,0,4,0,0,0,100,0,0,0,15000,20000,0,11,49758,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Volgur - In Combat - Cast 'Charge'"),
(30483,0,5,0,0,0,100,0,15000,18000,15000,18000,0,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - In Combat - Cast 'Whirlwind'"),

(30483,0,6,0,6,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,30475,0,0,0,0,0,0,0,"Volgur - On Just Died - Set Data 0 1 (Thane Illskar)");

-- Brita
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30484 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3048400) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30484,0,0,0,8,0,100,0,36851,0,0,0,0,80,3048400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Spellhit 'Bethod's Sword Challenge' - Run Script"),
(30484,0,1,0,1,1,100,0,0,0,2000,2000,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brita - Out of Combat - Set Orientation Stored Target 1 (Phase 1)"),

(30484,0,2,3,38,0,100,0,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Data Set 0 1 - Set Event Phase 0"),
(30484,0,3,4,61,0,100,0,0,0,0,0,0,11,52354,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Link - Cast 'Script Effect - Creature Attack GUID from Dot Variable'"),
(30484,0,4,5,61,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Link - Remove Flag Immune To Players"),
(30484,0,5,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brita - On Link - Start Attack Stored Target 1"),

(30484,0,6,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Aggro - Say Line 0"),
(30484,0,7,0,0,0,100,0,0,0,2400,3000,0,11,49712,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Brita - In Combat CMC - Cast 'Shoot'"),
(30484,0,8,0,0,0,100,0,19500,19600,60000,60000,0,11,43414,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - In Combat - Cast 'Freezing Trap'"),
(30484,0,9,0,0,0,100,0,5000,10000,10000,15000,0,11,44286,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Brita - In Combat - Cast 'Wing Clip'"),
(30484,0,10,0,0,0,100,0,10000,15000,10000,15000,0,11,60932,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Brita - In Combat - Cast 'Disengage'"),
(30484,0,11,0,0,0,100,0,7000,10000,7000,10000,0,11,60954,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Brita - In Combat - Cast 'Aimed Shot'"),

(30484,0,12,0,6,0,100,0,0,0,0,0,0,45,0,2,0,0,0,0,19,30475,0,0,0,0,0,0,0,"Brita - On Just Died - Set Data 0 2 (Thane Illskar)"),

(3048400,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brita - On Script - Store Targetlist"),
(3048400,9,1,0,0,0,100,0,0,0,0,0,0,11,52353,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brita - On Script - Cast 'Script Effect - Creature Capture GUID to Dot Variable'"),
(3048400,9,2,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Brita - On Script - Set Orientation Invoker"),
(3048400,9,3,0,0,0,100,0,5000,5000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `CreatureID` IN (30483,30484);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(30483,0,0,"",0,0,100,0,0,13533,0,0,"Volgur"),
(30483,0,1,"",0,0,100,0,0,13534,0,0,"Volgur"),
(30483,0,2,"",0,0,100,0,0,13535,0,0,"Volgur"),
(30483,0,3,"",0,0,100,0,0,13536,0,0,"Volgur"),
(30483,0,4,"",0,0,100,0,0,13537,0,0,"Volgur"),
(30483,0,5,"",0,0,100,0,0,13538,0,0,"Volgur"),
(30483,0,6,"",0,0,100,0,0,13539,0,0,"Volgur"),
(30483,0,7,"",0,0,100,0,0,13540,0,0,"Volgur"),
(30483,0,8,"",0,0,100,0,0,13541,0,0,"Volgur"),
(30483,0,9,"",0,0,100,0,0,13542,0,0,"Volgur"),
(30484,0,0,"",0,0,100,0,0,14384,0,0,"Brita"),
(30484,0,1,"",0,0,100,0,0,14385,0,0,"Brita"),
(30484,0,2,"",0,0,100,0,0,14386,0,0,"Brita"),
(30484,0,3,"",0,0,100,0,0,14387,0,0,"Brita"),
(30484,0,4,"",0,0,100,0,0,14388,0,0,"Brita"),
(30484,0,5,"",0,0,100,0,0,14389,0,0,"Brita"),
(30484,0,6,"",0,0,100,0,0,14390,0,0,"Brita"),
(30484,0,7,"",0,0,100,0,0,14391,0,0,"Brita");
