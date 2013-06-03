DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q14112_14145_chum_the_water';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(66741,'spell_q14112_14145_chum_the_water');

-- Template updates for creature 35071 (North Sea Mako)
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`InhabitType`=`InhabitType`&~1 WHERE `entry` IN (35071,35060,35061); -- North Sea * (Last 2 entries guessed)
UPDATE `creature_template` SET `faction_A`=1885,`faction_H`=1885,`baseattacktime`=2000 WHERE `entry`=35072; -- Angry Kvaldir
-- Addon data for creature 35071 (North Sea Mako)
DELETE FROM `creature_template_addon` WHERE `entry` IN (35071,35072,35060,35061);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35071,0,0,1,0, NULL), -- North Sea Mako
(35060,0,0,1,0, NULL), -- North Sea Thresher - guessed
(35061,0,0,1,0, NULL), -- North Sea Blue Shark - guessed
(35072,0,0,1,0, NULL); -- Angry Kvaldir
