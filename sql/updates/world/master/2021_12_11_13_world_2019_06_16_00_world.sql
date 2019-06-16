-- 
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (26477, 28202, 28203, 29856);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(26477, 61832, 1, 0),
(28202, 50926, 1, 0),
(28203, 50918, 1, 0),
(29856, 55364, 1, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26477, 28202, 28203, 29856) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26477,0,0,0, 8,0,100,1,61832,0,0,0,11,47096,3,0,0,0,0,7,0,0,0,0,0,0,0,"Dead Mage Hunter - On Spellhit 'Rifle the Bodies: Create Magehunter Personal Effects Cover' - Cast `Rifle the Bodies: Create Mage Hunter Personal Effects`"),
(26477,0,1,0,31,0,100,1,47096,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dead Mage Hunter - On Spellhit target 'Rifle the Bodies: Create Magehunter Personal Effects' - Despawn Instant"),
(28202,0,0,0, 8,0,100,1,50926,0,0,0,11,50927,3,0,0,0,0,7,0,0,0,0,0,0,0,"Zul'Drak Rat - On Spellhit 'Gluttonous Lurkers: Create Zul'Drak Rat Cover' - Cast `Create Zul'Drak Rat`"),
(28202,0,1,0,31,0,100,1,50927,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'Drak Rat - On Spellhit target 'Create Zul'Drak Rat' - Despawn Instant"),
(28203,0,0,0, 8,0,100,1,50918,0,0,0,11,50919,3,0,0,0,0,7,0,0,0,0,0,0,0,"Gorged Lurking Basilisk - On Spellhit 'Gluttonous Lurkers: Create Basilisk Crystals Cover' - Cast `Create Basilisk Crystals`)"),
(28203,0,1,0,31,0,100,1,50919,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorged Lurking Basilisk - On Spellhit target 'Create Basilisk Crystals' - Despawn Instant"),
(29856,0,0,0, 8,0,100,1,55364,0,0,0,11,55363,3,0,0,0,0,7,0,0,0,0,0,0,0,"Gooey Ghoul Drool - On Spellhit 'Create Ghoul Drool Cover' - Cast `Create Gooey Ghoul Drool`"),
(29856,0,1,0,31,0,100,1,55363,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gooey Ghoul Drool - On Spellhit target 'Create Gooey Ghoul Drool' - Despawn Instant");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` IN (26477, 28202, 28203, 29856);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 26477, 61832, 0, 0, 9, 0, 11999, 0, 0, 0, 0, 0, "", "spellclick 'Rifle the Bodies: Create Magehunter Personal Effects Cover' requires quest 'Rifle the Bodies (H)' active"),
(18, 26477, 61832, 0, 1, 9, 0, 12000, 0, 0, 0, 0, 0, "", "spellclick 'Rifle the Bodies: Create Magehunter Personal Effects Cover' requires quest 'Rifle the Bodies (A)' active"),
(18, 28202, 50926, 0, 0, 9, 0, 12527, 0, 0, 0, 0, 0, "", "spellclick 'Gluttonous Lurkers: Create Zul'Drak Rat Cover' requires quest 'Gluttonous Lurkers' active"),
(18, 28203, 50918, 0, 0, 9, 0, 12527, 0, 0, 0, 0, 0, "", "spellclick 'Gluttonous Lurkers: Create Basilisk Crystals Cover' requires quest 'Gluttonous Lurkers' active"),
(18, 29856, 55364, 0, 0, 9, 0, 12629, 0, 0, 0, 0, 0, "", "spellclick 'Create Ghoul Drool Cover' requires quest 'You Can Run, But You Can't Hide' active"),
(18, 29856, 55364, 0, 0, 2, 0, 38687, 5, 0, 1, 0, 0, "", "spellclick 'Create Ghoul Drool Cover' requires not 5 Gooey Ghoul Drool in bags"),
(18, 29856, 55364, 0, 1, 9, 0, 12643, 0, 0, 0, 0, 0, "", "spellclick 'Create Ghoul Drool Cover' requires quest 'Silver Lining' active"),
(18, 29856, 55364, 0, 1, 2, 0, 38687, 5, 0, 1, 0, 0, "", "spellclick 'Create Ghoul Drool Cover' requires not 5 Gooey Ghoul Drool in bags");


UPDATE `creature_template` SET `unit_flags`=0 WHERE `entry` IN (26477);
UPDATE `creature_template_addon` SET `auras`="29266"  WHERE `entry` IN (26477);
DELETE FROM `creature_template_addon` WHERE `entry` = 28203;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(28203, 0, 0, 0, 4097, 0, '50917');
