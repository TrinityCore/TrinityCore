SET @CGUID := 91749;
SET @OGUID := 62179;

UPDATE `creature_template` SET `npcflag`=16777216 WHERE  `entry`=28162;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28162;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(28162, 51026, 1, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(28162,28330,28156) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(2833000,2833001,2833002) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28162, 0, 0, 1, 8, 0, 100, 1, 51026, 0, 0, 0, 11, 61286, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Corpse - On Spellhit Create Drakkari Medallion Cover - Cast World Generic Dismount/Cancel Shapeshift'),
(28162, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 50737, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Corpse - On Spellhit Create Drakkari Medallion Cover - Cast Create Drakkari Medallion'),
(28162, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Corpse - On Spellhit Create Drakkari Medallion Cover - Cast Create Drakkari Medallion'),
(28162, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Corpse - On Spellhit Create Drakkari Medallion Cover - Despawn'),
(28162, 0, 4, 0, 25, 0, 100, 0, 0, 0, 0, 0, 81, 16777216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Drakkari Corpse - On Respawn - Set NPC Flags'),
(28330, 0, 0, 1, 8, 0, 100, 0, 51333, 0, 120000, 120000, 33, 28330, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - On Spell Hit - Give Quest Credit'),
(28330, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 190550, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - On Spell Hit - Despawn GO'),
(28330, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 87, 2833000, 2833001, 2833002, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - On Spell Hit - Run Random Script'),
(28156, 0, 0, 1, 8, 0, 100, 1, 51276, 0, 0, 0, 11, 59216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit \'Incinerate Corpse\' - Cast \'Burning Corpse\''),
(28156, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51279, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit - Cast \'Defeated Argent Footman KC\''),
(28156, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Defeated Argent Footman - On Spellhit - Despawn'),
(2833000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51345, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - Script 1 - Cast Summon Ancient Drakkari Chest'),
(2833001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51357, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - Script 2 - Cast Summon Spider'),
(2833002, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 51370, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ancient Dirt KC Bunny - Script 3 - Cast Summon Drakkari Spectre');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=28162;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(18, 28162, 51026, 0, 0, 9, 0, 12519, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');

DELETE FROM `gameobject_template` WHERE `entry`=190552;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(190552, 3, 2450, 'Ancient Drakkari Chest', '', '', '', 94, 0, 1, 1691, 27240, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 14007);

DELETE FROM `gameobject_loot_template` WHERE `Entry`=27240;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(27240, 46369, 0, 52, 0, 1, 1, 1, 1, NULL),
(27240, 46368, 0, 47, 0, 1, 1, 1, 1, NULL),
(27240, 43851, 0, 15, 0, 1, 2, 1, 1, NULL),
(27240, 43852, 0, 14, 0, 1, 2, 1, 1, NULL),
(27240, 33470, 0, 14, 0, 1, 3, 1, 4, NULL);

DELETE FROM `creature` WHERE `id`=28330;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 28330, 571, 1, 1, 4994.237, -2934.52, 289.698, 4.502949, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+1, 28330, 571, 1, 1, 4928.283, -2954.844, 289.4258, 0.3665192, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+2, 28330, 571, 1, 1, 4971.499, -2967.053, 290.4032, 6.021386, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+3, 28330, 571, 1, 1, 4934.217, -2988.888, 290.1517, 3.316126, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+4, 28330, 571, 1, 1, 4901.642, -3020.357, 290.4903, 3.577925, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+5, 28330, 571, 1, 1, 4936.192, -2911.305, 289.9935, 3.804818, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+6, 28330, 571, 1, 1, 4904.635, -2938.013, 290.041, 2.792527, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+7, 28330, 571, 1, 1, 4959.712, -2882.519, 290.1794, 2.495821, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+8, 28330, 571, 1, 1, 4903.988, -2988.983, 289.8607, 6.073746, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+9, 28330, 571, 1, 1, 4884.578, -2949.397, 291.4635, 6.248279, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+10, 28330, 571, 1, 1, 4867.053, -3032.317, 290.2768, 0.01745329, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+11, 28330, 571, 1, 1, 4875.137, -2981.573, 289.6624, 3.769911, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+12, 28330, 571, 1, 1, 4948.37, -2845.009, 289.9186, 0.2094395, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+13, 28330, 571, 1, 1, 4900.262, -2870.288, 290.5846, 2.879793, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+14, 28330, 571, 1, 1, 4889.488, -2826.498, 291.2368, 6.213372, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+15, 28330, 571, 1, 1, 4865.896, -2879.65, 291.2252, 3.124139, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+16, 28330, 571, 1, 1, 4847.792, -2933.366, 290.7986, 1.954769, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+17, 28330, 571, 1, 1, 4838.494, -2962.302, 290.7893, 5.096361, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+18, 28330, 571, 1, 1, 4834.676, -3024.518, 290.9732, 5.77704, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+19, 28330, 571, 1, 1, 4834.516, -3055.432, 292.7168, 4.223697, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+20, 28330, 571, 1, 1, 4833.344, -3086.806, 290.7325, 5.183628, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+21, 28330, 571, 1, 1, 4811.373, -3122.263, 290.908, 3.787364, 120, 0, 0), -- 28330 (Area: 66)
(@CGUID+22, 28330, 571, 1, 1, 4774.604, -3146.782, 293.9535, 4.886922, 120, 0, 0); -- 28330 (Area: 66)

DELETE FROM `gameobject` WHERE `id`=190550;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 190550, 571, 1, 1, 4947.931, -2845.012, 289.6788, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 4278)
(@OGUID+1, 190550, 571, 1, 1, 4994.241, -2934.715, 289.4844, 3.036838, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+2, 190550, 571, 1, 1, 4959.522, -2882.375, 289.9583, -0.2268925, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+3, 190550, 571, 1, 1, 4935.69, -2910.847, 289.8739, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+4, 190550, 571, 1, 1, 4904.143, -2988.849, 289.7597, -2.879789, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+5, 190550, 571, 1, 1, 4901.818, -3020.541, 290.4142, 2.862335, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+6, 190550, 571, 1, 1, 4847.445, -2933.018, 290.703, 2.91469, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+7, 190550, 571, 1, 1, 4889.123, -2826.122, 291.1009, -2.670348, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+8, 190550, 571, 1, 1, 4959.522, -2882.375, 289.9583, -0.2268925, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+9, 190550, 571, 1, 1, 4904.084, -2937.728, 289.9795, -0.9250239, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+10, 190550, 571, 1, 1, 4865.544, -2879.292, 291.0988, 0.8377574, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+11, 190550, 571, 1, 1, 4935.69, -2910.847, 289.8739, 0.4712385, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+12, 190550, 571, 1, 1, 4934.223, -2988.802, 290.0577, 1.727875, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+13, 190550, 571, 1, 1, 4874.853, -2981.499, 289.5772, 5.183629, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+14, 190550, 571, 1, 1, 4837.822, -2961.738, 290.6022, 2.565632, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+15, 190550, 571, 1, 1, 4834.372, -3055.432, 292.4856, 4.799657, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+16, 190550, 571, 1, 1, 4928.226, -2954.833, 289.3405, 2.129301, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 4279)
(@OGUID+17, 190550, 571, 1, 1, 4900.326, -2870.361, 290.4038, 1.431168, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 0)
(@OGUID+18, 190550, 571, 1, 1, 4971.439, -2966.859, 290.2518, 4.520406, 0, 0, 0, 1, 120, 255, 1), -- 190550 (Area: 4278)
(@OGUID+19, 190550, 571, 1, 1, 4928.226, -2954.833, 289.3405, 2.129301, 0, 0, 0, 1, 120, 255, 1); -- 190550 (Area: 0)

DELETE FROM `event_scripts` WHERE  `id`=4845 AND `delay`=0 AND `command`=9 AND `datalong`=21207 AND `datalong2`=66 AND `dataint`=0 AND `x`=0 AND `y`=0 AND `z`=0 AND `o`=0 LIMIT 1;
