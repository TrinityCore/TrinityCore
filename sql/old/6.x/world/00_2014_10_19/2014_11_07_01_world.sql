SET @OGuid := 5513;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(25379,25761,25759);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(25379,25761,25759) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2575900 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25379, 0, 0, 0, 19, 0, 100, 0, 11711, 0, 0, 0, 85, 45963, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warden Nork Bloodfrenzy - On Quest Accept (Coward Delivery... Under 30 Minutes or its Free - Invoker Cast Call Alliance Deserter'),
(25379, 0, 1, 2, 62, 0, 100, 0, 9184, 0, 0, 0, 85, 45963, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warden Nork Bloodfrenzy - On Gossip Option 0 Selected - Invoker Cast Call Alliance Deserter'),
(25379, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warden Nork Bloodfrenzy - On Gossip Option 0 Selected - Close Gossip'),
(25379, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warden Nork Bloodfrenzy - On Gossip Option 0 Selected - Say'),
(25761, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 45957, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Alliance Deserter - On Just Summoned - Cast Escorting Alliance Deserter'),
(25761, 0, 1, 0, 8, 0, 100, 0, 45981, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Deserter - On Spellhit (Escorting Alliance Deserter) - Despawn'),
(25761, 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Deserter - On Spellhit (Escorting Alliance Deserter) - Despawn'),
(25759, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - On Just Summoned - Store Targetlist'),
(25759, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2575900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - On Just Summoned - Run Script'),
(2575900, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - Script - Say'),
(2575900, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, 45981, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - Script - Cast Escorting Alliance Deserter'),
(2575900, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 15,11711, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - Script - Complete quest'),
(2575900, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45,1, 1, 0, 0, 0, 0, 19, 25761, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - Script - Set Data on Alliance Deserter '),
(2575900, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Valiance Keep Officer - Script - Despawn');

DELETE FROM `creature_text` WHERE `entry` IN(25379,25759);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(25379, 0, 0, 'Try to not lose this one, $n. It is important that we at least try and keep up appearances with the Alliance.', 15, 1, 100, 0, 0, 0, 'Warden Nork Bloodfrenzy',24977),
(25759, 0, 0, 'Thank you, $r. I will take this miserable cur from you now.', 12, 1, 100, 1, 0, 0, 'Valiance Keep Officer',24966);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9184;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(9184, 0, 0, 'I am embarassed to say it, Nork, but my deserter has gone missing.', 24976, 1, 1, 0, 0, 0, 0, '', 0); -- 25379

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9184;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9184, 0, 0, 0,9, 0, 11711, 0, 0, 0, 0, 0, '', 'Warden Nork Bloodfrenzy - Show Gossip option only if player has Coward Delivery... Under 30 Minutes or its Free in quest log'),
(15, 9184, 0, 0, 0,1, 0, 45963, 0, 0, 1, 0, 0, '', 'Warden Nork Bloodfrenzy - Show Gossip option only if player does not have aura Call Alliance Deserter');

DELETE FROM `gameobject`  WHERE `id`=187894;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@OGuid, 187894, 571, 1, 1, 2942.86, 5381.48, 60.6052, 2.28369, 0, 0, 0.909402, 0.415919, 300, 0, 1, 0);

DELETE FROM `spell_scripts` WHERE `id`=45958;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(45958, 0, 0, 15, 45956, 0, 0, 0, 0, 0, 0);
