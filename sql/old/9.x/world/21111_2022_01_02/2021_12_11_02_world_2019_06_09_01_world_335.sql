-- 
UPDATE `creature` SET `orientation`=5.448936 WHERE `id`=10638;
DELETE FROM `script_waypoint` WHERE `entry` =10638;
UPDATE `creature_template` SET `AIName`="SmartAI", ScriptName="" WHERE `entry` IN (10638,10720);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10638,10720) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1063800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10638,0,0,0,19,0,100,0,4966,0,0,0,80,1063800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - On quest accept - Action list"),
(1063800,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - Action list - remove npc flag"),
(1063800,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - Action list - Set run off"),
(1063800,9,2,0,0,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - Action list - Remove unit flag"),
(1063800,9,3,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - Set faction"),
(1063800,9,4,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,"Kanati Greycloud - Action list - Store target"),
(1063800,9,5,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4901.4824, -1372.647, -52.6119, 5.463072,"Kanati Greycloud - Action list - move to pos"),
(1063800,9,6,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - Action list - Say text"),
(1063800,9,7,0,0,0,100,0,3000,3000,0,0,12,10720,8,0,0,0,0,8,0,0,0,-4878.44531, -1396.48547, -53.30289, 2.375675,"Kanati Greycloud - Action list - Summon Galak Assassin"),
(1063800,9,8,0,0,0,100,0,0,0,0,0,12,10720,8,0,0,0,0,8,0,0,0,-4873.76416, -1397.92834, -53.46692, 2.375675,"Kanati Greycloud - Action list - Say text Galak Assassin"),
(1063800,9,9,0,0,0,100,0,0,0,0,0,12,10720,8,0,0,0,0,8,0,0,0,-4876.83105, -1401.11694, -53.21575, 2.375675,"Kanati Greycloud - Action list - Say text Galak Assassin"),
(10638,0,1,2,77,0,100,0,1,3,5000,5000,15,4966,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kanati Greycloud - On counter - Quest explored"),
(10638,0,2,3,61,0,100,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - Set unit flag"),
(10638,0,3,4,61,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - Add npc flag"),
(10638,0,4,5,61,0,100,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - reset counter"),
(10638,0,5,6,61,0,100,0,0,0,0,0,2,104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - reset faction"),
(10638,0,6,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - Evade"),
(10638,0,7,8,7,0,100,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - In evade - Set unit flag"),
(10638,0,8,9,61,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - Add npc flag"),
(10638,0,9,10,61,0,100,0,0,0,0,0,63,1,0,1,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - reset counter"),
(10638,0,10,6,61,0,100,0,0,0,0,0,2,104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kanati Greycloud - link - reset faction"),
(10720,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,10638,0,0,0,0,0,0,"Galak Assassin - Just summoned - attack"),
(10720,0,1,0,0,0,100,0,2000,7000,8000,12000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Assassin - IC - Cast Net"),
(10720,0,2,0,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Assassin - On evade - Despawn"),
(10720,0,3,0,6,0,100,0,0,0,0,0,63,1,1,0,0,0,0,19,10638,0,0,0,0,0,0,"Galak Assassin - On Death - Set counter");

DELETE FROM `creature_template_addon` WHERE `entry`=10720;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(10720,0,0,1,0, "3616");
