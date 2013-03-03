update creature_template set spell1=53117 where entry=29104;
update creature_template set spell1=53348,killcredit1=29150 where entry IN (29102,29103);
update creature_template set scriptname="mob_anti_air" where entry in (29102,29103,29104);


DELETE FROM `spell_script_target` WHERE entry IN
(53110);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(53110, 1, 29102),
(53110, 1, 29103); -- Devour Humanoid
