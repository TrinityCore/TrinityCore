-- Quest Chain: http://www.wowhead.com/quest=13213/battle-at-valhalas#see-also
-- Battle at Valhalas: Fallen Heroes
-- Battle at Valhalas: Khit'rix the Dark Master
-- Battle at Valhalas: The Return of Sigrid Iceborn
-- Battle at Valhalas: Carnage!
-- Battle at Valhalas: Thane Deathblow
-- Battle at Valhalas: Final Challenge
SET @NPC_GEIRRVIF           := 31135;
SET @QUEST_FALLENHEROES     := 13214;
SET @NPC_ELDRETH_13214      := 31195;
SET @NPC_GENESS_13214       := 31193;
SET @NPC_JHADRAS_13214      := 31191;
SET @NPC_MASUD_13214        := 31192;
SET @NPC_RITH_13214         := 31196;
SET @NPC_TALLA_13214        := 31194;
SET @QUEST_KDARKMASTER      := 13215;
SET @NPC_KHITRIX_13215      := 31222;
SET @NPC_BONESPIDER_13215   := 32484;
SET @QUEST_SIGRIDICEBORN    := 13216;
SET @NPC_SIGRID_13216       := 31242;
SET @NPC_SIGRID_MOUNT       := 30159;
SET @QUEST_CARNAGE          := 13217;
SET @NPC_CARNAGE_13217      := 31271;
SET @QUEST_THANE            := 13218;
SET @NPC_THANE_13218        := 31277;
SET @QUEST_FINCHAL          := 13219;
SET @NPC_PRINCESAND_13219   := 14688;
SET @NPC_GENERIC_BUNNY      := 24110;
SET @CHEER_SOUND            := 14998;
SET @KILL_13214             := 20;
SET @WIPE_13214             := 19;
SET @CREDIT_13214           := 1;
SET @CREDIT_13215           := 2;
SET @CREDIT_13216           := 3;
SET @CREDIT_13217           := 4;
SET @CREDIT_13218           := 5;
SET @CREDIT_13219           := 6;
SET @DESPAWN_13219          := 7;
-- Quest Progression
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 31135;
UPDATE `quest_template` SET `PrevQuestId`=13213 WHERE `Id`=13214;
UPDATE `quest_template` SET `PrevQuestId`=13214 WHERE `Id`=13215;
UPDATE `quest_template` SET `PrevQuestId`=13215 WHERE `Id`=13216;
UPDATE `quest_template` SET `PrevQuestId`=13216 WHERE `Id`=13217;
UPDATE `quest_template` SET `PrevQuestId`=13217 WHERE `Id`=13218;
UPDATE `quest_template` SET `PrevQuestId`=13218 WHERE `Id`=13219;
-- Proper template data
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `mindmg`=311, `maxdmg`=474, `attackpower`=478, `minrangedmg`=344, `maxrangedmg`=490, `rangedattackpower`=80 WHERE `entry`=31242;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `mindmg`=417, `maxdmg`=582, `attackpower`=608, `minrangedmg`=341, `maxrangedmg`=506, `rangedattackpower`=80  WHERE  `entry`=31271;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `mindmg`=445, `maxdmg`=621, `attackpower`=642, `minrangedmg`=289, `maxrangedmg`=381, `rangedattackpower`=69 WHERE  `entry`=31277;
UPDATE `creature_template` SET `mindmg`=217, `maxdmg`=389, `attackpower`=357, `minrangedmg`=211, `maxrangedmg`=378, `rangedattackpower`=80 WHERE  `entry`=31192;
UPDATE `creature_template` SET `mindmg`=299, `maxdmg`=411, `attackpower`=394, `minrangedmg`=373, `maxrangedmg`=541, `rangedattackpower`=69 WHERE  `entry`=31193;
UPDATE `creature_template` SET `mindmg`=254, `maxdmg`=371, `attackpower`=294, `minrangedmg`=344, `maxrangedmg`=490, `rangedattackpower`=80 WHERE  `entry`=31194;
UPDATE `creature_template` SET `mindmg`=417, `maxdmg`=682, `attackpower`=608, `minrangedmg`=341, `maxrangedmg`=506, `rangedattackpower`=80 WHERE  `entry`=31196;
 -- Template updates for creature 31191 (Father Jhadras)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|32768 WHERE `entry`=31191; -- Father Jhadras
-- Equipment of 31191 (Father Jhadras)
DELETE FROM `creature_equip_template` WHERE `entry`=31191;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31191,1,13220,0,0);
-- Model data 27584 (creature 31191 (Father Jhadras))
UPDATE `creature_model_info` SET `bounding_radius`=0.173611,`combat_reach`=0.75,`gender`=0 WHERE `modelid`=27584; -- Father Jhadras
-- Addon data for creature 31191 (Father Jhadras)
DELETE FROM `creature_template_addon` WHERE `entry`=31191;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31191,0,0,1,0, NULL); -- Father Jhadras
-- Template updates for creature 31193 (Geness Half-Soul)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|32768 WHERE `entry`=31193; -- Geness Half-Soul
-- Model data 27580 (creature 31193 (Geness Half-Soul))
UPDATE `creature_model_info` SET `bounding_radius`=0.1909721,`combat_reach`=0.825,`gender`=0 WHERE `modelid`=27580; -- Geness Half-Soul
-- Addon data for creature 31193 (Geness Half-Soul)
DELETE FROM `creature_template_addon` WHERE `entry`=31193;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31193,0,0,1,0, NULL); -- Geness Half-Soul
-- Template updates for creature 31192 (Masud)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|32768 WHERE `entry`=31192; -- Masud
-- Equipment of 31192 (Masud)
DELETE FROM `creature_equip_template` WHERE `entry`=31192;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31192,1,30388,0,0);
-- Model data 27582 (creature 31192 (Masud))
UPDATE `creature_model_info` SET `bounding_radius`=0.2951387,`combat_reach`=1.275,`gender`=0 WHERE `modelid`=27582; -- Masud
-- Addon data for creature 31192 (Masud)
DELETE FROM `creature_template_addon` WHERE `entry`=31192;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31192,0,0,1,0, NULL); -- Masud
-- Template updates for creature 31196 (Rith)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|32768 WHERE `entry`=31196; -- Rith
-- Equipment of 31196 (Rith)
DELETE FROM `creature_equip_template` WHERE `entry`=31196;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31196,1,29631,0,0);
-- Model data 27583 (creature 31196 (Rith))
UPDATE `creature_model_info` SET `bounding_radius`=0.2083332,`combat_reach`=0.9,`gender`=0 WHERE `modelid`=27583; -- Rith
-- Addon data for creature 31196 (Rith)
DELETE FROM `creature_template_addon` WHERE `entry`=31196;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31196,0,0,1,0, NULL); -- Rith
-- Template updates for creature 31194 (Talla)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|32768,`unit_class`=4 WHERE `entry`=31194; -- Talla
-- Equipment of 31194 (Talla)
DELETE FROM `creature_equip_template` WHERE `entry`=31194;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31194,1,34283,0,0);
-- Model data 27906 (creature 31194 (Talla))
UPDATE `creature_model_info` SET `bounding_radius`=0.1562499,`combat_reach`=0.675,`gender`=0 WHERE `modelid`=27906; -- Talla
-- Addon data for creature 31194 (Talla)
DELETE FROM `creature_template_addon` WHERE `entry`=31194;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31194,0,0,1,0, NULL); -- Talla
-- Template updates for creature 31222 (Khit'rix the Dark Master)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|33600 WHERE `entry`=31222;
-- Khit'rix the Dark Master
-- Model data 25269 (creature 31222 (Khit'rix the Dark Master))
UPDATE `creature_model_info` SET `bounding_radius`=1.24,`combat_reach`=4,`gender`=0 WHERE `modelid`=25269; -- Khit'rix the Dark Master
-- Addon data for creature 31222 (Khit'rix the Dark Master)
DELETE FROM `creature_template_addon` WHERE `entry`=31222;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31222,0,0,1,0, NULL); -- Khit'rix the Dark Master
-- Template updates for creature 31242 (Sigrid Iceborn)
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|33600 WHERE `entry`=31242; -- Sigrid Iceborn
-- Equipment of 31242 (Sigrid Iceborn)
DELETE FROM `creature_equip_template` WHERE `entry`=31242;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31242,1,40436,0,0);
-- Model data 27528 (creature 31242 (Sigrid Iceborn))
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=27528;
-- Sigrid Iceborn
-- Addon data for creature 31242 (Sigrid Iceborn)
DELETE FROM `creature_template_addon` WHERE `entry`=31242;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31242,0,0,1,0, ''); 
-- Sigrid Iceborn
UPDATE `creature_template` SET `speed_run`=3.14286 WHERE  `entry`=30159; 
-- Sigrid Iceborn's Proto Drake
DELETE FROM `creature_template_addon` WHERE `entry`=30159;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30159,0,33554432,1,0, ''); -- Addon data for creature 30159 (Sigrid Iceborn's Proto Drake)
-- Template updates for creature 31271 (Carnage)
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|33600 WHERE `entry`=31271; -- Carnage
-- Model data 24301 (creature 31271 (Carnage))
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=9,`gender`=0 WHERE `modelid`=24301; -- Carnage
-- Addon data for creature 31271 (Carnage)
DELETE FROM `creature_template_addon` WHERE `entry`=31271;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31271,0,0,1,0, NULL); -- Carnage
-- Template updates for creature 31277 (Thane Banahogg)
UPDATE `creature_template` SET `faction_A`=2116,`faction_H`=2116,`exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|33600,`speed_walk`=1.6,`speed_run`=1.71429 WHERE `entry`=31277; -- Thane Banahogg
-- Equipment of 31277 (Thane Banahogg)
DELETE FROM `creature_equip_template` WHERE `entry`=31277;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(31277,1,43578,0,0);
-- Model data 27551 (creature 31277 (Thane Banahogg))
UPDATE `creature_model_info` SET `bounding_radius`=0.6076385,`combat_reach`=2.625,`gender`=0 WHERE `modelid`=27551; -- Thane Banahogg
-- Addon data for creature 31277 (Thane Banahogg)
DELETE FROM `creature_template_addon` WHERE `entry`=31277;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(31277,0,0,1,0, NULL); -- Thane Banahogg
-- Template updates for creature 14688 (Prince Sandoval)
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21,`unit_flags`=`unit_flags`|33600,`speed_walk`=2,`speed_run`=2.14286 WHERE `entry`=14688; -- Prince Sandoval
-- Equipment of 14688 (Prince Sandoval)
DELETE FROM `creature_equip_template` WHERE `entry`=14688;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES 
(14688,1,31311,0,0);
-- Model data 27555 (creature 14688 (Prince Sandoval))
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=2,`gender`=0 WHERE `modelid`=27555; -- Prince Sandoval
-- Addon data for creature 14688 (Prince Sandoval)
DELETE FROM `creature_template_addon` WHERE `entry`=14688;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(14688,0,0,0,0, NULL); -- Prince Sandoval

UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `AIName`='SmartAI' WHERE `entry` IN (@NPC_ELDRETH_13214, @NPC_GENESS_13214, @NPC_JHADRAS_13214, @NPC_MASUD_13214, @NPC_TALLA_13214, @NPC_RITH_13214);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_ELDRETH_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_ELDRETH_13214, 0, 0, 0, 0, 0, 80, 0, 0, 0, 6000, 12000, 11, 34829, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eldreth - IC - Cast Arcane Shot'),
(@NPC_ELDRETH_13214, 0, 1, 0, 0, 0, 80, 0, 10000, 20000, 10000, 20000, 11, 44475, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eldreth - IC - Cast Magic Dampening Field'),
(@NPC_ELDRETH_13214, 0, 2, 0, 9, 0, 80, 0, 5, 30, 3000, 6000, 11, 15620, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Eldreth - On  range - Cast Shoot'),
(@NPC_ELDRETH_13214, 0, 3, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Eldreth - On  death - Set Data'),
(@NPC_ELDRETH_13214, 0, 4, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eldreth - On  reach home - Despawn self'),
(@NPC_ELDRETH_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Eldreth - On  reach home - Set Data'),
(@NPC_ELDRETH_13214, 0, 6, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0,0, 0, 0, 'Eldreth - On  kill target - Set Data');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_GENESS_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_GENESS_13214, 0, 0, 0, 0, 0, 80, 0, 2000, 6000, 3000, 7000, 11, 61041, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Geness Half-Soul - IC - Cast Brutal Fist'),
(@NPC_GENESS_13214, 0, 1, 0, 13, 0, 80, 0, 10000, 15000, 0, 0, 11, 46182, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Geness Half-Soul - On  target Cast - Cast Snap Kick'),
(@NPC_GENESS_13214, 0, 2, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Geness Half-Soul - On  death - Set Data'),
(@NPC_GENESS_13214, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Geness Half-Soul - On  reach home - Despawn self'),
(@NPC_GENESS_13214, 0, 4, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Geness Half-Soul - On  kill target - Set Data'),
(@NPC_GENESS_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Geness Half-Soul - On  reach home - Set Data');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_JHADRAS_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_JHADRAS_13214, 0, 0, 0, 14, 0, 80, 0, 50, 40, 10000, 30000, 11, 15586, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Father Jhadras - On  friendly hp deficit - Cast Heal'),
(@NPC_JHADRAS_13214, 0, 1, 0, 0, 0, 80, 0, 0, 3000, 8000, 12000, 11, 25054, 0, 0, 0, 0, 0, 5, 0, 0, 40, 0, 0, 0, 0, 'Father Jhadras - IC - Cast Holy Smite'),
(@NPC_JHADRAS_13214, 0, 2, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Father Jhadras - On   death - Set Data'),
(@NPC_JHADRAS_13214, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Father Jhadras - On  reach home - Despawn self'),
(@NPC_JHADRAS_13214, 0, 4, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Father Jhadras - On  kill target - Set Data'),
(@NPC_JHADRAS_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0,0, 'Father Jhadras - On  reach home - Set Data');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_MASUD_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_MASUD_13214, 0, 0, 0, 0, 0, 80, 0, 0, 0, 15000, 25000, 11, 41056, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Masud - IC - Cast Whirlwind'),
(@NPC_MASUD_13214, 0, 1, 0, 0, 0, 80, 0, 0, 0, 10000, 20000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Masud - IC - Cast Cleave'),
(@NPC_MASUD_13214, 0, 2, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Masud - On  death - Set Data'),
(@NPC_MASUD_13214, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Masud - On  reach home - Despawn self'),
(@NPC_MASUD_13214, 0, 4, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Masud - On  kill target - Set Data'),
(@NPC_MASUD_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0,0, 'Masud - On  reach home - Set Data');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_RITH_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_RITH_13214, 0, 0, 0, 0, 0, 80, 0, 0, 0, 10000, 20000, 11, 61044, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rith - IC - Cast Demoralizing Shout'),
(@NPC_RITH_13214, 0, 1, 0, 0, 0, 80, 0, 0, 0, 20000, 30000, 11, 58461, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rith - IC - Cast Sunder Armor'),
(@NPC_RITH_13214, 0, 2, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Rith - On  death - Set Data'),
(@NPC_RITH_13214, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rith - On  reach home - Despawn self'),
(@NPC_RITH_13214, 0, 4, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Rith - On  kill target - Set Data'),
(@NPC_RITH_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0,0, 'Rith - On  reach home - Set Data');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_TALLA_13214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_TALLA_13214, 0, 0, 0, 0, 0, 80, 0, 0, 0, 5000, 15000, 11, 14873, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talla - IC - Cast Sinister Strike '),
(@NPC_TALLA_13214, 0, 1, 0, 0, 0, 80, 0, 0, 0, 20000, 25000, 11, 30981, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Talla - IC - Cast Crippling PoisOn  '),
(@NPC_TALLA_13214, 0, 2, 0, 6, 0, 100, 1, 0, 0, 0, 0, 45, 6, 6, 0, 0, 0, 0, 11, @NPC_GENERIC_BUNNY, 100, 0, 0, 0, 0, 0, 'Talla - On  death - Set Data'),
(@NPC_TALLA_13214, 0, 3, 0, 21, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Talla - On  reach home - Despawn self'),
(@NPC_TALLA_13214, 0, 4, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Talla - On  kill target - Set Data'),
(@NPC_TALLA_13214, 0, 5, 0, 21, 0, 100, 0, 0, 0, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0,0, 'Talla - On  reach home - Set Data');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC_GENERIC_BUNNY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_GENERIC_BUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_GENERIC_BUNNY, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 1(1)'),
(@NPC_GENERIC_BUNNY, 0, 1, 0, 38, 0, 100, 1, 2, 2, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 2(2)'),
(@NPC_GENERIC_BUNNY, 0, 2, 0, 38, 0, 100, 1, 3, 3, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 3(4)'),
(@NPC_GENERIC_BUNNY, 0, 3, 0, 38, 0, 100, 1, 4, 4, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 4(8)'),
(@NPC_GENERIC_BUNNY, 0, 4, 0, 38, 0, 100, 1, 5, 5, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 5(16)'),
(@NPC_GENERIC_BUNNY, 0, 5, 0, 38, 0, 100, 1, 6, 6, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  data set - increment phase 6(32)'),
(@NPC_GENERIC_BUNNY, 0, 6, 7, 1, 32, 100, 1, 0, 0, 0, 0, 45, @CREDIT_13214, @CREDIT_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Kill trigger - On  phase 6(32) - Set Data'),
(@NPC_GENERIC_BUNNY, 0, 7, 0, 61, 32, 100, 0, 0, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kill trigger - On  phase 6(32) - Set Phase 0');

UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `AIName`='SmartAI', `unit_flags`=0 WHERE `entry`=@NPC_KHITRIX_13215;
DELETE FROM `creature_text` WHERE `entry`=@NPC_KHITRIX_13215;
INSERT INTO `creature_text` VALUES
(@NPC_KHITRIX_13215,0,0,'When I am done here, I am going to mount your heads upon the walls of Azjol-Nerub!',14,0,0,0,0,0,'Dark Master say 1');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_KHITRIX_13215, @NPC_KHITRIX_13215*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_KHITRIX_13215, 0, 0, 0, 0, 0, 80, 0, 0, 0, 10000, 20000, 11, 38243, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - IC - Cast Mind Flay'),
(@NPC_KHITRIX_13215, 0, 1, 0, 0, 0, 80, 0, 5000, 25000, 5000, 25000, 11, 22884, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - IC - Cast Psychic Scream'),
(@NPC_KHITRIX_13215, 0, 2, 0, 0, 0, 80, 0, 10000, 15000, 120000, 180000, 11, 61055, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - IC - Cast Bone Spiders'),
(@NPC_KHITRIX_13215, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_KHITRIX_13215*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - On  summon - Call script 1'),
--
(@NPC_KHITRIX_13215*100, 9, 0, 0, 1, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8197.6045, 3502.557, 625.108032, 0.585, 'Khitrix the Dark Master - OOC script 1 - Move to position'),
(@NPC_KHITRIX_13215*100, 9, 1, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 0, 10, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - OOC script 1 - Say 1'),
--
(@NPC_KHITRIX_13215, 0, 5, 0, 1, 0, 100, 0, 500, 500, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - OOC - Start Attack'),
(@NPC_KHITRIX_13215, 0, 6, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - On Kill target - Set Data'),
(@NPC_KHITRIX_13215, 0, 7, 0, 6, 0, 100, 0, 0, 0, 1, 0, 45, @CREDIT_13215, @CREDIT_13215, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - On Death - Set Data'),
(@NPC_KHITRIX_13215, 0, 8, 0, 1, 0, 100, 1, 30000, 30000, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Khitrix the Dark Master - OOC - Set Data');

UPDATE `creature_template` SET `exp`=0, `mindmg`=200, `maxdmg`=300, `dmg_multiplier`=2, `AIName`='SmartAI',`Health_mod`=1 WHERE `entry`=@NPC_BONESPIDER_13215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_BONESPIDER_13215 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_BONESPIDER_13215, 0, 0, 0, 0, 0, 80, 0, 0, 0, 10000, 20000, 11, 744, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Bone spiders - IC - Cast Poison'),
(@NPC_BONESPIDER_13215, 0, 1, 0, 1, 0, 100, 0, 500, 500, 0, 0, 49, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Bone Spiders - OOC - Start Attack Random Player');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_SIGRID_13216);
INSERT INTO `creature_text` VALUES
(@NPC_SIGRID_13216,0,0,'Ah, there you are! Remember me? Of course you do! Wait right there, I''m coming down.',14,0,0,0,0,0,'Sigrid Iceborn say 1'),
(@NPC_SIGRID_13216,1,0,'I told you I''d be better prepared when next we met. I''ve fought and won the Hyldsmeet, trained at Valkyrion, and here I am.  Come and get some!',14,0,0,0,0,0,'Sigrid Iceborn say 2');

-- Sigrid Flight WP's
DELETE FROM `waypoints` WHERE entry =@NPC_SIGRID_MOUNT;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@NPC_SIGRID_MOUNT, 1, 8258.836, 3599.048, 677.6457, ''),
(@NPC_SIGRID_MOUNT, 2, 8258.059, 3598.419, 677.6457, ''),
(@NPC_SIGRID_MOUNT, 3, 8217.432, 3554.571, 677.6457, ''),
(@NPC_SIGRID_MOUNT, 4, 8169.096, 3473.421, 677.6457, ''),
(@NPC_SIGRID_MOUNT, 5, 8200.269, 3417.768, 673.563, ''),
(@NPC_SIGRID_MOUNT, 6, 8281.517, 3453.952, 673.535, ''),
(@NPC_SIGRID_MOUNT, 7, 8278.022, 3504.947, 677.6457, ''),
(@NPC_SIGRID_MOUNT, 8, 8222.471, 3532.925, 631.09, ''),
(@NPC_SIGRID_MOUNT, 9, 8222.471, 3532.925, 631.09, '');

UPDATE `creature_template` SET `InhabitType` =1 WHERE `entry` =@NPC_SIGRID_13216;
UPDATE `creature_template` SET `InhabitType` =7 WHERE `entry` =@NPC_SIGRID_MOUNT;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`IN (@NPC_SIGRID_13216,@NPC_SIGRID_MOUNT);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_SIGRID_13216, @NPC_SIGRID_13216*100,@NPC_SIGRID_MOUNT);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_SIGRID_13216, 0, 0, 0, 9, 0, 80, 0, 0, 2, 15000, 30000, 11, 57635, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  range - Cast Disengage'),
(@NPC_SIGRID_13216, 0, 1, 2, 9, 0, 80, 0, 0, 3, 10000, 30000, 11, 61170, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - IC - Cast Flash Freeze'),
(@NPC_SIGRID_13216, 0, 2, 0, 61, 0, 80, 0, 0, 0, 0, 0, 89, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On Link - Set Random Movement'),
(@NPC_SIGRID_13216, 0, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 11, 61165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - IC - Cast Frostbite Weapon'),
(@NPC_SIGRID_13216, 0, 4, 0, 9, 0, 80, 0, 5, 30, 5000, 25000, 11, 61168, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  range - Cast Throw'),
(@NPC_SIGRID_13216, 0, 5, 0, 9, 0, 100, 0, 30, 100, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - Start Moving - Not in Throw Range'),
(@NPC_SIGRID_13216, 0, 6, 0, 9, 0, 100, 0, 9, 15, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - In Range - Stop Moving at 15 Yard'),
(@NPC_SIGRID_13216, 0, 7, 0, 9, 0, 100, 0, 0, 5, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - Start Moving - Not in Throw Range'),
(@NPC_SIGRID_13216, 0, 8, 0, 9, 0, 100, 0, 5, 30, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - Stop Moving - In Throw Range'),
(@NPC_SIGRID_13216, 0, 9, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_SIGRID_13216*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  summon  - Call script 1'),
--
(@NPC_SIGRID_13216*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  summon  script 1 - Say 1'),
--
(@NPC_SIGRID_13216, 0, 10, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  kill target - Set Data'),
(@NPC_SIGRID_13216, 0, 11, 0, 6, 0, 100, 0, 0, 0, 1, 0, 45, @CREDIT_13216, @CREDIT_13216, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On  death - Set Data'),
(@NPC_SIGRID_13216, 0, 12, 0, 1, 0, 100, 1, 30000, 30000, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Sigrid Iceborn - OOC - Set Data'),
--
(@NPC_SIGRID_MOUNT, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 53, 1, @NPC_SIGRID_MOUNT, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn Mount - On Respawn - Start WP movement'),
(@NPC_SIGRID_MOUNT, 0, 1, 2, 40, 0, 100, 1, 9, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn Mount - On WP reached - Despawn'),
(@NPC_SIGRID_MOUNT, 0, 2, 0, 61, 0, 100, 1, 9, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, @NPC_SIGRID_13216, 20, 0, 0, 0, 0, 0, 'Sigrid Iceborn Mount - On WP reached - Set Data on Sigrid'),
--
(@NPC_SIGRID_13216, 0, 13, 14, 54, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_SIGRID_MOUNT, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On Link - Summon Mount'),
(@NPC_SIGRID_13216, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 7, 0, 0, 0, 0, 11, @NPC_SIGRID_MOUNT, 100, 0, 0, 0, 0, 0, 'Sigrid Iceborn  - On Link - Mount Sigrid''s Proto Drake'),
(@NPC_SIGRID_13216, 0, 15, 16, 38, 0, 100, 1, 1, 1, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On WP reached - Start Attack'),
(@NPC_SIGRID_13216, 0, 16, 17, 61, 0, 100, 1, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On WP reached - Start Attack'),
(@NPC_SIGRID_13216, 0, 17, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sigrid Iceborn - On Link - Say 2');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC_CARNAGE_13217;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_CARNAGE_13217, @NPC_CARNAGE_13217*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_CARNAGE_13217, 0, 1, 0, 0, 0, 80, 0, 10000, 30000, 20000, 40000, 11, 61065, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Carnage - IC - Cast War Stomp'),
(@NPC_CARNAGE_13217, 0, 2, 0, 0, 0, 80, 0, 5000, 12000, 5000, 12000, 11, 61070, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Carnage - IC - Cast Smash'),
(@NPC_CARNAGE_13217, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_CARNAGE_13217*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Carnage - On  summon - Call script 1'),
--
(@NPC_CARNAGE_13217*100, 9, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8193.264648, 3496.165771, 625.067322, 0.746269, 'Carnage - OOC script 1 - Move to position'),
--
(@NPC_CARNAGE_13217, 0, 4, 0, 1, 0, 100, 0, 5000, 5000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 70, 0, 0, 0, 0, 0, 0, 'Carnage - OOC - Start Attack'),
(@NPC_CARNAGE_13217, 0, 5, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Carnage - On  kill target - Set Data'),
(@NPC_CARNAGE_13217, 0, 6, 0, 6, 0, 100, 0, 0, 0, 1, 0, 45, @CREDIT_13217, @CREDIT_13217, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Carnage - On  death - Set Data'),
(@NPC_CARNAGE_13217, 0, 7, 0, 1, 0, 100, 1,  30000, 30000, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Carnage - OOC - Set Data');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_THANE_13218);
INSERT INTO `creature_text` VALUES
(@NPC_THANE_13218,0,0,'ENOUGH! You tiny insects are not worthy to do battle within this sacred place!.',14,0,0,0,0,0,'Thane say 1'),
(@NPC_THANE_13218,1,0,'Fight me and die you cowards!',14,0,0,0,0,0,'Thane say 2'),
(@NPC_THANE_13218,2,0,'Haraak foln! ',12,0,0,0,0,0,'Thane say 3');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC_THANE_13218;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_THANE_13218, @NPC_THANE_13218*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_THANE_13218, 0, 1, 0, 0, 0, 80, 0, 5000, 10000, 15000, 20000, 11, 13737, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - IC - Cast Mortal Strike'),
(@NPC_THANE_13218, 0, 2, 0, 0, 0, 80, 0, 5000, 10000, 5000, 10000, 11, 61133, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - IC - Cast Punt'),
(@NPC_THANE_13218, 0, 3, 0, 0, 0, 100, 0, 20000, 20000, 20000, 30000, 11, 61134, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - IC - Cast Leap'),
(@NPC_THANE_13218, 0, 5, 0, 12, 0, 100, 0, 0, 20, 5000, 10000, 11, 61140, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - On  %hp - Cast Execute'),
(@NPC_THANE_13218, 0, 6, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_THANE_13218*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - On  summon - call script 1'),
--
(@NPC_THANE_13218*100, 9, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC script 1 - say 1'),
(@NPC_THANE_13218*100, 9, 1, 0, 0, 0, 100, 1, 5000, 5000, 0, 0, 97, 25, 30, 0, 0, 0, 0, 1, 0, 0, 0, 8169.0015, 3477.075, 626.4695, 0.673769, 'Thane Banahogg - OOC script 1 - Jump to position'),
(@NPC_THANE_13218*100, 9, 2, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC script 1 - Set Home Pos'),
(@NPC_THANE_13218*100, 9, 3, 0, 0, 0, 100, 1, 1500, 1500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC script 1 - Say 2'),
(@NPC_THANE_13218*100, 9, 4, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC script 1 - Say 3'),
--
(@NPC_THANE_13218, 0, 8, 0, 1, 0, 100, 0, 12000, 12000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC - Start Attack'),
(@NPC_THANE_13218, 0, 9, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Thane Banahogg - On  kill target - Set Data'),
(@NPC_THANE_13218, 0, 10, 0, 6, 0, 100, 0, 0, 0, 1, 0, 45, @CREDIT_13218, @CREDIT_13218, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Thane Banahogg - On  death - Set Data'),
(@NPC_THANE_13218, 0, 11, 0, 1, 0, 100, 1, 30000, 30000, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Thane Banahogg - OOC - Set Data');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_PRINCESAND_13219);
INSERT INTO `creature_text` VALUES
(@NPC_PRINCESAND_13219,0,0,'Hardly a fitting introduction , Spear-Wife. Now, who is this outsider that I''ve been hearing so much about?',14,0,0,0,0,0,'Prince Sandoval say 1'),
(@NPC_PRINCESAND_13219,1,0,'I will make this as easy as possible for you. Simply come here and die. That is all that I ask for your many trespasses. For your sullying this exlated place of battle. ',14,0,0,0,0,0,'Prince Sandoval say 2'),
(@NPC_PRINCESAND_13219,2,0,'FOR YOUR EFFRONTERY TO THE LICH KING!',14,0,0,0,0,0,'Prince Sandoval say 3');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@NPC_PRINCESAND_13219;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_PRINCESAND_13219, @NPC_PRINCESAND_13219*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_PRINCESAND_13219, 0, 0, 0, 0, 0, 80, 0, 0, 0, 10000, 20000, 11, 61162, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - IC - Cast Engulfing Strike'),
(@NPC_PRINCESAND_13219, 0, 1, 0, 0, 0, 80, 0, 15000, 20000, 30000, 30000, 11, 61163, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - IC - Cast Fire Nova'),
(@NPC_PRINCESAND_13219, 0, 2, 0, 0, 0, 100, 0, 30000, 30000, 30000, 30000, 11, 61144, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - IC - Cast Fire Shield'),
(@NPC_PRINCESAND_13219, 0, 3, 4, 0, 0, 100, 0, 31100, 31100, 30000, 30000, 11, 61145, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - IC - Cast Ember Shower'),
(@NPC_PRINCESAND_13219, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Change state'),
(@NPC_PRINCESAND_13219, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 18, 131077, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Change unit flag'),
(@NPC_PRINCESAND_13219, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 103, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Set Root'),
(@NPC_PRINCESAND_13219, 0, 7, 8, 0, 0, 100, 0, 45100, 45100, 30000, 30000, 19, 131077, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - IC - Change unit flag'),
(@NPC_PRINCESAND_13219, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Change state'),
(@NPC_PRINCESAND_13219, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 28, 61144, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Remove Fire Shield'),
(@NPC_PRINCESAND_13219, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 28, 61145, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link- Remove Ember Shower'),
(@NPC_PRINCESAND_13219, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Remove Root'),
(@NPC_PRINCESAND_13219, 0, 12, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @NPC_PRINCESAND_13219*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On  summon - Call script 1'),
(@NPC_PRINCESAND_13219, 0, 13, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 4335, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On  summon - Cast Summon Smoke'),
--
(@NPC_PRINCESAND_13219*100, 9, 0, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 1, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC script 1 - Say 1'),
(@NPC_PRINCESAND_13219*100, 9, 1, 0, 1, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8197.6045, 3502.557, 625.108032, 0.585, 'Prince Sandoval - OOC script 1 - Move to position'),
(@NPC_PRINCESAND_13219*100, 9, 2, 0, 1, 0, 100, 1, 8000, 8000, 0, 0, 1, 2, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC script 1 - Say 2'),
--
(@NPC_PRINCESAND_13219, 0, 14, 0, 54, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC script 1 - Say 3'),
(@NPC_PRINCESAND_13219, 0, 15, 0, 1, 0, 100, 0, 14000, 14000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC - Start Attack'),
(@NPC_PRINCESAND_13219, 0, 16, 0, 5, 0, 100, 0, 0, 0, 0, 0, 45, @KILL_13214, @KILL_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Prince Sandoval - On kill target - Set Data'),
(@NPC_PRINCESAND_13219, 0, 17, 0, 6, 0, 100, 0, 0, 0, 1, 0, 45, @CREDIT_13219, @CREDIT_13219, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Prince Sandoval - On death - Set Data'),
(@NPC_PRINCESAND_13219, 0, 18, 0, 1, 0, 100, 1,  30000,  30000, 0, 0, 45, @WIPE_13214, @WIPE_13214, 0, 0, 0, 0, 11, @NPC_GEIRRVIF, 100, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC - Set Data'),
--
(@NPC_PRINCESAND_13219, 0, 19, 20, 1, 0, 100, 0, 0, 0, 0, 0, 19, 131077, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - OOC - Change state'),
(@NPC_PRINCESAND_13219, 0, 20, 21, 61, 0, 100, 0, 0, 0, 0, 0, 28, 61144, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Remove Fire Shield'),
(@NPC_PRINCESAND_13219, 0, 21, 22, 61, 0, 100, 0, 0, 0, 0, 0, 28, 61145, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link- Remove Ember Shower'),
(@NPC_PRINCESAND_13219, 0, 22, 0, 61, 0, 100, 0, 0, 0, 0, 0, 103, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Prince Sandoval - On Link - Remove Root');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_GEIRRVIF;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_GEIRRVIF, @NPC_GEIRRVIF*100, @NPC_GEIRRVIF*100+1, @NPC_GEIRRVIF*100+2, @NPC_GEIRRVIF*100+3, @NPC_GEIRRVIF*100+4, @NPC_GEIRRVIF*100+5, @NPC_GEIRRVIF*100+6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_GEIRRVIF, 0, 0, 0, 19, 0, 100, 0, @QUEST_FALLENHEROES, 0, 0, 0, 80, @NPC_GEIRRVIF*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 1 - Call script 1'),
--
(@NPC_GEIRRVIF*100, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 1 - Move to position'),
(@NPC_GEIRRVIF*100, 9, 1, 0, 1, 0, 100, 1, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - Change npc flag'),
(@NPC_GEIRRVIF*100, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - Despawn corpse'),
(@NPC_GEIRRVIF*100, 9, 3, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 1, 0, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - say 0'),
(@NPC_GEIRRVIF*100, 9, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 1, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - say 1'),
(@NPC_GEIRRVIF*100, 9, 5, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 2, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - say 2'),
(@NPC_GEIRRVIF*100, 9, 6, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 1, 3, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 1 - say 3'),
(@NPC_GEIRRVIF*100, 9, 7, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_JHADRAS_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8222, 3518, 625.162, 3.559, 'Grieff - OOC script 1 - Summon  Father Jhadras'),
(@NPC_GEIRRVIF*100, 9, 8, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_MASUD_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8217, 3523, 624.908, 5.236, 'Grieff - OOC script 1 - Summon Masud'),
(@NPC_GEIRRVIF*100, 9, 9, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_GENESS_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8210, 3517, 624.6, 6.143, 'Grieff - OOC script 1 - Summon Geness Half-Soul'),
(@NPC_GEIRRVIF*100, 9, 10, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_TALLA_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8209, 3511, 625.117, 0.571, 'Grieff - OOC script 1 - Summon Talla'),
(@NPC_GEIRRVIF*100, 9, 11, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_ELDRETH_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8198, 3517, 625.838, 0.089, 'Grieff - OOC script 1 - Summon Eldreth'),
(@NPC_GEIRRVIF*100, 9, 12, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_RITH_13214, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8200, 3507, 625.339, 0.514, 'Grieff - OOC script 1 - Summon Rith'),
--
(@NPC_GEIRRVIF, 0, 1, 2, 38, 0, 100, 0, @CREDIT_13214, @CREDIT_13214, 0, 0, 1, 4, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Say 5'),
(@NPC_GEIRRVIF, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  linked - Move to position'),
(@NPC_GEIRRVIF, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Change npc flag'),
(@NPC_GEIRRVIF, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_FALLENHEROES, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Kill credit'),
(@NPC_GEIRRVIF, 0, 5, 0, 19, 0, 100, 0, @QUEST_KDARKMASTER, 0, 0, 0, 80, @NPC_GEIRRVIF*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 2 - Call script 2'),
--
(@NPC_GEIRRVIF*100+1, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 2 - Move to position'),
(@NPC_GEIRRVIF*100+1, 9, 1, 0, 1, 0, 100, 1, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 2 - Change npc flag'),
(@NPC_GEIRRVIF*100+1, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 2 - Despawn corpse'),
(@NPC_GEIRRVIF*100+1, 9, 3, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 1, 5, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 2 - say 5'),
(@NPC_GEIRRVIF*100+1, 9, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 6, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 2 - say 6'),
(@NPC_GEIRRVIF*100+1, 9, 5, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 7, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 2 - say 7'),
(@NPC_GEIRRVIF*100+1, 9, 6, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_KHITRIX_13215, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8165, 3451, 627.199, 1.935, 'Grieff - OOC script 2 - Summon Khitrix the Dark Master'),
--
(@NPC_GEIRRVIF, 0, 6, 7, 38, 0, 100, 0, @CREDIT_13215, @CREDIT_13215, 0, 0, 1, 8, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Say 8'),
(@NPC_GEIRRVIF, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  linked - Move to position'),
(@NPC_GEIRRVIF, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Change npc flag'),
(@NPC_GEIRRVIF, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_KDARKMASTER, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Kill credit'),
(@NPC_GEIRRVIF, 0, 10, 0, 19, 0, 100, 0, @QUEST_SIGRIDICEBORN, 0, 0, 0, 80, @NPC_GEIRRVIF*100+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 3 - Call script 3'),
--
(@NPC_GEIRRVIF*100+2, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 3 - Move to position'),
(@NPC_GEIRRVIF*100+2, 9, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 3 - Change npc flag'),
(@NPC_GEIRRVIF*100+2, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 3 - Despawn corpse'),
(@NPC_GEIRRVIF*100+2, 9, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 1, 9, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 3 - Say 9'),
(@NPC_GEIRRVIF*100+2, 9, 4, 0, 1, 0, 100, 1, 9000, 9000, 0, 0, 1, 10, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 3 - Say 10'),
(@NPC_GEIRRVIF*100+2, 9, 5, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_SIGRID_13216, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8258.836, 3599.048, 677.6457, 0.383, 'Grieff - OOC script 3 - summon Sigrid Iceborn'),
--
(@NPC_GEIRRVIF, 0, 11, 12, 38, 0, 100, 0, @CREDIT_13216, @CREDIT_13216, 0, 0, 1, 11, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Say 11'),
(@NPC_GEIRRVIF, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  linked - Move to position'),
(@NPC_GEIRRVIF, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Change npc flag'),
(@NPC_GEIRRVIF, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_SIGRIDICEBORN, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Kill credit'),
(@NPC_GEIRRVIF, 0, 15, 0, 19, 0, 100, 0, @QUEST_CARNAGE, 0, 0, 0, 80, @NPC_GEIRRVIF*100+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 4 - Call Script 4'),
--
(@NPC_GEIRRVIF*100+3, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 4 - Move to position'),
(@NPC_GEIRRVIF*100+3, 9, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 4 - Change npc flag'),
(@NPC_GEIRRVIF*100+3, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 4 - Despawn corpse'),
(@NPC_GEIRRVIF*100+3, 9, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 1, 12, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 4 - say 13'),
(@NPC_GEIRRVIF*100+3, 9, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 13, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 4 - say 13'),
(@NPC_GEIRRVIF*100+3, 9, 5, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 14, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 4 - say 14'),
(@NPC_GEIRRVIF*100+3, 9, 6, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_CARNAGE_13217, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8141.532715, 3488.100342, 626.986084, 3.662119, 'Grieff - OOC script 4 - summon Carnage'),
--
(@NPC_GEIRRVIF, 0, 16, 17, 38, 0, 100, 0, @CREDIT_13217, @CREDIT_13217, 0, 0, 1, 15, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Say 15'),
(@NPC_GEIRRVIF, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  linked - Move to position'),
(@NPC_GEIRRVIF, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Change npc flag'),
(@NPC_GEIRRVIF, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_CARNAGE, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - On Link - Kill credit'),
(@NPC_GEIRRVIF, 0, 20, 0, 19, 0, 100, 0, @QUEST_THANE, 0, 0, 0, 80, @NPC_GEIRRVIF*100+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 5 - Call script 5'),
--
(@NPC_GEIRRVIF*100+4, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 5 - Move to position'),
(@NPC_GEIRRVIF*100+4, 9, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 5 - Change npc flag'),
(@NPC_GEIRRVIF*100+4, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 5 - Despawn corpse'),
(@NPC_GEIRRVIF*100+4, 9, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 1, 16, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 5 - say 16'),
(@NPC_GEIRRVIF*100+4, 9, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 17, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 5 - say 17'),
(@NPC_GEIRRVIF*100+4, 9, 5, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 18, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 5 - say 18'),
(@NPC_GEIRRVIF*100+4, 9, 6, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_THANE_13218, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8151.247559, 3462.894043, 672.115662, 0.6877, 'Grieff - OOC script 5 - summon Thane Banahogg'),
--
(@NPC_GEIRRVIF, 0, 21, 22, 38, 0, 100, 0, @CREDIT_13218, @CREDIT_13218, 0, 0, 1, 19, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Say 19'),
(@NPC_GEIRRVIF, 0, 22, 23, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  linked - Move to position'),
(@NPC_GEIRRVIF, 0, 23, 24, 61, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Change npc flag'),
(@NPC_GEIRRVIF, 0, 24, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_THANE, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - On  linked - Kill credit'),
(@NPC_GEIRRVIF, 0, 25, 0, 19, 0, 100, 0, @QUEST_FINCHAL, 0, 0, 0, 80, @NPC_GEIRRVIF*100+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  accept quest 6 - Call script 6'),
--
(@NPC_GEIRRVIF*100+5, 9, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 69, 8216, 3516, 653, 0, 0, 0, 8, 0, 0, 0, 8215.81, 3515.88, 652.885, 3.83972, 'Grieff - OOC script 6 - Move to position'),
(@NPC_GEIRRVIF*100+5, 9, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Change npc flag'),
(@NPC_GEIRRVIF*100+5, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 45, @DESPAWN_13214, @DESPAWN_13214, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Despawn corpse'),
(@NPC_GEIRRVIF*100+5, 9, 3, 0, 1, 0, 100, 1, 0, 0, 0, 0, 1, 20, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Say 20'),
(@NPC_GEIRRVIF*100+5, 9, 4, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 21, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Say 21'),
(@NPC_GEIRRVIF*100+5, 9, 5, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 22, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Say 22'),
(@NPC_GEIRRVIF*100+5, 9, 6, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 23, 10, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 6 - Say 23'),
(@NPC_GEIRRVIF*100+5, 9, 7, 0, 1, 0, 100, 1, 0, 0, 0, 0, 12, @NPC_PRINCESAND_13219, 7, 0, 0, 1, 0, 8, 0, 0, 0, 8182.54, 3489.78, 625.50519, 0.63625, 'Grieff - OOC script 6 - Summon Prince Sandoval'),
--
(@NPC_GEIRRVIF, 0, 26, 27, 38, 0, 100, 0, @CREDIT_13219, @CREDIT_13219, 0, 0, 80, @NPC_GEIRRVIF*100+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Call script 7'),
--
(@NPC_GEIRRVIF*100+6, 9, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 1, 24, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On data set - Say 24'),
(@NPC_GEIRRVIF*100+6, 9, 1, 0, 1, 0, 100, 0, 0, 0, 0, 0, 15, @QUEST_FINCHAL, 0, 0, 0, 0, 0, 18, 80, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 7 - Kill credit'),
(@NPC_GEIRRVIF*100+6, 9, 2, 0, 1, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On link - Move to position'),
(@NPC_GEIRRVIF*100+6, 9, 3, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 1, 25, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 7 - Say 25'),
(@NPC_GEIRRVIF*100+6, 9, 4, 0, 1, 0, 100, 1, 6000, 6000, 0, 0, 1, 26, 10, 0, 0, 1, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 7 - Say 26'),
(@NPC_GEIRRVIF*100+6, 9, 5, 0, 1, 0, 100, 1, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - OOC script 7 - Change npc flag'),
--
(@NPC_GEIRRVIF, 0, 27, 0, 38, 0, 100, 0, @KILL_13214, @KILL_13214, 0, 0, 1, 27, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Greiff - On  data set - Say kill'),
(@NPC_GEIRRVIF, 0, 28, 0, 38, 0, 100, 0, @WIPE_13214, @WIPE_13214, 0, 0, 69, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 8216.25, 3516.23, 629.357, 3.83972, 'Grieff - On  data set - Move to position'),
(@NPC_GEIRRVIF, 0, 29, 0, 38, 0, 100, 0, @WIPE_13214, @WIPE_13214, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Change npc flag'),
(@NPC_GEIRRVIF, 0, 30, 0, 38, 0, 100, 0, @WIPE_13214, @WIPE_13214, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grieff - On  data set - Script reset'),
(@NPC_GEIRRVIF, 0, 31, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_ELDRETH_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 32, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_GENESS_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 33, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_JHADRAS_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 34, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_MASUD_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 35, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_RITH_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 36, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_TALLA_13214, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 37, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_KHITRIX_13215, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 38, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_SIGRID_13216, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 39, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_CARNAGE_13217, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 40, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_THANE_13218, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse'),
(@NPC_GEIRRVIF, 0, 41, 0, 38, 0, 100, 0, @DESPAWN_13219, @DESPAWN_13219, 0, 0, 41, 0, 0, 0, 0, 0, 0, 11, @NPC_PRINCESAND_13219, 200, 0, 0, 0, 0, 0, 'Grieff - On  data set - Despawn corpse');

DELETE FROM `creature_text` WHERE `entry`=@NPC_GEIRRVIF;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@NPC_GEIRRVIF, 0, 0, 'Valhalas is yours to win or die in, $N. But whatever you do, stay within the bounds of the arena. To flee is to lose and be dishonored.', 12, 0, 0, 0, 0, 0, 'Greiff quest 1 say 1'),
(@NPC_GEIRRVIF, 1, 1, '$N and $g his : her; comrades in arms have chosen to accept honorable combat within the sacred confines of Valhalas.', 14, 0, 0, 0, 0, 0, 'Greiff quest 1 say 2'),
(@NPC_GEIRRVIF, 2, 2, 'There can be only one outcome to such a battle: death for one side or the other. Let $N prove $g himself : herself; upon the bones of those outsiders who have fallen before!', 14, 0, 0, 0, 0, 0, 'Greiff quest 1 say 3'),
(@NPC_GEIRRVIF, 3, 3, 'The fallen heroes of Valhalas emerge from the ground to do battle once more!', 41, 0, 0, 0, 0, 14998, 'Greiff quest 1 say 4'),
(@NPC_GEIRRVIF, 4, 4, '$N has defeated the fallen heroes of Valhalas battles past. This is only a beginning, but it will suffice.', 14, 0, 0, 0, 0, 14998, 'Greiff quest 1 say 5'),
(@NPC_GEIRRVIF, 5, 5, 'Prepare yourself. Khit''rix will be entering Valhalas from the southeast. Remember, do not leave the ring or you will lose the battle.', 12, 0, 0, 0, 0, 0, 'Greiff quest 2 say 1'),
(@NPC_GEIRRVIF, 6, 6, '$N has accepted the challenge of Khit''rix the Dark Master. May the gods show mercy upon $g him : her; for Khit''rix surely will not.', 14, 0, 0, 0, 0, 0, 'Greiff quest 2 say 2'),
(@NPC_GEIRRVIF, 7, 7, 'Khit''rix the Dark Master skitters into Valhalas from the southeast!', 41, 0, 0, 0, 0, 14998, 'Greiff quest 2 say 3'),
(@NPC_GEIRRVIF, 8, 8, 'Khit''rix the Dark Master has been defeated by $N and $g his : her; band of companions. Let the next challenge be issued!', 14, 0, 0, 0, 0, 14998, 'Greiff quest 2 sasy 4'),
(@NPC_GEIRRVIF, 9, 9, 'Sigrid Iceborn has returned to the heights of Jotunheim to prove herself against $N. When last they met, $N bested her in personal combat. Let us see the outcome of this match.', 14, 0, 0, 0, 0, 0, 'Greiff quest 3 say 1'),
(@NPC_GEIRRVIF, 10, 10, 'Circling Valhalas, Sigrid Iceborn approaches to seek her revenge! ', 41, 0, 0, 0, 0, 14998, 'Greiff quest 3 say 2'),
(@NPC_GEIRRVIF, 11, 11, '$N has defeated Sigrid Iceborn for a second time.  Well, this time $g he : she; did it with the help of $g his : her; friends, but a win is a win!', 14, 0, 0, 0, 0, 14998, 'Greiff quest 3 say 3'),
(@NPC_GEIRRVIF, 12, 12, 'Carnage is coming! Remember, no matter what you do, do NOT leave the battle ring or I will disqualify you and your group.', 12, 0, 0, 0, 0, 0, 'Greiff quest 4 say 1'),
(@NPC_GEIRRVIF, 13, 13, 'From the bowels of the Underhalls comes Carnage.  Brave and foolish $N has accepted the challenge.  $G He : She; and $g his : her; group stand ready to face the monstrosity.', 14, 0, 0, 0, 0, 0, 'Greiff quest 4 say 2'),
(@NPC_GEIRRVIF, 14, 14, 'Lumbering in from the south, the smell of Carnage precedes him!', 41, 0, 0, 0, 0, 14998, 'Greiff quest 4 say 3'),
(@NPC_GEIRRVIF, 15, 15, 'The horror known as Carnage is no more. Could it be that $N is truly worthy of battle in Valhalas? We shall see.', 14, 0, 0, 0, 0, 14998, 'Greiff quest 4 say 4'),
(@NPC_GEIRRVIF, 16, 16, 'Look to the southeast and you will see the thane upon the platform near Gjonner the Merciless when he shows himself. Let him come down. Stay within the ring of Valhalas.', 12, 0, 0, 0, 0, 0, 'Greiff quest 5 say 1'),
(@NPC_GEIRRVIF, 17, 17, 'Thane Banahogg returns to Valhalas for the first time in ages to prove that the vrykul are the only beings worthy to fight within its sacred ring. Will $N prove him wrong?', 14, 0, 0, 0, 0, 0, 'Greiff quest 5 say 2'),
(@NPC_GEIRRVIF, 18, 18, 'Thane Banahogg appears upon the overlook to the southeast!', 41, 0, 0, 0, 0, 14998, 'Greiff quest 5 say 3'),
(@NPC_GEIRRVIF, 19, 19, 'Thane Banahogg the Deathblow has fallen to $N and $g his : her; fighting companions.  $G He : She; has but one challenge ahead of $g him : her;.  Who will it be?', 14, 0, 0, 0, 0, 14998, 'Greiff quest 5 say 4'),
(@NPC_GEIRRVIF, 20, 20, 'It''s too late to run now. Do not leave the ring. Die bravely, $N!', 12, 0, 0, 0, 0, 0, 'Greiff quest 6 say 1'),
(@NPC_GEIRRVIF, 21, 21, 'From the depths of Icecrown Citadel, one of the Lich King''s chosen comes to put an end to the existence of $N and $g his : her; friends.', 14, 0, 0, 0, 0, 0, 'Greiff quest 6 say 2'),
(@NPC_GEIRRVIF, 22, 22, 'Warriors of Jotunheim, I present to you, Blood Prince Sandoval!', 14, 0, 0, 0, 0, 0, 'Greiff quest 6 say 3'),
(@NPC_GEIRRVIF, 23, 23, 'Without warning, Prince Sandoval magically appears within Valhalas! ', 41, 0, 0, 0, 0, 14998, 'Greiff quest 6 say 4'),
(@NPC_GEIRRVIF, 24, 24, 'The unthinkable has happened... $N has slain Prince Sandoval!', 14, 0, 0, 0, 0, 0, 'Greiff quest 6 say 5'),
(@NPC_GEIRRVIF, 25, 25, 'In defeating him, $g he : she; and $g his : her; fighting companions have proven themselves worthy of battle in this most sacred place of vrykul honor.', 14, 0, 0, 0, 0, 0, 'Greiff quest 6 say 6'),
(@NPC_GEIRRVIF, 26, 26, 'ALL HAIL $N, CHAMPION OF VALHALAS!', 14, 0, 0, 0, 0, 14998, 'Greiff quest 6 say 7'),
(@NPC_GEIRRVIF, 27, 27, 'You were not prepared!', 14, 0, 0, 0, 0, 0, 'Greiff kill');
