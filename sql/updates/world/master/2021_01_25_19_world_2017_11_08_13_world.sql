-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (49625, 49634);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (43069, 43106);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 49625, 0, 0, 29, 0, 24087, 90, 0, 0, 0, 0, "", "Spell Brave's Flare can be used within 90 yards of Skorn Tower NW Bunny OR"),
(17, 0, 49625, 0, 1, 29, 0, 24092, 90, 0, 0, 0, 0, "", "Spell Brave's Flare can be used within 90 yards of Skorn Tower E Bunny OR"),
(17, 0, 49625, 0, 2, 29, 0, 24093, 90, 0, 0, 0, 0, "", "Spell Brave's Flare can be used within 90 yards of Skorn Tower SW Bunny OR"),
(17, 0, 49625, 0, 3, 29, 0, 24094, 90, 0, 0, 0, 0, "", "Spell Brave's Flare can be used within 90 yards of Skorn Tower SE Bunny"),
(17, 0, 49634, 0, 0, 29, 0, 24087, 90, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower NW Bunny OR"),
(17, 0, 49634, 0, 1, 29, 0, 24092, 90, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower E Bunny OR"),
(17, 0, 49634, 0, 2, 29, 0, 24093, 90, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower SW Bunny OR"),
(17, 0, 49634, 0, 3, 29, 0, 24094, 90, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower SE Bunny"),
(13, 1, 43069, 0, 0, 31, 0, 3, 23668, 0, 0, 0, 0, "", "Towers of Certain Doom: Skorn Cannonfire targets Winterskorn Rune-Caster OR"),
(13, 1, 43069, 0, 1, 31, 0, 3, 23667, 0, 0, 0, 0, "", "Towers of Certain Doom: Skorn Cannonfire targets Winterskorn Rune-Seer OR"),
(13, 1, 43069, 0, 2, 31, 0, 3, 23669, 0, 0, 0, 0, "", "Towers of Certain Doom: Skorn Cannonfire targets Winterskorn Oracle"),
(13, 1, 43106, 0, 0, 31, 0, 3, 24087, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower NW Bunny OR"),
(13, 1, 43106, 0, 1, 31, 0, 3, 24092, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower E Bunny OR"),
(13, 1, 43106, 0, 2, 31, 0, 3, 24093, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower SW Bunny OR"),
(13, 1, 43106, 0, 3, 31, 0, 3, 24094, 0, 0, 0, 0, "", "Spell Sergeant's Flare can be used within 90 yards of Skorn Tower SE Bunny");
