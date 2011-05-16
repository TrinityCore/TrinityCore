-- fix Junkboxes Needed quest available for all classes
UPDATE `quest_template` SET `ZoneOrSort` = '0'  WHERE `entry` = '8249';

-- fix mobs aggro for keldelar quest npc
UPDATE `quest_template` SET `SrcSpell` = '70974' WHERE `entry` =20439;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31885;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31886;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31557;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32419;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32420;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32253;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32415;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32412;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32251;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32252;

UPDATE `quest_template` SET `SrcSpell` = '70972' WHERE `entry` =24451;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35507;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31580;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31579;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35494;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 37942;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 33964;  

-- fix 12856 (Cold Hearted)
-- captive proto-drake
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=29708;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`)
VALUES (29708,55028,12856,1,12856,1,0,0,0);

-- freed proto-drake
DELETE FROM `creature_template_addon` WHERE `entry`=29709;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29709,0,50331648,257,0, NULL);

UPDATE `creature_template` SET `unit_flags`=`unit_flags`|16777216, `ScriptName`='' WHERE `entry`=29708;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=29709;

-- hack quest "An End To All Things..."
UPDATE `quest_template` SET Method = 0 WHERE `entry` = 12779;

-- fix The Black Knight's Orders quest
UPDATE `creature_template` SET `VehicleId` = 369, `InhabitType` = 7 WHERE `entry` = 33519;

SET @ENTRY :=33519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,53,0,@ENTRY,0,13663,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On Passenger - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,40,@ENTRY,0,0,33,33519,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Quest Credit'),
(@ENTRY,0,2,0,40,0,100,0,43,@ENTRY,0,0,11,50630,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Dismount Spell'),
(@ENTRY,0,3,0,40,0,100,0,44,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Despawn');

DELETE FROM `waypoints` WHERE `entry`=33519;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(33519,1,8521.271,569.596,552.8375,'Black Knight''s Gryphon'),
(33519,2,8517.864,579.1095,553.2125,'Black Knight''s Gryphon'),
(33519,3,8513.146,594.6724,551.2125,'Black Knight''s Gryphon'),
(33519,4,8505.263,606.5569,550.4177,'Black Knight''s Gryphon'),
(33519,5,8503.017,628.4188,547.4177,'Black Knight''s Gryphon'),
(33519,6,8480.271,652.7083,547.4177,'Black Knight''s Gryphon'),
(33519,7,8459.121,686.1427,547.4177,'Black Knight''s Gryphon'),
(33519,8,8436.802,713.8687,547.3428,'Black Knight''s Gryphon'),
(33519,9,8405.380,740.0045,547.4177,'Black Knight''s Gryphon'),
(33519,10,8386.139,770.6009,547.5881,'Black Knight''s Gryphon'),
(33519,11,8374.297,802.2525,547.9304,'Black Knight''s Gryphon'),
(33519,12,8374.271,847.0363,548.0427,'Black Knight''s Gryphon'),
(33519,13,8385.988,868.9881,548.0491,'Black Knight''s Gryphon'),
(33519,14,8413.027,867.8573,547.2991,'Black Knight''s Gryphon'),
(33519,15,8452.552,869.0339,547.2991,'Black Knight''s Gryphon'),
(33519,16,8473.058,875.2012,547.2955,'Black Knight''s Gryphon'),
(33519,17,8472.278,912.3134,547.4169,'Black Knight''s Gryphon'),
(33519,18,8479.666,954.1650,547.3298,'Black Knight''s Gryphon'),
(33519,19,8477.349,1001.368,547.3372,'Black Knight''s Gryphon'),
(33519,20,8484.538,1025.797,547.4622,'Black Knight''s Gryphon'),
(33519,21,8525.363,1029.284,547.4177,'Black Knight''s Gryphon'),
(33519,22,8532.808,1052.904,548.1677,'Black Knight''s Gryphon'),
(33519,23,8537.356,1077.927,554.5791,'Black Knight''s Gryphon'),
(33519,24,8540.528,1083.379,569.6827,'Black Knight''s Gryphon'),
(33519,25,8563.641,1140.965,569.6827,'Black Knight''s Gryphon'),
(33519,26,8594.897,1205.458,569.6827,'Black Knight''s Gryphon'),
(33519,27,8617.104,1257.399,566.1833,'Black Knight''s Gryphon'),
(33519,28,8648.496,1329.349,558.0187,'Black Knight''s Gryphon'),
(33519,29,8667.723,1388.411,546.188,'Black Knight''s Gryphon'),
(33519,30,8699.145,1474.898,528.2197,'Black Knight''s Gryphon'),
(33519,31,8726.869,1546.006,501.7741,'Black Knight''s Gryphon'),
(33519,32,8739.058,1592.157,478.5511,'Black Knight''s Gryphon'),
(33519,33,8750.799,1636.771,455.0797,'Black Knight''s Gryphon'),
(33519,34,8760.006,1669.482,423.2208,'Black Knight''s Gryphon'),
(33519,35,8783.31,1701.852,375.8872,'Black Knight''s Gryphon'),
(33519,36,8817.336,1735.731,343.3323,'Black Knight''s Gryphon'),
(33519,37,8882.32,1789.754,301.5807,'Black Knight''s Gryphon'),
(33519,38,8958.597,1841.807,259.9141,'Black Knight''s Gryphon'),
(33519,39,9045.891 ,1908.076,233.4143,'Black Knight''s Gryphon'),
(33519,40,9107.177,1964.594,215.9704,'Black Knight''s Gryphon'),
(33519,41,9134.763,2036.925,175.1925,'Black Knight''s Gryphon'),
(33519,42,9128.608,2089.091,141.3593,'Black Knight''s Gryphon'),
(33519,43,9093.364,2128.384,99.38685,'Black Knight''s Gryphon'),
(33519,44,9050.709,2123.656,60.24802,'Black Knight''s Gryphon');

-- fix phase fox NPC 37158
UPDATE `creature` SET `phaseMask` = '99' WHERE `id` = 37158;