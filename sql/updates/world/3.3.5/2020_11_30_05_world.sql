-- Remaining issues: text from creature 23837 should be used by player after aura 25732 apply
-- After spell cast 57889 player should cast 57891 & 57885, currently handled by linked spells but should be handled in script
UPDATE `creature_template` SET `minlevel` = 79 WHERE `entry` = 30835;
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 0.99206284114 WHERE `entry` = 30836;
UPDATE `creature_text` SET `comment` = "Image of a Shadow Cultist" WHERE `CreatureID` = 30835;
UPDATE `creature_text` SET `comment` = "Image of Vardmadra" WHERE `CreatureID` = 30836;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30836 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3083600) AND `source_type` = 9;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30835 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3083500,3083501) AND `source_type` = 9;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 192861 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30836,0,0,0,54,0,100,0,0,0,0,0,0,80,3083600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Vardmadra - On Just Summoned - Run Script"),

(3083600,9,0,0,0,0,100,0,1500,1500,0,0,0,66,0,0,0,0,0,0,19,30835,30,0,0,0,0,0,0,"Image of Vardmadra - On Script - Set Orientation Closest Creature 'Image of a Shadow Cultist'"),

(30835,0,0,0,54,0,100,0,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,0,6829.184,3814.8867,621.06964,0,"Image of a Shadow Cultist - On Just Summoned - Move To Position"),
(30835,0,1,0,34,0,100,0,8,1,0,0,0,80,3083500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Reached Point 1 - Run Script"),
(30835,0,2,0,34,0,100,0,8,2,0,0,0,80,3083501,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Reached Point 2 - Run Script"),
(30835,0,3,0,54,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Just Summoned - Set Run Off"),

(3083500,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Set Orientation Closest Creature 'Image of Vardmadra'"),
(3083500,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Set Flag Standstate Kneel"),
(3083500,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 0"),
(3083500,9,3,0,0,0,100,0,1500,1500,0,0,0,1,0,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 0 (Image of Vardmadra)"),
(3083500,9,4,0,0,0,100,0,1500,1500,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 1"),
(3083500,9,5,0,0,0,100,0,6500,6500,0,0,0,1,1,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 1 (Image of Vardmadra)"),
(3083500,9,6,0,0,0,100,0,500,500,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 2"),
(3083500,9,7,0,0,0,100,0,3500,3500,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 3"),
(3083500,9,8,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 2 (Image of Vardmadra)"),
(3083500,9,9,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 4"),
(3083500,9,10,0,0,0,100,0,4000,4000,0,0,0,1,3,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 3 (Image of Vardmadra)"),
(3083500,9,11,0,0,0,100,0,8000,8000,0,0,0,1,4,0,0,0,0,0,19,30836,10,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 4 (Image of Vardmadra)"),
(3083500,9,12,0,0,0,100,0,4000,4000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Remove Flag Standstate Kneel"),
(3083500,9,13,0,0,0,100,0,2000,2000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Say Line 5"),
(3083500,9,14,0,0,0,100,0,2000,2000,0,0,0,69,2,0,0,0,0,0,8,0,0,0,0,6817.6914,3802.5713,621.06964,0,"Image of a Shadow Cultist - On Script - Move To Position"),

(3083501,9,0,0,0,0,100,0,0,0,0,0,0,86,57884,0,19,30836,30,0,23,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Cross Cast 'Through the Eye: Kill Credit to Master' (Image of Vardmadra)"),
(3083501,9,1,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,19,30836,30,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Delayed Despawn (Image of Vardmadra)"),
(3083501,9,2,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of a Shadow Cultist - On Script - Despawn Instant"),

(192861,1,0,1,62,0,100,0,10005,0,0,0,0,11,57888,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Eye of the Lich King - On Gossip Option 0 Selected - Cast 'Through the Eye: Eye of the Lich King Gossip Force Cast'"),
(192861,1,1,2,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,23837,10,0,0,0,0,0,0,"Eye of the Lich King - On Gossip Option 0 Selected - Set Data 0 1"),
(192861,1,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Eye of the Lich King - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (57885,57891);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,57885,0,0,31,0,3,23837,121192,0,0,0,"","Group 0: Spell 'Through the Eye: Summon Image of a Shadow Cultist' targets creature 'ELM General Purpose Bunny'"),
(13,1,57891,0,0,31,0,3,23837,121193,0,0,0,"","Group 0: Spell 'Through the Eye: Summon Image of Vardmadra' targets creature 'ELM General Purpose Bunny'");
