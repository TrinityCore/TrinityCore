-- Unused yet:
-- Wintergrasp is under attack!
-- Wintergrasp Fortress is under attack!
-- Winter's Edge Tower is under attack!
-- Eastern Bridge is under attack!
-- Western Bridge is under attack!
-- Westspark Bridge is under attack!
-- Flamewatch Tower is under attack!

-- 'You have reached Rank 1: Corporal' Sent to player by raid leader
-- 'You have reached Rank 2: First Lieutenant' Sent to player by raid leader

-- Wintergrasp coreside texts
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 12050 AND 12072;
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`)VALUES
(12050, '%s has been captured by %s ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12051, '%s is under attack by %s', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12052, 'The Broken Temple siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12053, 'Eastspark siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12054, 'Westspark siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12055, 'The Sunken Ring siege workshop', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12057, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12056, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12058, 'The battle for Wintergrasp is about to begin!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12059, 'You have reached Rank 1: Corporal', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12060, 'You have reached Rank 2: First Lieutenant', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12061, 'The south-eastern keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12062, 'The north-eastern keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12063, 'The south-western keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12064, 'The north-western keep tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12065, '%s has been damaged !', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12066, '%s has been destroyed!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12067, 'The battle for Wintergrasp begin!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12068, '%s has successfully defended the Wintergrasp fortress!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12069, 'The southern tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12070, 'The eastern tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12071, 'The western tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(12072, 'The Wintergrasp fortress has been captured by %s !', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Wintergrasp script texts
DELETE FROM `script_texts` WHERE entry BETWEEN -1850507 AND -1850500;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`)VALUES
(0, -1850500, 'Guide me to the Fortress Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850501, 'Guide me to the Sunken Ring Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850502, 'Guide me to the Broken Temple Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850503, 'Guide me to the Westspark Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850504, 'Guide me to the Eastspark Graveyard.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850505, 'Guide me back to the Horde landing camp.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850506, 'Guide me back to the Alliance landing camp.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''),
(0, -1850507, 'Se mettre dans la file pour le Joug-d''hiver.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, ''); -- (Needs proper english text, maybe "Get in the queue for Wintergrasp."?)

-- New support-commands for battlefield class
DELETE FROM `command` WHERE name IN ('bf start', 'bf stop', 'bf enable', 'bf switch', 'bf timer');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('bf start',3,'Syntax: .bf start #battleid'),
('bf stop',3,'Syntax: .bf stop #battleid'),
('bf enable',3,'Syntax: .bf enable #battleid'),
('bf switch',3,'Syntax: .bf switch #battleid'),
('bf timer',3,'Syntax: .bf timer #battleid #timer');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=15214 AND `groupid` BETWEEN 0 AND 30;
DELETE FROM `creature_text` WHERE `entry` IN (31036,31091) AND `groupid` BETWEEN 0 AND 3;
DELETE FROM `creature_text` WHERE `entry` IN (31108,31109,34924) AND `groupid`=0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15214,0,0, 'Let the battle begin!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,1,0, 'The southern tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,2,0, 'The southern tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,3,0, 'The eastern tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,4,0, 'The eastern tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,5,0, 'The western tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,6,0, 'The western tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,7,0, 'The north-western keep tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,8,0, 'The north-western keep tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,9,0, 'The south-eastern keep tower has been damaged!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,10,0, 'The south-eastern keep tower has been destroyed!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,11,0, 'The Broken Temple siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,12,0, 'The Broken Temple siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,13,0, 'The Broken Temple siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,14,0, 'The Broken Temple siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,15,0, 'The Eastspark siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,16,0, 'The Eastspark siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,17,0, 'The Eastspark siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,18,0, 'The Eastspark siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,19,0, 'The Sunken Ring siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,20,0, 'The Sunken Ring siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,21,0, 'The Sunken Ring siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,22,0, 'The Sunken Ring siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,23,0, 'The Westspark siege workshop has been attacked by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,24,0, 'The Westspark siege workshop has been captured by the Alliance!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,25,0, 'The Westspark siege workshop has been attacked by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,26,0, 'The Westspark siege workshop has been captured by the Horde!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,27,0, 'The Alliance has defended Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,28,0, 'The Alliance has captured Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,29,0, 'The Horde has defended Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
(15214,30,0, 'The Horde has captured Wintergrasp Fortress!',3,0,100,0,0,0, 'Invisible Stalker'),
-- Not sure if all Alliance text is here, need horde text
(31036,0,0, 'The first of the Horde towers has fallen! Destroy all three and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,1,0, 'The second tower has fallen! Destroy the final tower and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,2,0, 'The Horde towers have fallen! We have forced their hand. Finish off the remaining forces!',1,7,100,0,0,0, 'Commander Zanneth'),
(31036,3,0, 'Show those animals no mercy, $n!',0,7,100,0,0,0, 'Commander Zanneth'),
(31091,0,0, 'The first of the Alliance towers has fallen! Destroy all three and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,1,0, 'Lok''tar! The second tower falls! Destroy the final tower and we will hasten their retreat!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,2,0, 'The Alliance towers have fallen! We have forced their hand. Finish off the remaining forces!',1,7,100,0,0,0, 'Commander Dardosh'),
(31091,3,0, 'Show those animals no mercy, $n!',0,7,100,0,0,0, 'Commander Dardosh'), -- ???
(31108,0,0, 'Stop the Horde from retrieving the embers, $n. We cannot risk them having the advantage when the battle resumes!',0,7,100,0,0,0, 'Siege Master Stouthandle'),
(31109,0,0, 'Destroy their foul machines of war, $n!',0,7,100,0,0,0, 'Senior Demolitionist Legoso'),
(34924,0,0, 'The gates have been breached! Defend the keep!',1,0,100,0,0,0, 'High Commander Halford Wyrmbane');
