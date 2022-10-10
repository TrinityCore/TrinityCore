delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (116711,118071,115740,115741,115742,115743,117736);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 4, 116711, 0, 0, 31, 0, 3, 60438, 0, 0, 0, '', NULL),
(13, 1, 118071, 0, 0, 31, 0, 3, 60009, 0, 0, 0, '', NULL),
(13, 15, 115740, 0, 0, 31, 0, 3, 60009, 0, 0, 0, '', NULL),
(13, 15, 115741, 0, 0, 31, 0, 3, 60009, 0, 0, 0, '', NULL),
(13, 15, 115742, 0, 0, 31, 0, 3, 60009, 0, 0, 0, '', NULL),
(13, 15, 115743, 0, 0, 31, 0, 3, 60009, 0, 0, 0, '', NULL),
(13, 1, 117736, 0, 0, 31, 0, 3, 60627, 0, 0, 0, '', NULL);

delete from spell_target_filter where spellid in (118530,116784,132301,117716);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(118530, 15, 0, 0, 0, 0, 0, 0, 1, 1, 3, 8, 0, 0, 'Fen: Spirit Bolt'),
(116784, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Wildfire Spark'),
(132301, 15, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 'Amethyst Pool'),
(117716, 15, 0, 0, 0, 0, 0, 0, 1, 1, 5, 10, 0, 0, 'Siphoning Shield');

delete from spell_dummy_trigger where spell_id in (132301);
INSERT INTO `spell_dummy_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(132301, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 'Amethyst Pool');

delete from spell_linked_spell where spell_trigger in (115811,115972);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastype`, `hastalent`, `hastype2`, `hastalent2`, `chance`, `cooldown`, `duration`, `hitmask`, `removeMask`, `targetCountType`, `targetCount`, `actiontype`, `group`, `comment`) VALUES 
(115811, -115972, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 'Ap Nullification Barrier - Remove Shroud of Reversal'),
(115972, -115811, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 'Ap Shroud of Reversa - Remove Nullification Barrier');

delete from areatrigger_actions where entry in (465,229);
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) VALUES 
(465, 0, 1, 0, 4096, 130774, 0, 0, 0, 0, 0, 0, 0, 'Amethyst Pool Apply'),
(465, 1, 42, 1, 4096, 130774, 0, 0, 0, 0, 0, 0, 0, 'Amethyst Pool Remove'),
(229, 0, 1, 0, 8, 115856, 0, 0, 0, 0, 0, 0, 0, '115817 - Nullification Barrier - cast 115856 on owner player enter'),
(229, 1, 42, 1, 8, 115856, 0, 0, 0, 0, 0, 0, 0, '115817 - Nullification Barrier - remove 115856 on owner player leave');

update gameobject set state = 1 where id = 213247;
delete from gameobject where id in (211626,211628);

update creature_template set modelid2 = 0, modelid2 = 0, flags_extra = 128 where entry = 60241;
update creature_template set modelid2 = 0, modelid2 = 0, modelid3 = 0, minlevel = 93, maxlevel = 93, exp = 4, flags_extra = 128 where entry = 60438;
update creature_template set minlevel = 92, maxlevel = 92, faction = 14, speed_run = 0.5, npcflag = 0, ScriptName = 'npc_feng_soul_fragment' where entry = 60781;
update creature_template set modelid2 = 0, minlevel = 92, maxlevel = 92, faction = 14, npcflag = 0, unit_flags = 768, flags_extra = 128 where entry = 60627;

update gameobject_template set ScriptName = 'go_stolen_essences_of_stone' where entry in (211626,211628);
