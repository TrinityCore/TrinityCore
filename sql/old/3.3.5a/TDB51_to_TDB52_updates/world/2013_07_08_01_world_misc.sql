-- Pathing for Akama Entry: 23191
SET @PATH := 847160;
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,517.4877,400.7993,112.7837,0,0,0,0,100,0),
(@PATH,2,517.4877,400.7993,112.7837,3.118662,0,0,0,100,0);

SET @GOSSIP := 21335;
SET @TEXTID := 10866;
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP WHERE `entry`=23191;
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=22990;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=@TEXTID;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (@GOSSIP, @TEXTID);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`box_text`) VALUES
(@GOSSIP, 0, 0, 'I am ready to fight alongside you, Akama.', 1, 1, '');

UPDATE `creature` SET `id`=23191,`position_x`=547.1864,`position_y`=400.5344,`position_z`=112.8671,`orientation`=3.124139 WHERE `guid`=84716;
UPDATE `creature_template` SET `speed_walk`=1.6, `ScriptName` = 'npc_akama_shade' WHERE `entry`=23191;
UPDATE `creature_template` SET `ScriptName` = 'npc_creature_generator_akama' WHERE `entry`=23210;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry`=22990;

UPDATE `creature_template` SET `speed_run`=1.7143, `AIName`= '', `flags_extra`=0, `ScriptName` = 'npc_ashtongue_defender' WHERE `entry`=23216;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23216;
DELETE FROM `creature_equip_template` WHERE `entry`=23216 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(23216,1,18983,31468,0);

UPDATE `creature_template` SET `speed_run`=1.7143, `ScriptName` = 'npc_ashtongue_sorcerer' WHERE `entry`=23215;
DELETE FROM `creature_equip_template` WHERE `entry`=23215 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(23215,1,29685,0,0);

UPDATE `creature_template` SET `speed_run`=1.7143, `baseattacktime`=1600, `AIName`= '', `ScriptName` = 'npc_ashtongue_rogue' WHERE `entry`=23318;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23318;

DELETE FROM `creature_equip_template` WHERE `entry`=23318 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(23318,1,10612,10612,0);

UPDATE `creature_template` SET `speed_run`=0.99206, `faction_A`=1813, `faction_H`=1813 WHERE `entry`=22847;
DELETE FROM `creature_equip_template` WHERE `entry`=22847 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(22847,1,29651,13924,0);

UPDATE `creature_template` SET `speed_run`=0.99206, `faction_A`=1813, `faction_H`=1813 WHERE `entry`=22845;
DELETE FROM `creature_equip_template` WHERE `entry`=22845 AND `id`=1;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(22845,1,29685,0,0);

UPDATE `creature_template` SET `speed_walk`=2, `faction_A`=1813, `faction_H`=1813 WHERE `entry`=22849;

UPDATE `creature_template` SET `speed_run`=0.99206, `faction_A`=1813, `faction_H`=1813 WHERE `entry`=22846;

DELETE FROM `creature_text` WHERE `entry`=23191;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23191, 0, 0, 'Broken of the Ashtongue tribe, your leader speaks!', 14, 0, 100, 0, 0, 0, 'Akama SAY_BROKEN_FREE_0'),
(23191, 1, 0, 'The Betrayer no longer holds sway over us.  His dark magic over the Ashtongue soul has been destroyed!', 14, 0, 100, 0, 0, 0, 'Akama SAY_BROKEN_FREE_1'),
(23191, 2, 0, 'Come out from the shadows!  I''ve returned to lead you against our true enemy!  Shed your chains and raise your weapons against your Illidari masters!', 14, 0, 100, 0, 0, 0, 'Akama SAY_BROKEN_FREE_2');

DELETE FROM `creature` WHERE `guid` BETWEEN 53919 AND 53929;
UPDATE `creature` SET `modelid`=0 WHERE `id`=23033;
UPDATE `creature_template` SET `AIName`='', `flags_extra`=128 WHERE `entry`=23033;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=40607;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,40607,0,0,31,0,3,22841,0,0,'','Spell Fixate targets Shade of Akama');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=41602;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,41602,0,0,31,0,3,23191,0,0,'','Spell Threat targets Akama');

DELETE FROM `creature_addon` WHERE `guid`=12777;
DELETE FROM `creature_template_addon` WHERE `entry`=22841;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (22841, 1, '40973');
UPDATE `creature_template` SET `speed_walk`=0.8 WHERE `entry`=22841;
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags`=33587200, `unit_flags2`=0 WHERE `entry`=23421;
