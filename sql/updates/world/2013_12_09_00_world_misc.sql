-- Fix for Quest 13285 "Forging the Keystone"

-- Missing Brann Bronzebeard spawn
SET @GUID := 24;
DELETE FROM `creature` WHERE `guid` IN (@GUID);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,31810,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0);

-- Brann Bronzebeard creature update
UPDATE `creature_template` SET `gossip_menu_id`=10124,`minlevel`=80,`maxlevel`=80,`exp`=2,`npcflag`=3, `AIName`= '',ScriptName = 'npc_brann_bronzebeard' WHERE `entry`=31810;
DELETE FROM `creature_template_addon` WHERE `entry`=31810;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31810,0,0,1,0, '54500');

-- Add missing equipment for Brann Bronzebeard
DELETE FROM `creature_equip_template` WHERE `entry`=31810;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES (31810,1,1903,0,0);

-- Add Missing gossip for Brann Bronzebeard
DELETE FROM `gossip_menu` WHERE (`entry`=10124 AND `text_id`=13641);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10124,13641);
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=10124);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(10124,0,0, 'I''m ready, Brann. Let''s make the keystone.',1,1,0,0,0,0, '');

-- Talk text for Brann Bronzebeard
SET @ENTRY := 31810;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Let''s see if we can finish this keystone.',12,0,100,1,0,0, 'Brann Bronzebeard'),
(@ENTRY,1,0,'The keystone is completed! We''ve done it, $N!',12,0,100,5,0,0, 'Brann Bronzebeard'),
(@ENTRY,2,0,'Who knows what secrets await within Ulduar''s archives? I''m off to discover them. Thank you again for your help, $N. Without it, I''d still be searching for that key.',12,0,100,66,0,0, 'Brann Bronzebeard');

-- Spell "See Quest Brann Bronzebeard (TOI)" for quest "Forging the Keystone"
DELETE FROM `spell_area` WHERE `spell`=60963;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(60963, 4466, 13285, 0, 0, 0, 2, 1, 74, 11);

-- A Distant Voice creature update
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=2,`InhabitType`=4,`flags_extra`=`flags_extra`|128 WHERE `entry`=31814;
DELETE FROM `creature_template_addon` WHERE `entry`=31814;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31814,0,0,1,0, '35709');

-- Talk text for A Distant Voice
SET @ENTRY := 31814;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Welcome, Brann Bronzebeard. I am all that remains of this temple''s guardian.',12,0,100,0,0,0, 'A Distant Voice'),
(@ENTRY,1,0,'You have proven yourself as an explorer and seeker of knowledge.',12,0,100,0,0,0, 'A Distant Voice'),
(@ENTRY,2,0,'You have been a steadfast ally to the Earthen.',12,0,100,0,0,0, 'A Distant Voice'),
(@ENTRY,3,0,'You and your companion have proven yourselves in combat and in the pursuit of the keystone.',12,0,100,0,0,0, 'A Distant Voice'),
(@ENTRY,4,0,'Your motives are pure. The keystone''s parts shall be reunited. Go to Ulduar and learn the answers to your questions, Brann Bronzebeard.',12,0,100,0,0,0, 'A Distant Voice');
