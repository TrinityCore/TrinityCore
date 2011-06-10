-- Delete disabled achievements
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN(10074,10075,10220,10221,10077,10079);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN(10074,10075,10220,10221,10077,10079);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`ScriptName`) VALUES
-- Nerf Engineering 10m
(10074,11,0,'achievement_nerf_engineering'),
(10074,12,0,''),
-- Nerf Engineering 25m
(10075,11,0,'achievement_nerf_engineering'),
(10075,12,1,''),
-- Heartbreaker 10m
(10221,11,0,'achievement_heartbreaker'),
(10221,12,0,''),
-- Heartbreaker 25m
(10220,11,0,'achievement_heartbreaker'),
(10220,12,1,''),
-- Nerf Gravity Bombs 10m
(10077,11,0,'achievement_nerf_gravity_bombs'),
(10077,12,0,''),
-- Nerf Gravity Bombs 25m
(10079,11,0,'achievement_nerf_gravity_bombs'),
(10079,12,1,'');

DELETE FROM `spell_script_names` WHERE `spell_id` IN(64233,63025);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64233,'spell_xt002_gravity_bomb_damage'),
(63025,'spell_xt002_gravity_bomb_damage');

-- Better naming for changed script with new functionality
UPDATE `spell_script_names` SET `ScriptName`='spell_xt002_gravity_bomb_aura' WHERE `spell_id` IN(64234,63024)