-- 
DELETE FROM `creature` WHERE `id`=26674;

-- Delete wrong data for Darkweb Hatchling.
DELETE FROM `creature_addon` WHERE `guid` IN (127472, 127473, 127474, 127475);
DELETE FROM `waypoint_data` WHERE `id` IN (1274720, 1274730, 1274740, 1274750);
DELETE FROM `linked_respawn` WHERE `guid` IN (127472, 127473, 127474, 127475);

UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=26675;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (26625, 26674, 26675);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26625, 26674, 26675, 2667500) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26625, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - On Aggro - Set Event Phase 1"),
(26625, 0, 1, 0, 0, 1, 100, 0, 4000, 8000, 20000, 30000, 0, 11, 49704, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - IC - Cast 'Encasing Webs' (Phase 1)"),
(26625, 0, 2, 0, 0, 1, 100, 0, 2000, 4000, 8000, 10000, 0, 11, 49708, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - IC - Cast 'Poison Spit' (Phase 1)"),
(26625, 0, 3, 4, 2, 0, 100, 1, 0, 20, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - Health Between 0-20% - Set Event Phase 0"),
(26625, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - Health Between 0-20% - Say Line 0"),
(26625, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 92, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - Health Between 0-20% - Stop Current Cast"),
(26625, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - Health Between 0-20% - Set ReactState Passive"),
(26625, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 26675, 100, 0, 0, 0, 0, 0, "Darkweb Recluse - Health Between 0-20% - Move To Nearby NPC 'Spider Summon Target'"),
(26625, 0, 8, 9, 34, 0, 100, 0, 0, 1, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26675, 5, 0, 0, 0, 0, 0, "Darkweb Recluse - On MovementInform PointID 1 - Set Data 1 1 To Nearby NPC 'Spider Summon Target'"),
(26625, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - On MovementInform PointID 1 - Set Event Phase 1"),
(26625, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - On MovementInform PointID 1 - Set ReactState Aggressive"),
(26625, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Darkweb Recluse - On MovementInform PointID 1 - Attack Target"),

(26674, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, "Darkweb Hatchling - On Spawn - Attack Closest Player"),

(26675, 0, 0, 0, 38, 0, 100, 0, 1, 1, 10000, 10000, 0, 80, 2667500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Data Set 1 1 - Run Script"),
(2667500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'"),
(2667500, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 11, 47302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spider Summon Target - On Script - Summon Creature 'Darkweb Hatchling'");

DELETE FROM `creature_text` WHERE `CreatureID`=26625;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26625, 0, 0, "%s flees back to its den....", 16, 0, 100, 0, 0, 0, 26536, 0, "Darkweb Recluse");

-- Spider Summon Targets are behind invisible walls, so disable MMAPS for mobs that must go through this wall.
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|536870912 WHERE `entry` IN (26674, 31335, 26625, 31336);
