-- Pulroy the Archaeologist
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24122;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24122);
DELETE FROM `creature_template_addon` WHERE `entry` = 24122;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(24122,'29266');
-- Zedd
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 24145;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24145);
DELETE FROM `creature_template_addon` WHERE `entry` = 24145;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(24145,'29266');
-- Trapped Animal
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24196;
-- Slain Apothecary
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 24280;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24280);
DELETE FROM `creature_template_addon` WHERE `entry` = 24280;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(24280,'29266');
-- Shadowstalker Luther
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25328;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 25328);
DELETE FROM `creature_template_addon` WHERE `entry` = 25328;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(25328,'45530 29266');
-- Dead Caravan Guard & Dead Caravan Worker
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25342;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25343;
-- Steeljaw's Corpse & William Allerton
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25384;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25385;
-- Oil Pool
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912 WHERE `entry` = 25781;

-- Fizzcrank Recon Pilot, everything is messed up
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `emote` = 0, `auras` = "29266" WHERE `entry` = 25841;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25841;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 9190;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9190,0,0,0,47,0,11795,10,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has taken quest 'Emergency Protocol: Section 8.2, Paragraph C'"),
(15,9190,1,0,0,47,0,11887,10,0,0,0,0,"","Group 0: Show Gossip Option 1 if player has taken quest 'Emergency Supplies'");

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 9190;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(9190,0,0,"Search for the pilot's insignia.",25042,1,1,0,0,0,0,"",0,11723),
(9190,1,0,"Search the body for the pilot's emergency toolkit.",25112,1,1,0,0,0,0,"",0,0);

UPDATE `gossip_menu` SET `VerifiedBuild` = 11723 WHERE `MenuID` = 9190;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25841 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25841,0,0,2,62,0,100,0,9190,0,0,0,0,11,46166,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fizzcrank Recon Pilot - On Gossip Option 0 Selected - Cast 'Summon Pilot's Insignia'"),
(25841,0,1,2,62,0,100,0,9190,1,0,0,0,11,46362,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fizzcrank Recon Pilot - On Gossip Option 1 Selected - Cast 'Give Emergency Kit'"),
(25841,0,2,3,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fizzcrank Recon Pilot - On Link - Close Gossip"),
(25841,0,3,4,61,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fizzcrank Recon Pilot - On Link - Remove NPC Flag Gossip"),
(25841,0,4,0,61,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fizzcrank Recon Pilot - On Link - Delayed Despawn");

-- Crashed Recon Pilot
UPDATE `creature_template_addon` SET `bytes1` = 0, `bytes2` = 1, `auras` = "29266" WHERE `entry` = 25984;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 25984;

-- Taunka'le Evacuee
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26159;
DELETE FROM `creature_template_addon` WHERE `entry` = 26159;
DELETE FROM `creature_addon` WHERE `guid` IN (100356,100354,100358,100357,100355,100359,100360,100361,100362,100363,100364,100365,100366,100367,100376,100378,100379,100381,100382,100383,100388,100389,100390,100393,100394,100395,100401,100403,100417);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(100356,0,0,1,257,0,0,""),
(100354,0,0,1,257,0,0,""),
(100358,0,0,1,257,0,0,""),
(100357,0,0,1,257,0,0,""),
(100355,0,0,1,257,0,0,""),
(100359,0,0,1,257,0,0,""),
(100360,0,0,0,1,0,0,"46708 29266"),
(100361,0,0,0,1,0,0,"46708 29266"),
(100362,0,0,0,1,0,0,"46708 29266"),
(100363,0,0,0,1,0,0,"46708 29266"),
(100364,0,0,0,1,0,0,"46708 29266"),
(100365,0,0,0,1,0,0,"46708 29266"),
(100366,0,0,0,1,0,0,"46708 29266"),
(100367,0,0,0,1,0,0,"46708 29266"),
(100376,0,0,0,1,0,0,"46708 29266"),
(100378,0,0,0,1,0,0,"46708 29266"),
(100379,0,0,0,1,0,0,"46708 29266"),
(100381,0,0,0,1,0,0,"46708 29266"),
(100382,0,0,0,1,0,0,"46708 29266"),
(100383,0,0,0,1,0,0,"46708 29266"),
(100388,0,0,0,1,0,0,"46708 29266"),
(100389,0,0,0,1,0,0,"46708 29266"),
(100390,0,0,0,1,0,0,"46708 29266"),
(100393,0,0,0,1,0,0,"46708 29266"),
(100394,0,0,0,1,0,0,"46708 29266"),
(100395,0,0,0,1,0,0,"46708 29266"),
(100401,0,0,0,1,0,0,"46708 29266"),
(100403,0,0,0,1,0,0,"46708 29266"),
(100417,0,0,0,1,0,0,"46708 29266");
UPDATE `creature` SET `unit_flags` = 33536 WHERE `id` = 26159 AND `guid` IN (100360,100361,100362,100363,100364,100365,100366,100367,100376,100378,100379,100381,100382,100383,100388,100389,100390,100393,100394,100395,100401,100403,100417);

-- Taunka'le Pack Kodo, these are freezed, bad model detail
UPDATE `creature_template` SET `unit_flags` = 0, `dynamicflags` = 0 WHERE `entry` = 26160;
DELETE FROM `creature_template_addon` WHERE `entry` = 26160;
DELETE FROM `creature_addon` WHERE `guid` IN (100459,100456,100457,100460,100464);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(100459,0,0,1,257,0,0,""),
(100456,0,0,1,257,0,0,""),
(100457,0,0,0,1,0,0,"46708 29266"),
(100460,0,0,0,1,0,0,"46708 29266"),
(100464,0,0,0,1,0,0,"46708 29266");
UPDATE `creature` SET `unit_flags` = 768 WHERE `id` = 26160 AND `guid` IN (100457,100460,100464);

-- Slain Cultist
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26172;

-- Iruk
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26219;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 26219);
DELETE FROM `creature_template_addon` WHERE `entry` = 26219;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(26219,0,0,0,1,383,0,"29266");
UPDATE `smart_scripts` SET `action_param2` = 2, `comment` = "Iruk - On Gossip Option 0 Selected - Cast 'Create Totem of Issliruk'" WHERE `entryorguid` = 26219 AND `source_type` = 0 AND `id` = 0;

-- Drakkari Shaman Corpse & Drakkari Warrior Corpse
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26513;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 26516;
