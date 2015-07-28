UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=193188; -- Doodad_GunDrak_Trapdoor_01

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (57068,57071,57072,54988);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,57068,0,0,31,0,3,30298,127032,0,0, '', 'Cosmetic - Fire Beam Mammoth'),
(13,1,57071,0,0,31,0,3,30298,127035,0,0, '', 'Cosmetic - Fire Beam Snake'),
(13,1,57072,0,0,31,0,3,30298,127033,0,0, '', 'Cosmetic - Fire Beam Elemental'),
(13,1,54988,0,0,31,0,3,22517,0,0,0, '', 'Heart Beam Visual');

UPDATE `creature_addon` SET `auras`=NULL WHERE `guid`=127213;

UPDATE `creature_model_info` SET `bounding_radius`=0.3875, `combat_reach`=6.25 WHERE `modelid`=26278;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (54956,59827);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(54956,'spell_gal_darah_impaling_charge'),
(59827,'spell_gal_darah_impaling_charge');

DELETE FROM `creature_text` WHERE `entry` IN (29304, 29305, 29306, 29932, 29573);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(29304, 0, 0, 'Drakkari gonna kill anybody who tressspasss on these landsss!', 14, 0, 100, 0, 0, 14443, 31711, 'Slad''ran - Aggro'),
(29304, 1, 0, 'You not breathin''? Good.', 14, 0, 100, 0, 0, 14446, 31712, 'Slad''ran - Slay 1'),
(29304, 1, 1, 'Ssscared now?', 14, 0, 100, 0, 0, 14447, 31713, 'Slad''ran - Slay 2'),
(29304, 1, 2, 'I eat you next, mon.', 14, 0, 100, 0, 0, 14448, 31714, 'Slad''ran - Slay 3'),
(29304, 2, 0, 'I sssee now... Ssscourge wasss not... our greatessst enemy....', 14, 0, 100, 0, 0, 14449, 31715, 'Slad''ran - Death'),
(29304, 3, 0, 'Minionsss of the scale, heed my call!', 14, 0, 100, 0, 0, 14444, 30369, 'Slad''ran - Summon Snakes'),
(29304, 4, 0, 'A thousssand fangsss gonna rend your flesh!', 14, 0, 100, 0, 0, 14445, 30370, 'Slad''ran - Summon Constrictors'),
(29304, 5, 0, '%s begins to cast Poison Nova!', 41, 0, 100, 0, 0, 0, 30757, 'Slad''ran - Poison Nova'),
(29304, 6, 0, 'As %s falls, the altar set into the floor on his balcony begins to glow faintly.', 16, 0, 100, 0, 0, 0, 31199, 'Slad''ran - Activate Altar'),

(29305, 0, 0, 'We fought back da Scourge. What chance joo thinkin'' JOO got?', 14, 0, 100, 0, 0, 14721, 31427, 'Moorabi - Aggro'),
(29305, 1, 0, 'I crush joo cockroaches!', 14, 0, 100, 0, 0, 14725, 31430, 'Moorabi - Slay 1'),
(29305, 1, 1, 'Who gonna stop me? You?', 14, 0, 100, 0, 0, 14726, 31431, 'Moorabi - Slay 2'),
(29305, 1, 2, 'Not so tough now!!', 14, 0, 100, 0, 0, 14727, 31432, 'Moorabi - Slay 3'),
(29305, 2, 0, 'If our gods can die... den so can we....', 14, 0, 100, 0, 0, 14728, 31433, 'Moorabi - Death'),
(29305, 3, 0, 'Get ready for somethin''... much... BIGGAH!', 14, 0, 100, 0, 0, 14722, 31428, 'Moorabi - Transform'),
(29305, 4, 0, 'Da ground gonna swallow you up!', 14, 0, 100, 0, 0, 14723, 31429, 'Moorabi - Quake'),
(29305, 5, 0, '%s begins to transform!', 41, 0, 100, 0, 0, 0, 30385, 'Moorabi - Begin Transform'),
(29305, 6, 0, '%s transforms into a Mammoth!', 16, 0, 100, 0, 0, 0, 30388, 'Moorabi - Transformed'),
(29305, 7, 0, 'As %s falls, the altar set into the floor on his balcony begins to glow faintly.', 16, 0, 100, 0, 0, 0, 31199, 'Moorabi - Activate Altar'),

(29306, 0, 0, 'I''m gonna spill your guts, mon!', 14, 0, 100, 0, 0, 14430, 32534, 'Gal''darah - Aggro'),
(29306, 1, 0, 'What a rush!', 14, 0, 100, 0, 0, 14436, 32540, 'Gal''darah - Slay 1'),
(29306, 1, 1, 'Who needs gods when we ARE gods?', 14, 0, 100, 0, 0, 14437, 32541, 'Gal''darah - Slay 2'),
(29306, 1, 2, 'I told ya so!', 14, 0, 100, 0, 0, 14438, 32542, 'Gal''darah - Slay 3'),
(29306, 2, 0, 'Even the mighty... can fall.', 14, 0, 100, 0, 0, 14439, 32543, 'Gal''darah - Death'),
(29306, 3, 0, 'Gut them! Impale them!', 14, 0, 100, 0, 0, 14433, 32537, 'Gal''darah - Summon Rhino 1'),
(29306, 3, 1, 'KILL THEM ALL!', 14, 0, 100, 0, 0, 14434, 32538, 'Gal''darah - Summon Rhino 2'),
(29306, 3, 2, 'Say hello to my BIG friend!', 14, 0, 100, 0, 0, 14435, 32539, 'Gal''darah - Summon Rhino 3'),
(29306, 4, 0, 'Ain''t gonna be nothin'' left after this!', 14, 0, 100, 0, 0, 14431, 32535, 'Gal''darah - Transform 1'),
(29306, 5, 0, 'You wanna see power? I''m gonna show you power!', 14, 0, 100, 0, 0, 14432, 32536, 'Gal''darah - Transform 2'),
(29306, 6, 0, '$n is impaled!', 41, 0, 100, 0, 0, 0, 30718, 'Gal''darah - Impale'),

(29932, 0, 0, 'Something stirs in the pool of mojo...', 16, 0, 100, 0, 0, 0, 30740, 'Eck the Ferocious'),

(29573, 0, 0, '%s gathers its mojo and surges forward!', 16, 0, 100, 0, 0, 0, 30717, 'Drakkari Elemental - Mojo'),
(29573, 1, 0, 'As the last remnants of the %s seep into the ground, the altar set into the floor nearby begins to glow faintly.', 16, 0, 100, 0, 0, 0, 31226, 'Drakkari Elemental - Death');
