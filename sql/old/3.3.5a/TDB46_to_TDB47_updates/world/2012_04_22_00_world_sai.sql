-- SAI for Tabard Vendor Elizabeth Ross
SET @ROSS := 28776;
SET @GOSSIP := 9832;

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ROSS;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id`>0 AND `id`<11;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP, 1, 0, 'I''ve lost my Blood Knight Tabard.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 2, 0, 'I''ve lost my Tabard of the Hand.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 3, 0, 'I''ve lost my Tabard of the Protector.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 4, 0, 'I''ve lost my Green Trophy Tabard of the Illidari.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 5, 0, 'I''ve lost my Purple Trophy Tabard of the Illidari.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 6, 0, 'I''ve lost my Tabard of Summer Skies.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 7, 0, 'I''ve lost my Tabard of Summer Flames.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 8, 0, 'I''ve lost my Loremaster''s Colors.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 9, 0, 'I''ve lost my Tabard of the Explorer.', 1, 1, 0, 0, 0, 0, ''),
(@GOSSIP, 10, 0, 'I''ve lost my Tabard of the Achiever.', 1, 1, 0, 0, 0, 0, '');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ROSS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ROSS, 0, 0, 10, 62, 0, 100, 0, @GOSSIP, 1, 0, 0, 11, 54974, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Blood Knight Tabard'),
(@ROSS, 0, 1, 10, 62, 0, 100, 0, @GOSSIP, 2, 0, 0, 11, 54976, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of the Hand'),
(@ROSS, 0, 2, 10, 62, 0, 100, 0, @GOSSIP, 3, 0, 0, 11, 55008, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of the Protector'),
(@ROSS, 0, 3, 10, 62, 0, 100, 0, @GOSSIP, 4, 0, 0, 11, 54977, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Green Trophy Tabard of the Illidari'),
(@ROSS, 0, 4, 10, 62, 0, 100, 0, @GOSSIP, 5, 0, 0, 11, 54982, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Purple Trophy Tabard of the Illidari'),
(@ROSS, 0, 5, 10, 62, 0, 100, 0, @GOSSIP, 6, 0, 0, 11, 62768, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of Summer Skies'),
(@ROSS, 0, 6, 10, 62, 0, 100, 0, @GOSSIP, 7, 0, 0, 11, 62769, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of Summer Flames'),
(@ROSS, 0, 7, 10, 62, 0, 100, 0, @GOSSIP, 8, 0, 0, 11, 58194, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Loremaster''s Colors'),
(@ROSS, 0, 8, 10, 62, 0, 100, 0, @GOSSIP, 9, 0, 0, 11, 58224, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of the Explorer'),
(@ROSS, 0, 9, 10, 62, 0, 100, 0, @GOSSIP, 10, 0, 0, 11, 55006, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Cast Spell Create Tabard of the Achiever'),
(@ROSS, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Elizabeth Ross - On Gossip Select - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP,1,0,2,25549,1,1,1,0,'','Only show gossip if player doesn''t have Blood Knight Tabard'),
(15,@GOSSIP,1,0,8,9737,0,0,0,0,'','Only show gossip if player already finished quest True Masters of Light'),
(15,@GOSSIP,2,0,2,24344,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of the Hand'),
(15,@GOSSIP,2,0,8,9762,0,0,0,0,'','Only show gossip if player already finished quest The Unwritten Prophecy'),
(15,@GOSSIP,3,0,2,28788,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of the protector'),
(15,@GOSSIP,3,0,8,10259,0,0,0,0,'','Only show gossip if player already finished quest Into the Breach'),
(15,@GOSSIP,4,0,2,31404,1,1,1,0,'','Only show gossip if player doesn''t have Green Trophy Tabard of Illidari'),
(15,@GOSSIP,4,0,2,31405,1,1,1,0,'','Only show gossip if player doesn''t have Purple Trophy Tabard of Illidari'),
(15,@GOSSIP,4,0,2,31408,1,1,1,0,'','Only show gossip if player doesn''t have Offering of the Sha''tar'),
(15,@GOSSIP,4,0,8,10781,0,0,0,0,'','Only show gossip if player already finished quest Battle of the Crimson Watch'),
(15,@GOSSIP,5,0,2,31404,1,1,1,0,'','Only show gossip if player doesn''t have Green Trophy Tabard of Illidari'),
(15,@GOSSIP,5,0,2,31405,1,1,1,0,'','Only show gossip if player doesn''t have Purple Trophy Tabard of Illidari'),
(15,@GOSSIP,5,0,2,31408,1,1,1,0,'','Only show gossip if player doesn''t have Offering of the Sha''tar'),
(15,@GOSSIP,5,0,8,10781,0,0,0,0,'','Only show gossip if player already finished quest Battle of the Crimson Watch'),
(15,@GOSSIP,6,0,2,35279,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of Summer Skies'),
(15,@GOSSIP,6,0,2,35280,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of Summer Flames'),
(15,@GOSSIP,6,0,8,11972,0,0,0,0,'','Only show gossip if player already finished quest Shards of Ahune'),
(15,@GOSSIP,7,0,2,35279,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of Summer Skies'),
(15,@GOSSIP,7,0,2,35280,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of Summer Flames'),
(15,@GOSSIP,7,0,8,11972,0,0,0,0,'','Only show gossip if player already finished quest Shards of Ahune'),
(15,@GOSSIP,8,0,2,43300,1,1,1,0,'','Only show gossip if player doesn''t have Loremaster''s Colors'),
(15,@GOSSIP,8,0,17,1681,0,0,0,0,'','Only show gossip if player have achievement Loremaster (A)'),
(15,@GOSSIP,8,1,2,43300,1,1,1,0,'','Only show gossip if player doesn''t have Loremaster''s Colors'),
(15,@GOSSIP,8,1,17,1682,0,0,0,0,'','Only show gossip if player have achievement Loremaster (H)'),
(15,@GOSSIP,9,0,2,43348,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of the Explorer'),
(15,@GOSSIP,9,0,17,45,0,0,0,0,'','Only show gossip if player have achievement Explore Northrend'),
(15,@GOSSIP,10,0,2,40643,1,1,1,0,'','Only show gossip if player doesn''t have Tabard of the Explorer'),
(15,@GOSSIP,10,0,17,1021,0,0,0,0,'','Only show gossip if player have achievement Twenty-Five Tabards');
