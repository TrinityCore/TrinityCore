    UPDATE `creature_template` SET `gossip_menu_id`=10948, `npcflag`=3, `AIName`='SmartAI' WHERE `entry` IN(38045,38044,38043,38042,38041,38040,38039,37887);

    DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (38045,38044,38043,38042,38041,38040,38039,37887);

    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (38045, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38045, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38044, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38044, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38043, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38043, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38042, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38042, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38041, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38041, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38040, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38040, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (38039, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (38039, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip'),
    (37887, 0, 0, 1, 62, 0, 100, 0, 10948, 0, 0, 0, 11, 70648, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Cast Create Lovely Charm Collectors Kit'),
    (37887, 0, 1, 0, 61, 0, 100, 0, 10948, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kwee Q. Peddlefeet - On Gossip Option Select - Close Gossip');
