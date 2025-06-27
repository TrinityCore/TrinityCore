-- 
DELETE FROM `spell_custom_attr` WHERE `entry` IN (37320,37221,37322,37323);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(37320, 4096),(37221, 4096),(37322, 4096),(37323, 4096);
-- Dullgrom Dredger Cosmetic Aura
UPDATE `creature_template_addon` SET `auras` = '36661' WHERE `entry` = 21254;
UPDATE `creature_addon` SET `auras` = '36661' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 21254);

-- Dullgrom Dredger SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 21254;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21254 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21254, 0, 0, 0, 13, 0, 100, 0, 19000, 24000, 0, 0, 0, 11, 34802, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - Target Casting - Cast 'Kick'"),
(21254, 0, 1, 0, 2, 0, 100, 1, 0, 30, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - Between 0-30% Health - Cast 'Enrage'"),
(21254, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 28, 36661, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - IC - Remove Confused Ogre"),
(21254, 0, 3, 4, 29, 0, 100, 512, 0, 0, 0, 0, 0, 28, 36661, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - On charmed - Remove Confused Ogre"),
(21254, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - On charmed - Emote state none"),
(21254, 0, 5, 0, 1, 0, 100, 0, 40000, 120000, 100000, 240000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - OOC - Text"),
(21254, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Dullgrom Dredger - On aggro - Say Text");

-- Vekh'nir Stormcaller SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 19983;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19983 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19983, 0, 0, 0, 0, 0, 100, 0, 8000, 12000, 20000, 24000, 0, 11, 32717, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Vekh'nir Stormcaller - In Combat - Cast 'Hurricane'"),
(19983, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 12000, 12000, 0, 11, 37654, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Vekh'nir Stormcaller - In Combat - Cast 'Lightning Tether'"),
(19983, 0, 2, 0, 1, 0, 100, 0, 40000, 120000, 100000, 240000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Vekh'nir Stormcaller - OOC - Text");

-- Vekh SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22305;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22305 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22305, 0, 0, 0, 0, 0, 100, 0, 8000, 12000, 10000, 15000, 0, 11, 37582, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Vekh - In Combat - Cast 'whirlwind'"),
(22305, 0, 1, 0, 2, 0, 100, 0, 1, 30, 10000, 15000, 0, 11, 11642, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Vekh - Health pct - Cast 'Heal'");

DELETE FROM `creature_text` WHERE `CreatureID` IN (19983, 21254);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `Comment`, `BroadcastTextId`) VALUES
(21254, 0, 0, "Me promise be good...", 14, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 19037),
(21254, 0, 1, "Me no want to die.", 14, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 19038),
(21254, 0, 2, "Me sorry...", 14, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 19039),
(21254, 0, 3, "Me sorry little birdy!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18851),
(21254, 0, 4, "Bird, you hurting me!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18852),
(21254, 0, 5, "ARGH!!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18853),
(21254, 0, 6, "Why you keep hurting me? Me said me sorry...", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18854),
(21254, 0, 7, "Me DO whatever birdy want. Just STOP the hurting.", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18855),
(21254, 0, 8, "Me NO can think RIGHT anymore!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 18857),
(21254, 1, 0, "Bird spell not working. Me is free!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 19030),
(21254, 1, 1, "I'll crush you!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 1925),
(21254, 1, 2, "Me smash! You die!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 1926),
(21254, 1, 3, "Raaar!!! Me smash $r!", 12, 0, 100, 0, 0, 0, 'Dullgrom Dredger', 1927),
(19983, 0, 0, "Stupid ogre. You all need to be taught a lesson.", 12, 0, 100, 0, 0, 0, "Vekh'nir Stormcaller", 19032),
(19983, 0, 1, "If freedom is what you seek, freedom is what you shall find.", 12, 0, 100, 0, 0, 0, "Vekh'nir Stormcaller", 19033),
(19983, 0, 2, "You ogres are disposable.  That being said, it is time to take out the garbage.", 12, 0, 100, 0, 0, 0, "Vekh'nir Stormcaller", 19034),
(19983, 0, 3, "I tire of these ogres. We should wipe them out, all of them.", 12, 0, 100, 0, 0, 0, "Vekh'nir Stormcaller", 19035),
(19983, 0, 5, "Do any of you other ogres want to join your friend?", 12, 0, 100, 0, 0, 0, "Vekh'nir Stormcaller", 19036);

-- Conditions for Trial and Error (10566)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (37221,37320,37322,37323);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,37221,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37320,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37322,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37323,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'");
