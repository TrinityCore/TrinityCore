UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 40925;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (255117, 255119, 255120, 255115);
UPDATE `creature` SET `MovementType`= 0, `spawndist`= 0 WHERE `guid` IN (255021, 255022, 255023, 255019);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_tott_shock_defense';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86611, 'spell_tott_shock_defense'),
(86613, 'spell_tott_shock_defense'),
(86614, 'spell_tott_shock_defense');
