UPDATE creature_template SET scriptname = "npc_anduin_tides_of_war" WHERE entry = 120756;
UPDATE creature_template SET scriptname = "npc_jaina_tides_of_war" WHERE entry = 120590;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_tides_of_war' WHERE `Id` IN (4857, 8709);

UPDATE creature_template SET gossip_menu_id = 22328 WHERE entry = 120590;
REPLACE INTO `gossip_menu` VALUES (22328, 34271, 28153);
REPLACE INTO `gossip_menu_option` VALUES (22328, 0, 0, "I'm ready to set sail!", 0, 1, 1, 28153);

UPDATE creature_template SET scriptname = "npc_jaina_boralus_intro" WHERE entry = 120922;
UPDATE scene_template SET ScriptName = "scene_jaina_to_proudmoore_keep" where SceneId = 1954;
UPDATE scene_template SET ScriptName = "scene_flynn_jailbreak" where SceneId = 1735;
UPDATE creature_template SET scriptname = "npc_flynn_fairwind" WHERE entry = 121239;
UPDATE creature_template SET scriptname = "npc_flynn_fairwind_follower" WHERE entry = 124311;
UPDATE gameobject_template SET scriptname = "go_toldagor_cell_block_lever" WHERE entry = 271938;
UPDATE `creature_template` SET `flags_extra` = 128, `ScriptName` = 'npc_tol_dagor_enter_sewer_credit' WHERE (entry = 134922);

UPDATE `creature_addon` SET `aiAnimKit` = 14225 WHERE `guid` = 210303366;

UPDATE quest_template_addon SET scriptname = "quest_out_like_flynn" WHERE Id = 47098;

REPLACE INTO npc_spellclick_spells VALUES
(121239, 264918, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 246555;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 246555, 31, 5, 124022); 

DELETE FROM spell_script_names WHERE scriptname IN ("aura_tol_dagor_intro_prisoner", "aura_stormwind_to_harbor_teleport");
INSERT INTO spell_script_names VALUES
(240876, "aura_stormwind_to_harbor_teleport"),
(272512, "aura_tol_dagor_intro_prisoner");

UPDATE `npc_spellclick_spells` SET `cast_flags` = '1' WHERE `npc_entry` = '124030' AND `spell_id` = '247045';
UPDATE `creature_template` SET `InhabitType` = 4 WHERE entry IN (124030, 139522);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_tol_dagor_escape' WHERE `Id` IN (5336, 5340);
UPDATE `conversation_template` SET `ScriptName` = 'conversation_tol_dagor_inmate' WHERE `Id` IN (8330, 8333, 8334);
UPDATE `creature_template` SET `InhabitType` = 4, `VehicleId` = '5474' WHERE `entry` = '124357'; 

DELETE FROM `gameobject` WHERE `guid` IN (210406721, 210406722);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(210406721, 289321, 0, 1519, 6292, '0', '11925', 0, -8371.054, 242.3681, 155.3472, 2.24604, 0, 0, 0.901412, 0.4329623, 120, 255, 1, 27404), -- Alliance Map Table (Area: Stormwind Keep - Difficulty: 0)
(210406722, 281874, 0, 1519, 6292, '0', '11825', 0, -8245.816, 1331.063, -3.089088, 4.750497, 0, 0, -0.6935062, 0.7204506, 120, 255, 1, 27404); -- Jaina's Ship (Area: Stormwind Keep - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` BETWEEN 280000112 AND 280000123;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(280000112, 139645, 0, 1519, 6292, '0', '11925', 0, 0, 0, -8373.802, 245.4097, 156.8826, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Vision of Sailor's Memory (Area: Stormwind Keep - Difficulty: 0)
(280000113, 43845,  0, 1519, 6292, '0', '11925', 0, 0, 0, -8411.259, 219.3385, 155.4305, 3.967043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Malfurion Stormrage (Area: Stormwind Keep - Difficulty: 0)
(280000114, 120597, 0, 1519, 6292, '0', '11925', 0, 0, 0, -8382.04, 231.9323, 155.4305, 0.9864509, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Commander Lorna Crowley (Area: Stormwind Keep - Difficulty: 0)
(280000115, 7999,   0, 1519, 6292, '0', '11925', 0, 0, 0, -8416.451, 220.0833, 155.4305, 5.23185, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Tyrande Whisperwind (Area: Stormwind Keep - Difficulty: 0)
(280000116, 139642, 0, 1519, 6292, '0', '11925', 0, 0, 0, -8374.014, 245.4497, 155.4305, 5.645445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- 7th Legion Sailor (Area: Stormwind Keep - Difficulty: 0)
(280000117, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8264.268, 1338.944, 18.76146, 3.158645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)
(280000118, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8235.139, 1334.891, 18.78497, 1.481358, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)
(280000119, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8234.069, 1337.019, 18.61984, 4.112025, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)
(280000120, 120590, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8281.764, 1326.863, 5.322724, 3.288784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Lady Jaina Proudmoore (Area: Stormwind Harbor - Difficulty: 0)
(280000121, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8263.696, 1359.635, 18.8017, 1.417557, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)
(280000122, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8237.676, 1369.901, 23.27885, 3.236135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404), -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)
(280000123, 144378, 0, 1519, 4411, '0', '11825', 0, 0, 0, -8240, 1369.356, 23.27885, 0.6054686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27404); -- Alliance Sailor (Area: Stormwind Harbor - Difficulty: 0)

UPDATE creature SET npcflag = 1 WHERE guid = 280000120;

UPDATE conversation_template SET LastLineEndTime = 35185 WHERE Id = 5336;
UPDATE conversation_template SET LastLineEndTime = 15326 WHERE Id = 5340;

DELETE FROM `conversation_actors` WHERE ConversationId IN (4857, 4896, 8709, 8334, 7653, 5462, 8062, 8356, 8741, 8742);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorGuid`, `Idx`, `VerifiedBuild`) VALUES
(4857, 280000109, 1, 27404), -- Full: 0x203CE00000885D000009A5000000A939 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: 139636 (Master Mathias Shaw) Low: 43321
(4857, 280000110, 2, 27404), -- Full: 0x203CE0000075F5000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Genn Greymane Low: 43320
(4857, 280000111, 0, 27404), -- Full: 0x203CE0000075ED000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Anduin Wrynn Low: 43320
(4896, 280000110, 2, 27404), -- Full: 0x203CE0000075F5000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Genn Greymane Low: 43320
(4896, 280000111, 1, 27404), -- Full: 0x203CE0000075ED000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Anduin Wrynn Low: 43320
(4896, 280000111, 0, 27404),
(8709, 280000111, 0, 27404), -- Full: 0x203CE0000075ED000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Anduin Wrynn Low: 43320
(8709, 280000110, 2, 27404), -- Full: 0x203CE0000075F5000009A5000000A938 Creature/0 R3896/S2469 Map: Eastern Kingdoms Entry: Genn Greymane Low: 43320;

(8334, 210347835, 0, 27404), -- Full: 0x204240CD60797100006DC9000000A78F Creature/0 R4240/S28105 Map: Kul Tiras Entry: 124356 (Taelia) Low: 42895
-- (8334, UNKNOWN, 1, 27404), -- Full: 0x204240CD607965C0006DC9000003E89F Creature/0 R4240/S28105 Map: Kul Tiras Entry: 124311 (Tol Dagor Inmate) Low: 256159

-- "King greyman it is an honor"
(8062, 210347841, 0, 27404), -- Full: 0x203CD0CD60778080003183000003EECC Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 257740
(8062, 210347835, 1, 27404), -- Full: 0x203CD0CD607664C000318300000316A7 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Taelia Low: 202407

-- Cyrus story with wounded guy
(7653, 210347841, 1, 27404), -- Full: 0x203CD0CD60778080003183000003EF63 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 257891
(7653, 210334796, 0, 27404), -- Full: 0x203CD0CD6075F500003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Genn Greymane Low: 202398

-- "Situation report ready"
(8356, 210347841, 1, 27404), -- Full: 0x203CD0CD60778080003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 202398
(8356, 210347835, 0, 27404), -- Full: 0x203CD0CD607664C000318300000316A7 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Taelia Low: 202407

-- Flynn explain new ashvane weapon
(8741, 210347841, 1, 27404), -- Full: 0x203CD0CD60778080003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 202398
(8741, 210304139, 2, 27404), -- Full: 0x203CD0CD607665C0003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Flynn Fairwind Low: 202398
(8741, 210347835, 0, 27404), -- Full: 0x203CD0CD607664C000318300000316A7 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Taelia Low: 202407

-- What was that ?
(5462, 210347841, 0, 27404), -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: Eastern Kingdoms Low: 1099511627775
(5462, 210347841, 1, 27404), -- Full: 0x203CD0CD60778080003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 202398
(5462, 210304139, 2, 27404), -- Full: 0x203CD0CD607665C0003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Flynn Fairwind Low: 202398

-- Flynn  help our new ally
(8742, 210347841, 0, 27404), -- Full: 0x203CD0CD60778080003183000003169E Creature/0 R3892/S12675 Map: Kul Tiras Entry: Cyrus Crestfall Low: 202398
(8742, 210304139, 1, 27404), -- Full: 0x203CD0CD607665C0003183000003F242 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Flynn Fairwind Low: 258626
(8742, 210347835, 2, 27404); -- Full: 0x203CD0CD607664C000318300000316A7 Creature/0 R3892/S12675 Map: Kul Tiras Entry: Taelia Low: 202407

UPDATE `quest_template_addon` SET `PrevQuestID` = '47099', `ExclusiveGroup` = '0' WHERE `id` = 46729;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47098', `ExclusiveGroup` = '0' WHERE `id` = 47099;
UPDATE `quest_template_addon` SET `PrevQuestID` = '51341', `ExclusiveGroup` = '0' WHERE `id` = 47098;
UPDATE `quest_template_addon` SET `PrevQuestID` = '46728', `ExclusiveGroup` = '0' WHERE `id` = 51341;
UPDATE `quest_template_addon` SET `PrevQuestID` = '46727', `ExclusiveGroup` = '0' WHERE `id` = 46728;
UPDATE `quest_template_addon` SET `PrevQuestID` = '51403', `ExclusiveGroup` = '0' WHERE `id` = 46727;
UPDATE `quest_template_addon` SET `ExclusiveGroup` = '0' WHERE `id` = 51403;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 124357;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
('124357', '46598', '1'); 

DELETE FROM creature WHERE guid IN (210303743, 210303744, 210303745, 210303746, 210303747);

UPDATE `vehicle_template_accessory` SET `seat_id` = '2' WHERE `entry` = '124357' AND `seat_id` = '1'; 

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (124356, 124363);
INSERT INTO `creature_equip_template` (`CreatureID`, `ItemID1`, `VerifiedBuild`) VALUES
('124356', '155767', '28503'),
('124363', '155767', '28503'); 

UPDATE creature_template SET scriptname = "npc_tol_dagor_getaway_boat" WHERE entry = 124357;
UPDATE scene_template SET ScriptName = "scene_tol_dagor_getaway_boat" where SceneId = 1746;

UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_get_your_bearings' WHERE `Id` IN (5360, 5362, 5365, 5366, 5375, 7605, 9556);

REPLACE INTO `creature_model_info` (`DisplayID`, `CombatReach`, `VerifiedBuild`) VALUES
('81516', '1', '28503');

UPDATE creature_template SET npcflag = 2, scriptname = "npc_taelia_get_your_bearings" WHERE entry = 124630;

DELETE FROM `creature_questender` WHERE (quest = 47099);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(124630, 47099);

DELETE FROM `creature_queststarter` WHERE (quest = 46729);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(124630, 46729);

REPLACE INTO `creature_summoner_entry` (`CreatureId`, `SummonerVisibleCreatureId`) VALUES
('124630', '138622');

DELETE FROM creature WHERE id IN (32639, 62821, 32638, 137316);
DELETE FROM creature WHERE guid IN (210304119, 210304120, 210304117, 210304118);

UPDATE creature_addon SET aiAnimKit = 13362 WHERE guid = 210304139;

DELETE FROM `spell_area` WHERE `spell` IN (272512, 247532);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(272512, 8978, 47098, 0,     0, 1, 1,  0),
(247532, 8717, 47099, 46729, 0, 1, 74, 66);

UPDATE scene_template SET ScriptName = "scene_boralus_old_knight" where SceneId = 1960;

UPDATE creature_template SET scriptname = "npc_cyrus_crestfall" WHERE entry = 122370;
UPDATE `conversation_template` SET `LastLineEndTime` = '106000', `ScriptName` = "conversation_cyrus_story" WHERE `Id` = '7653'; 

UPDATE gameobject_template_addon SET flags = 3 WHERE entry IN (281878, 301088);

UPDATE creature_template_addon SET aiAnimKit = 15435 WHERE entry = 135943;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=7317 AND `Idx`=1) OR (`ConversationId`=7317 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(7317, 210321411, 1, 27377), -- Full: 0x204228CD6084C240001AC10000772A61 Creature/0 R4234/S6849 Map: Kul Tiras Entry: 135945 (Mark Waldorf) Low: 7809633
(7317, 210321420, 0, 27377); -- Full: 0x204228CD6084C1C0001AC10000772A61 Creature/0 R4234/S6849 Map: Kul Tiras Entry: 135943 (Laura Statler) Low: 7809633

UPDATE `gameobject_template_addon` SET `faction`=2908 WHERE `entry`=35591; -- Fishing Bobber

UPDATE `creature_template_addon` SET `auras`='98892 281565 178806' WHERE `entry`=131997; -- 131997 (Training Dummy)
UPDATE `creature_template_addon` SET `auras`='98892 167347 260294 178806' WHERE `entry`=131998; -- 131998 (Training Dummy)

REPLACE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(135107, 135112, 0, 1, 'Scrimshaw Thug - Gaunt Vagabond', 6, 60000), -- Scrimshaw Thug - Gaunt Vagabond
(142543, 142132, 0, 1, 'Becca\'s Vehicle Bunny - Becca', 6, 60000), -- Becca's Vehicle Bunny - Becca
(135792, 124883, 0, 1, 'Boralus Worker - Kul Tiran Wheelbarrow', 6, 60000), -- Boralus Worker - Kul Tiran Wheelbarrow
(135798, 135797, 0, 1, 'Hanging - Abraham Combs', 6, 60000), -- Hanging - Abraham Combs
(137979, 137980, 1, 1, 'Galeheart - Taelia', 6, 60000), -- Galeheart - Taelia
(143260, 143262, 0, 1, 'Steve Martinez - Captain', 6, 60000); -- Steve Martinez - Captain

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(142139, 224326, 1, 0),
(142056, 224326, 1, 0),
(143022, 224326, 1, 0),
(143502, 224326, 1, 0),
(135521, 224326, 1, 0),
(143272, 224326, 1, 0),
(134849, 267134, 1, 0),
(134845, 265601, 1, 0),
(142119, 224326, 1, 0),
(142092, 224326, 1, 0),
(142099, 224326, 1, 0),
(143721, 224326, 1, 0),
(142126, 224326, 1, 0),
(142527, 224326, 1, 0),
(142530, 224326, 1, 0),
(142541, 224326, 1, 0),
(142124, 224326, 1, 0),
(142130, 224326, 1, 0),
(142091, 224326, 1, 0),
(142090, 224326, 1, 0),
(143571, 224326, 1, 0),
(143516, 224326, 1, 0),
(142125, 224326, 1, 0),
(142505, 224326, 1, 0),
(142507, 224326, 1, 0),
(142122, 224326, 1, 0),
(142127, 224326, 1, 0),
(142542, 224326, 1, 0),
(142129, 224326, 1, 0),
(142506, 224326, 1, 0),
(142116, 224326, 1, 0),
(142549, 224326, 1, 0),
(143501, 224326, 1, 0),
(142513, 224326, 1, 0),
(142118, 224326, 1, 0),
(142514, 224326, 1, 0),
(142517, 224326, 1, 0),
(142526, 224326, 1, 0),
(144175, 224326, 1, 0),
(144178, 224326, 1, 0),
(144177, 224326, 1, 0),
(144176, 224326, 1, 0),
(139735, 274326, 1, 0),
(142111, 224326, 1, 0),
(137199, 224326, 1, 0),
(137196, 224326, 1, 0),
(142050, 224326, 1, 0),
(138423, 224326, 1, 0),
(142035, 224326, 1, 0),
(142044, 224326, 1, 0),
(142453, 224326, 1, 0),
(138410, 224326, 1, 0),
(138421, 224326, 1, 0),
(142069, 224326, 1, 0),
(142051, 224326, 1, 0),
(142053, 224326, 1, 0),
(142052, 224326, 1, 0),
(142029, 224326, 1, 0),
(142046, 224326, 1, 0),
(142031, 224326, 1, 0),
(142030, 224326, 1, 0),
(142613, 224326, 1, 0),
(142043, 224326, 1, 0),
(142042, 224326, 1, 0),
(142040, 224326, 1, 0),
(137201, 224326, 1, 0),
(138422, 224326, 1, 0),
(142055, 224326, 1, 0),
(142032, 224326, 1, 0),
(144110, 224326, 1, 0),
(144327, 224326, 1, 0),
(144328, 224326, 1, 0),
(143444, 224326, 1, 0),
(137135, 269403, 1, 0);


UPDATE `gameobject_template_addon` SET `faction`=2908 WHERE `entry`=35591; -- Fishing Bobber

UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=143700; -- 143700 (Domestic Alpaca)
UPDATE `creature_template_addon` SET `bytes1`=50331649 WHERE `entry`=127636; -- 127636 (Tiragarde Owl)
UPDATE `creature_template_addon` SET `auras`='212682' WHERE `entry`=133264; -- 133264 (Hatherford Inspector)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=126496; -- 126496 (Wandering Mouser)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=142774; -- 142774 (Cellarman Hinz)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=140906; -- 140906 (Dock Rat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=144213; -- 144213 (Scrimshaw Racketeer)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=132638; -- 132638 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142180; -- 142180 (Tradewinds Laborer)
UPDATE `creature_template_addon` SET `aiAnimKit`=16390 WHERE `entry`=143107; -- 143107 (Navigator Hudson)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='244863' WHERE `entry`=142166; -- 142166 (Tradewinds Dockworker)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=143870; -- 143870 (Off-Duty Cannoneer)
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=136633; -- Harbor Guard
UPDATE `creature_template_addon` SET `bytes2`=1, `aiAnimKit`=14225 WHERE `entry`=121239; -- Flynn Fairwind
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=123642; -- 123642 (Boralus Citizen)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=133282; -- 133282 (Stormsong Trader)
UPDATE `creature_template_addon` SET `auras`='281526' WHERE `entry`=135520; -- 135520 (Boralus Youth)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='' WHERE `entry`=141085; -- 141085 (Off-Duty Cadet)
UPDATE `creature_template_addon` SET `mount`=81689 WHERE `entry`=139088; -- Boralus Guard
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=144378; -- 144378 (Alliance Sailor)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=140202; -- 140202 (Darnassian Archer)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=120788; -- Genn Greymane
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=120599; -- Greyguard
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=141583; -- 141583 (Grieving Citizen)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=136728; -- 136728 (Maiden of Vitality)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=133433; -- 133433 (Ghostblade Scout)
UPDATE `creature_template_addon` SET `auras`='122729 123240' WHERE `entry`=62822; -- 62822 (Cousin Slowhands)
UPDATE `creature_template_addon` SET `auras`='122729 123236' WHERE `entry`=62821; -- 62821 (Mystic Birdhat)


UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=125005 AND `ID`=2); -- Kul Tiran Noble
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=125005 AND `ID`=1); -- Kul Tiran Noble
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=139088 AND `ID`=2); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=142605 AND `ID`=1); -- Chris Pyle
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=133282 AND `ID`=1); -- Stormsong Trader
UPDATE `creature_equip_template` SET `ItemID1`=80057 WHERE (`CreatureID`=135792 AND `ID`=2); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=135792 AND `ID`=1); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=31824 WHERE (`CreatureID`=135678 AND `ID`=2); -- 7th Legion Cannoneer
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=135678 AND `ID`=1); -- 7th Legion Cannoneer


UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=139522; -- Scouting Map
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=121239; -- Flynn Fairwind
UPDATE `creature_template` SET `faction`=2995 WHERE `entry`=141085; -- Off-Duty Cadet
UPDATE `creature_template` SET `minlevel`=123, `maxlevel`=123 WHERE `entry`=43845; -- Malfurion Stormrage
UPDATE `creature_template` SET `minlevel`=123, `maxlevel`=123 WHERE `entry`=7999; -- Tyrande Whisperwind
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=120599; -- Greyguard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=1756; -- Stormwind Royal Guard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=89715; -- Franklin Martin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=14439; -- Officer Brady
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=43690; -- Auctioneer Hesse
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=43842; -- Auctioneer Fitzgerald
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=43841; -- Auctioneer Lauffer
UPDATE `creature_template` SET `maxlevel`=5 WHERE `entry`=43102; -- Rock Lobster
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=37944; -- Stormwind City Patroller
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=29712; -- Stormwind Harbor Guard
UPDATE `creature_template` SET `speed_run`=0.7142857 WHERE `entry`=140146; -- Stormwind Infantry Captain
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=48275; -- Kurzel
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=48883; -- Ramkahen Guardian
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags3`=1 WHERE `entry`=3681; -- Wisp
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=51348; -- Stormwind Gryphon Rider
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=1976; -- Stormwind City Patroller
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2 WHERE `entry`=12360; -- Riding Striped Nightsaber
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags3`=1 WHERE `entry`=50307; -- Lord Candren
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags3`=1 WHERE `entry`=50305; -- Moon Priestess Lasara
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2 WHERE `entry`=35168; -- Striped Dawnsaber
UPDATE `creature_template` SET `minlevel`=2, `maxlevel`=2 WHERE `entry`=14556; -- Swift Frostsaber
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `unit_flags`=33536, `unit_flags3`=1 WHERE `entry`=4423; -- Darnassian Protector
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=14602; -- Swift Stormsaber
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=12358; -- Riding Striped Frostsaber
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=68; -- Stormwind City Guard

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(112698, 224326, 1, 0),
(112686, 224326, 1, 0),
(112694, 224326, 1, 0),
(142786, 224326, 1, 0),
(29152, 83580, 1, 0),
(139645, 274244, 1, 0),
(135521, 224326, 1, 0),
(124030, 247045, 1, 0),
(142056, 224326, 1, 0),
(142139, 224326, 1, 0),
(143502, 224326, 1, 0),
(143022, 224326, 1, 0),
(143272, 224326, 1, 0),
(142119, 224326, 1, 0),
(129745, 257256, 1, 0),
(134586, 257256, 1, 0),
(134122, 257256, 1, 0),
(129724, 257217, 1, 0),
(140755, 275332, 1, 0),
(127016, 252092, 1, 0),
(125333, 224326, 1, 0),
(130461, 224326, 1, 0),
(127149, 240770, 1, 0),
(127618, 254969, 1, 0),
(124847, 254964, 1, 0),
(127718, 253500, 1, 0),
(128478, 254961, 1, 0),
(128476, 254965, 1, 0);

UPDATE `quest_template_addon` SET `PrevQuestID` = 47186 WHERE (ID = 47189);
UPDATE `quest_template_addon` SET `PrevQuestID` = 46729 WHERE (ID = 52128);
UPDATE `quest_template_addon` SET `PrevQuestID` = 52128 WHERE (ID = 47186);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47189 WHERE (ID = 52654);
UPDATE `quest_template_addon` SET `PrevQuestID` = 52654 WHERE (ID = 52544);
UPDATE `quest_template_addon` SET `PrevQuestID` = 52544 WHERE (ID = 53332);

UPDATE `quest_template_addon` SET `PrevQuestID` = 53332 WHERE (ID = 51714);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51714 WHERE (ID = 51715);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51715 WHERE (ID = 53074);
UPDATE `quest_template_addon` SET `PrevQuestID` = 53074 WHERE (ID = 51569);

UPDATE `quest_template_addon` SET `PrevQuestID` = 47960 WHERE (ID = 47181);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47181 WHERE (ID = 47485);
UPDATE `quest_template_addon` SET `PrevQuestID` = 50972 WHERE (ID = 52800);

UPDATE `quest_template_addon` SET `PrevQuestID` = 47962 WHERE (ID = 47952);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47952 WHERE (ID = 51487);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51487 WHERE (ID = 51488);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51488 WHERE (ID = 51489);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51489 WHERE (ID = 51490);
UPDATE `quest_template_addon` SET `PrevQuestID` = 51490 WHERE (ID = 51401);


UPDATE `quest_template_addon` SET `PrevQuestID` = 47961 WHERE (ID = 48622);
UPDATE `quest_template_addon` SET `PrevQuestID` = 48622 WHERE (ID = 47968);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47968 WHERE (ID = 47978);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47978 WHERE (ID = 47979);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47979 WHERE (ID = 47981);
UPDATE `quest_template_addon` SET `PrevQuestID` = 47981 WHERE (ID = 47982);

UPDATE `quest_template_addon` SET `PrevQuestID` = 49404 WHERE (ID = 52148);


UPDATE `quest_template_addon` SET `PrevQuestID` = '53041', `ExclusiveGroup` = '0' WHERE `id` = 47489;
UPDATE `quest_template_addon` SET `PrevQuestID` = '50531', `ExclusiveGroup` = '0' WHERE `id` = 53041;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47486', `ExclusiveGroup` = '0' WHERE `id` = 50531;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47486' WHERE `id` = 47486;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47486' WHERE `id` = 47488;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47486' WHERE `id` = 50573;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47486' WHERE `id` = 47487;
UPDATE `quest_template_addon` SET `ExclusiveGroup` = '0' WHERE `id` = 47485;

UPDATE `quest_template_addon` SET `RequiredSkillID` = 2565, `RequiredSkillPoints` = 150 WHERE ID IN (51889, 52043);

DELETE FROM `creature_queststarter` WHERE quest = 47186 AND id IN (120788);
DELETE FROM `creature_questender`   WHERE quest = 47186 AND id IN (120788);

UPDATE creature SET phaseId = 50 WHERE guid IN (210322451);

UPDATE `quest_template_addon` SET `PrevQuestID` = 47960 WHERE `id` = 47181;
UPDATE `quest_template_addon` SET `PrevQuestID` = 47181 WHERE `id` = 47485;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47488' WHERE `id` = 47488;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47488' WHERE `id` = 47487;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47488' WHERE `id` = 47486;
UPDATE `quest_template_addon` SET `PrevQuestID` = '47485', `ExclusiveGroup` = '-47488' WHERE `id` = 50573;
UPDATE `quest_template_addon` SET `PrevQuestID` = 47488 WHERE `id` = 50531;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50531 WHERE `id` = 53041;
UPDATE `quest_template_addon` SET `PrevQuestID` = 53041 WHERE `id` = 47489;

UPDATE `quest_template_addon` SET `PrevQuestID` = 47489 WHERE `id` = 49218;
UPDATE `quest_template_addon` SET `PrevQuestID` = '49218', `ExclusiveGroup` = '-49230' WHERE `id` = 49230;
UPDATE `quest_template_addon` SET `PrevQuestID` = '49218', `ExclusiveGroup` = '-49230' WHERE `id` = 49178;
UPDATE `quest_template_addon` SET `PrevQuestID` = '49218', `ExclusiveGroup` = '-49230' WHERE `id` = 49226;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49230 WHERE `id` = 48421;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48421 WHERE `id` = 48516;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48516 WHERE `id` = 48419;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48419 WHERE `id` = 48505;

UPDATE `quest_template_addon` SET `PrevQuestID` = 48505 WHERE `id` = 48539;
UPDATE `quest_template_addon` SET `PrevQuestID` = '48539', `ExclusiveGroup` = '-48558' WHERE `id` = 48558;
UPDATE `quest_template_addon` SET `PrevQuestID` = '48539', `ExclusiveGroup` = '-48558' WHERE `id` = 48773;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48558 WHERE `id` = 49239;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49239 WHERE `id` = 49398;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49398 WHERE `id` = 49401;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49401 WHERE `id` = 49399;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49399 WHERE `id` = 49404;

UPDATE `quest_template_addon` SET `PrevQuestID` = 49404 WHERE `id` = 49405;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49405 WHERE `id` = 52431;
UPDATE `quest_template_addon` SET `PrevQuestID` = 52431 WHERE `id` = 49869;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49869 WHERE `id` = 52750;

UPDATE `quest_template_addon` SET `PrevQuestID` = 52750 WHERE `id` = 49737;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49737 WHERE `id` = 49738;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49738 WHERE `id` = 49736;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49736 WHERE `id` = 49740;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49740 WHERE `id` = 52787;
UPDATE `quest_template_addon` SET `PrevQuestID` = 52787 WHERE `id` = 49741;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49741 WHERE `id` = 50110;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50110 WHERE `id` = 50795;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50795 WHERE `id` = 50787;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50787 WHERE `id` = 50788;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50788 WHERE `id` = 50789;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50789 WHERE `id` = 50790;
UPDATE `quest_template_addon` SET `PrevQuestID` = 50790 WHERE `id` = 50972;

UPDATE `quest_template_addon` SET `PrevQuestID` = 48070 WHERE `Id` = 48077;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48077 WHERE `Id` = 48080;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48080 WHERE `Id` = 48616;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48616 WHERE `Id` = 48670;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48670 WHERE `Id` = 48195;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48195 WHERE `Id` = 48196;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48196 WHERE `Id` = 48597;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48597 WHERE `Id` = 48778;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48778 WHERE `Id` = 48003;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48003 WHERE `Id` = 48005;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48005 WHERE `Id` = 48004;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48004 WHERE `Id` = 48939;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48939 WHERE `Id` = 48087;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48087 WHERE `Id` = 48088;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48088 WHERE `Id` = 48089;

UPDATE `quest_template_addon` SET `PrevQuestID` = 48347 WHERE `Id` = 48540;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48540 WHERE `Id` = 49268;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49268 WHERE `Id` = 48352;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48352 WHERE `Id` = 48348;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48348 WHERE `Id` = 48353;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48353 WHERE `Id` = 49292;
UPDATE `quest_template_addon` SET `PrevQuestID` = 49292 WHERE `Id` = 48354;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48354 WHERE `Id` = 48355;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48355 WHERE `Id` = 48356;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48356 WHERE `Id` = 48009;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48009 WHERE `Id` = 48365;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48365 WHERE `Id` = 48366;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48366 WHERE `Id` = 48372;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48372 WHERE `Id` = 48368;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48368 WHERE `Id` = 48370;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48370 WHERE `Id` = 48367;
UPDATE `quest_template_addon` SET `PrevQuestID` = 48367 WHERE `Id` = 49302;

UPDATE `creature_template` SET `minlevel` = 120, `maxlevel` = 120 WHERE (entry = 124630);
DELETE FROM `creature_equip_template` WHERE (CreatureID = 124630);
INSERT INTO `creature_equip_template` (`CreatureID`, `ItemID1`) VALUES
(124630, 155757);

DELETE FROM `creature_queststarter` WHERE `quest` = 53118;
UPDATE `creature_template` SET `ScriptName` = 'npc_boralus_portal_maga' WHERE (entry = 137066);
UPDATE `creature_template` SET `ScriptName` = 'npc_taelia_harbormaster' WHERE (entry = 121235);
UPDATE `creature_template` SET `ScriptName` = 'npc_boralus_adventure_map' WHERE (entry = 139522);

UPDATE `creature_template` SET `gossip_menu_id` = 21157 WHERE (entry = 122681);
UPDATE `gameobject_template` SET `Data1` = '47486' WHERE (entry = 271616);
