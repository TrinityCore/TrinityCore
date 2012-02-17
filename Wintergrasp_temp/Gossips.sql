-- Template gossip updates
UPDATE `creature_template` SET `gossip_menu_id`=9904 WHERE `entry`=30400;
UPDATE `creature_template` SET `gossip_menu_id`=10229 WHERE `entry`=31091;

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13759;
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13761;
DELETE FROM `gossip_menu` WHERE `entry`=9923 AND `text_id`=14172;
DELETE FROM `gossip_menu` WHERE `entry`=10229 AND `text_id`=14221;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9904,13759),
(9904,13761),
(9923,14172),
(10229,14221);

-- Gossip Menu Option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9904;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10129 AND `id` IN (2,4);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9904,0,0, 'I would like to build a catapult.',1,1,0,0,0,0, ''),
(9904,1,0, 'I would like to build a demolisher.',1,1,0,0,0,0, ''),
(9904,2,0, 'I would like to build a siege engine.',1,1,0,0,0,0, ''),
(10129,2,0, 'Guide me to the Broken Temple Graveyard.',1,1,0,0,0,0, ''),
(10129,4,0, 'Guide me to the Eastspark Graveyard.',1,1,0,0,0,0, '');

-- Conditions
-- Add gossip_menu condition for 9904 Horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9904;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9923;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9904;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9923;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(14,9904,13759,0,1,33280), -- Must have Rank 1: Corporal
(14,9904,13759,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9904,13761,0,11,33280), -- Must not have Rank 1: Corporal
(14,9904,13761,0,11,55629), -- Must not have Rank 2: First Lieutenant
-- Add gossip_menu condition for 9923 Alliance
(14,9923,13798,0,1,33280), -- Must have Rank 1: Corporal
(14,9923,13798,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9923,14172,0,11,33280), -- Must not have Rank 1: Corporal
(14,9923,14172,0,11,55629), -- Must not have Rank 2: First Lieutenant
-- Add conditions to gossip options horde
(15,9904,0,0,1,33280), -- Must have reached Rank 1: Corporal
(15,9904,0,1,1,55629), -- Or must have reached Rank 2: First Lieutenant
(15,9904,1,0,1,55629), -- Must have reached Rank 2: First Lieutenant
(15,9904,2,0,1,55629), -- Must have reached Rank 2: First Lieutenant
-- Add conditions to gossip options alliance
(15,9923,0,0,1,33280), -- Must have reached Rank 1: Corporal
(15,9923,0,1,1,55629), -- Or must have reached Rank 2: First Lieutenant
(15,9923,1,0,1,55629), -- Must have reached Rank 2: First Lieutenant
(15,9923,2,0,1,55629); -- Must have reached Rank 2: First Lieutenant

/* -- Add scripts to Wintergrasp spirit guide gossip
-- !!!should be scripted by SAI or cpp script!!!
UPDATE `gossip_menu_option` SET `action_script_id`=1012800 WHERE `menu_id` IN (10128,10129) AND `id`=0;
UPDATE `gossip_menu_option` SET `action_script_id`=1012801 WHERE `menu_id` IN (10128,10129) AND `id`=1;
UPDATE `gossip_menu_option` SET `action_script_id`=1012802 WHERE `menu_id` IN (10128,10129) AND `id`=2;
UPDATE `gossip_menu_option` SET `action_script_id`=1012803 WHERE `menu_id` IN (10128,10129) AND `id`=3;
UPDATE `gossip_menu_option` SET `action_script_id`=1012804 WHERE `menu_id` IN (10128,10129) AND `id`=4;
UPDATE `gossip_menu_option` SET `action_script_id`=1012805 WHERE `menu_id`=10128 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_script_id`=1012806 WHERE `menu_id`=10129 AND `id`=5;

-- Add Teleport graveyard Spells to gossip scripts
DELETE FROM `gossip_scripts` WHERE `id` IN (1012800,1012801,1012802,1012803,1012804,1012805,1012806);
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`) VALUES
(1012800,0,33,0,0),(1012800,0,15,59760,1),
(1012801,0,33,0,0),(1012801,0,15,59762,1),
(1012802,0,33,0,0),(1012802,0,15,59763,1),
(1012803,0,33,0,0),(1012803,0,15,59766,1),
(1012804,0,33,0,0),(1012804,0,15,59767,1),
(1012805,0,33,0,0),(1012805,0,15,59769,1),
(1012806,0,33,0,0),(1012806,0,15,59765,1);

-- Add scripts to Wintergrasp engineers
-- already done by engineer's script
UPDATE `gossip_menu_option` SET `action_script_id`=990400 WHERE `menu_id` IN (9904,9923) AND `id`=0;
UPDATE `gossip_menu_option` SET `action_script_id`=990401 WHERE `menu_id` IN (9904,9923) AND `id`=1;
UPDATE `gossip_menu_option` SET `action_script_id`=990402 WHERE `menu_id` IN (9904) AND `id`=2;
UPDATE `gossip_menu_option` SET `action_script_id`=990403 WHERE `menu_id` IN (9923) AND `id`=2;

-- Add create vehicle Spells to gossip scripts
DELETE FROM `gossip_scripts` WHERE `id` IN (990400,990401,990402);
INSERT INTO `gossip_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`) VALUES
(990400,0,33,0,0),(990400,0,15,56663,1),
(990401,0,33,0,0),(990401,0,15,56575,1),
(990402,0,33,0,0),(990402,0,15,61408,1),
(990403,0,33,0,0),(990403,0,15,56661,1);
*/
