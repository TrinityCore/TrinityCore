SET @NPC_URSOC := 26633;
SET @NPC_RAGEPAW := 27328;
SET @NPC_SPIRIT := 27373;
SET @NPC_BLOOD := 28854;

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9496 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9497 AND `id` IN (0,1,2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9496,0,0, 'We have the purified ashes of Vordrassil''s sapling.  If we can subdue Ursoc, we might be able to heal his soul.',1,1,9497,0,0,0, ''),
(9497,0,0, 'Assume your druidic bear form, Tur.',1,1,0,0,0,0, ''),
(9497,1,0, 'Help us subdue him.',1,1,0,0,0,0, ''),
(9497,2,0, 'We could use a healer.',1,1,0,0,0,0, '');

DELETE FROM `gossip_menu` WHERE `entry`=9496 AND `text_id`=12785;
DELETE FROM `gossip_menu` WHERE `entry`=9497 AND `text_id`=12787;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9496,12785),
(9497,12787);

UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `dmg_multiplier`=4.6, `unit_flags`=32832 WHERE `entry`=@NPC_URSOC;
UPDATE `creature_template` SET `gossip_menu_id`=9496, `speed_walk`=0.666667, `speed_run`=0.992063 WHERE `entry`=@NPC_RAGEPAW;
UPDATE `creature_template` SET `speed_run`=0.357143 WHERE `entry`=@NPC_BLOOD;

UPDATE `creature_model_info` SET `bounding_radius`=3.666, `combat_reach`=9 WHERE `modelid`=23964;

DELETE FROM `creature_template_addon` WHERE `entry`=28854;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(28854,1,'52561');

UPDATE `creature` SET `spawntimesecs`=0 WHERE `guid` IN (104065,104066,114077);

DELETE FROM `creature_addon` WHERE `guid` IN (104065,104066,104068,104069,104070,104071);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(104065,'16245'),
(104066,'16245'),
(104068,'16245'),
(104069,'16245'),
(104070,'16245'),
(104071,'16245');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (48398,48399);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9496 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (52551,52554);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@NPC_RAGEPAW;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,48398,0,0,31,0,3,24921,0,0,'','Spell Tur''s Chains targets Cosmetic Trigger - LAB'),
(13,1,48398,0,0,29,0,@NPC_RAGEPAW,2,0,0,'','Spell Tur''s Chains target needs to be within 2y of Tur Ragepaw'),
(13,1,48399,0,0,31,0,3,24921,0,0,'','Spell Tur''s Chains targets Cosmetic Trigger - LAB'),
(13,1,48399,0,0,29,0,@NPC_RAGEPAW,2,0,0,'','Spell Tur''s Chains target needs to be within 2y of Tur Ragepaw'),
(15,9496,0,0,0,9,0,12236,0,0,0,'','Tur Ragepaw - Show gossip option only if player has taken quest Ursoc, the Bear God'),
(15,9496,0,0,1,9,0,12249,0,0,0,'','Tur Ragepaw - Show gossip option only if player has taken quest Ursoc, the Bear God'),
(17,0,52551,0,0,38,1,80,4,0,0,'','Spell Lifebloom will be casted only if target has less than 80% health'),
(17,0,52554,0,0,38,1,65,4,0,0,'','Spell Nourish will be casted only if target has less than 65% health'),
(22,14,@NPC_RAGEPAW,0,0,1,1,48368,1,0,0,'','SAI of Tur Ragepaw triggers only if under the effect of aura Bearform'),
(22,16,@NPC_RAGEPAW,0,0,1,1,48369,1,0,0,'','SAI of Tur Ragepaw triggers only if under the effect of aura Moonkin Form'),
(22,17,@NPC_RAGEPAW,0,0,1,1,48371,1,0,0,'','SAI of Tur Ragepaw triggers only if under the effect of aura Tree of Life');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_RAGEPAW,@NPC_SPIRIT);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_RAGEPAW,0,0, 'Stay behind me, $r.  I will do my best to protect you.',12,0,100,0,0,0, 'Tur Ragepaw'),
(@NPC_RAGEPAW,1,0, 'My freedom means nothing if we fail to save Ursoc.  Make haste, $N.',12,0,100,0,0,0, 'Tur Ragepaw'),
(@NPC_RAGEPAW,2,0, 'I will watch over you and your allies, $r.',12,0,100,0,0,0, 'Tur Ragepaw'),
(@NPC_RAGEPAW,3,0, 'Ursoc, brother of Ursol and guardian of the furbolg tribes... show yourself!',12,0,100,0,0,0, 'Tur Ragepaw'),
(@NPC_SPIRIT,0,0, 'I thank you all. The druids of old were wise to tear down Vordrassil, for its roots seep deep into the dwelling of an ancient evil.',12,0,100,0,0,0, 'Spirit of Ursoc'),
(@NPC_SPIRIT,1,0, 'You know their kind as old gods. Beware Yogg-Saron, the beast with a thousand maws. His evil extends beyond Vordrassil''s roots.',12,0,100,0,0,0, 'Spirit of Ursoc');

DELETE FROM `waypoints` WHERE `entry`=@NPC_RAGEPAW;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@NPC_RAGEPAW, 1, 4688.4, -3854.87, 327.0471, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 2, 4705.639, -3845.388, 327.5565, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 3, 4726.497, -3846.529, 330.2256, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 4, 4743.628, -3848.904, 332.7676, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 5, 4756.063, -3847.442, 333.9136, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 6, 4782.305, -3843.417, 333.9443, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 7, 4813.348, -3838.03, 336.6674, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 8, 4835.112, -3837.782, 338.4213, 'Tur Ragepaw'),
(@NPC_RAGEPAW, 9, 4865.375, -3842.427, 338.2963, 'Tur Ragepaw');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@NPC_URSOC,@NPC_BLOOD);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_URSOC,@NPC_RAGEPAW,@NPC_SPIRIT,@NPC_BLOOD);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-104065,-104066,-104068,-104069,-104070,-104071,@NPC_URSOC,@NPC_RAGEPAW,@NPC_SPIRIT,@NPC_BLOOD) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_RAGEPAW*100+0,@NPC_RAGEPAW*100+1,@NPC_RAGEPAW*100+2,@NPC_RAGEPAW*100+3,@NPC_SPIRIT*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-104068,0,0,0,38,0,100,0,0,1,0,0,11,48399,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104068,0,1,0,38,0,100,0,0,2,0,0,11,48334,0,0,0,0,0,19,@NPC_RAGEPAW,20,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104069,0,0,0,38,0,100,0,0,1,0,0,11,48398,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104069,0,1,0,38,0,100,0,0,2,0,0,11,48334,0,0,0,0,0,19,@NPC_RAGEPAW,20,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104070,0,0,0,38,0,100,0,0,1,0,0,11,48399,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104070,0,1,0,38,0,100,0,0,2,0,0,11,48334,0,0,0,0,0,19,@NPC_RAGEPAW,20,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104071,0,0,0,38,0,100,0,0,1,0,0,11,48398,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104071,0,1,0,38,0,100,0,0,2,0,0,11,48334,0,0,0,0,0,19,@NPC_RAGEPAW,20,0,0,0,0,0,'Cosmetic Trigger - LAB - On data 0 1 set - Spellcast Tur''s Chains'),
(-104065,0,0,0,8,0,100,0,48399,0,0,0,69,1,0,0,0,0,0,8,0,0,0,4672.254,-3872.959,327.6967,0,'Cosmetic Trigger - LAB - On spellhit Tur''s Chains - Move to position'),
(-104065,0,1,0,34,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On movement inform - Despawn'),
(-104066,0,0,0,8,0,100,0,48398,0,0,0,69,1,0,0,0,0,0,8,0,0,0,4677.567,-3874.965,323.9017,0,'Cosmetic Trigger - LAB - On spellhit Tur''s Chains - Move to position'),
(-104066,0,1,0,34,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cosmetic Trigger - LAB - On movement inform - Despawn'),

(@NPC_URSOC,0,0,0,54,0,100,0,0,0,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ursoc - Just summoned - Play emote'),
(@NPC_URSOC,0,1,0,0,0,100,0,7000,8000,20000,20000,11,52560,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ursoc - On update IC - Spellcast Summon Blood of the Old God'),
(@NPC_URSOC,0,2,0,0,0,100,0,10000,13000,21000,25000,11,52583,0,0,0,0,0,18,50,0,0,0,0,0,0,'Ursoc - On update IC - Spellcast Old God''s Influence'),
(@NPC_URSOC,0,3,0,9,0,100,0,0,5,9000,12000,11,52581,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ursoc - On target within 5y - Spellcast Crunch Armor'),
(@NPC_URSOC,0,4,0,8,0,100,0,48549,0,0,0,12,@NPC_SPIRIT,3,25000,0,0,0,1,0,0,0,0,0,0,0,'Ursoc - On spellhit Ashes of Vordrassil - Summon Spirit of Ursoc'),
(@NPC_URSOC,0,5,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,114077,@NPC_RAGEPAW,0,0,0,0,0,'Ursoc - On death - Set data 0 1 Tur Ragepaw'),

(@NPC_RAGEPAW,0,0,1,11,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On spawn - Set faction default'),
(@NPC_RAGEPAW,0,1,2,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,9,24921,2,20,0,0,0,0,'Tur Ragepaw - On spawn - Set data 0 2 Cosmetic Trigger - LAB'),
(@NPC_RAGEPAW,0,2,3,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On spawn - Set unit_field_bytes1 (kneel)'),
(@NPC_RAGEPAW,0,3,4,61,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On spawn - Set npcflag gossip'),
(@NPC_RAGEPAW,0,4,0,61,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On spawn - Set reaction defensive'),
(@NPC_RAGEPAW,0,5,8,62,0,100,0,9497,0,0,0,80,@NPC_RAGEPAW*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On gossip select - Run script 0'),
(@NPC_RAGEPAW,0,6,8,62,0,100,0,9497,1,0,0,80,@NPC_RAGEPAW*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On gossip select - Run script 1'),
(@NPC_RAGEPAW,0,7,8,62,0,100,0,9497,2,0,0,80,@NPC_RAGEPAW*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On gossip select - Run script 2'),
(@NPC_RAGEPAW,0,8,9,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Tur Ragepaw - On gossip select - Close gossip'),
(@NPC_RAGEPAW,0,9,10,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On gossip select - Remove npcflag gossip'),
(@NPC_RAGEPAW,0,10,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,24921,2,20,0,0,0,0,'Tur Ragepaw - On gossip select - Set data 0 1 Cosmetic Trigger - LAB'),
(@NPC_RAGEPAW,0,11,0,38,0,100,0,0,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On data 0 1 set - Despawn'),
(@NPC_RAGEPAW,0,12,0,40,0,100,0,9,@NPC_RAGEPAW,0,0,80,@NPC_RAGEPAW*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On WP 9 Reached - Run script 3'),
(@NPC_RAGEPAW,0,13,14,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On reset - Set event phase 1'),
(@NPC_RAGEPAW,0,14,0,61,0,100,0,0,0,0,0,28,52507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On reset - Remove aura Ragepaw''s Presence'),
(@NPC_RAGEPAW,0,15,0,25,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On reset - Set event phase 2'),
(@NPC_RAGEPAW,0,16,0,25,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On reset - Set event phase 3'),
(@NPC_RAGEPAW,0,17,0,4,1,100,0,0,0,0,0,11,52507,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On aggro (phase 1) - Spellcast Ragepaw''s Presence'),
(@NPC_RAGEPAW,0,18,0,9,1,100,0,0,5,2500,4000,11,52504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tur Ragepaw - On target within 5y (phase 1) - Spellcast Lacerate'),
(@NPC_RAGEPAW,0,19,0,9,1,100,0,0,5,6000,8000,11,52506,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tur Ragepaw - On target within 5y (phase 1) - Spellcast Maul'),
(@NPC_RAGEPAW,0,20,0,14,1,100,0,2000,30,20000,20000,11,6795,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tur Ragepaw - On friendly attacked (phase 1) - Spellcast Growl'),
(@NPC_RAGEPAW,0,21,0,4,2,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On aggro (phase 2) - Stop combat movement'),
(@NPC_RAGEPAW,0,22,0,9,2,100,0,0,40,2500,4000,11,52501,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tur Ragepaw - On target within 40y (phase 2) - Spellcast Wrath'),
(@NPC_RAGEPAW,0,23,0,9,2,100,0,0,40,13000,14000,11,52502,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tur Ragepaw - On target within 40y (phase 2) - Spellcast Moonfire'),
(@NPC_RAGEPAW,0,24,0,0,4,100,0,0,0,1500,1500,11,52554,0,0,0,0,0,18,40,0,0,0,0,0,0,'Tur Ragepaw - On update IC (phase 4) - Spellcast Nourish'),
(@NPC_RAGEPAW,0,25,0,0,4,100,0,50,50,1700,1700,11,52551,0,0,0,0,0,18,40,0,0,0,0,0,0,'Tur Ragepaw - On update IC (phase 4) - Spellcast Lifebloom'),
(@NPC_RAGEPAW,0,26,0,4,4,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw - On aggro (phase 4) - Set reaction aggressive'),

(@NPC_SPIRIT,0,0,0,54,0,100,0,0,0,0,0,80,@NPC_SPIRIT*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Ursoc - Just summoned - Run script'),

(@NPC_BLOOD,0,0,0,9,0,100,1,0,1.5,0,0,11,52564,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blood of the Old God - On target within 1.5y - Spellcast Corruption of the Old God'),

(@NPC_RAGEPAW*100+0,9,0,0,0,0,100,0,0,0,0,0,11,48368,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Spellcast Bearform'),
(@NPC_RAGEPAW*100+0,9,1,0,0,0,100,0,300,300,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Set faction'),
(@NPC_RAGEPAW*100+0,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Remove unit_field_bytes1 (kneel)'),
(@NPC_RAGEPAW*100+0,9,3,0,0,0,100,0,2500,2500,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Say line'),
(@NPC_RAGEPAW*100+0,9,4,0,0,0,100,0,4700,4700,0,0,53,1,@NPC_RAGEPAW,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Start WP movement'),
(@NPC_RAGEPAW*100+0,9,6,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Set reaction aggressive'),
(@NPC_RAGEPAW*100+0,9,5,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 0 - Set event phase 1'),

(@NPC_RAGEPAW*100+1,9,0,0,0,0,100,0,0,0,0,0,11,48369,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Spellcast Moonkin Form'),
(@NPC_RAGEPAW*100+1,9,1,0,0,0,100,0,300,300,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Set faction'),
(@NPC_RAGEPAW*100+1,9,2,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Remove unit_field_bytes1 (kneel)'),
(@NPC_RAGEPAW*100+1,9,3,0,0,0,100,0,0,0,0,0,11,24905,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Spellcast Moonkin Form (Passive)'),
(@NPC_RAGEPAW*100+1,9,4,0,0,0,100,0,0,0,0,0,11,24907,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Spellcast Moonkin Aura'),
(@NPC_RAGEPAW*100+1,9,5,0,0,0,100,0,400,400,0,0,11,52503,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Spellcast Empowered Moonkin Aura'),
(@NPC_RAGEPAW*100+1,9,6,0,0,0,100,0,2500,2500,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Say line'),
(@NPC_RAGEPAW*100+1,9,7,0,0,0,100,0,4700,4700,0,0,53,1,@NPC_RAGEPAW,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Start WP movement'),
(@NPC_RAGEPAW*100+1,9,8,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Set reaction aggressive'),
(@NPC_RAGEPAW*100+1,9,9,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 1 - Set event phase 2'),

(@NPC_RAGEPAW*100+2,9,0,0,0,0,100,0,0,0,0,0,11,48371,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Spellcast Tree of Life'),
(@NPC_RAGEPAW*100+2,9,1,0,0,0,100,0,100,100,0,0,11,52553,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Spellcast Empowered Tree of Life'),
(@NPC_RAGEPAW*100+2,9,2,0,0,0,100,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Set faction'),
(@NPC_RAGEPAW*100+2,9,3,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Remove unit_field_bytes1 (kneel)'),
(@NPC_RAGEPAW*100+2,9,4,0,0,0,100,0,2600,2600,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Say line'),
(@NPC_RAGEPAW*100+2,9,5,0,0,0,100,0,4700,4700,0,0,53,1,@NPC_RAGEPAW,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Start WP movement'),
(@NPC_RAGEPAW*100+2,9,6,0,0,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 2 - Set event phase 3'),

(@NPC_RAGEPAW*100+3,9,0,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 3 - Set homeposition'),
(@NPC_RAGEPAW*100+3,9,1,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tur Ragepaw script 3 - Say line'),
(@NPC_RAGEPAW*100+3,9,2,0,0,0,100,0,300,300,0,0,12,@NPC_URSOC,6,60000,0,0,0,8,0,0,0,4893.267,-3842.415,337.6485,3.124139,'Tur Ragepaw script 3 - Summon Ursoc'),

(@NPC_SPIRIT*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Ursoc script 0 - Say line'),
(@NPC_SPIRIT*100,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Spirit of Ursoc script 0 - Say line');
