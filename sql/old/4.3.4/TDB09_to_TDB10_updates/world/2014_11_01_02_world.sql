    UPDATE `smart_scripts` SET `event_type`=25 WHERE  `entryorguid`=29717 AND `source_type`=0 AND `id`=0 AND `link`=0;

    UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN(31119,30952,30951,31131,30951);

    DELETE FROM `smart_scripts` WHERE `entryorguid`IN(31110,31119,30952,3095200,31131,3113100,30951);
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (31110, 0, 0, 0, 54, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Just Summoned - Cast Ethereal'),
    (31110, 0, 1, 0, 27, 0, 100, 1, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Boarded - Cast Ethereal'),
    (31110, 0, 2, 0, 28, 0, 100, 1, 0, 0, 0, 0, 28, 58548, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Passenger Removed - Remove Ethereal'),
    (31110, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 58548, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eidolon Watcher - On Reset - Cast Ethereal'),
    (31119, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Store Targetlist'),
    (31119, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 30952, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Just Summoned - Set Data on Hungering Plaguehound'),
    (31119, 0, 2, 3, 38, 0, 100, 1, 1, 1, 0, 0, 11, 58564, 2, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Give Kill Credit'),
    (31119, 0, 3, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloody Meat - On Data Set - Despawn'),
    (30952, 0, 0, 0, 75, 0, 100, 0, 0, 31119, 20, 15000, 80, 3095200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - On Bloody Meat within 20 yards - Run Script'),
    (30951, 0, 0, 0, 8, 0, 100, 0, 45254, 0, 0, 0, 33, 30951, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Restless Lookout - On Spellhit - Killcredit'),
    (31131, 0, 0, 0, 8, 0, 100, 0, 58662, 0, 300000, 300000, 80, 3113100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - On Spellhit - Run Script'),
    (3113100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 31131, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Kill Credit'),
    (3113100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Set Bytes 1'),
    (3113100, 9, 2, 0, 0, 0, 100, 0, 300000, 300000, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Containment Crystal - Script - Remove Bytes 1'),
    (3095200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Disable Random Move'),
    (3095200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
    (3095200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 31119, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Move to Bloodymeat'),
    (3095200, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Evade'),
    (3095200, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungering Plaguehound - Script - Enable Random Move');

    DELETE FROM `spell_linked_spell` WHERE `spell_trigger`IN(-58563);
    INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
    (-58563, 45254, 0,'Assasinate Restless Lookout triggers Suicide');
