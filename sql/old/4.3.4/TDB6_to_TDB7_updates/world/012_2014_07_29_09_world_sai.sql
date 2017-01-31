UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` IN(16196,16183, 15951);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(16196,16183, 15951) and `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16183, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Courier Dawnstrider - On Data Set  - Remove Bytes 1'),
(16183, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Courier Dawnstrider - On Data Set  - Set Bytes 1'),
(16196, 0, 0, 1, 20, 0, 100, 0, 9147, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 16183, 0, 0, 0, 0, 0, 0, 'Apothecary Thedra - On Quest Reward (The Fallen Courier)  - Set Data 1 1 on Courier Dawnstrider'),
(16196, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 7000, 0, 0, 0, 0, 19, 16183, 0, 0, 0, 0, 0, 0, 'Apothecary Thedra - Linked with Previous Event  - Say Line 1 on Courier Dawnstrider'),
(16196, 0, 2, 3, 52, 0, 100, 0, 0, 16183, 0, 0, 45, 2, 2, 0, 0, 0, 0, 19, 16183, 0, 0, 0, 0, 0, 0, 'Apothecary Thedra - On Text Over  - Set Data 2 2 on Courier Dawnstrider'),
(16196, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Apothecary Thedra - Linked with Previous Event  - Say Line 1'),
(15951, 0, 0, 1, 20, 0, 100, 0, 8891, 0, 0, 0, 50, 181012, 4000, 0, 0, 0, 0, 8, 0, 0, 0, 9049.713, -7434.266, 84.65627, 2.094393, 'Magister Duskwither - On Quest Reward (Abandoned Investigations)  - Spawn Magister Duskwithers Journal'),
(15951, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Magister Duskwither - Linked with Previous Event  - Say Line 1'),
(15951, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 26660, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0 , 0, 'Magister Duskwither - Linked with Previous Event  - Cast Duskwither''s Fireball');

DELETE FROM `creature_text` WHERE `entry` IN (16183,15951,16196);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(16183, 0, 0, 'Where... where am I?', 12, 0, 100, 0, 0, 0, 'Courier Dawnstrider', 12726),
(15951, 0, 0, 'Good riddance... now none shall be able to repeat my mistakes!', 12, 0, 100, 0, 0, 0, 'Magister Duskwither',11713),
(16196, 0, 0, 'You''re not going anywhere just yet, handsome.  Not until you regain your strength.', 12, 0, 100, 0, 0, 0, 'Apothecary Thedra',12728);
