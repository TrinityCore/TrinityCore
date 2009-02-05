DELETE FROM gameobject_template WHERE `entry` IN (187578, 188173);
INSERT INTO gameobject_template () VALUES (187578, 10, 4891, 'Scrying Orb', '', 0, 0, 2.16851, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_movie_orb');
INSERT INTO gameobject_template () VALUES (188173, 10, 7161, 'Escape to the Isle of Quel\'Danas', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_kael_orb');

DELETE FROM spell_script_target WHERE `entry` IN (44320, 44321);
INSERT INTO spell_script_target () VALUES (44320, 1, 24723);
INSERT INTO spell_script_target () VALUES (44321, 1, 24723);

UPDATE creature_template SET modelid_A = '17612' WHERE entry = '24745';
UPDATE creature_template SET modelid_H = '17612' WHERE entry = '24745';

UPDATE `creature_template` SET `minhealth` = '6900' WHERE `entry` = 24675;
UPDATE `creature_template` SET `maxhealth` = '6900' WHERE `entry` = 24675;

UPDATE `creature_template` SET `minlevel` = '70' WHERE `entry` = 24708;
UPDATE `creature_template` SET `maxlevel` = '70' WHERE `entry` = 24708;

UPDATE `creature_template` SET `minlevel` = '70' WHERE `entry` = 24666;
UPDATE `creature_template` SET `maxlevel` = '70' WHERE `entry` = 24666;

UPDATE `creature_template` SET `scale` = '0.5' WHERE `entry` = 24708;

UPDATE `gameobject_template` SET `ScriptName` = 'go_kael_orb' WHERE `entry` = 188173;
UPDATE `gameobject_template` SET `ScriptName` = 'go_movie_orb' WHERE `entry` = 187578;

update creature_template SET spell1=6474 WHERE entry=22487;
update creature_template SET spell1=3600 WHERE entry=22486;