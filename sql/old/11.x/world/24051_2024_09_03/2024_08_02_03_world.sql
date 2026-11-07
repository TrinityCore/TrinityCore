-- Instasnce
DELETE FROM `instance_template` WHERE `map`=1763;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1763, 0, 'instance_atal_dazar');

-- Creature
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.40000009536743164, `speed_run`=1.285714268684387207, `BaseAttackTime`=1500, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=67633152, `AIName`='SmartAI' WHERE `entry`=129517; -- Reanimated Raptor
UPDATE `creature_template` SET `unit_flags2`=2048, `ScriptName`='boss_rezan' WHERE `entry`=122963; -- Rezan

DELETE FROM `creature_template_addon` WHERE `entry` = 129517;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(129517, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 129517 (Reanimated Raptor)

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (255372, 255421, 257407, 258344, 255600, 255371);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(255372, 'spell_rezan_tail_selector'),
(255421, 'spell_rezan_devour'),
(257407, 'spell_rezan_pursuit'),
(258344, 'spell_gen_reverse_cast_target_to_caster_triggered'),
(255600, 'spell_rezan_boss_emote_at_target'),
(255371, 'spell_rezan_terrifying_visage');

-- Areatriggers
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_rezan_pile_of_bones_spawn_raptor' WHERE `Id`=11959 AND `IsCustom`=0;
UPDATE `areatrigger_create_properties` SET `ScriptName`='at_rezan_pile_of_bones_slow' WHERE `Id`=11958 AND `IsCustom`=0;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 122963;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(122963, 0, 0, 'The restless bones come to life as a Reanimated Raptor!', 41, 0, 100, 0, 0, 0, 141130, 0, 'Rezan'),
(122963, 1, 0, '$n awakens a pile of bones!', 16, 0, 100, 0, 0, 0, 141075, 0, 'Rezan to Rezan'),
(122963, 2, 0, '|TInterface\\Icons\\ABILITY_DEVOUR.BLP:20|tRezan uses his |cFFFF0000|Hspell:255371|h[Terrifying Visage]|h|r, hide!', 41, 0, 100, 0, 0, 0, 141155, 0, 'Rezan to Rezan'),
(122963, 3, 0, 'Rezan sets his sights on $n to |TInterface\Icons\ABILITY_MOUNT_FOSSILIZEDRAPTOR.BLP:20|t|cFFFF0000|Hspell:255421|h[Devour]|h|r them!', 42, 0, 100, 0, 0, 0, 138730, 0, 'Rezan to Player');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=129517 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12951700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(129517, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, 12951700, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Reanimated Raptor - On just created - Cast self 256633'),
(12951700, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 256633, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Reanimated Raptor - Action list - Cast self 256633'),
(12951700, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 28, 256633, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Reanimated Raptor - Action list - Remove aura 256633'),
(12951700, 9, 2, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 0, '', 144, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Reanimated Raptor - Action list - Remove immune to pc'),
(12951700, 9, 3, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 145, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Reanimated Raptor - Action list - Remove immune to npc');

UPDATE `creature_template_difficulty` SET `StaticFlags1`=`StaticFlags1`|0x00080000 WHERE `Entry` IN(122963, 129517); -- add amphibious flag to Rezan and Raptors, evades in water otherwise // hack
