DELETE FROM `spell_script_target` WHERE entry IN (51859);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(51859, 1, 28525), -- siphon of archerus
(51859, 1, 28542),
(51859, 1, 28543),
(51859, 1, 28544);
UPDATE `creature_template` SET `spell5`=51890 WHERE `entry`=28511; -- Eye of Acherus flight
UPDATE `creature_template` SET `minlevel`=50,`maxlevel`=52,`minhealth`=2215,`maxhealth`=2317,`faction_A`=2084,`faction_H`=2084,`mindmg`=50,`maxdmg`=50 WHERE `entry`=28528; -- ghoul
