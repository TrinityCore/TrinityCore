UPDATE `creature_template` SET `AIName`='' WHERE  `entry`=18490;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=18490 AND `source_type`=0;
UPDATE `creature_template` SET `unit_flags`=536871680, `unit_flags2`=2049, `dynamicflags`=0 WHERE  `entry`=18490;
UPDATE `creature_template_addon` SET `auras`='29266 32423' WHERE  `entry`=18490;

DELETE FROM `spell_area` WHERE `spell`=32407;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(32407, 3674, 0, 0, 0, 0, 2, 1, 64, 11); 

UPDATE `smart_scripts` SET `action_param3`=1927115 WHERE  `entryorguid`=19271 AND `source_type`=0 AND `id`=13;
