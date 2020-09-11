-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (69683);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 69683, 0, 24, 1, 8, 0, 0, 0, '', "Mini K. T. (passif) Find Target hits only critters");

DELETE FROM `creature_template_addon` WHERE `entry` = 36979;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36979, 0, 0, 0, 0, 0, '69683 70050');

DELETE FROM `spell_scripts` WHERE `id` IN (69682,69731);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(69682 ,0,0,15,69681,0,0,0,0,0,0),
(69682 ,0,3,1,451,0,0,0,0,0,0),
(69682 ,0,3,16,16493,0,0,0,0,0,0),
(69731 ,0,0,1,402,0,0,0,0,0,0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 70049;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(70049, 69731, 0, 'Lich Pet emote');

-- To do: when the pet is summoned the player get the aura 69732 (the aura is added and removed by "Lich Pet Aura Remove"=69736 and "Lich Pet OnSummon"=69735)
-- The spell 69732 has the proc flag= 2 (0x2) - "Kill that yields experience or honor"  when it procs it must trigger a cast of 69731 on/from the pet
