
UPDATE `instance_template` SET `script`= 'instance_iron_docks' WHERE `map`= 1195;
-- Skulloc
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `vehicleId`= 3808, `scriptname`= 'boss_skulloc' WHERE `entry`= 83612; -- 3808 1631
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `unit_flags`= 33554496, `unit_flags2`= 1073874944, `flags_extra`= 0 WHERE `entry` IN (84109, 84030);
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `unit_flags`= 33554432, `unit_flags2`= 2048, `flags_extra`= 128, `InhabitType`= 4 WHERE `entry` = 84464;

-- Koramar
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `scriptname`= 'boss_koramar' WHERE `entry`= 83613;

-- Zoggosh
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `scriptname`= 'boss_zoggosh' WHERE `entry`= 83616;

-- Blackhands Might Cannon
UPDATE `creature_template` SET `minlevel`= 95, `maxlevel`= 95, `faction`= 14, `exp`= 5, `unit_flags`= 33554496, `unit_flags2`= 1073741824 WHERE `entry`= 84215;



DELETE FROM `creature_text` WHERE `entry` IN (83612, 83613, 83616);
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
-- Skulloc
(83612, 0, 0, '%s prepares a |cFFFF0404|Hspell:168148|h[Cannon Barrage]|h|r! Get behind cover to survive!', 41, 0, 100, 0, 0, 0, '90484', 'Skulloc - Cannon Barrage'),
-- Koramar
(83613, 1, 0, 'Hah. Would you look at that. Maybe I... underestimated them. Zoggosh! Prepare Skulloc! Let them have a taste of what he has to offer.', 14, 0, 100, 6, 0, 43902, '85909', 'Koramar to Player'),
-- Zoggosh
(83616, 1, 0, 'Igniting the cannons, sir!', 14, 0, 100, 6, 0, 44051, '85928', 'Zoggosh to Player');


REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(168227, 'spell_skulloc_gronn_smash'),
(168929, 'spell_skulloc_cannon_barrage_channel_aura'),
(168129, 'spell_skulloc_cannon_barrage_cannon_aura'),
(169131, 'spell_skulloc_backdraft_dummy'),
(168390, 'spell_skulloc_cannon_barrage_aoe');


REPLACE INTO `spell_target_position`(`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(168167, 2, 1195, 6857.7, -990.11, 23.3);

REPLACE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(83612, 84109, 0, 1, 'Skulloc - Cannon', 7, 0),
(83612, 84030, 1, 1, 'Skulloc - Cannon', 7, 0);

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(83612, 77901, 0);

DELETE FROM `conditions` WHERE `SourceEntry` IN (169131);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 7, 169131, 0, 0, 31, 0, 3, 84464, 0, 0, 0, '', 'Backdraft target Backdraft');

REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(10145, 'at_iron_docks_gauntlet_2');

