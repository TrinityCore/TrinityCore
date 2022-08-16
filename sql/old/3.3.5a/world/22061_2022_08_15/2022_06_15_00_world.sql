--
UPDATE `creature_template` SET `minlevel` = 64, `maxlevel` = 64 WHERE `entry` IN (18176,18177,18179);
UPDATE `creature_template` SET `minlevel` = 72, `maxlevel` = 72 WHERE `entry` IN (19897,19899,19900);
UPDATE `creature_template` SET `minlevel` = 1, `maxlevel` = 1 WHERE `entry` IN (20208,22322);

DELETE FROM `creature_template_addon` WHERE `entry` IN (18176,18179);

DELETE FROM `creature_template_spell` WHERE `CreatureID` IN (19897,19900,19899,22322);
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(19897,0,31982,12340),
(19900,0,31986,12340),
(19899,0,33134,12340),
(22322,0,38799,12340);

-- Casts nova when its aura kills him or when someone kills him, basically one event, one spell for both modes(scales with level)
-- No anim for some reason
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18179 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18179,0,0,0,6,0,100,0,0,0,0,0,0,11,33132,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Corrupted Nova Totem - On Death - Cast 'Fire Nova'");

UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 18177;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18177 AND `source_type` = 0;
