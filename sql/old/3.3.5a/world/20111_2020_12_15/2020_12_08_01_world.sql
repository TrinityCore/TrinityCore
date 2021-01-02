-- First we have to unassign generic training dummy script from creatures which
-- actually are not training dummies and apply few fixes while at it
UPDATE `creature_model_info` SET `BoundingRadius` = 2, `CombatReach` = 2 WHERE `DisplayID` = 16011;

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 12426;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(12426,1,0,0,1,0,0);

UPDATE `creature_template` SET `minlevel` = 20, `maxlevel` = 20, `speed_walk` = 1, `speed_run` = 1, `RangeAttackTime` = 2000, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 2673;
UPDATE `creature_template` SET `minlevel` = 40, `maxlevel` = 40, `speed_run` = 1, `RangeAttackTime` = 2000, `unit_flags` = 0, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 2674;
UPDATE `creature_template` SET `minlevel` = 55, `maxlevel` = 55, `speed_walk` = 1, `speed_run` = 1, `RangeAttackTime` = 2000, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 12426;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 16111;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2673,2674,12426,16111) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2673,0,0,0,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Target Dummy - On Just Summoned - Set Reactstate Passive"),
(16111,0,0,0,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Love Fool - On Just Summoned - Set Reactstate Passive"),
(2674,0,0,0,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Advanced Target Dummy - On Just Summoned - Set Reactstate Passive"),
(12426,0,0,0,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Masterwork Target Dummy - On Just Summoned - Set Reactstate Passive");

-- Next remove already added flag from Hellfire Training Dummy and engineering dummies
-- Hellfire Training Dummy even cannot be attacked by players and does not have that flag in CreatureDifficulty
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 0x00040000 WHERE `entry` IN (2673,2674,16111,17578);

-- Apply to all of them
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00040000 WHERE `entry` IN
(397, -- Morganth
4952, -- Theramore Combat Dummy
7666, -- Archmage Allistarj
7668, -- Servant of Razelikh
7669, -- Servant of Grol
7670, -- Servant of Allistarj
7671, -- Servant of Sevine
11446, -- Gordok Spirit
16478, -- Lieutenant Orrin
16484, -- Lieutenant Nevell
16490, -- Lieutenant Lisande
16493, -- Lieutenant Dagel
16494, -- Lieutenant Rukag
16495, -- Lieutenant Beitha
18731, -- Ambassador Hellmaw
20284, -- Dr. Boom
20636, -- Ambassador Hellmaw (1)
21416, -- Lakaan
21506, -- Azaloth
21709, -- Eykenen
21710, -- Uylaru
21711, -- Haalum
24792, -- Advanced Training Dummy
27355, -- Rothin the Decaying
27461, -- Bambina
27485, -- Vengeful Bambina
28017, -- Bloodworm
28659, -- Artruis the Heartless
28712, -- Basic Loot Pinata
28720, -- First Aid Loot Pinata
28781, -- Battleground Demolisher
29441, -- Lieutenant Julek
29442, -- Lieutenant Kregor
31012, -- Iceskin Sentry
31144, -- Grandmaster's Training Dummy
31146, -- Heroic Training Dummy
31324, -- Iceskin Sentry
31744, -- Cooking Loot Pinata
32541, -- Initiate's Training Dummy
32542, -- Disciple's Training Dummy
32543, -- Veteran's Training Dummy
32545, -- Initiate's Training Dummy
32546, -- Ebon Knight's Training Dummy
32547, -- Highlord's Nemesis Trainer
32666, -- Expert's Training Dummy
32667, -- Master's Training Dummy
32796, -- Battleground Demolisher (1)
33229, -- Melee Target
33243, -- Ranged Target
33272, -- Charge Target
33568, -- Fish
34444, -- Thrakgar
34445, -- Liandra Suncaller
34447, -- Caiphus the Stern
34459, -- Erin Misthoof
34465, -- Velanaa
34466, -- Anthar Forgemender
34469, -- Melador Valestrider
34470, -- Saamul
34632, -- Ogre Pinata
34775, -- Demolisher
34776, -- Siege Engine
34793, -- Catapult
34802, -- Glaive Thrower
35069, -- Siege Engine
35273, -- Glaive Thrower
35413, -- Catapult (1)
35415, -- Demolisher (1)
35419, -- Glaive Thrower (1)
35421, -- Glaive Thrower (1)
35431, -- Siege Engine (1)
35433, -- Siege Engine (1)
35665, -- Anthar Forgemender (1)
35666, -- Anthar Forgemender (2)
35667, -- Anthar Forgemender (3)
35683, -- Caiphus the Stern (1)
35684, -- Caiphus the Stern (2)
35685, -- Caiphus the Stern (3)
35686, -- Erin Misthoof (1)
35687, -- Erin Misthoof (2)
35688, -- Erin Misthoof (3)
35705, -- Liandra Suncaller (1)
35706, -- Liandra Suncaller (2)
35707, -- Liandra Suncaller (3)
35714, -- Melador Valestrider (1)
35715, -- Melador Valestrider (2)
35716, -- Melador Valestrider (3)
35728, -- Saamul (1)
35729, -- Saamul (2)
35730, -- Saamul (3)
35740, -- Thrakgar (1)
35741, -- Thrakgar (2)
35742, -- Thrakgar (3)
35746, -- Velanaa (1)
35747, -- Velanaa (2)
35748, -- Velanaa (3)
36954, -- The Lich King
38857); -- PattyMacks LK
