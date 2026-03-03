-- Mustering the Reds / Keristrasza
SET @SPAWN_GROUP_ID := 346; -- 1

UPDATE `spell_target_position` SET `PositionX` = 4034.25, `PositionY` = 7349.38, `PositionZ` = 635.97, `Orientation` = 4.520402908325195312, `VerifiedBuild` = 46158 WHERE `ID` = 46772;
UPDATE `spell_target_position` SET `PositionX` = 3574.22, `PositionY` = 6652.13, `PositionZ` = 195.185, `Orientation` = 3.630285024642944335, `VerifiedBuild` = 46158 WHERE `ID` = 46824;

UPDATE `creature` SET `phaseMask` = 1, `position_x` = 3580.8499, `position_y` = 6656.071, `position_z` = 195.70258, `orientation` = 3.778709173202514648, `VerifiedBuild` = 46158 WHERE `id` = 26206;

DELETE FROM `spawn_group` WHERE `spawnId` = 27588 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,0,27588);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Borean Tundra - Keristrasza",4);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26206,-27588,26117) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2620600,2620601,2620602,2620603) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26206,0,0,1,62,0,100,0,9262,0,0,0,0,11,46772,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Cast 'Teleport'"),
(26206,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 0 Selected - Close Gossip"),
(26206,0,2,3,62,0,100,0,9262,1,0,0,0,11,46824,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Cast 'Teleport'"),
(26206,0,3,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option 1 Selected - Close Gossip"),
(26206,0,4,0,54,0,100,0,0,0,0,0,0,80,2620600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Just Summoned - Run Script"),

(2620600,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Set Orientation Owner"),
(2620600,9,1,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Cast 'Simple Teleport'"),

(-27588,0,0,0,11,0,100,0,0,0,0,0,0,80,2620601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Spawn - Run Script"),
(-27588,0,1,0,58,0,100,0,0,2620600,0,0,0,80,2620602,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Waypoint Finished - Run Script"),
(-27588,0,2,0,58,0,100,0,0,2620601,0,0,0,80,2620603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Waypoint Finished - Run Script"),

(2620601,9,0,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Remove Gossip+QuestGiver Flag"),
(2620601,9,1,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Cast 'Simple Teleport'"),
(2620601,9,2,0,0,0,100,0,0,0,0,0,0,53,0,2620600,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Start Waypoint"),

(2620602,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 0"),
(2620602,9,1,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,19,26117,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 4 (Raelorasz)"),
(2620602,9,2,0,0,0,100,0,8000,8000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 1"),
(2620602,9,3,0,0,0,100,0,8000,8000,0,0,0,1,5,0,0,0,0,0,19,26117,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 5 (Raelorasz)"),
(2620602,9,4,0,0,0,100,0,8000,8000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 2"),
(2620602,9,5,0,0,0,100,0,8000,8000,0,0,0,1,6,0,0,0,0,0,19,26117,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 6 (Raelorasz)"),
(2620602,9,6,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Say Line 3"),
(2620602,9,7,0,0,0,100,0,3000,3000,0,0,0,53,0,2620601,0,0,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Start Waypoint"),

(2620603,9,0,0,0,0,100,0,0,0,0,0,0,132,346,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Keristrasza - On Script - Despawn SpawnGroup 346"),

(26117,0,0,1,62,0,100,0,9253,1,0,0,0,11,46764,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Raelorasz - On Gossip Option 1 Selected - Cast 'Push Arcane Prison'"),
(26117,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Raelorasz - On Gossip Option 1 Selected - Close Gossip"),
(26117,0,2,0,20,0,100,0,11967,0,0,0,0,131,346,0,0,4,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Quest 'Mustering the Reds' Rewarded - Spawn SpawnGroup 346");

DELETE FROM `waypoint_data` WHERE `id` IN (2620600,2620601);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(2620600,1,3572.7988,6651.349,195.26575,NULL,0,0,0,100,0),
(2620601,1,3577.1555,6642.89,195.21191,NULL,0,0,0,100,0),
(2620601,2,3581.8403,6636.9146,195.26575,NULL,0,0,0,100,0),
(2620601,3,3582.4182,6629.9614,195.09573,NULL,0,0,0,100,0),
(2620601,4,3589.9731,6625.721,194.20486,NULL,0,0,0,100,0),
(2620601,5,3598.081,6623.26,192.59402,NULL,0,0,0,100,0);

-- Drake Hunt (11919 / 11940)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4914 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4914,2,0,1,46,0,100,0,4914,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Transitus Shield) - On Trigger - Store Targetlist"),
(4914,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,26175,0,0,0,0,0,0,0,"Areatrigger (Transitus Shield) - On Link - Send Target 1 (Coldarra - Drake Hunt Invisman)"),
(4914,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,26175,0,0,0,0,0,0,0,"Areatrigger (Transitus Shield) - On Link - Set Data 0 1 (Coldarra - Drake Hunt Invisman)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4914;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4914,'SmartTrigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4914 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4914,2,0,1,0,46691,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player does have aura 'Drake Hatchling Subdued'");

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 26175;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26175 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26175,0,0,0,38,0,100,0,0,1,0,0,0,33,26175,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Coldarra - Drake Hunt Invisman - On Data Set 0 1 - Quest Credit 'Drake Hunt'"),
(26175,0,1,0,38,0,100,0,0,1,0,0,0,11,46693,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Coldarra - Drake Hunt Invisman - On Data Set 0 1 - Cast 'Strip Auras'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_red_dragonblood';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_borean_tundra_strip_auras',
'spell_borean_tundra_drake_hatchling_subdued',
'spell_borean_tundra_drake_harpoon',
'spell_borean_tundra_red_dragonblood');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46693, 'spell_borean_tundra_strip_auras'),
(46691, 'spell_borean_tundra_drake_hatchling_subdued'),
(46607, 'spell_borean_tundra_drake_harpoon'),
(46620, 'spell_borean_tundra_red_dragonblood');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26127 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26117 AND `source_type` = 0 AND `id` = 3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2612700,2612701,2612702,2611700,2611701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26127,0,0,0,0,0,100,0,15000,20000,20000,35000,0,11,36513,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - In Combat - Cast 'Intangible Presence'"),
(26127,0,1,0,0,0,100,0,5000,10000,15000,25000,0,11,36631,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - In Combat - Cast 'Netherbreath'"),

(26127,0,2,0,8,0,100,0,46673,0,0,0,0,80,2612700,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Capture Trigger' - Run Script"),
-- We have to store target because last invoker is removed after evade
(2612700,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Store Targetlist"),
(2612700,9,1,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Set Home Position"),
(2612700,9,2,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Evade"),
(2612700,9,3,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Set Faction 35"),
(2612700,9,4,0,0,0,100,0,0,0,0,0,0,29,20,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Start Follow Stored Target"),
(2612700,9,5,0,0,0,100,0,0,0,0,0,0,28,46607,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Remove Aura 'Drake Harpoon'"),
(2612700,9,6,0,0,0,100,0,0,0,0,0,0,11,46675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Subdued'"),
(2612700,9,7,0,0,0,100,0,0,0,0,0,0,11,46678,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Drake Vomit, Periodic'"),
(2612700,9,8,0,0,0,100,0,0,0,0,0,0,11,46691,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Drake Hatchling Subdued'"),
-- Cast as triggered, otherwise creature will not follow player
(2612700,9,9,0,0,0,100,0,0,0,0,0,0,11,46674,2,0,0,0,0,12,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Rope Beam'"),

(26127,0,3,0,8,0,100,0,46696,0,0,0,0,80,2612701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Drake Turn-in' - Run Script"),

(2612701,9,0,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0,3571.31,6651.11,196.26575,0,"Nexus Drake Hatchling - On Script - Move To Position"),
(2612701,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,3.799816131591796875,"Nexus Drake Hatchling - On Script - Set Orientation"),
(2612701,9,2,0,0,0,100,0,0,0,0,0,0,11,46702,0,0,0,0,0,19,26117,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Drake Completion Ping'"),

(26127,0,4,0,8,0,100,0,46704,0,0,0,0,80,2612702,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Raelorasz Fireball' - Run Script"),

(2612702,9,0,0,0,0,100,0,0,0,0,0,0,11,46703,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cast 'Complete Immolation'"),
(2612702,9,1,0,0,0,100,0,0,0,0,0,0,5,34,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Play Emote 34"),
(2612702,9,2,0,0,0,100,0,2000,2000,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Set Flag Standstate Dead"),
(2612702,9,3,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Despawn Instant"),

(26117,0,3,0,8,0,100,0,46702,0,0,0,0,88,2611700,2611701,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Spellhit 'Drake Completion Ping' - Run Random Script"),

(2611700,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Say Line 0"),
(2611700,9,1,0,0,0,100,0,0,0,0,0,0,11,46704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Cast 'Raelorasz Fireball'"),
(2611700,9,2,0,0,0,100,0,5000,5000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Set Flag Standstate Kneel"),
(2611700,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Say Line 1"),
(2611700,9,4,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Remove Flag Standstate Kneel"),

(2611701,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Say Line 2"),
(2611701,9,1,0,0,0,100,0,0,0,0,0,0,11,46704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Cast 'Raelorasz Fireball'"),
(2611701,9,2,0,0,0,100,0,5000,5000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Set Flag Standstate Kneel"),
(2611701,9,3,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Say Line 3"),
(2611701,9,4,0,0,0,100,0,5000,5000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raelorasz - On Script - Remove Flag Standstate Kneel");

DELETE FROM `creature_text` WHERE `CreatureID` = 26117;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26117,0,0,"Sleep now, young one....",12,0,100,0,0,0,25323,0,"Raelorasz"),
(26117,1,0,"A wonderful specimen.",12,0,100,0,0,0,25324,0,"Raelorasz"),
(26117,2,0,"Easy now, drakeling.",12,0,100,0,0,0,25325,0,"Raelorasz"),
(26117,3,0,"Yes, this one should advance my studies nicely....",12,0,100,0,0,0,25326,0,"Raelorasz"),
(26117,4,0,"Keristrasza! I wish that circumstances allowed for a more fitting welcome. Fate has been kind to return you to us.",12,0,100,5,0,0,25464,0,"Raelorasz"),
(26117,5,0,"Malygos - in the open? I hadn't dared hope for an opportunity such as this. I'll assemble our bretheren at once!",12,0,100,1,0,0,25467,0,"Raelorasz"),
(26117,6,0,"Of course, my lady. Until we meet again...",12,0,100,1,0,0,25468,0,"Raelorasz");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 46607;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,46607,0,0,31,1,3,26127,0,0,0,0,'',"Group 0: Spell 'Drake Harpoon' targets creature 'Nexus Drake Hatchling'"),
(17,0,46607,0,0,1,1,46675,0,0,1,0,0,'',"Group 0: Spell 'Drake Harpoon' can be used if target does not have aura 'Subdued'");

-- The Power of the Elements (11893)
DELETE FROM `creature_template_spell` WHERE `CreatureID` = 25987;

UPDATE `creature_template` SET `unit_flags` = 768, `AIName` = 'SmartAI' WHERE `entry` = 25987;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25987 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25987,0,0,0,11,0,100,0,0,0,0,0,0,11,46373,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Windsoul Totem - On Spawn - Cast 'Windsoul Totem Periodic'"),
(25987,0,1,0,8,0,100,0,46376,0,0,0,0,11,46378,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Windsoul Totem - On Spellhit 'Airy Soul' - Cast 'Windsoul Credt'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24601 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24601,0,0,0,0,0,100,0,10000,20000,10000,20000,0,11,50375,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Steam Rager - In Combat - Cast 'Steam Blast'"),
(24601,0,1,0,6,0,100,0,0,0,0,0,0,11,46376,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Steam Rager - On Death - Cast 'Airy Soul'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 24601 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,24601,0,0,1,1,46374,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if creature does have aura 'Windsoul Totem Aura'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 46376;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46376,0,0,31,0,3,25987,0,0,0,0,"","Group 0: Spell 'Airy Soul' (Effect 0) targets creature 'Windsoul Totem'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_windsoul_totem_aura';

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 25987;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(25987,1,1,1,1,0,0,NULL);
