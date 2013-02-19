-- Orgrimmar: Hidden Enemies (5727)
SET @Gossip=21272;

DELETE FROM `gossip_menu` WHERE `text_id` IN (4513,4533,4534,4535,4536);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(3701,4513), -- 1st
(@Gossip+0,4533), -- 2nd
(@Gossip+1,4534), -- 3rd
(@Gossip+2,4535), -- 4th
(@Gossip+3,4536); -- last
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3701,@Gossip+0,@Gossip+1,@Gossip+2,@Gossip+3);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(3701,0,0, 'You may speak frankly, Neeru...' ,1,1,@Gossip+0,0,0,0,NULL),
(@Gossip+0,0,0, 'It is good to see the Burning Blade is taking over where the Shadow Council once failed.' ,1,1,@Gossip+1,0,0,0,NULL),
(@Gossip+1,0,0, 'So the Searing Blade is expendable?' ,1,1,@Gossip+2,0,0,0,NULL),
(@Gossip+2,0,0, 'If there is anything you would have of me...' ,1,1,@Gossip+3,0,0,0,NULL); -- Must Link to Final Action Menu as well

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=3216; -- Neeru Fireblade
DELETE FROM `smart_scripts` WHERE `entryorguid`=3216 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3216, 0, 0, 0, 62, 0, 100, 0, @Gossip+2, 0, 0, 0, 15, 5727, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Neeru Fireblade - On gossip select give Hidden Enemies quest completed');

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|2 WHERE `entry`=5727; -- Hidden Enemies (quest completable by external event)
-- Conditions so gossips don't show up if the player doesn't have the item
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=3701;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` BETWEEN @Gossip+0 AND @Gossip+3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,3701,0,0,2,14544,1,0,0,'', 'Neeru Fireblade: Quest Hidden Enemies gossip option - requires item Lieutenant''s Insignia'),
(14,@Gossip+0,4533,0,2,14544,1,0,0, '', 'Neeru Fireblade: Quest Hidden Enemies gossip 1 - requires item Lieutenant''s Insignia'),
(14,@Gossip+1,4534,0,2,14544,1,0,0, '', 'Neeru Fireblade: Quest Hidden Enemies gossip 2 - requires item Lieutenant''s Insignia'),
(14,@Gossip+2,4535,0,2,14544,1,0,0, '', 'Neeru Fireblade: Quest Hidden Enemies gossip 3 - requires item Lieutenant''s Insignia'),
(14,@Gossip+3,4536,0,2,14544,1,0,0, '', 'Neeru Fireblade: Quest Hidden Enemies gossip 4 - requires item Lieutenant''s Insignia');
